#include "filestorage.h"
#include "QFileInfo"
#include "QFileDialog"
#include "QDebug"
#include "QDateTime"
FileStorage::FileStorage(QObject *parent):QObject(parent)
{
    qRegisterMetaType<QList<double>>("QList<double>");
    init();
    setConnect();
}

FileStorage::~FileStorage()
{
    delete storage;
    if(eegdata_head==NULL)
    {
        free(eegdata_head);
    }
}
void FileStorage::append_eeg(QList<double> data)
{
    if(data.isEmpty())
    {
        return;
    }
    if(start_flag&&(!pause_flag))
    {
        for(QList<double>::const_iterator begin=data.begin();begin!=data.end();begin++)
        {
            (*eegdata_end)=(*begin);
            eegdata_end++;
        }
        storage_num++;
        if(storage_num>=num)
        {
            save();
        }
    }
}
void FileStorage::start()
{
    if(!account.isEmpty())
    {
        if(stop_flag)
        {
            QDateTime datetime=QDateTime::currentDateTime();
            QString data=datetime.date().toString("yyyyMMdd");
            QString time=datetime.time().toString("hhmmss");
            QString filename=dir+"/"+account+"_"+data+time+"_"+QString::number(game_id)+".mat";
            creatFile(filename);
            start_flag=true;
            pause_flag=false;
            stop_flag=false;
        }
        if(pause_flag)
        {
            start_flag=true;
            pause_flag=false;
        }
    }

}
void FileStorage::pause()
{
    pause_flag=true;
    save();
}
void FileStorage::stop()
{
    start_flag=false;
    stop_flag=true;
    save();
    storage->stop();
}

void FileStorage::setSampleNum(int value)
{
    num = value;
}

void FileStorage::setChannel_num(quint8 value)
{
    quint64 byte_size=sizeof(double)*value*num;
    eegdata_head=(double*)malloc(byte_size);
    eegdata_end=eegdata_head;
    storage->setChannelNum(value);
}

void FileStorage::setSrate(quint16 rate)
{
    storage->setSrate(rate);
}

void FileStorage::setChanlocs(QVariantList value)
{
    storage->setChanlocs(value);
}

void FileStorage::setFileNameMsg(QString dir,QString account, int game_id)
{
    this->dir=dir;
    this->account=account;
    this->game_id=game_id;
}
void FileStorage::creatFile()
{
    //选择文件
    QString name=QFileDialog::getSaveFileName(NULL,"新建文件","",tr("mat(*.mat);;bin(*.bin);;txt(*.txt);;csv(*.csv)"));

    //建立文件
    QFile file(name);
    file.open(QIODevice::WriteOnly);
    file.close();

    if(name.isEmpty())
    {
        return;
    }
    creatFile(name);
}
void FileStorage::creatFile(QString name)
{
    this->stop_flag=false;
    storage->setFilename(name);
}

void FileStorage::appendEvent(int type)
{
    storage->appendEvent(type,storage_num);
}
void FileStorage::init()
{
    this->num=20000;
    this->storage_num=0;
    this->start_flag=false;
    this->pause_flag=false;
    this->stop_flag=true;
    storage=new MatStorage;
}
void FileStorage::setConnect()
{
    setStorageConnect();
}
void FileStorage::setStorageConnect()
{
    connect(this,&FileStorage::storageSignal,storage,&Storage::save,Qt::DirectConnection);
    connect(this,&FileStorage::stopSignal,storage,&Storage::stop,Qt::DirectConnection);
    connect(storage,&Storage::saveFinish,this,&FileStorage::saveFinish);
    connect(storage,&Storage::mergeMsg,this,&FileStorage::mergeMsg);
}

void FileStorage::save()
{
    eegdata_end=eegdata_head;
    emit storageSignal(eegdata_end,storage_num);
    storage_num=0;

}
