#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "analysisgamemsg.h"
class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    void analysis(QString);

signals:
private:
    AnalysisGameMsg *analysisgamemsg;
};

#endif // TEST_H
