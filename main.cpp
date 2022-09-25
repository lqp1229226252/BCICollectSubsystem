
#include "start_game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start_game w;
    w.show();
    return a.exec();
}
