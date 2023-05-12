#ifndef FTPSENDER_H
#define FTPSENDER_H

#include <QWidget>
#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QQueue>
#include <QFile>
#include <QFileSystemWatcher>
#include <QSet>
#include <QString>
#include <QTextCodec>

class FTPSender : public QWidget
{
    Q_OBJECT

public:
    FTPSender(QWidget *parent = nullptr);
    ~FTPSender();


    void setPort(int port) {if(port != -1) url.setPort(port);}  // 端口
    void setHost(const QString &host){if(host != "") url.setHost(host);}    // 服务器ip
    void setPath(const QString &path) {this->uploadPath = path;}  // 设置服务器存储的文件路径
    void setUserName(const QString &userName) {url.setUserName(userName);}  // 设置服务器用户名
    void setPassWord(const QString &password) {url.setPassword(password);}  // 设置密码
    void setScheme(const QString &scheme) {if(scheme != "") url.setScheme(scheme);}
    void setUrl(QUrl qurl);

    void setLocalPath(QString locPath);   // 设置本地文件目录

    // 开始上传
    void startUploading();

public slots:
    void onUploadFinished();
//    void onDownloadFinished();
    void onErrorOccur(QNetworkReply::NetworkError error);
//    void onUploadBtnClicked();
//    void onSetLocalPath() ;
//    void onStopBtnClicked();

    void onDirectoryChanged(QString);
    void onFileChanged(QString);

    void onTimeOut();

    void onFileEnqueue(QString name);

private:
    QUrl url;
    QString path;
    QString localPath;
    QString uploadPath;
    QString downloadPath;
    QString extension = "*.mat";  // 文件后缀

    bool isListening = false;

    QNetworkAccessManager manager;

    QTimer *timer ;
    //    QQueue<QFile*> fileQueue;
    QQueue<QString> *fileQueue;

    QSet<QString> currentDirSet;

    QFileSystemWatcher *watcher;

//    QTextCodec *codec = QTextCodec::codecForName("GB18030");

//    void init();

    // put请求
    QNetworkReply *put(const QString &localPath, const QString &uploadPath);
    // get请求
//    QNetworkReply *get(const QString &downloadPath, const QString &localPath);

    void enQueueFiles();

signals:
    void fileEnqueue(QString name);


};
#endif // FTPSENDER_H
