#include "test.h"
#include "QDebug"
Test::Test(QObject *parent) : QObject(parent)
{
    analysisgamemsg=new AnalysisGameMsg();
    connect(analysisgamemsg,&AnalysisGameMsg::gameStart,[=](QMap<QString,QString> map){
        qDebug()<<"游戏开始"<<map;
    });
    connect(analysisgamemsg,&AnalysisGameMsg::gameFinish,[=](QMap<QString,QString> map){
        qDebug()<<"游戏结束"<<map;
    });
    connect(analysisgamemsg,&AnalysisGameMsg::gameEnemyBorn,[=](QMap<QString,QString> map){
        qDebug()<<"敌人刷新"<<map;
    });
    connect(analysisgamemsg,&AnalysisGameMsg::gameEnemyDie,[=](QMap<QString,QString> map){
        qDebug()<<"敌人死亡"<<map;
    });
    connect(analysisgamemsg,&AnalysisGameMsg::gameFireHit,[=](QMap<QString,QString> map){
        qDebug()<<"开枪命中"<<map;
    });
    connect(analysisgamemsg,&AnalysisGameMsg::gameFireMiss,[=](QMap<QString,QString> map){
        qDebug()<<"开枪没命中"<<map;
    });
    connect(analysisgamemsg,&AnalysisGameMsg::gameCutHit,[=](QMap<QString,QString> map){
        qDebug()<<"挥砍命中"<<map;
    });
}

void Test::analysis(QString msg)
{
    analysisgamemsg->analysis(msg);
}
