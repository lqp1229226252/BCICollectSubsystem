#include "filedevice.h"
#include "QDebug"
#include "QFile"
#include "QFileInfo"
#include "QDir"
#include "QStandardPaths"
FileDevice::FileDevice()
{
    init();
}

bool FileDevice::open(QString name)
{
    eegdata.clear();
    QFileInfo info(name);
    if(info.suffix()=="vhdr")
    {
        return readVHDR(name);
    }
    else if(info.suffix()=="bin")
    {
        return readBIN(name);
    }
    else if(info.suffix()=="csv")
    {
        return readCSV(name);
    }
    else if(info.suffix()=="txt")
    {
        return readTXT(name);
    }
    return true;
}

QList<QList<double>> FileDevice::GetData()
{
    QList<QList<double>> ret;
    QList<double> data=eegdata.getData();
    if(!data.isEmpty())
    {
       ret.append(data);
    }
    return ret;
}

QStringList FileDevice::getChannelName()
{
    QStringList labels=eegdata.getCh_names();
    SampleDevice::readChanlocs(labels);
    return labels;
}

void FileDevice::StartGetData()
{
    SampleDevice::StartGetData();
}

void FileDevice::StopGetData()
{
    SampleDevice::StopGetData();
}

void FileDevice::init()
{
    process=new QProcess();

}

bool FileDevice::readVHDR(QString name)
{
    QFileInfo info(name);
    QString temp_dir=QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    QDir dir(temp_dir);
    temp_dir=temp_dir+"/"+info.baseName();
    QFileInfo temp_file(temp_dir);
    if(!temp_file.exists())
    {
        QStringList args;
        args<<"--path"<<name<<"--temp"<<temp_dir;
        process->start("file/main.exe",args);
        process->waitForFinished();
        process->kill();
    }
    QFile file(temp_dir+"/ch_names.txt");
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok)
    {
        QByteArray filedata=file.readAll();
        eegdata.setCh_names(filedata);
    }
    else
    {
        qDebug()<<"失败";
        return false;
    }
    eegdata.setData(temp_dir+"/data.bin");
    qDebug()<<"读取结束";
    return true;
}

bool FileDevice::readTXT(QString)
{
    return false;
}
bool FileDevice::readBIN(QString name)
{
    QFileInfo info(name);
    QString ch_names_dir=info.absolutePath()+"/ch_names.txt";
    QFile file(ch_names_dir);
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok)
    {
        QByteArray filedata=file.readAll();
        eegdata.setCh_names(filedata);
    }
    else
    {
        qDebug()<<"失败";
        return false;
    }
    eegdata.setData(name);
    qDebug()<<"读取结束";
    return true;
}

bool FileDevice::readCSV(QString)
{
    return false;
}


