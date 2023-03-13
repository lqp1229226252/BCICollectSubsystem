#include "start_game.h"
#include <QApplication>
#include "QStringList"
QList<start_game::GameData> createGameData()
{
    QList<start_game::GameData> gamedata;
    QStringList names={"天命奇遇","天命奇遇2","巫师3：狂猎","Apex Legends"};
    QString url="D:/project/Qt/BCI/UserGameWidget/test/res/";
    for(int i=0;i<names.size();i++)
    {
        start_game::GameData data;
        data.name=names[i];
        QString path=url+QString::number(i)+".png";
        data.icon=QIcon(path);
        gamedata.append(data);
    }
    return  gamedata;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start_game w;
    QList<start_game::GameData> gamedata=createGameData();
    w.addGame(gamedata);
    w.show();
    return a.exec();
}
