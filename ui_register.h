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

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(251, 268);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 91, 21));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        pushButton_getVerification = new QPushButton(Register);
        pushButton_getVerification->setObjectName(QString::fromUtf8("pushButton_getVerification"));
        pushButton_getVerification->setGeometry(QRect(130, 150, 81, 31));
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 240, 250, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 7.5pt \"Adobe \345\256\213\344\275\223 Std L\";"));

        horizontalLayout->addWidget(label_2);

        pushButton_userAgree = new QPushButton(layoutWidget);
        pushButton_userAgree->setObjectName(QString::fromUtf8("pushButton_userAgree"));
        pushButton_userAgree->setStyleSheet(QString::fromUtf8("font: 25 7.8pt \"Adobe \345\256\213\344\275\223 Std L\";\n"
"QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));

        horizontalLayout->addWidget(pushButton_userAgree);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 7.5pt \"Adobe \345\256\213\344\275\223 Std L\";"));

        horizontalLayout->addWidget(label_3);

        pushButton_privacyAgree = new QPushButton(layoutWidget);
        pushButton_privacyAgree->setObjectName(QString::fromUtf8("pushButton_privacyAgree"));
        pushButton_privacyAgree->setStyleSheet(QString::fromUtf8("font: 25 7.8pt \"Adobe \345\256\213\344\275\223 Std L\";\n"
"QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));

        horizontalLayout->addWidget(pushButton_privacyAgree);

        lineEdit_phone = new QLineEdit(Register);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(20, 30, 191, 31));
        pushButton_register = new QPushButton(Register);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(20, 190, 191, 41));
        pushButton_register->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        lineEdit_verification = new QLineEdit(Register);
        lineEdit_verification->setObjectName(QString::fromUtf8("lineEdit_verification"));
        lineEdit_verification->setGeometry(QRect(21, 152, 111, 31));
        lineEdit_password = new QLineEdit(Register);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(20, 70, 191, 31));
        lineEdit_repassword = new QLineEdit(Register);
        lineEdit_repassword->setObjectName(QString::fromUtf8("lineEdit_repassword"));
        lineEdit_repassword->setGeometry(QRect(20, 110, 191, 31));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        label->setText(QCoreApplication::translate("Register", "\346\254\242\350\277\216\346\263\250\345\206\214", nullptr));
        pushButton_getVerification->setText(QCoreApplication::translate("Register", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214\345\215\263\350\241\250\347\244\272\345\220\214\346\204\217", nullptr));
        pushButton_userAgree->setText(QCoreApplication::translate("Register", "\343\200\212\347\224\250\346\210\267\345\215\217\350\256\256\343\200\213", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "\345\217\212", nullptr));
        pushButton_privacyAgree->setText(QCoreApplication::translate("Register", "\351\232\220\347\247\201\345\215\217\350\256\256", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("Register", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        lineEdit_verification->setPlaceholderText(QCoreApplication::translate("Register", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Register", "\345\257\206\347\240\2018-20\344\275\215\357\274\214\345\214\205\346\213\254\346\225\260\345\255\227/\345\255\227\346\257\215", nullptr));
        lineEdit_repassword->setPlaceholderText(QCoreApplication::translate("Register", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
