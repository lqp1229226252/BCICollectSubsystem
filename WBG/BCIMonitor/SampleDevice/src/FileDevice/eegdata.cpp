#include "eegdata.h"
#include "QDebug"
#include "QFile"
EEGData::EEGData()
{
    data_index=0;
}

void EEGData::setData(QByteArray data)
{
    analysis(data);
}

void EEGData::setData(QString name)
{

    QFile file(name);
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok)
    {
        int byte_size=sizeof(double)*ch_names.size();
        QByteArray buf=file.read(byte_size);
        double *value=(double *)malloc(sizeof(double)*data.size());
        while(!buf.isEmpty())
        {
            memcpy(value,buf.data(),buf.size());
            for(int i=0;i<data.size();i++)
            {
                data[i].append(value[i]*1000000);

            }
            buf=file.read(byte_size);

        }
        free(value);
        file.close();
    }

//    qDebug()<<this->data.size();
//    qDebug()<<this->data[0].size();
}

void EEGData::setCh_names(const QStringList &value)
{
    ch_names = value;
}

void EEGData::setCh_names(QByteArray value)
{
    QString str=QString::fromUtf8(value).replace("\r","");
    this->ch_names=str.split("\n");
    this->ch_names.removeAt(this->ch_names.size()-1);
    this->data.resize(this->ch_names.size());
}
void EEGData::clear()
{
    data.clear();
    data_index=0;
    ch_names.clear();
}
QList<double> EEGData::getData()
{
    QList<double> value;
    if(data_index==data[0].size())
    {
        return value;
    }
    for(int i=0;i<ch_names.size();i++)
    {
         value.append(data[i][data_index]);
    }
    data_index++;
    return value;
}
QStringList EEGData::getCh_names() const
{
    return ch_names;
}

void EEGData::analysis(QByteArray data)
{
   int channel_index=0,point_index=0;
   QString temp;
   for(int i=0;i<data.size();i++)
   {
       qDebug()<<data[i];
        if(data[i]==' ')
        {
            this->data[channel_index][point_index]=temp.toDouble();
            point_index++;
            temp.clear();
        }
        else if(data[i]=='\n')
        {
           channel_index++;
           point_index--;
           temp.clear();
        }
        else
        {
            temp.append(QChar(data[i]));
        }

   }
   qDebug()<<this->data.size();
   QString eegdata=QString(data);
   QStringList eegitem=eegdata.split("\n");
   for(int i=0;i<eegitem.size();i++)
   {
        QStringList eegstr=eegitem[i].split(" ");
        QVector<double> eeg;
        for(int j=0;j<eeg.size();j++)
        {
            eeg.append(eegstr[i].toDouble());
        }
        this->data.append(eeg);
   }
//   qDebug()<<this->data.size();
//   qDebug()<<this->data[0].size();
}
