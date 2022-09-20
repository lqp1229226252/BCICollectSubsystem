#include "introducewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IntroduceWidget w;
    w.show();
    return a.exec();
}
