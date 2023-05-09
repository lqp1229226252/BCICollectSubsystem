#ifndef USERGAMEWIDGET_H
#define USERGAMEWIDGET_H

#include <QWidget>
#include "QListWidgetItem"
#include "gameoverviewitem.h"
#include "gamedata.h"
#include "gameitem.h"
#include "dynamicdata.h"
#include "dynamicitem.h"
namespace Ui {
class UserGameWidget;
}

class UserGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserGameWidget(QWidget *parent = nullptr);
    ~UserGameWidget();
    void addGamePlay(QList<GameData> data);
    void addGameUpdate(QList<GameData> data);
    void addGame(QList<GameData> data);
    void setGameOverview(QList<GameData> data);
    void setGameDynamic(QList<DynamicData> data);

private:
    Ui::UserGameWidget *ui;
    QList<QListWidgetItem *> listview;
    QList<GameOverviewItem *> gameOverview;
    void initLayout();


};



#endif // USERGAMEWIDGET_H
