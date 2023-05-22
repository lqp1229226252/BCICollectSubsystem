#ifndef QRCODELOGINWIDGET_H
#define QRCODELOGINWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QRCodeLoginWidget; }
QT_END_NAMESPACE

class QRCodeLoginWidget : public QMainWindow
{
    Q_OBJECT

public:
    QRCodeLoginWidget(QWidget *parent = nullptr);
    ~QRCodeLoginWidget();


    void showQRCodeLogin(QString);

private:
    Ui::QRCodeLoginWidget *ui;
};
#endif // QRCODELOGINWIDGET_H
