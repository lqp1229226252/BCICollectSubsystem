#ifndef WBGWIDGET_H
#define WBGWIDGET_H

#include <QWidget>
#include "./src/indexwidget.h"
#include "./src/introducewidget.h"
#include "./src/login.h"
#include "QMouseEvent"
QT_BEGIN_NAMESPACE
namespace Ui { class WBGWIdget; }
QT_END_NAMESPACE

class WBGWIdget : public QWidget
{
    Q_OBJECT

public:
    WBGWIdget(QWidget *parent = nullptr);
    ~WBGWIdget();
    void initParams();
    void setConnect();
    void setLayout();
    void initIndexWidget();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::WBGWIdget *ui;
    bool  move_flage;//窗口移动标志
    int last_mouse_x;    //上一次的鼠标x坐标
    int last_mouse_y;    //上一次的鼠标y坐标

    IndexWidget *indexWidget;
    IntroduceWidget *introduceWidget;

    login *loginWidget;


};
#endif // WBGWIDGET_H
