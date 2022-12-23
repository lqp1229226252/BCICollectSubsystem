#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>


namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    QString SendAccount();  //给login获取注册时的account，默认account为电话号码。

signals:
    void close_register();
    void sendRegister(QString,QString);

private:
    Ui::Register *ui;

private slots:

    void closeEvent(QCloseEvent *event);  //关闭返回登录界面
    void on_pushButton_getVerification_clicked();
    void on_pushButton_register_clicked();
};

#endif // REGISTER_H
