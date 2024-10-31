/**
* @file        QNpc.h
* @brief      Npc类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QNPC_H
#define QNPC_H

#include <QObject>
#include "qrole.h"
#include "Global.h"
#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QTimer>
typedef ROLEINFO   NPCINFO;    //NPC与角色共有属性

/**
 * @struct NPCTILE
 *
 * @brief 定义一个结构体，用于存储NPC相关的信息，包括图块ID数组、脚本ID和显示状态,NPC属性。
 */
struct NPCTILE
{
    IDTILE idTile[MAX_NPC_TILE];    ///<一个最多包含MAX_NPC_TILE个图块ID的数组，用于标识与NPC相关的图块。即Npc的动画相关图块
    IDSCRIPT idScrpt;              ///<一个脚本ID，用于标识与NPC相关的脚本。
    bool bShow;                     ///<一个布尔值，用于标识NPC是否显示。
    NPCINFO npcInfo;                ///<NPC属性
};
class QNpc : public QWidget
{
    Q_OBJECT
public:
    explicit QNpc(QWidget *parent = nullptr);

    //类的初始化
    void initNpc();//用于初始化Npc数据
    void load(IDTILE idTile);//加载指定图块ID的Npc数据
    void load(QNpc &npc);//加载另一个QNpc对象的数据

    //访问函数
    IDTILE getTileID();//获取Npc的图块ID
    void getNpcTile(IDTILE idTile[MAX_NPC_TILE]);//将当前NPC实例的图块ID数组复制到指定的数组中
    NPCINFO getNpcInfo();//获取Npc属性信息
    IDSCRIPT getScriptID();//获取NPC脚本的ID
    void hide();//用于隐藏npc

    //定时器处理槽函数
    void npcOnTimer();
private:
    static NPCTILE NpcData[MAX_NPC];//存储所有 NPC 的图块信息
    IDTILE m_idTile[MAX_NPC_TILE];//存储当前Npc图块ID
    int m_nTileIndex;//当前Npc图块索引
    IDSCRIPT m_idScript;//当前Npc的脚本ID
    bool m_bShow;//用于记录Npc显示状态
    NPCINFO m_npcInfo;//当前Npc属性

    QTimer *npcTimer;
signals:
};

#endif // QNPC_H