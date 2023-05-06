#ifndef ANALYSISGAMEMSG_H
#define ANALYSISGAMEMSG_H
#include "QObject"
#include "QMap"
class AnalysisGameMsg:public QObject
{
    Q_OBJECT
public:
    AnalysisGameMsg();
    void analysis(QString);
    void analyGameStartMsg(QStringList);
    void analyzeGameOverMsg(QStringList);
signals:
    void gameFinish(QMap<QString,QString>);
    void gameStart(QMap<QString,QString>);
    void gameEnemyBorn(QMap<QString,QString>);
    void gameEnemyDie(QMap<QString,QString>);
    void gameFireHit(QMap<QString,QString>);
    void gameFireMiss(QMap<QString,QString>);
    void gameCutHit(QMap<QString,QString>);
};

#endif // ANALYSISGAMEMSG_H
