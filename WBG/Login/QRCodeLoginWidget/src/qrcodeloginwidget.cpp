#include "qrcodeloginwidget.h"
#include "./ui_qrcodeloginwidget.h"

QRCodeLoginWidget::QRCodeLoginWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QRCodeLoginWidget)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/QRCode/logo.png"));  //单独运行是用的


}

QRCodeLoginWidget::~QRCodeLoginWidget()
{
    delete ui;
}

void QRCodeLoginWidget::showQRCodeLogin(QString login_type)
{
    //三种不同扫码方式的登录
    if(login_type=="wx"){
        this->setWindowTitle("微信");
        QImage img(":/QRCode/QRCode.png");
        ui->label->setPixmap(QPixmap::fromImage(img));
        this->show();
    }
    else if(login_type=="qq"){
        this->setWindowTitle("QQ");
        QImage img(":/QRCode/QRCode.png");
        ui->label->setPixmap(QPixmap::fromImage(img));
        this->show();
    }
    else{
        this->setWindowTitle("WBG");
        QImage img(":/QRCode/QRCode.png");
        ui->label->setPixmap(QPixmap::fromImage(img));
        this->show();
    }
}

