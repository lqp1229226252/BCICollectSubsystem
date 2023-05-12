#ifndef FILEDEVICE_H
#define FILEDEVICE_H

#include <QObject>
#include "SampleDevice.h"
#include "QProcess"
#include "eegdata.h"
class FileDevice:public SampleDevice
{
public:
    FileDevice();
    bool open(QString name) override;
    QList<QList<double>> GetData() override;
    QStringList getChannelName() override;
    void StartGetData() override;
    void StopGetData() override;
private:
    QProcess *process;
    EEGData eegdata;
    void init();
    bool readVHDR(QString);
    bool readTXT(QString);
    bool readBIN(QString);
    bool readCSV(QString);
};

#endif // FILEDEVICE_H
