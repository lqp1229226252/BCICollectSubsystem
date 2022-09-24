#include "personaldata.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PersonalData w;
    w.show();
    return a.exec();
}
