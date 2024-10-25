#include "maparea.h"
#include "ui_maparea.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
//#include <QPixmap>
MapArea::MapArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MapArea)
{
    ui->setupUi(this);
    this->mainMap=ui->map->rect();
    this->mapBorder=this->rect();
    void (MapArea:: *Layerupdated)(void)=&MapArea::updateMap;
    connect(this,Layerupdated,[=](void){
        ui->map->update();
    });
    // void (MapArea:: *SelectTileupdated)(int id)=&MapArea::updateSelectTile;
    // connect(this,SelectTileupdated,[=](int id){
    //     ui->map->setCurSelectTileID(id);
    // });
    // void (MapArea:: *SelectLayerupdated)(int value)=&MapArea::updateSelectLayer;
    // connect(this,SelectLayerupdated,[=](int value){
    //     ui->map->setCurLayer(value);
    //     ui->map->update();
    // });
}

MapArea::~MapArea()
{
    delete ui;
}

void MapArea::paintEvent(QPaintEvent *e)
{
    QPainter painter_border(this);
    QPen pen(Qt::black);
    pen.setWidth(3);
    painter_border.setPen(pen);
    painter_border.drawRect(this->mapBorder);

    painter_border.setPen(pen);
    painter_border.drawRect(this->mapBorder.adjusted(10,10,-10,-10));
    pen.setColor(Qt::white);
    pen.setWidth(8);
    painter_border.setPen(pen);
    painter_border.drawRect(this->mapBorder.adjusted(6,6,-6,-6));
    QWidget::paintEvent(e);
}


