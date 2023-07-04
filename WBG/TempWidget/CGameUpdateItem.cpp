#include "CGameUpdateItem.h"
#include "ui_CGameUpdateItem.h"

CGameUpdateItem::CGameUpdateItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CGameUpdateItem)
{
    ui->setupUi(this);
}

CGameUpdateItem::~CGameUpdateItem()
{
    delete ui;
}
