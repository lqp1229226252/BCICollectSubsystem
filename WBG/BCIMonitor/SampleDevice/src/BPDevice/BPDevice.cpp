#include "BPDevice.h"

#include "QDebug"
BPDevice::BPDevice()
{
    Set10_20();
}
BPDevice::~BPDevice()
{
    this->amplifier.StopAcquisition();
}
QStringList BPDevice::GetDeviceFamily()
{
    QStringList familys;
    familys.append("LiveAmp");
    familys.append("actiCHamp");
    return familys;
}
bool BPDevice::SelectDeviceFamily(int family)
{

    int res = SetAmplifierFamily((AmplifierFamily)family);
    if(res==AMP_OK)
    return true;
    else
    return false;
} 
QStringList BPDevice::GetInterfaceType()
{
    QStringList familys; 
    familys.append("any");
    familys.append("usb");
    familys.append("bluetooth");
    familys.append("sim");
    return familys;
}
int BPDevice::SearchDeviceNum(int InterfaceType)
{
    std::string sHWDeviceAddress ="";
    char hwi[20];
	switch (InterfaceType)
	{
	case 3:
		strcpy_s(hwi, "SIM");
		break;
	case 2:
		strcpy_s(hwi, "BT");
		break;
	case 1:
		strcpy_s(hwi, "USB");
		break;
	default:
		strcpy_s(hwi, "ANY");
		break;
	}
    int num= EnumerateDevices(hwi, sizeof(hwi), (const char*)sHWDeviceAddress.data(), 0);
    return num;
}

void BPDevice::CloseDevice()
{
    this->amplifier.Close();
}
QString BPDevice::GetDeviceInfo()
{
    if(this->amplifier.m_hAmplifier==NULL)
    {  
       throw "amplifier don't connection";
    }
    else
    {
        int channel_num;
        this->amplifier.GetProperty(channel_num,DPROP_I32_AvailableChannels);
        int use_channel_num;
        this->amplifier.GetProperty(use_channel_num,0,MPROP_I32_UseableChannels);
        float sample_rate;
        this->amplifier.GetProperty(sample_rate,DPROP_F32_BaseSampleRate);
        std::string family;
        this->amplifier.GetProperty(family,DPROP_CHR_Family);
        std::string type;
        this->amplifier.GetProperty(type,DPROP_CHR_Type);
        std::string interfacetype;
        this->amplifier.GetProperty(interfacetype,DPROP_CHR_Type);
        int modules_num;
        this->amplifier.GetProperty(modules_num,DPROP_I32_AvailableModules);
        QString info;
        info+="channel num:"+QString::number(channel_num);
        info+="\n used channel num:"+QString::number(use_channel_num);
        info+="\nsample rate:"+QString::number(sample_rate);
        info+="\nsmaple family:"+QString::fromStdString(family);
        info+="\nsmaple type:"+QString::fromStdString(type);
        info+="\ninterface type:"+QString::fromStdString(interfacetype);
        info+="\nmodule num:"+QString::number(modules_num);
        info+="\n";
        return info; 
    }
}
bool BPDevice::SetBaseSampleRate(float sample_rate)
{
    SampleDevice::SetBaseSampleRate(sample_rate);
    return this->amplifier.SetProperty(sample_rate,DPROP_F32_BaseSampleRate);
}
bool BPDevice::GetBaseSampleRateRange(QVector<float> &range)
{
    range.clear();
    PropertyRange<float> prAvailableSampleRates;
    int res=this->amplifier.GetPropertyRange(prAvailableSampleRates,DPROP_F32_BaseSampleRate);
    if(res!=AMP_OK)
    {
        return false;
    }
    else
    {
        int nAvailable=prAvailableSampleRates.ByteLength/sizeof(float);
        for(int i=0;i<nAvailable;i++)
        {
            range.append(prAvailableSampleRates.RangeArray[i]);
        }
        return true;
    }
}
bool BPDevice::SetChannelLabel(std::string channel_label)
{
    this->labels=QString::fromStdString(channel_label).split(",");
    return true;
//    return CStorage::SetChannelLabels(this->amplifier.m_hAmplifier,channel_label.c_str());
}
bool BPDevice::Set10_20()
{
    QString channel_label="Fp1,Fp2,F7,F3,Fz,F4,F8,FC5,FC1,FC2,FC6,T7,C3,Cz,C4,T8,TP9,CP5,CP1,CP2,CP6,TP10,P7,P3,Pz,P4,P8,PO9,O1,Oz,O2,PO10";
    labels=channel_label.split(",");
    SampleDevice::readChanlocs(labels);
    return true;
//    std::string channel_label="Fp1,Fp2,F7,F3,Fz,F4,F8,FC5,FC1,FC2,FC6,T7,C3,Cz,C4,T8,TP9,CP5,CP1,CP2,CP6,TP10,P7,P3,Pz,P4,P8,PO9,O1,Oz,O2,PO10";
    //    return this->SetChannelLabel(channel_label.c_str());
}

bool BPDevice::setResistanceValue(int value)
{

    int res=amplifier.SetProperty(value,DPROP_I32_GoodImpedanceLevel);
    if(res==AMP_OK)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool BPDevice::setHighPass(float value)
{
    for(int i=0;i<32;i++)
    {
         int res=amplifier.SetProperty(value,i,CPROP_F32_HighPass);
         if(res!=AMP_OK)
         {
             return false;
         }
    }
    {
        return true;
    }
}

bool BPDevice::setLowPass(float value)
{
    for(int i=0;i<32;i++)
    {
         int res=amplifier.SetProperty(value,i,CPROP_F32_LowPass);
         if(res!=AMP_OK)
         {
             return false;
         }
    }
    {
        return true;
    }
}
void BPDevice::StartGetData(int model)
{
    if((model<=0)&&(model>=3))
    {
        throw "Don't exsit this model";
    }
    this->model=model;
    int res=this->amplifier.StartAcquisition((RecordingMode)model);
}

void BPDevice::StartGetData()
{
   StartGetData(1);
   SampleDevice::StartGetData();
}

bool BPDevice::ConnectDevice(int DeviceId)
{
    this->amplifier.m_hAmplifier=NULL;
    int res=this->amplifier.Open(DeviceId);
    rdh=new RawDataHandler(this->amplifier);
    if(res!=AMP_OK)
    {
        emit error("连接失败");
        return false;
    }
    else
    {
        return true;
    }
}

QList<QList<double>> BPDevice::GetData()
{
    QList<QList<double>> data;
    std::vector<std::vector<float>> vvfData;
    //采集器的数据获取
    int nSamples = 0;
    while (nSamples == 0)
        nSamples = rdh->ParseRawData(this->amplifier, vvfData);
    for(int i=0;i<nSamples;++i){
        //数据截断只取32通道数据
        std::vector<double> tmp = std::vector<double>(vvfData[i].begin(), vvfData[i].begin()+32);
        data.append(QVector<double>::fromStdVector(tmp).toList());
    }
    return data;
}
void BPDevice::StopGetData()
{
    int res=this->amplifier.StopAcquisition();
    SampleDevice::StopGetData();
}

QStringList BPDevice::getChannelName()
{
    return this->labels;
}

float BPDevice::getBatteryVoltage()
{
    float value;
    amplifier.GetProperty(value,DPROP_F32_BatteryVoltage);
    return value;
}

void BPDevice::getBatteryLevel()
{
    t_BatteryState value;
    amplifier.GetProperty(value,DPROP_I32_BatteryLevel);
}
bool BPDevice::SetAnnotation(std::string Description)
{
    int res=CStorage::SetAnnotation(this->amplifier.m_hAmplifier,Description.c_str());
    if(res==AMP_OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool BPDevice::CheckImpedances()
{
    BOOL bChannelSupportImp;
    int nRet;
    int nAvailableChannels;
    int nImpChns = 0;
    amplifier.GetProperty(nAvailableChannels, DPROP_I32_AvailableChannels);
    for (int i = 0; i < nAvailableChannels; i++)
    {
        nRet = amplifier.GetProperty(bChannelSupportImp, i, CPROP_B32_ImpedanceMeasurement);
        nRet = amplifier.GetProperty(bChannelSupportImp, i, CPROP_F32_Resolution);
        if (!bChannelSupportImp || nRet < 0)
            continue;

        nImpChns++;
    }
    if(nImpChns==39)
    {
        return true;
    }
    else
    {
        return false;
    }

}
