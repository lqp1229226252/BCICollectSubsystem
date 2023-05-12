#include "connectdialog.h"
#include "ui_connectdialog.h"
#include "QMessageBox"
#include "QDebug"
#include "QMovie"
#include "sample.h"
ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    loading=new QLabel(this);
    loading->resize(this->size()/2);
    loading->raise();
    QMovie *movie=new QMovie(":/loading.gif");
    movie->start();
    loading->setMovie(movie);
    loading->setScaledContents(true);
    loading->hide();
    loading->move(this->width()/4,this->height()/4);
    this->ui->device->setEnabled(false);
    this->ui->connect->setEnabled(false);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::setFamily(QStringList value)
{
    ui->family->clear();
    this->ui->family->addItems(value);
}

void ConnectDialog::setType(QStringList value)
{
    ui->type->clear();
    ui->type->addItems(value);
}

void ConnectDialog::setDeviceNum(int num)
{
    loading->hide();
    ui->device->clear();
    for(int i=0;i<num;i++)
    {
        ui->device->addItem(QString::number(i));
    }
    this->ui->device->setEnabled(true);
    this->ui->connect->setEnabled(true);
    this->ui->search->setEnabled(true);
}

void ConnectDialog::showError(quint8 error)
{
    if(error==Sample::ConnectError)
    {
        QMessageBox::about(this,"消息提示","连接设备失败");
        this->ui->search->setEnabled(true);
    }
    if(error==Sample::FamilyError)
    {
        QMessageBox::about(this,"消息提示","设备系列设置失败");
        this->ui->search->setEnabled(true);
    }

}
void ConnectDialog::on_connect_clicked()
{
    emit connect(ui->device->currentIndex());
}

void ConnectDialog::on_search_clicked()
{
    loading->show();
    this->ui->search->setEnabled(false);
    emit search(ui->family->currentIndex(),ui->type->currentIndex());
}
