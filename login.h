#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_min_clicked();

private:
    Ui::login *ui;

    //拖拽窗口函数
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //拖拽窗口变量
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

};
#endif // LOGIN_H
