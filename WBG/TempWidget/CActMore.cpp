#include "CActMore.h"
#include "ui_CActMore.h"

CActMore::CActMore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CActMore)
{
    ui->setupUi(this);
}

CActMore::~CActMore()
{
    delete ui;
}
