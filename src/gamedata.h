#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <QObject>
#include "QPixmap"
class GameData
{
public:
    GameData();
    GameData(QPixmap pixmap,QString name);
    QString getName() const;
    void setName(const QString &value);

    QPixmap getCover() const;
    void setCover(const QPixmap &value);

    int getPlaytime() const;
    QString getPlaytime();
    void setPlaytime(int value);

    int getPlayrank() const;
    QString getPlayrank();
    void setPlayrank(int value);

private:
    QString name;
    QPixmap cover;
    int playtime;
    int playrank;
};

#endif // GAMEDATA_H
