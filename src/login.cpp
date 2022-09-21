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

void login::on_pushButton_register_clicked()
{
    Register *register_1 = new Register;
    register_1->show();
    this->close();
    connect(register_1,&Register::close_register,this,[=](){
        this->show();
    });
}

void login::on_pushButton_close_clicked()
{
    this->close();
}

void login::on_pushButton_min_clicked()
{
    //最小化窗口
    this->showMinimized();
}

void login::on_pushButton_land_clicked()
{
    emit login_success();
}
