#ifndef CGAMEITEM_H
#define CGAMEITEM_H

#include <QWidget>

namespace Ui {
class CGameItem;
}

class CGameItem : public QWidget
{
    Q_OBJECT

public:
    explicit CGameItem(QWidget *parent = nullptr);
    ~CGameItem();

private:
    Ui::CGameItem *ui;
};

#endif // CGAMEITEM_H
