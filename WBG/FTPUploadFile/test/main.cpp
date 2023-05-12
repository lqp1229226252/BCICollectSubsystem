#include <QApplication>

#include "test.h"
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    test t;

    t.upload("D:/test/000.txt");
    t.upload("D:/test/0.txt");

    t.upload("D:/test/1.txt");


    return a.exec();
}
