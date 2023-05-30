#ifndef STORAGE_H
#define STORAGE_H
#include "QFileInfo"
#include "QDebug"
#include "QProcess"
class Storage:public QObject
{
    Q_OBJECT
public:
    virtual ~Storage(){};
    void setFilename(QString name);
    QString getFilename();
    void getNumber(quint16 &number);
    virtual void setChannelLabels(QString lables)=0;
    virtual void setChannelNum(quint8 num)=0;
    virtual void save(double* data,int num);
    void setChanlocs(QVariantList chanlocs);
    QVariantList getChanlocs();
    void setSrate(quint16 rate);
    quint16 getSrate();
    virtual void stop();

    void appendEvent(int,int);

    QVariantList getEvent() const;

    QVariantList getUrevent() const;

    void clearEvent();

    int getPoint_num() const;

signals:
    void saveFinish(QString);
    void mergeMsg(QString msg);
private:
    //文件的名字
    QString name;
    //分段标号
    quint16 number;
    //已保存的采样点数据
    int point_num=0;
    //脑电导联信息
    QVariantList chanlocs;
    //采样率
    quint16 srate;
    //事件序号
    quint32 event_id=0;
    //事件
    QVariantList event;
    //原始事件
    QVariantList urevent;
};
#endif // STORAGE_H
