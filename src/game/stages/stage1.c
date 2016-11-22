#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../xyj2_func.h"
#include "../game_wave.h"


/*
*==========================================
*			STAGE 1 - 随机关卡
*==========================================
*/
extern void CreatMapObj(int a1,int a2,int a3,int a4,int a5,short MapPal,short a7,short a8,short a9,short a10,short a11);
extern void MotionInit();
#define MotionState	V8(0x20020610)
#define FlyBoxOBJ	V32(0x20020624)
#define BossCMD		V32(0x20020614)
#define SecretFlag1	V16(0x2002061)
void s1m1f1()
{
	short MapPal;
	int i;
	MotionInit();
	Play_Music_Repeat(WAVE_ST1_M1,104,0);
	LoadMapBit(0x10187048, 0);//载入地图 0层
	LoadMapBit(0x10183C10, 1);//载入地图 1层
	LoadMapMask(0x1019A544, 0, 160);//载入地图的Mask
	CreatItemBox(0, 1, 375, 168);
	CreatItemBox(0, 2, 155, 221);
	MapPal = SetMapBitPal(0x104F2EAC, 0, 0, 0);
	CreatMapObj(0x1033FB6C,117,0,167,1,MapPal,-2,0,1,7,6);//创建地图用的背景OBJ喷泉那些
	CreatMapObj(0x1033FB6C,553,0,187,0,MapPal,-2,0,1,7,6);
	CreatMapObj(0x1033FBC0,820,0,187,0,MapPal,-2,0,1,7,6);
	CreatMapObj(0x1033FB6C,956,0,167,0,MapPal,-2,0,1,7,6);
	CreatMapObj(0x1033FBC0,1223,0,167,0,MapPal,-2,0,1,7,6);
	CreatMapObj(0x1033FB6C,1397,0,167,0,MapPal,-2,0,1,7,6);
	
	SecretFlag1 = 0;
	V16(0x2002061A) = 0;
	V16(0x2002061C) = 0;
	V16(0x2002061E) = 0;
	V16(0x20020620) = 0;
	V8(0x20020628) = 1;	

	FlyBoxOBJ = CreatPicOBJ(0x1033FAA8, 714, 50, 0, 1);
	ExecPicCMD(FlyBoxOBJ, 0x1033F450);
	V16(FlyBoxOBJ+266) = 1;
	V16(FlyBoxOBJ+268) = 7;
	V16(FlyBoxOBJ+270) = 6;
	MapPal = sub_1004FBE2(FlyBoxOBJ+256, 6, 0, 0);
	sub_1004FF3C(MapPal, 0, 0);
	
	sub_1004F566(0, 8, 512, 248);
	sub_100337E0(1, 10);
	sub_100915BE();
	sub_100584B2();
	LoadRoroCMD(0x1033F444, 0);
	for ( i = 0; i < 15; ++i )
		ExecRoroCMD();
	sub_100BF4F2();
	sub_1002B94E(60);
	StopPlayerCtrl(1);	
	sub_10022584(0);
	sub_1002297C();
	sub_1001BDCC();
	sub_10091516();
	sub_10098146();	
	BossCMD = 0;
	MotionState = 0;
	

}

int s1m1f2()
{
	int i;
	ROLE_RAM *RoleRAM;
	IC_CARD *ICCard;
	ROLE_CMD *Player;
	int OBJ;
	short MoveFlag[4];
	int v9;
	int RoroCMD;
	int RoroACT;
	int result;
	pgm2log("%d",MotionState);
	if (MotionState < 16)
	{
		switch (MotionState)
		{
			case 0:
			//pgm2log("1");
				for (i=0;i<80;i++)
				{
					ExecRoroCMD();
					ScreenUpdate();
				}
				MotionState = 1;
				return 0;
			case 1:
				
				if (ExecRoroCMD())
				{
					if (GetPlayerCnt()>=3)
						CreatItemBox(1,3,918,233);
					LoadRoroCMD(0x1033F444,1);
					for (i=0;i<10;i++)
						ExecRoroCMD();
						ScreenUpdate();
					GoMessage(0,384,150,6,1);
					MotionState = 2;
				}
				
				return 0;
			case 2:
				sub_100917CC();
				if (GetRoleInBox(512,1024,248,0))
				{
					if (FlyBoxOBJ)
					{
						for (i=0;i<4;i++)
						{
							RoleRAM = (ROLE_RAM *)GetRoleInfoRAM(i);
							ICCard = (IC_CARD *)ReadICCardData(RoleRAM->PlayerNo);
							if ( (ICCard && ICCard->OverTimes>0) || sub_10065570())
								SecretFlag1 = 1;
						}
						SecretFlag1 = 1;
						if (SecretFlag1)
						{
							V16(0x2002061A) = 1;
							OBJ = CreatPicOBJ(
							0x1033FAA8,
							gDstX - V16(0x2002015C) - (V16(FlyBoxOBJ+268) * (gDstX>>3)) + (V16(FlyBoxOBJ+28)&0x7FF),
							gDstY - V16(0x2002015E) - (V16(FlyBoxOBJ+270) * (gDstY>>3)) + (V16(FlyBoxOBJ+30)&0x3FF),
							0,
							1
							);
							ExecPicCMD(OBJ,0x1033F8DC);
							V32(OBJ + 124) = 0;
							V16(OBJ + 112) = 1;
							FlyBoxOBJ = OBJ;
						}
					}
					sub_100918EE();
					MotionState = 3;
				}
				return 0;
			case 3:
				MotionState = 4;
				return 0;
			case 4:
				if (ExecRoroCMD())
				{
					GoMessage(0,384,150,6,1);
					V32(0x2002062C) = 0;
					MotionState = 5;
				}
				return 0;
			case 5:
				sub_100917CC();
				GetRoleInBox(576,1024,248,0);
				if (V32(0x2002062C)++>20 && sub_100BEF44(750,0,1536,256,0))
				{
					sub_100918EE();
					MotionState = 6;
				}
				return 0;
			case 6:
				Play_Music_Repeat(WAVE_S1_BOSS1,104,0);
				sub_10098146();
				sub_1007722E(0);
				sub_1002D8F0();
				sub_1002BF0E();
				sub_10007F22(0);
				sub_10022584(1);
				sub_10022984();
				sub_100207FA();
				sub_1001BDDE();
				sub_1002B7F6();
				sub_1004D14A();
				StopPlayerCtrl(0);
				if (SecretFlag1)
					V16(0x2002061C) = 1;
				pgm2log("0");
				for(i=0;i<20;i++)
					ScreenUpdate();
				//sub_1002F7FC(20, ScreenUpdate());
				sub_10059198(GetRoroInfoRAM(SetRoro(UseRoro(),0x102F426C,1400,216,0,1,0)));
				sub_10059198(GetRoroInfoRAM(SetRoro(UseRoro(),0x102F426C,1430,173,0,1,0)));
				sub_10091A32(1072,16,0);
				sub_1004F566(1024,8,1536,248);
				v9 = 0;
				for ( i = 0; i < 4; ++i )
					MoveFlag[i] = 0;
				while ( !v9 )
				{
					v9 = 1;
					i = 0;
					for ( Player = (ROLE_CMD *)GetPlayerInfo(); Player; Player = (ROLE_CMD *)sub_1002367A(Player) )
					{
						if ( !MoveFlag[i] )
						{
							if ( MovePlayer(
								Player,
								P16(0x1033FC14)[(int)(Player->pRoleInfoRAM->PlayerNo)],
								P16(0x1033FC1C)[(int)(Player->pRoleInfoRAM->PlayerNo)]))
							{
								MoveFlag[i] = 1;
							}
							else
							{
								v9 = 0;
							}
						}
						++i;
					}
					ScreenUpdate();
				}
				for ( RoroCMD = sub_1001B72E(); RoroCMD; RoroCMD = sub_1001B748(RoroCMD) )
				{
					RoroACT = sub_1002DAA8(RoroCMD, 1, 15);
					sub_1002DB90(RoroCMD, RoroACT);
				}
				for ( i = 0; i < 10; ++i )
					ScreenUpdate();
				v9 = 0;
				while ( !v9 )
				{
					v9 = 1;
					for ( Player = (ROLE_CMD *)GetPlayerInfo(); Player; Player = (ROLE_CMD *)sub_1002367A(Player) )
					{
						if ( !MovePlayer(
							Player,
							P16(0x1033FC14)[(int)Player->pRoleInfoRAM->PlayerNo] + 150,
							P16(0x1033FC1C)[(int)Player->pRoleInfoRAM->PlayerNo]) )
							v9 = 0;
					}
					ScreenUpdate();
				}				
				sub_100BF44C();
				for ( i = 0; i < 5; ++i )
					ScreenUpdate();
				for ( Player = (ROLE_CMD *)GetPlayerInfo(); Player; Player = (ROLE_CMD *)sub_1002367A(Player) )
				{
					v9 = sub_10020FF8(Player, 2, 22);
					sub_100210EC(Player, v9);
				}
				for ( i = 0; i < 100; ++i )
					ScreenUpdate();
				sub_10043D3C();
				Player = (ROLE_CMD *)sub_100BF8AC(8);
				if ( !Player )
					Player = (ROLE_CMD *)sub_100BF8AC(3);
				if ( !Player )
					Player = (ROLE_CMD *)GetPlayerInfo();
				switch ( Player->RoleId_1 )
				{
					case 8u:
						ExecDialogRight(V16(BossCMD + 256), 0, 0, 0, 0);
						ExecDialogLeft(Player->RoleId_1, 0, 1, 0, Player->pRoleInfoRAM);
						break;
					case 0u:
					case 1u:
					case 2u:
						ExecDialogRight(V16(BossCMD + 256), 0, 17, 0, 0);
						break;
					case 3u:
						ExecDialogRight(V16(BossCMD + 256), 0, 11, 0, 0);
						ExecDialogLeft(Player->RoleId_1, 0, 12, 0, Player->pRoleInfoRAM);
						ExecDialogRight(V16(BossCMD + 256), 0, 13, 0, 0);
						break;
					case 4u:
					case 5u:
					case 6u:
					case 7u:
					case 9u:
						ExecDialogRight(V16(BossCMD + 256), 0, 21, 0, 0);
						break;
					default:
						ExecDialogRight(V16(BossCMD + 256), 0, 17, 0, 0);
						break;
				}
				sub_1004C54E();
				sub_10049BB4(46, 0, 0);
				sub_1004C54E();
				sub_10043E24();
				SetMotionTimer(99);
				if ( BossCMD)
					sub_100786F4(BossCMD);
				V16(BossCMD + 522) = 30;
				sub_10022584(0);
				sub_1002297C();
				sub_100207F0();
				sub_1001BDCC();
				StopPlayerCtrl(1);
				sub_10007F22(1);
				sub_1007722E(1);
				sub_1009152C(1);
				if ( FlyBoxOBJ && !V16(0x2002061E) )
				{
					V16(0x20020624 + 28) = gDstX;
					V16(0x20020624 + 92) = 1;
					ExecPicCMD(FlyBoxOBJ, 0x1033F79C);
				}
				if ( SecretFlag1 )
					V16(0x2002061C) = 0;
				MotionState = 7;
				return 0;
			case 7:
				LoadRoroCMD(0x1033F444,2);
				MotionState = 8;
				return 0;
			case 8:
				if ((BossCMD && !V16(BossCMD + 108)) || sub_100914E8(V16(BossCMD + 256)) )
				{
					sub_100208A2(1);
					if ( SecretFlag1 )
						V16(0x2002061C) = 1;
					sub_10098146();
					sub_10096AFC();
					sub_100207FA();
					sub_1001BDDE();
					sub_10007F22(0);
					sub_10078C90(V16(BossCMD + 282));
					V16(BossCMD + 108) = 1;
					V16(BossCMD + 184) = 0;
					sub_100BF090(BossCMD);
					sub_1007722E(0);
					sub_1002BF0E();
					sub_10007F32(0);
					sub_10007F38(0);
					sub_10022584(1);
					sub_10022984();
					sub_1002B7F6();
					sub_1004D14A();
					StopPlayerCtrl(0);
					MotionState = 15;
				}
				else
				{
				ExecRoroCMD();
				}
				return 0;
			case 15:
				result = sub_1002BF40();
				if ( result )
				{
					sub_10043D3C();
					Player = (ROLE_CMD *)sub_100BF8AC(8);
					if ( !Player )
						Player = (ROLE_CMD *)sub_100BF8AC(3);
					if ( !Player )
						Player = (ROLE_CMD *)GetPlayerInfo();
					switch ( Player->RoleId_1 )
					{
						case 8u:
							ExecDialogRight(V16(BossCMD + 256), 0, 8, 0, 0);
							ExecDialogLeft(Player->RoleId_1, 0, 9, 0, Player->pRoleInfoRAM);
							ExecDialogRight(V16(BossCMD + 256), 0, 10, 0, 0);
							break;
						case 3u:
							ExecDialogLeft(Player->RoleId_1, 0, 14, 0, Player->pRoleInfoRAM);
							ExecDialogRight(V16(BossCMD + 256), 0, 15, 0, 0);
							ExecDialogLeft(Player->RoleId_1, 0, 16, 0, Player->pRoleInfoRAM);
							break;
						case 0u:
						case 1u:
						case 2u:
							ExecDialogRight(V16(BossCMD + 256), 0, 18, 0, 0);
							ExecSystemOBJ(5, Player->Off_28, Player->Off_30 + 1, -100, 2, Player->Off_200);
							for ( i = 0; i < 20; ++i )
								ScreenUpdate();
							ExecDialogLeft(Player->RoleId_1, 0, 19, 0, Player->pRoleInfoRAM);
							ExecDialogRight(V16(BossCMD + 256), 0, 20, 0, 0);
							break;
						default:
							ExecDialogRight(V16(BossCMD + 256), 0, 18, 0, 0);
							ExecSystemOBJ(5, Player->Off_28, Player->Off_30 + 1, -100, 2, Player->Off_200);
							for ( i = 0; i < 20; ++i )
								ScreenUpdate();
							ExecDialogLeft(Player->RoleId_1, 0, 19, 0, Player->pRoleInfoRAM);
							ExecDialogRight(V16(BossCMD + 256), 0, 20, 0, 0);
							break;
					}
					sub_1004C54E();
					sub_10043E24();
					if ( SecretFlag1 )
					{
						V16(0x2002061C) = 0;
						V16(0x20020620) = 1;
					}
					V16(BossCMD + 396) = 1;
					V16(BossCMD + 166) = 1;
					V16(BossCMD + 196) = 0;
					sub_10098BBE(gDstX + 224, gDstY + 195, 0, 164, 0, 0, 0, 0);
					sub_10098BBE(gDstX + 174, gDstY + 195, 0, 113, 0, 0, 0, 0);
					sub_1004E85A(gDstX + 194, gDstY + 180, 0, 0x801D, 0, 0);
					if ( g_GAME_MODE == 1
						&& V8(V32(V32(BossCMD + 484) + 260) + 210) >= 50
						&& GetJingShuCnt(V32(BossCMD + 484)) > 0 )
					{
						sub_10098BBE(gDstX + 254, gDstY + 180, 0, 125, 0, 0, 0, 0);
					}
					switch ( GetPlayerCnt())
					{
						case 1:
							sub_1004E85A(gDstX + 274, gDstY + 195, 0, 32769, 0, 0);
							sub_1004E85A(gDstX + 254, gDstY + 210, 0, 32769, 0, 0);
							break;
						case 2:
							sub_1004E85A(gDstX + 274, gDstY + 195, 0, 32769, 0, 0);
							sub_1004E85A(gDstX + 254, gDstY + 210, 0, 32770, 0, 0);
							break;
						case 3:
							sub_1004E85A(gDstX + 274, gDstY + 195, 0, 32792, 0, 0);
							sub_1004E85A(gDstX + 254, gDstY + 210, 0, 32769, 0, 0);
							sub_1004E85A(gDstX + 194, gDstY + 210, 0, 32769, 0, 0);
							sub_1004E85A(gDstX + 154, gDstY + 180, 0, 32771, 0, 0);
							break;
						case 4:
							sub_1004E85A(gDstX + 274, gDstY + 195, 0, 32769, 0, 0);
							sub_1004E85A(gDstX + 254, gDstY + 210, 0, 32769, 0, 0);
							sub_1004E85A(gDstX + 194, gDstY + 210, 0, 32770, 0, 0);
							sub_1004E85A(gDstX + 154, gDstY + 180, 0, 32770, 0, 0);
							break;
					}
					sub_10022584(0);
					sub_1009813C();
					sub_1002297C();
					sub_100207F0();
					sub_100207D8(BossCMD);
					StopPlayerCtrl(1);
					sub_1007722E(1);
					sub_1009152C(0);
					sub_10007F22(1);
					sub_1004EA42();
					result = sub_1002BF40();
					if ( result )
					{
						sub_1004D14A();
						sub_100915C6();
						sub_1005850A();
						SetNextStage(2);
						sub_1004D8F4(0);
						V32(0x20020280) = 1;
						V32(0x20020284) = 548;
						V8(0x20020288) = 1;
						result = 4;
					}
				}
				return result;
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 9:
				return 0;
		}
	}
	return 0;
}




//0x1033EC18 原版的STAGE1的MOTION指针表
const int Stage1MotionTable[]={
//0x100BF4FB, 0x100BF8D7, 0x100C0609, 0x100C0613, 0x100C061F, 0x100BF7FD, 0x63,//花果山
(int)(&s1m1f1+1), (int)(&s1m1f2+1), 0x100C0609, 0x100C0613, 0x100C061F, 0x100BF7FD, 0x63,//花果山
0x100C0F0B, 0x100C130F, 0x100C225F, 0x100C2269, 0x100C2275, 0x100C1285, 0x63,//高老庄
0x100C24B7, 0x100C2815, 0x100C3689, 0x100C36AB, 0x100C36B7, 0x100C278B, 0x63,//流沙河
0x100C3D4B, 0x100C45BD, 0x100C58F1, 0x100C58FB, 0x100C59E7, 0x100C452B, 0x63,//南天门
};


signed int st1_init()
{
	SetMotion(0);
	return 1;
	ROLE_RAM *RoleInfo;
	int Flag[4]={0,0,0,0};
	int i;
	int r;
	int PlayerNo;
	
	for(PlayerNo=0;PlayerNo<4;PlayerNo++)
	{
		RoleInfo = (ROLE_RAM *)(GetRoleInfoRAM(PlayerNo));
		if (RoleInfo->Status)//角色状态不为0
			Flag[get_role_id(RoleInfo->RoleId)] = 1;
	}
	
	for (i=0;i<150;i++)
	{
		r = rand(4);//取随机数0-3
		//pgm2log("%d",Flag[r]);
		if(!Flag[r])//如果特殊角色未被选中
		{
			//pgm2log("随机关卡");
			SetMotion(r);
			return 1;
		}	
	}
	//pgm2log("固定关卡");
	if(Flag[0])
	{
		if(Flag[1])
		{
			if(Flag[2])
				SetMotion(3);
			else
				SetMotion(2);
		}
		else
		{
			SetMotion(1);
		}
		
	}
	else
	{
		SetMotion(0);
	}
	return 1;

}

int s1f1(int Motion)
{
  return FUNC32(Stage1MotionTable[7 * Motion + 0])();
}

int s1f2(int Motion)
{
  return FUNC32(Stage1MotionTable[7 * Motion + 1])();
}

int st1_getmotionend(int Motion)
{
  return FUNC32(Stage1MotionTable[7 * Motion + 2])();
}

int st1_getmotiondrop(int Motion,int ItemId)
{
  return FUNC32(Stage1MotionTable[7 * Motion + 3])(ItemId);
}

int st1_getmotionother(int Motion,int ItemId)
{
  return FUNC32(Stage1MotionTable[7 * Motion + 4])(ItemId);
}

int st1_getmotionbeforeend(int Motion,int ItemId)
{
  return FUNC32(Stage1MotionTable[7 * Motion + 5])(ItemId);
}

int st1_getmotiontime(int Motion)
{
  return Stage1MotionTable[7 * Motion + 6];
}

int st1_getmotionnull(int Motion)
{
  return 0;
}


