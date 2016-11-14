#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../game_type.h"
#include "../xyj2_func.h"


/*
*==========================================
*			STAGE 0 - 测试关卡
*==========================================
*/


void CreatMapObj(int a1,int a2,int a3,int a4,int a5,short MapPal,short a7,short a8,short a9,short a10,short a11){
	int MapOBJ;
  MapOBJ = sub_10015D4A(a1, a2, a3, a4, a5);//创建OBJ
  V16(MapOBJ + 80) = MapPal;
  V16(MapOBJ + 142) = MapPal;
  V16(MapOBJ + 212) = a7;
  sub_10126378(V16(MapOBJ + 76), (V16(MapOBJ + 30) - 2));
  V16(MapOBJ + 118) = a8;
  V16(MapOBJ + 266) = a9;
  V16(MapOBJ + 268) = a10;
  V16(MapOBJ + 270) = a11;
}

signed int Stage0Motion0Begin()
{
//  short MapPal; // r5@1

  Music_Stop();//停止音乐
  sub_10022984();//V8(0x200200C7)=0;
  sub_1001BDDE();//V8(0x200200A2)=0;
  StopPlayerCtrl(0);//禁止控制角色
  sub_1005C9E2(0);//V8(0x2002029F)=0;
  LoadMapBit(0x10187048, 0);//载入地图 0层
  LoadMapBit(0x10183C10, 1);//载入地图 1层
  LoadMapMask(0x1019A544, 0, 160);//载入地图的Mask
  SetMapBitPal(0x104F2EAC, 0, 0, 0);
 // MapPal = SetMapBitPal(0x104F2EAC, 0, 0, 0);//载入地图的色盘
//  CreatMapObj(0x1033EB70,117,0,167,1,MapPal,-2,0,1,7,6);//创建地图用的背景OBJ喷泉那些
//  CreatMapObj(0x1033EB70,553,0,187,0,MapPal,-2,0,1,7,6);
//  CreatMapObj(0x1033EBC4,820,0,187,0,MapPal,-2,0,1,7,6);
//  CreatMapObj(0x1033EB70,956,0,167,0,MapPal,-2,0,1,7,6);
//  CreatMapObj(0x1033EBC4,1223,0,167,0,MapPal,-2,0,1,7,6);
//  CreatMapObj(0x1033EB70,1397,0,167,0,MapPal,-2,0,1,7,6);

  sub_1004FBE2(270, 6, 0, 0);//这里也是色盘有关
  sub_1004FF3C();//这里也是色盘有关
  sub_100337E0(0, 16);//V16(0x20020160)=a1,V16(0x20020162)=a2;
  sub_1004F566(0, 0, 1024, 256);//V16(0x20020202)=a1,V16(0x20020204)=a2,V16(0x20020206)=a3,V16(0x20020208)=a4;应该是地图卷轴大小设置
  sub_100915BE();//V8(20061EA8)[5*PlayerNo]=0;V16(0x20020466)=0;
  sub_100584B2();//设置一些变量
  vPalette_FadeManageRealTimeFunction(1, 0, 8, 0);//淡入
  sub_1002B94E(60);
  StopPlayerCtrl(1);
  sub_1002297C();
  sub_1001BDCC();//V8(0x200200A2)=1;这里好像跟怪物的攻击有关，屏蔽后怪物就不攻击人了
  V16(0x200205FA) = 0;
  V16(0x200205F8) = 0;
  sub_10091516();//这里好像跟遁入环境什么的有关
  return 1;
}

int Stage0Motion0Turn()
{
  signed int i; // r4@4

  sub_100BE856();//测试武器和装备的函数
  if ( V16(0x200205F8) )
  {
    if ( V16(0x200205F8) == 1 )
    {
      if ( V32(0x200205E8) )
      {
        if ( !V32(0x200205F0) )
        {
          print_(0,7,"X = %3d,    Y = %3d,    Z = %3d",VS16(V32(0x200205E8) + 28),VS16(V32(0x200205E8) + 30),VS16(V32(0x200205E8) + 32));
          print_(0,8,"ACTTYPE = %3d,  ACTID = %3d", V16(V32(0x200205E8) + 76),V16(V32(0x200205E8) + 78));
          if ( V8(V32(0x200205E8) + 396) )
            print_(30, 8, "CHIEF SUPER");
          else
            print_(30, 8, "           ");
        }
      }
      if ( !sub_100206AA() )
        V16(0x200205F8) = 15;
    }
    else if ( V16(0x200205F8) == 15 )
    {
      for ( i = 0; i < 150; ++i )
        ScreenUpdate();
      sub_100915C6();
      sub_1005850A();
      V16(0x200205F8) = 0;
    }
  }
  else
  {
    print_(0, 7, "                                         ");
    print_(0, 8, "                                         ");
    print_(30, 8, "           ");
    SetMotionTimer(99);
    sub_100BE008();
    sub_100207FA();
    sub_10022984();
    sub_100BE02E();//这个是关卡设定的函数
    sub_100BE4E8();
    sub_100207F0();
    sub_1002297C();
    V16(0x200205F8) = 1;
  }
  return 0;
}

signed int Stage0Motion0End(){
  return 1;
}

void Stage0Motion0Drop(){
  if ( V32(0x20020600) > 0 )
    --V32(0x20020600);
}

int Stage0Motion0Other(int a1)
{
	int result;
  result = sub_1002066C(a1);

  if ( result == V32(0x200205E8) )
  {
    result = 0;
    V32(0x200205E8) = 0;
  }
  return result;
}

int Stage0Motion0BeforeEnd(int pPlayerCmdObj)
{
  short PlayerNo; // r5@1
  //pgm2log("%08X\n",a1);
  PlayerNo = V8(V32(pPlayerCmdObj + 260) + 1);
  return sub_1002A7CA(pPlayerCmdObj, 5 * PlayerNo + 50, 5 * PlayerNo + 180, 0, 0, 2, 0);
}






//0x1033E964 原版的测试关卡的MOTION指针表
const int Stage0MotionTable[]={
//0x100BE5DD, 0x100BEBE3, 0x100BED79, 0x100BED7D, 0x100BED97, 0x100BE827, 0x63
(int)(&Stage0Motion0Begin+1), (int)(&Stage0Motion0Turn+1), (int)(&Stage0Motion0End+1), (int)(&Stage0Motion0Drop+1), (int)(&Stage0Motion0Other+1), (int)(&Stage0Motion0BeforeEnd+1), 0x63
};



signed int st0_init(){//初始化函数
  return 1;
}

int st0_getmotionbegin(int Motion)
{
  return FUNC32(Stage0MotionTable[7 * Motion + 0])();
}

int st0_getmotionturn(int Motion)
{
  return FUNC32(Stage0MotionTable[7 * Motion + 1])();
}

int st0_getmotionend(int Motion)
{
  return FUNC32(Stage0MotionTable[7 * Motion + 2])();
}

int st0_getmotiondrop(int Motion,int ItemId)
{
  return FUNC32(Stage0MotionTable[7 * Motion + 3])(ItemId);
}

int st0_getmotionother(int Motion,int ItemId)
{
  return FUNC32(Stage0MotionTable[7 * Motion + 4])(ItemId);
}

int st0_getmotionbeforeend(int Motion,int ItemId)
{
  return FUNC32(Stage0MotionTable[7 * Motion + 5])(ItemId);
}

int st0_getmotiontime(int Motion)
{
  return Stage0MotionTable[7 * Motion + 6];
}

int st0_getmotionnull(int Motion)
{
  return 0;
}


