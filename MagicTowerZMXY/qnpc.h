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
typedef ROLEINFO		NPCINFO;    //NPC与角色共有属性

/**
 * @struct NPCTILE
 *
 * @brief 定义一个结构体，用于存储NPC相关的信息，包括图块ID数组、脚本ID和显示状态,NPC属性。
 */
struct NPCTILE
{
    IDTILE idTile[MAX_NPC_TILE];    ///<一个最多包含MAX_NPC_TILE个图块ID的数组，用于标识与NPC相关的图块。即Npc的动画相关图块
    IDSCRIPT idScript;              ///<一个脚本ID，用于标识与NPC相关的脚本。
    bool bShow;                     ///<一个布尔值，用于标识NPC是否显示。
    NPCINFO npcInfo;                ///<NPC属性
};
class QNpc : public QObject
{
    Q_OBJECT
public:
    explicit QNpc(QObject *parent = nullptr);

signals:
};

#endif // QNPC_H
