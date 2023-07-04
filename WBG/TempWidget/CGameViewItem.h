#ifndef CGAMEVIEWITEM_H
#define CGAMEVIEWITEM_H

#include <QWidget>

namespace Ui {
class CGameViewItem;
}

class CGameViewItem : public QWidget
{
    Q_OBJECT

public:
    explicit CGameViewItem(QWidget *parent = nullptr);
    ~CGameViewItem();

private:
    Ui::CGameViewItem *ui;
};

#endif // CGAMEVIEWITEM_H
