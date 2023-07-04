#include "MPicturePlayer.h"
#include "ui_MPicturePlayer.h"


const QPointF MPicturePlayer::vecl(0.99619469, -0.08715574); /* 左侧3张图中心移动向量 */
const QPointF MPicturePlayer::vecr(0.99619469, 0.08715574); /* 右侧3张图中心移动向量 */
const qreal MPicturePlayer::lengths[] = { -340, -220, -100, 0, 100, 220, 340 }; /* 每张图片距中心的距离 */
//const qreal MPicturePlayer::scales[] = { 0.3, 0.6, 0.85, 1, 0.85, 0.6, 0.3 }; /* 每张图片的缩放系数 */
const qreal MPicturePlayer::scales[] = { 0.6, 0.9, 1, 1.2, 1, 0.9, 0.6 }; /* 每张图片的缩放系数 */

MPicturePlayer::MPicturePlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MPicturePlayer)
{
    ui->setupUi(this);
    currIndex = 0;
    moveRate = 0;
    opacity = 0;
}

MPicturePlayer::~MPicturePlayer()
{
    delete ui;
}
void MPicturePlayer::setFirsrt()
{

    QImage qimage(":/image/image/sy1.png");
    append(qimage);

    QImage qimage2(":/image/image/sy2.png");
    append(qimage2);

    QImage qimage3(":/image/image/sy3.png");
    append(qimage3);

    QImage qimage4(":/image/image/sy4.png");
    append(qimage4);

    QImage qimage5(":/image/image/sy5.png");
    append(qimage5);

    play(true);
}
void MPicturePlayer::setAutoRun()
{
    QImage qimage(":/image/image/ai.jpg");
    append(qimage);

    QImage qimage2(":/image/image/horror-5042320_1920.jpg");
    append(qimage2);

    QImage qimage3(":/image/image/image/soldier.jpg");
    append(qimage3);

    QImage qimage4(":/image/image/image/warrior-7631678.jpg");
    append(qimage4);

    QImage qimage5(":/image/image/sci-fi-6770027_1920.jpg");
    append(qimage5);


    play(true);
}
void MPicturePlayer::append(const QImage& iimage)
{
    if (images.empty())
    {
        images.push_back(iimage);
        return;
    }
    QSize exist = images.first().size();
    if (exist == iimage.size())
    {
        images.push_back(iimage);
    }
    else
    {
        images.push_back(iimage.scaled(exist));
    }
}

//---------------------------------------------------------------------------------------
// 这里的图片轮播一次只显示5张图，点击鼠标可以轮播图片。为了绘制动画，我们定义了7个
// 数据（lengths和scales），正常情况最边上2个不显示图片。画控件的时候，从两边向中间
// 绘制以保证中间那张图在最上方。见下面的变量indexs。
// 另外，图片大小要配合控件大小才能有良好的显示效果。
//---------------------------------------------------------------------------------------
void MPicturePlayer::paintEvent(QPaintEvent *event)
{//
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), QColor(255,255,255,0));
    int count = images.size();
    if (count == 0)
    {
        return; /* 无图 */
    }
    if (moveRate == 1.0)
    {
        currIndex = (currIndex + count - 1) % count;
        moveRate = 0;
    }
    if (moveRate == -1.0)
    {
        currIndex = (currIndex + 1) % count;
        moveRate = 0;
    }
    QSize baseSize = images.first().size().scaled(size() * 0.6, Qt::KeepAspectRatio);
    int indexs[] = { 0, 6, 1, 5, 2, 4, 3 }; /* 绘制图片的顺序 */
    if (moveRate > 0)
    {
        /* 默认的indexs是先画左2后画右4 */
        /* 这会导致右4在上方，从而使动画出现明显的可见的顿挫感 */
        /* 所以在图片右移时先画右4后画左2 */
        std::swap(indexs[4], indexs[5]);
    }
    for (auto i : indexs)
    {
        QRectF thisRect;
        if (moveRate == 0 && i != 0 && i != 6)
        {
            thisRect = paintStand(&painter, baseSize, i);
        }
        if (moveRate > 0 && i != 6) /* 图片向右移 */
        {
            thisRect = paintMoveRight(&painter, baseSize, i);
        }
        if (moveRate < 0 && i != 0) /* 图片向左移 */
        {
            thisRect = paintMoveLeft(&painter, baseSize, i);
        }
        if (i != 3)
        {
            int alpha = 32 * abs(i - 3);
            painter.fillRect(thisRect, QColor(0, 0, 0, alpha));
        }
    }
}

QRectF MPicturePlayer::paintStand(QPainter* painter, const QSize& baseSize, int i)
{
    int count = images.size();
    QPointF center(width() * 0.5, height() * 0.5);
    QPointF thisPos = center + lengths[i] * (i < 3 ? vecl : vecr);
    QSize thisSize = baseSize * scales[i];
    QRectF thisRect;
    thisRect.setX(thisPos.x() - thisSize.width() * 0.5);
    thisRect.setY(thisPos.y() - thisSize.height() * 0.5);
    thisRect.setSize(thisSize);
    int hitIndex = (currIndex + count + (i - 3)) % count;
    painter->drawImage(thisRect, images[hitIndex]);
    return thisRect;
}

//---------------------------------------------------------------------------------------
// 图片向右移动
//---------------------------------------------------------------------------------------
QRectF MPicturePlayer::paintMoveRight(QPainter* painter, const QSize& baseSize, int i)
{
    int count = images.size();
    QPointF center(width() * 0.5, height() * 0.5);
    qreal value = lengths[i] + (lengths[i + 1] - lengths[i]) * moveRate;
    qreal scale = scales[i] + (scales[i + 1] - scales[i]) * moveRate;
    QPointF thisPos = center + value * (i < 3 ? vecl : vecr);
    QSize thisSize = baseSize * scale;
    QRectF thisRect;
    thisRect.setX(thisPos.x() - thisSize.width() * 0.5);
    thisRect.setY(thisPos.y() - thisSize.height() * 0.5);
    thisRect.setSize(thisSize);
    if (i == 2)
    {
        rect2Or4 = thisRect;
    }
    int hitIndex = (currIndex + count + (i - 3)) % count;
    QImage thisImage = images[hitIndex];
    if (i == 3) /* 3必须在2后面绘制 */
    {
        QRectF cross = thisRect.intersected(rect2Or4);
        qreal uiCross = cross.width(); /* 这里是左侧重叠 */
        QRectF uiLeft(thisRect.x(), thisRect.y(), uiCross, thisRect.height());
        QRectF uiRight(thisRect.x() + uiCross, thisRect.y(), thisRect.width() - uiCross, thisRect.height());
        qreal imCross = uiCross * (thisImage.width() / thisRect.width());
        QRectF imLeft(0, 0, imCross, thisImage.height());
        QRectF imRight(imCross, 0, thisImage.width() - imCross, thisImage.height());
        painter->save();
        painter->setOpacity(opacity);
        painter->drawImage(uiLeft, thisImage, imLeft);
        painter->restore();
        painter->drawImage(uiRight, thisImage, imRight);
    }
    else if (i == 5)
    {
        painter->save();
        painter->setOpacity(opacity);
        painter->drawImage(thisRect, thisImage);
        painter->restore();
    }
    else
    {
        painter->drawImage(thisRect, thisImage);
    }
    return thisRect;
}

//---------------------------------------------------------------------------------------
// 图片向左移动
//---------------------------------------------------------------------------------------
QRectF MPicturePlayer::paintMoveLeft(QPainter* painter, const QSize& baseSize, int i)
{
    int count = images.size();
    QPointF center(width() * 0.5, height() * 0.5);
    qreal value = lengths[i] + (lengths[i - 1] - lengths[i]) * -moveRate;
    qreal scale = scales[i] + (scales[i - 1] - scales[i]) * -moveRate;
    QPointF thisPos = center + value * (i > 3 ? vecr : vecl);
    QSize thisSize = baseSize * scale;
    QRectF thisRect;
    thisRect.setX(thisPos.x() - thisSize.width() * 0.5);
    thisRect.setY(thisPos.y() - thisSize.height() * 0.5);
    thisRect.setSize(thisSize);
    if (i == 4)
    {
        rect2Or4 = thisRect;
    }
    int hitIndex = (currIndex + count + (i - 3)) % count;
    QImage thisImage = images[hitIndex];
    if (i == 3)
    {
        QRectF cross = thisRect.intersected(rect2Or4);
        qreal uiCross = cross.width(); /* 这里是右侧重叠 */
        QRectF uiLeft(thisRect.x(), thisRect.y(), thisRect.width() - uiCross, thisRect.height());
        QRectF uiRight(thisRect.x() + thisRect.width() - uiCross, thisRect.y(), uiCross, thisRect.height());
        qreal imCross = uiCross * (thisImage.width() / thisRect.width());
        QRectF imLeft(0, 0, thisImage.width() - imCross, thisImage.height());
        QRectF imRight(thisImage.width() - imCross, 0, imCross, thisImage.height());
        painter->save();
        painter->setOpacity(opacity);
        painter->drawImage(uiRight, thisImage, imRight);
        painter->restore();
        painter->drawImage(uiLeft, thisImage, imLeft);
    }
    else if (i == 1)
    {
        painter->save();
        painter->setOpacity(opacity);
        painter->drawImage(thisRect, thisImage);
        painter->restore();
    }
    else
    {
        painter->drawImage(thisRect, thisImage);
    }
    return thisRect;
}

void MPicturePlayer::setMoveProgress(qreal pro)
{
    moveRate = pro; /* [0,1] */
    update();
}

void MPicturePlayer::setOpacity(qreal opac)
{
    opacity = opac; /* [0,1] */
    update();
}

void MPicturePlayer::mousePressEvent(QMouseEvent *event)
{
    pressPt = event->pos();
}

void MPicturePlayer::mouseReleaseEvent(QMouseEvent *event)
{
    if (pressPt == event->pos())
    {
        bool isClickLeft = (pressPt.x() < width() / 2);
        play(isClickLeft); /* 点的太快会有BUG */
    }
}

void MPicturePlayer::play(bool isToRight)
{
    QParallelAnimationGroup* group = new QParallelAnimationGroup(this);
    QVariantAnimation* ani1 = new QVariantAnimation(group);
    ani1->setStartValue(0.0);
    ani1->setEndValue(isToRight ? 1.0 : -1.0);
    ani1->setDuration(200);
    connect(ani1, &QVariantAnimation::valueChanged, this,
        [this](const QVariant& value) { setMoveProgress(value.toDouble()); });
    QVariantAnimation* ani2 = new QVariantAnimation(group);
    ani2->setStartValue(1.0);
    ani2->setEndValue(0.0);
    ani2->setDuration(200);
    connect(ani2, &QVariantAnimation::valueChanged, this,
        [this](const QVariant& value) { setOpacity(value.toDouble()); });
    group->addAnimation(ani1);
    group->addAnimation(ani2);
    group->start(QVariantAnimation::DeleteWhenStopped);
}
