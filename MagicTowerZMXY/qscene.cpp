#include "qscene.h"
#include <QPainter>
IDTILE QScene::TileData[MAX_SCENE][MAP_WIDTH][MAP_HEIGHT];
QScene::QScene(QWidget *parent)
    : QWidget{parent}
{
    //控制原生窗口大小位置
    this->setFixedSize(MAP_WIDTH*TILE_WIDTH,MAP_HEIGHT*TILE_WIDTH);
    this->setGeometry(QRect(250, 50, MAP_WIDTH * TILE_WIDTH, MAP_HEIGHT * TILE_WIDTH));

    this->isActive=false;
    this->Sound = new QSoundEffect(this);
    tile=new QTile(this);

    connect(this, &QScene::startAnimation, this, [=](){
        this->isActive=true;

        for(int i = 0; i < MAP_HEIGHT; i++)
        {
            for(int j = 0; j < MAP_WIDTH; j++)
            {
                if(npc[this->m_idScene][i][j].isAutoAnimation())
                {
                    npc[this->m_idScene][i][j].startNpcTimer();
                }
            }
        }
        role.startRoleTimer();
    });
    connect(this,&QScene::stopAnimation,[=](){
        this->isActive=false;
        //this->hide();
    });
}

void QScene::load(IDSCENE sceneID)
{
    this->m_idScene=sceneID;
    role.setPos(roleEntryPos[this->m_idScene],roleEntryTile[this->m_idScene]);
}

void QScene::initScene()
{
    this->m_idScene = 0;
    this->m_idLayerDone = 0;
    memset(roleEntryPos, 0, sizeof(roleExitPos));
    memset(roleExitPos, 0, sizeof(roleExitPos));

    this->readStairFile();
    memset(roleEntryTile, TILE_ROLE_ENTRY, sizeof(roleExitTile));
    memset(roleExitTile, TILE_ROLE_EXIT, sizeof(roleExitTile));


    for(int i = 0; i < MAX_SCENE; i++)
    {
        for(int j = 0; j < MAP_HEIGHT; j++)
        {
            for(int k = 0; k < MAP_WIDTH; k++)
            {
                if(role.isRoleTileID(TileData[i][j][k]))		//判断是否是主角
                {												//是则设置相应入口信息
                    roleEntryPos[i] = QPoint(k, j);
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
}

void QScene::backward()
{
    //roleEntryPos[this->m_idScene]=role.getPos();
    roleEntryTile[this->m_idScene]=role.getRoleTileID();
    (this->m_idScene-1<0)?1:this->m_idScene--;
    role.setPos(roleExitPos[this->m_idScene],roleExitTile[this->m_idScene]);
    emit layerChanged("下了一层楼");
}

void QScene::forward()
{
    //roleExitPos[this->m_idScene]=role.getPos();
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
    emit layerChanged("上了一层楼");
}

QPoint QScene::getRoleNextPoint(QKeyEvent *event)
{
    return role.getNextPoint(event);
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

INDEX QScene::getRoleTileID()
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

void QScene::getNpcTile(QPoint curPos, INDEX idTile[])
{
    npc[this->m_idScene][curPos.y()][curPos.x()].getNpcTile(idTile);
    // *npcInfo=npc[this->m_idScene][curPos.y()][curPos.x()].getNpcInfo();
}



NPCINFO QScene::getNpcInfo(QPoint curPos)
{
    return npc[this->m_idScene][curPos.y()][curPos.x()].getNpcInfo();
}

IDSCRIPT QScene::getScriptID(QPoint curPos)
{
    return npc[this->m_idScene][curPos.y()][curPos.x()].getScriptID();
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
        npc[this->m_idScene][newPos.y()][newPos.x()].load(npc[this->m_idScene][curPos.y()][curPos.x()]);
        npc[this->m_idScene][curPos.y()][curPos.x()].load(TILE_FLOOR);
        if(!npc[this->m_idScene][newPos.y()][newPos.x()].isNpcTimerActive())
        {
            // qDebug()<<"active";
            npc[this->m_idScene][newPos.y()][newPos.x()].startNpcTimer();
        }
    }
}

void QScene::hideNpc(QPoint pos)
{
    npc[this->m_idScene][pos.y()][pos.x()].hide();
}

void QScene::paintEvent(QPaintEvent *event)
{
    if(this->isActive)
    {
        QPainter painter(this);

        for(int i = 0; i < MAP_HEIGHT; i++)
        {
            for(int j = 0; j <MAP_WIDTH ; j++)
            {
                this->tile->draw(painter, j * TILE_WIDTH, i * TILE_HEIGHT, npc[this->m_idScene][i][j].getTileID());
            }
        }

        QPoint curPos=role.getPos();
        INDEX roleTile=role.getRoleTileID();
        this->tile->draw(painter,curPos.x()*TILE_WIDTH,curPos.y()*TILE_HEIGHT,roleTile);

        QWidget::paintEvent(event);
    }
    QWidget::paintEvent(event);
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
    in.setVersion(QDataStream::Qt_6_5);
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

void QScene::startPtPosAnimation(int layer, int y, int x)
{
    connect(&npc[layer][y][x],&QNpc::stopDoorAnimation,[=]()
    {
        this->hideNpc(QPoint(x,y));
        emit this->stopDoorAnimation();
        this->Sound->stop();
    });

    npc[layer][y][x].setDoorFlag();
    this->Sound->setSource(QUrl::fromLocalFile(SOUND_DOOR_FILE));
    this->Sound->play();
    npc[layer][y][x].startNpcTimer();

}

void QScene::readStairFile()
{
    QFile stairFile(STAIR_FILE_NAME);
    if(!stairFile.open(QIODeviceBase::ReadOnly)){
        qDebug()<<"file error";
    }
    QDataStream in(&stairFile);
    in.setVersion(QDataStream::Qt_6_7);
    int layer;
    in>>layer;//读取维度信息
    for(int i=0;i<layer;i++)
    {
        in>>this->roleEntryPos[i];
        in>>this->roleExitPos[i];
    }
    stairFile.close();
}
