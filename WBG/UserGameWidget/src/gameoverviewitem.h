#ifndef GAMEOVERVIEWITEM_H
#define GAMEOVERVIEWITEM_H

#include <QWidget>

namespace Ui {
class GameOverviewItem;
}

class GameOverviewItem : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverviewItem(QWidget *parent = nullptr);
    ~GameOverviewItem();
    void setData(QString name,QString date,QString rank);

private:
    Ui::GameOverviewItem *ui;
};

#endif // GAMEOVERVIEWITEM_H
