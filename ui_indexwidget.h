/********************************************************************************
** Form generated from reading UI file 'indexwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXWIDGET_H
#define UI_INDEXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndexWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *tools;
    QToolButton *toolButton;
    QHBoxLayout *tabs;
    QHBoxLayout *btns;
    QSpacerItem *horizontalSpacer;
    QToolButton *min;
    QToolButton *max;
    QToolButton *close;

    void setupUi(QWidget *IndexWidget)
    {
        if (IndexWidget->objectName().isEmpty())
            IndexWidget->setObjectName(QString::fromUtf8("IndexWidget"));
        IndexWidget->resize(800, 600);
        IndexWidget->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border:none\n"
"}"));
        gridLayout = new QGridLayout(IndexWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tools = new QHBoxLayout();
        tools->setObjectName(QString::fromUtf8("tools"));
        toolButton = new QToolButton(IndexWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        tools->addWidget(toolButton);

        tabs = new QHBoxLayout();
        tabs->setObjectName(QString::fromUtf8("tabs"));

        tools->addLayout(tabs);

        btns = new QHBoxLayout();
        btns->setSpacing(10);
        btns->setObjectName(QString::fromUtf8("btns"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        btns->addItem(horizontalSpacer);

        min = new QToolButton(IndexWidget);
        min->setObjectName(QString::fromUtf8("min"));

        btns->addWidget(min);

        max = new QToolButton(IndexWidget);
        max->setObjectName(QString::fromUtf8("max"));

        btns->addWidget(max);

        close = new QToolButton(IndexWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMaximumSize(QSize(40, 16777215));
        close->setStyleSheet(QString::fromUtf8(""));

        btns->addWidget(close);


        tools->addLayout(btns);


        verticalLayout->addLayout(tools);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(IndexWidget);

        QMetaObject::connectSlotsByName(IndexWidget);
    } // setupUi

    void retranslateUi(QWidget *IndexWidget)
    {
        IndexWidget->setWindowTitle(QCoreApplication::translate("IndexWidget", "IndexWidget", nullptr));
        toolButton->setText(QCoreApplication::translate("IndexWidget", "logo", nullptr));
        min->setText(QCoreApplication::translate("IndexWidget", "...", nullptr));
        max->setText(QCoreApplication::translate("IndexWidget", "...", nullptr));
        close->setText(QCoreApplication::translate("IndexWidget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexWidget: public Ui_IndexWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXWIDGET_H
