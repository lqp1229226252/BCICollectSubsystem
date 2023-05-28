
#include "wbgwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int fontId = QFontDatabase::addApplicationFont(QStringLiteral("./font/Alibaba_PuHuiTi_2.0_35_Thin_35_Thin.ttf"));
     QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
     qDebug()<<"fontfamilies:"<<fontFamilies;
     if (fontFamilies.size() > 0)
     {
         QFont font;
         font.setFamily(fontFamilies[0]);//设置全局字体
         a.setFont(font);
     }

    WBGWIdget w;
    w.setWindowIcon(QIcon(":/icon/logo.png"));
//    w.show();
    return a.exec();
}
