﻿#include "ftpserver.h"
#include "ftpcontrolconnection.h"

#include <QDebug>
#include <QNetworkInterface>
#include <QTcpServer>
#include <QTcpSocket>

FtpServer::FtpServer(QObject *parent, const QString &rootPath, int port, const QString &userName, const QString &password, bool readOnly, bool onlyOneIpAllowed) :
    QObject(parent)
{
    this->userName = userName;
    this->password = password;
    this->rootPath = rootPath;
    this->readOnly = readOnly;
    this->onlyOneIpAllowed = onlyOneIpAllowed;

    server = new QTcpServer(this);
    // In Qt4, QHostAddress::Any listens for IPv4 connections only, but as of
    // Qt5, it now listens on all available interfaces, and
    // QHostAddress::AnyIPv4 needs to be used if we want only IPv4 connections.
#if QT_VERSION >= 0x050000
    server->listen(QHostAddress::AnyIPv4, port);
#else
    server->listen(QHostAddress::Any, port);
#endif
    connect(server, SIGNAL(newConnection()), this, SLOT(startNewControlConnection()));
}

bool FtpServer::isListening()
{
    return server->isListening();
}
//未被使用
QString FtpServer::lanIp()
{
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)) {
            return address.toString();
        }
    }
    return "";
}

/**
 * 启动NewControl连接
 * @brief FtpServer::startNewControlConnection
 */
void FtpServer::startNewControlConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    // If this is not a previously encountered IP emit the newPeerIp signal.
    QString peerIp = socket->peerAddress().toString();
    qDebug() << "connection from" << peerIp;
    if (!encounteredIps.contains(peerIp)) {
        // If we don't allow more than one IP for the client, we close
        // that connection.
        if (onlyOneIpAllowed && !encounteredIps.isEmpty()) {
            delete socket;
            return;
        }
        emit newPeerIp(peerIp);//这个再ftpserverwidget中未被实现
        encounteredIps.insert(peerIp);
    }

    // Create a new FTP control connection on this socket.
    // 来一个socket连接就创建一个对象来跟这个socket进行通信
    new FtpControlConnection(this, socket, rootPath, userName, password, readOnly);
}
