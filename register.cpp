#include "register.h"
#include "ui_register.h"
#include <QDebug>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    connect(this,&Register::close,this,&Register::emit_close);
}

Register::~Register()
{
    emit close_register();
    delete ui;
}

void Register::emit_close()
{
    emit close_register();
}

void Register::closeEvent(QCloseEvent *event)
{
    emit close_register();
    this->close();
}

void Register::on_pushButton_getVerification_clicked()
{

}
