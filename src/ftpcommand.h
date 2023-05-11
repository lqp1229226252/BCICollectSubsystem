#ifndef FTPCOMMAND_H
#define FTPCOMMAND_H

#include <QObject>

class QTcpSocket;

// The base class for all FTP commands that need a data connection.
// 纯虚类，其子类有ftp-stor-command(上传到服务器)、ftp-retr-command(从服务器下载文件)、
//              ftp-list-command(显示文件，类似linux中的ls命令，也能解析ls -l)
class FtpCommand : public QObject
{
    Q_OBJECT
public:
    explicit FtpCommand(QObject *parent = 0);

signals:
    void reply(const QString &details);

public:
    void start(QTcpSocket *socket);

protected:
    virtual void startImplementation() = 0;
    QTcpSocket* socket;
    bool started;
};

#endif // FTPCOMMAND_H
