#include "login.h"
#include "ui_login.h"
#include "register.h"
#include <QDebug>


login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);



    //设置窗口不显示标题、不显示边框
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);

    initMysql();
}

login::~login()
{
    delete ui;
}


//拖拽操作
void login::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //mouseStartPoint = event->pos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}
void login::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //QPoint distance = event->pos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}
void login::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}

void login::initMysql()
{

    connect(bcimysql,&BciMysql::connectFail,this,[=](){
        QMessageBox::information(this,"connect-mysql","link failed!");
    });

    connect(bcimysql,&BciMysql::registerSuccess,this,[=](){
        //注册成功后,开始编辑个人信息
        QString account = register_1->SendAccount(); //获取注册用户的账号
        register_1->close();  //关闭注册页面
        register_info = new Register_info;
        register_info->getAccount(account);
        register_info->show();

        connect(register_info,&Register_info::sendRegisterInfo,bcimysql,&BciMysql::SaveRegisterInfo);
    });

}

void login::initInfo()
{

}

void login::on_pushButton_register_clicked()
{
    //点击注册槽
    register_1 = new Register;
    register_1->show();
    this->close();
    connect(register_1,&Register::close_register,this,[=](){
        this->show();
    });
    connect(register_1,&Register::sendRegister,bcimysql,&BciMysql::registerUser);


}

void login::on_pushButton_close_clicked()
{
    //点击关闭窗口
    this->close();
}

void login::on_pushButton_min_clicked()
{
    //点击最小化窗口
    this->showMinimized();
}

void login::on_pushButton_land_clicked()
{

//    QString filename = "userInfo.json";
//    QFile file(filename);
//    file.open(QIODevice::ReadOnly);

//    QString account = ui->lineEdit_account->text();
//    QString password= ui->lineEdit_password->text();
//    int isAutoLand = ui->checkBox_autoLand->isChecked();


//    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
//    file.close();

//    QJsonObject obj= jdc.object();


//    obj.insert("isAutoLand",isAutoLand); //0或1

//    obj.insert(account,password);
//    obj.insert("lastAccount",account);

//    QJsonDocument doc(obj);
//    QByteArray json=doc.toJson();
//    file.open(QFile::WriteOnly);
//    file.write(json);
//    file.close();

    //点击登录槽
//    int anser  =  bcimysql->login(ui->lineEdit_account->text(),ui->lineEdit_password->text());
    if(  bcimysql->login(ui->lineEdit_account->text(),ui->lineEdit_password->text())  ){
        //验证成功,关闭登录界面，进入wgb页面。
        QString account = ui->lineEdit_account->text();
        QString password= ui->lineEdit_password->text();
        int isAutoLand = ui->checkBox_autoLand->isChecked();
        int isSavePassword = ui->checkBox_savePassword->isChecked();

        JsonOperation *jsonOperation=new JsonOperation();
        jsonOperation->landID(account,password,isAutoLand
                              ,isSavePassword);
        Sleep(500);
        delete jsonOperation;
        //进入wgb页面的显示  后续加上

    }
    else{
//        //验证失败

        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,"Password error","Password error");
        QTimer::singleShot(1000,m_box,SLOT(accept()));
        m_box->exec();

    }
}
