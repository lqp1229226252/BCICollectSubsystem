#ifndef CABOUTME_H
#define CABOUTME_H

#include <QWidget>

namespace Ui {
class CAboutMe;
}

class CAboutMe : public QWidget
{
    Q_OBJECT

public:
    explicit CAboutMe(QWidget *parent = nullptr);
    ~CAboutMe();
    void setText();

private:
    Ui::CAboutMe *ui;
};

#endif // CABOUTME_H
