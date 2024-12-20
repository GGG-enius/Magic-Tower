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

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include "Global.h"
#include <QDataStream>
#include "qtile.h"

class QBackGround : public QWidget
{
    Q_OBJECT
public:
    explicit QBackGround(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event)override ;

    void setActive(bool value);//槽函数，触发背景绘图

    friend QDataStream &operator<<(QDataStream &out, const QBackGround &obj) {
        out << obj.isActive;
        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, QBackGround &obj) {
        in >> obj.isActive;
        return in;
    }
private:
    QTile *tile;
    bool isActive;//背景活动状态标志
};

#endif // QBACKGROUND_H
