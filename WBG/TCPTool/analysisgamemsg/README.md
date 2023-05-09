# analysisgamemsg
## 接口
### 信号
```
void gameFinish(QMap<QString,QString>); //游戏结束
void gameStart(QMap<QString,QString>);  //游戏开始
void gameEnemyBorn(QMap<QString,QString>); //敌人刷新
void gameEnemyDie(QMap<QString,QString>);  ///敌人死亡
void gameFireHit(QMap<QString,QString>);   //开枪
void gameFireMiss(QMap<QString,QString>);  //开枪未命中
void gameCutHit(QMap<QString,QString>);    //挥砍命中
```
