#include "CPalyingItem.h"
#include "ui_CPalyingItem.h"

CPalyingItem::CPalyingItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CPalyingItem)
{
    ui->setupUi(this);
}

CPalyingItem::~CPalyingItem()
{
    delete ui;
}
