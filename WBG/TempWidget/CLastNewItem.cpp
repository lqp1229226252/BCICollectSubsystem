#include "CLastNewItem.h"
#include "ui_CLastNewItem.h"

CLastNewItem::CLastNewItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CLastNewItem)
{
    ui->setupUi(this);
}

CLastNewItem::~CLastNewItem()
{
    delete ui;
}
