#ifndef MATFILESTORAGE_H
#define MATFILESTORAGE_H
#include "QObject"
#include "mat.h"
#include "storage.h"
#include "mat.h"
class MatStorage:public Storage
{
    Q_OBJECT
public:
    MatStorage();
    ~MatStorage();
    void setChannelLabels(QString lables)override;
    void setChannelNum(quint8 num)override;
public slots:
    void save(double*,int num)override;
    void stop() override;
private:
    MAT mat;
    QString getCurrentFileName();
    QVariantList getEvent(int);
    QVariantList getUrevent(int);
    int sample=0;
    int sample_id=0;
};

#endif // MATSTORAGE_H
