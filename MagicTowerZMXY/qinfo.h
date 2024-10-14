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
#include "Global.h"
class QInfo : public QObject
{
    Q_OBJECT
public:
    explicit QInfo(QObject *parent = nullptr);

signals:
};

#endif // QINFO_H
