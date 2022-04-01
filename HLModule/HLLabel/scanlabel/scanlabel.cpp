/*********************************************************
** 描述：该模块实现了一个扫描显示控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#include "scanlabel.h"

#include <QTimer>
#include <QPainter>
#include <QPainterPath>

ScanLabel::ScanLabel(QWidget *parent)
    : QWidget(parent)
{
    m_imageRadius = 10;
    m_imageBorderWidth = 5;
    m_scanRadius = 50;
    m_scanDeg = 0;

    QPixmap pix(1, 1);
    pix.fill(Qt::white);
    m_image = pix;

    m_imageBorderColor = QColor(255, 255, 255);
    m_scanColor = QColor(255, 100, 10);

    m_circleTimer = new QTimer(this);
    m_circleTimer->setInterval(20);
    m_circleTimer->start();
    connect(m_circleTimer, SIGNAL(timeout()), SLOT(updateRender()));
}

ScanLabel::~ScanLabel()
{
    delete m_circleTimer;
}

void ScanLabel::setImage(const QPixmap &image)
{
    if (image.cacheKey() != m_image.cacheKey()) {
        m_image = image;
    }
}

void ScanLabel::setImageRadius(int imageRadius)
{
    if (imageRadius != m_imageRadius) {
        m_imageRadius = imageRadius;
    }
}

void ScanLabel::setImageBorderWidth(int imageBorderWidth)
{
    if (imageBorderWidth != m_imageBorderWidth) {
        m_imageBorderWidth = imageBorderWidth;
    }
}

void ScanLabel::setImageBorderColor(const QColor &imageBorderColor)
{
    if (imageBorderColor != m_imageBorderColor) {
        m_imageBorderColor = imageBorderColor;
    }
}

void ScanLabel::setScanRadius(int scanRadius)
{
    if (scanRadius != m_scanRadius) {
        m_scanRadius = scanRadius;
    }
}

void ScanLabel::setScanColor(const QColor &scanColor)
{
    if (scanColor != m_scanColor) {
        m_scanColor = scanColor;
    }
}

QSize ScanLabel::sizeHint() const
{
    return QSize(180, 180);
}

void ScanLabel::updateRender()
{
    m_scanDeg -= 3;          //clockwise
    update();
}

void ScanLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int w = width();
    const int h = height();
    const int side = qMin(w, h);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.translate(w / 2, h / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawScan(&painter);
    drawImage(&painter);
}

void ScanLabel::drawScan(QPainter *painter)
{
    painter->save();

    QConicalGradient conicalGradient(0, 0, m_scanDeg);

    QColor color = m_scanColor;
    color.setAlpha(50);
    conicalGradient.setColorAt(0, color);
    color.setAlpha(0);
    conicalGradient.setColorAt(1, color);

    QPen pen;
    pen.setBrush(conicalGradient);
    painter->setPen(Qt::NoPen);
    painter->setBrush(conicalGradient);

    QRect rect(-m_scanRadius, -m_scanRadius, m_scanRadius * 2, m_scanRadius * 2);
    painter->drawPie(rect, m_scanDeg * 16, 360 * 16);
    painter->restore();
}

void ScanLabel::drawImage(QPainter *painter)
{
    painter->save();

    QPainterPath path;
    path.addEllipse(QPoint(0, 0), m_imageRadius, m_imageRadius);
    painter->setClipPath(path);

    QRect rect(-m_imageRadius, -m_imageRadius, m_imageRadius * 2, m_imageRadius * 2);
    painter->drawPixmap(rect, m_image);

    QPen pen;
    pen.setWidth(m_imageBorderWidth);
    pen.setColor(m_imageBorderColor);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);

    painter->drawEllipse(rect);
    painter->restore();
}
