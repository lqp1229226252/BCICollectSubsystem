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
    this->ui->cover->setPixmap(cover);
    this->ui->name->setText(name);
}

void GameItem::cancelName()
{
    delete  ui->name;
    ui->name=NULL;
}

int GameItem::getCoverWidth()
{
    return ui->cover->width();
}
void GameItem::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"跳转游戏";
}
