#ifndef GAMEENDDATAITEM_H
#define GAMEENDDATAITEM_H

#include <QWidget>

namespace Ui {
class gameenddataitem;
}

class gameenddataitem : public QWidget
{
    Q_OBJECT

public:
    explicit gameenddataitem(QWidget *parent = nullptr);
    ~gameenddataitem();

    void setTitle(QString title);
    void setValue(QString value);


private:
    Ui::gameenddataitem *ui;
};

#endif // GAMEENDDATAITEM_H
