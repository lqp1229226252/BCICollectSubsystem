
#include <QApplication>
#include "login.h"
#include "register_info.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login *loginWidget= new Login;
    loginWidget->show();

    return a.exec();
}
