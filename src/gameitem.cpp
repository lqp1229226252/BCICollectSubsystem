#include "gameitem.h"
#include "ui_gameitem.h"
#include "QDebug"
GameItem::GameItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameItem)
{
    ui->setupUi(this);
}

GameItem::~GameItem()
{
    delete ui;
}

void GameItem::setGameMsg(QPixmap cover, QString name)
{
    cover=cover.scaled(ui->cover->width(),ui->cover->height());
    this->ui->cover->setPixmap(cover);
    this->ui->name->setText(name);
}

void GameItem::cancelName()
{
    delete  ui->name;
}

int GameItem::getCoverWidth()
{
    return ui->cover->width();
}
