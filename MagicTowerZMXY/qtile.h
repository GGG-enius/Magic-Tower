#ifndef TILE_H
#define TILE_H

#include "Global.h"
#include <QWidget>
class QTile:public QWidget
{
public:
    explicit QTile(QWidget *parent = nullptr);
    static void initTile(); // 初始化图块数据
    void draw(QPainter &painter, int x, int y, int idTile = 0); // 绘制图块
    // void drawEx(QPainter &painter, int x, int y, int idTile, int idRoleTile); // 绘制带有角色图块的图块

private:
    static QImage tileData[MAX_TILE]; // 存储图块数据的数组
    int offset;
};

#endif // TILE_H
