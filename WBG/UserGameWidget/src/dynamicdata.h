#ifndef DYNAMICDATA_H
#define DYNAMICDATA_H

#include <QObject>
#include "QPixmap"
class DynamicData
{
public:
    DynamicData();
    QString getDate() const;
    void setDate(const QString &value);
    QPixmap getCover() const;
    void setCover(const QPixmap &value);
    QString getDynamic_name() const;
    void setDynamic_name(const QString &value);

    QPixmap getGame_icon() const;
    void setGame_icon(const QPixmap &value);

    QString getGame_name() const;
    void setGame_name(const QString &value);

private:
    QString date;
    QPixmap cover;
    QString dynamic_name;
    QPixmap game_icon;
    QString game_name;
};

#endif // DYNAMICDATA_H
