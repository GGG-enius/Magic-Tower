#include "qnpc.h"

//每个 NPCTILE 结构体的实例代表游戏中 NPC 的一个配置
//idTile[0] 和 idTile[1] 可以是相同（通常用来简单表示一个实体的静态图像）或不同（表示这个实体有多个帧或动画)
//idScript表达 NPC 或物体的类型、功能或交互方式
//bShow值为 1 时表示该 NPC 默认是可见的
NPCTILE QNpc::NpcData[MAX_NPC] ={
//            结构体数组

    {36,  36,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//盾1
    {37,  37,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//盾2
    {38,  38,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//盾3
    {39,  39,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//盾4
    {40,  40,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//盾5
    {41,  41,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//剑1
    {42,  42,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//剑2
    {43,  43,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//剑3
    {44,  44,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//剑4
    {45,  45,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//剑5
    {46,  46,  SI_SHOP, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//商店1
    {47,  47,  SI_SHOP, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//商店2
    {48,  171, SI_WALL, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//星星
    {49,  172, SI_WALL, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//熔岩
    {50,  50,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//杖1
    {51,  51,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},			//杖2
    {52,  52,  SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}},		//杖3
    {53, 53, SI_SECRET, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 机关
    {54, 54, SI_EXIT, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 入口
    {55, 55, SI_ENTRY, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 出口
    {56, 56, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 蓝血瓶
    {57, 57, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 红血瓶
    {58, 58, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 红宝石
    {59, 59, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 蓝宝石
    {60, 60, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 红钥匙
    {61, 61, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 蓝钥匙
    {62, 62, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 黄钥匙
    {63, 63, SI_SECRET, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 石门
    {64, 64, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 红门
    {65, 65, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 蓝门
    {66, 66, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 黄门
    {67, 67, SI_WALL, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 墙
    {68, 68, SI_FLOOR, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 地板
    {83, 84, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物1
    {85, 86, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物2
    {87, 88, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物3
    {89, 90, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物4
    {91, 92, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物5
    {93, 94, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物6
    {95, 96, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物7
    {97, 98, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物8
    {99, 100, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物9
    {101, 102, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物10
    {103, 104, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物11
    {105, 106, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物12
    {107, 108, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物13
    {109, 110, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物14
    {111, 112, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物15
    {113, 114, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物16
    {115, 116, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物17
    {117, 118, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物18
    {119, 120, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物19
    {121, 122, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物20
    {123, 124, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物21
    {125, 126, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物22
    {127, 127, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 金刚盾
    {128, 128, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 武器1
    {129, 129, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 武器2
    {130, 130, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 圣钥匙
    {131, 131, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 十字镖
    {132, 132, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 伏魔剑
    {133, 133, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 圣光杯
    {134, 134, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 十字架
    {135, 135, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 宝物梳1
    {136, 136, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 宝物梳2
    {137, 137, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 宝物梳3
    {138, 138, SI_NULL, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 主角
    {139, 140, SI_CELESTIAL, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 仙子
    {156, 156, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // NPC
    {157, 158, SI_SHOP, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 3层商店
    {159, 160, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // NPC
    {161, 162, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // NPC
    {163, 164, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // NPC
    {165, 166, SI_NPC, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // NPC
    {167, 168, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}, // 怪物
    {169, 170, SI_MONSTER, 1, {1, 1000, 10, 10, 0, 0, 1, 1, 1}}  // 怪物
};





QNpc::QNpc(QWidget *parent)
    : QWidget{parent}
{
    m_nTileIndex = 0;//初始化为 0 表示对象创建时，默认使用第一个图块。这意味着 CNpc 对象在创建时，默认显示第一帧或第一个状态。
    m_bShow = false;//默认不可见

    npcTimer = new QTimer(this);
    connect(npcTimer, &QTimer::timeout, this, &QNpc::npcOnTimer);
    //npcTimer->start(200); //测试成功，在Qscene中触发
}

//从一个文件中读取 NPC 信息，并将其存储到 NpcInfo 数组中
void QNpc::initNpc()
{
    QFile npcFile(NPC_FILE_NAME);
    if(npcFile.open(QIODeviceBase::ReadOnly))
    {
        qDebug()<<"NPC文件打开成功";
        int npcIndex = 0;
        while (npcIndex < MAX_NPC && !npcFile.atEnd()) {
            // 读取 NPCINFO 数据并写入到 NpcData 数组的 info 成员
            npcFile.read(reinterpret_cast<char*>(&NpcData[npcIndex].npcInfo), sizeof(NPCINFO));
            ++npcIndex;
        }
        qDebug()<<"文件基本成功完成读取";
        npcFile.close();
    }
    else
    {
        qDebug()<<"无法打开Npc文件";
    }
}

//根据提供的idTile 从 NpcData 数组中加载一个 NPC 的数据
void QNpc::load(IDTILE idTile)
{
    for(int i=0;i<MAX_NPC;i++)
    {
        //检查传入的 idTile 是否等于当前遍历的元素的任一 idTile
        if(idTile==NpcData[i].idTile[0]||idTile==NpcData[i].idTile[1])
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

void QNpc::load(QNpc &npc)
{
    for(int i=0;i<MAX_NPC_TILE;i++)
    {
        m_idTile[i] = npc.m_idTile[i];
    }
    m_nTileIndex = npc.m_nTileIndex;
    m_idScript = npc.m_idScript;
    m_bShow = npc.m_bShow;
}

//返回当前的图块 ID，如果 NPC 被隐藏，则返回地板图块 TILE_FLOOR
IDTILE QNpc::getTileID()
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
void QNpc::getNpcTile(IDTILE idTile[])
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
    qDebug()<<"触发了定时器，调用了onTimer函数";
    m_nTileIndex = (m_nTileIndex + 1) % MAX_NPC_TILE;
    qDebug()<<m_nTileIndex;
}


