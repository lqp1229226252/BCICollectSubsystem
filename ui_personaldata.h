/********************************************************************************
** Form generated from reading UI file 'personaldata.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALDATA_H
#define UI_PERSONALDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalData
{
public:
    QWidget *widget_radar;
    QWidget *widget_detailedData;
    QLabel *label_detailedData;
    QWidget *widget_gameStyle;
    QLabel *label_gameStyle;

    void setupUi(QWidget *PersonalData)
    {
        if (PersonalData->objectName().isEmpty())
            PersonalData->setObjectName(QString::fromUtf8("PersonalData"));
        PersonalData->resize(800, 447);
        widget_radar = new QWidget(PersonalData);
        widget_radar->setObjectName(QString::fromUtf8("widget_radar"));
        widget_radar->setGeometry(QRect(420, 10, 371, 421));
        widget_detailedData = new QWidget(PersonalData);
        widget_detailedData->setObjectName(QString::fromUtf8("widget_detailedData"));
        widget_detailedData->setGeometry(QRect(10, 200, 401, 241));
        label_detailedData = new QLabel(widget_detailedData);
        label_detailedData->setObjectName(QString::fromUtf8("label_detailedData"));
        label_detailedData->setGeometry(QRect(3, 1, 401, 241));
        widget_gameStyle = new QWidget(PersonalData);
        widget_gameStyle->setObjectName(QString::fromUtf8("widget_gameStyle"));
        widget_gameStyle->setGeometry(QRect(10, 10, 401, 181));
        label_gameStyle = new QLabel(widget_gameStyle);
        label_gameStyle->setObjectName(QString::fromUtf8("label_gameStyle"));
        label_gameStyle->setGeometry(QRect(3, 1, 401, 181));

        retranslateUi(PersonalData);

        QMetaObject::connectSlotsByName(PersonalData);
    } // setupUi

    void retranslateUi(QWidget *PersonalData)
    {
        PersonalData->setWindowTitle(QCoreApplication::translate("PersonalData", "PersonalData", nullptr));
        label_detailedData->setText(QString());
        label_gameStyle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PersonalData: public Ui_PersonalData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALDATA_H
