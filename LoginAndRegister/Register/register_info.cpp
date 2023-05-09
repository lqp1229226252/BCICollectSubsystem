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

void Register_info::getAccount(QString _account)
{

    account=_account;
}

void Register_info::on_pushButton_saveInfo_clicked()
{
    //点击保存按钮。
    int sex = ui->lineEdit_sex->text()=="男"? 0:1;
    int handedness = ui->lineEdit_handy->text()=="右"? 0:1;
    QString qs=QString("call user_message('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13')")
            .arg(account)
            .arg("")
            .arg(ui->lineEdit_name->text())
            .arg(ui->lineEdit_age->text().toInt())
            .arg(ui->lineEdit_nation->text())
            .arg(sex)
            .arg(handedness)
            .arg(ui->lineEdit_work->text())
            .arg(ui->lineEdit_education->text())
            .arg(ui->lineEdit_address->text())
            .arg(ui->lineEdit_phone->text())
            .arg(ui->lineEdit_sport->text())
            .arg(ui->lineEdit_health->text());
    emit sendRegisterInfo(qs);
}
