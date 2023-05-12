#include "dynamicitem.h"
#include "ui_dynamicitem.h"
#include "QDebug"
DynamicItem::DynamicItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DynamicItem)
{
    ui->setupUi(this);
}

DynamicItem::~DynamicItem()
{
    delete ui;
}

void DynamicItem::setDynamicData(DynamicData data)
{
    this->ui->date->setText(data.getDate());
    this->ui->cover->setPixmap(data.getCover());
    this->ui->dynamicname->setText(data.getDynamic_name());
    this->ui->gamename->setGameMsg(data.getGame_icon(),data.getGame_name());

}

void DynamicItem::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"查看公告详情";
}
