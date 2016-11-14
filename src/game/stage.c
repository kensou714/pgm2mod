//0x1015108C 原版的关卡总指针表，每个关卡10个int
//待补充每个指针指向说明
//{场景数,初始化函数,场景函数1-场景开始,场景函数2-场景流程,场景函数3-场景结束,场景函数4-掉物函数,场景函数5-空函数,场景函数6-场景结束前?,场景参数7-场景时间,场景参数8-0}


struct MotionInfo{
	int MotionBegin;//场景函数1-场景开始
	int MotionTurn;//场景函数2-场景流程
	int MotionEnd;//场景函数3-场景结束
	int MotionDrop;//场景函数4-掉物函数
	int MotionOther;//场景函数5-空函数
	int MotionBeforeEnd;//场景函数6-场景结束前?
	short MotionTime;//场景时间
	short MotionNull;
};

struct StageInfo{
	int	MotionCnt;//场景数
	int pStageInit;//初始化函数
	int pGetMotionBegin;//场景函数1-场景开始
	int pGetMotionTurn;//场景函数2-场景流程
	int pGetMotionEnd;//场景函数3-场景结束
	int pGetMotionDrop;//场景函数4-掉物函数
	int pGetMotionOther;//场景函数5-空函数
	int pGetMotionBeforeEnd;//场景函数6-场景结束前?
	int pGetMotionTime;//场景时间
	int pGetMotionNull;//0
};








const int StageTbl[]={
1, 0x100BDF6D, 0x100BDF71, 0x100BDF81, 0x100BDF93, 0x100BDFA5, 0x100BDFBB, 0x100BDFD1, 0x100BDFE7, 0x100BDFF5, //test stage
4, 0x100BEDB9, 0x100BEEB3, 0x100BEEC3, 0x100BEED5, 0x100BEEE7, 0x100BEEFD, 0x100BEF13, 0x100BEF29, 0x100BEF37, //stage1 随机新手关
5, 0x100C5A11, 0x100C5A19, 0x100C5A29, 0x100C5A3B, 0x100C5A4D, 0x100C5A63, 0x100C5A79, 0x100C5A8F, 0x100C5A9D,//stage2	平顶山
6, 0x100CE095, 0x100CE0AD, 0x100CE0BD, 0x100CE0CF, 0x100CE0E1, 0x100CE0F7, 0x100CE10D, 0x100CE123, 0x100CE131, //stage3 车迟国
4, 0x100D87D1, 0x100D87D5, 0x100D87E5, 0x100D87F7, 0x100D8809, 0x100D881F, 0x100D8835, 0x100D884B, 0x100D8859, //stage4 碗子山
2, 0x100DF195, 0x100DF1A7, 0x100DF1B7, 0x100DF1C9, 0x100DF1DB, 0x100DF1F1, 0x100DF207, 0x100DF21D, 0x100DF22B, //stage5 枯松涧
10, 0x100E48E9, 0x100E48F9, 0x100E4909, 0x100E491B, 0x100E492D, 0x100E4943, 0x100E4959, 0x100E496F, 0x100E497D, //stage6 通天河
4, 0x100EBEFD, 0x100EBF07, 0x100EBF17, 0x100EBF29, 0x100EBF3B, 0x100EBF51, 0x100EBF67, 0x100EBF7D, 0x100EBF8B, //stage7 盘丝洞
6, 0x100F2325, 0x100F236F, 0x100F237F, 0x100F2391, 0x100F23A3, 0x100F23B9, 0x100F23CF, 0x100F23E5, 0x100F23F3, //stage8 狮驼岭
5, 0x100FCF49, 0x100FCF63, 0x100FCF73, 0x100FCF85, 0x100FCF97, 0x100FCFAD, 0x100FCFC3, 0x100FCFD9, 0x100FCFE7, //stage9 花果山
5, 0x10107DDD, 0x10107DED, 0x10107DFD, 0x10107E0F, 0x10107E21, 0x10107E37, 0x10107E4D, 0x10107E63, 0x10107E71, //stage10 火焰山
8, 0x1010F0B5, 0x1010F0BF, 0x1010F0CF, 0x1010F0E1, 0x1010F0F3, 0x1010F109, 0x1010F11F, 0x1010F135, 0x1010F143, //stage11 小雷音寺
3, 0x10117D65, 0x10117D6F, 0x10117D7F, 0x10117D91, 0x10117DB9, 0x10117DCF, 0x10117DE5, 0x10117DFB, 0x10117E09, //stage12 商店
1, 0x101243ED, 0x101243F7, 0x10124409, 0x1012441B, 0x1012442F, 0x10124445, 0x1012445B, 0x10124471, 0x1012447F, //stage13 挑战BOSS
1, 0x10124491, 0x10124495, 0x101244A5, 0x101244B7, 0x101244C9, 0x101244DF, 0x101244F5, 0x1012450B, 0x10124519, //stage14 好像是一些特殊剧情
};

//自定义的关卡总指针表
extern signed int st0_init();
extern int st0_getmotionbegin(int Motion);
extern int st0_getmotionturn(int Motion);
extern int st0_getmotionend(int Motion);
extern int st0_getmotiondrop(int Motion,int ItemId);
extern int st0_getmotionother(int Motion,int ItemId);
extern int st0_getmotionbeforeend(int Motion,int ItemId);
extern int st0_getmotiontime(int Motion);
extern int st0_getmotionnull(int Motion);

const int StageTblMod[]={
1, 0x100BDF6D, 0x100BDF71, 0x100BDF81, 0x100BDF93, 0x100BDFA5, 0x100BDFBB, 0x100BDFD1, 0x100BDFE7, 0x100BDFF5, //test stage
1, (int)(&st0_init+1), (int)(&st0_getmotionbegin+1), (int)(&st0_getmotionturn+1), (int)(&st0_getmotionend+1), (int)(&st0_getmotiondrop+1), (int)(&st0_getmotionother+1), (int)(&st0_getmotionbeforeend+1), (int)(&st0_getmotiontime+1), (int)(&st0_getmotionnull+1), //test stage
//4, 0x100BEDB9, 0x100BEEB3, 0x100BEEC3, 0x100BEED5, 0x100BEEE7, 0x100BEEFD, 0x100BEF13, 0x100BEF29, 0x100BEF37, //stage1 随机新手关
5, 0x100C5A11, 0x100C5A19, 0x100C5A29, 0x100C5A3B, 0x100C5A4D, 0x100C5A63, 0x100C5A79, 0x100C5A8F, 0x100C5A9D,//stage2	平顶山
6, 0x100CE095, 0x100CE0AD, 0x100CE0BD, 0x100CE0CF, 0x100CE0E1, 0x100CE0F7, 0x100CE10D, 0x100CE123, 0x100CE131, //stage3 车迟国
4, 0x100D87D1, 0x100D87D5, 0x100D87E5, 0x100D87F7, 0x100D8809, 0x100D881F, 0x100D8835, 0x100D884B, 0x100D8859, //stage4 碗子山
2, 0x100DF195, 0x100DF1A7, 0x100DF1B7, 0x100DF1C9, 0x100DF1DB, 0x100DF1F1, 0x100DF207, 0x100DF21D, 0x100DF22B, //stage5 枯松涧
10, 0x100E48E9, 0x100E48F9, 0x100E4909, 0x100E491B, 0x100E492D, 0x100E4943, 0x100E4959, 0x100E496F, 0x100E497D, //stage6 通天河
4, 0x100EBEFD, 0x100EBF07, 0x100EBF17, 0x100EBF29, 0x100EBF3B, 0x100EBF51, 0x100EBF67, 0x100EBF7D, 0x100EBF8B, //stage7 盘丝洞
6, 0x100F2325, 0x100F236F, 0x100F237F, 0x100F2391, 0x100F23A3, 0x100F23B9, 0x100F23CF, 0x100F23E5, 0x100F23F3, //stage8 狮驼岭
5, 0x100FCF49, 0x100FCF63, 0x100FCF73, 0x100FCF85, 0x100FCF97, 0x100FCFAD, 0x100FCFC3, 0x100FCFD9, 0x100FCFE7, //stage9 花果山
5, 0x10107DDD, 0x10107DED, 0x10107DFD, 0x10107E0F, 0x10107E21, 0x10107E37, 0x10107E4D, 0x10107E63, 0x10107E71, //stage10 火焰山
8, 0x1010F0B5, 0x1010F0BF, 0x1010F0CF, 0x1010F0E1, 0x1010F0F3, 0x1010F109, 0x1010F11F, 0x1010F135, 0x1010F143, //stage11 小雷音寺
3, 0x10117D65, 0x10117D6F, 0x10117D7F, 0x10117D91, 0x10117DB9, 0x10117DCF, 0x10117DE5, 0x10117DFB, 0x10117E09, //stage12 商店
1, 0x101243ED, 0x101243F7, 0x10124409, 0x1012441B, 0x1012442F, 0x10124445, 0x1012445B, 0x10124471, 0x1012447F, //stage13 挑战BOSS
1, 0x10124491, 0x10124495, 0x101244A5, 0x101244B7, 0x101244C9, 0x101244DF, 0x101244F5, 0x1012450B, 0x10124519, //stage14 挑战双BOSS？
};



//0x1033EC18 原版的STAGE1的MOTION指针表
const int Stage1MotionTable[]={
0x100BF4FB, 0x100BF8D7, 0x100C0609, 0x100C0613, 0x100C061F, 0x100BF7FD, 0x63,//花果山
0x100C0F0B, 0x100C130F, 0x100C225F, 0x100C2269, 0x100C2275, 0x100C1285, 0x63,//高老庄
0x100C24B7, 0x100C2815, 0x100C3689, 0x100C36AB, 0x100C36B7, 0x100C278B, 0x63,//流沙河
0x100C3D4B, 0x100C45BD, 0x100C58F1, 0x100C58FB, 0x100C59E7, 0x100C452B, 0x63,//南天门
};

//0x10343BFC 原版的STAGE2的MOTION指针表
const int Stage2MotionTable[]={
0x100C5FF9, 0x100C6655, 0x100C72D5, 0x100C7307, 0x100C7313, 0x100C647D, 0x63,//
0x100C87EF, 0x100C8981, 0x100C94DF, 0x100C9515, 0x100C9521, 0x100C88F9, 0x63,//
0x100CA037, 0x100CA4AD, 0x100CB047, 0x100CB051, 0x100CB05D, 0x100CA47D, 0x63,//
0x100CBD4D, 0x100CC1A7, 0x100CC8F9, 0x100CC903, 0x100CC90F, 0x100CC11D, 0x63,//
0x100CCF8F, 0x100CD2F1, 0x100CDF73, 0x100CDF7D, 0x100CDF89, 0x100CD263, 0x63,//
};

//0x103497B8 原版的STAGE3的MOTION指针表
const int Stage3MotionTable[]={
0x100CEF5D, 0x100CF377, 0x100D0A43, 0x100D0A4D, 0x100D0A59, 0x100CF2B9, 0x63,//
0x100D1C5D, 0x100D2559, 0x100D2BF9, 0x100D2C13, 0x100D2C41, 0x100D212B, 0x63,//
0x100D428D, 0x100D4E23, 0x100D5677, 0x100D5681, 0x100D568D, 0x100D4D49, 0x63,//
0x100D57C3, 0x100D5A61, 0x100D6003, 0x100D600D, 0x100D6019, 0x100D59D9, 0x63,//
0x100D6D95, 0x100D710D, 0x100D7B3F, 0x100D7B49, 0x100D7B55, 0x100D6FD7, 0x63,//
0x100D7F83, 0x100D8429, 0x100D879F, 0x100D87A9, 0x100D87B5, 0x100D8313, 0x63,//
};

//0x1034F898 原版的STAGE4的MOTION指针表
const int Stage4MotionTable[]={
0x100D8DC9, 0x100DAF67, 0x100DB643, 0x100DB64F, 0x100DB697, 0x100D8F37, 0x63,//
0x100DC229, 0x100DC85D, 0x100DCDA7, 0x100DCDAB, 0x100DCDB7, 0x100DC483, 0x63,//
0x100DCFED, 0x100DDD63, 0x100DE051, 0x100DE055, 0x100DE061, 0x100DD0B9, 0x63,//
0x100DE71D, 0x100DEC27, 0x100DEDAB, 0x100DEDAF, 0x100DEDFB, 0x100DE93D, 0x63,//
};

//0x10356B64 原版的STAGE5的MOTION指针表
const int Stage5MotionTable[]={
0x100E03DD, 0x100E1C57, 0x100E25ED, 0x100E25F1, 0x100E25FD, 0x100E054F, 0x63,//
0x100E3AB7, 0x100E3D7D, 0x100E4381, 0x100E4385, 0x100E4391, 0x100E2DFD, 0x63,//
};

//0x1035C5E8 原版的STAGE6的MOTION指针表
const int Stage6MotionTable[]={
0x100E4A5D, 0x100E4F5F, 0x100E50FD, 0x100E5101, 0x100E510D, 0x100E4A2D, 0x63,//
0x100E625D, 0x100E6CA3, 0x100E7051, 0x100E7055, 0x100E7061, 0x100E607F, 0x63,//
0x100E74C5, 0x100E7665, 0x100E76E1, 0x100E76E5, 0x100E76F1, 0x100E72F3, 0x63,//
0x100E7C83, 0x100E7EFD, 0x100E7FBF, 0x100E7FC3, 0x100E7FCF, 0x100E7C43, 0x63,//
0x100E8063, 0x100E824F, 0x100E8487, 0x100E848B, 0x100E8497, 0x100E7FEB, 0x63,//
0x100E89C1, 0x100E8B61, 0x100E8C15, 0x100E8C19, 0x100E8C25, 0x100E87A5, 0x63,//
0x100E8CBD, 0x100E8D7B, 0x100E8F07, 0x100E8F0B, 0x100E8F3B, 0x100E8C7F, 0x63,//
0x100E9035, 0x100E914D, 0x100E91CD, 0x100E91D1, 0x100E91DD, 0x100E8FF7, 0x63,//
0x100EA8A5, 0x100EABDD, 0x100EAE95, 0x100EAE99, 0x100EAEA5, 0x100EA865, 0x63,//
0x100EB545, 0x100EB7E5, 0x100EBA2F, 0x100EBA33, 0x100EBA3F, 0x100EB357, 0x63,//
};

//0x10367B94 原版的STAGE7的MOTION指针表
const int Stage7MotionTable[]={
0x100EC4C9, 0x100ED0AB, 0x100ED3D9, 0x100ED3DD, 0x100ED46D, 0x100EC5F3, 0x63,//
0x100EEAF3, 0x100EF077, 0x100EF75F, 0x100EF799, 0x100EF7A5, 0x100EECA1, 0x63,//
0x100F0CC9, 0x100F15F9, 0x100F18F1, 0x100F18F5, 0x100F1901, 0x100F0FD7, 0x63,//
0x100F1E9D, 0x100F21DB, 0x100F22FF, 0x100F2303, 0x100F230F, 0x100F205B, 0x63,//
};

//0x1036E4BC 原版的STAGE8的MOTION指针表
const int Stage8MotionTable[]={
0x100F2F7D, 0x100F4261, 0x100F4465, 0x100F4475, 0x100F44B1, 0x100F30E1, 0x63,//
0x100F5479, 0x100F6165, 0x100F6441, 0x100F6445, 0x100F6451, 0x100F5911, 0x63,//
0x100F6F31, 0x100F87B7, 0x100F900D, 0x100F9011, 0x100F901D, 0x100F755F, 0x63,//
0x100F9895, 0x100FA611, 0x100FA93F, 0x100FA943, 0x100FA94F, 0x100F9CC1, 0x63,//
0x100FB46D, 0x100FBE1D, 0x100FBEE3, 0x100FBF03, 0x100FBF0F, 0x100FB6FB, 0x63,//
0x100FCA87, 0x100FCBE9, 0x100FCF17, 0x100FCF31, 0x100FCF3D, 0x100FCBCD, 0x63,//
};

//0x1037449C 原版的STAGE9的MOTION指针表
const int Stage9MotionTable[]={
0x100FD2B9, 0x100FE1AF, 0x100FE3C9, 0x100FE3CD, 0x100FE3D9, 0x100FD387, 0x63,//
0x101033ED, 0x10103715, 0x10103D17, 0x10103D21, 0x10103D2D, 0x10103489, 0x63,//
0x101049C1, 0x10105827, 0x101059DD, 0x101059E1, 0x101059ED, 0x10104A9B, 0x63,//
0x10105CB3, 0x10106A0B, 0x10106C43, 0x10106C47, 0x10106C53, 0x10106501, 0x63,//
0x1010704D, 0x1010770B, 0x10107A75, 0x10107A79, 0x10107A85, 0x1010719D, 0x63,//
};

//0x1037E450 原版的STAGE10的MOTION指针表
const int Stage10MotionTable[]={
0x10108E33, 0x1010909B, 0x101096F5, 0x101096FF, 0x1010970B, 0x1010907D, 0x63,//
0x10109781, 0x1010990D, 0x10109A2F, 0x10109A39, 0x10109A45, 0x101098EF, 0x63,//
0x10109E19, 0x1010A0FD, 0x1010A3D3, 0x1010A3F1, 0x1010A3FD, 0x1010A04D, 0x63,//
0x1010AD09, 0x1010B3D9, 0x1010BBB5, 0x1010BBDB, 0x1010BBE7, 0x1010B351, 0x63,//
0x1010DFBF, 0x1010E1B7, 0x1010ED03, 0x1010ED29, 0x1010ED35, 0x1010E0B9, 0x63,//
};

//0x103859C4 原版的STAGE11的MOTION指针表
const int Stage11MotionTable[]={
0x1010FA9F, 0x1010FC45, 0x101100B9, 0x101100C3, 0x101100CF, 0x1010FBB7, 0x63,//
0x10110211, 0x101106BF, 0x101109CB, 0x101109D5, 0x101109E1, 0x10110635, 0x63,//
0x101125CF, 0x10112789, 0x101128AB, 0x101128C3, 0x101128CF, 0x10112733, 0x63,//
0x101128FB, 0x10112A95, 0x10112BC5, 0x10112BDD, 0x10112BE9, 0x10112A3B, 0x63,//
0x10112C2B, 0x10112DC5, 0x10112EF5, 0x10112F0D, 0x10112F19, 0x10112D6B, 0x63,//
0x10112F5B, 0x101130F5, 0x10113225, 0x10113239, 0x10113245, 0x1011309B, 0x63,//
0x10113287, 0x1011359D, 0x101136F9, 0x1011372B, 0x10113737, 0x101133C7, 0x63,//
0x10116DB9, 0x10117531, 0x10117D33, 0x10117D3D, 0x10117D49, 0x101174A7, 0x63,//
};

//0x10389128 原版的STAGE12的MOTION指针表
const int Stage12MotionTable[]={
0x10118D2F, 0x10119327, 0x1011A16D, 0x1011A195, 0x1011A1A1, 0x10119309, 0x63,//物品店
0x1011B157, 0x1011B561, 0x1011C1E5, 0x1011C1EF, 0x1011C1FB, 0x1011B543, 0x63,//维修店
0x1011C8B9, 0x1011CF1D, 0x1011E25B, 0x1011E265, 0x1011E271, 0x1011CC83, 0x63,//密码店
};

//0x1038AEF8 原版的STAGE13的MOTION指针表
const int Stage13MotionTable[]={
0x1011FC79, 0x1011FF7D, 0x1012024B, 0x10120265, 0x1012028D, 0x1011FF65, 0x63,//
0x1012474D, 0x10124A49, 0x10124A53, 0x10124A5D, 0x10124A69, 0x10124A2F, 0x63,//
0x10124AAD, 0x10124BB3, 0x10124BBD, 0x10124BCD, 0x10124BD9, 0x10124B99, 0x63,//
0x10125089, 0x101255DD, 0x101255E7, 0x101255F1, 0x101255FD, 0x101255C3, 0x63,//
0x10125635, 0x101256E5, 0x101256EF, 0x101256F9, 0x10125705, 0x101256CB, 0x63,//
0x10125721, 0x101258E3, 0x101258F1, 0x101258FF, 0x1012590B, 0x101257C1, 0x63,//
0x1012593D, 0x10125A55, 0x10125A5F, 0x10125A69, 0x10125A75, 0x10125A3B, 0x63,//
0x10125AA1, 0x10125B4B, 0x10125B55, 0x10125B5F, 0x10125B6B, 0x10125B31, 0x63,//
0x10125B85, 0x10125C79, 0x10125C83, 0x10125C8D, 0x10125C99, 0x10125C5F, 0x63,//
};

