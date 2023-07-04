#ifndef CGAMEUPDATEITEM_H
#define CGAMEUPDATEITEM_H

#include <QWidget>

namespace Ui {
class CGameUpdateItem;
}

class CGameUpdateItem : public QWidget
{
    Q_OBJECT

public:
    explicit CGameUpdateItem(QWidget *parent = nullptr);
    ~CGameUpdateItem();

private:
    Ui::CGameUpdateItem *ui;
};

#endif // CGAMEUPDATEITEM_H
