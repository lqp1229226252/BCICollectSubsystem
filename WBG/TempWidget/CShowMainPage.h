#ifndef CSHOWMAINPAGE_H
#define CSHOWMAINPAGE_H

#include <QWidget>
#include "CPlayVideo.h"
#include "MPicturePlayer.h"
#include "CNavigationBar.h"
#include "CShowBorder.h"
#include "CAboutMe.h"
#include "CShopPage.h"
#include "CPlayPicture.h"
namespace Ui {
class CShowMainPage;
}

class CShowMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit CShowMainPage(QWidget *parent = nullptr);
    ~CShowMainPage();
void  setUSerInfo(const QString &qsData);//设置个人信息
private:
    Ui::CShowMainPage *ui;
    CPlayVideo*m_pPlayer;

    MPicturePlayer*m_pPicturePlayer;
    CNavigationBar*m_pNavigationBar;

    CShowBorder*m_pBoder;
    CAboutMe*m_pAboutPage;
    CShopPage*m_pShopPage;


private:
    void setCurrentButton(int iDex);
    void setProductList();
    void setFuncList();
private slots:
    void slot_navigationBarClose();
    void slot_show_index(int);
private slots:
    void on_btn_head_show_clicked();

    void on_btn_show_view_clicked();

    void on_btn_other_video_clicked();

    void on_btn_info_clicked();
};

#endif // CSHOWMAINPAGE_H
