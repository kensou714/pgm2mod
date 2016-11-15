#include <stdlib.h>
#include <stdio.h>

#include "game_type.h"
#include "xyj2_func.h"

//这个是自定义的升级经验表
const int ExpTableMod[]={					//0x10161890升级经验表 这个是飞雪自己用的经验表
0, 102400, 204800, 409600, 819200, 1280000, 2560000, 5120000, 7680000, 10240000,// 0
	12800000, 15360000, 17920000, 20480000, 23040000, 25600000,28160000,30720000,33280000,35840000,// 10
	38400000,40960000,43520000,46080000,48640000,51200000,53760000,56320000,58880000,61440000,// 20
	64000000,66560000,69120000,71680000,74240000,76800000,79360000,81920000,84480000,87040000,// 30
	89600000,92160000,94720000,97280000,99840000,102400000,104960000,107520000,110080000,112640000,// 40
	115200000,117760000,120320000,122880000,125440000,128000000,130560000,133120000,135680000,138240000,// 50
	140800000,143360000,145920000,148480000,151040000,153600000,156160000,158720000,161280000,163840000,// 60
166400000,168960000,171520000,174080000,176640000,179200000,181760000,184320000,186880000,189440000,// 70
192000000,194560000,197120000,199680000,202240000,204800000,207360000,209920000,212480000,215040000,// 80
217600000,220160000,222720000,225280000,227840000,230400000,232960000,235520000,238080000,240640000,// 90
};

//自定义的连段分数表
const short HitScoreTableMod[]={
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,	
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,
	0,0,0,0,0,0,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640,672,704,736,768,8,832,864,896,928,960,992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,16,1632,1664,1696,1728,1760,1792,1824,		
	};


























void AddExp(int RoleInfo, int AddValue,int isAdd)
{
  int Area; // r7@5
  int ICCard; // r5@6
  signed int isLevelUp; // r6@8

if ( isAdd == 99 )
{
  if ( AddValue )//增加值
  {
	  pgm2log("AddExp -> %d\n",AddValue);
    if ( V32(RoleInfo + 204) < (-1 - AddValue) )
    {
      V32(RoleInfo + 204) += AddValue;
      Area = ubArea_Get();
      if ( get_iccard_flag() )
      {
        ICCard = sub_1000F328(V8(RoleInfo + 1));
        if ( ICCard )
          V32(ICCard + 16) = V32(RoleInfo + 204);
      }
      isLevelUp = 0;
      while ( V8(RoleInfo + 210) < 99 && V32(RoleInfo + 204) >= V32(RoleInfo + 216) )
      {
        isLevelUp = 1;
        if ( ++V8(RoleInfo + 210) < 99 )
        {
          if ( Area != 2 && Area != 4 )
            V32(RoleInfo + 216) = ExpTableMod[V8(RoleInfo + 210) + 1];
          else
            V32(RoleInfo + 216) = P32(0x10161700)[V8(RoleInfo + 210) + 1];
        }
        else
        {
          V8(RoleInfo + 210) = 99;
          V32(RoleInfo + 216) = -1;
        }
      }
      if ( isLevelUp )
      {
		  pgm2log("levelup - > %d\n",V8(RoleInfo+210));
        V8(RoleInfo + 209) = 1;
        V8(RoleInfo + 212) = 1;
		if (V8(RoleInfo + 244) != V8(RoleInfo + 248) )
			V8(RoleInfo + 244) = V8(RoleInfo + 244) +1;//+1气
        sub_10064C46(RoleInfo);

        sub_1005C3F4();
      }
    }
    else
    {
      V32(RoleInfo + 204) = -1;
    }
  }
}
V32(RoleInfo + 232) = V32(RoleInfo + 204)/100;//让分数等于经验/100
}

int AddLifes;
void __fastcall AddScore(int RoleInfo, signed int AddValue)
{
  int ICCard; // r6@9

  if ( AddValue )
  {
    if ( V8(V32(RoleInfo + 4) + 390) )//暴气状态
      AddValue = 4;//暴气固定加2W分
    if ( V32(RoleInfo + 232) < (-1 - AddValue) )
      V32(RoleInfo + 232) += AddValue;
	else
      V32(RoleInfo + 232) = -1;
	if ( AddValue <= 50)//非hit的分数就*50倍
		AddValue *= 50;
	if (V32(RoleInfo + 232) >= 300000 && !AddLifes){//奖第一次命
				V8(RoleInfo + 3) =  V8(RoleInfo + 3) + 1;
				AddLifes = 1;
				sub_1005D9B4(RoleInfo);//刷新生命数显示
	}
	if (V32(RoleInfo + 232) >= 1000000 && AddLifes == 1){//奖第二次命
				V8(RoleInfo + 3) =  V8(RoleInfo + 3) + 1;
				AddLifes = 2;
				sub_1005D9B4(RoleInfo);//刷新生命数显示
	}

	AddExp(RoleInfo,AddValue*100,99);//这里把分数当经验传过去
    if ( get_iccard_flag() )
    {
      ICCard = sub_1000F328(V8(RoleInfo + 1));
      if ( ICCard )
      {
        if ( V8(0x20020105) )
        {
          if ( V8(0x20020105) == 2 )
          {
            if ( V32(ICCard + 24) < V32(RoleInfo + 232) )
              V32(ICCard + 24) = V32(RoleInfo + 232);
          }
          else if ( !V8(0x20020105) && V32(ICCard + 28) < V32(RoleInfo + 232) )
          {
            V32(ICCard + 28) = V32(RoleInfo + 232);
          }
        }
        else if ( V32(ICCard + 20) < V32(RoleInfo + 232) )
        {
          V32(ICCard + 20) = V32(RoleInfo + 232);
        }
      }
    }
    V8(RoleInfo + 230) = 1;


	
  }
}