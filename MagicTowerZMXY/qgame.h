/**
* @file       QGame.h
* @brief       游戏类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QGAME_H
#define QGAME_H

#include <QObject>
#include "Global.h"
//Game State
/**
 * @enum GAMESTATE
 *
 * @brief 游戏状态枚举类型。
 *
 * @note  用于表示游戏的不同状态。
 */
enum GAMESTATE
{
    GS_INIT,///<初始化状态
    GS_WALK,///<行走状态
    GS_TALK,///<对话状态
    GS_FIGHT,///<战斗状态
    GS_OVER///<结束状态
};

class QGame : public QObject
{
    Q_OBJECT
public:
    explicit QGame(QObject *parent = nullptr);

signals:
};

#endif // QGAME_H
