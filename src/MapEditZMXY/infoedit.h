#ifndef INFOEDIT_H
#define INFOEDIT_H

#include <QWidget>
#include <QPainter>
namespace Ui {
class InfoEdit;
}

class InfoEdit : public QWidget
{
    Q_OBJECT

public:
    explicit InfoEdit(QWidget *parent = nullptr);
    ~InfoEdit();

    void setInfoName(QString infoName);
    void paintEvent(QPaintEvent* e);
    int getNpcInfo();
    void setNpcInfo(int info);
    void setMinNum(int value);
private:
    Ui::InfoEdit *ui;
signals:
    void updateNpcInfo();
};

#endif // INFOEDIT_H
