#include <QCoreApplication>
#include "matread.h"
#include "QDebug"
int main(int argc, char *argv[])
{
    QString Dir=QString(argv[1]);
    QString channel_num=QString(argv[2]);
    QString point_num=QString(argv[3]);
    MatRead matread;
    matread.setDataDim(channel_num.toUInt(),point_num.toUInt());
    matread.setDir(Dir);
//    matread.setDataDim(31,20000*9);
//    matread.setDir("D:/project/Qt/BCI/BCI/WebrianRecorder-1.1/build/debug/temp/123456/230528185217");
    return 0;
}
