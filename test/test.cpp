#include "test.h"
#include "uploadfilehandler.h"

test::test(QObject *parent) : QObject(parent)
{
    init();
//    handler->manager->connectToHost("10.23.67.168", 21);
}

test::~test()
{

}

void test::init()
{
    handler = new UploadFileHandler();

//    url.setHost("10.23.67.168");
//    url.setPort(21);
//    url.setUserName("zzh");
//    url.setPassword("zzh");
//    url.setScheme("ftp");
//    url.setPath("/ttt");

//    handler->setUrl(url);

    qDebug() << handler->getUrl();


}
