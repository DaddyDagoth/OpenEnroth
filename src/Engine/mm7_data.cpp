#include "Engine/mm7_data.h"

#include "Party.h"

#include "Engine/Autonotes.h"
#include "Engine/Awards.h"
#include "Engine/Graphics/Viewport.h"
#include "Engine/stru123.h"
#include "Engine/stru160.h"
#include "Engine/stru367.h"
#include "MapInfo.h"
#include "OurMath.h"

MapStats *pMapStats;
Viewport *pViewport = new Viewport;
ViewingParams *viewparams = new ViewingParams;
stru123 stru_5E4C90_MapPersistVars;
std::array<Autonote, 196> pAutonoteTxt;
std::array<Award, 105> pAwards;
std::array<AwardType, 1000> achieved_awards;
int num_achieved_awards;
int full_num_items_in_book;

std::array<stru160, 66> array_4EB8B8 = {  // vertices for spheres
    {stru160(0.0000000f, 0.0000000f, 1.0000000f),
     stru160(0.0000000f, 0.3826830f, 0.9238799f),
     stru160(0.3826830f, 0.0000000f, 0.9238799f),
     stru160(0.4082480f, 0.4082480f, 0.8164970f),
     stru160(0.0000000f, 0.7071070f, 0.7071070f),
     stru160(0.7071070f, 0.0000000f, 0.7071070f),
     stru160(0.4082480f, 0.8164970f, 0.4082480f),
     stru160(0.8164970f, 0.4082480f, 0.4082480f),
     stru160(0.7071070f, 0.7071070f, 0.0000000f),
     stru160(0.0000000f, 0.9238799f, 0.3826830f),
     stru160(0.3826830f, 0.9238799f, 0.0000000f),
     stru160(0.0000000f, 1.0000000f, 0.0000000f),
     stru160(0.9238799f, 0.3826830f, 0.0000000f),
     stru160(0.9238799f, 0.0000000f, 0.3826830f),
     stru160(1.0000000f, 0.0000000f, 0.0000000f),
     stru160(0.0000000f, -0.3826830f, 0.9238799f),
     stru160(0.4082480f, -0.4082480f, 0.8164970f),
     stru160(0.0000000f, -0.7071070f, 0.7071070f),
     stru160(0.8164970f, -0.4082480f, 0.4082480f),
     stru160(0.4082480f, -0.8164970f, 0.4082480f),
     stru160(0.7071070f, -0.7071070f, 0.0000000f),
     stru160(0.9238799f, -0.3826830f, 0.0000000f),
     stru160(0.3826830f, -0.9238799f, 0.0000000f),
     stru160(0.0000000f, -0.9238799f, 0.3826830f),
     stru160(0.0000000f, -1.0000000f, 0.0000000f),
     stru160(-0.3826830f, 0.0000000f, 0.9238799f),
     stru160(-0.4082480f, -0.4082480f, 0.8164970f),
     stru160(-0.7071070f, 0.0000000f, 0.7071070f),
     stru160(-0.4082480f, -0.8164970f, 0.4082480f),
     stru160(-0.8164970f, -0.4082480f, 0.4082480f),
     stru160(-0.7071070f, -0.7071070f, 0.0000000f),
     stru160(-0.3826830f, -0.9238799f, 0.0000000f),
     stru160(-0.9238799f, -0.3826830f, 0.0000000f),
     stru160(-0.9238799f, 0.0000000f, 0.3826830f),
     stru160(-1.0000000f, 0.0000000f, 0.0000000f),
     stru160(-0.4082480f, 0.4082480f, 0.8164970f),
     stru160(-0.8164970f, 0.4082480f, 0.4082480f),
     stru160(-0.4082480f, 0.8164970f, 0.4082480f),
     stru160(-0.7071070f, 0.7071070f, 0.0000000f),
     stru160(-0.9238799f, 0.3826830f, 0.0000000f),
     stru160(-0.3826830f, 0.9238799f, 0.0000000f),
     stru160(0.0000000f, 0.0000000f, -1.0000000f),
     stru160(0.0000000f, 0.3826830f, -0.9238799f),
     stru160(0.3826830f, 0.0000000f, -0.9238799f),
     stru160(0.4082480f, 0.4082480f, -0.8164970f),
     stru160(0.0000000f, 0.7071070f, -0.7071070f),
     stru160(0.7071070f, 0.0000000f, -0.7071070f),
     stru160(0.4082480f, 0.8164970f, -0.4082480f),
     stru160(0.8164970f, 0.4082480f, -0.4082480f),
     stru160(0.0000000f, 0.9238799f, -0.3826830f),
     stru160(0.9238799f, 0.0000000f, -0.3826830f),
     stru160(0.0000000f, -0.3826830f, -0.9238799f),
     stru160(0.4082480f, -0.4082480f, -0.8164970f),
     stru160(0.0000000f, -0.7071070f, -0.7071070f),
     stru160(0.8164970f, -0.4082480f, -0.4082480f),
     stru160(0.4082480f, -0.8164970f, -0.4082480f),
     stru160(0.0000000f, -0.9238799f, -0.3826830f),
     stru160(-0.3826830f, 0.0000000f, -0.9238799f),
     stru160(-0.4082480f, -0.4082480f, -0.8164970f),
     stru160(-0.7071070f, 0.0000000f, -0.7071070f),
     stru160(-0.4082480f, -0.8164970f, -0.4082480f),
     stru160(-0.8164970f, -0.4082480f, -0.4082480f),
     stru160(-0.9238799f, 0.0000000f, -0.3826830f),
     stru160(-0.4082480f, 0.4082480f, -0.8164970f),
     stru160(-0.8164970f, 0.4082480f, -0.4082480f),
     stru160(-0.4082480f, 0.8164970f, -0.4082480f)}};
std::array<stru160, 128> array_4EBBD0;
std::array<int32_t, 128 * 3> array_4EBBD0_x = {  // indicies for triangle in sphere
    {0x00000000, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000002,
     0x00000001, 0x00000004, 0x00000003, 0x00000003, 0x00000005, 0x00000002,
     0x00000004, 0x00000006, 0x00000003, 0x00000006, 0x00000007, 0x00000003,
     0x00000006, 0x00000008, 0x00000007, 0x00000007, 0x00000005, 0x00000003,
     0x00000004, 0x00000009, 0x00000006, 0x00000009, 0x0000000A, 0x00000006,
     0x00000009, 0x0000000B, 0x0000000A, 0x0000000A, 0x00000008, 0x00000006,
     0x00000008, 0x0000000C, 0x00000007, 0x0000000C, 0x0000000D, 0x00000007,
     0x0000000C, 0x0000000E, 0x0000000D, 0x0000000D, 0x00000005, 0x00000007,
     0x00000000, 0x00000002, 0x0000000F, 0x00000002, 0x00000010, 0x0000000F,
     0x00000002, 0x00000005, 0x00000010, 0x00000010, 0x00000011, 0x0000000F,
     0x00000005, 0x00000012, 0x00000010, 0x00000012, 0x00000013, 0x00000010,
     0x00000012, 0x00000014, 0x00000013, 0x00000013, 0x00000011, 0x00000010,
     0x00000005, 0x0000000D, 0x00000012, 0x0000000D, 0x00000015, 0x00000012,
     0x0000000D, 0x0000000E, 0x00000015, 0x00000015, 0x00000014, 0x00000012,
     0x00000014, 0x00000016, 0x00000013, 0x00000016, 0x00000017, 0x00000013,
     0x00000016, 0x00000018, 0x00000017, 0x00000017, 0x00000011, 0x00000013,
     0x00000000, 0x0000000F, 0x00000019, 0x0000000F, 0x0000001A, 0x00000019,
     0x0000000F, 0x00000011, 0x0000001A, 0x0000001A, 0x0000001B, 0x00000019,
     0x00000011, 0x0000001C, 0x0000001A, 0x0000001C, 0x0000001D, 0x0000001A,
     0x0000001C, 0x0000001E, 0x0000001D, 0x0000001D, 0x0000001B, 0x0000001A,
     0x00000011, 0x00000017, 0x0000001C, 0x00000017, 0x0000001F, 0x0000001C,
     0x00000017, 0x00000018, 0x0000001F, 0x0000001F, 0x0000001E, 0x0000001C,
     0x0000001E, 0x00000020, 0x0000001D, 0x00000020, 0x00000021, 0x0000001D,
     0x00000020, 0x00000022, 0x00000021, 0x00000021, 0x0000001B, 0x0000001D,
     0x00000000, 0x00000019, 0x00000001, 0x00000019, 0x00000023, 0x00000001,
     0x00000019, 0x0000001B, 0x00000023, 0x00000023, 0x00000004, 0x00000001,
     0x0000001B, 0x00000024, 0x00000023, 0x00000024, 0x00000025, 0x00000023,
     0x00000024, 0x00000026, 0x00000025, 0x00000025, 0x00000004, 0x00000023,
     0x0000001B, 0x00000021, 0x00000024, 0x00000021, 0x00000027, 0x00000024,
     0x00000021, 0x00000022, 0x00000027, 0x00000027, 0x00000026, 0x00000024,
     0x00000026, 0x00000028, 0x00000025, 0x00000028, 0x00000009, 0x00000025,
     0x00000028, 0x0000000B, 0x00000009, 0x00000009, 0x00000004, 0x00000025,
     0x00000029, 0x0000002A, 0x0000002B, 0x0000002A, 0x0000002C, 0x0000002B,
     0x0000002A, 0x0000002D, 0x0000002C, 0x0000002C, 0x0000002E, 0x0000002B,
     0x0000002D, 0x0000002F, 0x0000002C, 0x0000002F, 0x00000030, 0x0000002C,
     0x0000002F, 0x00000008, 0x00000030, 0x00000030, 0x0000002E, 0x0000002C,
     0x0000002D, 0x00000031, 0x0000002F, 0x00000031, 0x0000000A, 0x0000002F,
     0x00000031, 0x0000000B, 0x0000000A, 0x0000000A, 0x00000008, 0x0000002F,
     0x00000008, 0x0000000C, 0x00000030, 0x0000000C, 0x00000032, 0x00000030,
     0x0000000C, 0x0000000E, 0x00000032, 0x00000032, 0x0000002E, 0x00000030,
     0x00000029, 0x0000002B, 0x00000033, 0x0000002B, 0x00000034, 0x00000033,
     0x0000002B, 0x0000002E, 0x00000034, 0x00000034, 0x00000035, 0x00000033,
     0x0000002E, 0x00000036, 0x00000034, 0x00000036, 0x00000037, 0x00000034,
     0x00000036, 0x00000014, 0x00000037, 0x00000037, 0x00000035, 0x00000034,
     0x0000002E, 0x00000032, 0x00000036, 0x00000032, 0x00000015, 0x00000036,
     0x00000032, 0x0000000E, 0x00000015, 0x00000015, 0x00000014, 0x00000036,
     0x00000014, 0x00000016, 0x00000037, 0x00000016, 0x00000038, 0x00000037,
     0x00000016, 0x00000018, 0x00000038, 0x00000038, 0x00000035, 0x00000037,
     0x00000029, 0x00000033, 0x00000039, 0x00000033, 0x0000003A, 0x00000039,
     0x00000033, 0x00000035, 0x0000003A, 0x0000003A, 0x0000003B, 0x00000039,
     0x00000035, 0x0000003C, 0x0000003A, 0x0000003C, 0x0000003D, 0x0000003A,
     0x0000003C, 0x0000001E, 0x0000003D, 0x0000003D, 0x0000003B, 0x0000003A,
     0x00000035, 0x00000038, 0x0000003C, 0x00000038, 0x0000001F, 0x0000003C,
     0x00000038, 0x00000018, 0x0000001F, 0x0000001F, 0x0000001E, 0x0000003C,
     0x0000001E, 0x00000020, 0x0000003D, 0x00000020, 0x0000003E, 0x0000003D,
     0x00000020, 0x00000022, 0x0000003E, 0x0000003E, 0x0000003B, 0x0000003D,
     0x00000029, 0x00000039, 0x0000002A, 0x00000039, 0x0000003F, 0x0000002A,
     0x00000039, 0x0000003B, 0x0000003F, 0x0000003F, 0x0000002D, 0x0000002A,
     0x0000003B, 0x00000040, 0x0000003F, 0x00000040, 0x00000041, 0x0000003F,
     0x00000040, 0x00000026, 0x00000041, 0x00000041, 0x0000002D, 0x0000003F,
     0x0000003B, 0x0000003E, 0x00000040, 0x0000003E, 0x00000027, 0x00000040,
     0x0000003E, 0x00000022, 0x00000027, 0x00000027, 0x00000026, 0x00000040,
     0x00000026, 0x00000028, 0x00000041, 0x00000028, 0x00000031, 0x00000041,
     0x00000028, 0x0000000B, 0x00000031, 0x00000031, 0x0000002D, 0x00000041}};

#include "MapsLongTimer.h"
std::array<MapsLongTimer, 100> MapsLongTimersList;

#include "Engine/Tables/IconFrameTable.h"
struct IconFrameTable *pIconsFrameTable;

#include "Engine/Tables/PlayerFrameTable.h"
struct PlayerFrameTable *pPlayerFrameTable;  // idb

//-------------------------------------------------------------------------
// Data declarations

int game_viewport_width;
int game_viewport_height;
int game_viewport_x;
int game_viewport_y;
int game_viewport_z;
int game_viewport_w;

std::array<unsigned int, 2> saveload_dlg_xs = {{82, 0}};
std::array<unsigned int, 2> saveload_dlg_ys = {{60, 0}};
std::array<unsigned int, 2> saveload_dlg_zs = {{460, 640}};
std::array<unsigned int, 2> saveload_dlg_ws = {{344, 480}};
int pWindowList_at_506F50_minus1_indexing[1];
int dword_4C9890[10];
int dword_4C9920[16];
char _4D864C_force_sw_render_rules;
float flt_4D86CC = 1.0f;  // spot light scale??
int dword_4D86D8 = 0x40000000;

float flt_4D84E8 = 0.0f;

unsigned int uGammaPos = 0;
std::array<int, 8> BtnTurnCoord = {{
    0xA4,
    0x5D,
    0x16,
    0xB,
    0x5,
    0xD,
    0x7,
    0x3B,
}};
std::array<int16_t, 4> RightClickPortraitXmin = {{20, 131, 242, 357}};
std::array<int16_t, 4> RightClickPortraitXmax = {{83, 198, 312, 423}};

std::array<unsigned int, 4> pHealthBarPos = {{23, 138, 251, 366}}; //was 22, 137
std::array<unsigned int, 4> pManaBarPos = {{102, 217, 331, 447}};

std::array<int8_t, 88> monster_popup_y_offsets = {
    {-20, 20, 0,   -40, 0,   0,   0,   0,   0,   0,   -50, 20,  0,   -10, -10,
     -20, 10, -10, 0,   0,   0,   -20, 10,  -10, 0,   0,   0,   -20, -10, 0,
     0,   0,  -40, -20, 0,   0,   0,   -50, -30, -30, -30, -30, -30, -30, 0,
     0,   0,  0,   0,   0,   -20, -20, -20, 20,  20,  20,  10,  10,  10,  10,
     10,  10, -90, -60, -40, -20, -20, -80, -10, 0,   0,   -40, 0,   0,   0,
     -20, 10, 0,   0,   0,   0,   0,   0,   -60, 0,   0,   0,   0}};
unsigned char hourglass_icon_idx = 12;

int dword_4E455C;
std::array<int, 6> dword_4E4560;
std::array<int, 6> dword_4E4578;
std::array<int, 6> dword_4E4590;
std::array<int, 6> dword_4E45A8;
std::array<float, 10> flt_4E4A80 = {{
    0.050000001f, 0.1f,  0.30000001f, 0.5f,
    0.60000002f,  1.0f,  6.0f,        25.0f,
    50.0f,        100.0f
}};

std::array<std::array<int, 2>, 14> pPartySpellbuffsUI_XYs = {{
    {{477, 247}},
    {{497, 247}},
    {{522, 247}},
    {{542, 247}},
    {{564, 247}},
    {{581, 247}},
    {{614, 247}},
    {{477, 279}},
    {{497, 279}},
    {{522, 279}},
    {{542, 279}},
    {{564, 279}},
    {{589, 279}},
    {{612, 279}}
}};
std::array<unsigned char, 14> byte_4E5DD8 = {
    {PARTY_BUFF_FEATHER_FALL, PARTY_BUFF_RESIST_FIRE, PARTY_BUFF_RESIST_AIR,
     PARTY_BUFF_RESIST_WATER, PARTY_BUFF_RESIST_MIND, PARTY_BUFF_RESIST_EARTH,
     PARTY_BUFF_RESIST_BODY, PARTY_BUFF_HEROISM, PARTY_BUFF_HASTE,
     PARTY_BUFF_SHIELD, PARTY_BUFF_STONE_SKIN, PARTY_BUFF_PROTECTION_FROM_MAGIC,
     PARTY_BUFF_IMMOLATION, PARTY_BUFF_DAY_OF_GODS}};
std::array<uint8_t, 14> pPartySpellbuffsUI_smthns = {
    {14, 1, 10, 4, 7, 2, 9, 3, 6, 15, 8, 3, 12, 0}};

std::array<std::array<int, 6>, 6> pNPCPortraits_x = {{
    {{521, 0, 0, 0, 0, 0}},
    {{521, 521, 0, 0, 0, 0}},
    {{521, 521, 521, 0, 0, 0}},
    {{521, 486, 564, 521, 0, 0}},
    {{521, 486, 564, 486, 564, 0}},
    {{486, 564, 486, 564, 486, 564}}
}};
std::array<std::array<int, 6>, 6> pNPCPortraits_y = {{
    {{38, 0, 0, 0, 0, 0}},
    {{38, 165, 0, 0, 0, 0}},
    {{38, 133, 228, 0, 0, 0}},
    {{38, 133, 133, 228, 0, 0}},
    {{38, 133, 133, 228, 228, 0}},
    {{38, 38, 133, 133, 228, 228}}
}};
std::array<const char *, 11> pHouse_ExitPictures = {{
    "",         "ticon01", "ticon02", "ticon03", "ticon04", "ticon05",
    "istairup", "itrap",   "outside", "idoor",   "isecdoor"
}};

std::array<int16_t, 11> word_4E8152 = {{0, 0, 0, 90, 8, 2, 70, 20, 10, 50, 30}};  // level spawn monster levels ABC

char _4E94D0_light_type = 5;  // stationary??
char _4E94D2_light_type = 6;
char _4E94D3_light_type = 10;
// char *off_4EB080; // idb
std::array<const char *, 465> pTransitionStrings = {{"", nullptr}};
std::array<const char *, 25> pPlayerPortraitsNames = {{
    "pc01-", "pc02",  "pc03",  "pc04",  "pc05-", "pc06", "pc07",
    "pc08",  "pc09-", "pc10",  "pc11-", "pc12",  "pc13", "pc14",
    "pc15",  "pc16",  "pc17-", "pc18",  "pc19",  "pc20", "pc21-",
    "pc22-", "pc23",  "pc24-", "pc25-"
}};

std::array<std::array<unsigned char, 25>, 48> byte_4ECF08 = {{
    {{2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1}},  // 1
    {{2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 2
    {{2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 3
    {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 4
    {{2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 5
    {{2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 6
    {{2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 7
    {{2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1}},  // 8
    {{2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2}},  // 9
    {{2, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 10
    {{2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 11
    {{1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 2}},  // 12
    {{2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 13
    {{1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 1, 2, 2}},  // 14
    {{2, 1, 1, 2, 1, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2}},  // 15
    {{1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1}},  // 16
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 17
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1}},  // 18
    {{1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 19
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 20
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 21
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 22
    {{2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1}},  // 23
    {{2, 2, 2, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2}},  // 24
    {{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 2, 2, 2, 1, 2, 1, 1}},  // 25
    {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 26
    {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2}},  // 27
    {{1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 28
    {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 1, 1}},  // 29
    {{1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1}},  // 30
    {{1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 1}},  // 31
    {{1, 1, 2, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2}},  // 32
    {{1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1}},  // 33
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1}},  // 34
    {{1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2}},  // 35
    {{1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2}},  // 36
    {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2}},  // 37
    {{2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 1, 1}},  // 38
    {{1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1}},  // 39
    {{1, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 40
    {{2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1}},  // 41
    {{1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1}},  // 42
    {{1, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},  // 43
    {{1, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 2}},  // 44
    {{2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2}},  // 45
    {{1, 1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 2}},  // 46
    {{1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1}},  // 47
    {{1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1}}   // 48
}};

IndexedArray<std::array<unsigned char, 3>, SPEECH_FIRST, SPEECH_LAST> speechVariants = {
    {SPEECH_None,                {0,  0,  0}},
    {SPEECH_KillWeakEnemy,       {38, 0,  0}},
    {SPEECH_KillStrongEnemy,     {37, 0,  0}},
    {SPEECH_StoreClosed,         {2,  0,  0}},
    {SPEECH_TrapDisarmed,        {1,  0,  0}},
    {SPEECH_TrapExploded,        {3,  0,  0}},
    {SPEECH_AvoidDamage,         {0,  0,  0}},
    {SPEECH_IndentifyItemWeak,   {5,  0,  0}},
    {SPEECH_IndentifyItemStrong, {6,  0,  0}},
    {SPEECH_IndentifyItemFail,   {7,  0,  0}},
    {SPEECH_RepairSuccess,       {8,  0,  0}},
    {SPEECH_RepairFail,          {9,  0,  0}},
    {SPEECH_SetQuickSpell,       {13, 0,  0}},
    {SPEECH_CantRestHere,        {23, 0,  0}},
    {SPEECH_SkillIncrease,       {0,  0,  0}},
    {SPEECH_NoRoom,              {25, 0,  0}},
    {SPEECH_PotionSuccess,       {26, 0,  0}},
    {SPEECH_PotionExplode,       {27, 0,  0}},
    {SPEECH_DoorLocked,          {28, 0,  0}},
    {SPEECH_WontBudge,           {0,  0,  0}},
    {SPEECH_CantLearnSpell,      {30, 0,  0}},
    {SPEECH_LearnSpell,          {29, 0,  0}},
    {SPEECH_GoodDay,             {32, 33, 0}},
    {SPEECH_GoodEvening,         {34, 0,  0}},
    {SPEECH_Damaged,             {15, 0,  0}},
    {SPEECH_Weak,                {0,  0,  0}},
    {SPEECH_Fear,                {22, 0,  0}},
    {SPEECH_Poisoned,            {20, 0,  0}},
    {SPEECH_Diseased,            {20, 0,  0}},
    {SPEECH_Insane,              {19, 0,  0}},
    {SPEECH_Cursed,              {21, 0,  0}},
    {SPEECH_Drunk,               {18, 0,  0}},
    {SPEECH_Unconscious,         {0,  0,  0}},
    {SPEECH_Dead,                {17, 0,  0}},
    {SPEECH_Petrified,           {0,  0,  0}},
    {SPEECH_Eradicated,          {17, 0,  0}},
    {SPEECH_DrinkPotion,         {0,  0,  0}},
    {SPEECH_ReadScroll,          {0,  0,  0}},
    {SPEECH_NotEnoughGold,       {24, 0,  0}},
    {SPEECH_CantEquip,           {31, 0,  0}},
    {SPEECH_ItemBroken,          {0,  0,  0}},
    {SPEECH_SPDrained,           {0,  0,  0}},
    {SPEECH_Aging,               {0,  0,  0}},
    {SPEECH_SpellFailed,         {0,  0,  0}},
    {SPEECH_DamagedParty,        {0,  0,  0}},
    {SPEECH_Tired,               {0,  0,  0}},
    {SPEECH_EnterDungeon,        {41, 0,  0}},
    {SPEECH_LeaveDungeon,        {40, 0,  0}},
    {SPEECH_BadlyHurt,           {16, 0,  0}},
    {SPEECH_CastSpell,           {0,  0,  0}},
    {SPEECH_Shoot,               {0,  0,  0}},
    {SPEECH_AttackHit,           {0,  0,  0}},
    {SPEECH_AttackMiss,          {0,  0,  0}},
    {SPEECH_Beg,                 {0,  0,  0}},
    {SPEECH_BegFail,             {0,  0,  0}},
    {SPEECH_Threat,              {0,  0,  0}},
    {SPEECH_ThreatFail,          {0,  0,  0}},
    {SPEECH_Bribe,               {0,  0,  0}},
    {SPEECH_BribeFail,           {0,  0,  0}},
    {SPEECH_NPCDontTalk,         {0,  0,  0}},
    {SPEECH_FoundItem,           {0,  0,  0}},
    {SPEECH_HireNPC,             {0,  0,  0}},
    {SPEECH_62,                  {0,  0,  0}},
    {SPEECH_LookUp,              {0,  0,  0}},
    {SPEECH_LookDown,            {0,  0,  0}},
    {SPEECH_Yell,                {47, 0,  0}},
    {SPEECH_Falling,             {22, 0,  0}},
    {SPEECH_PacksFull,           {0,  0,  0}},
    {SPEECH_TavernDrink,         {0,  0,  0}},
    {SPEECH_TavernGotDrunk,      {0,  0,  0}},
    {SPEECH_TavernTip,           {0,  0,  0}},
    {SPEECH_TravelHorse,         {0,  0,  0}},
    {SPEECH_TravelBoat,          {0,  0,  0}},
    {SPEECH_ShopIdentify,        {0,  0,  0}},
    {SPEECH_ShopRepair,          {0,  0,  0}},
    {SPEECH_ItemBuy,             {0,  0,  0}},
    {SPEECH_AlreadyIdentified,   {0,  0,  0}},
    {SPEECH_ItemSold,            {0,  0,  0}},
    {SPEECH_SkillLearned,        {0,  0,  0}},
    {SPEECH_WrongShop,           {0,  0,  0}},
    {SPEECH_ShopRude,            {44, 0,  0}},
    {SPEECH_BankDeposit,         {0,  0,  0}},
    {SPEECH_TempleHeal,          {0,  0,  0}},
    {SPEECH_TempleDonate,        {0,  0,  0}},
    {SPEECH_HelloHouse,          {32, 33, 0}},
    {SPEECH_SkillMasteryInc,     {0,  0,  0}},
    {SPEECH_JoinedGuild,         {0,  0,  0}},
    {SPEECH_LevelUp,             {0,  0,  0}},
    {SPEECH_88,                  {0,  0,  0}},
    {SPEECH_89,                  {0,  0,  0}},
    {SPEECH_90,                  {0,  0,  0}},
    {SPEECH_StatBonusInc,        {0,  0,  0}},
    {SPEECH_StatBaseInc,         {0,  0,  0}},
    {SPEECH_QuestGot,            {0,  0,  0}},
    {SPEECH_94,                  {0,  0,  0}},
    {SPEECH_95,                  {0,  0,  0}},
    {SPEECH_AwardGot,            {0,  0,  0}},
    {SPEECH_97,                  {0,  0,  0}},
    {SPEECH_AfraidSilent,        {0,  0,  0}},
    {SPEECH_CheatedDeath,        {0,  0,  0}},
    {SPEECH_InPrison,            {0,  0,  0}},
    {SPEECH_101,                 {0,  0,  0}},
    {SPEECH_PickMe,              {4,  0,  0}},
    {SPEECH_Awaken,              {0,  0,  0}},
    {SPEECH_IDMonsterWeak,       {10, 0,  0}},
    {SPEECH_IDMonsterStrong,     {11, 0,  0}},
    {SPEECH_IDMonsterFail,       {12, 0,  0}},
    {SPEECH_LastManStanding,     {39, 0,  0}},
    {SPEECH_NotEnoughFood,       {14, 0,  0}},
    {SPEECH_DeathBlow,           {17, 0,  0}},
    {SPEECH_110,                 {0,  0,  0}} // initially this entry was not present in array
};

IndexedArray<std::array<unsigned char, 5>, SPEECH_FIRST, SPEECH_LAST> expressionVariants = {{
    {SPEECH_None,                {0,  0,  0,  0,  0}},
    {SPEECH_KillWeakEnemy,       {37, 38, 45, 0,  0}},
    {SPEECH_KillStrongEnemy,     {47, 53, 0,  0,  0}},
    {SPEECH_StoreClosed,         {25, 0,  0,  0,  0}},
    {SPEECH_TrapDisarmed,        {47, 0,  0,  0,  0}},
    {SPEECH_TrapExploded,        {41, 42, 0,  0,  0}},
    {SPEECH_AvoidDamage,         {33, 0,  0,  0,  0}},
    {SPEECH_IndentifyItemWeak,   {21, 22, 23, 24, 45}},
    {SPEECH_IndentifyItemStrong, {47, 0,  0,  0,  0}},
    {SPEECH_IndentifyItemFail,   {43, 48, 0,  0,  0}},
    {SPEECH_RepairSuccess,       {38, 0,  0,  0,  0}},
    {SPEECH_RepairFail,          {39, 0,  0,  0,  0}},
    {SPEECH_SetQuickSpell,       {37, 38, 0,  0,  0}},
    {SPEECH_CantRestHere,        {25, 0,  0,  0,  0}},
    {SPEECH_SkillIncrease,       {37, 38, 45, 0,  0}},
    {SPEECH_NoRoom,              {25, 0,  0,  0,  0}},
    {SPEECH_PotionSuccess,       {38, 47, 0,  0,  0}},
    {SPEECH_PotionExplode,       {41, 42, 0,  0,  0}},
    {SPEECH_DoorLocked,          {25, 0,  0,  0,  0}},
    {SPEECH_WontBudge,           {51, 0,  0,  0,  0}},
    {SPEECH_CantLearnSpell,      {25, 0,  0,  0,  0}},
    {SPEECH_LearnSpell,          {27, 0,  0,  0,  0}},
    {SPEECH_GoodDay,             {37, 38, 0,  0,  0}},
    {SPEECH_GoodEvening,         {53, 0,  0,  0,  0}},
    {SPEECH_Damaged,             {34, 35, 36, 0,  0}},
    {SPEECH_Weak,                {3,  0,  0,  0,  0}},
    {SPEECH_Fear,                {5,  0,  0,  0,  0}},
    {SPEECH_Poisoned,            {8,  0,  0,  0,  0}},
    {SPEECH_Diseased,            {9,  0,  0,  0,  0}},
    {SPEECH_Insane,              {7,  0,  0,  0,  0}},
    {SPEECH_Cursed,              {2,  0,  0,  0,  0}},
    {SPEECH_Drunk,               {6,  0,  0,  0,  0}},
    {SPEECH_Unconscious,         {11, 0,  0,  0,  0}},
    {SPEECH_Dead,                {0,  0,  0,  0,  0}},
    {SPEECH_Petrified,           {12, 0,  0,  0,  0}},
    {SPEECH_Eradicated,          {0,  0,  0,  0,  0}},
    {SPEECH_DrinkPotion,         {37, 0,  0,  0,  0}},
    {SPEECH_ReadScroll,          {49, 0,  0,  0,  0}},
    {SPEECH_NotEnoughGold,       {25, 0,  0,  0,  0}},
    {SPEECH_CantEquip,           {25, 0,  0,  0,  0}},
    {SPEECH_ItemBroken,          {41, 42, 0,  0,  0}},
    {SPEECH_SPDrained,           {39, 48, 0,  0,  0}},
    {SPEECH_Aging,               {46, 0,  0,  0,  0}},
    {SPEECH_SpellFailed,         {39, 48, 0,  0,  0}},
    {SPEECH_DamagedParty,        {41, 42, 0,  0,  0}},
    {SPEECH_Tired,               {39, 48, 0,  0,  0}},
    {SPEECH_EnterDungeon,        {21, 0,  0,  0,  0}},
    {SPEECH_LeaveDungeon,        {21, 0,  0,  0,  0}},
    {SPEECH_BadlyHurt,           {46, 0,  0,  0,  0}},
    {SPEECH_CastSpell,           {40, 0,  0,  0,  0}},
    {SPEECH_Shoot,               {39, 0,  0,  0,  0}},
    {SPEECH_AttackHit,           {37, 38, 0,  0,  0}},
    {SPEECH_AttackMiss,          {48, 49, 50, 0,  0}},
    {SPEECH_Beg,                 {44, 0,  0,  0,  0}},
    {SPEECH_BegFail,             {48, 0,  0,  0,  0}},
    {SPEECH_Threat,              {37, 38, 45, 0,  0}},
    {SPEECH_ThreatFail,          {41, 42, 0,  0,  0}},
    {SPEECH_Bribe,               {47, 0,  0,  0,  0}},
    {SPEECH_BribeFail,           {39, 48, 0,  0,  0}},
    {SPEECH_NPCDontTalk,         {39, 48, 0,  0,  0}},
    {SPEECH_FoundItem,           {37, 38, 0,  0,  0}},
    {SPEECH_HireNPC,             {37, 38, 0,  0,  0}},
    {SPEECH_62,                  {37, 38, 0,  0,  0}},
    {SPEECH_LookUp,              {31, 0,  0,  0,  0}},
    {SPEECH_LookDown,            {32, 0,  0,  0,  0}},
    {SPEECH_Yell,                {46, 0,  0,  0,  0}},
    {SPEECH_Falling,             {5,  0,  0,  0,  0}},
    {SPEECH_PacksFull,           {25, 0,  0,  0,  0}},
    {SPEECH_TavernDrink,         {37, 0,  0,  0,  0}},
    {SPEECH_TavernGotDrunk,      {52, 0,  0,  0,  0}},
    {SPEECH_TavernTip,           {45, 0,  0,  0,  0}},
    {SPEECH_TravelHorse,         {27, 0,  0,  0,  0}},
    {SPEECH_TravelBoat,          {37, 38, 0,  0,  0}},
    {SPEECH_ShopIdentify,        {49, 0,  0,  0,  0}},
    {SPEECH_ShopRepair,          {48, 0,  0,  0,  0}},
    {SPEECH_ItemBuy,             {37, 38, 45, 0,  0}},
    {SPEECH_AlreadyIdentified,   {48, 0,  0,  0,  0}},
    {SPEECH_ItemSold,            {37, 38, 45, 0,  0}},
    {SPEECH_SkillLearned,        {47, 0,  0,  0,  0}},
    {SPEECH_WrongShop,           {48, 0,  0,  0,  0}},
    {SPEECH_ShopRude,            {39, 48, 0,  0,  0}},
    {SPEECH_BankDeposit,         {48, 49, 0,  0,  0}},
    {SPEECH_TempleHeal,          {38, 0,  0,  0,  0}},
    {SPEECH_TempleDonate,        {31, 0,  0,  0,  0}},
    {SPEECH_HelloHouse,          {37, 38, 0,  0,  0}},
    {SPEECH_SkillMasteryInc,     {37, 38, 0,  0,  0}},
    {SPEECH_JoinedGuild,         {37, 38, 0,  0,  0}},
    {SPEECH_LevelUp,             {47, 0,  0,  0,  0}},
    {SPEECH_88,                  {38, 0,  0,  0,  0}},
    {SPEECH_89,                  {48, 0,  0,  0,  0}},
    {SPEECH_90,                  {0,  0,  0,  0,  0}},
    {SPEECH_StatBonusInc,        {38, 0,  0,  0,  0}},
    {SPEECH_StatBaseInc,         {47, 0,  0,  0,  0}},
    {SPEECH_QuestGot,            {38, 0,  0,  0,  0}},
    {SPEECH_94,                  {0,  0,  0,  0,  0}},
    {SPEECH_95,                  {0,  0,  0,  0,  0}},
    {SPEECH_AwardGot,            {38, 0,  0,  0,  0}},
    {SPEECH_97,                  {38, 0,  0,  0,  0}},
    {SPEECH_AfraidSilent,        {5,  0,  0,  0,  0}},
    {SPEECH_CheatedDeath,        {37, 38, 0,  0,  0}},
    {SPEECH_InPrison,            {44, 0,  0,  0,  0}},
    {SPEECH_101,                 {48, 0,  0,  0,  0}},
    {SPEECH_PickMe,              {0,  0,  0,  0,  0}},
    {SPEECH_Awaken,              {58, 0,  0,  0,  0}},
    {SPEECH_IDMonsterWeak,       {45, 0,  0,  0,  0}},
    {SPEECH_IDMonsterStrong,     {47, 0,  0,  0,  0}},
    {SPEECH_IDMonsterFail,       {43, 48, 0,  0,  0}},
    {SPEECH_LastManStanding,     {48, 0,  0,  0,  0}},
    {SPEECH_NotEnoughFood,       {48, 0,  0,  0,  0}},
    {SPEECH_DeathBlow,           {0,  0,  0,  0,  0}},
    {SPEECH_110,                 {0,  0,  0,  0,  0}} // initially this entry was not present in array
}};

std::array<int16_t, 4> pPlayerPortraitsXCoords_For_PlayerBuffAnimsDrawing = {{34, 149, 264, 379}};

IndexedArray<PLAYER_SKILL_LEVEL, PLAYER_SKILL_FIRST, PLAYER_SKILL_LAST> skills_max_level = {
    {PLAYER_SKILL_STAFF, 60},        {PLAYER_SKILL_SWORD, 60},      {PLAYER_SKILL_DAGGER, 60},
    {PLAYER_SKILL_AXE, 60},          {PLAYER_SKILL_SPEAR, 60},      {PLAYER_SKILL_BOW, 60},
    {PLAYER_SKILL_MACE, 60},         {PLAYER_SKILL_BLASTER, 60},    {PLAYER_SKILL_SHIELD, 60},
    {PLAYER_SKILL_LEATHER, 60},      {PLAYER_SKILL_CHAIN, 60},      {PLAYER_SKILL_PLATE, 60},
    {PLAYER_SKILL_FIRE, 60},         {PLAYER_SKILL_AIR, 60},        {PLAYER_SKILL_WATER, 60},
    {PLAYER_SKILL_EARTH, 60},        {PLAYER_SKILL_SPIRIT, 60},     {PLAYER_SKILL_MIND, 60},
    {PLAYER_SKILL_BODY, 60},         {PLAYER_SKILL_LIGHT, 60},      {PLAYER_SKILL_DARK, 60},
    {PLAYER_SKILL_ITEM_ID, 60},      {PLAYER_SKILL_MERCHANT, 60},   {PLAYER_SKILL_REPAIR, 60},
    {PLAYER_SKILL_BODYBUILDING, 60}, {PLAYER_SKILL_MEDITATION, 60}, {PLAYER_SKILL_PERCEPTION, 60},
    {PLAYER_SKILL_DIPLOMACY, 60},    {PLAYER_SKILL_THIEVERY, 60},   {PLAYER_SKILL_TRAP_DISARM, 60},
    {PLAYER_SKILL_DODGE, 60},        {PLAYER_SKILL_UNARMED, 60},    {PLAYER_SKILL_MONSTER_ID, 60},
    {PLAYER_SKILL_ARMSMASTER, 60},   {PLAYER_SKILL_STEALING, 60},   {PLAYER_SKILL_ALCHEMY, 60},
    {PLAYER_SKILL_LEARNING, 60},     {PLAYER_SKILL_CLUB, 1},        {PLAYER_SKILL_MISC, 1}
};

IndexedArray<uint, PLAYER_SKILL_FIRST, PLAYER_SKILL_LAST> base_recovery_times_per_weapon_type = {
    {PLAYER_SKILL_STAFF, 100},       {PLAYER_SKILL_SWORD, 90},      {PLAYER_SKILL_DAGGER, 60},
    {PLAYER_SKILL_AXE, 100},         {PLAYER_SKILL_SPEAR, 80},      {PLAYER_SKILL_BOW, 100},
    {PLAYER_SKILL_MACE, 80},         {PLAYER_SKILL_BLASTER, 30},    {PLAYER_SKILL_SHIELD, 10},
    {PLAYER_SKILL_LEATHER, 10},      {PLAYER_SKILL_CHAIN, 20},      {PLAYER_SKILL_PLATE, 30},

    /* Recovery penalty for wetsuits. */
    {PLAYER_SKILL_MISC, 0},

    /* In MM6 clubs had 100 base recovery, in MM7/MM8 they doesn't have base recovery and so they always capped by minimal recovery for melee weapons (30)
     * Is that change was intentional to make them more viable or they were just forgotten? */
    {PLAYER_SKILL_CLUB, 100},

    /* Skills below aren't accessed, they are here just to make IndexedArray's assert happy. */
    {PLAYER_SKILL_FIRE, 0},          {PLAYER_SKILL_AIR, 0},         {PLAYER_SKILL_WATER, 0},
    {PLAYER_SKILL_EARTH, 0},         {PLAYER_SKILL_SPIRIT, 0},      {PLAYER_SKILL_MIND, 0},
    {PLAYER_SKILL_BODY, 0},          {PLAYER_SKILL_LIGHT, 0},       {PLAYER_SKILL_DARK, 0},
    {PLAYER_SKILL_ITEM_ID, 0},       {PLAYER_SKILL_MERCHANT, 0},    {PLAYER_SKILL_REPAIR, 0},
    {PLAYER_SKILL_BODYBUILDING, 0},  {PLAYER_SKILL_MEDITATION, 0},  {PLAYER_SKILL_PERCEPTION, 0},
    {PLAYER_SKILL_DIPLOMACY, 0},     {PLAYER_SKILL_THIEVERY, 0},    {PLAYER_SKILL_TRAP_DISARM, 0},
    {PLAYER_SKILL_DODGE, 0},         {PLAYER_SKILL_UNARMED, 0},     {PLAYER_SKILL_MONSTER_ID, 0},
    {PLAYER_SKILL_ARMSMASTER, 0},    {PLAYER_SKILL_STEALING, 0},    {PLAYER_SKILL_ALCHEMY, 0},
    {PLAYER_SKILL_LEARNING, 0}
};

// byte[] @ MM7.exe::004ED820, some of these are started at 4ED94C, but needs to be here
std::array<IndexedArray<CLASS_SKILL, PLAYER_SKILL_FIRST, PLAYER_SKILL_LAST>, 9> pSkillAvailabilityPerClass = {{
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AXE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BOW, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MACE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_WATER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_AXE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BOW, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MACE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_WATER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_AXE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BOW, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MACE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_WATER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_AXE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BOW, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MACE, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_WATER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AXE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BOW, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_MACE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_AIR, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_WATER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_AXE, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BOW, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MACE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_WATER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AXE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BOW, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MACE, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_WATER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MIND, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BODY, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_AXE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BOW, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MACE, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_AIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_WATER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    },
    {
        {PLAYER_SKILL_STAFF, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_SWORD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DAGGER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_AXE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SPEAR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BOW, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MACE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BLASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_SHIELD, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LEATHER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_CHAIN, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PLATE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_FIRE, CLASS_SKILL_PRIMARY},
        {PLAYER_SKILL_AIR, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_WATER, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_EARTH, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_SPIRIT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MIND, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_LIGHT, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DARK, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ITEM_ID, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MERCHANT, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_REPAIR, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_BODYBUILDING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MEDITATION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_PERCEPTION, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DIPLOMACY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_THIEVERY, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_TRAP_DISARM, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_DODGE, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_UNARMED, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_MONSTER_ID, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_ARMSMASTER, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_STEALING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_ALCHEMY, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_LEARNING, CLASS_SKILL_DENIED},
        {PLAYER_SKILL_CLUB, CLASS_SKILL_AVAILABLE},
        {PLAYER_SKILL_MISC, CLASS_SKILL_AVAILABLE}
    }
}};
std::array<IndexedArray<PLAYER_SKILL_MASTERY, PLAYER_SKILL_FIRST, PLAYER_SKILL_LAST>, 36> byte_4ED970_skill_learn_ability_by_class_table = {{
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Knight
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Thief
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Monk
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Paladin
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Archer
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Ranger
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Cleric
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Druid
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },  // Sorcerer
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    },
    {
        {PLAYER_SKILL_STAFF, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_SWORD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DAGGER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_AXE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_SPEAR, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BOW, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MACE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BLASTER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SHIELD, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LEATHER, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_CHAIN, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_PLATE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_FIRE, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_AIR, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_WATER, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_EARTH, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_SPIRIT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MIND, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_BODY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_LIGHT, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DARK, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ITEM_ID, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_MERCHANT, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_REPAIR, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_BODYBUILDING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MEDITATION, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_PERCEPTION, PLAYER_SKILL_MASTERY_EXPERT},
        {PLAYER_SKILL_DIPLOMACY, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_THIEVERY, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_TRAP_DISARM, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_DODGE, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_UNARMED, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_MONSTER_ID, PLAYER_SKILL_MASTERY_GRANDMASTER},
        {PLAYER_SKILL_ARMSMASTER, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_STEALING, PLAYER_SKILL_MASTERY_NONE},
        {PLAYER_SKILL_ALCHEMY, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_LEARNING, PLAYER_SKILL_MASTERY_MASTER},
        {PLAYER_SKILL_CLUB, PLAYER_SKILL_MASTERY_NOVICE},
        {PLAYER_SKILL_MISC, PLAYER_SKILL_MASTERY_NOVICE}
    }
}};
std::array<unsigned int, 2> pHiredNPCsIconsOffsetsX = {{489, 559}};
std::array<unsigned int, 2> pHiredNPCsIconsOffsetsY = {{152, 152}};
std::array<short, 28> word_4EE150 = {{1,  2,  3,  4,  5,  7,  32, 33, 36, 37,
                                      38, 40, 41, 42, 43, 45, 46, 47, 48, 49,
                                      50, 51, 52, 53, 54, 55, 56, 60}};

std::array<int, 32> guild_membership_flags = {
    {54, 54, 54, 54, 52, 52, 52, 52, 55, 55, 55, 55, 53, 53, 53, 53,
     58, 58, 58, 58, 57, 57, 57, 57, 56, 56, 56, 56, 59, 59, 60, 60}};
std::array<int16_t, 49> word_4F0754;
std::array<std::pair<int16_t, ITEM_TYPE>, 27> _4F0882_evt_VAR_PlayerItemInHands_vals = {{
    {0x0D4, ITEM_QUEST_VASE},
    {0x0D5, ITEM_RARE_LADY_CARMINES_DAGGER},
    {0x0D6, ITEM_MESSAGE_SCROLL_OF_WAVES},
    {0x0D7, ITEM_MESSAGE_CIPHER},
    {0x0D8, ITEM_QUEST_WORN_BELT},
    {0x0D9, ITEM_QUEST_HEART_OF_THE_WOOD},
    {0x0DA, ITEM_MESSAGE_MAP_TO_EVENMORN_ISLAND},
    {0x0DB, ITEM_QUEST_GOLEM_HEAD},
    {0x0DC, ITEM_QUEST_ABBEY_NORMAL_GOLEM_HEAD},
    {0x0DD, ITEM_QUEST_GOLEM_RIGHT_ARM},
    {0x0DE, ITEM_QUEST_GOLEM_LEFT_ARM},
    {0x0DF, ITEM_QUEST_GOLEM_RIGHT_LEG},
    {0x0E0, ITEM_QUEST_GOLEM_LEFT_LEG},
    {0x0E1, ITEM_QUEST_GOLEM_CHEST},
    {0x0E2, ITEM_SPELLBOOK_DIVINE_INTERVENTION},
    {0x0E3, ITEM_QUEST_DRAGON_EGG},
    {0x0E4, ITEM_QUEST_ZOKARR_IVS_SKULL},
    {0x0E5, ITEM_QUEST_LICH_JAR_EMPTY},
    {0x0E6, ITEM_QUEST_ELIXIR},
    {0x0E7, ITEM_QUEST_CASE_OF_SOUL_JARS},
    {0x0E8, ITEM_QUEST_ALTAR_PIECE_1},
    {0x0E9, ITEM_QUEST_ALTAR_PIECE_2},
    {0x0EA, ITEM_QUEST_CONTROL_CUBE},
    {0x0EB, ITEM_QUEST_WETSUIT},
    {0x0EC, ITEM_QUEST_OSCILLATION_OVERTHRUSTER},
    {0x0ED, ITEM_QUEST_LICH_JAR_FULL},
    {0x0F1, ITEM_RARE_THE_PERFECT_BOW}
}};
std::array<unsigned short, 6> pMaxLevelPerTrainingHallType = {{5, 15, 25, 25, 200, 200}};

std::array<int, 11> price_for_membership = {{100, 100, 50, 50, 50, 50, 50, 50, 50, 1000, 1000}};

std::array<int16_t, 32> word_4F0F30 = {{
    4, 7, 10, 11, 4, 7, 10, 11, 4, 7, 10, 11, 4, 7,  10, 11,
    4, 7, 10, 11, 4, 7, 10, 11, 4, 7, 10, 11, 7, 11, 7,  11
}};

int ai_arrays_size;
std::array<int, 500> ai_array_detected_actor_dist;
std::array<int, 500> ai_array_detected_actor_ids;
std::array<int, 500> ai_near_actors_targets_pid;
std::array<int, 500> ai_near_actors_distances;
std::array<unsigned int, 500> ai_near_actors_ids;

char byte_4FAA24;  // turn over break??
// HWND dword_4FAA28; // idb

// std::array<unsigned int, 480> pSRZBufferLineOffsets;
std::array<char, 777> books_num_items_per_page;
int CurrentLloydPlayerID;
int LloydsBeaconSpellDuration;  // 604800 * spell level
int MapBookOpen;
int books_page_number;
int books_primary_item_per_page;
int Autonotes_Instructors_page_flag;  // dword_50652C
int Autonotes_Misc_page_flag;         // dword_506530
int Book_PageBtn6_flag;               // dword_506534
int Book_PageBtn5_flag;               // dword_506538
int Book_PageBtn4_flag;               // dword_50653C
int Book_PageBtn3_flag;               // dword_506540
int BtnDown_flag;                     // BtnDown_flag
int BtnUp_flag;                       // BtnUp_flag
int quick_spell_at_page;
char byte_506550;
AUTONOTE_TYPE _506568_autonote_type;
bool bRecallingBeacon;
int uLastPointedObjectID;
// uint8_t bMonsterInfoUI_bDollInitialized;
int dword_506980_uW;
int dword_506984_uZ;
int dword_506988_uY;
int dword_50698C_uX;
int KeyboardPageNum;
int uRestUI_FoodRequiredToRest;
int _506F14_resting_stage;
int _506F18_num_minutes_to_sleep;
int dword_506F1C;
char bFlashHistoryBook;
char bFlashAutonotesBook;
char bFlashQuestBook;
GUIButton *pBtn_ZoomOut;  // idb
GUIButton *pBtn_ZoomIn;  // idb
unsigned int uGameUIFontShadow;
unsigned int uGameUIFontMain;
int dword_507B00_spell_info_to_draw_in_popup;
int dword_507BF0_is_there_popup_onscreen;
int awards_scroll_bar_created;
int dword_507CC0_activ_ch;
GameTime GameUI_RightPanel_BookFlashTimer;
int _507CD4_RestUI_hourglass_anim_controller;
bool OpenedTelekinesis;
std::array<int, 50> dword_50B570;
std::array<int, 50> dword_50B638;
stru367 PortalFace;
std::array<int, 100> dword_50BC10;
std::array<int, 100> dword_50BDA0;
char TownPortalCasterId;
int some_active_character;
std::array<unsigned int, 5> pIconIDs_Turn;
unsigned int uIconID_TurnStop;
unsigned int uIconID_TurnHour;
int uIconID_CharacterFrame;  // idb
unsigned int uIconID_TurnStart;
int dword_50C994 = 0;
int dword_50C998_turnbased_icon_1A = 0;
int uSpriteID_Spell11;  // idb
bool IsEnchantingInProgress;
int ItemEnchantmentTimer;
UIMessageType AfterEnchClickEventId;
int AfterEnchClickEventSecondParam;
int AfterEnchClickEventTimeout;
UIMessageType GateMasterEventId;
struct NPCData *GateMasterNPCData;
// int dword_50C9E8; // idb
// int dword_50C9EC[120];
int dword_50CDC8;
std::array<char, 54> party_has_equipment;

unsigned int uNumBlueFacesInBLVMinimap;
std::array<uint16_t, 50> pBlueFacesInBLVMinimapIDs;

std::array<class Image *, 14> party_buff_icons;
unsigned int uIconIdx_FlySpell;
unsigned int uIconIdx_WaterWalk;
GameTime _5773B8_event_timer;

struct Actor *pDialogue_SpeakingActor;
DIALOGUE_TYPE uDialogueType;
int sDialogue_SpeakingActorNPC_ID;
struct LevelDecoration *_591094_decoration; // level decoration store for branchless dialogue
int uCurrentHouse_Animation;
char *Party_Teleport_Map_Name;
// int Party_Teleport_Z_Speed;
// int Party_Teleport_Cam_Pitch;
// int Party_Teleport_Cam_Yaw;
// int Party_Teleport_Z_Pos;
// int Party_Teleport_Y_Pos;
// int Party_Teleport_X_Pos;
std::array<std::array<char, 100>, 6> byte_591180;  // idb
std::array<struct NPCData *, 7> HouseNPCData;  // 0 zero element holds standart house npc
GUIButton *HouseNPCPortraitsButtonsList[6];  // dword_5913F4
std::string branchless_dialogue_str;
int EvtTargetObj;                               // 0x5B5920
int _unused_5B5924_is_travel_ui_drawn = false;  // 005B5924
int Party_Teleport_X_Pos;
int Party_Teleport_Y_Pos;
int Party_Teleport_Z_Pos;
int Party_Teleport_Cam_Yaw;
int Party_Teleport_Cam_Pitch;
int Party_Teleport_Z_Speed;
int Start_Party_Teleport_Flag;
int dword_5B65C4_cancelEventProcessing;
int MapsLongTimers_count;  // dword_5B65C8 счётчик таймеров для колодцев,
                           // фаерволов-ловушек
int npcIdToDismissAfterDialogue;
signed int dword_5B65D0_dialogue_actor_npc_id;
int dword_5C3418; //  eventid store for branchless dialogue
int dword_5C341C; // entry line store for branchless dialogue
// std::array<char, 777> byte_5C3427;

// TODO(pskelton): GameStatusBar class
std::string game_ui_status_bar_event_string;
std::string game_ui_status_bar_string;
unsigned int game_ui_status_bar_event_string_time_left; // this is platform->tickcount till elapsed

int bForceDrawFooter;
int _5C35C0_force_party_death = false;
int bDialogueUI_InitializeActor_NPC_ID;
std::string p2DEventsTXT_Raw;

int dword_5C35D4;
char byte_5C45AF[777];

std::array<char, 100> Journal_limitation_factor;
int ui_current_text_color;
int64_t qword_5C6DF0;
char *pHealthPointsAttributeDescription;
char *pSpellPointsAttributeDescription;
char *pArmourClassAttributeDescription;
char *pPlayerConditionAttributeDescription;  // idb
char *pFastSpellAttributeDescription;
char *pPlayerAgeAttributeDescription;
char *pPlayerLevelAttributeDescription;
char *pPlayerExperienceAttributeDescription;
char *pAttackBonusAttributeDescription;
char *pAttackDamageAttributeDescription;
char *pMissleBonusAttributeDescription;
char *pMissleDamageAttributeDescription;
char *pFireResistanceAttributeDescription;
char *pAirResistanceAttributeDescription;
char *pWaterResistanceAttributeDescription;
char *pEarthResistanceAttributeDescription;
char *pMindResistanceAttributeDescription;
char *pBodyResistanceAttributeDescription;
char *pSkillPointsAttributeDescription;

struct FactionTable *pFactionTable;
// std::array<char, 777> byte_5C8D1A;

std::array<char, 777> byte_5E4C15;

std::string pMonstersTXT_Raw;
std::string pMonsterPlacementTXT_Raw;
std::string pSpellsTXT_Raw;
char *pMapStatsTXT_Raw = nullptr;
std::string pHostileTXT_Raw;
char *pPotionsTXT_Raw = nullptr;
char *pPotionNotesTXT_Raw = nullptr;

std::array<int, 777> _6807B8_level_decorations_ids;  // idb -level decoratiosn sound
int _6807E0_num_decorations_with_sounds_6807B8;
std::array<int, 3000> event_triggers;  // 6807E8
size_t num_event_triggers;             // 6836C8
std::array<int, 64> dword_69B010;
float flt_69B138_dist;
char byte_69BD41_unused;
int pSaveListPosition;
unsigned int uLoadGameUI_SelectedSlot;
char cMM7GameCDDriveLetter;  // idb
int uDefaultTravelTime_ByFoot;
int day_attrib;
int day_fogrange_1; // fog start dist
int day_fogrange_2; // fog end dist
struct TileTable *pTileTable;                                        // idb
std::array<char, 777> pDefaultSkyTexture;                            // idb
std::array<char, 16> byte_6BE124_cfg_textures_DefaultGroundTexture;  // idb
int _6BE134_odm_main_tile_group;
int dword_6BE138;  // are you sure check game menu - load slots
int dword_6BE13C_uCurrentlyLoadedLocationID;
float fWalkSpeedMultiplier = 1.0f;
float fBackwardWalkSpeedMultiplier = 1.0f;
float fTurnSpeedMultiplier = 1.0f;
std::string pCurrentMapName;
unsigned int uLevelMapStatsID;
int dword_6BE364_game_settings_1 = 0;

float debug_non_combat_recovery_mul;
float debug_combat_recovery_mul;
float debug_turn_based_monster_movespeed_mul;
float flt_debugrecmod3;

std::string s_SavedMapName;  // idb
char bNoNPCHiring = false;
std::array<int, 100> dword_720020_zvalues;
std::array<int, 299> dword_7201B0_zvalues;
std::array<int16_t, 104> odm_floor_face_vert_coord_Y;  // word_720F70
std::array<int16_t, 104> odm_floor_face_vert_coord_X;  // word_721040
Vec3i blv_prev_party_pos;
std::array<NPCTopic, 789> pNPCTopics;
std::array<const char *, 513> pQuestTable;
char *dword_723718_autonote_related;  // idb
IndexedArray<const char *, ITEM_FIRST_MESSAGE_SCROLL, ITEM_LAST_MESSAGE_SCROLL> pScrolls;
int dword_7241C8;
std::string pAwardsTXT_Raw;
std::string pScrollsTXT_Raw;
std::string pMerchantsTXT_Raw;
IndexedArray<const char *, MERCHANT_PHRASE_COUNT> pMerchantsBuyPhrases;
IndexedArray<const char *, MERCHANT_PHRASE_COUNT> pMerchantsSellPhrases;
IndexedArray<const char *, MERCHANT_PHRASE_COUNT> pMerchantsRepairPhrases;
IndexedArray<const char *, MERCHANT_PHRASE_COUNT> pMerchantsIdentifyPhrases;
std::string pTransitionsTXT_Raw;
std::string pAutonoteTXT_Raw;
std::string pQuestsTXT_Raw;
std::vector<Vec3f> pTerrainNormals;
std::array<unsigned short, 128 * 128 * 2> pTerrainNormalIndices;
std::array<unsigned int, 128 * 128 * 2> pTerrainSomeOtherData;
int dword_A74C88;
int uPlayerCreationUI_ArrowAnim;
unsigned int uPlayerCreationUI_SelectedCharacter;
int dword_A74CDC;
int64_t _A750D8_player_speech_timer;  // qword_A750D8
int uSpeakingCharacter;
char byte_AE5B91;
std::array<int, 32> dword_F1B430;
// int dword_F8B144; // nexindex [-1] to the following
std::array<int, 4> player_levels = {{1, 1, 1, 1}};
std::array<int16_t, 6> weapons_Ypos;           // word_F8B158
int guild_membership_approved;
PLAYER_SKILL_MASTERY dword_F8B1B0_MasteryBeingTaught;
int gold_transaction_amount;  // F8B1B4
std::array<const char *, 4> pShopOptions;
int dword_F8B1E0;
int dword_F8B1E4;
std::string current_npc_text;                        // F8B1E8
char dialogue_show_profession_details = false;  // F8B1EC
std::array<char, 777> byte_F8B1EF;

int bGameoverLoop = 0;
