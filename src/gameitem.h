#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QWidget>

namespace Ui {
class GameItem;
}

class GameItem : public QWidget
{
    Q_OBJECT

public:
    explicit GameItem(QWidget *parent = nullptr);
    ~GameItem();
    void setGameMsg(QPixmap cover,QString name);
    void cancelName();
    int  getCoverWidth();
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    Ui::GameItem *ui;
};

#endif // GAMEITEM_H
