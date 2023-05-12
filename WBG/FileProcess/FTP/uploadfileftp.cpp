#include "uploadfileftp.h"
#include <QFile>



UploadFileFTP::UploadFileFTP(QObject *parent) : QObject(parent)
{
//    SetURL("10.23.66.17",21,"yw","yw","/");
}

UploadFileFTP::~UploadFileFTP()
{

}

// 测试用
void UploadFileFTP::SetURL(const QString host,const int port,const QString UserName,const QString Password,const QString RemotePath)
{
    url.setHost(host);
    url.setPort(21);
    url.setUserName(UserName);
    url.setPassword(Password);
    url.setScheme("ftp");
    this->uploadPth = RemotePath;
//    url.setPath(uploadPth);
}

// localPath文件的绝对路径
// uploadPath服务器的存放路径,格式：/temp/a.txt或/a.txt
QNetworkReply *UploadFileFTP::put(const QString localPath, const QString uploadPath)
{
    QFile file(localPath);
    if(!file.open(QIODevice::ReadOnly))
        return NULL;
    url.setPath(uploadPath);

    qDebug() << url;
    QByteArray fileBytes = file.readAll();

    QString fileName = getFileName(localPath);

    QNetworkRequest request(url);

    request.setRawHeader("STOR", qPrintable(fileName));
    this->manager.setNetworkAccessible(QNetworkAccessManager::Accessible);

    QNetworkReply *reply = manager.put(request, fileBytes);
    connect(reply, SIGNAL(finished()), SLOT(onUploadFinished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(onError(QNetworkReply::NetworkError)));

    return reply;
}

// fileName : 文件绝对路径
void UploadFileFTP::uploadFileByName(const QString fileName)
{

    QString path = this->uploadPth + QString("/%1").arg(getFileName(fileName));
    put(fileName, path);

}

QString UploadFileFTP::getFileName(const QString fileName)
{
    QString filename = fileName.split("/").last();
    return filename;
}

void UploadFileFTP::setServerInfo(QString ip, int port, QString userName, QString pwd, QString path)
{
    url.setScheme("ftp");
    url.setHost(ip);
    url.setPort(port);
    url.setUserName(userName);
    url.setPassword(pwd);

    this->uploadPth = path;

}

void UploadFileFTP::onUploadFinished()
{
    qDebug() << "upload Finished!";
}

void UploadFileFTP::onError(QNetworkReply::NetworkError error)
{
    qDebug() << error;
}

