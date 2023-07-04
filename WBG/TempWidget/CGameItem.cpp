#include "CGameItem.h"
#include "ui_CGameItem.h"

CGameItem::CGameItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CGameItem)
{
    ui->setupUi(this);
}

CGameItem::~CGameItem()
{
    delete ui;
}
