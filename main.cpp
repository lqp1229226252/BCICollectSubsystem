#include "store.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Store w;
    w.show();
    return a.exec();
}
