#include "test.h"
#include <QTimer>

test::test(QObject *parent) : QObject(parent)
{
    drawEcharts = new DrawEcharts;
    drawEcharts->show();
    initMap();
    connect(this, &test::sendMapSignal, drawEcharts, &DrawEcharts::getRecChartDatas);

    timer = new QTimer;
    timer->setInterval(10000);

    connect(timer, SIGNAL(timeout()), this, SLOT(ontimeout()));

}

test::~test()
{
    delete drawEcharts;
}

void test::sendMap()
{
    emit sendMapSignal(map);
}

void test::ontimeout()
{
    sendMap();
    timer->stop();

}

void test::timeStart()
{
    timer->start();
}

void test::initMap()
{
    map.insert("Visual",67.34);
    map.insert("Auditory",57.32);
    map.insert("Attention",47.32);
    map.insert("MotorCoordination",78.56);
    map.insert("ComprehensiveCognitive",47.88);

    map.insert("Stress",24.69);
    map.insert("Pressure",54.32);
    map.insert("Morale",16.42);
    map.insert("Arousal",34.65);
    map.insert("EmotionalValence",86.79);
}

