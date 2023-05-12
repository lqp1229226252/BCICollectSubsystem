#ifndef DATATHREAD_H
#define DATATHREAD_H

#define TESTENABLE 0
#include "QThread"
#include "SampleDevice.h"
class DataThread:public QThread
{
    Q_OBJECT
public:
    explicit DataThread(QObject *parent=nullptr);
    ~DataThread();
    void setDeivce(SampleDevice *);
    void run() override;
    void setStatus(bool value);

    void destroy();

signals:
    void readFinish(QList<double>);
private:
    SampleDevice *device;
    bool status;
    bool destroyFlag;
};

#endif // DATATHREAD_H
