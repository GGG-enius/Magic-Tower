#include <QImage>
#include <QPainter>
#include <QFile>
#include <QDataStream>
#include "qtile.h"
#include <QDebug>
#include <QFileInfo>

QImage QTile::tileData[MAX_TILE];


QTile::QTile(QWidget *parent)
    : QWidget{parent}
{

}


//ZMXY版数据
void QTile::initTile()
{
    // qDebug()<<QDir::currentPath();
    QFile tileFile(TILE_FILE_NAME);
    if(!tileFile.open(QIODeviceBase::ReadOnly)){
        //检查文件是否存在
        if (!QFileInfo::exists(TILE_FILE_NAME)) {
            qWarning() << "文件不存在。";
        }
        // 检查文件是否可读
        else if (!QFileInfo(TILE_FILE_NAME).isReadable()) {
            qWarning() << "文件不可读，请检查文件权限。";
        }
        // 其他错误
        else {
            qWarning() << "打开文件时出现其他错误。";
        }
        return;
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
        if(!QTile::tileData[i].loadFromData(byteArray,"PNG"))
        {
            break;
        }
        i++;
    }
    tileFile.close();

    // qDebug()<<"1";
}




void QTile::draw(QPainter &painter, int x, int y, INDEX idTile) {
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
    if (idTile >= 0 && idTile < MAX_TILE) {
        painter.drawImage(x, y, tileData[idTile].scaled(TILE_WIDTH,TILE_HEIGHT,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        //painter.drawImage(x, y, QImage(":/pictruetest.png"));
    }
    else{
        qWarning()<<"TILE index out of range";
    }
}


//原版数据
// void QTile::initTile()
// {
//     //test
//     QFile imageFile(TILE_FILE_NAME);
//     if (!imageFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         qWarning() << "无法打开文件:" << TILE_FILE_NAME << "错误信息：" << imageFile.errorString();

//         // 检查文件是否存在
//         if (!QFileInfo::exists(TILE_FILE_NAME)) {
//             qWarning() << "文件不存在。";
//         }
//         // 检查文件是否可读
//         else if (!QFileInfo(TILE_FILE_NAME).isReadable()) {
//             qWarning() << "文件不可读，请检查文件权限。";
//         }
//         // 其他错误
//         else {
//             qWarning() << "打开文件时出现其他错误。";
//         }
//         return;
//     }
//     qWarning("Tile.txt打开成功");
//     // 读取文件数据
//     QByteArray fileData = imageFile.readAll();
//     imageFile.close();

//     // 解析文件数据并存储到TileData中
//     int offset = 0;
//     for (int i = 0; i < MAX_TILE; ++i) {
//         tileData[i] = QImage(TILE_WIDTH, TILE_HEIGHT, QImage::Format_RGB888);
//         if (tileData[i].isNull()) {
//             qWarning("Failed to create image.");
//             return;
//         }
//         //写入每个图块的颜色
//         for (int y = TILE_HEIGHT-1; y >= 0; --y) {
//             for (int x = TILE_WIDTH-1; x >=0 ; --x) {
//                 uchar b = static_cast<uchar>(fileData[offset++]);
//                 uchar g = static_cast<uchar>(fileData[offset++]);
//                 uchar r = static_cast<uchar>(fileData[offset++]);
//                 tileData[i].setPixel(x, y, qRgb(r, g, b));
//             }
//         }
//     }
// }


// void QTile::drawEx(QPainter &painter, int x, int y, int idTile, int idRoleTile) {

//     if (idTile >= 0 && idTile < MAX_TILE && idRoleTile >= 0 && idRoleTile < MAX_TILE) {
//         QImage roleTileData = tileData[idRoleTile].convertToFormat(QImage::Format_ARGB32);
//         QImage tile = tileData[idTile].convertToFormat(QImage::Format_ARGB32);

//         for (int i = 0; i < TILE_HEIGHT; ++i) {
//             for (int j = 0; j < TILE_WIDTH; ++j) {
//                 QColor roleColor = roleTileData.pixelColor(j, i);
//                 if (roleColor.alpha() != 0) { // Assuming alpha 0 is the transparent color
//                     tile.setPixelColor(j, i, roleColor);
//                 }
//             }
//         }
//         painter.drawImage(x, y, tile);
//     }
// }
