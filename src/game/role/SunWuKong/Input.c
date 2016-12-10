//INPUT结构体定义，必须包含，固定。
#include "../../Include/Input.h"
//输入方式的extern声明，通用，必须包含，内容如下方注释。如需增加类型，请在../../System/SkillInput.c中定义
#include "../../Include/SkillInput.h"
/* 以下定义包含在SkillInput.h
extern int Input_Ins_6A[];
extern int Input_Ins_2A[];
extern int Input_Ins_28A[];
extern int Input_Ins_82A[];
extern int Input_Ins_46A[];
extern int Input_Ins_236A[];
extern int Input_Ins_88A[];
extern int Input_Ins_22A[];
extern int Input_Ins_6B[];
extern int Input_Ins_2B[];
extern int Input_Ins_28B[];
extern int Input_Ins_82B[];
extern int Input_Ins_46B[];
extern int Input_Ins_236B[];
extern int Input_Ins_88B[];
extern int Input_Ins_22B[];
*/


const InputElem InputTbl_SunWuKong_0[]={
	//	输入指令		固定	  ActionId	参数		//参数部分详细分析后应在input.h中进行define
	{Input_Ins_6A,			0x14,	10,	0x4890},		//黑色波动
	{Input_Ins_236A,		0x14,	12,	0x4890},		//
	{Input_Ins_236A,		0x14,	13,	0x18A0},		//空中
	{Input_Ins_28A,			0x14,	11,	0x4890},		//
	{Input_Ins_82A,			0x14,	14,	0x4891},		//
	{Input_Ins_2A,			0x14,	15,	0x18A3},		//空中
	//以下曝气后输入
	{Input_Ins_6A,			0x14,	0,	0x4910},		//黑色波动
	{Input_Ins_236A,		0x14,	2,	0x4910},		//
	{Input_Ins_236A,		0x14,	3,	0x1920},		//空中
	{Input_Ins_28A,			0x14,	1,	0x4910},		//
	{Input_Ins_82A,			0x14,	4,	0x4911},		//
	{Input_Ins_2A,			0x14,	5,	0x1923},		//空中

//	{Input_Ins_2B,			0x14,	28,	0x1810},		//新增加2B突进技测试
	{Input_Ins_6B,			0x14,	28,	0x1810},		//
	{Input_Ins_6B,			0x14,	29,	0x1820},		//空中
	{Input_Ins_236B,		0x14,	21,	0x4890},		//
	{Input_Ins_46B,		0x14,	20,	0x4850},	//
	{Input_Ins_28B,		0x14,	22,	0x4852},	//
	{Input_Ins_82B,		0x14,	23,	0x4854},	//
	{Input_Ins_88B,		0x14,	24,	0x4855},	//
	{Input_Ins_22B,		0x14,	25,	0x4856},	//
	{0,					0,		0,		 0}		//结束，必须有
};