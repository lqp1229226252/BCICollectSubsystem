## drawcharts.h

图表类。初始时从本地的最新文件读取数据呈现到图表上。实时显示数据。

本地文件存放位置：

```
D:/BCIData/FTP-LocalSave
```

接口：

```c++
void getRecChartDatas(QMap<QString, double>);
// 外部传map到这个信号，将map解析到图表上。
```

