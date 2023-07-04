#include "CNavigationBar.h"
#include "ui_CNavigationBar.h"

CNavigationBar::CNavigationBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNavigationBar)
{
    ui->setupUi(this);
}

CNavigationBar::~CNavigationBar()
{
    delete ui;
}

void CNavigationBar::on_btn_min_clicked()
{

}

void CNavigationBar::on_btn_close_clicked()
{
    emit signal_close();
}

void CNavigationBar::on_btn_main_clicked()
{
    emit signal_show_index(0);
    setButtonWidget(0);
}

void CNavigationBar::on_btn_about_me_clicked()
{
    emit signal_show_index(1);
    setButtonWidget(1);
}

void CNavigationBar::on_btn_shop_clicked()
{
    emit signal_show_index(2);
    setButtonWidget(2);
}
void CNavigationBar::on_btn_view_clicked()
{
    emit signal_show_index(3);
    setButtonWidget(3);
}
void CNavigationBar::on_btn_eeg_clicked()
{
    //emit signal_show_index(4);
    setButtonWidget(4);
}

void CNavigationBar::on_btn_live_clicked()
{
    //emit signal_show_index(5);
    setButtonWidget(5);
}
void CNavigationBar::on_btn_person_clicked()
{
    //emit signal_show_index(6);
    setButtonWidget(6);
}

void CNavigationBar::on_btn_load_clicked()
{
    //emit signal_show_index(7);
    setButtonWidget(7);
}

void CNavigationBar::on_btn_set_clicked()
{
    //emit signal_show_index(8);
    setButtonWidget(8);
}

void CNavigationBar::setButtonWidget(int iIdex)
{
    ui->widget_about_me->setStyleSheet("QWidget#widget_about_me{}");
    ui->widget_shop->setStyleSheet("QWidget#widget_shop{}");
    ui->widget_view->setStyleSheet("QWidget#widget_view{}");
    ui->widget_main->setStyleSheet("QWidget#widget_main{}");
    ui->widget_eeg->setStyleSheet("QWidget#widget_main{}");
    ui->widget_live->setStyleSheet("QWidget#widget_view{}");
    ui->widget_load->setStyleSheet("QWidget#widget_main{}");



    switch (iIdex) {
    case 0:
    ui->widget_main->setStyleSheet("QWidget#widget_main{image: url(:/image/image/tz.png);}");
    ui->widget_about_me->setStyleSheet("QWidget#widget_about_me{}");
    ui->widget_shop->setStyleSheet("QWidget#widget_shop{}");
    ui->widget_view->setStyleSheet("QWidget#widget_view{}");
        break;
    case 1:
    ui->widget_about_me->setStyleSheet("QWidget#widget_about_me{image: url(:/image/image/tz.png);}");
    ui->widget_main->setStyleSheet("QWidget#widget_main{}");
    ui->widget_shop->setStyleSheet("QWidget#widget_shop{}");
    ui->widget_view->setStyleSheet("QWidget#widget_view{}");
        break;
    case 2:
    ui->widget_shop->setStyleSheet("QWidget#widget_shop{image: url(:/image/image/tz.png);}");
    ui->widget_about_me->setStyleSheet("QWidget#widget_about_me{}");
    ui->widget_main->setStyleSheet("QWidget#widget_main{}");
    ui->widget_view->setStyleSheet("QWidget#widget_view{}");
        break;
    case 3:
    ui->widget_view->setStyleSheet("QWidget#widget_view{image: url(:/image/image/tz.png);}");
    ui->widget_main->setStyleSheet("QWidget#widget_main{}");
    ui->widget_shop->setStyleSheet("QWidget#widget_shop{}");
    ui->widget_about_me->setStyleSheet("QWidget#widget_about_me{}");
        break;
    case 4:
    ui->widget_eeg->setStyleSheet("QWidget#widget_eeg{image: url(:/image/image/tz.png);}");
        break;
    case 5:
    ui->widget_live->setStyleSheet("QWidget#widget_live{image: url(:/image/image/tz.png);}");
        break;
    case 6:
    ui->widget_person->setStyleSheet("QWidget#widget_person{image: url(:/image/image/tz.png);}");
        break;
    case 7:
    ui->widget_load->setStyleSheet("QWidget#widget_load{image: url(:/image/image/tz.png);}");
        break;
    case 8:
    ui->widget_set->setStyleSheet("QWidget#widget_set{image: url(:/image/image/tz.png);}");
        break;

    }

}




