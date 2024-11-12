/********************************************************************************
** Form generated from reading UI file 'infoedit.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOEDIT_H
#define UI_INFOEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoEdit
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *InfoEdit)
    {
        if (InfoEdit->objectName().isEmpty())
            InfoEdit->setObjectName("InfoEdit");
        InfoEdit->resize(102, 69);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InfoEdit->sizePolicy().hasHeightForWidth());
        InfoEdit->setSizePolicy(sizePolicy);
        InfoEdit->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(InfoEdit);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(InfoEdit);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Algerian")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(InfoEdit);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimumSize(QSize(80, 25));
        spinBox->setFont(font);
        spinBox->setStyleSheet(QString::fromUtf8("border-image: url(:/Image/Background/LayerBG.png);"));
        spinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMinimum(0);
        spinBox->setMaximum(99999);

        verticalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(InfoEdit);
        horizontalSlider->setObjectName("horizontalSlider");
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMinimumSize(QSize(90, 10));
        horizontalSlider->setMaximumSize(QSize(90, 10));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(99999);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        retranslateUi(InfoEdit);

        QMetaObject::connectSlotsByName(InfoEdit);
    } // setupUi

    void retranslateUi(QWidget *InfoEdit)
    {
        InfoEdit->setWindowTitle(QCoreApplication::translate("InfoEdit", "Form", nullptr));
        label->setText(QCoreApplication::translate("InfoEdit", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoEdit: public Ui_InfoEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOEDIT_H
