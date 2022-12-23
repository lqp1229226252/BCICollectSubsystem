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
    QPushButton *pushButton_land;
    QPushButton *pushButton_wechart;
    QPushButton *pushButton_qq;
    QPushButton *pushButton_QRCode;
    QPushButton *pushButton_register;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_autoLand;
    QCheckBox *checkBox_savePassword;
    QPushButton *pushButton_forgetPassword;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(755, 490);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setMinimumSize(QSize(755, 490));
        login->setMaximumSize(QSize(755, 490));
        login->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	font: 7pt \"Arial\";\n"
"	color: rgb(118, 119, 121);\n"
"}\n"
"\n"
"#label_2\n"
"{\n"
"	font: 14pt \"Blackadder ITC\";\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"#label_3\n"
"{\n"
"	color:rgb(17, 168, 255);\n"
"	font:14px;\n"
"}\n"
"\n"
"\n"
"QPushButton\n"
"{	\n"
"	font: 8pt \"Arial\";\n"
"}\n"
"QPushButton:hover\n"
"{	\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(255, 255, 255, 0)\n"
"}\n"
"\n"
"#login\n"
"{\n"
"	background-color: rgb(31, 33, 38);\n"
"}\n"
"\n"
"#lineEdit_account,#lineEdit_password\n"
"{\n"
"	background-color: rgb(49, 52, 59);\n"
"	color:rgb(255, 255, 255);\n"
"	border-style:none;\n"
"	padding-left:10px;\n"
"	border-radius:3px\n"
"}\n"
"\n"
"#lineEdit_account:hover,#lineEdit_password:hover{\n"
"	background-color: rgb(56, 59, 67);\n"
"}\n"
"#pushButton_forgetPassword:hover,#pushButton_register:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:unchecked{	\n"
"		background-color:rgb(49, "
                        "52, 59);\n"
"}\n"
"QCheckBox::indicator:unchecked:hover{\n"
"	background-color: rgb(56, 59, 67);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 235, 501));
        label->setStyleSheet(QString::fromUtf8("#label\n"
"{\n"
"	border-image: url(:/image/Nj.png);\n"
"}"));
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 60, 111, 41));
        pushButton_min = new QPushButton(login);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(700, 10, 21, 31));
        pushButton_min->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_min{\n"
"	image: url(:/image/min2.0.png);\n"
"}\n"
"QPushButton#pushButton_min:hover{\n"
"\n"
"}"));
        pushButton_min->setFlat(true);
        pushButton_close = new QPushButton(login);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(730, 10, 21, 21));
        pushButton_close->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_close\n"
"{\n"
"	image:url(:/image/close2.0.png);\n"
"}\n"
"QPushButton#pushButton_close:hover\n"
"{\n"
"\n"
"}\n"
"outline:nonoe;"));
        pushButton_close->setFlat(true);
        widget = new QWidget(login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(270, 100, 481, 151));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 141, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Arial\";"));
        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(10, 100, 371, 41));
        lineEdit_password->setFrame(true);
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_account = new QLineEdit(widget);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(10, 50, 371, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(7);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lineEdit_account->setFont(font1);
        lineEdit_account->setStyleSheet(QString::fromUtf8("font: 7pt \"Arial\";"));
        lineEdit_account->setFrame(true);
        pushButton_land = new QPushButton(login);
        pushButton_land->setObjectName(QString::fromUtf8("pushButton_land"));
        pushButton_land->setGeometry(QRect(280, 300, 371, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        pushButton_land->setFont(font2);
        pushButton_land->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_land{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(6, 191, 255), stop:1 rgb(44, 114, 255) );\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:3px;		\n"
"	font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QPushButton#pushButton_land:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(20, 204, 255), stop:1 rgb(11, 141, 255) );\n"
"	border-style:none;\n"
"	border-radius:3px;\n"
"	font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton#pushButton_land:pressed{\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(20, 204, 255), stop:0.5 rgb(5, 191, 255), stop:1 rgb(11, 141, 255) );\n"
"	border-style:none;\n"
"	border-radius:3px;	\n"
"	font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
""));
        pushButton_wechart = new QPushButton(login);
        pushButton_wechart->setObjectName(QString::fromUtf8("pushButton_wechart"));
        pushButton_wechart->setGeometry(QRect(280, 410, 41, 41));
        pushButton_wechart->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_wechart->setStyleSheet(QString::fromUtf8("image: url(:/image/wc.png);"));
        pushButton_wechart->setFlat(true);
        pushButton_qq = new QPushButton(login);
        pushButton_qq->setObjectName(QString::fromUtf8("pushButton_qq"));
        pushButton_qq->setGeometry(QRect(330, 410, 41, 41));
        pushButton_qq->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_qq->setStyleSheet(QString::fromUtf8("image: url(:/image/QQ.png);"));
        pushButton_qq->setFlat(true);
        pushButton_QRCode = new QPushButton(login);
        pushButton_QRCode->setObjectName(QString::fromUtf8("pushButton_QRCode"));
        pushButton_QRCode->setGeometry(QRect(380, 410, 41, 41));
        pushButton_QRCode->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_QRCode->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_QRCode{\n"
"	image: url(:/image/er1.png);\n"
"}\n"
"QPushButton#pushButton_QRCode:hover{\n"
"	image: url(:/image/er2.png);\n"
"}"));
        pushButton_QRCode->setFlat(true);
        pushButton_register = new QPushButton(login);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(600, 370, 51, 31));
        pushButton_register->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_register->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial\";"));
        pushButton_register->setFlat(true);
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 249, 371, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_autoLand = new QCheckBox(layoutWidget);
        checkBox_autoLand->setObjectName(QString::fromUtf8("checkBox_autoLand"));
        checkBox_autoLand->setMinimumSize(QSize(119, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(9);
        checkBox_autoLand->setFont(font3);
        checkBox_autoLand->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_autoLand->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Arial\";"));

        horizontalLayout->addWidget(checkBox_autoLand);

        checkBox_savePassword = new QCheckBox(layoutWidget);
        checkBox_savePassword->setObjectName(QString::fromUtf8("checkBox_savePassword"));
        checkBox_savePassword->setFont(font3);
        checkBox_savePassword->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_savePassword->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Arial\";"));

        horizontalLayout->addWidget(checkBox_savePassword);

        pushButton_forgetPassword = new QPushButton(layoutWidget);
        pushButton_forgetPassword->setObjectName(QString::fromUtf8("pushButton_forgetPassword"));
        pushButton_forgetPassword->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_forgetPassword->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Arial\";"));
        pushButton_forgetPassword->setAutoDefault(false);
        pushButton_forgetPassword->setFlat(true);

        horizontalLayout->addWidget(pushButton_forgetPassword);


        retranslateUi(login);

        pushButton_forgetPassword->setDefault(false);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("login", "WeBrainGame", nullptr));
        pushButton_min->setText(QString());
        pushButton_close->setText(QString());
        label_3->setText(QCoreApplication::translate("login", "\350\264\246\345\217\267\345\257\206\347\240\201\347\231\273\345\275\225", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        lineEdit_account->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton_land->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        pushButton_wechart->setText(QString());
        pushButton_qq->setText(QString());
        pushButton_QRCode->setText(QString());
        pushButton_register->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        checkBox_autoLand->setText(QCoreApplication::translate("login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox_savePassword->setText(QCoreApplication::translate("login", "\344\277\235\345\255\230\345\257\206\347\240\201", nullptr));
        pushButton_forgetPassword->setText(QCoreApplication::translate("login", "\345\277\230\350\256\260\345\257\206\347\240\201?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
