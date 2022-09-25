#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include "QListWidgetItem"
namespace Ui {
class Store;
}

class Store : public QWidget
{
    Q_OBJECT

public:
    explicit Store(QWidget *parent = nullptr);
    ~Store();
    void addGame();
    void newGame();
    void game_point_list();
private:
    Ui::Store *ui;
    QList<QListWidgetItem *> game;
};

#endif // STORE_H
