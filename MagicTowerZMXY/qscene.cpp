#include "qscene.h"
#include <QPainter>
IDTILE QScene::TileData[MAX_SCENE][MAP_WIDTH][MAP_HEIGHT];
QScene::QScene(QWidget *parent)
    : QWidget{parent}
{
    this->m_idScene = 0;
    this->m_idLayerDone = 0;
    memset(roleEntryPos, 0, sizeof(roleExitPos));
    memset(roleExitPos, 0, sizeof(roleExitPos));
    memset(roleEntryTile, TILE_ROLE_ENTRY, sizeof(roleExitTile));
    memset(roleExitTile, TILE_ROLE_EXIT, sizeof(roleExitTile));


    for(int i = 0; i < MAX_SCENE; i++)
    {
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            for(int k = 0; k < MAP_HEIGHT; k++)
            {
                if(role.isRoleTileID(TileData[i][j][k]))		//判断是否是主角
                {												//是则设置相应入口信息
                    roleEntryPos[i] = QPoint(j, k);
                    roleEntryTile[i] = TileData[i][j][k];
                    npc[i][j][k].load(TILE_FLOOR);				//相应位置补充地板ID, Ps:正因地板ID唯一, 所以游戏未采用分层结构
                }
                else
                {
                    npc[i][j][k].load(TileData[i][j][k]);		//相应位置载入相应NPC
                }
            }
        }
    }

    //交给QGame启动定时器
    this->sceneTimer = new QTimer(this);
    connect(this->sceneTimer, &QTimer::timeout, this, [=](){
        for(int i = 0; i < MAP_WIDTH; i++)
        {
            for(int j = 0; j < MAP_HEIGHT; j++)
            {
                npc[this->m_idScene][i][j].startNpcTimer();
            }
        }
        role.startRoleTimer();
    });
}

void QScene::load(IDSCENE sceneID)
{
    this->m_idScene=sceneID;
    role.setPos(roleEntryPos[this->m_idScene],roleEntryTile[this->m_idScene]);
}

void QScene::backward()
{
    roleEntryPos[this->m_idScene]=role.getPos();
    roleEntryTile[this->m_idScene]=role.getRoleTileID();
    (this->m_idScene-1<0)?1:this->m_idScene--;
    role.setPos(roleExitPos[this->m_idScene],roleExitTile[this->m_idScene]);
}

void QScene::forward()
{
    roleExitPos[this->m_idScene]=role.getPos();
    roleExitTile[this->m_idScene]=role.getRoleTileID();
    (this->m_idScene+1>23)?1:this->m_idScene++;
    if(this->m_idScene>this->m_idLayerDone)
    {
        this->m_idLayerDone=this->m_idScene;
        role.setPos(roleEntryPos[this->m_idScene],roleEntryTile[this->m_idScene]);
    }
    else
    {
        role.setPos(roleEntryPos[this->m_idScene],roleEntryTile[this->m_idScene],true);
    }
}

QPoint QScene::getRoleNextPoint(int key)
{
    return role.getNextPoint(key);
}

IDSCENE QScene::getSceneID()
{
    return this->m_idScene;
}

QString QScene::getSceneName()
{

    if(this->m_idScene==0)
    {
        this->sceneName=QString("序   章");
    }
    else
    {
        this->sceneName=QString("第 %1 层").arg(this->m_idScene);
    }
    return this->sceneName;
}

IDTILE QScene::getRoleTileID()
{
    return role.getRoleTileID();
}

QPoint QScene::getRolePos()
{
    return role.getPos();
}

ROLEINFO QScene::getRoleInfo()
{
    return role.getRoleInfo();
}

void QScene::getNpcTile(QPoint curPos, IDTILE idTile[], NPCINFO *npcInfo)
{
    npc[this->m_idScene][curPos.x()][curPos.y()].getNpcTile(idTile);
    *npcInfo=npc[this->m_idScene][curPos.x()][curPos.y()].getNpcInfo();
}



NPCINFO QScene::getNpcInfo(QPoint curPos)
{
    return npc[this->m_idScene][curPos.x()][curPos.y()].getNpcInfo();
}

IDSCRIPT QScene::getScriptID(QPoint curPos)
{
    return npc[this->m_idScene][curPos.x()][curPos.y()].getScriptID();
}

void QScene::setRolePos(QPoint nextPos)
{
    role.moveTo(nextPos);
}

void QScene::setRoleInfo(ROLEINFO roleInfo)
{
    role.SetRoleInfo(roleInfo);
}

void QScene::setNpcPos(QPoint curPos, QPoint newPos)
{
    if(curPos!=newPos)
    {
        npc[this->m_idScene][newPos.x()][newPos.y()].load(npc[this->m_idScene][curPos.x()][curPos.y()]);
        npc[this->m_idScene][curPos.x()][curPos.y()].load(TILE_FLOOR);
    }
}

void QScene::hideNpc(QPoint pos)
{
    npc[this->m_idScene][pos.x()][pos.y()].hide();
}

void QScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i = 0; i < MAP_WIDTH; i++)
    {
        for(int j = 0; j < MAP_HEIGHT; j++)
        {
            this->tile.draw(painter, i * TILE_WIDTH, j * TILE_HEIGHT, npc[this->m_idScene][i][j].getTileID());
        }
    }

    QPoint curPos=role.getPos();
    IDTILE roleTile=role.getRoleTileID();
    this->tile.draw(painter,curPos.x()*TILE_WIDTH,curPos.y()*TILE_HEIGHT,roleTile);
    QWidget::paintEvent(event);
}

void QScene::startSceneTimer()
{
    this->sceneTimer->start();
}

void QScene::stopSceneTimer()
{
    this->sceneTimer->stop();
}


//ZMXY版读取地图数据
void QScene::initMap()
{
    QFile mapFile(MAP_FILE_NAME);
    if(!mapFile.open(QIODeviceBase::ReadOnly)){
        qDebug()<<"file error";
        return;
    }
    QDataStream in(&mapFile);
    in.setVersion(QDataStream::Qt_6_7);
    int dim1,dim2,dim3;
    in>>dim1>>dim2>>dim3;//读取维度信息
    for(int i=0;i<dim1;i++)
    {
        for(int j=0;j<dim2;j++)
        {
            for(int k=0;k<dim3;k++)
            {
                in>>QScene::TileData[i][j][k];
            }
        }
    }
    mapFile.close();
    // qDebug()<<"3";
}
// void QScene::timerEvent(QTimerEvent *event)
// {

// }
