#include "mainmap.h"


#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <cstring>
#include <QFile>

#include <QByteArray>
#include <QBuffer>

int MainMap::curLayer=0;
int MainMap::mapBuf[MAP_LAYER][CURMAP_W][CURMAP_H];
MainMap::MainMap(QWidget *parent)
    :QWidget(parent)
{
    memset(MainMap::mapBuf,18,sizeof(MainMap::mapBuf));
    this->setFixedSize(MAP_WIDTH*TILE_WIDTH,MAP_HEIGHT*TILE_HEIGHT);
    this->curMapArea=this->rect().adjusted(TILE_WIDTH,TILE_HEIGHT,-TILE_WIDTH,-TILE_HEIGHT);

    //测试!!!事关程序正常运行，一定要初始化变量
    // this->setCurLayer(0);
    // this->setCurSelectTileID(1);
    // this->setDefaultFloorID(1);
    // this->initMap=false;
}

void MainMap::paintEvent(QPaintEvent *e)
{
    QPainter painter_map(this);


    //painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);//测试


    //painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,pngPixmap);//测试

    QPixmap backgroundPixmap;
    QPixmap pngPixmap;
    painter_map.setCompositionMode(QPainter::CompositionMode_SourceAtop);//设置混合模式



    //测试动画
    // backgroundPixmap.load(":/Floor/Floor0002.png");
    // painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);
    // (this->tt)%=4;
    // pngPixmap.load(MainMap::tileURL[this->tt++]);
    // painter_map.drawPixmap(0,0,TILE_WIDTH,TILE_HEIGHT,pngPixmap);




    // if(this->initMap)
    // {
    //     for(int i=0;i<13;i++)
    //     {
    //         for(int j=0;j<13;j++)
    //         {
    //             backgroundPixmap.load(":/Floor/Floor0002.png");
    //             painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);

    //         }
    //     }
    // }
    // else
    // {
    // qDebug()<<this->getCurLayer();
        for(int i=0;i<MAP_HEIGHT;i++)
        {
            for(int j=0;j<MAP_WIDTH;j++)
            {
                if(i==0||j==0||i==(MAP_HEIGHT-1)||j==(MAP_WIDTH-1))
                {
                    backgroundPixmap.load(TileButton::tileURL[11]);
                    painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);
                    if(i==0&&j==0)
                    {
                        pngPixmap.load(":/Image/NPC/WuJing.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }else if(i==0&&j==(MAP_WIDTH-1))
                    {
                        pngPixmap.load(":/Image/NPC/XuanZang.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }else if(i==(MAP_HEIGHT-1)&&j==0)
                    {
                        pngPixmap.load(":/Image/NPC/WuKong.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }else if(i==(MAP_HEIGHT-1)&&j==(MAP_WIDTH-1))
                    {
                        pngPixmap.load(":/Image/NPC/WuNeng.png");
                        painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                    }
                }
                else
                {
                    int index=MainMap::mapBuf[MainMap::curLayer][j-1][i-1];
                    //QString url=MapArea::tileURL[index];//???
                    QString url=TileButton::tileURL[index];

                    // backgroundPixmap.load(url);
                    backgroundPixmap.load(":/Image/Floor/Floor0002.png");
                    painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,backgroundPixmap);
                    pngPixmap.load(url);
                    // // pngPixmap.load(":/Guard/GuardBow0001.png");

                    painter_map.drawPixmap(i*TILE_WIDTH,j*TILE_HEIGHT,TILE_WIDTH,TILE_HEIGHT,pngPixmap);
                }
            }
        }
    //}
    QWidget::paintEvent(e);
}

void MainMap::mousePressEvent(QMouseEvent *e)
{
    if(this->curMapArea.contains(e->pos()))
    {
        int x=(e->pos().x()-this->curMapArea.topLeft().x())/TILE_WIDTH;
        int y=(e->pos().y()-this->curMapArea.topLeft().y())/TILE_HEIGHT;
        if(e->button()==Qt::LeftButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::curSelectTileID;
            // qDebug()<<"layer: "<<MainMap::curLayer;
            // qDebug()<<"id:    "<<TileButton::curSelectTileID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        else if(e->button()==Qt::RightButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::defaultFloorID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        // qDebug()<<"层:"<<this->getCurLayer();
        // qDebug()<<"坐标:"<<x<<","<<y;
    }
    else
    {
        // qDebug()<<"出界";
    }
    this->update();
    return QWidget::mousePressEvent(e);
}

void MainMap::mouseMoveEvent(QMouseEvent *e)
{
    if(this->curMapArea.contains(e->pos()))
    {
        int x=(e->pos().x()-this->curMapArea.topLeft().x())/TILE_WIDTH;
        int y=(e->pos().y()-this->curMapArea.topLeft().y())/TILE_HEIGHT;
        if(e->buttons() & Qt::LeftButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::curSelectTileID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        else if(e->buttons() & Qt::RightButton)
        {
            this->mapBuf[MainMap::curLayer][y][x]=TileButton::defaultFloorID;
            // qDebug()<<mapBuf[this->getCurLayer()][y][x];
        }
        //qDebug()<<"层:"<<this->getCurLayer();
        // qDebug()<<"坐标:"<<x<<","<<y;
    }
    else
    {
        // qDebug()<<"出界";
    }
    this->update();
    return QWidget::mouseMoveEvent(e);
}


//让顶层去实现
// void MainMap::keyPressEvent(QKeyEvent *e)
// {
//     // if(e->key()==Qt::Key_S)
//     // {
//     //     qDebug()<<"Save";
//     // }
//     QWidget::keyPressEvent(e);
// }

// int MainMap::getCurSelectTileID()
// {
//     return this->curSelectTileID;
// }

// void MainMap::setCurSelectTileID(int value)
// {
//     this->curSelectTileID=value;
// }

// int MainMap::getCurLayer()
// {
//     return this->curLayer;
// }

// void MainMap::setCurLayer(int value)
// {
//     this->curLayer=value;
// }

// int MainMap::getDefaultFloorID()
// {
//     return this->defaultFloorID;
// }

// void MainMap::setDefaultFloorID(int value)
// {
//     this->defaultFloorID=value;
// }

bool MainMap::readImageFile()
{
    // qDebug()<<QDir::currentPath();
    QFile tileFile(TILE_FILE_NAME);
    if(!tileFile.open(QIODeviceBase::ReadOnly)){
        return false;
    }
    int i=0;
    while(!tileFile.atEnd())
    {
        qint64 dataSize=0;
        if(tileFile.read((char*)&dataSize,sizeof(dataSize))!=sizeof(dataSize))
        {
            break;
        }
        QByteArray byteArray;
        byteArray.resize(dataSize);
        if(tileFile.read(byteArray.data(),dataSize)!=dataSize)
        {
            break;
        }
        if(!TileButton::tilePNG[i].loadFromData(byteArray,"PNG"))
        {
            break;
        }
        i++;
    }
    tileFile.close();
    return true;
}


bool MainMap::writeImageFile()
{
    QFile tileFile("../../IOFile/Tile.bin");
    if(!tileFile.open(QIODeviceBase::WriteOnly)){
        qDebug()<<tileFile.errorString();
        return false;
    }

    for(int i=0;i<PIC_ABLE;i++)
    {
        QImage image(TileButton::tileURL[i]);
        if(image.isNull())
        {
            qDebug()<<"failed to load png image"<<TileButton::tileURL[i];
            continue;
        }
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        if(!image.save(&buffer,"PNG"))
        {
            qDebug()<<"failed to save image to binary"<<TileButton::tileURL[i];
            continue;
        }

        qint64 dataSize=byteArray.size();
        tileFile.write((const char* )&dataSize,sizeof(dataSize));
        tileFile.write(byteArray);
    }

    tileFile.close();
    return true;
}

bool MainMap::readMapFile()
{
    // qDebug()<<QDir::currentPath();
    QFile mapFile(MAP_FILE_NAME);
    if(!mapFile.open(QIODeviceBase::ReadOnly)){
        return false;
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
                in>>MainMap::mapBuf[i][j][k];
            }
        }
    }
    mapFile.close();
    return true;
}

bool MainMap::writeMapFile()
{
    QFile mapFile("../../IOFile/Map.bin");
    if(!mapFile.open(QIODeviceBase::WriteOnly)){
        qDebug()<<mapFile.errorString();
        return false;
    }
    // qDebug()<<"empty";
    QDataStream out(&mapFile);
    out.setVersion(QDataStream::Qt_6_7);
    out << MAP_LAYER<<CURMAP_W<<CURMAP_H;//写入维度信息

    for(int i=0;i<MAP_LAYER;i++)
    {
        for(int j=0;j<CURMAP_H;j++)
        {
            for(int k=0;k<CURMAP_W;k++)
            {
                out<<MainMap::mapBuf[i][j][k];
            }
        }
    }
    mapFile.close();
    return true;
}


