#include "gamefinishdata.h"
#include "QFile"
#include "QDir"
#include "QDebug"
GameFinishData::GameFinishData(QObject *parent) : QObject(parent)
{
    train_time=0;
    this->bci_save_path="result";
}

void GameFinishData::setPath(QString path)
{
    this->gamefile_path=path;
}

void GameFinishData::setBCIPath(QString name)
{
    this->bci_save_path=name;
}

void GameFinishData::readGameFinishData()
{
    QDir directory(this->gamefile_path);
    QStringList files = directory.entryList(QStringList() << "*.bci", QDir::Files);
    if(!files.isEmpty())
    {
        for(QString file:files)
        {
            file=this->gamefile_path+"/"+file;
            readGameFile(file);
        }
    }
    saveFinishData();
    //训练次数自加
    train_time++;
}

bool  GameFinishData::readGameFile(QString name)
{
    QList<double> emotion_value;
    QList<double> periceive_value;
    QFile file(name);
    QString line;
    QStringList arr;
    file.open(QIODevice::ReadOnly);
    int cnt=0;
    bool flag=false;
    while (!file.atEnd()) {
        line=file.readLine();
        if(line.contains("Result"))
            flag=true;
        if(flag==false) continue;
        if(cnt<11){
            arr += line.split(QRegExp("[: \r\n]"),QString::SkipEmptyParts);
            cnt++;
        }
        else break;
    }
    //十个指标
    //若发来的BCI文件有误应该返回错误
    if(arr.size()<11) return false;
    for(int i=1;i<11;i++){
        QStringList  strs=  arr[i].split("=");
        if(i<6)
        {
            periceive_value.append(strs[1].toDouble()/10000);
        }
        else
        {
             emotion_value.append(strs[1].toDouble()/10000);
        }
    }
    if(emotion_max_value.isEmpty())
    {
        emotion_max_value=emotion_value;
        periceive_max_value=periceive_value;
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            emotion_max_value[i]=emotion_max_value[i]>emotion_value[i]?emotion_max_value[i]:emotion_value[i];
            periceive_max_value[i]=periceive_max_value[i]>periceive_value[i]?periceive_max_value[i]:periceive_value[i];
        }
    }
    file.close();
    //将BCI文件转移
    QString fileName = QFileInfo(name).fileName();
    QDir dir;
    QString path= bci_save_path +"/"+QString::number(train_time);
    dir.mkpath(path);
    QString destinationFilePath = path+"/"+fileName;
    QFile::rename(name,destinationFilePath);
    return true;
}

QList<double>GameFinishData::getEmotionValue()
{
    QList<double> value=emotion_max_value;
    emotion_max_value.clear();
    return value;
}
QList<double>GameFinishData::getPericeiveValue()
{
    QList<double> value=periceive_max_value;
    periceive_max_value.clear();
    return value;
}

void GameFinishData::saveFinishData()
{
    QString game_path=this->bci_save_path+"/finish.game";
    QFile file(game_path);
    file.open(QIODevice::Append);
    QString data="";
    for(int i=0;i<5;i++)
    {
        data+=QString::number(periceive_max_value[i])+" ";
    }
    for(int i=0;i<5;i++)
    {
        data+=QString::number(emotion_max_value[i])+" ";
    }
    data+="\n";
    file.write(data.toUtf8());
    file.close();
}

int GameFinishData::getTrainTime() const
{
    return train_time;
}


