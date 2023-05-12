#include "operationthread.h"
#include "SampleDevice.h"
OperationThread::OperationThread(QObject *parent):QThread(parent)
{
    searchflag=false;
    connectflag=false;
}
void OperationThread::setDeivce(void *device)
{
    this->device=device;
}

void OperationThread::run()
{
    SampleDevice *device=(SampleDevice*)(this->device);
    if(connectflag)
    {
        bool isok=device->ConnectDevice(device_id);
        connectflag=false;
        emit connectStatus(isok);
    }
    if(searchflag)
    {
        int num=device->SearchDeviceNum(type);
        searchflag=false;
        emit deviceNum(num);
    }
}
void OperationThread::setType(int value)
{
    type = value;
}

void OperationThread::setDevice_id(int value)
{
    device_id = value;
}

void OperationThread::setConnectflag()
{
    connectflag = true;
}

void OperationThread::setSearchflag()
{
    searchflag = true;
}

