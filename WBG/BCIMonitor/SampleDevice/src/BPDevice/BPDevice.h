#ifndef BPDEVICE_H
#define BPDEVICE_H
#include "SDK.h"
#include "QStringList"
#include "iostream"
#include "qvector.h"
#include "SampleDevice.h"
#include "RawDataHandlerExample.h"
class BPDevice: public SampleDevice
{
    Q_OBJECT
private:
    /* data */
    CAmplifier amplifier; //采集器
    int model;            //数据读取模式
    QStringList  labels;   //数据标签;
public:
    BPDevice(/* args */);
    virtual ~BPDevice();
    /**********采集器的连接************/
    //选择采样器的类型
    bool SelectDeviceFamily(int);
    //返回可选择的采样器类型
    QStringList GetDeviceFamily();
    //搜索输入接口的设备数目
    int  SearchDeviceNum(int type);
    //返回可以选择的接口
    QStringList GetInterfaceType();
    //连接设备
    bool ConnectDevice(int);
    //关闭设备
    void CloseDevice();
    //获取设备信息
    QString GetDeviceInfo();
    
    /**********设置采集器属性************/
    //设置采样率
    bool SetBaseSampleRate(float);
    bool GetBaseSampleRateRange(QVector<float>& range); 
    //设置通道标签
    bool SetChannelLabel(std::string);
    bool Set10_20();
    //设置阻值
    bool setResistanceValue(int);
    bool setHighPass(float) override;
    bool setLowPass(float) override;
    /**********获取采集器数据************/
    //开始获取数据
    void StartGetData(int model);
    void StartGetData();
    //打印通道数据
    QList<QList<double>> GetData();
    //结束数据的获取
    void StopGetData();
    //获取通道标签
    QStringList getChannelName() override;
    float getBatteryVoltage() override;
    void getBatteryLevel() override;
    /**********功能性************/
    //设置标注
    bool SetAnnotation(std::string);
    //检测阻抗
    bool CheckImpedances();
private:
    //采集器的数据获取
    RawDataHandler *rdh;

};
#endif
