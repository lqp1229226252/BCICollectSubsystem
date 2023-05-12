#include "tcpserver.h"
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QHostInfo>
#include <QTcpServer>
#include <QTcpSocket>

TcpServer* TcpServer::self = NULL;
QTcpServer* TcpServer::tcpServer = NULL;


TcpServer *TcpServer::getInstance()
{
    //判断是否是第一次调用
    //假如不为NULL,会直接return
    if (self == NULL) {

        //防止多进程同时调用创建2个对象的问题
        //原理是因为是静态变量只会定义一次
        static QMutex mutex;

        //上锁  QMutexLocker会锁住mutex，当QMutexLocker 被释放的时候会自动解锁
        //locker是局部变量，所以getInstance（）函数结束之后会自动解锁
        QMutexLocker locker(&mutex);

        //再判断一次,防止其它进程抢先new过了
        if (self == NULL) {
            self = new TcpServer();
            tcpServer = new QTcpServer(self);
//            tcpSocket = new QTcpSocket(self);

        }
    }

    return self; //返回指针
}

void TcpServer::hello()
{
    qDebug() << "hello";
}

// 开始监听
void TcpServer::tcpListen()
{
    // 判断当前是否已开启，是则close，否则listen
    QString IP = getLocalIP();
//    QString IP = "10.0.0.1";
    QHostAddress addr(IP);
    quint16 port = 6666;
    if(tcpServer->isListening()){
        qDebug() << "监听失败";
        closeServer();
    }else{
        //开始监听，并判断是否成功
        if(tcpServer->listen(addr, port)){
            //连接成功就修改界面按钮提示，以及地址栏不可编辑
            qDebug() << "监听成功";
            //连接相关的信号槽
            connect(tcpServer, &QTcpServer::newConnection, this, &TcpServer::tcpNewConnect);
        }
    }

}

// 监听到新的客户端连接请求
void TcpServer::tcpNewConnect()
{
    //循环获取客户端socket
    while (tcpServer->hasPendingConnections())
    {
//        qDebug() << "监听到新的连接请求";
        QTcpSocket *clientTemp = tcpServer->nextPendingConnection();   //拿到当前的socket
        qDebug() << "客户端IP" << clientTemp->peerAddress().toString();
        clientList.append(clientTemp);    //将当前socket添加到列表中（方便操作）
        connect(clientTemp, &QTcpSocket::readyRead, this, &TcpServer::readyReadData);
    }
}

void TcpServer::readyReadData()
{
    //拿到发送信号的客户端指针，通过该指针读取数据
    QTcpSocket *curClient = dynamic_cast<QTcpSocket *>(sender());
    emit recvDataSignal(curClient->readAll());
}


// 服务器向客户端发送内容
void TcpServer::tcpSendContent(QString content)
{
    //判断是否开启了server
    if(!tcpServer->isListening())
        return;
    //将发送区文本发送给客户端
    const QByteArray sendData=content.toUtf8();
    if(sendData.isEmpty())
        return;
//    if(sendData != nullptr)
//        return;
    for(QTcpSocket *socket:clientList)
    {
        socket->write(sendData);
    }
}


// 关闭监听
void TcpServer::closeServer()
{

    for(QTcpSocket *socket:clientList)
    {
        //断开与客户端的连接
        socket->disconnectFromHost();
        if(socket->state()!=QAbstractSocket::UnconnectedState){
            socket->abort();
        }
    }
    //停止服务
    tcpServer->close();
}



// 获取本机IPv4地址
QString TcpServer::getLocalIP()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIP = "";

    QList<QHostAddress> addList = hostInfo.addresses();
    if(!addList.isEmpty()){
        for (int i=0;i<addList.count();i++){
            QHostAddress aHost = addList.at(i);
            if(QAbstractSocket::IPv4Protocol==aHost.protocol()){
                localIP = aHost.toString();
                break;
            }
        }
    }
    return localIP;
}


