#include "usergamewidget.h"
#include "QApplication"
QList<GameData> createData()
{
    QList<GameData> gamedata;
    QStringList names={"天命奇遇","天命奇遇2","巫师3：狂猎","Apex Legends"};
    QString url="D:/project/Qt/BCI/UserGameWidget/test/res/";
    for(int i=0;i<names.size();i++)
    {
        GameData data;
        data.setName(names[i]);
        QString path=url+QString::number(i)+".png";
        QPixmap pixmap(path);
        data.setCover(pixmap);
        data.setPlaytime(i+1);
        data.setPlayrank(i+1);
        gamedata.append(data);
    }
    return gamedata;
}
int main(int args,char** argv)
{
    QApplication app(args,argv);

    UserGameWidget w;
    QList<GameData> gamedata=createData();
    w.addGame(gamedata);
    w.addGamePlay(gamedata);
    w.addGameUpdate(gamedata);
    w.setGameOverview(gamedata);
    w.show();
    return app.exec();
}
