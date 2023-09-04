#include "gamefinishwidget.h"
#include "QApplication"
#include "QDebug"
int main(int args,char** argv)
{
   QApplication app(args,argv);
   GameFinishWidget w;
   w.setGameFilePath("D:\\project\\Qt\\WebrainRecorder\\数据");
   QMap<QString, QString> data;
   data.insert("GameType", "1");
   data.insert("TotalScore", "85");
   data.insert("AverageReactTime", "0.8");
   data.insert("AverageRightReactTime", "1.14");
   data.insert("TotalEnemyNum", "24");
   data.insert("TotalKillNum", "20");
   data.insert("TotalMissNum", "1.14");
   data.insert("TotalWrongNum", "24");
   data.insert("TotalFire", "20");
   data.insert("TotalGameTime", "53.2");
   data.insert("HitRate", "80.25");
//   for(int i=0;i<10;i++)
//   {
//      w.showWidget(data);
//   }
   w.show();
   app.exec();
}
