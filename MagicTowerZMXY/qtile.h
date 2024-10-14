/**
* @file           QTile.h
* @brief          Tile类的头文件
* @author      ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QTILE_H
#define QTILE_H

#include <QObject>
#include "Global.h"
class QTile : public QObject
{
    Q_OBJECT
public:
    explicit QTile(QObject *parent = nullptr);

signals:
};

#endif // QTILE_H
