#pragma once

#include <string>
#include <memory>

#include "Media/Media.h"

// MOVIE_3DOLogo  "3dologo"
// MOVIE_NWCLogo  "new world logo"
// MOVIE_JVC      "jvc"
// MOVIE_Intro    "Intro"
// MOVIE_Emerald  "Intro Post"
// MOVIE_Death    "losegame"
// MOVIE_Outro    "end_seq1"

class VideoList;
class FFmpegLogProxy;

class MPlayer {
 public:
    MPlayer();
    virtual ~MPlayer();

    void Initialize();
    void Unload();

    void PlayFullscreenMovie(const std::string &pMovieName);

    void OpenHouseMovie(const std::string &pMovieName, bool bLoop);
    void HouseMovieLoop();

    bool IsMoviePlaying() const;
    bool StopMovie();

 protected:
    std::unique_ptr<FFmpegLogProxy> logProxy;
    VideoList *might_list;
    VideoList *magic_list;
    std::string sInHouseMovie;

    FILE *LoadMovie(const std::string &video_name, size_t &size,
                    size_t &offset);
};

extern MPlayer *pMediaPlayer;
extern PMovie pMovie_Track;
