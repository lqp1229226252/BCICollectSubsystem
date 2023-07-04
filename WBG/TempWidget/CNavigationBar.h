#ifndef CNAVIGATIONBAR_H
#define CNAVIGATIONBAR_H

#include <QWidget>

namespace Ui {
class CNavigationBar;
}

class CNavigationBar : public QWidget
{
    Q_OBJECT

public:
    explicit CNavigationBar(QWidget *parent = nullptr);
    ~CNavigationBar();

private slots:
    void on_btn_min_clicked();

    void on_btn_close_clicked();

    void on_btn_main_clicked();

    void on_btn_about_me_clicked();

    void on_btn_shop_clicked();

    void on_btn_eeg_clicked();

    void on_btn_live_clicked();

    void on_btn_view_clicked();

    void on_btn_person_clicked();

    void on_btn_load_clicked();

    void on_btn_set_clicked();

private:
    Ui::CNavigationBar *ui;
private:
    void setButtonWidget(int iIdex);

signals:
    void signal_close();
    void signal_show_index(int);
};

#endif // CNAVIGATIONBAR_H
