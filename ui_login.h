/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_min;
    QPushButton *pushButton_close;
    QWidget *widget;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_account;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_autoLand;
    QCheckBox *checkBox_savePassword;
    QPushButton *pushButton_forgetPassword;
    QPushButton *pushButton_land;
    QPushButton *pushButton_wechart;
    QPushButton *pushButton_qq;
    QPushButton *pushButton_QRCode;
    QPushButton *pushButton_register;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(425, 330);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setMinimumSize(QSize(425, 330));
        login->setMaximumSize(QSize(426, 330));
        login->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
""));
        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 171, 311));
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 10, 161, 41));
        pushButton_min = new QPushButton(login);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(340, 10, 41, 41));
        pushButton_min->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_min{\n"
"	image: url(:/image/min.png);\n"
"}\n"
"QPushButton#pushButton_min:hover{\n"
"	\n"
"	background-color: rgb(224, 255, 255);\n"
"}"));
        pushButton_min->setFlat(false);
        pushButton_close = new QPushButton(login);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(380, 10, 41, 41));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_close\n"
"{\n"
"	image: url(:/image/close.png);\n"
"}\n"
"QPushButton#pushButton_close:hover\n"
"{\n"
"	background-color: rgb(255,84,57);\n"
"}"));
        pushButton_close->setFlat(false);
        widget = new QWidget(login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 70, 241, 171));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 141, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(10, 90, 211, 41));
        lineEdit_password->setFrame(true);
        lineEdit_account = new QLineEdit(widget);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(10, 40, 211, 41));
        lineEdit_account->setFrame(true);
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 140, 231, 25));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_autoLand = new QCheckBox(widget1);
        checkBox_autoLand->setObjectName(QString::fromUtf8("checkBox_autoLand"));

        horizontalLayout->addWidget(checkBox_autoLand);

        checkBox_savePassword = new QCheckBox(widget1);
        checkBox_savePassword->setObjectName(QString::fromUtf8("checkBox_savePassword"));

        horizontalLayout->addWidget(checkBox_savePassword);

        pushButton_forgetPassword = new QPushButton(widget1);
        pushButton_forgetPassword->setObjectName(QString::fromUtf8("pushButton_forgetPassword"));
        pushButton_forgetPassword->setAutoDefault(false);
        pushButton_forgetPassword->setFlat(true);

        horizontalLayout->addWidget(pushButton_forgetPassword);

        pushButton_land = new QPushButton(login);
        pushButton_land->setObjectName(QString::fromUtf8("pushButton_land"));
        pushButton_land->setGeometry(QRect(184, 242, 231, 41));
        pushButton_land->setStyleSheet(QString::fromUtf8("font: 16pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        pushButton_wechart = new QPushButton(login);
        pushButton_wechart->setObjectName(QString::fromUtf8("pushButton_wechart"));
        pushButton_wechart->setGeometry(QRect(180, 290, 31, 31));
        pushButton_qq = new QPushButton(login);
        pushButton_qq->setObjectName(QString::fromUtf8("pushButton_qq"));
        pushButton_qq->setGeometry(QRect(210, 290, 31, 31));
        pushButton_QRCode = new QPushButton(login);
        pushButton_QRCode->setObjectName(QString::fromUtf8("pushButton_QRCode"));
        pushButton_QRCode->setGeometry(QRect(240, 290, 31, 31));
        pushButton_QRCode->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_QRCode{\n"
"	image: url(:/image/er1.png);\n"
"}\n"
"QPushButton#pushButton_QRCode:hover{\n"
"	image: url(:/image/er2.png);\n"
"}"));
        pushButton_QRCode->setFlat(true);
        pushButton_register = new QPushButton(login);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(360, 295, 51, 21));
        pushButton_register->setFlat(true);

        retranslateUi(login);

        pushButton_forgetPassword->setDefault(false);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label->setText(QCoreApplication::translate("login", "\345\256\243\344\274\240\347\211\207", nullptr));
        label_2->setText(QCoreApplication::translate("login", "logo", nullptr));
        pushButton_min->setText(QString());
        pushButton_close->setText(QString());
        label_3->setText(QCoreApplication::translate("login", "\350\264\246\345\217\267\345\257\206\347\240\201\347\231\273\345\275\225", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        lineEdit_account->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        checkBox_autoLand->setText(QCoreApplication::translate("login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox_savePassword->setText(QCoreApplication::translate("login", "\344\277\235\345\255\230\345\257\206\347\240\201", nullptr));
        pushButton_forgetPassword->setText(QCoreApplication::translate("login", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        pushButton_land->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        pushButton_wechart->setText(QCoreApplication::translate("login", "PushButton", nullptr));
        pushButton_qq->setText(QCoreApplication::translate("login", "PushButton", nullptr));
        pushButton_QRCode->setText(QString());
        pushButton_register->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
