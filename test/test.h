#ifndef TEST_H
#define TEST_H

#include "uploadfilehandler.h"
#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    ~test();

    void init();


    UploadFileHandler *handler;


signals:

private:
    QUrl url;


};

#endif // TEST_H
