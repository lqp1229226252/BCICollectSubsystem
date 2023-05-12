#ifndef STORAGE_H
#define STORAGE_H
#include "QFileInfo"
#include "QDebug"
class Storage:public QObject
{
    Q_OBJECT
public:
    virtual ~Storage(){};
    void setFilename(QString name){this->name=name;number=0;};
    QString getFilename(){return name;};
    void getNumber(quint16 &number){number=this->number;this->number++;};
    virtual void setChannelLabels(QString lables)=0;
    virtual void setChannelNum(quint8 num)=0;
    virtual void save(double* data,int num)=0;
    void setChanlocs(QVariantList chanlocs){this->chanlocs=chanlocs;}
    QVariantList getChanlocs(){return chanlocs;}
    void setSrate(quint16 rate){this->srate=rate;}
    quint16 getSrate(){return srate;}
    virtual void stop(){};
signals:
    void saveFinish(QString);
private:
    QString name;
    quint16 number;
    QVariantList chanlocs;
    quint16 srate;
};
#endif // STORAGE_H
