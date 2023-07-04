#include "CAboutMe.h"
#include "ui_CAboutMe.h"
#include "CGameItem.h"
#include "CGameUpdateItem.h"
#include "CGameViewItem.h"
#include "CNoticeItem.h"
#include "CPalyingItem.h"

CAboutMe::CAboutMe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CAboutMe)
{
    ui->setupUi(this);
    setText();
}

CAboutMe::~CAboutMe()
{
    delete ui;
}

void CAboutMe::setText()
{
    for (int i=0;i<20 ;i++ ) {
       CGameItem* pgameitem = new CGameItem(this);
       ui->verticalLayout_game_list->addWidget(pgameitem);
    }

    for (int i=0;i<20 ;i++ ) {
       CNoticeItem* pnotice = new CNoticeItem(this);
       ui->horizontalLayout_fabu->addWidget(pnotice);
    }

    for (int i=0;i<20 ;i++ ) {
       CGameUpdateItem* pupdate = new CGameUpdateItem(this);
       ui->verticalLayout_update->addWidget(pupdate);
    }
    for (int i=0;i<20 ;i++ ) {
       CPalyingItem* pplay = new CPalyingItem(this);
       ui->horizontalLayout_playing->addWidget(pplay);
    }

    for (int i=0;i<20 ;i++ ) {
       CGameViewItem* pgameview = new CGameViewItem(this);
       ui->verticalLayout_all_view->addWidget(pgameview);
    }

}
