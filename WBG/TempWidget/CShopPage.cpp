#include "CShopPage.h"
#include "ui_CShopPage.h"
#include "CLastNewItem.h"
#include "CActMore.h"
#include "CRecenePlayingItem.h"

CShopPage::CShopPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CShopPage)
  ,m_pPicurePlay(nullptr)
{
    ui->setupUi(this);
    m_pPicurePlay = new MPicturePlayer(ui->widget_main_logo);
    m_pPicurePlay->setAutoRun();
    //ui->verticalLayout_pic->addWidget(m_pPicurePlay);
    setText();
}

CShopPage::~CShopPage()
{
    delete ui;
}

void CShopPage::setText()
{
    for (int i=0;i<20 ;i++ ) {
       CLastNewItem* plastnew = new CLastNewItem(this);
       ui->horizontalLayout_new->addWidget(plastnew);
    }
    for (int i=0;i<20 ;i++ ) {
       CRecenePlayingItem* prplaying = new CRecenePlayingItem(this);
       ui->verticalLayout_playing->addWidget(prplaying);
    }
    for (int i=0;i<20 ;i++ ) {
       CActMore* pmore = new CActMore(this);
       ui->verticalLayout_more->addWidget(pmore);
    }
    for (int i=0;i<20 ;i++ ) {
       CActMore* pact = new CActMore(this);
       ui->verticalLayout_free->addWidget(pact);
    }

}
