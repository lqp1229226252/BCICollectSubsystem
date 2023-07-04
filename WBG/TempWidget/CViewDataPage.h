#ifndef CVIEWDATAPAGE_H
#define CVIEWDATAPAGE_H

#include <QWidget>

namespace Ui {
class CViewDataPage;
}

class CViewDataPage : public QWidget
{
    Q_OBJECT

public:
    explicit CViewDataPage(QWidget *parent = nullptr);
    ~CViewDataPage();

private:
    Ui::CViewDataPage *ui;
};

#endif // CVIEWDATAPAGE_H
