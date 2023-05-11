#include "tcpserver.h"
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QHostInfo>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtCore/QCoreApplication>
#include <QStringBuilder>

TcpServer::TcpServer()
{
    analysisGameMsg=new AnalysisGameMsg;
    tcpServer=new QTcpServer();
    connect(analysisGameMsg, &AnalysisGameMsg::gameFinish, this, &TcpServer::gameFinish);
    connect(analysisGameMsg, &AnalysisGameMsg::gameStart, this, &TcpServer::gameStart);
    connect(analysisGameMsg, &AnalysisGameMsg::gameEnemyBorn, this, &TcpServer::gameEnemyBorn);
    connect(analysisGameMsg, &AnalysisGameMsg::gameEnemyDie, this, &TcpServer::gameEnemyDie);
    connect(analysisGameMsg, &AnalysisGameMsg::gameFireHit, this, &TcpServer::gameFireHit);
    connect(analysisGameMsg, &AnalysisGameMsg::gameFireMiss, this, &TcpServer::gameFireMiss);
    connect(analysisGameMsg, &AnalysisGameMsg::gameCutHit, this, &TcpServer::gameCutHit);
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
        QTcpSocket *clientTemp = tcpServer->nextPendingConnection();   //拿到当前的socket
        qDebug() << "监听到新的连接请求";

        qDebug() << "TcpServer::tcpNewConnect--" << "客户端IP" << clientTemp->peerAddress().toString();
        qDebug() << "TcpServer::tcpNewConnect--" << "客户端port" << clientTemp->peerPort();
        clientList.append(clientTemp);    //将当前socket添加到列表中（方便操作）

        connect(clientTemp, &QTcpSocket::readyRead, this, &TcpServer::readyReadData);

        //连接断开，销毁socket对象，这是为了开关server时socket正确释放
        connect(clientTemp,&QTcpSocket::disconnected,[this,clientTemp]{
            clientTemp->deleteLater();
            clientList.removeOne(clientTemp);
            qDebug() << "TcpServer::tcpNewConnect--" << "客户端"
                     << clientTemp->peerAddress().toString() << ":" << clientTemp->peerPort() << "断开连接";
            recContent.clear();
         });
    }
}

void TcpServer::readyReadData()
{
    //拿到发送信号的客户端指针，通过该指针读取数据
    QTcpSocket *curClient = dynamic_cast<QTcpSocket *>(sender());

    recContent.append(curClient->readAll());

    QByteArray start = "MsgType";
    QByteArray end = "MsgEnd";

    if (!recContent.isEmpty()){
        //qDebug() << recContent;
        if(recContent.startsWith(start) && recContent.endsWith(end)){
            int startIndex = recContent.indexOf(start);
            int endIndex = recContent.indexOf(end)+end.length()-1;
            int MsgLength = endIndex-startIndex+1;
            //qDebug() << startIndex;
            //qDebug() << MsgLength;
            QByteArray content = recContent.mid(startIndex,MsgLength);
            analysisGameMsg->analysis(content);
            recContent.remove(startIndex,MsgLength);
        }else{
            int MsgTypeIndex = recContent.indexOf(start);
            recContent.remove(0,MsgTypeIndex);
        }
    }
//    emit recvDataSignal(curClient->readAll());
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


