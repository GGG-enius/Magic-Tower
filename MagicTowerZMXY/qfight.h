/**
* @file       QFight.h
* @brief       战斗类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QFIGHT_H
#define QFIGHT_H

#include <QObject>
#include "Global.h"
class QFight : public QObject
{
    Q_OBJECT
public:
    explicit QFight(QObject *parent = nullptr);

signals:
};

#endif // QFIGHT_H
