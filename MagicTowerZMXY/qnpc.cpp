#include "qnpc.h"
#include <cstring>
//每个 NPCTILE 结构体的实例代表游戏中 NPC 的一个配置
//idTile[0] 和 idTile[1] 可以是相同（通常用来简单表示一个实体的静态图像）或不同（表示这个实体有多个帧或动画)
//idScript表达 NPC 或物体的类型、功能或交互方式
//bShow值为 1 时表示该 NPC 默认是可见的
NPCTILE QNpc::NpcData[MAX_NPC] ={
//            结构体数组

    {{0,0,0,0},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙1----0
    {{1,1,1,1},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙2----1
    {{2,2,2,2},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙3----2
    {{3,3,3,3},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙4----3
    {{4,439,4,439},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //蓝熔岩--4
    {{5,5,5,5},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙5----5
    {{6,6,6,6},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙6----6
    {{7,7,7,7},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙7----7
    {{8,8,8,8},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                       //墙8----8
    {{9,9,9,9},SI_SECRET, true,{0,0,0,0,0,0,0,0,0}},                      //机关1--9
    {{10,10,10,10},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                   //墙9----10
    {{11,11,11,11},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                   //墙10---11
    {{12,440,12,440},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                   //红熔岩--12
    {{13,441,13,441},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                   //星星1--13
    {{14,442,14,442},SI_WALL, true, {0,0,0,0,0,0,0,0,0}},                   //星星2--14
    {{15,15,15,15},SI_EXIT, true,{0,0,0,0,0,0,0,0,0}},                    //下楼---15
    {{16,16,16,16},SI_ENTRY, true,{0,0,0,0,0,0,0,0,0}},                   //上楼---16
    {{17,17,17,17},SI_FLOOR, true,{0,0,0,0,0,0,0,0,0}},                   //地板1--17
    {{18,18,18,18},SI_FLOOR, true,{0,0,0,0,0,0,0,0,0}},                   //地板2--18
    {{19,19,19,19},SI_FLOOR, true,{0,0,0,0,0,0,0,0,0}},                   //地板3--19
    {{20,20,20,20},SI_FLOOR, true,{0,0,0,0,0,0,0,0,0}},                   //地板4--20
    {{21,22,23,24},SI_DOOR, true,{0,0,0,0,0,0,0,0,0}},                    //黄门---21
    {{25,26,27,28},SI_DOOR, true,{0,0,0,0,0,0,0,0,0}},                    //蓝门---22
    {{29,30,31,32},SI_DOOR, true,{0,0,0,0,0,0,0,0,0}},                    //红门---23
    {{33,34,35,36},SI_SECRET, true,{0,0,0,0,0,0,0,0,0}},                  //机关2--24
    {{37,37,37,37},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //黄钥匙--25
    {{38,38,38,38},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //蓝钥匙--26
    {{39,39,39,39},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //红钥匙--27
    {{40,40,40,40},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //机关钥匙-28
    {{41,41,41,41},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石1---29
    {{42,42,42,42},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石2---30
    {{43,43,43,43},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石3---31
    {{44,44,44,44},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石4---32
    {{45,45,45,45},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石5---33
    {{46,46,46,46},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石6---34
    {{47,47,47,47},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石7---35
    {{48,48,48,48},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石8---36
    {{49,49,49,49},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石9---37
    {{50,50,50,50},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石10--38
    {{51,51,51,51},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石11--39
    {{52,52,52,52},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //宝石12--40
    {{53,53,53,53},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶1---41
    {{54,54,54,54},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶2---42
    {{55,55,55,55},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶3---43
    {{56,56,56,56},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶4---44
    {{57,57,57,57},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶5---45
    {{58,58,58,58},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶6---46
    {{59,59,59,59},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶7---47
    {{60,60,60,60},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶8---48
    {{61,61,61,61},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶9---49
    {{62,62,62,62},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶10--50
    {{63,63,63,63},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶11--51
    {{64,64,64,64},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //血瓶12--52
    {{65,65,65,65},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff1--53
    {{66,66,66,66},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff2--54
    {{67,67,67,67},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff3--55
    {{68,68,68,68},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff4--56
    {{69,69,69,69},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff5--57
    {{70,70,70,70},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff6--58
    {{71,71,71,71},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff7--59
    {{72,72,72,72},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //buff8--60
    {{73,73,73,73},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //经验瓶--61
    {{74,74,74,74},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //货币1---62
    {{75,75,75,75},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //货币2---63
    {{76,76,76,76},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //货币3---64
    {{77,77,77,77},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //货币4---65
    {{78,78,78,78},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //货币5---66
    {{79,79,79,79},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //点券----67
    {{80,80,80,80},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //星币----68
    {{81,81,81,81},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //灵魂1---69
    {{82,82,82,82},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //灵魂2---70
    {{83,83,83,83},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //礼包1---71
    {{84,84,84,84},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //礼包2---72
    {{85,85,85,85},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //红包----73
    {{86,86,86,86},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具1---74
    {{87,87,87,87},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具2---75
    {{88,88,88,88},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具3---76
    {{89,89,89,89},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具4---77
    {{90,90,90,90},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具5---78
    {{91,91,91,91},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具6---79
    {{92,92,92,92},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具7---80
    {{93,93,93,93},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具8---81
    {{94,94,94,94},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具9---82
    {{95,95,95,95},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //法具10--83
    {{96,96,96,96},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //材料1---84
    {{97,97,97,97},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //材料2---85
    {{98,98,98,98},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //材料3---86
    {{99,99,99,99},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},                  //材料4---87
    {{100,100,100,100},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //材料5---88
    {{101,101,101,101},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //材料6---89
    {{102,102,102,102},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //材料7---90
    {{103,103,103,103},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具1---91
    {{104,104,104,104},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具2---92
    {{105,105,105,105},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具3---93
    {{106,106,106,106},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具4---94
    {{107,107,107,107},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具5---95
    {{108,108,108,108},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具6---96
    {{109,109,109,109},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具7---97
    {{110,110,110,110},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具8---98
    {{111,111,111,111},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具9---99
    {{112,112,112,112},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具10--100
    {{113,113,113,113},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //防具12--101
    {{114,114,114,114},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器1---102
    {{115,115,115,115},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器2---103
    {{116,116,116,116},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器3---104
    {{117,117,117,117},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器4---105
    {{118,118,118,118},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器5---106
    {{119,119,119,119},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器6---107
    {{120,120,120,120},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器7---108
    {{121,121,121,121},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器8---109
    {{122,122,122,122},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器9---110
    {{123,123,123,123},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器10--111
    {{124,124,124,124},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器11--112
    {{125,125,125,125},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器12--113
    {{126,126,126,126},SI_OBJECT, true,{0,0,0,0,0,0,0,0,0}},              //武器13--114
    {{18,18,18,18},SI_ROLE, true,{1, 1000, 10, 10, 0, 0, 1, 1, 1}},    //角色16块单独存放,这里用地板替代 {127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142}---115
    {{143,144,145,146},SI_NPC, true,{0,0,0,0,0,0,0,0,0}},              //指引者--116
    {{147,148,149,150},SI_NPC, true,{0,0,0,0,0,0,0,0,0}},              //醉酒仙翁左-117
    {{151,152,153,154},SI_NPC, true,{0,0,0,0,0,0,0,0,0}},              //醉酒仙翁右-118
    {{155,156,157,158},SI_NPC, true,{0,0,0,0,0,0,0,0,0}},              //南瓜左----119
    {{159,160,161,162},SI_NPC, true,{0,0,0,0,0,0,0,0,0}},              //南瓜右----120
    {{163,164,165,166},SI_NPC, true,{0,0,0,0,0,0,0,0,0}},              //强盗左----121
    {{167,168,169,170},SI_NPC, true,{0,0,0,0,0,0,0,0,0}},              //强盗右----122
    {{171,172,173,174},SI_CELESTIAL,true, {0,0,0,0,0,0,0,0,0}},          //太白左--123
    {{175,176,177,178},SI_CELESTIAL,true, {0,0,0,0,0,0,0,0,0}},          //太白右--124
    {{179,180,181,182},SI_SHOP, true,{0,0,0,0,0,0,0,0,0}},             //商人-----125
    {{183,184,185,186},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //持国天王左-126
    {{187,188,189,190},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //持国天王右-127
    {{191,192,193,194},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //多闻天王左-128
    {{195,196,197,198},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //多闻天王右-129
    {{199,200,201,202},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //广目天王左-130
    {{203,204,205,206},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //广目天王右-131
    {{207,208,209,210},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //巨灵神左---132
    {{211,212,213,214},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //巨灵神右---133
    {{215,216,217,218},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //托塔天王左-134
    {{219,220,221,222},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //托塔天王右-135
    {{223,224,225,226},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //袁洪左----136
    {{227,228,229,230},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //袁洪右----137
    {{231,232,233,234},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //真广天王左-138
    {{235,236,237,238},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //真广天王右-139
    {{239,240,241,242},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //朱子真左--140
    {{243,244,245,246},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //朱子真右--141
    {{247,248,249,250},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //二郎神左--142
    {{251,252,253,254},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //二郎神右--143
    {{255,256,257,258},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵斧左--144
    {{259,260,261,262},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵斧右--145
    {{263,264,265,266},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天鹰左---146
    {{267,268,269,270},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天鹰右---147
    {{271,272,273,274},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //黑虎左---148
    {{275,276,277,278},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //黑虎右---149
    {{279,280,281,282},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵弓左-150
    {{283,284,285,286},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵弓右-151
    {{287,288,289,290},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天牛左---152
    {{291,292,293,294},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天牛右---153
    {{295,296,297,298},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天犬左---154
    {{299,300,301,302},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天犬右---155
    {{303,304,305,306},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //顺风耳左-156
    {{307,308,309,310},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //顺风耳右-157
    {{311,312,313,314},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //千里眼左-158
    {{315,316,317,318},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //千里眼右-159
    {{319,320,321,322},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天羊左---160
    {{323,324,325,326},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天羊右---161
    {{327,328,329,330},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵锤左-162
    {{331,332,333,334},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵锤右-163
    {{335,336,337,338},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵刀左-164
    {{339,340,341,342},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵刀右-165
    {{343,344,345,346},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //小轮转王左-166
    {{347,348,349,350},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //小轮转王右-167
    {{351,352,353,354},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //大轮转王左-168
    {{355,356,357,358},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //大轮转王右-169
    {{359,360,361,362},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //六耳猕猴左-170
    {{363,364,365,366},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //六耳猕猴右-171
    {{367,368,369,370},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //红翼左----172
    {{371,372,373,374},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //红翼右----173
    {{375,376,377,378},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天蛇左----174
    {{379,380,381,382},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天蛇右----175
    {{383,384,385,386},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵枪左--176
    {{387,388,389,390},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天兵枪右--177
    {{391,392,393,394},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //石怪左----178
    {{395,396,397,398},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //石怪右----179
    {{399,400,401,402},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天龟左----180
    {{403,404,405,406},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天龟右----181
    {{407,408,409,410},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天蜈左----182
    {{411,412,413,414},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //天蜈右----183
    {{415,416,417,418},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //鹰眼左----184
    {{419,420,421,422},SI_MONSTER, true,{0,0,0,0,0,0,0,0,0}},          //鹰眼右----185
};







QNpc::QNpc(QWidget *parent)
    : QWidget{parent}
{
    m_nTileIndex = 0;//初始化为 0 表示对象创建时，默认使用第一个图块。这意味着 CNpc 对象在创建时，默认显示第一帧或第一个状态。
    m_bShow = false;//默认不可见
    this->doorFlag=false;
    // memset(this->m_idTile,0,sizeof(this->m_idTile));
    npcTimer = new QTimer(this);
    connect(npcTimer, &QTimer::timeout, this, &QNpc::npcOnTimer);
    //npcTimer->start(200); //测试成功，在Qscene中触发
}

//从一个文件中读取 NPC 信息，并将其存储到 NpcInfo 数组中
//ZMXY版数据
void QNpc::initNpc()
{
    // qDebug()<<QDir::currentPath();
    QFile npcFile(NPC_FILE_NAME);
    if(!npcFile.open(QIODeviceBase::ReadOnly)){
        qDebug()<<"file error";
        return;
    }
    QDataStream in(&npcFile);
    in.setVersion(QDataStream::Qt_6_5);
    quint32 size;
    in>>size;//读取结构体数量
    for(quint32 i=0;i<size;i++)
    {
        in>>(QNpc::NpcData[i].npcInfo.nLevel)
        >>(QNpc::NpcData[i].npcInfo.nHealth)
            >>(QNpc::NpcData[i].npcInfo.nAttack)
            >>(QNpc::NpcData[i].npcInfo.nDefense)
            >>(QNpc::NpcData[i].npcInfo.nMoney)
            >>(QNpc::NpcData[i].npcInfo.nExperience)
            >>(QNpc::NpcData[i].npcInfo.nRedKey)
            >>(QNpc::NpcData[i].npcInfo.nBlueKey)
            >>(QNpc::NpcData[i].npcInfo.nYellowKey);
    }
    npcFile.close();
    // qDebug()<<"2";
}


//根据提供的idTile 从 NpcData 数组中加载一个 NPC 的数据
void QNpc::load(IDTILE idTile)
{
    this->m_id=idTile;
    for(int i=0;i<MAX_NPC;i++)
    {
        //检查传入的 idTile 是否等于当前遍历的元素的任一 idTile
        if(idTile==i)
        {
            //将 NpcData[i].idTile 的值复制到当前对象的 m_idTile 中
            for(int j=0;j<MAX_NPC_TILE;j++)
            {
                m_idTile[j] = NpcData[i].idTile[j];
            }
            m_idScript = NpcData[i].idScrpt;
            m_bShow = NpcData[i].bShow;
            m_npcInfo = NpcData[i].npcInfo;
            break;
        }
    }
}

// void QNpc::load(IDTILE idTile)
// {
//     for(int i=0;i<MAX_NPC;i++)
//     {
//         //检查传入的 idTile 是否等于当前遍历的元素的任一 idTile
//         if(idTile==NpcData[i].idTile[0]||idTile==NpcData[i].idTile[1]||id)
//         {
//             //将 NpcData[i].idTile 的值复制到当前对象的 m_idTile 中
//             for(int j=0;j<MAX_NPC_TILE;j++)
//             {
//                 m_idTile[j] = NpcData[i].idTile[j];
//             }
//             m_idScript = NpcData[i].idScrpt;
//             m_bShow = NpcData[i].bShow;
//             m_npcInfo = NpcData[i].npcInfo;
//             break;
//         }
//     }
// }

void QNpc::load(QNpc &npc)
{
    this->m_id=npc.m_id;
    for(int i=0;i<MAX_NPC_TILE;i++)
    {
        m_idTile[i] = npc.m_idTile[i];
    }
    m_nTileIndex = npc.m_nTileIndex;
    m_idScript = npc.m_idScript;
    m_bShow = npc.m_bShow;
}



//返回当前的图块 ID，如果 NPC 被隐藏，则返回地板图块 TILE_FLOOR
INDEX QNpc::getTileID()
{
    if(m_bShow)
    {
        return m_idTile[m_nTileIndex];
    }
    else
    {
        return TILE_FLOOR;//68
    }
}
//将成员变量 m_idTile 复制到外部数组，以便外界访问
void QNpc::getNpcTile(INDEX idTile[])
{
    for(int i=0;i<MAX_NPC_TILE;i++)
    {
        idTile[i] = m_idTile[i];
    }
}

NPCINFO QNpc::getNpcInfo()
{
    return m_npcInfo;
}

IDSCRIPT QNpc::getScriptID()
{
    if(m_bShow)
    {
        return m_idScript;
    }
    else
    {
        return 0;
    }
}

void QNpc::hide()
{
    m_bShow = false;
}

//通过更新 m_nTileIndex 来实现 NPC 动画或图块的帧切换
void QNpc::npcOnTimer()
{
    //将当前 NPC 实例的图块索引 m_nTileIndex 加 1，并对 MAX_NPC_TILE 取模，以确保索引在有效范围内循环
    // qDebug()<<"触发了定时器，调用了onTimer函数";
    m_nTileIndex = (m_nTileIndex + 1) % MAX_NPC_TILE;
    if(this->doorFlag &&  m_nTileIndex==MAX_NPC_TILE-1)
    {
        this->stopNpcTimer();
        emit this->stopDoorAnimation();
    }
    // qDebug()<<m_nTileIndex;
}


void QNpc::startNpcTimer()
{
    if(!this->isNpcTimerActive())
    {
        if(!this->doorFlag)
        {
            this->npcTimer->start(300);
        }else{
            this->npcTimer->start(100);
        }
    }
}

void QNpc::stopNpcTimer()
{
    this->npcTimer->stop();
}

bool QNpc::isNpcTimerActive()
{
    return this->npcTimer->isActive();
}

bool QNpc::isAutoAnimation()
{
    if(this->m_bShow&&(this->m_idScript==SI_MONSTER||this->m_idScript==SI_CELESTIAL||
    this->m_idScript==SI_SHOP||this->m_idScript==SI_NPC||this->m_idScript==SI_ROLE||this->m_idScript==SI_WALL))
    {
        return true;
    }
    return false;
}

void QNpc::setDoorFlag()
{
    this->doorFlag=true;
}

IDTILE QNpc::id() const
{
    return m_id;
}

//原版数据
// void QNpc::initNpc()
// {
//     QFile npcFile(NPC_FILE_NAME);
//     if(npcFile.open(QIODeviceBase::ReadOnly))
//     {
//         qDebug()<<"NPC文件打开成功";
//         int npcIndex = 0;
//         while (npcIndex < MAX_NPC && !npcFile.atEnd()) {
//             // 读取 NPCINFO 数据并写入到 NpcData 数组的 info 成员
//             npcFile.read(reinterpret_cast<char*>(&NpcData[npcIndex].npcInfo), sizeof(NPCINFO));
//             ++npcIndex;
//         }
//         qDebug()<<"文件基本成功完成读取";
//         npcFile.close();
//     }
//     else
//     {
//         qDebug()<<"无法打开Npc文件";
//     }
// }
