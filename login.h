#ifndef LOGIN_H
#define LOGIN_H

#include "bcimysql.h"
#include "register.h"
#include "register_info.h"
#include "jsonoperation.h"



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

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();




private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_land_clicked();

private:
    Ui::login *ui;

    //拖拽窗口函数
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //mysql
    BciMysql *bcimysql=new BciMysql(this);
    void initMysql();

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
    QJsonArray *json;


};
#endif // LOGIN_H
