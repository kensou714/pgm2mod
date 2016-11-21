#include <stdlib.h>
#include <stdio.h>

#include "game_type.h"
#include "xyj2_func.h"
#include "game_wave.h"

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




/*
*=================================================================
*				增加经验值函数			By Kensou
*	1.整体函数摘自sub_10064C98().
*	2.在原有函数基础上增加一个调用参数isAdd,用来识别调用来自哪里.
*	3.添加升级时赠送一个Power数.
*	4.修改分数等于经验.
*=================================================================
*/
int AddLifes;
void AddExp(ROLE_RAM *Role, int AddValue,int isAdd)
{
	int Area; // r7@5
	IC_CARD *ICCard; // r5@6
	signed int isLevelUp; // r6@8

	if ( isAdd == 99 )//来自AddScore的调用
	{
		if ( AddValue )//增加值
		{
			//pgm2log("AddExp -> %d\n",AddValue);
			if ( Role->NowEXP + AddValue < 0xFFFFFFFF )
			{
				Role->NowEXP += AddValue;
				Area = ubArea_Get();
				if ( get_iccard_flag() )
				{
					ICCard = (IC_CARD *)(ReadICCardData(Role->PlayerNo));
					if ( ICCard )
						ICCard->NowEXP = Role->NowEXP;
				}
				isLevelUp = 0;
				while ( Role->Level < 99 && Role->NowEXP >= Role->NextEXP )
				{
					isLevelUp = 1;
					if ( ++Role->Level < 99 )
					{
						if ( Area != 2 && Area != 4 )
							Role->NextEXP = ExpTableMod[Role->Level + 1];
						else
							Role->NextEXP = ExpTableMod[Role->Level + 1];
					}
					else
					{
						Role->Level = 99;
						Role->NextEXP = -1;
					}
				}
				if ( isLevelUp )
				{
					Role->BYTE_209 = 1;
					Role->BYTE_212 = 1;
					//       sub_1002BA4A(Role, 25);//+25HP
					//		sub_1005D370(Role);//刷新生命显示
					sub_10064AD0(Role, 1);//加一个气
					sub_10064C46(Role);
					//sub_1005B144(Role);//刷新能量和分数显示
					sub_1005C3F4();
					sub_1002F288(WAVE_SYS_02,64);//播放音效
				}
			}
			else
			{
				Role->NowEXP = -1;
			}
		}
	}
	Role->Score = Role->NowEXP/100;//让分数等于经验/100
	if (Role->NowEXP >= 50000000 && !AddLifes){//奖第一次命
		pgm2log("奖命");
		Role->Lifes =  Role->Lifes + 1;
		AddLifes = 1;
		sub_1005D9B4(Role);//刷新生命数显示
		sub_1002F288(1,64);//播放音效
	}
	if (Role->NowEXP >= 100000000 && AddLifes == 1){//奖第二次命
		Role->Lifes =  Role->Lifes + 1;
		AddLifes = 2;
		sub_1005D9B4(Role);//刷新生命数显示
		sub_1002F288(1,64);//播放音效
	}
}


void __fastcall AddScore(ROLE_RAM *Role, signed int AddValue)
{
	IC_CARD *ICCard; // r6@9

	if ( AddValue )
	{
		if ( Role->pCmdPtr->UltraStateFlag )//暴气状态
			AddValue = 4;//暴气固定加2W分
		if ( Role->Score < (-1 - AddValue) )
			Role->Score += AddValue;
		else
			Role->Score = -1;
		if ( AddValue <= 50)//非hit的分数就*50倍
			AddValue *= 50;


		AddExp(Role,AddValue*100,99);//这里把分数当经验传过去
		if ( get_iccard_flag() ){
			ICCard = (IC_CARD *)(ReadICCardData(Role->PlayerNo));
			if ( ICCard ){
				if ( g_GAME_MODE ){
					if ( g_GAME_MODE == MODE_BOSS ){
						if ( ICCard->ChallengeScore < Role->Score )
							ICCard->ChallengeScore = Role->Score;
					}
					else if ( g_GAME_MODE==MODE_STORY && ICCard->IRScore < Role->Score ){
						ICCard->IRScore = Role->Score;
					}
				}
				else if ( ICCard->StoryScore < Role->Score ){
					ICCard->StoryScore = Role->Score;
				}
			}
		}
		Role->BYTE_230 = 1;
	}
}