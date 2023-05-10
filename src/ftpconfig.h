#ifndef FTPCONFIG_H
#define FTPCONFIG_H

#include <QObject>
#include <QSettings>
#include <QUrl>

class FTPConfig : public QObject
{
    Q_OBJECT
public:
    explicit FTPConfig(QObject *parent = nullptr);
    virtual~FTPConfig();

    //读取配置文件
    QUrl getFTPConfig();

    //写入配置文件
    void setFTpConfig(QUrl);

signals:

private:

    QSettings *settings;

    void init();
};

#endif // FTPCONFIG_H
