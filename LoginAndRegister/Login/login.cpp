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



    initInfo();

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
         QMessageBox *box = new QMessageBox(QMessageBox::Information,"connect-mysql","link failed!");
         QTimer::singleShot(1000,box,SLOT(accept()));
         box->exec();

    });

    connect(bcimysql,&BciMysql::connectSuce,this,[=](){
         QMessageBox *box = new QMessageBox(QMessageBox::Information,"connect-mysql","link succeed!");
         QTimer::singleShot(1000,box,SLOT(accept()));
         box->exec();

    });

    connect(bcimysql,&BciMysql::registerSuccess,this,[=](){
        //注册成功后,进入用户信息编辑页面,开始编辑个人信息
        QString account = register_1->SendAccount(); //获取注册用户的账号
        register_1->close();  //关闭注册页面
        register_info = new Register_info;
        register_info->getAccount(account);  //发送用户账户给注册信息
        register_info->show();

        connect(register_info,&Register_info::sendRegisterInfo,bcimysql,&BciMysql::SaveRegisterInfo);
    });

}

void login::initInfo()
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    file.close();
    QJsonObject obj= jdc.object();
    QStringList keys = obj.keys();
//    qDebug()<<obj;
//    qDebug()<<keys;
    //将历史账号加载到combox里
    for (int i = 0 ;i< keys.size()-3;i++){
//        qDebug()<<"====";
        ui->comboBox_account->addItem(keys[i]);
    }
    //设置自动登录、保存密码的状态和上一次登录的账号设置到账号和密码栏里
    ui->comboBox_account->setCurrentText(obj.value("lastAccount").toString());
    ui->checkBox_autoLand->setChecked(obj.value("isAutoLand").toInt());
    ui->checkBox_savePassword->setChecked(obj.value("isSavePassword").toInt());
    ui->lineEdit_account->setText(obj.value("lastAccount").toString());
    ui->lineEdit_password->setText(obj.value(
                                       obj.value("lastAccount").toString()
                                       ).toString());

    //更换账号时的出发函数
    connect(ui->comboBox_account,&QComboBox::currentTextChanged,this,[=](){
        ui->lineEdit_account->setText(keys[ui->comboBox_account->currentIndex()]);
        ui->lineEdit_password->setText(obj.value(
                                           keys[ui->comboBox_account->currentIndex()]
                                       ).toString());
        ui->checkBox_autoLand->setChecked(false);
        ui->checkBox_savePassword->setChecked(false);
    });

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
//   **********注释部分转到jsonoperation去操作了   从这开始**************
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
//  **********注释部分转到jsonoperation去操作了  到此结束**************

    //点击登录槽
    int anser  =  bcimysql->login(ui->lineEdit_account->text(),ui->lineEdit_password->text());
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
        delete jsonOperation; //删除json操作指针
        //发出登录成功的信号  进入wgb页面的显示
        emit LoginSucceedSignal(account);  //告知显示界面显示的账号account
        this->close();
    }
    else{
//        //验证失败

        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,"Password error","Password error");
        QTimer::singleShot(1000,m_box,SLOT(accept()));
        m_box->exec();

    }
}

void login::on_pushButton_QRCode_clicked()
{
    showQRCodeLogin("WBG");
}

void login::on_pushButton_qq_clicked()
{
    showQRCodeLogin("qq");
}

void login::on_pushButton_wechart_clicked()
{
    showQRCodeLogin("wx");
}

void login::showQRCodeLogin(QString type_login)
{
    QRCodeLoginWidget *qrCodeLogin=new QRCodeLoginWidget;
    qrCodeLogin->showQRCodeLogin(type_login);

}

