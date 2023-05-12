#include "bcimysql.h"

#include <QMessageBox>
#include <QTimer>


BciMysql::BciMysql(QObject *parent) : QObject(parent)
{
    initMysql();  //进来就先初始化数据库配置内容
}

void BciMysql::initMysql()
{
    //连接mysql数据库
    db = QSqlDatabase::addDatabase("QMYSQL"); //创建数据库连接
    db.setHostName("47.109.75.201");    // 主机服务器
    db.setPort(3306);
    db.setDatabaseName("WGB");
    db.setUserName("wgb");
    db.setPassword("wgb!@#QAZ123");
    if (db.open()){ //连接并判断数据库是否连接成功
        emit connectSuce();
        qDebug()<<"connect-mysql success!";

    }else{
        emit connectFail();
        qDebug()<<"error open database because"<<db.lastError();
    }
}

int BciMysql::login(QString account, QString password)
{
    //登录验证过程
    QSqlQuery query_login(db);
    //    QString qs=QString("select * from user where account='%1' and password='%2'").arg(account).arg(password);
    QString qs =QString("call login('%1','%2')").arg(account).arg(password);
    query_login.exec(qs); // 打印出来是否执行了语句
    query_login.next();
    return query_login.value(0).toInt();  // select result,account_id;所以写0
}

int BciMysql::registerUser(QString phone,QString password)
{
    //注册验证过程
//    qDebug()<<"BciMysql::registerUser"<<phone<<password;  //成功接收到的手机号和密码
    QSqlQuery query_register(db);
    QString qs=QString("call registered('%1','%2')").arg(phone).arg(password);
    query_register.exec(qs);
    query_register.next();

    if( query_register.value(0).toInt() ){
        //如果注册成功，就发送注册成功信号，触发函数展示出设置用户信息页面
        emit registerSuccess();
    }
    else{
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,"注册号码重复","此号码账号已存在");
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->exec();
    }
    return 0;
}

int BciMysql::SaveRegisterInfo(QString qs)
{
    qDebug()<<"BciMysql::SaveRegisterInfo";
    QSqlQuery query_login(db);
    query_login.exec(qs); // 执行sql语句（保存注册的用户信息，根据account来完成）
    return 0;
}




