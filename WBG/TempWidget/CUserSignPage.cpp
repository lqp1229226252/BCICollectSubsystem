#include "CUserSignPage.h"
#include "ui_CUserSignPage.h"
#include "CSignInfo.h"
CUserSignPage::CUserSignPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CUserSignPage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);
    setText();
}

CUserSignPage::~CUserSignPage()
{
    delete ui;
}
void CUserSignPage::setText()
{

    CSignInfo* pTemp = new CSignInfo(this);
    pTemp->setTextInfo("姓名","大玩家");
    ui->verticalLayout_user->addWidget(pTemp);

    CSignInfo* pTemp2 = new CSignInfo(this);
    pTemp2->setTextInfo("年龄","3岁");
    ui->verticalLayout_user->addWidget(pTemp2);

    CSignInfo* pTemp3 = new CSignInfo(this);
    pTemp3->setTextInfo("名族","汉");
    ui->verticalLayout_user->addWidget(pTemp3);

    CSignInfo* pTemp4 = new CSignInfo(this);
    pTemp4->setTextInfo("性别","无性别");
    ui->verticalLayout_user->addWidget(pTemp4);

    CSignInfo* pTemp5 = new CSignInfo(this);
    pTemp5->setTextInfo("左右利手","右利手");

    ui->verticalLayout_exp->addWidget(pTemp5);

    CSignInfo* pTemp6 = new CSignInfo(this);
    pTemp6->setTextInfo("工作经历","无");
    ui->verticalLayout_exp->addWidget(pTemp6);

    CSignInfo* pTemp7 = new CSignInfo(this);
    pTemp7->setTextInfo("教育水平","再读");
    ui->verticalLayout_exp->addWidget(pTemp7);

    CSignInfo* pTemp8 = new CSignInfo(this);
    pTemp8->setTextInfo("联系电话","1345678888");
    ui->verticalLayout_exp->addWidget(pTemp8);

    CSignInfo* pTemp9 = new CSignInfo(this);
    pTemp9->setTextInfo("联系地址","m78星云");
    ui->verticalLayout_exp->addWidget(pTemp9);

    CSignInfo* pTemp10 = new CSignInfo(this);
    pTemp10->setTextInfo("身体健康状态","好");
    ui->verticalLayout_body->addWidget(pTemp10);

    CSignInfo* pTemp11 = new CSignInfo(this);
    pTemp11->setTextInfo("体育锻炼类型","打怪兽");
    ui->verticalLayout_body->addWidget(pTemp11);

    CSignInfo* pTemp12 = new CSignInfo(this);
    pTemp12->setTextInfo("常玩游戏（类型，名称）","无性别");
    ui->verticalLayout_body->addWidget(pTemp12);

    CSignInfo* pTemp13 = new CSignInfo(this);
    pTemp13->setTextInfo("日常娱乐方式","无性别");
    ui->verticalLayout_body->addWidget(pTemp13);

    CSignInfo* pTemp14 = new CSignInfo(this);
    pTemp14->setTextInfo("其他（允许方便扩展）","无性别");
    ui->verticalLayout_body->addWidget(pTemp14);
}

void CUserSignPage::on_btn_ok_clicked()
{
    accept();
}
