#include "sample.h"
#include "BPDevice.h"
#include "filedevice.h"
Sample::Sample(QObject *parent) : QObject(parent)
{
    init();
}
Sample::~Sample()
{
    if(datathread!=NULL)
    {
        datathread->destroy();
        QThread::msleep(1000);
        datathread->quit();
    }
    if(operationthread!=NULL)
    {
        delete operationthread;
    }
    if(sampledevice!=NULL)
    {
       delete sampledevice;
    }
}
void Sample::setSampleDeivce(quint8 device)
{
    if(sampledevice!=NULL)
    {
        stop();
        delete  sampledevice;
    }
    switch (device) {
    case 0:
        sampledevice=new BPDevice();
        break;
    case 1:
        sampledevice=new FileDevice();
        break;
    case 2:
        break;
    }
    initThread();
    setThreadConnect();
}
void Sample::searchDeivce(int family, int type)
{
    bool isok=sampledevice->SelectDeviceFamily(family);
    if(isok)
    {
        operationthread->setSearchflag();
        operationthread->setType(type);
        operationthread->start();
    }
    else
    {
        error(FamilyError);
    }
}

void Sample::connectDeivce(quint8 id)
{
    operationthread->setConnectflag();
    operationthread->setDevice_id(id);
    operationthread->start();
}

void Sample::open(QString name)
{
    sampledevice->open(name);
}

QStringList Sample::getChannelName()
{
    return sampledevice->getChannelName();
}

QVariantList Sample::getChanlocs()
{
    return sampledevice->getChanlocs();
}

QStringList Sample::GetDeviceFamily()
{
    return sampledevice->GetDeviceFamily();
}

QStringList Sample::GetInterfaceType()
{
    return sampledevice->GetInterfaceType();
}

float Sample::getBatteryVoltage()
{
    return sampledevice->getBatteryVoltage();
}

void Sample::getBatteryLevel()
{
     sampledevice->getBatteryLevel();
}

bool Sample::CheckImpedances()
{
    return sampledevice->CheckImpedances();
}

void Sample::setResistanceValue(int value)
{
    sampledevice->setResistanceValue(value);
}

void Sample::start()
{
    datathread->start();
    sampledevice->StartGetData();
    datathread->setStatus(true);
}
void Sample::pause()
{
    datathread->setStatus(false);
}
void Sample::stop()
{
    datathread->destroy();
    datathread->setStatus(false);
    sampledevice->StopGetData();
}
void Sample::init()
{
    sampledevice=NULL;
    operationthread=NULL;
    datathread=NULL;
}

void Sample::initSample()
{
    sampledevice->setResistanceValue(500);
}
void Sample::initThread()
{
    if(sampledevice!=NULL)
    {
        if(operationthread!=NULL)
        {
            delete operationthread;
        }
        if(datathread!=NULL)
        {
            delete datathread;
        }
        operationthread=new OperationThread();
        operationthread->setDeivce(sampledevice);

        datathread=new DataThread();
        datathread->setDeivce(sampledevice);
    }
}

void Sample::setThreadConnect()
{
    connect(datathread,&DataThread::readFinish,this,&Sample::readData);
    connect(operationthread,&OperationThread::deviceNum,this,&Sample::searchFinish);
    connect(operationthread,&OperationThread::connectStatus,[=](bool status){
        if(status)
        {
            emit connectSuccess();
            initSample();

        }
        else
        {
            emit error(ConnectError);
        }
    });
}
