#include "SampleDevice.h"
#include "QFile"
#include "QMap"
#include "QTime"
#include "QDebug"
QVariantList SampleDevice::getChanlocs() const
{
    return chanlocs;
}
SampleDevice::SampleDevice()
{
}

SampleDevice::~SampleDevice()
{
}


bool SampleDevice::SetBaseSampleRate(float srate)
{
    this->srate=srate;
    return true;
}

quint16 SampleDevice::GetSmapleRate()
{
    return this->srate;
}

void SampleDevice::StartGetData(int)
{
    StartGetData();
}
void SampleDevice::readChanlocs(QString path)
{
    chanlocs.clear();
    QFile file(path);
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok)
    {
        QString filedata=QString(file.readAll());
        QStringList list=filedata.split("\r\n");
        list.removeAt(0);
        quint8 order=0;
        for(QStringList::const_iterator begin=list.begin();begin!=list.end();begin++)
        {
             QMap<QString,QVariant> map;
             QString str=(*begin);
             QStringList data=(*begin).split("\t");
             map["label"]=data[1];
             map["theta"]=data[2].toDouble();
             map["radius"]=data[3].toDouble();
             map["x"]=data[4].toDouble();
             map["y"]=data[5].toDouble();
             map["z"]=data[6].toDouble();
             map["sph_theta"]=data[7].toDouble();
             map["sph_phi"]=data[8].toDouble();
             map["sph_radius"]=data[9].toDouble();
             map["type"]=data[10].toInt();
             map["urchan"]=order;
             order++;
             chanlocs.append(map);
        }


    }
}

void SampleDevice::readChanlocs(QStringList label)
{
    chanlocs.clear();
    for(int i=0;i<label.size();i++)
    {
        QMap<QString,QVariant> map;
        map["labels"]=label[i];
        chanlocs.append(map);
    }
}
