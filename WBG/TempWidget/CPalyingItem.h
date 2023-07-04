#ifndef CPALYINGITEM_H
#define CPALYINGITEM_H

#include <QWidget>

namespace Ui {
class CPalyingItem;
}

class CPalyingItem : public QWidget
{
    Q_OBJECT

public:
    explicit CPalyingItem(QWidget *parent = nullptr);
    ~CPalyingItem();

private:
    Ui::CPalyingItem *ui;
};

#endif // CPALYINGITEM_H
