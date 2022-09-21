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

signals:
    void close_register();

private:
    Ui::Register *ui;

private slots:
    void emit_close();
    void closeEvent(QCloseEvent *event);
    void on_pushButton_getVerification_clicked();
};

#endif // REGISTER_H
