/**
* @file       QRole.h
* @brief       角色类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QROLE_H
#define QROLE_H

#include <QObject>
#include "Global.h"
/**
 * @struct ROLEINFO
 *
 * @brief 角色信息结构体,包含了角色的各项属性，如等级、生命值、攻击力、防御力、金币数、经验值以及各种钥匙的数量。
 */
struct ROLEINFO
{
    int nLevel;     ///<等级
    int nHealth;    ///<生命值
    int nAttack;    ///<攻击力
    int nDefense;   ///<防御力
    int nMoney;     ///<金币数
    int nExperience;///<经验值
    int nRedKey;    ///<红钥匙
    int nBlueKey;	///<蓝钥匙
    int nYellowKey;	///<黄钥匙
};

class QRole : public QObject
{
    Q_OBJECT
public:
    explicit QRole(QObject *parent = nullptr);

signals:
};

#endif // QROLE_H
