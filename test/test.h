#ifndef TEST_H
#define TEST_H

#include "drawecharts.h"
#include <QObject>
#include <QMap>
#include <QTimer>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    ~test();

    void sendMap();

signals:
    void sendMapSignal(QMap<QString, double>);

public slots:
    void ontimeout();

    void timeStart();

private:
    void initMap();

    DrawEcharts *drawEcharts;

    QMap<QString, double> map;

    QTimer *timer;

};

#endif // TEST_H
