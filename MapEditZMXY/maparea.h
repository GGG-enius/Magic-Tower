#ifndef MAPAREA_H
#define MAPAREA_H
#include "TileButton.h"
#include <QWidget>
#include <QRect>
/**@name 地图属性
* @{
*/
#define MAP_LAYER            24            ///< 地图总层数
#define MAP_WIDTH            13            ///< 地图单位宽
#define MAP_HEIGHT           13            ///< 地图单位高
#define CURMAP_W             11            ///< 正式版地图宽
#define CURMAP_H             11            ///< 正式版地图高
#define TILE_WIDTH           32            ///< 图块像素宽
#define TILE_HEIGHT          32            ///< 图块像素高
/** @} */

namespace Ui {
class MapArea;
}

class MapArea : public QWidget
{
    Q_OBJECT

public:


    explicit MapArea(QWidget *parent = nullptr);
    ~MapArea();
    void paintEvent(QPaintEvent* e);

private:
    Ui::MapArea *ui;

    QRect mainMap;
    QRect mapBorder;
signals:
    void updateMap();
    // void updateSelectTile(int id);
    // void updateSelectLayer(int value);
};

#endif // MAPAREA_H
