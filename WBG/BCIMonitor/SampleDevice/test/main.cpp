#include "sample.h"
#include "QDebug"
#include "QCoreApplication"
#include "test.h"
int main(int args,char** argv)
{
   QCoreApplication app(args,argv);
   Test test;
   app.exec();
}
