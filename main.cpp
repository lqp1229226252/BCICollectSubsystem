#include "live_broadcast.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    live_broadcast w;
    w.show();
    return a.exec();
}
