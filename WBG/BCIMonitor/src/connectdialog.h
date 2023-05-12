#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include "QCloseEvent"
#include "QLabel"
namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();
    void setFamily(QStringList);
    void setType(QStringList);
    void setDeviceNum(int);
    void showError(quint8);
signals:
    void search(int,int);
    void connect(int);
private slots:

    void on_connect_clicked();

    void on_search_clicked();

private:
    Ui::ConnectDialog *ui;
    QLabel *loading;
};

#endif // CONNECTDIALOG_H
