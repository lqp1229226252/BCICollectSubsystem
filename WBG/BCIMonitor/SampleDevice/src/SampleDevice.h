#ifndef SAMPLEDEVICE_H
#define SAMPLEDEVICE_H
#include "QObject"
#include "iostream"
#include "QVariantList"
Q_DECLARE_METATYPE(QList<double>)
class SampleDevice:public QObject
{
    Q_OBJECT
public:
    SampleDevice();
    virtual ~SampleDevice();
    /**********采集器的连接************/
    //选择采样器的类型
    virtual bool SelectDeviceFamily(int){return false;};
    //返回可选择的采样器类型
    virtual QStringList GetDeviceFamily(){return {""};};
    //搜索输入接口的设备数目
    virtual int  SearchDeviceNum(int ){return -1;};
    //返回可以选择的接口
    virtual QStringList GetInterfaceType(){return  {""};};
    //连接设备
    virtual bool ConnectDevice(int){return false;};
    //关闭设备
    virtual void CloseDevice(){};
    //打开设备
    virtual bool open(QString name){return false;};
    //获取设备信息
    virtual QString GetDeviceInfo(){return "";};
    
    /**********设置采集器属性************/
    //设置采样率
    virtual bool SetBaseSampleRate(float);
    virtual bool GetBaseSampleRateRange(QVector<float>&){return false;};
    quint16 GetSmapleRate();
    //设置通道标签
    virtual bool SetChannelLabel(std::string){return false;};
    virtual bool Set10_20(){return false;};
    //设置阻值
    virtual bool setResistanceValue(int){return false;};
    //设置高通滤波
    virtual bool setHighPass(float){return false;};
    //设置低通滤波
    virtual bool setLowPass(float){return false;};
    /**********获取采集器数据************/
    //开始获取数据
    virtual void StartGetData(int);
    //打印通道数据
    virtual QList<QList<double>> GetData()=0;
    //结束数据的获取
    virtual void StopGetData(){};
    //获取通道名字
    virtual QStringList getChannelName(){return  {""};}
    //获取采集器的电压
    virtual float getBatteryVoltage(){return 0.0;};
    //获取采集的充电水平
    virtual void getBatteryLevel(){};
    //获取采集器的连接状态
//    virtual bool getConnectStatus(){};
    /**********功能性************/
    //设置标注
    virtual bool SetAnnotation(std::string){return false;};
    //检测阻抗
    virtual bool CheckImpedances(){return false;};
    void readChanlocs(QString path);
    void readChanlocs(QStringList label);
    QVariantList getChanlocs() const;
signals:
    void searchFinish(int);
    void error(QString);
    void readData(QList<double>);
public slots:
    virtual void StartGetData(){};
private:
    int srate;
    QVariantList chanlocs;
};
#endif
