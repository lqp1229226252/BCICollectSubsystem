#include <QApplication>
#include "gameoverwidget.h"

#include "test.h"

#include <QString>
#include <QMap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMap<QString, QString> map;
    map.insert("GameType", "Y");
    map.insert("TotalScore", "67");
    map.insert("AverageReactTime", "0.98");
    map.insert("AverageRightReactTime", "0.8");
    map.insert("TotalEnemyNum", "1000");
    map.insert("TotalKillNum", "888");
    map.insert("TotalMissNum", "112");
    map.insert("TotalWrongNum", "10");
    map.insert("TotalFire", "4000");
    map.insert("TotalGameTime", "1000");
    map.insert("HitRate", "0.95");

    test t;
    t.analze(map);

    return a.exec();
}
