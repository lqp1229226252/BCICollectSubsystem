#ifndef OPERATIONTHREAD_H
#define OPERATIONTHREAD_H

#include "QThread"
class OperationThread:public QThread
{
    Q_OBJECT
public:
    OperationThread(QObject *parent=nullptr);
    void setDeivce(void *);
    void run() override;
    void setType(int value);

    void setDevice_id(int value);

    void setConnectflag();

    void setSearchflag();

signals:
    void deviceNum(int);
    void connectStatus(bool);
private:
     void *device;
     bool connectflag;
     int device_id;
     bool searchflag;
     int type;
};

#endif // OPERATIONTHREAD_H
