/**
* @file         QBackGround.h
* @brief       背景类的头文件
* @author      ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QBACKGROUND_H
#define QBACKGROUND_H

#include <QObject>
#include "Global.h"
class QBackGround : public QObject
{
    Q_OBJECT
public:
    explicit QBackGround(QObject *parent = nullptr);

signals:
};

#endif // QBACKGROUND_H
