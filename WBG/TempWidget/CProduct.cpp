#include "CProduct.h"
#include "ui_CProduct.h"

CProduct::CProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CProduct)
{
    ui->setupUi(this);
}

CProduct::~CProduct()
{
    delete ui;
}
