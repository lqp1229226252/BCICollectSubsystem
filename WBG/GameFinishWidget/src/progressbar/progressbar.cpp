#include "progressbar.h"
#include "ui_progressbar.h"
#include <QMetaObject>

ProgressBar::ProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar)
{
    ui->setupUi(this);

}

ProgressBar::~ProgressBar()
{
    delete ui;
}

void ProgressBar::showProgressBar(int value)
{
    QMetaObject::invokeMethod((QObject *)ui->quickWidget->rootObject()
                              ,"setTimes", Qt::DirectConnection,Q_ARG(QVariant, value));
}
