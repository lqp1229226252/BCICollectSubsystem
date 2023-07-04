#include "matstorage.h"

MatStorage::MatStorage()
{

}

MatStorage::~MatStorage()
{

}
void MatStorage::setChannelLabels(QString lables)
{

}
void MatStorage::setChannelNum(quint8 num)
{
    mat.setChannelNum(num);
}
void MatStorage::save(double *data, int num)
{

    QString filename=getCurrentFileName();
    mat.setFileName(filename);

    mat.save(data,num);
    //保存采样率
    mat.saveSrate(getSrate());
    //保存脑电导联信息
    mat.saveChanlocs(getChanlocs());
    //保存事件信息
    mat.saveEevent(getEvent(num));

    mat.saveUrevent(getUrevent(num));

    mat.stop();

    //采样点起始点更新
    sample+=num;
    emit saveFinish(filename);
}
void MatStorage::stop()
{
    //    mat.stop();
}

QString MatStorage::getCurrentFileName()
{
    quint16 number;
    getNumber(number);
    sample_id=number;
    if(sample_id==0)
    {
        sample=0;
    }
    QString filename=getFilename();
    QFileInfo info(filename);
    QString dir=info.absolutePath();
    QString baseName=info.baseName();
    QString path=dir+"/"+baseName+"_"+QString::number(number)+".mat";
    return path;
}

QVariantList MatStorage::getEvent(int number)
{
    int start=sample+1;
    QVariantMap map;
    map["latency"]=start;
    map["duration"]=number;
    map["channel"]=0;
    map["bvmknum"]=sample_id;
    map["type"]="S 22";
    map["urevent"]=sample_id;
    QVariantList list={map};
    return list;
}

QVariantList MatStorage::getUrevent(int number)
{
    int start=sample+1;
    QVariantMap map;
    map["latency"]=start;
    map["duration"]=number;
    map["channel"]=0;
    map["bvmknum"]=sample_id;
    map["type"]="S 22";
    QVariantList list={map};
    return list;
}
