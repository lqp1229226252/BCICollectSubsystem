#include "indexwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IndexWidget w;
    w.show();
    return a.exec();
}
