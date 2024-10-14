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
#include "Global.h"
/**
 * @brief The QFileUtil class 实现游戏读档存档功能
 */
class QFileUtil : public QObject
{
    Q_OBJECT
public:
    explicit QFileUtil(QObject *parent = nullptr);

signals:
};

#endif // QFILEUTIL_H
