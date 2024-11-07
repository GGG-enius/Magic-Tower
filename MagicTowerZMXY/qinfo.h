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

    void paintEvent(QPaintEvent *event)override;

    void onDraw(QPainter &painter, const QRect &rect, const ROLEINFO &roleInfo, const QString &sceneName);
    // ROLEINFO getRoleInfo() const;

    void setRoleInfo(const ROLEINFO &newRoleInfo);

    void setSceneName(const QString &newSceneName);

    void setActive(bool value);

    friend QDataStream &operator<<(QDataStream &out, const QInfo &obj) {
        out << obj.isActive;
        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, QInfo &obj) {
        in >> obj.isActive;
        return in;
    }
private:
    QTile * tile;
    QColor borderColor;
    int borderWidth;
    QRect InfoRect;
    QRect MainRect;

    ROLEINFO roleInfo;
    QString sceneName;
    bool isActive;
signals:
    void infoUpdated(ROLEINFO info,QString name);
};



#endif // QINFO_H
