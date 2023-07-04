#ifndef CUSERSIGNPAGE_H
#define CUSERSIGNPAGE_H

#include <QDialog>

namespace Ui {
class CUserSignPage;
}

class CUserSignPage : public QDialog
{
    Q_OBJECT

public:
    explicit CUserSignPage(QWidget *parent = nullptr);
    ~CUserSignPage();
    void setText();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::CUserSignPage *ui;
};

#endif // CUSERSIGNPAGE_H
