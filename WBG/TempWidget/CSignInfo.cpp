#include "CSignInfo.h"
#include "ui_CSignInfo.h"

CSignInfo::CSignInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSignInfo)
{
    ui->setupUi(this);
}

CSignInfo::~CSignInfo()
{
    delete ui;
}

void CSignInfo::setTextInfo(const QString &key,const QString &value)
{
    ui->label_key->setText(key);
    ui->label_value->setText(value);
}
