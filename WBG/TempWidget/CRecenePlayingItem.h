#ifndef CRECENEPLAYINGITEM_H
#define CRECENEPLAYINGITEM_H

#include <QWidget>

namespace Ui {
class CRecenePlayingItem;
}

class CRecenePlayingItem : public QWidget
{
    Q_OBJECT

public:
    explicit CRecenePlayingItem(QWidget *parent = nullptr);
    ~CRecenePlayingItem();

private:
    Ui::CRecenePlayingItem *ui;
};

#endif // CRECENEPLAYINGITEM_H
