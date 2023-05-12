#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "sample.h"
class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:
private:
    Sample *sample;
};

#endif // TEST_H
