#include "CNoticeItem.h"
#include "ui_CNoticeItem.h"

CNoticeItem::CNoticeItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNoticeItem)
{
    ui->setupUi(this);
}

CNoticeItem::~CNoticeItem()
{
    delete ui;
}
