#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QScreen>
#include <QVariant>
#include <QSettings>
#include <QFileDialog>
#include <QCommandLineParser>
#include "CProduct.h"
#include "CFuncDetial.h"
#include "CUserSignPage.h"
#include "CShowBorder.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_pPlayer(nullptr)
    ,m_pPicturePlayer(nullptr)
    ,m_pNavigationBar(nullptr)
    ,m_pBoder(nullptr)
    ,m_pAboutPage(nullptr)
    ,m_pShopPage(nullptr)
    ,m_pViewDataPage(nullptr)

{
    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);
    //this->setWindowFlags(Qt::FramelessWindowHint);

    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowStaysOnTopHint);

    ui->menubar->hide();
    ui->statusbar->hide();

    m_pPlayer = new CPlayVideo(this);
    ui->Layout_showVideo->addWidget(m_pPlayer);

    m_pPicturePlayer = new MPicturePlayer(this);
    ui->verticalLayout_pic->addWidget(m_pPicturePlayer);

//    m_pNavigationBar =  new CNavigationBar(this);
//    connect(m_pNavigationBar,&CNavigationBar::signal_close,this,&MainWindow::slot_navigationBarClose);
//    connect(m_pNavigationBar,&CNavigationBar::signal_show_index,this,&MainWindow::slot_show_index);
    //ui->horizontalLayout_bar->addWidget(m_pNavigationBar);
    ui->widget_title_bar->hide();
    //关于我的
    m_pAboutPage = new CAboutMe(this);
    ui->verticalLayout_about->addWidget(m_pAboutPage);

    m_pShopPage =new CShopPage(this);
    ui->verticalLayout_shop->addWidget(m_pShopPage);

    m_pViewDataPage = new CViewDataPage(this);
    ui->verticalLayout_view->addWidget(m_pViewDataPage);


    m_pPicturePlayer->setFirsrt();
    on_btn_head_show_clicked();
    setProductList();
    setFuncList();
    ui->stackedWidget->setCurrentIndex(0);
    m_pPicturePlayer->setFirsrt();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showEvent(QShowEvent *event)
{
//     QPoint p = mapToGlobal(ui->widget_play_video->pos());
//    m_pPlayer->setGeometry(p.x(),p.y()+80,ui->widget_play_video->width(),ui->widget_play_video->height());
//    m_pPlayer->show();
}
void MainWindow::setFuncList()
{
    for (int i=0;i<2 ;i++ ) {
        CFuncDetial* pFunDetail = new CFuncDetial(this);
        ui->gridLayout_funlist->addWidget(pFunDetail,i,0);
        CFuncDetial* pFunDetail2 = new CFuncDetial(this);
        ui->gridLayout_funlist->addWidget(pFunDetail2,i,1);
    }
}
void  MainWindow::setUSerInfo(const QString &qsData)
{

}
void MainWindow::setProductList()
{
    //设置产品
    for (int i=0;i<4 ;i++ ) {
        CProduct * ptempProduct = new CProduct(this);
        ui->verticalLayout_productList->addWidget(ptempProduct);
    }

}
void MainWindow::on_btn_head_show_clicked()
{

    setCurrentButton(0);
}

void MainWindow::on_btn_show_view_clicked()
{
    setCurrentButton(1);
}

void MainWindow::on_btn_other_video_clicked()
{
   setCurrentButton(2);
}
void MainWindow::setCurrentButton(int iDex)
{
    QString qspath="";
    switch (iDex) {
    case 0:
        qspath = QCoreApplication::applicationDirPath()+"/"+"head_video.mp4";
        m_pPlayer->openMedia(qspath);
//        ui->btn_head_show->setChecked(true);
//        ui->btn_other_video->setChecked(false);
//        ui->btn_show_view->setChecked(false);
        break;
    case 1:
        qspath = QCoreApplication::applicationDirPath()+"/"+"control_video.mp4";
        m_pPlayer->openMedia(qspath);
//        ui->btn_head_show->setChecked(false);
//        ui->btn_other_video->setChecked(false);
//        ui->btn_show_view->setChecked(true);
        break;
    case 2:
//        ui->btn_head_show->setChecked(false);
//        ui->btn_other_video->setChecked(true);
//        ui->btn_show_view->setChecked(false);
        break;

    }

}

void MainWindow::on_btn_info_clicked()
{
    CUserSignPage* signpage = new CUserSignPage(this);
    if(signpage->exec()==QDialog::Accepted)
    {

    }
    delete signpage;
    signpage=nullptr;
}
void MainWindow::slot_navigationBarClose()
{
    close();
}
void MainWindow::slot_show_index(int idex)
{
    ui->stackedWidget->setCurrentIndex(idex);
}
