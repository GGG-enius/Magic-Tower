/********************************************************************************
** Form generated from reading UI file 'qselectarea.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSELECTAREA_H
#define UI_QSELECTAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>
#include <selecttile.h>

QT_BEGIN_NAMESPACE

class Ui_QSelectArea
{
public:
    QScrollArea *scrollArea;
    SelectTile *scrollAreaWidgetContents;
    QScrollBar *ScrollBar;

    void setupUi(QWidget *QSelectArea)
    {
        if (QSelectArea->objectName().isEmpty())
            QSelectArea->setObjectName("QSelectArea");
        QSelectArea->resize(510, 760);
        QSelectArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea = new QScrollArea(QSelectArea);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 480, 760));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new SelectTile();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 480, 1100));
        scrollArea->setWidget(scrollAreaWidgetContents);
        ScrollBar = new QScrollBar(QSelectArea);
        ScrollBar->setObjectName("ScrollBar");
        ScrollBar->setGeometry(QRect(490, 0, 16, 760));
        ScrollBar->setStyleSheet(QString::fromUtf8("/* \346\225\264\344\270\252\346\273\232\345\212\250\346\235\241\345\214\272\345\237\237\346\240\267\345\274\217 */\n"
"QScrollBar:vertical {\n"
"  border: none;\n"
"	border-image: url(:/Image/Button/ScrollBar0002.png);\n"
"  width: 16px;\n"
"  /* \346\273\221\345\235\227\346\264\273\345\212\250\345\214\272\345\237\237\351\227\264\350\267\235\357\274\214\350\277\231\344\270\252\351\227\264\350\267\235\345\246\202\346\236\234\345\260\217\344\272\216add-line\345\222\214sub-line\347\232\204\351\253\230\345\272\246\346\210\226\345\256\275\345\272\246\346\273\232\345\212\250\346\273\221\345\235\227\345\260\206\344\274\232\350\246\206\347\233\226add-line\345\222\214sub-line\357\274\214\346\211\200\344\273\245\345\217\257\344\273\245\351\200\232\350\277\207margin: 0px 0 0px 0;\346\235\245\351\232\220\350\227\217\346\273\232\345\212\250\346\235\241\344\270\244\345\244\264\345\214\272\345\237\237*/\n"
"  margin: 16px 0 16px 0;\n"
"border-radius: 2px;\n"
"    border-style: flat;\n"
"}\n"
"/* \346\273\221\345\235\227\345\214"
                        "\272\345\237\237\346\240\267\345\274\217 */\n"
"QScrollBar::handle:vertical {\n"
"  \n"
"	border-image: url(:/Image/Button/ScrollBar0001.png);\n"
"  min-height: 16px;\n"
"  margin: 0 1px 0 1px; \n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
" \n"
"    border: 1px solid #4C99F8;\n"
"}\n"
"QScrollBar::handle:vertical:pressed {\n"
"  \n"
"    border: 1px solid #4C99F8;\n"
"}\n"
"/* \345\220\221\344\270\212\347\256\255\345\244\264\346\240\267\345\274\217 */\n"
"QScrollBar::sub-line:vertical {\n"
"  border: none; \n"
"background-color: transparent;\n"
"  height: 16px;\n"
"  subcontrol-position: top;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"/* \345\220\221\344\270\213\347\256\255\345\244\264\346\240\267\345\274\217 */\n"
"QScrollBar::add-line:vertical {\n"
"  border: none;\n"
"  background: transparent;\n"
"  height: 16px;\n"
"  subcontrol-position: bottom;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::up-arrow:vertical {\n"
"	border-image: url(:/Image/Button/UpArrow.png);\n"
"  width: 16;\n"
"  height"
                        ": 16;\n"
"  \n"
"}\n"
"/* \345\220\221\344\270\213\347\256\255\345\244\264\346\240\267\345\274\217 */\n"
"QScrollBar::down-arrow:vertical {\n"
"  \n"
"	border-image: url(:/Image/Button/DownArrow.png);\n"
"  width: 16;\n"
"  height: 16;\n"
"\n"
"}\n"
"/* \346\273\232\345\212\250\346\235\241\344\270\212\351\235\242\345\222\214\344\270\213\351\235\242\345\214\272\345\237\237\346\240\267\345\274\217 */\n"
"QScrollBar::sub-page:vertical,\n"
"QScrollBar::add-page:vertical {\n"
"  background: none;\n"
"  width: 0px;\n"
"  height: 0px;\n"
"}\n"
"\n"
""));
        ScrollBar->setMaximum(342);
        ScrollBar->setSingleStep(100);
        ScrollBar->setPageStep(30);
        ScrollBar->setOrientation(Qt::Orientation::Vertical);
        ScrollBar->setInvertedAppearance(false);

        retranslateUi(QSelectArea);

        QMetaObject::connectSlotsByName(QSelectArea);
    } // setupUi

    void retranslateUi(QWidget *QSelectArea)
    {
        QSelectArea->setWindowTitle(QCoreApplication::translate("QSelectArea", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSelectArea: public Ui_QSelectArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSELECTAREA_H
