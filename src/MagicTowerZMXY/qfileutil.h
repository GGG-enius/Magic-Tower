/**
* @file       QFileUtil.h
* @brief       游戏读档存档
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QFILEUTIL_H
#define QFILEUTIL_H

#include <QObject>
#include <QFile>
#include "qgame.h"
#include <QDataStream>
#include "Global.h"
/**
 * @brief The QFileUtil class 实现游戏读档存档功能
 */
class QFileUtil : public QObject
{
    Q_OBJECT
public:
    explicit QFileUtil(QObject *parent = nullptr);
    static void saveGame(const QGame &obj, const QString &fileName);
    static void loadGame(QGame &obj, const QString &fileName);
    // static void initTile(); // 初始化图块数据
    // static void initNpc();//用于初始化Npc数据
    // static void initMap();//  初始化地图数据
signals:
};

#endif // QFILEUTIL_H
