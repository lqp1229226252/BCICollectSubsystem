#include "register.h"
#include "ui_register.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

}

Register::~Register()
{
    delete ui;
}

QString Register::SendAccount()
{
    return ui->lineEdit_phone->text();
}


void Register::closeEvent(QCloseEvent *event)
{
    //关闭注册页面，返回登录页面
    emit close_register();
    this->close();
}

void Register::on_pushButton_getVerification_clicked()
{

}

void Register::on_pushButton_register_clicked()
{
    //发送注册信息

    if(ui->lineEdit_phone->text().count()==11){
        if ( (ui->lineEdit_password->text().count()>=8 && ui->lineEdit_password->text().count()<=20) ){
            if ( (ui->lineEdit_password->text() == ui->lineEdit_repassword->text()) ){
                emit sendRegister(ui->lineEdit_phone->text(),ui->lineEdit_password->text());
            }
            else{
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,"密码错误","两次密码输入不同");
                QTimer::singleShot(2000,m_box,SLOT(accept()));
                m_box->exec();
            }
        }
        else{
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,"密码错误","密码长度错误");
            QTimer::singleShot(2000,m_box,SLOT(accept()));
            m_box->exec();
        }
    }
    else{
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,"手机号错误","手机号长度错误");
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->exec();
    }


}




























