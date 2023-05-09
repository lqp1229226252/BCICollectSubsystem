#ifndef BCIMYSQL_H
#define BCIMYSQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>


class BciMysql : public QObject
{
    Q_OBJECT
public:
    explicit BciMysql(QObject *parent = nullptr);

    int login(QString,QString);

    int registerUser(QString,QString);

    int SaveRegisterInfo(QString);

signals:

    void connectFail();
    void connectSuce();

    void registerSuccess();

private:
    void initMysql();



    QSqlDatabase db;

signals:


};

#endif // BCIMYSQL_H
