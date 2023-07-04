#ifndef CLASTNEWITEM_H
#define CLASTNEWITEM_H

#include <QWidget>

namespace Ui {
class CLastNewItem;
}

class CLastNewItem : public QWidget
{
    Q_OBJECT

public:
    explicit CLastNewItem(QWidget *parent = nullptr);
    ~CLastNewItem();

private:
    Ui::CLastNewItem *ui;
};

#endif // CLASTNEWITEM_H
