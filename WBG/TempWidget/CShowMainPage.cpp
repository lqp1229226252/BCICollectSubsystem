#include "CShowMainPage.h"
#include "ui_CShowMainPage.h"
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
CShowMainPage::CShowMainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CShowMainPage)
  ,m_pPicturePlayer(nullptr)
  ,m_pNavigationBar(nullptr)
  ,m_pBoder(nullptr)
  ,m_pAboutPage(nullptr)
  ,m_pShopPage(nullptr)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_TranslucentBackground);
    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowStaysOnTopHint);

    m_pPlayer = new CPlayVideo(this);
    ui->Layout_showVideo->addWidget(m_pPlayer);

    m_pPicturePlayer = new MPicturePlayer(this);
    //m_pPicturePlayer = new CPlayPicture(this);
    ui->verticalLayout_pic->addWidget(m_pPicturePlayer);

    m_pNavigationBar =  new CNavigationBar(this);
    connect(m_pNavigationBar,&CNavigationBar::signal_close,this,&CShowMainPage::slot_navigationBarClose);
    connect(m_pNavigationBar,&CNavigationBar::signal_show_index,this,&CShowMainPage::slot_show_index);
    ui->horizontalLayout_bar->addWidget(m_pNavigationBar);

    //关于我的
    m_pAboutPage = new CAboutMe(this);
    ui->verticalLayout_about->addWidget(m_pAboutPage);

    m_pShopPage =new CShopPage(this);
    ui->verticalLayout_shop->addWidget(m_pShopPage);


    m_pPicturePlayer->setFirsrt();
    on_btn_head_show_clicked();
    setProductList();
    setFuncList();
    ui->stackedWidget->setCurrentIndex(0);
}

CShowMainPage::~CShowMainPage()
{
    delete ui;
}
void CShowMainPage::setFuncList()
{
    for (int i=0;i<2 ;i++ ) {
        CFuncDetial* pFunDetail = new CFuncDetial(this);
        ui->gridLayout_funlist->addWidget(pFunDetail,i,0);
        CFuncDetial* pFunDetail2 = new CFuncDetial(this);
        ui->gridLayout_funlist->addWidget(pFunDetail2,i,1);
    }
}
void  CShowMainPage::setUSerInfo(const QString &qsData)
{

}
void CShowMainPage::setProductList()
{
    //设置产品
    for (int i=0;i<4 ;i++ ) {
        CProduct * ptempProduct = new CProduct(this);
        ui->verticalLayout_productList->addWidget(ptempProduct);
    }

}
void CShowMainPage::on_btn_head_show_clicked()
{
    setCurrentButton(0);
}

void CShowMainPage::on_btn_show_view_clicked()
{
    setCurrentButton(1);
}

void CShowMainPage::on_btn_other_video_clicked()
{
   setCurrentButton(2);
}
void CShowMainPage::setCurrentButton(int iDex)
{
    QString qspath="";
    switch (iDex) {
    case 0:
        qspath = QCoreApplication::applicationDirPath()+"/"+"head_video.mp4";
        m_pPlayer->openMedia(qspath);
        ui->btn_head_show->setChecked(true);
        ui->btn_other_video->setChecked(false);
        ui->btn_show_view->setChecked(false);
        break;
    case 1:
        qspath = QCoreApplication::applicationDirPath()+"/"+"control_video.mp4";
        m_pPlayer->openMedia(qspath);
        ui->btn_head_show->setChecked(false);
        ui->btn_other_video->setChecked(false);
        ui->btn_show_view->setChecked(true);
        break;
    case 2:
        ui->btn_head_show->setChecked(false);
        ui->btn_other_video->setChecked(true);
        ui->btn_show_view->setChecked(false);
        break;

    }

}

void CShowMainPage::on_btn_info_clicked()
{
    CUserSignPage* signpage = new CUserSignPage(this);
    if(signpage->exec()==QDialog::Accepted)
    {

    }
    delete signpage;
    signpage=nullptr;
}
void CShowMainPage::slot_navigationBarClose()
{
    close();
}
void CShowMainPage::slot_show_index(int idex)
{
    ui->stackedWidget->setCurrentIndex(idex);
}

