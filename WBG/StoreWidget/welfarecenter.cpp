#include "welfarecenter.h"
#include "ui_welfarecenter.h"

WelfareCenter::WelfareCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelfareCenter)
{
    ui->setupUi(this);
}

WelfareCenter::~WelfareCenter()
{
    delete ui;
}

void WelfareCenter::setData(const QString title, const QString content){
    ui->title->setText(title);
    ui->content->setText(content);
}
