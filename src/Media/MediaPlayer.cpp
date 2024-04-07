#include "Media/MediaPlayer.h"

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libavutil/imgutils.h>
    #include <libavutil/mem.h>
    #include <libavutil/opt.h>
    #include <libswresample/swresample.h>
    #include <libswscale/swscale.h>
}

#include <algorithm>
#include <cassert>
#include <chrono>
#include <deque>
#include <map>
#include <memory>
#include <queue>
#include <vector>
#include <thread>
#include <utility>

#include "Engine/Engine.h"
#include "Engine/EngineGlobals.h"
#include "Engine/Graphics/Renderer/Renderer.h"
#include "Engine/Graphics/Image.h"

#include "Io/Mouse.h"

#include "Media/Audio/AudioPlayer.h"
#include "Media/Audio/OpenALSoundProvider.h"
#include "Media/FFmpegLogProxy.h"

#include "Utility/Streams/MemoryInputStream.h"
#include "Utility/Memory/FreeDeleter.h"
#include "Utility/DataPath.h"

#include "GUI/GUIWindow.h"

using namespace std::chrono_literals; // NOLINT

OpenALSoundProvider *provider = nullptr;

MPlayer *pMediaPlayer = nullptr;
PMovie pMovie_Track;

class AVStreamWrapper {
 public:
    AVStreamWrapper() {
        type = AVMEDIA_TYPE_UNKNOWN;
        stream_idx = -1;
        stream = nullptr;
        dec = nullptr;
        dec_ctx = nullptr;
    }

    virtual ~AVStreamWrapper() {
        close();
    }

    virtual void reset() {
        if (dec_ctx != nullptr) {
            avcodec_flush_buffers(dec_ctx);
        }
    }

    virtual void close() {
        type = AVMEDIA_TYPE_UNKNOWN;
        stream_idx = -1;
        stream = nullptr;
        dec = nullptr;
        if (dec_ctx != nullptr) {
            // Close the codec
            avcodec_close(dec_ctx);
            logger->trace("ffmpeg: close decoder context file");
            dec_ctx = nullptr;
        }
    }

    virtual bool open(AVFormatContext *format_ctx) = 0;

    virtual bool open(AVFormatContext *format_ctx, AVMediaType type_) {
        stream_idx = av_find_best_stream(format_ctx, type_, -1, -1, &dec, 0);
        if (stream_idx < 0) {
            close();
            logger->warning("ffmpeg: unable to find audio stream");
            return false;
        }

        stream = format_ctx->streams[stream_idx];
        dec_ctx = avcodec_alloc_context3(dec);
        if (dec_ctx == nullptr) {
            close();
            return false;
        }

        if (avcodec_parameters_to_context(dec_ctx, stream->codecpar) < 0) {
            close();
            return false;
        }
        if (avcodec_open2(dec_ctx, dec, nullptr) < 0) {
            close();
            return false;
        }

        return true;
    }

    AVMediaType type;
    int stream_idx;
    AVStream *stream;
#if LIBAVFORMAT_VERSION_MAJOR >= 59
    const AVCodec *dec;
#else
    AVCodec *dec;
#endif
    AVCodecContext *dec_ctx;
    std::queue<std::shared_ptr<Blob>> queue;
};

class AVAudioStream : public AVStreamWrapper {
 public:
    virtual bool open(AVFormatContext *format_ctx) override {
        if (!AVStreamWrapper::open(format_ctx, AVMEDIA_TYPE_AUDIO)) {
            return false;
        }

        converter = swr_alloc_set_opts(
            converter, AV_CH_LAYOUT_STEREO, AV_SAMPLE_FMT_S16,
            dec_ctx->sample_rate, dec_ctx->channel_layout, dec_ctx->sample_fmt,
            dec_ctx->sample_rate, 0, nullptr);
        if (swr_init(converter) < 0) {
            logger->warning("ffmpeg: swr_init failed");
            swr_free(&converter);
            converter = nullptr;
            return false;
        }

        return true;
    }

    std::shared_ptr<Blob> decode_frame(AVPacket *avpacket) {
        std::shared_ptr<Blob> result;
        AVFrame *frame = av_frame_alloc();

        if (!queue.empty()) {
            result = queue.front();
            queue.pop();
        }

        if (avcodec_send_packet(dec_ctx, avpacket) >= 0) {
            int res = 0;
            while (res >= 0) {
                res = avcodec_receive_frame(dec_ctx, frame);
                if (res == AVERROR(EAGAIN) || res == AVERROR_EOF) {
                    break;
                }
                if (res < 0) {
                    av_frame_free(&frame);
                    return result;
                }
                size_t tmp_size = frame->nb_samples * 2 * 2;
                std::unique_ptr<void, FreeDeleter> tmp_buf(malloc(tmp_size));
                uint8_t *dst_channels[8] = { static_cast<uint8_t *>(tmp_buf.get()) };
                int got_samples = swr_convert(
                    converter, dst_channels, frame->nb_samples,
                    (const uint8_t**)frame->data, frame->nb_samples);
                std::shared_ptr<Blob> tmp_blob = std::make_shared<Blob>(Blob::fromMalloc(std::move(tmp_buf), tmp_size));
                if (got_samples > 0) {
                    if (!result) {
                        result = tmp_blob;
                    } else {
                        queue.push(tmp_blob);
                    }
                }
            }
        }

        av_frame_free(&frame);

        return result;
    }

 protected:
    SwrContext *converter = nullptr;
};

class AVVideoStream : public AVStreamWrapper {
 public:
    virtual bool open(AVFormatContext *format_ctx) override {
        if (!AVStreamWrapper::open(format_ctx, AVMEDIA_TYPE_VIDEO)) {
            return false;
        }

        width = dec_ctx->width;
        height = dec_ctx->height;

        frame_len = av_q2d(stream->time_base) * 1000.;
        frames_per_second = 1. / av_q2d(stream->time_base);

        converter = sws_getContext(
            dec_ctx->width, dec_ctx->height, dec_ctx->pix_fmt, width, height,
            AV_PIX_FMT_BGR32, SWS_BICUBIC, nullptr, nullptr, nullptr);

        return true;
    }

    std::shared_ptr<Blob> decode_frame(AVPacket *avpacket) {
        std::shared_ptr<Blob> result;
        AVFrame *frame = av_frame_alloc();

        if (!queue.empty()) {
            result = queue.front();
            queue.pop();
        }

        if (avcodec_send_packet(dec_ctx, avpacket) >= 0) {
            int res = 0;
            while (res >= 0) {
                res = avcodec_receive_frame(dec_ctx, frame);
                if (res == AVERROR(EAGAIN) || res == AVERROR_EOF) {
                    break;
                }
                if (res < 0) {
                    av_frame_free(&frame);
                    return result;
                }
                int linesizes[4] = { 0, 0, 0, 0 };
                if (av_image_fill_linesizes(linesizes, AV_PIX_FMT_RGB32, width) < 0) {
                    assert(false);
                }
                size_t tmp_size = frame->height * linesizes[0] * 2;
                std::unique_ptr<void, FreeDeleter> tmp_buf(malloc(tmp_size));
                uint8_t *data[4] = { static_cast<uint8_t *>(tmp_buf.get()), nullptr, nullptr, nullptr };

                if (sws_scale(converter, frame->data, frame->linesize, 0, frame->height, data, linesizes) < 0) {
                    assert(false);
                }

                std::shared_ptr<Blob> tmp_blob = std::make_shared<Blob>(Blob::fromMalloc(std::move(tmp_buf), tmp_size));

                if (!result) {
                    result = tmp_blob;
                } else {
                    queue.push(tmp_blob);
                }
            }
        }

        av_frame_free(&frame);

        last_frame = result;

        return result;
    }

    std::shared_ptr<Blob> last_frame;
    double frames_per_second = 0;
    double frame_len = 0;
    SwsContext *converter = nullptr;
    int width = 0;
    int height = 0;
};

static Recti calculateVideoRectangle(const PMovie &pMovie_Track) {
    Sizei scaleSize;
    if (render->GetPresentDimensions() != render->GetRenderDimensions())
        scaleSize = render->GetRenderDimensions();
    else
        scaleSize = window->size();
    float ratio_width = (float)scaleSize.w / pMovie_Track->GetWidth();
    float ratio_height = (float)scaleSize.h / pMovie_Track->GetHeight();
    float ratio = std::min(ratio_width, ratio_height);

    float w = pMovie_Track->GetWidth() * ratio;
    float h = pMovie_Track->GetHeight() * ratio;

    Recti rect;
    rect.x = (float)scaleSize.w / 2 - w / 2;
    rect.y = (float)scaleSize.h / 2 - h / 2;
    rect.w = w;
    rect.h = h;

    return rect;
}

class Movie : public IMovie {
 public:
    Movie() {
        width = 0;
        height = 0;
        format_ctx = nullptr;
        playback_time = 0.0;

        last_resampled_frame_num = -1;

        audio_data_in_device = nullptr;
        ioBuffer = nullptr;
        format_ctx = nullptr;
        avioContext = nullptr;

        looping = false;
        playing = false;

        _blob = Blob();
    }

    virtual ~Movie() { Close(); }

    void Close() {
        ReleaseAVCodec();

        if (audio_data_in_device) {
            provider->DeleteStreamingTrack(&audio_data_in_device);
        }
    }

    inline void ReleaseAVCodec() {
        audio.close();
        video.close();

        if (format_ctx) {
            // Close the video file
            avformat_close_input(&format_ctx);
            logger->trace("close video format context file\n");
            format_ctx = nullptr;
        }
        if (avioContext) {
            av_free(avioContext);
            avioContext = nullptr;
        }
        if (ioBuffer) {
            // av_free(ioBuffer);
            ioBuffer = nullptr;
        }
    }

    bool Load(const char *filename) {  // Загрузка
        // Open video file
        if (avformat_open_input(&format_ctx, filename, nullptr, nullptr) < 0) {
            logger->warning("ffmpeg: Unable to open input file");
            Close();
            return false;
        }

        // Retrieve stream information
        if (avformat_find_stream_info(format_ctx, nullptr) < 0) {
            logger->warning("ffmpeg: Unable to find stream info");
            Close();
            return false;
        }

        // Dump information about file onto standard error
        av_dump_format(format_ctx, 0, filename, 0);

        audio.open(format_ctx);

        if (!video.open(format_ctx)) {
            logger->error("Cannot open video stream: {}", filename);
            Close();
            return false;
        }

        width = video.width;
        height = video.height;

        if (audio.stream_idx >= 0) {
            audio_data_in_device = provider->CreateStreamingTrack16(2, audio.dec_ctx->sample_rate, 2);
        }

        return true;
    }

    bool LoadFromLOD(const Blob &blob) {
        _blob = Blob::share(blob);
        _stream.reset(_blob.data(), _blob.size());

        if (!ioBuffer) {
            ioBuffer = (unsigned char *)av_malloc(AV_INPUT_BUFFER_MIN_SIZE);  // can get av_free()ed by libav
        }

        if (!avioContext) {
            avioContext = avio_alloc_context(ioBuffer, 0x4000, 0, this, s_read, NULL, s_seek);
        }
        if (!format_ctx) {
            format_ctx = avformat_alloc_context();
        }
        format_ctx->pb = avioContext;
        return Load("dummyFilename");
    }

    virtual std::shared_ptr<Blob> GetFrame() override {
        if (!playing) {
            return nullptr;
        }

        auto current_time = std::chrono::system_clock::now();
        auto diff = std::chrono::time_point_cast<std::chrono::milliseconds>(current_time) - std::chrono::time_point_cast<std::chrono::milliseconds>(start_time);

        playback_time += std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
        start_time = current_time;

        int desired_frame_number = (int)((playback_time / video.frame_len) + 0.5);
        if (last_resampled_frame_num == desired_frame_number) {
            return video.last_frame;
        }
        last_resampled_frame_num++;
        if (last_resampled_frame_num == video.stream->duration) {
            if (looping) {
                video.reset();
                audio.reset();
                int err = av_seek_frame(format_ctx, -1, 0,
                                        AVSEEK_FLAG_BACKWARD | AVSEEK_FLAG_ANY);
                char err_buf[2048];
                av_strerror(err, err_buf, 2048);
                if (err < 0) {
                    Close();
                    return nullptr;
                }
                last_resampled_frame_num = 0;
                playback_time = 0;
                desired_frame_number = 0;
            } else {
                playing = false;
                return nullptr;
            }
        }

        AVPacket *avpacket = av_packet_alloc();

        // keep reading packets until we hit the end or find a video packet
        do {
            if (av_read_frame(format_ctx, avpacket) < 0) {
                // probably movie is finished
                playing = false;
                av_packet_free(&avpacket);
                return nullptr;
            }

            // Is this a packet from the video stream?
            // audio packet - queue into playing
            if (avpacket->stream_index == audio.stream_idx) {
                std::shared_ptr<Blob> buffer = audio.decode_frame(avpacket);
                if (buffer) {
                    provider->Stream16(audio_data_in_device,
                                       buffer->size() / 2,
                                       buffer->data());
                }
            } else if (avpacket->stream_index == video.stream_idx) {
              // Decode video frame
              // video packet - decode & maybe show
              video.decode_frame(avpacket);
            } else {
                assert(false);  // unknown stream
            }
        } while (avpacket->stream_index != video.stream_idx ||
                 avpacket->pts <= desired_frame_number);

        av_packet_free(&avpacket);

        return video.last_frame;
    }

    virtual void PlayBink() override {
        // fix for #39 - choppy sound with bink

        AVPacket packet;


        // create texture
        GraphicsImage *tex = GraphicsImage::Create(pMovie_Track->GetWidth(), pMovie_Track->GetHeight());

        // holds decoded audio
        std::queue<std::shared_ptr<Blob>, std::deque<std::shared_ptr<Blob>>> buffq;

        // loop through once and add all audio packets to queue
        while (av_read_frame(format_ctx, &packet) >= 0) {
            if (packet.stream_index == audio.stream_idx) {
                std::shared_ptr<Blob> buffer = audio.decode_frame(&packet);
                if (buffer) buffq.push(buffer);
            }
        }
        logger->trace("Audio Packets Queued");

        // reset video to start
        int err = avformat_seek_file(format_ctx, -1, 0, 0, 0, AVSEEK_FLAG_BACKWARD);
        //int err = av_seek_frame(format_ctx, -1, 0, AVSEEK_FLAG_BACKWARD | AVSEEK_FLAG_ANY);
        if (err < 0) {
            logger->warning("Seek to start failed! - Exit Movie");
            tex->Release();
            return;
        }
        start_time = std::chrono::system_clock::now();
        logger->trace("Video stream reset");

        int lastvideopts = -1;
        int desired_frame_number;
        auto current_time = std::chrono::system_clock::now();
        int audioupdaterate = (30.0f * video.frame_len) / 1000.0f;

        // loop through and do video
        while (av_read_frame(format_ctx, &packet) >= 0) {
            do {
                // get playback time - and wait till we need the next frame
                current_time = std::chrono::system_clock::now();
                playback_time = (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time)).count();
                desired_frame_number = (int)((playback_time / video.frame_len)/* + 0.25*/);
                std::this_thread::sleep_for(5ms);
            } while (lastvideopts == desired_frame_number);

            // ignore audio packets
            if (packet.stream_index == audio.stream_idx) { continue; }

            if (packet.stream_index == video.stream_idx) {
                // check if anymore sound frames still in decoder
                std::shared_ptr<Blob> buffer = audio.decode_frame(NULL);
                if (buffer) buffq.push(buffer);

                // stream required sound frames
                // nwc and intro are 15fps vid but need 30fps sound
                // jvc is 10fps video but need 30 fps sound
                for (int i = 0; i < audioupdaterate; i++) {
                    if (!buffq.empty()) {
                        provider->Stream16(audio_data_in_device,
                                            buffq.front()->size() / 2,
                                            buffq.front()->data());
                        buffq.pop();
                    }
                }

                // Decode video frame and show
                lastvideopts = packet.pts;
                video.decode_frame(&packet);
                std::shared_ptr<Blob> tmp_buf = video.last_frame;

                render->BeginScene2D();
                // update pixels from buffer
                tex->rgba() = RgbaImage::copy(tex->width(), tex->height(), static_cast<const Color *>(tmp_buf->data()));

                // update texture
                render->Update_Texture(tex);
                render->DrawImage(tex, calculateVideoRectangle(pMovie_Track));
                render->Present();
            }

            MessageLoopWithWait();

            av_packet_unref(&packet);

            // exit movie
            if (!playing) break;
        }
        // hold for frame length at end of packets
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(video.frame_len)));

        // clean up
        while (!buffq.empty()) buffq.pop();
        tex->Release();

        return;
    }

    virtual std::string GetFormat() override {
        return format_ctx->iformat->name;
    }

    virtual unsigned int GetWidth() const override { return width; }

    virtual unsigned int GetHeight() const override { return height; }

    virtual bool Play(bool loop = false) override {
        start_time = std::chrono::system_clock::now();
        looping = loop;
        playing = true;
        return false;
    }

    virtual bool Stop() override {
        playing = false;
        return false;
    }

    virtual bool IsPlaying() const override { return playing; }

 protected:
    static int s_read(void *opaque, uint8_t *buf, int buf_size) {
        return static_cast<Movie *>(opaque)->read(buf, buf_size);
    }

    static int64_t s_seek(void *opaque, int64_t offset, int whence) {
        return static_cast<Movie *>(opaque)->seek(offset, whence);
    }

    int read(uint8_t *buf, int buf_size) {
        return _stream.read(buf, buf_size);
    }

    int64_t seek(int64_t offset, int whence) {
        if (whence == AVSEEK_SIZE) {
            return _blob.size();
        }

        switch (whence) {
            case SEEK_SET:
                _stream.seek(offset);
                break;
            case SEEK_CUR:
                _stream.seek(_stream.position() + offset);
                break;
            case SEEK_END:
                _stream.seek(_blob.size() - offset);
                break;
            default:
                assert(false);
                break;
        }

        return _stream.position();
    }

 protected:
    unsigned int width;
    unsigned int height;
    AVFormatContext *format_ctx;
    double playback_time;

    AVAudioStream audio;
    unsigned char *ioBuffer;
    AVIOContext *avioContext;
    OpenALSoundProvider::StreamingTrackBuffer *audio_data_in_device;

    AVVideoStream video;
    int last_resampled_frame_num;

    std::chrono::time_point<std::chrono::system_clock> start_time;
    bool looping;
    bool playing;

    Blob _blob;
    MemoryInputStream _stream;
};

void MPlayer::Initialize() {
    might_list.open(makeDataPath("anims", "might7.vid"));
    magic_list.open(makeDataPath("anims", "magic7.vid"));
}

void MPlayer::OpenHouseMovie(std::string_view pMovieName, bool bLoop) {
    if (IsMoviePlaying()) {
        return;
    }

    pEventTimer->setPaused(true);
    pAudioPlayer->pauseLooping();
    pAudioPlayer->MusicPause();
    Blob blob = LoadMovie(pMovieName);
    if (!blob) {
        return;
    }

    std::shared_ptr<Movie> pMovie = std::make_shared<Movie>();
    pMovie->LoadFromLOD(blob);
    pMovie_Track = std::dynamic_pointer_cast<IMovie>(pMovie);
    sInHouseMovie = pMovieName;
}

void MPlayer::HouseMovieLoop() {
    if (!pMovie_Track || engine->config->debug.NoVideo.value()) {
        return;
    }

    if (!pMovie_Track->IsPlaying()) {
        pMovie_Track->Play(false);
    }

    render->BeginScene2D();

    static GraphicsImage *tex;
    if (!tex) {
        tex = GraphicsImage::Create(pMovie_Track->GetWidth(), pMovie_Track->GetHeight());
    }

    std::shared_ptr<Blob> buffer = pMovie_Track->GetFrame();
    if (buffer) {
        Recti rect;
        Sizei wsize = render->GetRenderDimensions();
        rect.x = render->config->graphics.HouseMovieX1.value();
        rect.y = render->config->graphics.HouseMovieY1.value();
        rect.w = wsize.w - render->config->graphics.HouseMovieX2.value();
        rect.h = wsize.h - render->config->graphics.HouseMovieY2.value();

        // update pixels from buffer
        tex->rgba() = RgbaImage::copy(tex->width(), tex->height(), static_cast<const Color *>(buffer->data()));

        // update texture
        render->Update_Texture(tex);
        render->DrawImage(tex, rect);

    } else {
        pMovie_Track = nullptr;
        Blob blob = LoadMovie(sInHouseMovie);
        if (blob) {
            std::shared_ptr<Movie> pMovie = std::make_shared<Movie>();
            pMovie->LoadFromLOD(blob);
            pMovie_Track = std::dynamic_pointer_cast<IMovie>(pMovie);
            pMovie_Track->Play();
        }
        // callback to prevent skipped frame draw
        HouseMovieLoop();
    }
}

void MPlayer::PlayFullscreenMovie(std::string_view pFilename) {
    if (engine->config->debug.NoVideo.value()) {
        return;
    }

    Blob blob = LoadMovie(pFilename);
    if (!blob) {
        return;
    }

    std::shared_ptr<Movie> pMovie = std::make_shared<Movie>();
    if (!pMovie->LoadFromLOD(blob)) {
        return;
    }
    pMovie_Track = std::dynamic_pointer_cast<IMovie>(pMovie);

    pEventTimer->setPaused(true);
    pAudioPlayer->pauseLooping();
    pAudioPlayer->MusicPause();
    platform->setCursorShown(false);
    current_screen_type = SCREEN_VIDEO;

    pMovie_Track->Play();

    Sizei wSize = window->size();
    Sizei scaleSize;

    // create texture
    GraphicsImage *tex = GraphicsImage::Create(pMovie_Track->GetWidth(), pMovie_Track->GetHeight());

    if (pMovie->GetFormat() == "bink") {
        logger->trace("bink file");
        pMovie->PlayBink();
    } else {
        while (true) {
            MessageLoopWithWait();

            render->ClearBlack();
            render->BeginScene2D();

            std::this_thread::sleep_for(2ms);

            std::shared_ptr<Blob> buffer = pMovie_Track->GetFrame();
            if (!buffer) {
                break;
            }

            // update pixels from buffer
            tex->rgba() = RgbaImage::copy(tex->width(), tex->height(), static_cast<const Color *>(buffer->data()));

            // update texture
            render->Update_Texture(tex);
            render->DrawImage(tex, calculateVideoRectangle(pMovie_Track));

            render->Present();
        }
    }

    // release texture
    tex->Release();

    current_screen_type = SCREEN_GAME;
    pMovie_Track = nullptr;

    // prevent passing UIMSG_Escape event if video stopped by ESC key
    engine->_messageQueue->clear();

    platform->setCursorShown(true);
}

bool MPlayer::IsMoviePlaying() const {
    if (!pMovie_Track) {
        return false;
    }

    return pMovie_Track->IsPlaying();
}

bool MPlayer::StopMovie() {
    if (pMovie_Track) {
        return pMovie_Track->Stop();
    }
    return false;
}

Blob MPlayer::LoadMovie(std::string_view video_name) {
    std::string pVideoNameBik = fmt::format("{}.bik", video_name);
    std::string pVideoNameSmk = fmt::format("{}.smk", video_name);

    if (might_list.isOpen()) {
        if (might_list.exists(pVideoNameBik)) {
            return might_list.read(pVideoNameBik);
        }
        if (might_list.exists(pVideoNameSmk)) {
            return might_list.read(pVideoNameSmk);
        }
    }

    if (magic_list.isOpen()) {
        if (magic_list.exists(pVideoNameBik)) {
            return magic_list.read(pVideoNameBik);
        }
        if (magic_list.exists(pVideoNameSmk)) {
            return magic_list.read(pVideoNameSmk);
        }
    }

    return {};
}

void MPlayer::Unload() {
    if (pMovie_Track) {
        pMovie_Track->Stop();
    }
    pMovie_Track = nullptr;
    if (!bGameoverLoop) {
        pAudioPlayer->MusicResume();
        pAudioPlayer->resumeSounds();
    }
    pEventTimer->setPaused(false);
}

// for video//////////////////////////////////////////////////////////////////

MPlayer::MPlayer() {
    logProxy = std::make_unique<FFmpegLogProxy>(logger);
    pMovie_Track = nullptr;

    if (!provider) {
        provider = new OpenALSoundProvider;
        // logger->Warning("allocation dynamic memory for provider");
        provider->Initialize();
    }
}

MPlayer::~MPlayer() {
    delete provider;
}
