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
#include <QPoint>
#include <QDataStream>
#include <QRect>
#include <QTimer>
#include <QKeyEvent>
#include <QWidget>
#include <QDebug>
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


    //数据序列化
    friend QDataStream &operator<<(QDataStream &out, const ROLEINFO &obj) {
        out<<obj.nLevel<<obj.nHealth<<obj.nAttack<<obj.nDefense<<obj.nMoney<<obj.nExperience<<obj.nRedKey<<obj.nBlueKey<<obj.nYellowKey;

        return out;
    }
    //数据反序列化
    friend QDataStream &operator>>(QDataStream &in, ROLEINFO &obj) {
        in>>obj.nLevel>>obj.nHealth>>obj.nAttack>>obj.nDefense>>obj.nMoney>>obj.nExperience>>obj.nRedKey>>obj.nBlueKey>>obj.nYellowKey;
        return in;
    }
};

class QRole : public QWidget
{
    Q_OBJECT
public:
    explicit QRole(QWidget *parent = nullptr);

    //类接口成员的访问器和修改器
    ROLEINFO getRoleInfo();//获取角色信息
    void SetRoleInfo(ROLEINFO Info);//设置角色信息
    QPoint getPos();//获取角色当前位置
    void setPos(QPoint ptPos, INDEX index, bool bTurn = false);//设置角色的位置、TILE ID 以及是否需要转向
    INDEX getRoleTileID();//获取角色的TILE ID
    bool isRoleTileID(IDTILE idTile);//检查给定的 idTile 是否在角色的图块 ID 列表中

    //信号处理函数
    void roleOnTimer();//定时器处理函数
    QPoint getNextPoint(QKeyEvent *event);//根据按键获取下一个角色的位置
    void moveTo(QPoint ptPos);//将角色移动到指定位置

    void startRoleTimer();
    void stopRoleTimer();

    //数据序列化
    friend QDataStream &operator<<(QDataStream &out, const QRole &obj) {
        out<<obj.m_ptPos<<obj.RoleInfo<<obj.m_nTileIndex;

        return out;
    }
    //数据反序列化
    friend QDataStream &operator>>(QDataStream &in, QRole &obj) {
        in>>obj.m_ptPos>>obj.RoleInfo>>obj.m_nTileIndex;
        return in;
    }
private:
    int getTileIndex(INDEX index);//获取给定TILE ID的索引（作为私有函数，只被类内部使用）

signals:

private:
    QPoint m_ptPos;//角色当前位置
    QRect m_rtWalk;//角色行走区域
    static INDEX idTiles[MAX_ROLE_TILE]; //用于存储角色 TILE ID 的数组
    ROLEINFO RoleInfo;//角色信息数据
    int m_nTileIndex;//当前角色 TILE 的索引

    QTimer *timer_role;
signals:
    void timerRole();
};



#endif // QROLE_H
