/**
* @file         QTalk.h
* @brief         Talk类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QTALK_H
#define QTALK_H

#include <QObject>
#include <QString>
#include "Global.h"
/**
 *  @struct TALK
 *
 *  @brief 定义一个结构体，用于存储对话相关的信息，包括NPC的ID、角色名称和对话句子。
 */
struct TALK
{
    IDTILE idTile[MAX_NPC_TILE];///<一个最多包含MAX_NPC_TILE个图块ID的数组，用于标识与对话相关的图块。
    QString npcName;			    ///<用于存储角色的名称
    QString npcSentence;	        ///<用于存储对话
};

class QTalk : public QObject
{
    Q_OBJECT
public:
    explicit QTalk(QObject *parent = nullptr);

signals:
};

#endif // QTALK_H
