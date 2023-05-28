
gameoverwidget.h：游戏结束结算类
	公有（槽）函数：
		void onAnalyzeMsgDone();	// 将数据呈现到界面上

		void setMap(QMap<QString, QString>);	// 接受到analyzegamemsgtool中传来的map，// 触发analyzeMsgDoneSignal信号
	信号：
		void setGameOverMsgSignal();
    		void analyzeMsgDoneSignal();
	
	游戏结算界面自动弹出。
	