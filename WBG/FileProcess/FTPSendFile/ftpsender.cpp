#include "ftpsender.h"

#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QFile>
#include <QTimer>
#include <QDir>
#include <QFileSystemWatcher>

FTPSender::FTPSender(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer;
    timer->setInterval(3000);
    fileQueue = new QQueue<QString>;
    watcher = new QFileSystemWatcher;

//    qDebug() << "ftp";
    url.setScheme("ftp");

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(onDirectoryChanged(QString)));

    connect(this, SIGNAL(fileEnqueue(QString)), this, SLOT(onFileEnqueue(QString)));
    connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(onFileChanged(QString)));
}

FTPSender::~FTPSender()
{
    fileQueue->clear();
    currentDirSet.clear();
}

// 这样实现是为了防止覆盖
void FTPSender::setUrl(QUrl qurl)
{
    this->setHost(qurl.host());
    this->setPort(qurl.port());
    this->setUserName(qurl.userName());
    this->setPassWord(qurl.password());
    this->setPath(qurl.path());
    this->setScheme(qurl.scheme());
}

void FTPSender::setLocalPath(QString locPath)
{
    this->localPath = locPath;
    watcher->addPath(locPath);
//    qDebug() << this->localPath;
    enQueueFiles();
}

void FTPSender::startUploading()
{
    if(!url.isValid() || url.scheme() != "ftp"){
        qDebug() << "URL不合法！";
        return;
    }

    timer->start();
}


void FTPSender::onUploadFinished()
{
    qDebug() << "上传成功！";
}

void FTPSender::onErrorOccur(QNetworkReply::NetworkError error)
{
    qDebug() << "上传失败！" << error;
}

void FTPSender::onDirectoryChanged(QString fileName)
{
    // 检查有无新文件
    qDebug() << fileName;
    QDir dir;
    dir.setPath(fileName);
    dir.setFilter(QDir::Files);
    QStringList nameFilter;
    nameFilter << extension;
    QStringList list = dir.entryList(nameFilter);

    QSet<QString> newDirSet = QSet<QString>::fromList(list);

    QSet<QString> newFiles = newDirSet - this->currentDirSet;
    QStringList newFileList = newFiles.toList();

    foreach (QString str, newFileList) {
//        qDebug() << "enqueue:" << str;
        //        this->fileQueue->enqueue(dir.absoluteFilePath(str));
        this->fileQueue->enqueue(str);
        emit fileEnqueue(str);
    }

    this->currentDirSet = newDirSet;
}

void FTPSender::onFileChanged(QString fileName)
{
//    qDebug() << "onFileChanged:" << fileName;   // fileName是文件路径
    QString name = fileName.split("/").last();  // 文件名字

    fileQueue->enqueue(name);
    watcher->removePath(fileName);
}

void FTPSender::onTimeOut()
{
    if(!fileQueue->isEmpty()){  // 队列不为空
        this->timer->stop();
        while(!fileQueue->isEmpty()){
            QString fileName = fileQueue->dequeue();

            QString locPth = this->localPath + QString("/%1").arg(fileName);
            QString upPth = this->uploadPath + QString("/%1").arg(fileName);
//            qDebug() << "locPth:" << locPth;
//            qDebug() << "upPth:" << upPth;
            put(locPth, upPth);

        }
        this->timer->start();
    }else{  // 队列为空
        //        qDebug() << "onTimeOut";
    }
}

void FTPSender::onFileEnqueue(QString name)
{
    QString filePath = localPath + QString("/%1").arg(name);
//    qDebug() << "onFileEnqueue:" << filePath;
    watcher->addPath(filePath);
}

QNetworkReply *FTPSender::put(const QString &localPath, const QString &uploadPath)
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

    manager.setNetworkAccessible(QNetworkAccessManager::Accessible);

    QNetworkRequest request(url);
    QNetworkReply *reply = manager.put(request, file->readAll());

    connect(reply, SIGNAL(finished()), this, SLOT(onUploadFinished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onErrorOccur(QNetworkReply::NetworkError)));

    file->close();
    return reply;
}


void FTPSender::enQueueFiles()
{
    fileQueue->clear();

    QDir dir;
    dir.setPath(this->localPath);
    dir.setFilter(QDir::Files);
    QStringList nameFilter;
    nameFilter << extension;
    QStringList list = dir.entryList(nameFilter);

    currentDirSet = QSet<QString>::fromList(list);

    foreach (QString str, list) {
        //        fileQueue->enqueue(dir.absoluteFilePath(str));
        fileQueue->enqueue(str);
        qDebug() << str;
    }
}
