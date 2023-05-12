#ifndef UPLOADFILEFTP_H
#define UPLOADFILEFTP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>

class UploadFileFTP : public QObject
{
    Q_OBJECT
public:
    explicit UploadFileFTP(QObject *parent = nullptr);
    ~UploadFileFTP();

    void SetURL(const QString host,const int port,const QString UserName,const QString Password,const QString RemotePath);

    QNetworkReply *put(const QString localPath, const QString uploadPath);



    //通过文件名上传，调用这个函数就行，前提是用该类当中的服务器信息配置好。
    void uploadFileByName(const QString fileName);



    QString getFileName(const QString fileName);

    // 这个函数是设置服务器相关信息的，包括IP地址，端口号等
    // uploadPth:上传到服务器的地址,格式: '/temp'或'/'
    void setServerInfo(const QString ip, int port, const QString userName, const QString pwd, const QString uploadPth);

public slots:
    void onUploadFinished();
    void onError(QNetworkReply::NetworkError error);

signals:

private:
    QUrl url;
    QNetworkAccessManager manager;
    QString uploadPth;

};

#endif // UPLOADFILEFTP_H
