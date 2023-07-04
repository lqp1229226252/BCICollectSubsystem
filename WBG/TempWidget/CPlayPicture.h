#ifndef CPLAYPICTURE_H
#define CPLAYPICTURE_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class CPlayPicture;
}

class CPlayPicture : public QWidget
{
    Q_OBJECT

public:
    explicit CPlayPicture(QWidget *parent = nullptr);
    ~CPlayPicture();

private:
    Ui::CPlayPicture *ui;
protected:
    const QString popImage();

    void takeAnimation();

    void timerEvent( QTimerEvent *event );

private:
    void onAnimation0Finished();

    void onAnimation1Finished();

signals:
    void TakeAnimation();

private:
    QVector<QString>    aryImage;

    QWidget             *widget0;

    QWidget             *widget1;

    QPropertyAnimation  *animation0;

    QPropertyAnimation  *animation1;
};

#endif // CPLAYPICTURE_H
