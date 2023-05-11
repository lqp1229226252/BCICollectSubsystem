
#include "ftpserverwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //FTP服务器
    FtpServerWidget ftpWidget;
    if(ftpWidget.LoadIni()==-1){
        QString path = "D:/BCIData/FTP-Receive";
        ftpWidget.set_ftp_para("127.0.0.1","21","demo","demo",path);
    }
    else{
        ftpWidget.set_ftp_para(ftpWidget.ftpinfo.ip,ftpWidget.ftpinfo.port,ftpWidget.ftpinfo.username,
                               ftpWidget.ftpinfo.password,ftpWidget.ftpinfo.filepath);
    }

    ftpWidget.show();
    return a.exec();
}
