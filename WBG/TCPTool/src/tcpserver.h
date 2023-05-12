#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QtCore/QCoreApplication>
#include "analysisgamemsg.h"


class TcpServer : public QObject
{
    Q_OBJECT

public:
    TcpServer();

    void tcpListen();

    void tcpSendContent(QString content);

    void closeServer();

    QString getLocalIP();

    void recvData(TcpServer *server);

signals:
    //通过该信号传递接收到的数据
//    void recvDataSignal(QString data);

    void gameFinish(QMap<QString,QString>);
    void gameStart(QMap<QString,QString>);
    void gameEnemyBorn(QMap<QString,QString>);
    void gameEnemyDie(QMap<QString,QString>);
    void gameFireHit(QMap<QString,QString>);
    void gameFireMiss(QMap<QString,QString>);
    void gameCutHit(QMap<QString,QString>);

public slots:
    //当有新连接时的槽函数
    void tcpNewConnect();
    //当有数据来时的槽函数
    void readyReadData();



private:
   QTcpServer *tcpServer;
    //存储已连接的socket对象
    QList<QTcpSocket*> clientList;

    AnalysisGameMsg *analysisGameMsg;

    QByteArray recContent;

};

#endif // TCPSERVER_H
