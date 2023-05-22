#include <QApplication>
#include "register.h"
#include "register_info.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Register *registerWidget=new Register;
    registerWidget->show();

    Register_info *registerInfoWidget =new Register_info;
    registerInfoWidget->show();

    return a.exec();
}
