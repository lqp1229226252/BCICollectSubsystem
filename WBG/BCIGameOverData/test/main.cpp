#include <QApplication>
#include "gameoverwidget.h"
#include "test.h"

#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString endmsg ="MsgType=GameEnd,GameType=X,TotalScore=99,AverageReactTime=0.98,"
                   "AverageRightReactTime=0.8,TotalEnemyNum=1000,TotalKillNum=888,"
                   "TotalMissNum=112,TotalWrongNum=10,"
                   "TotalFire=4000,TotalGameTime=1000,HitRate=0.95,MsgEnd";

    test t;
    t.analze(endmsg);

    return a.exec();
}
