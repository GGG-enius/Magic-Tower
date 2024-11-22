#ifndef QSELECTAREA_H
#define QSELECTAREA_H
#include "TileButton.h"
#include <QWidget>

namespace Ui {
class QSelectArea;
}

class QSelectArea : public QWidget
{
    Q_OBJECT

public:
    explicit QSelectArea(QWidget *parent = nullptr);
    ~QSelectArea();

    Ui::QSelectArea * getUI();
private:
    Ui::QSelectArea *ui;
signals:
    void updateInfo();
    void updateDefault();
    // void Init(NPCINFO info);
    // void updateNpcInfo(NPCINFO info);
    // void updateSelectTile(int id);
};

#endif // QSELECTAREA_H
