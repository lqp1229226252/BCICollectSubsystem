## ftpconfig.h

​	配置文件类，将上传文件所需的服务器信息配置成文件。

​	公有函数：

```c++
	//读取配置文件
    QUrl getFTPConfig();

    //写入配置文件
    void setFTpConfig(QUrl);
```

## uploadfilehandler.h

​	上传文件类，该类在初始化时会自动读取配置文件设置url。配置文件在.exe同级目录下。

​	公有（槽）函数：

```C++
	QUrl getUrl() const;
    void setUrl(const QUrl &value);	//会自动生成配置文件

	// 文件名(绝对路径)传参
    void uploadFile(QString filePath);
	
```

在使用uploadfilehandler类时，不需要单独去调用ftpconfig。只需要使用setUrl就会生成配置文件，下次使用时，就不需要再setUrl。或者直接在已有的配置文件中修改服务器信息。

使用setUrl会覆盖配置文件中已有的服务器信息。

