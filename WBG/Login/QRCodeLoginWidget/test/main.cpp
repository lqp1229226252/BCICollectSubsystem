#include <QApplication>
#include "qrcodeloginwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRCodeLoginWidget *w=new QRCodeLoginWidget;
    w->showQRCodeLogin("wx");
    return a.exec();
}
