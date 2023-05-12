# BCIMonitor

## 接口

### 信号

```
 void downData(QString); //发给游戏的数据
 void saveFinish(QString);//文件保存结束
```

### 函数

```
  void setFileMsg(QString,QString,int);//文件信息
  void appendMarkEnemyBorn(QMap<QString,QString>);//敌人刷新
  void appendMarkEnemyDie(QMap<QString,QString>);//敌人死亡
  void appendMarkFireHit(QMap<QString,QString>);//开枪命中
  void appendMarkFireMiss(QMap<QString,QString>);//开枪未命中
  void appendMarkCutHit(QMap<QString,QString>);//挥砍未命中
```
