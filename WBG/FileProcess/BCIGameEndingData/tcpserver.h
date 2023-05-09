#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpServer : public QObject
{
    Q_OBJECT

public:
    //通过它获取self指针,这个函数是静态调用,不需要创建对象就可以访问
    static TcpServer *getInstance();

    void hello();

    void tcpListen();

    void tcpSendContent(QString content);

    void closeServer();

    QString getLocalIP();

    void recvData(TcpServer *server);

signals:
    //通过该信号传递接收到的数据
    void recvDataSignal(QString data);

public slots:
    //当有新连接时的槽函数
    void tcpNewConnect();
    //当有数据来时的槽函数
    void readyReadData();

private:
    TcpServer(){ //构造函数,写在private下,不允许new生成单例
    //可以加入你的代码,也可以没有代码
    }
    static TcpServer *self; //静态指针
    static QTcpServer *tcpServer;
//    static QTcpSocket *tcpSocket;
    //存储已连接的socket对象
    QList<QTcpSocket*> clientList;

};

#endif // TCPSERVER_H
