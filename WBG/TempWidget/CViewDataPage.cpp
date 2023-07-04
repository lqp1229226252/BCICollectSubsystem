#include "CViewDataPage.h"
#include "ui_CViewDataPage.h"

CViewDataPage::CViewDataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CViewDataPage)
{
    ui->setupUi(this);
}

CViewDataPage::~CViewDataPage()
{
    delete ui;
}
