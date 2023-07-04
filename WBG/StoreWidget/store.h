#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include <QMap>
#include <QList>
#include "QListWidgetItem"
#include "newgameitem.h"
#include "welfarecenter.h"
#include "MPicturePlayer.h"
#include "CLastNewItem.h"
#include "CRecenePlayingItem.h"
#include "CActMore.h"

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
    void setText();

private slots:
    void on_widget_main_logo_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Store *ui;
    QList<QListWidgetItem *> game;

    QList<newgameitem *> newGameList;

    QList<QIcon> playCurrentIconList;
    QStringList *playCurrentGameList;

    QVector<QPixmap> demoGame;

    QMap<QString, QString> welFareCenterMap;
    QList<WelfareCenter *> welfareCenterItems;
    MPicturePlayer * m_pPicurePlay;
};

#endif // STORE_H
