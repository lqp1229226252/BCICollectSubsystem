#ifndef SAVEFILETOBCI_H
#define SAVEFILETOBCI_H

#include <QObject>
#include <QFile>
#include "uploadfileftp.h"
/*这个类的主要工作是扫描FTP文件夹中是否有文件到来
根据后缀名判断是什么文件
1. xxx.bci 就保存到本地，后续交由其他类完成显示 保存方式为新建一个 账号_时间_游戏ID.monitor的文件，每次往这个文件中追加数据
2. xxx.gam 不做任何处理直接转发给游戏端
3.以上两种文件一旦处理完就直接从FTP文件夹中删除
*/
class SaveFileToBCI : public QObject
{
    Q_OBJECT
public:
    explicit SaveFileToBCI(QObject *parent = nullptr);
    void setFTPSavePath(const QString path);
    void setLocalSavePath(const QString path);
    ~SaveFileToBCI();
private:

    //测试，调用的时候参考这
    void SaveFileToBCI::test(void);

    void timerEvent(QTimerEvent *event) override;

    void HandelFile(void);
    void HandelBCIFile(const QString filename);
    void HandelGamFile(const QString filename);
    bool isFileExist(QString fullFileName);
    bool isDirExist(QString fullPath);//若无则创建
    //获取路径中文件名列表
    QStringList GetFileNameList(const QString &strDirpath);
    QString FTPFileDir;
    QString SaveFileDir;
    UploadFileFTP upLoadFileFtp;


signals:

};

#endif // SAVEFILETOBCI_H
