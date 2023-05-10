#include <QApplication>

#include "test.h"
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    test t;

    return a.exec();
}
