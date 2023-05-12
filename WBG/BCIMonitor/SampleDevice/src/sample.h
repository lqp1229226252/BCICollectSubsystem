#ifndef SAMPLE_H
#define SAMPLE_H

#include <QObject>
#include "SampleDevice.h"
#include "operationthread.h"
#include "datathread.h"
class Sample : public QObject
{
    Q_OBJECT
public:
    typedef enum
    {
        BP=0,
        FILE=1,
        Self_Innovate=2,
    }Deivce;
    typedef enum
    {
        FamilyError=0,
        ConnectError=1,
    }ErrorCode;
    explicit Sample(QObject *parent = nullptr);
    ~Sample();
    void setSampleDeivce(quint8 device);
    void connectDeivce(quint8 id);
    void open(QString);
    QStringList getChannelName();
    QVariantList getChanlocs();

    QStringList GetDeviceFamily();
    QStringList GetInterfaceType();
    float getBatteryVoltage();
    void getBatteryLevel();

    bool CheckImpedances();
    void setResistanceValue(int);
    void start();
    void pause();
    void stop();
public slots:
    void searchDeivce(int family,int type);
signals:
    //搜索的设备数目
    void searchFinish(int);
    //采集的数据
    void readData(QList<double> data);
    //连接成功的信号
    void connectSuccess();
    //错误信号
    void error(int);
private:
    //采集设备
    SampleDevice *sampledevice;
    //设备操作线程
    OperationThread *operationthread;
    //数据获取线程
    DataThread *datathread;
    void init();
    void initSample();
    void initThread();
    void setThreadConnect();
};

#endif // SAMPLE_H
