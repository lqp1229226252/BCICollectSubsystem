#ifndef MPICTUREPLAYER_H
#define MPICTUREPLAYER_H

#include <QWidget>
#include <QPainter>
#include <QParallelAnimationGroup>
#include <QVariantAnimation>
#include <QMouseEvent>
namespace Ui {
class MPicturePlayer;
}

class MPicturePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MPicturePlayer(QWidget *parent = nullptr);
    ~MPicturePlayer();
    void setAutoRun();
    void setFirsrt();
    void append(const QImage& iimage);
    void play(bool isToRight);


private:
    Ui::MPicturePlayer *ui;
private:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void setMoveProgress(qreal pro);
    void setOpacity(qreal opac);
    QRectF paintStand(QPainter* painter, const QSize& baseSize, int i);
    QRectF paintMoveRight(QPainter* painter, const QSize& baseSize, int i);
    QRectF paintMoveLeft(QPainter* painter, const QSize& baseSize, int i);

private:
    static const QPointF vecl; /* 左侧3张图中心移动向量 */
    static const QPointF vecr; /* 右侧3张图中心移动向量 */
    static const qreal lengths[]; /* 每张图片距中心的距离 */
    static const qreal scales[]; /* 每张图片的缩放系数 */
    int currIndex;
    qreal moveRate;
    qreal opacity;
    QPoint pressPt;
    QRectF rect2Or4; /* 图片2或4的UI矩形 */
    QVector<QImage> images;
};

#endif // MPICTUREPLAYER_H

