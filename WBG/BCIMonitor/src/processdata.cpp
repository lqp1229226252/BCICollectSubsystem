#include "processdata.h"
#include "QDebug"
ProcessData::ProcessData(QObject *parent) : QObject(parent)
{
    down_sample=12;
}

void ProcessData::setSrate(const quint16 &value)
{
    down_sample = value/20;

}

void ProcessData::receiveData(QList<double> value)
{
    int label_index[12]={2,3,13,7,17,21,24,26,27,28,29,30};
    data.append(value);
    int channel_num=12;
    QList<double> down_data;
    QString msgdata="MsgType=Curve,Points=";
    if(data.size()>=down_sample)
    {
         for(int i=0;i<channel_num;i++)
         {
             double channel_data=0;
             for(int j=0;j<down_sample;j++)
             {
                channel_data+=data[j][label_index[i]];
             }
             channel_data/=down_sample;
             msgdata+=QString::number(channel_data)+",";
             down_data.append(channel_data);
         }
         data.remove(0,down_sample);
         msgdata+="MsgEnd";
         qDebug()<<msgdata;
         emit downData(msgdata);
    }
}
