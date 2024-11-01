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
#include <QString>
#include <QWidget>
#include <QTimer>
#include <QDataStream>
#include "Global.h"
#include "qnpc.h"
#include "qtile.h"
class QScene : public QWidget
{
    Q_OBJECT
public:
    explicit QScene(QWidget *parent = nullptr);
    //Data Cache所有NPC的数据缓冲
    static IDTILE TileData[MAX_SCENE][MAP_WIDTH][MAP_HEIGHT];
    void load(IDSCENE sceneID);
    void backward();
    void forward();
    QPoint getRoleNextPoint(int key);
    IDSCENE getSceneID();
    QString getSceneName();
    IDTILE getRoleTileID();
    QPoint getRolePos();
    ROLEINFO getRoleInfo();
    void getNpcTile(QPoint curPos,IDTILE idTile[MAX_NPC_TILE],NPCINFO* npcInfo);
    NPCINFO getNpcInfo(QPoint curPos);
    IDSCRIPT getScriptID(QPoint curPos);
    void setRolePos(QPoint nextPos);
    void setRoleInfo(ROLEINFO roleInfo);
    void setNpcPos(QPoint curPos, QPoint newPos);
    void hideNpc(QPoint pos);
    void paintEvent(QPaintEvent *event);//绘画事件
    // void timerEvent(QTimerEvent *event);//定时器事件
    //数据序列化
    friend QDataStream &operator<<(QDataStream &out, const QScene &obj) {
        out<<MAX_SCENE<<MAP_WIDTH<<MAP_HEIGHT;
        // 序列化NestedClass的成员
        for(int i = 0; i < MAX_SCENE; i++)
        {
            for(int j = 0; j < MAP_WIDTH; j++)
            {
                for(int k = 0; k < MAP_HEIGHT; k++)
                {
                    out << obj.npc[i][j][k];
                }
            }
        }
        out<<obj.m_idScene<<obj.m_idLayerDone<<MAX_SCENE;
        for(int i=0;i<MAX_SCENE;i++)
        {
            out<<obj.roleEntryPos[i]<<obj.roleExitPos[i]<<obj.roleEntryTile[i]<<obj.roleExitTile[i];
        }
        out<<obj.role;
        return out;
    }
    //数据反序列化
    friend QDataStream &operator>>(QDataStream &in, QScene &obj) {
        int dim1,dim2,dim3,sceneSize;
        in>>dim1>>dim2>>dim3;
        for(int i=0;i<dim1;i++)
        {
            for(int j=0;j<dim2;j++)
            {
                for(int k=0;k<dim3;k++)
                {
                    in >> obj.npc[i][j][k];
                }
            }
        }
        in>>obj.m_idScene>>obj.m_idLayerDone>>sceneSize;
        for(int i=0;i<sceneSize;i++)
        {
            in>>obj.roleEntryPos[i]>>obj.roleExitPos[i]>>obj.roleEntryTile[i]>>obj.roleExitTile[i];
        }
        in>>obj.role;
        return in;
    }
    void startSceneTimer();
    void stopSceneTimer();
    static void initMap();//  初始化地图数据
private:
    QString sceneName;
    IDSCENE m_idScene;
    IDSCENE m_idLayerDone;
    QTile tile;
    QNpc npc[MAX_SCENE][MAP_WIDTH][MAP_HEIGHT];
    QRole role;
    QPoint roleEntryPos[MAX_SCENE];
    QPoint roleExitPos[MAX_SCENE];
    IDTILE roleEntryTile[MAX_SCENE];
    IDTILE roleExitTile[MAX_SCENE];
    QTimer* sceneTimer;
signals:
};

#endif // QSCENE_H
