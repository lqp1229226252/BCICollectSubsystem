#include <QApplication>
#include "tcpserver.h"
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TcpServer *tcp = TcpServer::getInstance();

    return a.exec();
}
