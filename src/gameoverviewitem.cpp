#include "gameoverviewitem.h"
#include "ui_gameoverviewitem.h"

GameOverviewItem::GameOverviewItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOverviewItem)
{
    ui->setupUi(this);
}

GameOverviewItem::~GameOverviewItem()
{
    delete ui;
}

void GameOverviewItem::setData(QString name, QString date, QString rank)
{
    ui->gamename->setText(name);
    ui->gamerank->setText(rank);
    ui->playdate->setText(date);
}
