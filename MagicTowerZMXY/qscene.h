/**
* @file        QScene.h
* @brief       场景类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QSCENE_H
#define QSCENE_H

#include <QObject>
#include "Global.h"
class QScene : public QObject
{
    Q_OBJECT
public:
    explicit QScene(QObject *parent = nullptr);

signals:
};

#endif // QSCENE_H
