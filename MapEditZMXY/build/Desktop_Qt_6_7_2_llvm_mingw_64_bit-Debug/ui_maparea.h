/********************************************************************************
** Form generated from reading UI file 'maparea.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPAREA_H
#define UI_MAPAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <mainmap.h>

QT_BEGIN_NAMESPACE

class Ui_MapArea
{
public:
    MainMap *map;

    void setupUi(QWidget *MapArea)
    {
        if (MapArea->objectName().isEmpty())
            MapArea->setObjectName("MapArea");
        MapArea->resize(440, 440);
        MapArea->setStyleSheet(QString::fromUtf8(""));
        map = new MainMap(MapArea);
        map->setObjectName("map");
        map->setGeometry(QRect(12, 12, 416, 416));
        map->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(MapArea);

        QMetaObject::connectSlotsByName(MapArea);
    } // setupUi

    void retranslateUi(QWidget *MapArea)
    {
        MapArea->setWindowTitle(QCoreApplication::translate("MapArea", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapArea: public Ui_MapArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPAREA_H
