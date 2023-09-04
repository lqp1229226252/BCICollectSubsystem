#include "gameenddataitem.h"
#include "ui_gameenddataitem.h"

gameenddataitem::gameenddataitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameenddataitem)
{
    ui->setupUi(this);
}

gameenddataitem::~gameenddataitem()
{
    delete ui;
}

void gameenddataitem::setTitle(QString title)
{
    ui->title->setText(title);

}

void gameenddataitem::setValue(QString value)
{
    ui->value->setText(value);
}

