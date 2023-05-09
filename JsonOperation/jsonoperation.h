#ifndef JSONOPERATION_H
#define JSONOPERATION_H

#include <QObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class JsonOperation
{
public:
    JsonOperation();

    void landID(QString account,QString password,int isAutoLand,int isSavePassword);


private:
    QJsonArray *json;

};

#endif // JSONOPERATION_H
