#include "login.h"

#include <QApplication>

#define CPU_SET(cpu, cpusetp) //设置cpu


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();
    return a.exec();
}
