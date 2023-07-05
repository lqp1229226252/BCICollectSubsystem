#ifndef Login_H
#define Login_H

//#include "bcimysql.h"
#include "register.h"
#include "register_info.h"
#include "jsonoperation.h"
#include "qrcodeLoginwidget.h"

#include <QWidget>
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <windows.h>

//#include "UserInfoStruct.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE


class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    int aaaa = 0;

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_land_clicked();

    void on_pushButton_QRCode_clicked();

    void on_pushButton_qq_clicked();

    void on_pushButton_wechart_clicked();

    void showQRCodeLogin(QString);

    void initParams();
    void initRegisterInfo();
    void ShowMessageBox(QString,QString);

signals:
    void LoginSucceedSignal(QString,QString);  //登录成功的信号



private:



    Ui::Login *ui;

    //拖拽窗口函数
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //register
    Register *register_1;

    //register_info
    Register_info *register_info;


    //拖拽窗口变量
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

    //初始化变量
    void initInfo();
    JsonOperation *jsonOperation;


};
#endif // Login_H
