#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "CPlayVideo.h"
#include "MPicturePlayer.h"
#include "CNavigationBar.h"
#include "CShowBorder.h"
#include "CAboutMe.h"
#include "CShopPage.h"
#include "CPlayPicture.h"
#include <QShowEvent>
#include "CViewDataPage.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void  setUSerInfo(const QString &qsData);//设置个人信息
protected:
    virtual void showEvent(QShowEvent *event);

private slots:
    void on_btn_head_show_clicked();

    void on_btn_show_view_clicked();

    void on_btn_other_video_clicked();

    void on_btn_info_clicked();

private:
    Ui::MainWindow *ui;

    CPlayVideo*m_pPlayer;

    MPicturePlayer*m_pPicturePlayer;
    //CPlayPicture*m_pPicturePlayer;
    CNavigationBar*m_pNavigationBar;

    CShowBorder*m_pBoder;
    CAboutMe*m_pAboutPage;
    CShopPage*m_pShopPage;
    CViewDataPage*m_pViewDataPage;


private:
    void setCurrentButton(int iDex);
    void setProductList();
    void setFuncList();
private slots:
    void slot_navigationBarClose();
    void slot_show_index(int);
};
#endif // MAINWINDOW_H
