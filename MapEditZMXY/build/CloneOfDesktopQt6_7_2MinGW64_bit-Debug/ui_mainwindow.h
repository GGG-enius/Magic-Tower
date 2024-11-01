/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <infoedit.h>
#include <maparea.h>
#include <qselectarea.h>
#include <qselectbutton.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *LayerFrame;
    QWidget *layoutWidget;
    QVBoxLayout *LayerGroups;
    QHBoxLayout *LayerGroup1;
    QSelectButton *layer0;
    QSelectButton *layer1;
    QSelectButton *layer2;
    QSelectButton *layer3;
    QSelectButton *layer4;
    QSelectButton *layer5;
    QHBoxLayout *LayerGroup2;
    QSelectButton *layer6;
    QSelectButton *layer7;
    QSelectButton *layer8;
    QSelectButton *layer9;
    QSelectButton *layer10;
    QSelectButton *layer11;
    QHBoxLayout *LayerGroup3;
    QSelectButton *layer12;
    QSelectButton *layer13;
    QSelectButton *layer14;
    QSelectButton *layer15;
    QSelectButton *layer16;
    QSelectButton *layer17;
    QHBoxLayout *LayerGroup4;
    QSelectButton *layer18;
    QSelectButton *layer19;
    QSelectButton *layer20;
    QSelectButton *layer21;
    QSelectButton *layer22;
    QSelectButton *layer23;
    QWidget *LayerBG;
    QSelectArea *TileArea;
    MapArea *Map;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Infos;
    InfoEdit *Info01;
    InfoEdit *Info02;
    InfoEdit *Info03;
    InfoEdit *Info04;
    InfoEdit *Info05;
    InfoEdit *Info06;
    InfoEdit *Info07;
    InfoEdit *Info08;
    InfoEdit *Info09;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1110, 800);
        MainWindow->setMinimumSize(QSize(1110, 800));
        MainWindow->setMaximumSize(QSize(1110, 800));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Icon/Icon0001.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        LayerFrame = new QWidget(centralwidget);
        LayerFrame->setObjectName("LayerFrame");
        LayerFrame->setGeometry(QRect(540, 20, 527, 194));
        layoutWidget = new QWidget(LayerFrame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 528, 194));
        LayerGroups = new QVBoxLayout(layoutWidget);
        LayerGroups->setObjectName("LayerGroups");
        LayerGroups->setContentsMargins(0, 0, 0, 0);
        LayerGroup1 = new QHBoxLayout();
        LayerGroup1->setObjectName("LayerGroup1");
        layer0 = new QSelectButton(layoutWidget);
        layer0->setObjectName("layer0");
        layer0->setMinimumSize(QSize(84, 43));
        layer0->setMaximumSize(QSize(84, 43));

        LayerGroup1->addWidget(layer0);

        layer1 = new QSelectButton(layoutWidget);
        layer1->setObjectName("layer1");
        layer1->setMinimumSize(QSize(84, 43));
        layer1->setMaximumSize(QSize(84, 43));

        LayerGroup1->addWidget(layer1);

        layer2 = new QSelectButton(layoutWidget);
        layer2->setObjectName("layer2");
        layer2->setMinimumSize(QSize(84, 43));
        layer2->setMaximumSize(QSize(84, 43));

        LayerGroup1->addWidget(layer2);

        layer3 = new QSelectButton(layoutWidget);
        layer3->setObjectName("layer3");
        layer3->setMinimumSize(QSize(84, 43));
        layer3->setMaximumSize(QSize(84, 43));

        LayerGroup1->addWidget(layer3);

        layer4 = new QSelectButton(layoutWidget);
        layer4->setObjectName("layer4");
        layer4->setMinimumSize(QSize(84, 43));
        layer4->setMaximumSize(QSize(84, 43));

        LayerGroup1->addWidget(layer4);

        layer5 = new QSelectButton(layoutWidget);
        layer5->setObjectName("layer5");
        layer5->setMinimumSize(QSize(84, 43));
        layer5->setMaximumSize(QSize(84, 43));

        LayerGroup1->addWidget(layer5);


        LayerGroups->addLayout(LayerGroup1);

        LayerGroup2 = new QHBoxLayout();
        LayerGroup2->setObjectName("LayerGroup2");
        layer6 = new QSelectButton(layoutWidget);
        layer6->setObjectName("layer6");
        layer6->setMinimumSize(QSize(84, 43));
        layer6->setMaximumSize(QSize(84, 43));

        LayerGroup2->addWidget(layer6);

        layer7 = new QSelectButton(layoutWidget);
        layer7->setObjectName("layer7");
        layer7->setMinimumSize(QSize(84, 43));
        layer7->setMaximumSize(QSize(84, 43));

        LayerGroup2->addWidget(layer7);

        layer8 = new QSelectButton(layoutWidget);
        layer8->setObjectName("layer8");
        layer8->setMinimumSize(QSize(84, 43));
        layer8->setMaximumSize(QSize(84, 43));

        LayerGroup2->addWidget(layer8);

        layer9 = new QSelectButton(layoutWidget);
        layer9->setObjectName("layer9");
        layer9->setMinimumSize(QSize(84, 43));
        layer9->setMaximumSize(QSize(84, 43));

        LayerGroup2->addWidget(layer9);

        layer10 = new QSelectButton(layoutWidget);
        layer10->setObjectName("layer10");
        layer10->setMinimumSize(QSize(84, 43));
        layer10->setMaximumSize(QSize(84, 43));

        LayerGroup2->addWidget(layer10);

        layer11 = new QSelectButton(layoutWidget);
        layer11->setObjectName("layer11");
        layer11->setMinimumSize(QSize(84, 43));
        layer11->setMaximumSize(QSize(84, 43));

        LayerGroup2->addWidget(layer11);


        LayerGroups->addLayout(LayerGroup2);

        LayerGroup3 = new QHBoxLayout();
        LayerGroup3->setObjectName("LayerGroup3");
        layer12 = new QSelectButton(layoutWidget);
        layer12->setObjectName("layer12");
        layer12->setMinimumSize(QSize(84, 43));
        layer12->setMaximumSize(QSize(84, 43));

        LayerGroup3->addWidget(layer12);

        layer13 = new QSelectButton(layoutWidget);
        layer13->setObjectName("layer13");
        layer13->setMinimumSize(QSize(84, 43));
        layer13->setMaximumSize(QSize(84, 43));

        LayerGroup3->addWidget(layer13);

        layer14 = new QSelectButton(layoutWidget);
        layer14->setObjectName("layer14");
        layer14->setMinimumSize(QSize(84, 43));
        layer14->setMaximumSize(QSize(84, 43));

        LayerGroup3->addWidget(layer14);

        layer15 = new QSelectButton(layoutWidget);
        layer15->setObjectName("layer15");
        layer15->setMinimumSize(QSize(84, 43));
        layer15->setMaximumSize(QSize(84, 43));

        LayerGroup3->addWidget(layer15);

        layer16 = new QSelectButton(layoutWidget);
        layer16->setObjectName("layer16");
        layer16->setMinimumSize(QSize(84, 43));
        layer16->setMaximumSize(QSize(84, 43));

        LayerGroup3->addWidget(layer16);

        layer17 = new QSelectButton(layoutWidget);
        layer17->setObjectName("layer17");
        layer17->setMinimumSize(QSize(84, 43));
        layer17->setMaximumSize(QSize(84, 43));

        LayerGroup3->addWidget(layer17);


        LayerGroups->addLayout(LayerGroup3);

        LayerGroup4 = new QHBoxLayout();
        LayerGroup4->setObjectName("LayerGroup4");
        layer18 = new QSelectButton(layoutWidget);
        layer18->setObjectName("layer18");
        layer18->setMinimumSize(QSize(84, 43));
        layer18->setMaximumSize(QSize(84, 43));

        LayerGroup4->addWidget(layer18);

        layer19 = new QSelectButton(layoutWidget);
        layer19->setObjectName("layer19");
        layer19->setMinimumSize(QSize(84, 43));
        layer19->setMaximumSize(QSize(84, 43));

        LayerGroup4->addWidget(layer19);

        layer20 = new QSelectButton(layoutWidget);
        layer20->setObjectName("layer20");
        layer20->setMinimumSize(QSize(84, 43));
        layer20->setMaximumSize(QSize(84, 43));

        LayerGroup4->addWidget(layer20);

        layer21 = new QSelectButton(layoutWidget);
        layer21->setObjectName("layer21");
        layer21->setMinimumSize(QSize(84, 43));
        layer21->setMaximumSize(QSize(84, 43));

        LayerGroup4->addWidget(layer21);

        layer22 = new QSelectButton(layoutWidget);
        layer22->setObjectName("layer22");
        layer22->setMinimumSize(QSize(84, 43));
        layer22->setMaximumSize(QSize(84, 43));

        LayerGroup4->addWidget(layer22);

        layer23 = new QSelectButton(layoutWidget);
        layer23->setObjectName("layer23");
        layer23->setMinimumSize(QSize(84, 43));
        layer23->setMaximumSize(QSize(84, 43));

        LayerGroup4->addWidget(layer23);


        LayerGroups->addLayout(LayerGroup4);

        LayerBG = new QWidget(centralwidget);
        LayerBG->setObjectName("LayerBG");
        LayerBG->setGeometry(QRect(690, 220, 231, 71));
        LayerBG->setStyleSheet(QString::fromUtf8("border-image: url(:/Image/Background/LayerBG.png);"));
        TileArea = new QSelectArea(centralwidget);
        TileArea->setObjectName("TileArea");
        TileArea->setGeometry(QRect(10, 20, 510, 760));
        Map = new MapArea(centralwidget);
        Map->setObjectName("Map");
        Map->setGeometry(QRect(660, 320, 440, 440));
        Map->setAutoFillBackground(false);
        Map->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(520, 269, 131, 491));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 120, 650));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 10, 111, 631));
        Infos = new QVBoxLayout(verticalLayoutWidget);
        Infos->setSpacing(4);
        Infos->setObjectName("Infos");
        Infos->setContentsMargins(6, 0, 0, 0);
        Info01 = new InfoEdit(verticalLayoutWidget);
        Info01->setObjectName("Info01");

        Infos->addWidget(Info01);

        Info02 = new InfoEdit(verticalLayoutWidget);
        Info02->setObjectName("Info02");

        Infos->addWidget(Info02);

        Info03 = new InfoEdit(verticalLayoutWidget);
        Info03->setObjectName("Info03");

        Infos->addWidget(Info03);

        Info04 = new InfoEdit(verticalLayoutWidget);
        Info04->setObjectName("Info04");

        Infos->addWidget(Info04);

        Info05 = new InfoEdit(verticalLayoutWidget);
        Info05->setObjectName("Info05");

        Infos->addWidget(Info05);

        Info06 = new InfoEdit(verticalLayoutWidget);
        Info06->setObjectName("Info06");

        Infos->addWidget(Info06);

        Info07 = new InfoEdit(verticalLayoutWidget);
        Info07->setObjectName("Info07");

        Infos->addWidget(Info07);

        Info08 = new InfoEdit(verticalLayoutWidget);
        Info08->setObjectName("Info08");

        Infos->addWidget(Info08);

        Info09 = new InfoEdit(verticalLayoutWidget);
        Info09->setObjectName("Info09");

        Infos->addWidget(Info09);

        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1110, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        QFont font;
        font.setFamilies({QString::fromUtf8("Algerian")});
        font.setPointSize(10);
        font.setBold(true);
        statusbar->setFont(font);
        statusbar->setStyleSheet(QString::fromUtf8("border-image: url(:/Image/Background/TileBG.png);"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MapEdit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
