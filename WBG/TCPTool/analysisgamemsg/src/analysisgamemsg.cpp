#include "analysisgamemsg.h"
#include "QDebug"
AnalysisGameMsg::AnalysisGameMsg()
{
}
void AnalysisGameMsg::analysis(QString gameMsg)
{
    QStringList list = gameMsg.split(",");
//    qDebug()<<"属性："<<list;
    QString headMsg = list.at(0);
    // 判断信息类型是否为GameEnd
    QString msg_type=headMsg.split("=")[1];

    // 解析数据
    list.removeAt(0);
    QMap<QString, QString> data;
    foreach (QString str, list) {
        if(str == "MsgEnd")
            break;
        QStringList entry = str.split("=");
        data.insert(entry[0], entry[1]);
    }
//    qDebug()<<data;
    //按照数据类型分发数据
    //游戏结算
    if(msg_type=="GameEnd")
    {
        emit gameFinish(data);
    }
    //游戏开始
    if(msg_type=="GameBegin")
    {
        emit gameStart(data);
    }
    //敌人刷新
    if(msg_type=="EnemyBorn")
    {
        emit gameEnemyBorn(data);
    }
    //敌人死亡
    if(msg_type=="EnemyDie")
    {
        emit gameEnemyDie(data);
    }
    //开枪命中
    if(msg_type=="FireHit")
    {
        emit gameFireHit(data);
    }
    //开枪Miss
    if(msg_type=="FireMiss")
    {
        emit gameFireMiss(data);
    }
    //挥砍命中
    if(msg_type=="CutHit")
    {
        emit gameCutHit(data);
    }

}
