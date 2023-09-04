#ifndef GAMEENDDATA_H
#define GAMEENDDATA_H

#include <QWidget>
#include <QMap>
#include <QDebug>
#include <QListWidget>
#include "gameenddataitem.h"

namespace Ui {
class GameEndData;
}

class GameEndData : public QWidget
{
    Q_OBJECT

public:
    explicit GameEndData(QWidget *parent = nullptr);
    ~GameEndData();

    void showGameEndData(QMap<QString, QString> data);

private:
    Ui::GameEndData *ui;
    void initGameEndData();
    QListWidget *list_widget;
    gameenddataitem *dataitem;
    QList<QString> convertKeysText(QList<QString> keys);
};

#endif // GAMEENDDATA_H
