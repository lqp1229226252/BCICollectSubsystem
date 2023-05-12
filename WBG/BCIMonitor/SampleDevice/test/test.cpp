#include "test.h"
#include "QDebug"
Test::Test(QObject *parent) : QObject(parent)
{
    sample=new Sample;
    sample->setSampleDeivce(Sample::BP);
    sample->searchDeivce(0,0);
    connect(sample,&Sample::searchFinish,[=](int num){
        sample->connectDeivce(0);
    });
    connect(sample,&Sample::connectSuccess,[=](){
        qDebug()<<"连接成功";
        sample->CheckImpedances();
        sample->setResistanceValue(0);
        qDebug()<<sample->getBatteryVoltage();
        sample->getBatteryLevel();

    });
    connect(sample,&Sample::error,[=](int num){
        qDebug()<<"连接失败";
    });
}
