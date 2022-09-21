#include "introducewidget.h"
#include "ui_introducewidget.h"
#include "QDebug"
IntroduceWidget::IntroduceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IntroduceWidget)
{
    ui->setupUi(this);
    init();
}

IntroduceWidget::~IntroduceWidget()
{
    delete ui;
}

void IntroduceWidget::init()
{

    ui->introduceLayout->setStretch(0,2);
    ui->introduceLayout->setStretch(1,1);

    ui->productLayout->setStretch(0,1);
    ui->productLayout->setStretch(1,5);
    ui->functionLayout->setStretch(0,1);
    ui->functionLayout->setStretch(1,5);
    ui->contactLayout->setStretch(0,1);
    ui->contactLayout->setStretch(1,5);

    ui->widgetLayout->setStretch(0,2);
    ui->widgetLayout->setStretch(1,1);

    ui->textLayout->insertStretch(0,1);
    ui->textLayout->addStretch(1);
    ui->textLayout->setStretch(1,4);
    ui->textLayout->setStretch(2,4);
    ui->textLayout->setStretch(3,4);
}

