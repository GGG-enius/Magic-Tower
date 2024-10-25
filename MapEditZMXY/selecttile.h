#ifndef SELECTTILE_H
#define SELECTTILE_H
#include "TileButton.h"
#include <QWidget>

namespace Ui {
class SelectTile;
}

class SelectTile : public QWidget
{
    Q_OBJECT

public:
    explicit SelectTile(QWidget *parent = nullptr);
    ~SelectTile();

private:
    Ui::SelectTile *ui;
signals:
    void updateInfo();
    void updateDefault();
    // void Init(NPCINFO info);
    // void updateNpcInfo(NPCINFO info);
    // void updateSelectTile(int id);
};

#endif // SELECTTILE_H
