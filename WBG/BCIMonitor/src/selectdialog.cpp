#include "selectdialog.h"
#include "ui_selectdialog.h"
#include "QDebug"
SelectDialog::SelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
{
    ui->setupUi(this);
}

SelectDialog::~SelectDialog()
{
    delete ui;
}

void SelectDialog::setDeviceType(QStringList devicetype)
{
    ui->device->clear();
    ui->device->addItems(devicetype);
}
void SelectDialog::on_select_clicked()
{
    emit select(ui->device->currentIndex());
}
