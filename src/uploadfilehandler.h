#ifndef UPLOADFILEHANDLER_H
#define UPLOADFILEHANDLER_H

#include "ftpconfig.h"

#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSettings>

class UploadFileHandler : public QObject
{
    Q_OBJECT
public:

    explicit UploadFileHandler(QObject *parent = nullptr);
    ~UploadFileHandler();

    QNetworkAccessManager *manager;

    QUrl getUrl() const;
    void setUrl(const QUrl &value);

    QString getUploadPath() const;
    void setUploadPath(const QString &value);

    // 连接是否成功
    bool isConnected();

signals:

public slots:

    // 文件名(绝对路径)传参
    void uploadFile(QString filePath);





    void onUploadFinished();

    void onErrorOccur(QNetworkReply::NetworkError error);

private:
    QUrl url;
    QString uploadPath;
    FTPConfig *ftpconfig;

    void init();
    // put请求
    QNetworkReply *put(const QString &localPath, const QString &uploadPath);

};

#endif // UPLOADFILEHANDLER_H
