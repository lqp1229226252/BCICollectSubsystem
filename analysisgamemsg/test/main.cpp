#include "analysisgamemsg.h"
#include "test.h"
#include "QCoreApplication"
int main(int args,char** argv)
{
    QCoreApplication app(args,argv);
    QString startmsg="MsgType=GameBegin,GameType=X,Account=123456,MsgEnd";
    QString endmsg="MsgType=GameEnd,GameType=X,TotalScore=99,AverageReactTime=0.98,"
                   "AverageRightReactTime=0.8,TotalEnemyNum=1000,TotalKillNum=888,"
                   "TotalMissNum=112,TotalWrongNum=10,"
                   "TotalFire=4000,TotalGameTime=1000,HitRate=0.95,MsgEnd";
    QString bornmsg="MsgType=EnemyBorn,EnemyType=1,InitLine=5,InnerIndex=2,MsgEnd";
    QString diemsg="MsgType=EnemyDie,EnemyType=1,DeathType=2,MsgEnd";
    QString hitmsg="MsgType=FireHit,EnemyType=1,MsgEnd";
    QString missmsg="MsgType=FireMiss,MsgEnd";
    QString cutmsg="MsgType=CutHit,EnemyType=1,MsgEnd";
    Test test;
    test.analysis(startmsg);
    test.analysis(bornmsg);
    test.analysis(endmsg);
    test.analysis(diemsg);
    test.analysis(hitmsg);
    test.analysis(missmsg);
    test.analysis(cutmsg);
    app.exec();

}
