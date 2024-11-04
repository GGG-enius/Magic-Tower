#include "qfileutil.h"
#include <QDebug>
#include <QFileInfo>
QFileUtil::QFileUtil(QObject *parent)
    : QObject{parent}
{}

void QFileUtil::saveGame(const QGame &obj, const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug()<<"file error";
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_5); // 确保版本兼容性
    out << obj;
    file.close();
}

void QFileUtil::loadGame(QGame &obj, const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"file error";
        return;
    }
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_6_5); // 确保版本兼容性
    in >> obj;
    file.close();
}















// //ZMXY版数据
// void QFileUtil::initTile()
// {
//     // qDebug()<<QDir::currentPath();
//     QFile tileFile(TILE_FILE_NAME);
//     if(!tileFile.open(QIODeviceBase::ReadOnly)){
//         qDebug()<<"file error";
//         return;
//     }
//     int i=0;
//     while(!tileFile.atEnd())
//     {
//         qint64 dataSize=0;
//         if(tileFile.read((char*)&dataSize,sizeof(dataSize))!=sizeof(dataSize))
//         {
//             break;
//         }
//         QByteArray byteArray;
//         byteArray.resize(dataSize);
//         if(tileFile.read(byteArray.data(),dataSize)!=dataSize)
//         {
//             break;
//         }
//         if(!QTile::tileData[i].loadFromData(byteArray,"PNG"))
//         {
//             break;
//         }
//         i++;
//     }
//     tileFile.close();

//     qDebug()<<"1";
// }



// //ZMXY版数据
// void QFileUtil::initNpc()
// {
//     // qDebug()<<QDir::currentPath();
//     QFile npcFile(NPC_FILE_NAME);
//     if(!npcFile.open(QIODeviceBase::ReadOnly)){
//         qDebug()<<"file error";
//         return;
//     }
//     QDataStream in(&npcFile);
//     in.setVersion(QDataStream::Qt_6_7);
//     quint32 size;
//     in>>size;//读取结构体数量
//     for(quint32 i=0;i<size;i++)
//     {
//         in>>(QNpc::NpcData[i].npcInfo.nLevel)
//         >>(QNpc::NpcData[i].npcInfo.nHealth)
//             >>(QNpc::NpcData[i].npcInfo.nAttack)
//             >>(QNpc::NpcData[i].npcInfo.nDefense)
//             >>(QNpc::NpcData[i].npcInfo.nMoney)
//             >>(QNpc::NpcData[i].npcInfo.nExperience)
//             >>(QNpc::NpcData[i].npcInfo.nRedKey)
//             >>(QNpc::NpcData[i].npcInfo.nBlueKey)
//             >>(QNpc::NpcData[i].npcInfo.nYellowKey);
//     }
//     npcFile.close();
//     qDebug()<<"2";
// }

// //ZMXY版读取地图数据
// void QFileUtil::initMap()
// {
//     QFile mapFile(MAP_FILE_NAME);
//     if(!mapFile.open(QIODeviceBase::ReadOnly)){
//         qDebug()<<"file error";
//         return;
//     }
//     QDataStream in(&mapFile);
//     in.setVersion(QDataStream::Qt_6_7);
//     int dim1,dim2,dim3;
//     in>>dim1>>dim2>>dim3;//读取维度信息
//     for(int i=0;i<dim1;i++)
//     {
//         for(int j=0;j<dim2;j++)
//         {
//             for(int k=0;k<dim3;k++)
//             {
//                 in>>QScene::TileData[i][j][k];
//             }
//         }
//     }
//     mapFile.close();
//     qDebug()<<"3";
// }











//原版数据
// void QFileUtil::initTile()
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
//         QTile::tileData[i] = QImage(TILE_WIDTH, TILE_HEIGHT, QImage::Format_RGB888);
//         if (QTile::tileData[i].isNull()) {
//             qWarning("Failed to create image.");
//             return;
//         }
//         //写入每个图块的颜色
//         for (int y = TILE_HEIGHT-1; y >= 0; --y) {
//             for (int x = TILE_WIDTH-1; x >=0 ; --x) {
//                 uchar b = static_cast<uchar>(fileData[offset++]);
//                 uchar g = static_cast<uchar>(fileData[offset++]);
//                 uchar r = static_cast<uchar>(fileData[offset++]);
//                 QTile::tileData[i].setPixel(x, y, qRgb(r, g, b));
//             }
//         }
//     }
// }
//原版数据
//从一个文件中读取 NPC 信息，并将其存储到 NpcInfo 数组中
// void QFileUtil::initNpc()
// {
//     QFile npcFile(NPC_FILE_NAME);
//     if(npcFile.open(QIODeviceBase::ReadOnly))
//     {
//         qDebug()<<"NPC文件打开成功";
//         int npcIndex = 0;
//         while (npcIndex < MAX_NPC && !npcFile.atEnd()) {
//             // 读取 NPCINFO 数据并写入到 NpcData 数组的 info 成员
//             npcFile.read(reinterpret_cast<char*>(&QNpc::NpcData[npcIndex].npcInfo), sizeof(NPCINFO));
//             ++npcIndex;
//         }
//         qDebug()<<"文件基本成功完成读取";
//         npcFile.close();
//     }
//     else
//     {
//         qDebug()<<"无法打开Npc文件";
//     }
// }

//原版数据  有待验证
// void QFileUtil::initMap()
// {
//     QFile mapFile(MAP_FILE_NAME);
//     if(!mapFile.open(QIODeviceBase::ReadOnly)){
//         qDebug()<<"file error";
//         return;
//     }
//     mapFile.Read(reinterpret_cast<char*>((&(&QScene::TileData)), MAX_SCENE * MAP_WIDTH * MAP_HEIGHT);
//     mapFile.Close();
// }




