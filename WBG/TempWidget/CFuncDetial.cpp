#include "CFuncDetial.h"
#include "ui_CFuncDetial.h"

CFuncDetial::CFuncDetial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CFuncDetial)
{
    ui->setupUi(this);
}

CFuncDetial::~CFuncDetial()
{
    delete ui;
}
