#ifndef __GAME_DEF_H__
#define __GAME_DEF_H__
#include <stdint.h>

#ifndef __fastcall
#define __fastcall
#endif
#ifndef __cdcel
#define __cdcel
#endif

#define __int8 char
#define __int16 short
#define __int32 int
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;

typedef  u32 (*_FUNC)();

#define FUNC32(x)  (*((u32 (*)())((x)+0)))
#define FUNC16(x)  (*((u32 (*)())((x)+1)))

#define P8(x)      ((u8 *)(x))
#define P16(x)      ((u16 *)(x))
#define P32(x)      ((u32 *)(x))

#define PS8(x)      ((s8 *)(x))
#define PS16(x)      ((s16 *)(x))
#define PS32(x)      ((s32 *)(x))

#define V8(x)      (*P8(x))
#define V16(x)      (*P16(x))
#define V32(x)      (*P32(x))

#define VS8(x)      (*PS8(x))
#define VS16(x)      (*PS16(x))
#define VS32(x)      (*PS32(x))

extern void pgm2log(const char *fmt, ...);
typedef struct ROLE_MEM ROLE_MEM;
typedef struct ROLE_CMD ROLE_CMD;
typedef struct IC_CARD IC_CARD;
struct __attribute__((aligned(4))) ROLE_MEM
{
  char Status;//0
  char PlayerNo;//
  char RoleId;
  char Lifes;
  ROLE_CMD *pCmdPtr;
  char DWORD_8;
  __int16 WORD_9;
  __int16 WORD_11;
  int DWORD_13;
  char Name[8];
  __int16 x;
  __int16 y;
  __int16 z;
  __int16 WORD_34;
  int DWORD_36;
  char DWORD_40;
  char DWORD_41;
  char DWORD_42;
  char DWORD_43;
  int DWORD_44;
  int DWORD_48;
  char BYTE_52;
  char BYTE_53;
  char BYTE_54;
  char BYTE_55;
  char BYTE_56;
  char BYTE_57;
  char BYTE_58;
  char BYTE_59;
  int DWORD_60;
  int DWORD_64;
  int DWORD_68;
  int DWORD_72;
  int DWORD_76;
  int DWORD_80;
  int DWORD_84;
  int DWORD_88;
  int DWORD_92;
  int DWORD_96;
  int DWORD_100;
  int DWORD_104;
  __int16 HP;
  __int16 WORD_110;
  int DWORD_112;
  int DWORD_116;
  int DWORD_120;
  int DWORD_124;
  int DWORD_128;
  __int16 WORD_132;
  __int16 WORD_134;
  int DWORD_136;
  int DWORD_140;
  int DWORD_144;
  int DWORD_148;
  int DWORD_152;
  int DWORD_156;
  int DWORD_160;
  int DWORD_164;
  int DWORD_168;
  int DWORD_172;
  int DWORD_176;
  int DWORD_180;
  char BYTE_184;
  char BYTE_185;
  char BYTE_186;
  char BYTE_187;
  int DWORD_188;
  int DWORD_192;
  int DWORD_196;
  __int16 Cash;
  char BYTE_202;
  char BYTE_203;
  signed int NowEXP;
  char BYTE_208;
  char BYTE_209;
  char Level;
  char BYTE_211;
  char BYTE_212;
  char BYTE_213;
  __int16 WORD_214;
  signed int NextEXP;
  char HPMax;
  char HPBarValue;
  __int16 WORD_222;
  int DWORD_224;
  char BYTE_228;
  char BYTE_229;
  char BYTE_230;
  char BYTE_231;
  int Score;
  int DWORD_236;
  __int16 WORD_240;
  char BYTE_242;
  char BYTE_243;
  char Powers;
  char BYTE_245;
  char BYTE_246;
  char BYTE_247;
  char PowersMax;
  char BYTE_249;
  char BYTE_250;
  char BYTE_251;
  int DWORD_252;
  char BYTE_256;
  char BYTE_257;
  char BYTE_258;
  char BYTE_259;
  int pRoleInfoPtr;
  __int16 WORD_264;
  __int16 WORD_266;
  int DWORD_268;
  __int16 WORD_272;
  __int16 WORD_274;
  int DWORD_276;
  char Limit_280;
  char PowersLimit;
  char SkillLimit;
  char AttackLimit;
  char BYTE_284;
  char BYTE_285;
  char Limit_286;
  char BYTE_287;
  char BYTE_288;
  char BYTE_289;
  char BYTE_290;
  char BYTE_291;
};



struct IC_CARD{//IC卡缓存结构体
  char BYTE_0;
  char Version;
  __int16 Credit;
  char Name[8];
  char Title;
  char RoleID;
  char OverTimes;
  char ContinueTimes;
  int NowEXP;
  int StoryScore;
  int ChallengeScore;
  int IRScore;
  __int16 Money;
  __int16 ItemGift;
  char ITEM_ID[6];
  char ITEM_NUM[6];
  __int16 ITEM_DURA[6];
  char WEAPON_ID[6];
  char WEAPON_NUM[6];
  __int16 WEAPON_DURA[6];
  char EQUIP_ID[9];
  char EQUIP_NUM[9];
  __int16 EQUIP_DURA[9];
  char BYTE_120;
  char BYTE_121;
  char BYTE_122;
  char BYTE_123;
};

struct ROLE_CMD
{
  int Off_0;
  int Off_4;
  int PlayerNo;
  __int16 Off_12;
  __int16 Off_14;
  __int16 Off_16;
  __int16 Off_18;
  __int16 Off_20;
  __int16 Off_22;
  __int16 Off_24;
  __int16 Off_26;
  __int16 Off_28;
  __int16 Off_30;
  __int16 Off_32;
  __int16 Off_34;
  __int16 Off_36;
  __int16 Off_38;
  int Off_40;
  int Off_44;
  int pImageAxisTbl;
  int pCollIndexTbl;
  int Off_56;
  __int16 Off_60;
  __int16 Off_62;
  __int16 Off_64;
  __int16 Off_66;
  int Off_68;
  int Off_72;
  __int16 Off_76;
  __int16 Off_78;
  int pRoleInfoROM_1;
  int pRoleInfoROM_2;
  int pImageTbl;
  __int16 Off_92;
  __int16 Off_94;
  int pWeaponPalPtr;
  int pBrom;
  int pArom;
  __int16 Off_108;
  __int16 WeaponPalOfft;
  int Off_112;
  int Off_116;
  int Off_120;
  int Off_124;
  __int16 Off_128;
  __int16 Off_130;
  __int16 Off_132;
  __int16 Off_134;
  __int16 Off_136;
  __int16 Off_138;
  __int16 Off_140;
  __int16 Off_142;
  __int16 Off_144;
  __int16 Off_146;
  __int16 Off_148;
  __int16 Off_150;
  __int16 Off_152;
  __int16 Off_154;
  __int16 Off_156;
  __int16 Off_158;
  __int16 Off_160;
  __int16 Off_162;
  __int16 Off_164;
  __int16 Off_166;
  __int16 Off_168;
  __int16 Off_170;
  __int16 Off_172;
  __int16 Off_174;
  int Off_176;
  __int16 Off_180;
  __int16 Off_182;
  __int16 Off_184;
  __int16 Off_186;
  __int16 Off_188;
  __int16 Off_190;
  int Off_192;
  __int16 Off_196;
  __int16 Off_198;
  __int16 Off_200;
  __int16 Off_202;
  __int16 Off_204;
  __int16 Off_206;
  int Off_208;
  int Off_212;
  __int16 Off_216;
  __int16 Off_218;
  int Off_220;
  int Off_224;
  int Off_228;
  int Off_232;
  int Off_236;
  int Off_240;
  int Off_244;
  int Off_248;
  int Off_252;
  __int16 RoleId_1;
  __int16 RoleId_2;
  int pRoleInfoRAM;
  __int16 Off_264;
  __int16 Off_266;
  int Off_268;
  int Off_272;
  int Off_276;
  __int16 Off_280;
  __int16 Off_282;
  int Off_284;
  int Off_288;
  __int16 Off_292;
  __int16 Off_294;
  __int16 Off_296;
  __int16 Off_298;
  __int16 Off_300;
  __int16 Off_302;
  __int16 Off_304;
  __int16 Off_306;
  __int16 Off_308;
  __int16 Off_310;
  __int16 Off_312;
  __int16 Off_314;
  __int16 Off_316;
  __int16 Off_318;
  __int16 Off_320;
  __int16 Off_322;
  char Off_324;
  char Off_325;
  char Off_326;
  char Off_327;
  char Off_328;
  char Off_329;
  char Off_330;
  char Off_331;
  char Off_332;
  char Off_333;
  char Off_334;
  char Off_335;
  char Off_336;
  char Off_337;
  char Off_338;
  char Off_339;
  char Off_340;
  char Off_341;
  char Off_342;
  char Off_343;
  char Off_344;
  char Off_345;
  char Off_346;
  char Off_347;
  char Off_348;
  char Off_349;
  char Off_350;
  char Off_351;
  char Off_352;
  char Off_353;
  char Off_354;
  char Off_355;
  char Off_356;
  char Off_357;
  char Off_358;
  char Off_359;
  __int16 Off_360;
  __int16 Off_362;
  int Off_364;
  int ppImageTbl;
  int Off_372;
  int Off_376;
  int Off_380;
  int Off_384;
  __int16 Off_388;
  __int16 UltraStateFlag;
  __int16 Off_392;
  __int16 Off_394;
  __int16 Off_396;
  __int16 Off_398;
  int Off_400;
  int Off_404;
  int Off_408;
  int Off_412;
  __int16 Off_416;
  __int16 Off_418;
  int Off_420;
  int Off_424;
  __int16 Off_428;
  __int16 Off_430;
  __int16 Off_432;
  __int16 Off_434;
  int Off_436;
  int Off_440;
  __int16 Off_444;
  __int16 Off_446;
  __int16 Off_448;
  __int16 Off_450;
  __int16 Off_452;
  __int16 Off_454;
  __int16 Off_456;
  __int16 Off_458;
  __int16 Off_460;
  __int16 Off_462;
  __int16 Off_464;
  __int16 Off_466;
  __int16 Off_468;
  __int16 Off_470;
  int Off_472;
  __int16 Off_476;
  __int16 Off_478;
  __int16 Off_480;
  __int16 Off_482;
  int Off_484;
  int Off_488;
  int Off_492;
  int Off_496;
  int Off_500;
  __int16 Off_504;
  __int16 Off_506;
  int Off_508;
  int Off_512;
  int Off_516;
  int Off_520;
  int Off_524;
  int Off_528;
  int Off_532;
  __int16 Off_536;
  __int16 Off_538;
  int Off_540;
  int Off_544;
  __int16 Off_548;
  __int16 Off_550;
  __int16 Off_552;
  __int16 Off_554;
  __int16 Off_556;
  __int16 Off_558;
  int Off_560;
  int Off_564;
  int Off_568;
  int Off_572;
  __int16 Off_576;
  __int16 Off_578;
  int Off_580;
  int Off_584;
  int Off_588;
  int Off_592;
  int Off_596;
  __int16 Off_600;
  __int16 Off_602;
  __int16 Off_604;
  __int16 Off_606;
  __int16 Off_608;
  __int16 Off_610;
  __int16 Off_612;
  __int16 Off_614;
  __int16 Off_616;
  __int16 Off_618;
  __int16 Off_620;
  __int16 Off_622;
  __int16 Off_624;
  __int16 Off_626;
  __int16 Off_628;
  __int16 Off_630;
  __int16 Off_632;
  __int16 Off_634;
  __int16 Off_636;
  __int16 Off_638;
  __int16 Off_640;
  __int16 Off_642;
  __int16 Off_644;
  __int16 Off_646;
  __int16 Off_648;
  __int16 Off_650;
  __int16 Off_652;
  __int16 Off_654;
  __int16 Off_656;
  __int16 Off_658;
  __int16 Off_660;
  __int16 Off_662;
  __int16 Off_664;
  __int16 Off_666;
  __int16 Off_668;
  __int16 Off_670;
  __int16 Off_672;
  __int16 Off_674;
  int Off_676;
  __int16 Off_680;
  __int16 Off_682;
  int Off_684;
  int Off_688;
  __int16 EquipWeapon;
  __int16 Off_694;
  int Off_696;
  int Off_700;
  __int16 Off_704;
  __int16 Off_706;
  int Off_708;
  int Off_712;
  __int16 Off_716;
  __int16 WeaponPalBaseOfft;
  int Off_720;
  int Off_724;
  int Off_728;
};

enum XYJ2GAMEMODE{
	MODE_STORY = 0,
	MODE_IR,
	MODE_BOSS,
};
#endif

