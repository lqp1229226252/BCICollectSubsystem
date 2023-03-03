#include "usergamewidget.h"
#include "QApplication"
QList<GameData> createData()
{
    QList<GameData> gamedata;
    QStringList names={"天命奇遇","天命奇遇2","巫师3：狂猎","Apex Legends"};
    QString url="D:/project/Qt/BCI/UserGameWidget/test/res/";
    QString cover_url="D:/project/Qt/BCI/UserGameWidget/test/res/cover/";
    for(int i=0;i<names.size();i++)
    {
        GameData data;
        data.setName(names[i]);
        QString path=url+QString::number(i)+".png";
        QPixmap pixmap(path);
        data.setIcon(pixmap);
        path=cover_url+QString::number(i)+".png";
        pixmap.load(path);
        data.setCover(pixmap);
        data.setPlaytime(i+1);
        data.setPlayrank(i+1);
        gamedata.append(data);
    }
    return gamedata;
}
QList<DynamicData> createDynamicData()
{
    QList<DynamicData> gamedata;
    QStringList dynamic_names={"《APEX Legends》皇家卫队收集活动","Prime重生:Mese Prime 和 Limbo","2.18 End Game Report"};
    QStringList game_names={"Apex Legends","Warframe","Goose Goose Duck"};
    QString game_cover="D:/project/Qt/BCI/UserGameWidget/test/res/";
    QString dynamic_cover="D:/project/Qt/BCI/UserGameWidget/test/res/dynamic/";
    for(int i=0;i<game_names.size();i++)
    {
        DynamicData data;
        data.setGame_name(game_names[i]);

        QString game_path=game_cover+QString::number(i)+".png";
        QPixmap pixmap(game_path);
        data.setGame_icon(pixmap);

        QString dynamic_path=dynamic_cover+QString::number(i)+".png";
        QPixmap pixmap1(dynamic_path);
        data.setCover(pixmap1);

        data.setDate("今天");

        data.setDynamic_name(dynamic_names[i]);

        gamedata.append(data);
    }
    return gamedata;
}
int main(int args,char** argv)
{
    QApplication app(args,argv);

    UserGameWidget w;
    QList<GameData> gamedata=createData();
    QList<DynamicData> dynamicdata=createDynamicData();
    w.addGame(gamedata);
    w.addGamePlay(gamedata);
    w.addGameUpdate(gamedata);
    w.setGameOverview(gamedata);
    w.setGameDynamic(dynamicdata);
    w.show();
    return app.exec();
}
