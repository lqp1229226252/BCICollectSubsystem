#include "introducewidget.h"
#include "ui_introducewidget.h"
#include "QDebug"

#include <QWidget>
#include <QMovie>
#include <QUrl>


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
    QMovie *movie = new QMovie(":/neurons-1117_512.gif");
    ui->gif_lbl->setMovie(movie);
    movie->start();
    ui->gif_lbl->show();
}



















