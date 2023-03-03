#include "dynamicdata.h"

DynamicData::DynamicData()
{

}

QString DynamicData::getDate() const
{
    return date;
}

void DynamicData::setDate(const QString &value)
{
    date = value;
}

QPixmap DynamicData::getCover() const
{
    return cover;
}

void DynamicData::setCover(const QPixmap &value)
{
    cover = value;
}

QString DynamicData::getDynamic_name() const
{
    return dynamic_name;
}

void DynamicData::setDynamic_name(const QString &value)
{
    dynamic_name = value;
}

QPixmap DynamicData::getGame_icon() const
{
    return game_icon;
}

void DynamicData::setGame_icon(const QPixmap &value)
{
    game_icon = value;
}

QString DynamicData::getGame_name() const
{
    return game_name;
}

void DynamicData::setGame_name(const QString &value)
{
    game_name = value;
}
