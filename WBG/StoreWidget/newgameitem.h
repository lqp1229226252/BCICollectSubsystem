#ifndef NEWGAMEITEM_H
#define NEWGAMEITEM_H

#include <QWidget>

namespace Ui {
class newgameitem;
}

class newgameitem : public QWidget
{
    Q_OBJECT

public:
    explicit newgameitem(QWidget *parent = nullptr);
    ~newgameitem();

    void setData(QString picPth);

private:
    Ui::newgameitem *ui;
};

#endif // NEWGAMEITEM_H
