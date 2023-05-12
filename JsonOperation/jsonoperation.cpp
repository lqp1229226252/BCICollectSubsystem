#include "jsonoperation.h"

#include <QFile>


JsonOperation::JsonOperation()

{

}

void JsonOperation::landID(QString account, QString password, int isAutoLand, int isSavePassword)
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    file.close();

    QJsonObject obj= jdc.object();

    obj.insert("isAutoLand",isAutoLand); //0或1
    obj.insert("isSavePassword",isSavePassword);
    obj.insert("lastAccount",account);  //这次登录的账号
    if(isSavePassword){
        //保存密码到配置文件
        obj.insert(account,password);
    }
    else{
        obj.insert(account,"");
    }

    QJsonDocument doc(obj);
    QByteArray json=doc.toJson();
    file.open(QFile::WriteOnly);
    file.write(json);
    file.close();
}
