#include "uploadfilehandler.h"
#include "ftpconfig.h"

#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

UploadFileHandler::UploadFileHandler(QObject *parent) : QObject(parent)
{
    init();
}

UploadFileHandler::~UploadFileHandler()
{
    manager->deleteLater();
}

void UploadFileHandler::init()
{
    manager = new QNetworkAccessManager;
    ftpconfig = new FTPConfig;

    // 读配置文件
    this->url = ftpconfig->getFTPConfig();
}

// 上传文件
void UploadFileHandler::uploadFile(QString filePath)
{
    QString fileName = filePath.split("/").last();

    QString upPth = this->uploadPath + QString("/%1").arg(fileName);

    put(filePath, upPth);
}

// 上传完成
void UploadFileHandler::onUploadFinished()
{
    qDebug() << "upload Finished!";
}

QString UploadFileHandler::getUploadPath() const
{
    return uploadPath;
}


void UploadFileHandler::onErrorOccur(QNetworkReply::NetworkError error)
{
    qDebug() << error;
}


// 上传
QNetworkReply *UploadFileHandler::put(const QString &localPath, const QString &uploadPath)
{
    // 打开文件指针
    QFile *file = new QFile;
    file->setFileName(localPath);

    if(!file->open(QIODevice::ReadOnly)){
        return NULL;
    }

    // 设置上传路径
    url.setPath(uploadPath);

    //    qDebug() <<"uploadPath:" << uploadPath;

    QStringList strList = uploadPath.split("/");
    QString filename = strList.last();


    qDebug() << url;

    manager->setNetworkAccessible(QNetworkAccessManager::Accessible);


    QNetworkRequest request(url);
    QNetworkReply *reply = manager->put(request, file->readAll());

    connect(reply, SIGNAL(finished()), this, SLOT(onUploadFinished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onErrorOccur(QNetworkReply::NetworkError)));

    reply->deleteLater();

    file->close();
    return reply;
}

// 设置上传到服务器的目录
void UploadFileHandler::setUploadPath(const QString &value)
{
    uploadPath = value;
}

bool UploadFileHandler::isConnected()
{
    bool isCon;

    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [&](){
        if(reply->error() == QNetworkReply::NoError){
            qDebug() << "connection successful!";
            isCon = true;
        }else{
            qDebug() << "connection fail!" << reply->errorString();
            isCon = false;
        }
    });

    reply->deleteLater();

    return isCon;
}

QUrl UploadFileHandler::getUrl() const
{
    return url;
}

void UploadFileHandler::setUrl(const QUrl &value)
{
    url = value;
    this->uploadPath = value.path();

    ftpconfig->setFTpConfig(url);
}
