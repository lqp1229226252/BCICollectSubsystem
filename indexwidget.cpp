#include "indexwidget.h"
#include "ui_indexwidget.h"
#include "QIcon"
#include "QDebug"
IndexWidget::IndexWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IndexWidget)
{
    ui->setupUi(this);
    init();
}

IndexWidget::~IndexWidget()
{
    delete ui;
}
void IndexWidget::init()
{
    lastIndex=0;
    //初始化指针
    this->tabBar=new QTabBar();
    this->widget=new QStackedWidget();
    //设置布局
    ui->tabs->addWidget(tabBar);
    ui->verticalLayout->addWidget(widget);

    //初始化选项卡
    this->tabBar->addTab("上一页");

    //设置最大化最小化图标
    ui->min->setIcon(QIcon("./image/min.png"));
    ui->max->setIcon(QIcon("./image/max.png"));
    ui->close->setIcon(QIcon("./image/close.png"));
//    setStyle();
//    //信号链接
    connect(this->tabBar,&QTabBar::tabBarClicked,this,&IndexWidget::tabClickSlot);
}

void IndexWidget::setStyle()
{
}

void IndexWidget::minMax()
{

}

void IndexWidget::addWidget(QString name, QWidget *widget)
{
    this->tabBar->addTab(name);
    this->widget->addWidget(widget);
}

void IndexWidget::tabClickSlot(int index)
{
    if(this->widget->count()==0)
    {
        return;
    }
    if(index==0)
    {
        this->widget->setCurrentIndex(lastIndex);
        this->tabBar->setCurrentIndex(lastIndex+1);
    }
    else
    {
        this->lastIndex=this->widget->currentIndex();
        this->widget->setCurrentIndex(index-1);
    }
}



void IndexWidget::on_min_clicked()
{
    emit minSingal();
}

void IndexWidget::on_max_clicked()
{
    emit maxSingal();
}

void IndexWidget::on_close_clicked()
{
    QCoreApplication::quit();
}
