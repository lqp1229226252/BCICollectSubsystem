#include "CGameViewItem.h"
#include "ui_CGameViewItem.h"

CGameViewItem::CGameViewItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CGameViewItem)
{
    ui->setupUi(this);
}

CGameViewItem::~CGameViewItem()
{
    delete ui;
}
