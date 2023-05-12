#include <QApplication>
#include "tcpserver.h"
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TcpServer *tcp = new TcpServer();
    tcp->tcpListen();


    return a.exec();
}
