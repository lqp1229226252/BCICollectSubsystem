#include "CShowBorder.h"
#include "ui_CShowBorder.h"

CShowBorder::CShowBorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CShowBorder)
{
    ui->setupUi(this);
}

CShowBorder::~CShowBorder()
{
    delete ui;
}
