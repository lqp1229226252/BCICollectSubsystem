/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QPushButton *pushButton_getVerification;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButton_userAgree;
    QLabel *label_3;
    QPushButton *pushButton_privacyAgree;
    QLineEdit *lineEdit_phone;
    QPushButton *pushButton_register;
    QLineEdit *lineEdit_verification;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_repassword;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(748, 693);
        Register->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(33, 36, 41);\n"
"color:rgb(255, 255, 255);\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	padding:10px;\n"
"	background-color: rgb(50, 53, 60);\n"
"	border: 0px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(118, 119, 121);\n"
"}"));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 40, 201, 61));
        label->setStyleSheet(QString::fromUtf8("font: 75 28pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_getVerification = new QPushButton(Register);
        pushButton_getVerification->setObjectName(QString::fromUtf8("pushButton_getVerification"));
        pushButton_getVerification->setGeometry(QRect(310, 420, 161, 51));
        pushButton_getVerification->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_getVerification{\n"
"	\n"
"	background-color: rgb(118, 119, 121);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:3px;		\n"
"	font: 10pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}\n"
"QPushButton#pushButton_getVerification:pressed{\n"
"	\n"
"	background-color:rgb(140, 141, 143);\n"
"	border-radius:3px;	\n"
"	font: 10pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}"));
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 500, 310, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        horizontalLayout->addWidget(label_2);

        pushButton_userAgree = new QPushButton(layoutWidget);
        pushButton_userAgree->setObjectName(QString::fromUtf8("pushButton_userAgree"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        pushButton_userAgree->setFont(font);
        pushButton_userAgree->setStyleSheet(QString::fromUtf8("font: 75 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        pushButton_userAgree->setFlat(true);

        horizontalLayout->addWidget(pushButton_userAgree);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        horizontalLayout->addWidget(label_3);

        pushButton_privacyAgree = new QPushButton(layoutWidget);
        pushButton_privacyAgree->setObjectName(QString::fromUtf8("pushButton_privacyAgree"));
        pushButton_privacyAgree->setStyleSheet(QString::fromUtf8("font: 75 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        pushButton_privacyAgree->setFlat(true);

        horizontalLayout->addWidget(pushButton_privacyAgree);

        lineEdit_phone = new QLineEdit(Register);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(90, 150, 382, 48));
        pushButton_register = new QPushButton(Register);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(90, 580, 151, 51));
        pushButton_register->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_register{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(6, 191, 255), stop:1 rgb(44, 114, 255) );\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:3px;		\n"
"	font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}\n"
"QPushButton#pushButton_register:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(20, 204, 255), stop:1 rgb(11, 141, 255) );\n"
"	border-style:none;\n"
"	border-radius:3px;\n"
"	font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}\n"
"\n"
"QPushButton#pushButton_register:pressed{\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(20, 204, 255), stop:0.5 rgb(5, 191, 255), stop:1 rgb(11, 141, 255) );\n"
"	border-style:none;\n"
"	border-radius:3px;	\n"
"	font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}\n"
""));
        lineEdit_verification = new QLineEdit(Register);
        lineEdit_verification->setObjectName(QString::fromUtf8("lineEdit_verification"));
        lineEdit_verification->setGeometry(QRect(90, 420, 201, 48));
        lineEdit_password = new QLineEdit(Register);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(90, 240, 381, 48));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_repassword = new QLineEdit(Register);
        lineEdit_repassword->setObjectName(QString::fromUtf8("lineEdit_repassword"));
        lineEdit_repassword->setGeometry(QRect(90, 330, 381, 48));
        lineEdit_repassword->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 130, 61, 16));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 220, 61, 16));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 306, 61, 20));
        label_7 = new QLabel(Register);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 400, 61, 20));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "\345\210\233\345\273\272\346\202\250\347\232\204\350\264\246\346\210\267", nullptr));
        label->setText(QCoreApplication::translate("Register", "<html><head/><body><p>\346\254\242\350\277\216\346\263\250\345\206\214</p></body></html>", nullptr));
        pushButton_getVerification->setText(QCoreApplication::translate("Register", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214\345\215\263\350\241\250\347\244\272\345\220\214\346\204\217", nullptr));
        pushButton_userAgree->setText(QCoreApplication::translate("Register", "\343\200\212\347\224\250\346\210\267\345\215\217\350\256\256\343\200\213", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "\345\217\212", nullptr));
        pushButton_privacyAgree->setText(QCoreApplication::translate("Register", "\343\200\212\351\232\220\347\247\201\345\215\217\350\256\256\343\200\213", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("Register", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        lineEdit_verification->setText(QString());
        lineEdit_verification->setPlaceholderText(QCoreApplication::translate("Register", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Register", "\345\257\206\347\240\2018-20\344\275\215\357\274\214\345\214\205\346\213\254\346\225\260\345\255\227/\345\255\227\346\257\215", nullptr));
        lineEdit_repassword->setPlaceholderText(QCoreApplication::translate("Register", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("Register", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("Register", "\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
        label_6->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("Register", "\351\252\214\350\257\201\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
