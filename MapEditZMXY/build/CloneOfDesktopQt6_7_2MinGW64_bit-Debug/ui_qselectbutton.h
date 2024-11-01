/********************************************************************************
** Form generated from reading UI file 'qselectbutton.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSELECTBUTTON_H
#define UI_QSELECTBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSelectButton
{
public:
    QPushButton *SelBtn;

    void setupUi(QWidget *QSelectButton)
    {
        if (QSelectButton->objectName().isEmpty())
            QSelectButton->setObjectName("QSelectButton");
        QSelectButton->resize(84, 43);
        QSelectButton->setMinimumSize(QSize(84, 43));
        QSelectButton->setMaximumSize(QSize(84, 43));
        QSelectButton->setStyleSheet(QString::fromUtf8("QPushButton{border:0px;}\n"
"QPushButton{background-image: url(:/Image/Button/SelectButton0001.png);}\n"
"QPushButton:hover{background-image: url(:/Image/Button/SelectButton0002.png);}\n"
"QPushButton:checked{background-image: url(:/Image/Button/SelectButton0002.png);}\n"
""));
        SelBtn = new QPushButton(QSelectButton);
        SelBtn->setObjectName("SelBtn");
        SelBtn->setGeometry(QRect(0, 0, 83, 42));
        SelBtn->setMinimumSize(QSize(83, 42));
        SelBtn->setMaximumSize(QSize(83, 42));
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\210\261\345\245\207\350\211\272\351\273\221\344\275\223 Black")});
        font.setPointSize(16);
        font.setBold(true);
        SelBtn->setFont(font);
        SelBtn->setStyleSheet(QString::fromUtf8("QPushButton{border:0px;}\n"
"QPushButton{border-image: url(:/Image/Button/SelectButton0001.png);}\n"
"QPushButton:hover{border-image: url(:/Image/Button/SelectButton0002.png);}\n"
"QPushButton:checked{border-image: url(:/Image/Button/SelectButton0002.png);}"));
        SelBtn->setCheckable(true);
        SelBtn->setChecked(false);
        SelBtn->setAutoExclusive(true);

        retranslateUi(QSelectButton);

        QMetaObject::connectSlotsByName(QSelectButton);
    } // setupUi

    void retranslateUi(QWidget *QSelectButton)
    {
        QSelectButton->setWindowTitle(QCoreApplication::translate("QSelectButton", "Form", nullptr));
        SelBtn->setText(QCoreApplication::translate("QSelectButton", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSelectButton: public Ui_QSelectButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSELECTBUTTON_H
