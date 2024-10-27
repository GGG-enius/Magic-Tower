/**
* @file       QInfo.h
* @brief        信息类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QINFO_H
#define QINFO_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QString>
#include "Global.h"
#include "qtile.h"
#include "qrole.h"
class QInfo : public QWidget
{
    Q_OBJECT
public:
    QInfo();
    virtual ~QInfo();
    explicit QInfo(QWidget *parent = nullptr);
    void drawBorder(QPainter &painter, const QRect &rect);
    void onDraw(QPainter &painter, const QRect &rect, const ROLEINFO &roleInfo, const QString &sceneName);
private:
    QTile * tile;
    QColor borderColor;
    int borderWidth;
signals:
};



#endif // QINFO_H
