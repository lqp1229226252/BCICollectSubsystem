#include "usergamewidget.h"
#include "ui_usergamewidget.h"
#include "QDebug"
UserGameWidget::UserGameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserGameWidget)
{
    ui->setupUi(this);
    initLayout();
}

UserGameWidget::~UserGameWidget()
{
    delete ui;
    qDeleteAll(listview.begin(),listview.end());
    qDeleteAll(gameOverview.begin(),gameOverview.end());
    listview.clear();
    gameOverview.clear();
}

void UserGameWidget::addGamePlay(QList<GameData> data)
{
    for(QList<GameData>::iterator begin=data.begin();begin!=data.end();begin++)
    {
        QListWidgetItem *item=new QListWidgetItem();
        GameItem *gameitem=new GameItem();

        QPixmap cover=(*begin).getCover();
        QString name=(*begin).getName();
        gameitem->setGameMsg(cover,name);
        gameitem->cancelName();
        item->setSizeHint(QSize(180,70));

        ui->gameplay->addItem(item);
        ui->gameplay->setItemWidget(item,gameitem);
    }
}

void UserGameWidget::addGameUpdate(QList<GameData> data)
{
    for(QList<GameData>::iterator begin=data.begin();begin!=data.end();begin++)
    {
        QListWidgetItem *item=new QListWidgetItem();
        GameItem *gameitem=new GameItem();
        QPixmap cover=(*begin).getCover();
        QString name=(*begin).getName();
        gameitem->setGameMsg(cover,name);
        gameitem->cancelName();
        item->setSizeHint(QSize(180,70));
        ui->gameupdate->addItem(item);
        ui->gameupdate->setItemWidget(item,gameitem);
    }
}

void UserGameWidget::addGame(QList<GameData> data)
{
    for(QList<GameData>::iterator begin=data.begin();begin!=data.end();begin++)
    {
        QListWidgetItem *item=new QListWidgetItem();
        GameItem *gameitem=new GameItem();
        gameitem->setGameMsg((*begin).getIcon(),(*begin).getName());
        item->setSizeHint(QSize(ui->gameList->width(),30));
        ui->gameList->addItem(item);
        ui->gameList->setItemWidget(item,gameitem);
    }

}

void UserGameWidget::setGameOverview(QList<GameData> data)
{
    ui->gameoverview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for(QList<GameData>::iterator begin=data.begin();begin!=data.end();begin++)
    {
        QListWidgetItem *item=new QListWidgetItem();
        GameOverviewItem *overviewitem=new GameOverviewItem();
        overviewitem->setData((*begin).getName(),(*begin).getPlaytime(),(*begin).getPlayrank());
        ui->gameoverview->addItem(item);
        ui->gameoverview->setItemWidget(item,overviewitem);
    }

}

void UserGameWidget::setGameDynamic(QList<DynamicData> data)
{
    for(QList<DynamicData>::iterator begin=data.begin();begin!=data.end();begin++)
    {
        QListWidgetItem *item=new QListWidgetItem();
        DynamicItem *dynamicitem=new DynamicItem();
        dynamicitem->setDynamicData((*begin));
        item->setSizeHint(QSize(ui->gamedynamic->height(),ui->gamedynamic->height()-30));
        ui->gamedynamic->addItem(item);
        ui->gamedynamic->setItemWidget(item,dynamicitem);
    }
}
void UserGameWidget::initLayout()
{
  /*  ui->widgetlayout->setStretch(0,2);
    ui->widgetlayout->setStretch(1,1);
    ui->gamelistlayout2->setStretch(0,1);
    ui->gamelistlayout2->setStretch(1,2);
    ui->gamelistlayout1->setStretch(0,1);
    ui->gamelistlayout1->setStretch(1,2);
    ui->gamelistlayout->setStretch(0,1);
    ui->gamelistlayout->setStretch(1,5);
    */
}
