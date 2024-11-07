#ifndef MAINMAP_H
#define MAINMAP_H
#include "maparea.h"
#include <QWidget>
#include <QRect>
// #include <QList>
#include <QString>
#include <QPoint>
// #include <QImage>
#include <QMouseEvent>
// #include <QKeyEvent>
#define TILE_FILE_NAME		"../../IOFile/Tile.bin"
#define MAP_FILE_NAME		"../../IOFile/Map.bin"
#define STAIR_FILE_NAME     "../../IOFile/Stair.bin"
class MainMap : public QWidget
{
    Q_OBJECT
public:
    static int curLayer;
    static int tileIDMapping[PIC_ABLE][4];
    static QString tileURL[TILE_IMAGE_TOTAL];
    //临时，后续改成宏定义
    static int mapBuf[MAP_LAYER][CURMAP_W][CURMAP_H];///<卧槽什么情况，这个成员变量直接把Qt干挂了?????!!!!!更加迷惑了突然又可以了，什么情况
    static QPoint stairEntryBuf[MAP_LAYER];
    static QPoint stairExitBuf[MAP_LAYER];
    explicit MainMap(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    // void keyPressEvent(QKeyEvent *e);
    // int getCurSelectTileID();
    // void setCurSelectTileID(int value);
    // int getCurLayer();
    // void setCurLayer(int value);
    // int getDefaultFloorID();
    // void setDefaultFloorID(int value);
    static bool readImageFile();
    static bool writeImageFile();
    static bool readMapFile();
    static bool writeMapFile();
    static bool readStairFile();
    static bool writeStairFile();
    // int tt=0;
private:
    // bool initMap=true;
    QRect curMapArea;
signals:
};

#endif // MAINMAP_H
