#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include <QMap>
#include <QList>
#include "QListWidgetItem"
#include "newgameitem.h"
#include "welfarecenter.h"

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
    void initNewGameList();
    void initPlayCurrentList();
    void initWelfareCenterMap();
    void initWelfareCenterItems();
    void initWelfareCenter();
private:
    Ui::Store *ui;
    QList<QListWidgetItem *> game;

    QList<newgameitem *> newGameList;

    QList<QIcon> playCurrentIconList;
    QStringList *playCurrentGameList;

    QVector<QPixmap> demoGame;

    QMap<QString, QString> welFareCenterMap;
    QList<WelfareCenter *> welfareCenterItems;
};

#endif // STORE_H
