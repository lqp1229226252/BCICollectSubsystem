#include "datathread.h"
#include "QDebug"
#include "QTime"
DataThread::DataThread(QObject *parent):QThread(parent)
{
    status=false;
    destroyFlag=false;
}

DataThread::~DataThread()
{
    this->device=NULL;
}
void DataThread::setDeivce(SampleDevice *device)
{
    this->device=device;
}

void DataThread::run()
{
#if TESTENABLE
    int start=QTime::currentTime().second();
    int num=0;
#endif
    while (1) {
        if(status&&(device!=NULL))
        {
            QList<QList<double>> all_data=device->GetData();
            int buf_num=all_data.size();
            for(int i=0;i<buf_num;i++){
                QList<double> data=all_data.at(i);
                data=filter.filterData(data);
                if(fabs(data[0])>200)
                {
                    data.clear();
                }
                if(data.size()!=0)
                {
                    usleep(1);
                    emit readFinish(data);
                    #if TESTENABLE
                    int end=QTime::currentTime().second();
                    num++;
                    if(end>start)
                    {
                        qDebug()<<num;
                        start=end;
                        num=0;
                    }
                    #endif
                    if(destroyFlag)
                    {
                        destroyFlag=false;
                        return;
                    }
                }
            }
        }
    }
}
void DataThread::setStatus(bool value)
{
    status = value;
}

void DataThread::destroy()
{
    destroyFlag = true;
}
