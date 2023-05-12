#include "gamedata.h"

GameData::GameData()
{

}

GameData::GameData(QPixmap pixmap, QString name)
{
    this->cover=pixmap;
    this->name=name;
}

QString GameData::getName() const
{
    return name;
}

void GameData::setName(const QString &value)
{
    name = value;
}

QPixmap GameData::getCover() const
{
    return cover;
}

void GameData::setCover(const QPixmap &value)
{
    cover = value;
}

int GameData::getPlaytime() const
{
    return playtime;
}

QString GameData::getPlaytime()
{
    return QString::number(playtime)+"h";
}

void GameData::setPlaytime(int value)
{
    playtime = value;
}

int GameData::getPlayrank() const
{
    return playrank;
}

QString GameData::getPlayrank()
{
    return QString::number(playrank);
}

void GameData::setPlayrank(int value)
{
    playrank = value;
}

QPixmap GameData::getIcon() const
{
    return icon;
}

void GameData::setIcon(const QPixmap &value)
{
    icon = value;
}
