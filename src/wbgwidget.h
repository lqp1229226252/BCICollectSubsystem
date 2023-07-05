#ifndef WBGWIDGET_H
#define WBGWIDGET_H

#include <QWidget>
#include "indexwidget.h"
#include "introducewidget.h"
#include "usergamewidget.h"
#include "personaldatawidget.h"
#include "store.h"
#include "start_game.h"
#include "bcimonitor.h"
#include <QApplication>
#include <QDebug>
#include <QWidget>
#include <QProcess>
#include <QWindow>
#include <Windows.h>
#include <QRect>
#include "QMouseEvent"

#include "Login.h"

#include "tcpserver.h"

#include "uploadfilehandler.h"

#include "savefiletobci.h"
#include "gameoverwidget.h"

#include "ftpserverwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WBGWIdget; }
QT_END_NAMESPACE

class WBGWIdget : public QWidget
{
    Q_OBJECT

public:
    WBGWIdget(QWidget *parent = nullptr);
    ~WBGWIdget();
    void initParams();
    void setConnect();
    void setLayout();
    void initIndexWidget();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public slots:
    void acceptGameAccount(QMap<QString,QString>);
private:
    Ui::WBGWIdget *ui;
    bool  move_flage;//窗口移动标志
    int last_mouse_x;    //上一次的鼠标x坐标
    int last_mouse_y;    //上一次的鼠标y坐标
    int isMaximized = 1;  //窗口启动既全屏

    IndexWidget *indexWidget;
    IntroduceWidget *introduceWidget;
    UserGameWidget *userGameWidget;
    PersonalDataWidget *personalDataWidget;
    Store *storeWidget;
    start_game *startGameWidget;
    //游戏结算页面
    GameOverWidget *gameoverwidget;
    void initGameEndWidget();
    void setGameEndWidgetConnect();
    //主页
//    MainWindow *mainwindow;

    //采集页面
    BCIMonitor *bcimonitor;
    void setMoniotrConnect();

    void initBCIMonitor(); //登录成功后初始化 mat保存路径

    Login *LoginWidget;



    void initUserGameWidget();

    void initStartGameWidget();


    //FTP服务端
    SaveFileToBCI * ftprevice;
    void initFTPRevice();
    void setFTPReviceConnect();

    //TCP服务
    TcpServer *tcpserver;
    void initTCP();
    void setTCPConnect();


    //FTP客户端
    //发送mat文件
    UploadFileHandler *handler;
    void initUploadFileHandler();


    //FTP服务器用于接收bci文件
    FtpServerWidget *ftpWidget;
    void initFTP();



    //mat文件保存路径
    QString saveMatPath;  //临时使用状态   ,麻烦确定后删除指定路径
    //登录成功后，传来的信息，用于显示：account，name用于接收
    QString account;
    QString name;
    //用户所玩游戏，用来接收用户所玩游戏的编号，  测试阶段默认为0；
    int game_id=0;    //临时使用状态   ,麻烦确定后删除默认值 

};
#endif // WBGWIDGET_H
