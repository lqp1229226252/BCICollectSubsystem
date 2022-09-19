#include "register_info.h"
#include "ui_register_info.h"

Register_info::Register_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register_info)
{
    ui->setupUi(this);
}

Register_info::~Register_info()
{
    delete ui;
}
