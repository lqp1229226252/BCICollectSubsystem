#include "ftpconfig.h"
#include <QSettings>

FTPConfig::FTPConfig(QObject *parent) : QObject(parent)
{
    init();
}

FTPConfig::~FTPConfig()
{

}

QUrl FTPConfig::getFTPConfig()
{
    QUrl url;
    url.setHost(settings->value("SERVERINFO/HostName").toString());
    url.setPort(settings->value("SERVERINFO/Port").toInt());
    url.setPath(settings->value("SERVERINFO/Path").toString());

    url.setScheme(settings->value("PROTOCOL/scheme").toString());

    url.setUserName(settings->value("USERINFO/UserName").toString());
    url.setPassword(settings->value("USERINFO/Password").toString());

    return url;

}

void FTPConfig::setFTpConfig(QUrl url)
{
    settings->setValue("SERVERINFO/HostName", url.host());
    settings->setValue("SERVERINFO/Port", url.port());
    settings->setValue("SERVERINFO/Path", url.path());

    settings->setValue("PROTOCOL/scheme", url.scheme());

    settings->setValue("USERINFO/UserName", url.userName());
    settings->setValue("USERINFO/Password", url.password());

}



void FTPConfig::init()
{
    settings = new QSettings("FTPConfigration.ini", QSettings::IniFormat);
}
