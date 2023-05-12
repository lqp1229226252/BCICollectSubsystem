#ifndef FTPSERVERWIDGET_H
#define FTPSERVERWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>
#include <QFileDialog>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QFileInfo>
#include <QHostInfo>
#include <QSettings>

#include "ftpserver.h"

class FtpServerWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString ip READ get_ip WRITE set_ip)
    Q_PROPERTY(QString port READ get_port WRITE set_port)
    Q_PROPERTY(QString userName READ get_user_name WRITE set_user_name)
    Q_PROPERTY(QString password READ get_password WRITE set_password)
    Q_PROPERTY(QString path READ get_path WRITE set_path)
signals:
    void para_changed();
public:
    explicit FtpServerWidget(QWidget *parent = nullptr);
    ~FtpServerWidget();

    bool set_ftp_para(QString ip,QString port,QString userName,QString password,QString path);

    bool ftp_start_server();
    bool ftp_stop_server();

    QString get_ip();
    void set_ip(QString val);
    QString get_port();
    void set_port(QString val);
    QString get_user_name();
    void set_user_name(QString val);
    QString get_password();
    void set_password(QString val);
    QString get_path();
    void set_path(QString val);
    int LoadIni();
    struct FTPInfo{
        QString ip;
        QString port;
        QString username;
        QString password;
        QString filepath;
    } ftpinfo;
protected:
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
private:
    void value_init();
    void control_init();
private slots:
  void btn_click_slot();
  void dir_select_slot(const QString &directory);

private:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditIp;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditUser;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditPassward;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEditPath;
    QPushButton *btnSelectPath;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnCancel;
    QPushButton *btnConfirm;

    QFileDialog *dirSelectDlg;
    QMessageBox *paraMessageBox;


    QString ftpIp = nullptr;
    QString ftpPort = nullptr;
    QString ftpUserName = nullptr;
    QString ftpPassword = nullptr;
    QString ftpPath = nullptr;

    FtpServer *ftpServer = nullptr;

};

#endif // FTPSERVERWIDGET_H
