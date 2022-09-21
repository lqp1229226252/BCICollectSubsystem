#include "wbgwidget.h"
#include "ui_wbgwidget.h"
#include "QDebug"
#include "windows.h"
WBGWIdget::WBGWIdget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WBGWIdget)
{
    ui->setupUi(this);
    initParams();
    initIndexWidget();
    setLayout();
    setConnect();
    loginWidget->show();
    this->setWindowFlags(Qt::FramelessWindowHint);
}

WBGWIdget::~WBGWIdget()
{
    delete ui;
    delete indexWidget;
    delete introduceWidget;
    delete loginWidget;
}

void WBGWIdget::initParams()
{
    move_flage=false;//窗口移动标志初始化为Flase
    indexWidget=new IndexWidget();
    introduceWidget=new IntroduceWidget();
    loginWidget=new login();
}

void WBGWIdget::setConnect()
{
    connect(loginWidget,&login::login_success,this,&WBGWIdget::show);
}

void WBGWIdget::setLayout()
{
    ui->layout->addWidget(indexWidget);
}

void WBGWIdget::initIndexWidget()
{
    indexWidget->addWidget("主页",introduceWidget);

}

void WBGWIdget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
         if(event->y()<20)
         {
            move_flage=true;
            last_mouse_x=event->globalX();//获取鼠标开始移动的x坐标
            last_mouse_y=event->globalY();//获取鼠标开始移动的y坐标
         }

    }
}

void WBGWIdget::mouseMoveEvent(QMouseEvent *event)
{
    if(move_flage)
    {
        int widget_x=this->pos().x();//获取当前窗口x坐标
        int widget_y=this->pos().y();//获取当前窗口y坐标
        //获取此时的鼠标x,y坐标
        int mouse_x=event->globalX();
        int mouse_y=event->globalY();
//        qDebug()<<"global_x:"<<global_x;
//        qDebug()<<"global_y:"<<global_y;
//        qDebug()<<"x:"<<x;
//        qDebug()<<"y:"<<y;
//        qDebug()<<"move_x:"<<x-start_move_x;
//        qDebug()<<"move_y:"<<y-start_move_y;
        //计算鼠标移动的距离
        int move_x=mouse_x-last_mouse_x;
        int move_y=mouse_y-last_mouse_y;
        //移动窗口坐标
        this->move(widget_x+move_x,widget_y+move_y);
        //记录这次的鼠标位置，用于计算鼠标坐标的移动
        last_mouse_x=mouse_x;
        last_mouse_y=mouse_y;

    }
}

void WBGWIdget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        move_flage=false;
    }
}

