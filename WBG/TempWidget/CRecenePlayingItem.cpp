#include "CRecenePlayingItem.h"
#include "ui_CRecenePlayingItem.h"

CRecenePlayingItem::CRecenePlayingItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CRecenePlayingItem)
{
    ui->setupUi(this);
}

CRecenePlayingItem::~CRecenePlayingItem()
{
    delete ui;
}
