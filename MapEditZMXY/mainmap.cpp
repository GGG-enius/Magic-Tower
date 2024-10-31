#include "mainmap.h"


#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <cstring>
#include <QFile>

#include <QByteArray>
#include <QBuffer>
int MainMap::tileIDMapping[PIC_ABLE][4]={
    {0,0,0,0},
    {1,1,1,1},
    {2,2,2,2},
    {3,3,3,3},
    {4,4,4,4},
    {5,5,5,5},
    {6,6,6,6},
    {7,7,7,7},
    {8,8,8,8},
    {9,9,9,9},
    {10,10,10,10},
    {11,11,11,11},
    {12,12,12,12},
    {13,13,13,13},
    {14,14,14,14},
    {15,15,15,15},
    {16,16,16,16},
    {17,17,17,17},
    {18,18,18,18},
    {19,19,19,19},
    {20,20,20,20},
    {21,22,23,24},
    {25,26,27,28},
    {29,30,31,32},
    {33,34,35,36},
    {37,37,37,37},
    {38,38,38,38},
    {39,39,39,39},
    {40,40,40,40},
    {41,41,41,41},
    {42,42,42,42},
    {43,43,43,43},
    {44,44,44,44},
    {45,45,45,45},
    {46,46,46,46},
    {47,47,47,47},
    {48,48,48,48},
    {49,49,49,49},
    {50,50,50,50},
    {51,51,51,51},
    {52,52,52,52},
    {53,53,53,53},
    {54,54,54,54},
    {55,55,55,55},
    {56,56,56,56},
    {57,57,57,57},
    {58,58,58,58},
    {59,59,59,59},
    {60,60,60,60},
    {61,61,61,61},
    {62,62,62,62},
    {63,63,63,63},
    {64,64,64,64},
    {65,65,65,65},
    {66,66,66,66},
    {67,67,67,67},
    {68,68,68,68},
    {69,69,69,69},
    {70,70,70,70},
    {71,71,71,71},
    {72,72,72,72},
    {73,73,73,73},
    {74,74,74,74},
    {75,75,75,75},
    {76,76,76,76},
    {77,77,77,77},
    {78,78,78,78},
    {79,79,79,79},
    {80,80,80,80},
    {81,81,81,81},
    {82,82,82,82},
    {83,83,83,83},
    {84,84,84,84},
    {85,85,85,85},
    {86,86,86,86},
    {87,87,87,87},
    {88,88,88,88},
    {89,89,89,89},
    {90,90,90,90},
    {91,91,91,91},
    {92,92,92,92},
    {93,93,93,93},
    {94,94,94,94},
    {95,95,95,95},
    {96,96,96,96},
    {97,97,97,97},
    {98,98,98,98},
    {99,99,99,99},
    {100,100,100,100},
    {101,101,101,101},
    {102,102,102,102},
    {103,103,103,103},
    {104,104,104,104},
    {105,105,105,105},
    {106,106,106,106},
    {107,107,107,107},
    {108,108,108,108},
    {109,109,109,109},
    {110,110,110,110},
    {111,111,111,111},
    {112,112,112,112},
    {113,113,113,113},
    {114,114,114,114},
    {115,115,115,115},
    {116,116,116,116},
    {117,117,117,117},
    {118,118,118,118},
    {119,119,119,119},
    {120,120,120,120},
    {121,121,121,121},
    {122,122,122,122},
    {123,123,123,123},
    {124,124,124,124},
    {125,125,125,125},
    {126,126,126,126},
    {18,18,18,18},         ///<角色16块单独存放,这里用地板替代 {127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142},
    {143,144,145,146},
    {147,148,149,150},
    {151,152,153,154},
    {155,156,157,158},
    {159,160,161,162},
    {163,164,165,166},
    {167,168,169,170},
    {171,172,173,174},
    {175,176,177,178},      ///<太白右
    {179,180,181,182},
    {183,184,185,186},
    {187,188,189,190},
    {191,192,193,194},
    {195,196,197,198},
    {199,200,201,202},
    {203,204,205,206},
    {207,208,209,210},
    {211,212,213,214},
    {215,216,217,218},
    {219,220,221,222},
    {223,224,225,226},
    {227,228,229,230},
    {231,232,233,234},
    {235,236,237,238},
    {239,240,241,242},
    {243,244,245,246},
    {247,248,249,250},
    {251,252,253,254},
    {255,256,257,258},
    {259,260,261,262},
    {263,264,265,266},
    {267,268,269,270},
    {271,272,273,274},
    {275,276,277,278},
    {279,280,281,282},
    {283,284,285,286},
    {287,288,289,290},
    {291,292,293,294},
    {295,296,297,298},
    {299,300,301,302},
    {303,304,305,306},
    {307,308,309,310},
    {311,312,313,314},
    {315,316,317,318},
    {319,320,321,322},
    {323,324,325,326},
    {327,328,329,330},
    {331,332,333,334},
    {335,336,337,338},
    {339,340,341,342},
    {343,344,345,346},
    {347,348,349,350},
    {351,352,353,354},
    {355,356,357,358},
    {359,360,361,362},
    {363,364,365,366},
    {367,368,369,370},
    {371,372,373,374},
    {375,376,377,378},
    {379,380,381,382},
    {383,384,385,386},
    {387,388,389,390},
    {391,392,393,394},
    {395,396,397,398},
    {399,400,401,402},
    {403,404,405,406},
    {407,408,409,410},
    {411,412,413,414},
    {415,416,417,418},
    {419,420,421,422}
};
QString MainMap::tileURL[TILE_IMAGE_TOTAL]={
    ":/Image/Wall/Wall0001.png",
    ":/Image/Wall/Wall0002.png",
    ":/Image/Wall/Wall0003.png",
    ":/Image/Wall/Wall0004.png",
    ":/Image/Wall/Wall0005.png",
    ":/Image/Wall/Wall0006.png",
    ":/Image/Wall/Wall0007.png",
    ":/Image/Wall/Wall0008.png",
    ":/Image/Wall/Wall0009.png",
    ":/Image/Wall/Wall0010.png",
    ":/Image/Wall/Wall0011.png",
    ":/Image/Wall/Wall0012.png",
    ":/Image/Wall/Wall0013.png",
    ":/Image/Wall/Wall0014.png",
    ":/Image/Wall/Wall0015.png",
    ":/Image/Items/Other/other0001.png",
    ":/Image/Items/Other/other0002.png",
    ":/Image/Floor/Floor0001.png",
    ":/Image/Floor/Floor0002.png",
    ":/Image/Floor/Floor0003.png",
    ":/Image/Floor/Floor0004.png",
    ":/Image/Door/door0001.png",
    ":/Image/Door/door0005.png",
    ":/Image/Door/door0009.png",
    ":/Image/Door/door0013.png",
    ":/Image/Door/door0002.png",
    ":/Image/Door/door0006.png",
    ":/Image/Door/door0010.png",
    ":/Image/Door/door0014.png",
    ":/Image/Door/door0003.png",
    ":/Image/Door/door0007.png",
    ":/Image/Door/door0011.png",
    ":/Image/Door/door0015.png",
    ":/Image/Door/door0004.png",
    ":/Image/Door/door0008.png",
    ":/Image/Door/door0012.png",
    ":/Image/Door/door0016.png",
    ":/Image/Door/door0017.png",
    ":/Image/Door/door0018.png",
    ":/Image/Door/door0019.png",
    ":/Image/Door/door0020.png",
    ":/Image/Items/Blood/blood0001.png",
    ":/Image/Items/Blood/blood0002.png",
    ":/Image/Items/Blood/blood0003.png",
    ":/Image/Items/Blood/blood0004.png",
    ":/Image/Items/Blood/blood0005.png",
    ":/Image/Items/Blood/blood0006.png",
    ":/Image/Items/Blood/blood0007.png",
    ":/Image/Items/Blood/blood0008.png",
    ":/Image/Items/Blood/blood0009.png",
    ":/Image/Items/Blood/blood0010.png",
    ":/Image/Items/Blood/blood0011.png",
    ":/Image/Items/Blood/blood0012.png",
    ":/Image/Items/Blood/blood0013.png",
    ":/Image/Items/Blood/blood0014.png",
    ":/Image/Items/Blood/blood0015.png",
    ":/Image/Items/Blood/blood0016.png",
    ":/Image/Items/Blood/blood0017.png",
    ":/Image/Items/Blood/blood0018.png",
    ":/Image/Items/Blood/blood0019.png",
    ":/Image/Items/Blood/blood0020.png",
    ":/Image/Items/Blood/blood0021.png",
    ":/Image/Items/Blood/blood0022.png",
    ":/Image/Items/Blood/blood0023.png",
    ":/Image/Items/Blood/blood0024.png",
    ":/Image/Items/Blood/blood0025.png",
    ":/Image/Items/Blood/blood0026.png",
    ":/Image/Items/Blood/blood0027.png",
    ":/Image/Items/Blood/blood0028.png",
    ":/Image/Items/Blood/blood0029.png",
    ":/Image/Items/Blood/blood0030.png",
    ":/Image/Items/Blood/blood0031.png",
    ":/Image/Items/Blood/blood0032.png",
    ":/Image/Items/Blood/blood0033.png",
    ":/Image/Items/Money/money0001.png",
    ":/Image/Items/Money/money0002.png",
    ":/Image/Items/Money/money0003.png",
    ":/Image/Items/Money/money0004.png",
    ":/Image/Items/Money/money0005.png",
    ":/Image/Items/Money/money0006.png",
    ":/Image/Items/Money/money0007.png",
    ":/Image/Items/Money/money0008.png",
    ":/Image/Items/Money/money0009.png",
    ":/Image/Items/Tool/wuping0001.png",
    ":/Image/Items/Tool/wuping0002.png",
    ":/Image/Items/Tool/wuping0003.png",
    ":/Image/Items/Tool/wuping0004.png",
    ":/Image/Items/Tool/wuping0005.png",
    ":/Image/Items/Tool/wuping0006.png",
    ":/Image/Items/Tool/wuping0007.png",
    ":/Image/Items/Tool/wuping0008.png",
    ":/Image/Items/Tool/wuping0009.png",
    ":/Image/Items/Tool/wuping0010.png",
    ":/Image/Items/Tool/wuping0011.png",
    ":/Image/Items/Tool/wuping0012.png",
    ":/Image/Items/Tool/wuping0013.png",
    ":/Image/Items/Tool/wuping0014.png",
    ":/Image/Items/Tool/wuping0015.png",
    ":/Image/Items/Tool/wuping0016.png",
    ":/Image/Items/Tool/wuping0017.png",
    ":/Image/Items/Tool/wuping0018.png",
    ":/Image/Items/Tool/wuping0019.png",
    ":/Image/Items/Tool/wuping0020.png",
    ":/Image/Items/RoleX/role0001.png",
    ":/Image/Items/RoleX/role0002.png",
    ":/Image/Items/RoleX/role0003.png",
    ":/Image/Items/RoleX/role0004.png",
    ":/Image/Items/RoleX/role0005.png",
    ":/Image/Items/RoleX/role0006.png",
    ":/Image/Items/RoleX/role0007.png",
    ":/Image/Items/RoleX/role0008.png",
    ":/Image/Items/RoleX/role0009.png",
    ":/Image/Items/RoleX/role0010.png",
    ":/Image/Items/RoleX/role0011.png",
    ":/Image/Items/RoleX/role0012.png",
    ":/Image/Items/RoleX/role0013.png",
    ":/Image/Items/RoleX/role0014.png",
    ":/Image/Items/RoleX/role0015.png",
    ":/Image/Items/RoleX/role0016.png",
    ":/Image/Items/RoleX/role0017.png",
    ":/Image/Items/RoleX/role0018.png",
    ":/Image/Items/RoleX/role0019.png",
    ":/Image/Items/RoleX/role0020.png",
    ":/Image/Items/RoleX/role0021.png",
    ":/Image/Items/RoleX/role0022.png",
    ":/Image/Items/RoleX/role0023.png",
    ":/Image/Items/RoleX/role0024.png",
    ":/Image/Role/WuKong0001.png",
    ":/Image/Role/WuKong0002.png",
    ":/Image/Role/WuKong0003.png",
    ":/Image/Role/WuKong0004.png",
    ":/Image/Role/WuKong0005.png",
    ":/Image/Role/WuKong0006.png",
    ":/Image/Role/WuKong0007.png",
    ":/Image/Role/WuKong0008.png",
    ":/Image/Role/WuKong0009.png",
    ":/Image/Role/WuKong0010.png",
    ":/Image/Role/WuKong0011.png",
    ":/Image/Role/WuKong0012.png",
    ":/Image/Role/WuKong0013.png",
    ":/Image/Role/WuKong0014.png",
    ":/Image/Role/WuKong0015.png",
    ":/Image/Role/WuKong0016.png",
    ":/Image/NPC/Guidener0001.png",
    ":/Image/NPC/Guidener0002.png",
    ":/Image/NPC/Guidener0003.png",
    ":/Image/NPC/Guidener0004.png",
    ":/Image/NPC/JiuWenLeft0001.png",
    ":/Image/NPC/JiuWenLeft0002.png",
    ":/Image/NPC/JiuWenLeft0003.png",
    ":/Image/NPC/JiuWenLeft0004.png",
    ":/Image/NPC/JiuWenRight0001.png",
    ":/Image/NPC/JiuWenRight0002.png",
    ":/Image/NPC/JiuWenRight0003.png",
    ":/Image/NPC/JiuWenRight0004.png",
    ":/Image/NPC/NanGuaLeft0001.png",
    ":/Image/NPC/NanGuaLeft0002.png",
    ":/Image/NPC/NanGuaLeft0003.png",
    ":/Image/NPC/NanGuaLeft0004.png",
    ":/Image/NPC/NanGuaRight0001.png",
    ":/Image/NPC/NanGuaRight0002.png",
    ":/Image/NPC/NanGuaRight0003.png",
    ":/Image/NPC/NanGuaRight0004.png",
    ":/Image/NPC/RobberLeft0001.png",
    ":/Image/NPC/RobberLeft0002.png",
    ":/Image/NPC/RobberLeft0003.png",
    ":/Image/NPC/RobberLeft0004.png",
    ":/Image/NPC/RobberRight0001.png",
    ":/Image/NPC/RobberRight0002.png",
    ":/Image/NPC/RobberRight0003.png",
    ":/Image/NPC/RobberRight0004.png",
    ":/Image/NPC/TaiBaiLeft0001.png",
    ":/Image/NPC/TaiBaiLeft0002.png",
    ":/Image/NPC/TaiBaiLeft0003.png",
    ":/Image/NPC/TaiBaiLeft0004.png",
    ":/Image/NPC/TaiBaiRight0001.png",
    ":/Image/NPC/TaiBaiRight0002.png",
    ":/Image/NPC/TaiBaiRight0003.png",
    ":/Image/NPC/TaiBaiRight0004.png",
    ":/Image/NPC/Trader0001.png",
    ":/Image/NPC/Trader0002.png",
    ":/Image/NPC/Trader0003.png",
    ":/Image/NPC/Trader0004.png",
    ":/Image/Boss/BossChiGuoTianWanLeft0001.png",
    ":/Image/Boss/BossChiGuoTianWanLeft0002.png",
    ":/Image/Boss/BossChiGuoTianWanLeft0003.png",
    ":/Image/Boss/BossChiGuoTianWanLeft0004.png",
    ":/Image/Boss/BossChiGuoTianWanRight0001.png",
    ":/Image/Boss/BossChiGuoTianWanRight0002.png",
    ":/Image/Boss/BossChiGuoTianWanRight0003.png",
    ":/Image/Boss/BossChiGuoTianWanRight0004.png",
    ":/Image/Boss/BossDuoWenTianWanLeft0001.png",
    ":/Image/Boss/BossDuoWenTianWanLeft0002.png",
    ":/Image/Boss/BossDuoWenTianWanLeft0003.png",
    ":/Image/Boss/BossDuoWenTianWanLeft0004.png",
    ":/Image/Boss/BossDuoWenTianWanRight0001.png",
    ":/Image/Boss/BossDuoWenTianWanRight0002.png",
    ":/Image/Boss/BossDuoWenTianWanRight0003.png",
    ":/Image/Boss/BossDuoWenTianWanRight0004.png",
    ":/Image/Boss/BossGuangMuTianWanLeft0001.png",
    ":/Image/Boss/BossGuangMuTianWanLeft0002.png",
    ":/Image/Boss/BossGuangMuTianWanLeft0003.png",
    ":/Image/Boss/BossGuangMuTianWanLeft0004.png",
    ":/Image/Boss/BossGuangMuTianWanRight0001.png",
    ":/Image/Boss/BossGuangMuTianWanRight0002.png",
    ":/Image/Boss/BossGuangMuTianWanRight0003.png",
    ":/Image/Boss/BossGuangMuTianWanRight0004.png",
    ":/Image/Boss/BossJuLingShenLeft0001.png",
    ":/Image/Boss/BossJuLingShenLeft0002.png",
    ":/Image/Boss/BossJuLingShenLeft0003.png",
    ":/Image/Boss/BossJuLingShenLeft0004.png",
    ":/Image/Boss/BossJuLingShenRight0001.png",
    ":/Image/Boss/BossJuLingShenRight0002.png",
    ":/Image/Boss/BossJuLingShenRight0003.png",
    ":/Image/Boss/BossJuLingShenRight0004.png",
    ":/Image/Boss/BossTuoTowerLeft0001.png",
    ":/Image/Boss/BossTuoTowerLeft0002.png",
    ":/Image/Boss/BossTuoTowerLeft0003.png",
    ":/Image/Boss/BossTuoTowerLeft0004.png",
    ":/Image/Boss/BossTuoTowerRight0001.png",
    ":/Image/Boss/BossTuoTowerRight0002.png",
    ":/Image/Boss/BossTuoTowerRight0003.png",
    ":/Image/Boss/BossTuoTowerRight0004.png",
    ":/Image/Boss/BossYuanHongLeft0001.png",
    ":/Image/Boss/BossYuanHongLeft0002.png",
    ":/Image/Boss/BossYuanHongLeft0003.png",
    ":/Image/Boss/BossYuanHongLeft0004.png",
    ":/Image/Boss/BossYuanHongRight0001.png",
    ":/Image/Boss/BossYuanHongRight0002.png",
    ":/Image/Boss/BossYuanHongRight0003.png",
    ":/Image/Boss/BossYuanHongRight0004.png",
    ":/Image/Boss/BossZenZhangTianWangLeft0001.png",
    ":/Image/Boss/BossZenZhangTianWangLeft0002.png",
    ":/Image/Boss/BossZenZhangTianWangLeft0003.png",
    ":/Image/Boss/BossZenZhangTianWangLeft0004.png",
    ":/Image/Boss/BossZenZhangTianWanRight0001.png",
    ":/Image/Boss/BossZenZhangTianWanRight0002.png",
    ":/Image/Boss/BossZenZhangTianWanRight0003.png",
    ":/Image/Boss/BossZenZhangTianWanRight0004.png",
    ":/Image/Boss/BossZhuZiZhenLeft0001.png",
    ":/Image/Boss/BossZhuZiZhenLeft0002.png",
    ":/Image/Boss/BossZhuZiZhenLeft0003.png",
    ":/Image/Boss/BossZhuZiZhenLeft0004.png",
    ":/Image/Boss/BossZhuZiZhenRight0001.png",
    ":/Image/Boss/BossZhuZiZhenRight0002.png",
    ":/Image/Boss/BossZhuZiZhenRight0003.png",
    ":/Image/Boss/BossZhuZiZhenRight0004.png",
    ":/Image/Boss/YangJianLeft0001.png",
    ":/Image/Boss/YangJianLeft0002.png",
    ":/Image/Boss/YangJianLeft0003.png",
    ":/Image/Boss/YangJianLeft0004.png",
    ":/Image/Boss/YangJianRight0001.png",
    ":/Image/Boss/YangJianRight0002.png",
    ":/Image/Boss/YangJianRight0003.png",
    ":/Image/Boss/YangJianRight0004.png",
    ":/Image/Guard/GuardAxeLeft0001.png",
    ":/Image/Guard/GuardAxeLeft0002.png",
    ":/Image/Guard/GuardAxeLeft0003.png",
    ":/Image/Guard/GuardAxeLeft0004.png",
    ":/Image/Guard/GuardAxeRight0001.png",
    ":/Image/Guard/GuardAxeRight0002.png",
    ":/Image/Guard/GuardAxeRight0003.png",
    ":/Image/Guard/GuardAxeRight0004.png",
    ":/Image/Guard/GuardBirdLeft0001.png",
    ":/Image/Guard/GuardBirdLeft0002.png",
    ":/Image/Guard/GuardBirdLeft0003.png",
    ":/Image/Guard/GuardBirdLeft0004.png",
    ":/Image/Guard/GuardBirdRight0001.png",
    ":/Image/Guard/GuardBirdRight0002.png",
    ":/Image/Guard/GuardBirdRight0003.png",
    ":/Image/Guard/GuardBirdRight0004.png",
    ":/Image/Guard/GuardBlackTigerLeft0001.png",
    ":/Image/Guard/GuardBlackTigerLeft0002.png",
    ":/Image/Guard/GuardBlackTigerLeft0003.png",
    ":/Image/Guard/GuardBlackTigerLeft0004.png",
    ":/Image/Guard/GuardBlackTigerRight0001.png",
    ":/Image/Guard/GuardBlackTigerRight0002.png",
    ":/Image/Guard/GuardBlackTigerRight0003.png",
    ":/Image/Guard/GuardBlackTigerRight0004.png",
    ":/Image/Guard/GuardBowLeft0001.png",
    ":/Image/Guard/GuardBowLeft0002.png",
    ":/Image/Guard/GuardBowLeft0003.png",
    ":/Image/Guard/GuardBowLeft0004.png",
    ":/Image/Guard/GuardBowRight0001.png",
    ":/Image/Guard/GuardBowRight0002.png",
    ":/Image/Guard/GuardBowRight0003.png",
    ":/Image/Guard/GuardBowRight0004.png",
    ":/Image/Guard/GuardCowLeft0001.png",
    ":/Image/Guard/GuardCowLeft0002.png",
    ":/Image/Guard/GuardCowLeft0003.png",
    ":/Image/Guard/GuardCowLeft0004.png",
    ":/Image/Guard/GuardCowRight0001.png",
    ":/Image/Guard/GuardCowRight0002.png",
    ":/Image/Guard/GuardCowRight0003.png",
    ":/Image/Guard/GuardCowRight0004.png",
    ":/Image/Guard/GuardDogLeft0001.png",
    ":/Image/Guard/GuardDogLeft0002.png",
    ":/Image/Guard/GuardDogLeft0003.png",
    ":/Image/Guard/GuardDogLeft0004.png",
    ":/Image/Guard/GuardDogRight0001.png",
    ":/Image/Guard/GuardDogRight0002.png",
    ":/Image/Guard/GuardDogRight0003.png",
    ":/Image/Guard/GuardDogRight0004.png",
    ":/Image/Guard/GuardEarLeft0001.png",
    ":/Image/Guard/GuardEarLeft0002.png",
    ":/Image/Guard/GuardEarLeft0003.png",
    ":/Image/Guard/GuardEarLeft0004.png",
    ":/Image/Guard/GuardEarRight0001.png",
    ":/Image/Guard/GuardEarRight0002.png",
    ":/Image/Guard/GuardEarRight0003.png",
    ":/Image/Guard/GuardEarRight0004.png",
    ":/Image/Guard/GuardEyeLeft0001.png",
    ":/Image/Guard/GuardEyeLeft0002.png",
    ":/Image/Guard/GuardEyeLeft0003.png",
    ":/Image/Guard/GuardEyeLeft0004.png",
    ":/Image/Guard/GuardEyeRight0001.png",
    ":/Image/Guard/GuardEyeRight0002.png",
    ":/Image/Guard/GuardEyeRight0003.png",
    ":/Image/Guard/GuardEyeRight0004.png",
    ":/Image/Guard/GuardGoatLeftc0001.png",
    ":/Image/Guard/GuardGoatLeftc0002.png",
    ":/Image/Guard/GuardGoatLeftc0003.png",
    ":/Image/Guard/GuardGoatLeftc0004.png",
    ":/Image/Guard/GuardGoatRight0001.png",
    ":/Image/Guard/GuardGoatRight0002.png",
    ":/Image/Guard/GuardGoatRight0003.png",
    ":/Image/Guard/GuardGoatRight0004.png",
    ":/Image/Guard/GuardHammerLeft0001.png",
    ":/Image/Guard/GuardHammerLeft0002.png",
    ":/Image/Guard/GuardHammerLeft0003.png",
    ":/Image/Guard/GuardHammerLeft0004.png",
    ":/Image/Guard/GuardHammerRight0001.png",
    ":/Image/Guard/GuardHammerRight0002.png",
    ":/Image/Guard/GuardHammerRight0003.png",
    ":/Image/Guard/GuardHammerRight0004.png",
    ":/Image/Guard/GuardKnifeLeft0001.png",
    ":/Image/Guard/GuardKnifeLeft0002.png",
    ":/Image/Guard/GuardKnifeLeft0003.png",
    ":/Image/Guard/GuardKnifeLeft0004.png",
    ":/Image/Guard/GuardKnifeRight0001.png",
    ":/Image/Guard/GuardKnifeRight0002.png",
    ":/Image/Guard/GuardKnifeRight0003.png",
    ":/Image/Guard/GuardKnifeRight0004.png",
    ":/Image/Guard/GuardLunLeft0001.png",
    ":/Image/Guard/GuardLunLeft0002.png",
    ":/Image/Guard/GuardLunLeft0003.png",
    ":/Image/Guard/GuardLunLeft0004.png",
    ":/Image/Guard/GuardLunRight0001.png",
    ":/Image/Guard/GuardLunRight0002.png",
    ":/Image/Guard/GuardLunRight0003.png",
    ":/Image/Guard/GuardLunRight0004.png",
    ":/Image/Guard/GuardLunZhuanWanLeft0001.png",
    ":/Image/Guard/GuardLunZhuanWanLeft0002.png",
    ":/Image/Guard/GuardLunZhuanWanLeft0003.png",
    ":/Image/Guard/GuardLunZhuanWanLeft0004.png",
    ":/Image/Guard/GuardLunZhuanWanRight0001.png",
    ":/Image/Guard/GuardLunZhuanWanRight0002.png",
    ":/Image/Guard/GuardLunZhuanWanRight0003.png",
    ":/Image/Guard/GuardLunZhuanWanRight0004.png",
    ":/Image/Guard/GuardMiHouLeft0001.png",
    ":/Image/Guard/GuardMiHouLeft0002.png",
    ":/Image/Guard/GuardMiHouLeft0003.png",
    ":/Image/Guard/GuardMiHouLeft0004.png",
    ":/Image/Guard/GuardMiHouRight0001.png",
    ":/Image/Guard/GuardMiHouRight0002.png",
    ":/Image/Guard/GuardMiHouRight0003.png",
    ":/Image/Guard/GuardMiHouRight0004.png",
    ":/Image/Guard/GuardRedEagleLeft0001.png",
    ":/Image/Guard/GuardRedEagleLeft0002.png",
    ":/Image/Guard/GuardRedEagleLeft0003.png",
    ":/Image/Guard/GuardRedEagleLeft0004.png",
    ":/Image/Guard/GuardRedEagleRight0001.png",
    ":/Image/Guard/GuardRedEagleRight0002.png",
    ":/Image/Guard/GuardRedEagleRight0003.png",
    ":/Image/Guard/GuardRedEagleRight0004.png",
    ":/Image/Guard/GuardSnakeLeft0001.png",
    ":/Image/Guard/GuardSnakeLeft0002.png",
    ":/Image/Guard/GuardSnakeLeft0003.png",
    ":/Image/Guard/GuardSnakeLeft0004.png",
    ":/Image/Guard/GuardSnakeRight0001.png",
    ":/Image/Guard/GuardSnakeRight0002.png",
    ":/Image/Guard/GuardSnakeRight0003.png",
    ":/Image/Guard/GuardSnakeRight0004.png",
    ":/Image/Guard/GuardSpearLeft0001.png",
    ":/Image/Guard/GuardSpearLeft0002.png",
    ":/Image/Guard/GuardSpearLeft0003.png",
    ":/Image/Guard/GuardSpearLeft0004.png",
    ":/Image/Guard/GuardSpearRight0001.png",
    ":/Image/Guard/GuardSpearRight0002.png",
    ":/Image/Guard/GuardSpearRight0003.png",
    ":/Image/Guard/GuardSpearRight0004.png",
    ":/Image/Guard/GuardStoneLeft0001.png",
    ":/Image/Guard/GuardStoneLeft0002.png",
    ":/Image/Guard/GuardStoneLeft0003.png",
    ":/Image/Guard/GuardStoneLeft0004.png",
    ":/Image/Guard/GuardStoneRight0001.png",
    ":/Image/Guard/GuardStoneRight0002.png",
    ":/Image/Guard/GuardStoneRight0003.png",
    ":/Image/Guard/GuardStoneRight0004.png",
    ":/Image/Guard/GuardTortoiseLeft0001.png",
    ":/Image/Guard/GuardTortoiseLeft0002.png",
    ":/Image/Guard/GuardTortoiseLeft0003.png",
    ":/Image/Guard/GuardTortoiseLeft0004.png",
    ":/Image/Guard/GuardTortoiseRight0001.png",
    ":/Image/Guard/GuardTortoiseRight0002.png",
    ":/Image/Guard/GuardTortoiseRight0003.png",
    ":/Image/Guard/GuardTortoiseRight0004.png",
    ":/Image/Guard/GuardWuGonLeft0001.png",
    ":/Image/Guard/GuardWuGonLeft0002.png",
    ":/Image/Guard/GuardWuGonLeft0003.png",
    ":/Image/Guard/GuardWuGonLeft0004.png",
    ":/Image/Guard/GuardWuGonRight0001.png",
    ":/Image/Guard/GuardWuGonRight0002.png",
    ":/Image/Guard/GuardWuGonRight0003.png",
    ":/Image/Guard/GuardWuGonRight0004.png",
    ":/Image/Guard/GuardYingDaoLeft0001.png",
    ":/Image/Guard/GuardYingDaoLeft0002.png",
    ":/Image/Guard/GuardYingDaoLeft0003.png",
    ":/Image/Guard/GuardYingDaoLeft0004.png",
    ":/Image/Guard/GuardYingDaoRight0001.png",
    ":/Image/Guard/GuardYingDaoRight0002.png",
    ":/Image/Guard/GuardYingDaoRight0003.png",
    ":/Image/Guard/GuardYingDaoRight0004.png",
};
int MainMap::curLayer=0;
int MainMap::mapBuf[MAP_LAYER][CURMAP_W][CURMAP_H];
MainMap::MainMap(QWidget *parent)
    :QWidget(parent)
{
    memset(MainMap::mapBuf,18,sizeof(MainMap::mapBuf));
    this->setFixedSize(MAP_WIDTH*TILE_WIDTH,MAP_HEIGHT*TILE_HEIGHT);
    this->curMapArea=this->rect().adjusted(TILE_WIDTH,TILE_HEIGHT,-TILE_WIDTH,-TILE_HEIGHT);

    //测试!!!事关程序正常运行，一定要初始化变量
    // this->setCurLayer(0);
    // this->setCurSelectTileID(1);
    // this->setDefaultFloorID(1);
    // this->initMap=false;
}

void MainMap::paintEvent(QPaintEvent *e)
{
    QPainter painter_map(this);


    //painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);//测试


    //painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,pngPixmap);//测试

    QPixmap backgroundPixmap;
    QPixmap pngPixmap;
    painter_map.setCompositionMode(QPainter::CompositionMode_SourceAtop);//设置混合模式



    //测试动画
    // backgroundPixmap.load(":/Floor/Floor0002.png");
    // painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);
    // (this->tt)%=4;
    // pngPixmap.load(MainMap::tileURL[this->tt++]);
    // painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,pngPixmap);




    // if(this->initMap)
    // {
    //     for(int i=0;i<13;i++)
    //     {
    //         for(int j=0;j<13;j++)
    //         {
    //             backgroundPixmap.load(":/Floor/Floor0002.png");
    //             painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);

    //         }
    //     }
    // }
    // else
    // {
    // qDebug()<<this->getCurLayer();
        for(int i=0;i<MAP_HEIGHT;i++)
        {
            for(int j=0;j<MAP_WIDTH;j++)
            {
                if(i==0||j==0||i==(MAP_HEIGHT-1)||j==(MAP_WIDTH-1))
                {
                    backgroundPixmap.load(TileButton::tileURL[11]);
                    painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);
                    if(i==0&&j==0)
                    {
                        pngPixmap.load(":/Image/NPC/WuJing.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }else if(i==0&&j==(MAP_WIDTH-1))
                    {
                        pngPixmap.load(":/Image/NPC/XuanZang.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }else if(i==(MAP_HEIGHT-1)&&j==0)
                    {
                        pngPixmap.load(":/Image/NPC/WuKong.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }else if(i==(MAP_HEIGHT-1)&&j==(MAP_WIDTH-1))
                    {
                        pngPixmap.load(":/Image/NPC/WuNeng.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }
                }
                else
                {
                    int index=MainMap::mapBuf[MainMap::curLayer][j-1][i-1];
                    //QString url=MapArea::tileURL[index];//???
                    QString url=TileButton::tileURL[index];

                    // backgroundPixmap.load(url);
                    backgroundPixmap.load(":/Image/Floor/Floor0002.png");
                    painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);
                    pngPixmap.load(url);
                    // // pngPixmap.load(":/Guard/GuardBow0001.png");

                    painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                }
            }
        }
    //}
    QWidget::paintEvent(e);
}

void MainMap::mousePressEvent(QMouseEvent *e)
{
    if(this->curMapArea.contains(e->pos()))
    {
        int x=(e->pos().x()-this->curMapArea.topLeft().x())/TILE_WIDTH;
        int y=(e->pos().y()-this->curMapArea.topLeft().y())/TILE_HEIGHT;
        if(e->button()==Qt::LeftButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::curSelectTileID;
            // qDebug()<<"layer: "<<MainMap::curLayer;
            // qDebug()<<"id:    "<<TileButton::curSelectTileID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        else if(e->button()==Qt::RightButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::defaultFloorID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        // qDebug()<<"层:"<<this->getCurLayer();
        // qDebug()<<"坐标:"<<x<<","<<y;
    }
    else
    {
        // qDebug()<<"出界";
    }
    this->update();
    return QWidget::mousePressEvent(e);
}

void MainMap::mouseMoveEvent(QMouseEvent *e)
{
    if(this->curMapArea.contains(e->pos()))
    {
        int x=(e->pos().x()-this->curMapArea.topLeft().x())/TILE_WIDTH;
        int y=(e->pos().y()-this->curMapArea.topLeft().y())/TILE_HEIGHT;
        if(e->buttons() & Qt::LeftButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::curSelectTileID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        else if(e->buttons() & Qt::RightButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::defaultFloorID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        //qDebug()<<"层:"<<this->getCurLayer();
        // qDebug()<<"坐标:"<<x<<","<<y;
    }
    else
    {
        // qDebug()<<"出界";
    }
    this->update();
    return QWidget::mouseMoveEvent(e);
}


//让顶层去实现
// void MainMap::keyPressEvent(QKeyEvent *e)
// {
//     // if(e->key()==Qt::Key_S)
//     // {
//     //     qDebug()<<"Save";
//     // }
//     QWidget::keyPressEvent(e);
// }

// int MainMap::getCurSelectTileID()
// {
//     return this->curSelectTileID;
// }

// void MainMap::setCurSelectTileID(int value)
// {
//     this->curSelectTileID=value;
// }

// int MainMap::getCurLayer()
// {
//     return this->curLayer;
// }

// void MainMap::setCurLayer(int value)
// {
//     this->curLayer=value;
// }

// int MainMap::getDefaultFloorID()
// {
//     return this->defaultFloorID;
// }

// void MainMap::setDefaultFloorID(int value)
// {
//     this->defaultFloorID=value;
// }

bool MainMap::readImageFile()
{
    // qDebug()<<QDir::currentPath();
    QFile tileFile(TILE_FILE_NAME);
    if(!tileFile.open(QIODeviceBase::ReadOnly)){
        return false;
    }
    int i=0;
    while(!tileFile.atEnd())
    {
        qint64 dataSize=0;
        if(tileFile.read((char*)&dataSize,sizeof(dataSize))!=sizeof(dataSize))
        {
            break;
        }
        QByteArray byteArray;
        byteArray.resize(dataSize);
        if(tileFile.read(byteArray.data(),dataSize)!=dataSize)
        {
            break;
        }
        if(!TileButton::tilePNG[i].loadFromData(byteArray,"PNG"))
        {
            break;
        }
        i++;
    }
    tileFile.close();
    return true;
}


bool MainMap::writeImageFile()
{
    QFile tileFile("../../IOFile/Tile.bin");
    if(!tileFile.open(QIODeviceBase::WriteOnly)){
        qDebug()<<tileFile.errorString();
        return false;
    }

    for(int i=0;i<TILE_IMAGE_TOTAL;i++)
    {
        QImage image(MainMap::tileURL[i]);
        if(image.isNull())
        {
            qDebug()<<"failed to load png image"<<TileButton::tileURL[i];
            continue;
        }
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        if(!image.save(&buffer,"PNG"))
        {
            qDebug()<<"failed to save image to binary"<<TileButton::tileURL[i];
            continue;
        }

        qint64 dataSize=byteArray.size();
        tileFile.write((const char* )&dataSize,sizeof(dataSize));
        tileFile.write(byteArray);
    }

    tileFile.close();
    return true;
}

bool MainMap::readMapFile()
{
    // qDebug()<<QDir::currentPath();
    QFile mapFile(MAP_FILE_NAME);
    if(!mapFile.open(QIODeviceBase::ReadOnly)){
        return false;
    }
    QDataStream in(&mapFile);
    in.setVersion(QDataStream::Qt_6_7);
    int dim1,dim2,dim3;
    in>>dim1>>dim2>>dim3;//读取维度信息
    for(int i=0;i<dim1;i++)
    {
        for(int j=0;j<dim2;j++)
        {
            for(int k=0;k<dim3;k++)
            {
                in>>MainMap::mapBuf[i][j][k];
            }
        }
    }
    mapFile.close();
    return true;
}

bool MainMap::writeMapFile()
{
    QFile mapFile("../../IOFile/Map.bin");
    if(!mapFile.open(QIODeviceBase::WriteOnly)){
        qDebug()<<mapFile.errorString();
        return false;
    }
    // qDebug()<<"empty";
    QDataStream out(&mapFile);
    out.setVersion(QDataStream::Qt_6_7);
    out << MAP_LAYER<<CURMAP_W<<CURMAP_H;//写入维度信息

    for(int i=0;i<MAP_LAYER;i++)
    {
        for(int j=0;j<CURMAP_H;j++)
        {
            for(int k=0;k<CURMAP_W;k++)
            {
                out<<MainMap::mapBuf[i][j][k];
            }
        }
    }
    mapFile.close();
    return true;
}


