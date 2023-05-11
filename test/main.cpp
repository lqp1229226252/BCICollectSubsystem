#include "test.h"
#include "drawecharts.h"
#include "analyzeechartsdata.h"
#include <QApplication>
#include <QMap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test t;
//    w.show();
//    DrawEcharts d;
//    d.show();
//    t.sendMap();
    t.timeStart();

    return a.exec();
}
