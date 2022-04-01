/*********************************************************
** 描述：该模块实现了一个转圈圈形状的加载显示控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#include "loadingprogress.h"

#include <qmath.h>
#include <QPainter>
#include <QDebug>

LoadingProgress::LoadingProgress(QWidget *parent)
    : QWidget(parent)
{
    setDotColor(QColor(49, 177, 190));
    setDotCount(20);
    setMaxDiameter(30);
    setMinDiameter(2);

    m_interval = 200;
    m_index = 0;

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));
    startTimer();
}

LoadingProgress::~LoadingProgress()
{
    if (m_timer->isActive()) {
        m_timer->stop();
    }
}

void LoadingProgress::setDotCount(int count)
{
    m_count = count;
    updateDotPara();
    update();
}

void LoadingProgress::setDotColor(const QColor &color)
{
    m_dotColor = color;
    update();
}

void LoadingProgress::setMaxDiameter(double max)
{
    m_maxDiameter = max;

    const double half = qMin(width(), height()) / 2;    //大圆轨迹半径
    if (max > half / 2) {          // 为了更好的视觉效果，小圆圈不宜过大
        m_maxDiameter = half / 2;
    }
    updateDotPara();
    update();
}

void LoadingProgress::setMinDiameter(double min)
{
    m_minDiameter = min;
    updateDotPara();
    update();
}

void LoadingProgress::updateDotPara()
{
    const double half = qMin(width(), height()) / 2;    //大圆轨迹半径
    const double centerDistance = half - m_maxDiameter / 2;  //小圆圈圆心到大圆圆心距离

    const double gap = (m_maxDiameter - m_minDiameter) / (m_count - 1) / 2; //小圆半径递增增幅
    const double angleGap = (double)360 / m_count;    //小圆圆心跟x轴夹角角度递增增幅

    m_dots.clear();
    m_ranges.clear();

    for (int i = 0; i < m_count; i++) {
        m_ranges << m_maxDiameter / 2 - i * gap;  //小圆半径列表
        const double radian = -angleGap * i * M_PI / 180.0;
        m_dots.append({half + centerDistance * qCos(radian), half - centerDistance * qSin(radian)});
    }
}

void LoadingProgress::startTimer()
{
    m_timer->setInterval(m_interval);
    m_timer->start();
}

void LoadingProgress::stopTimer()
{
    m_timer->stop();
}

QSize LoadingProgress::sizeHint() const
{
    return QSize(180, 180);
}

void LoadingProgress::updateRender()
{
    for (int i = 0; i < m_count - 1; i++) {
        m_ranges.move(i, i + 1);
    }
    update();
}

void LoadingProgress::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    qDebug() << "resizeEvent" << endl;
    updateDotPara();
}

void LoadingProgress::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(m_dotColor);
    painter.setBrush(m_dotColor);

    paintDot(painter);
}

void LoadingProgress::paintDot(QPainter &painter)
{
    for (int i = 0; i < m_count; i++) {
        painter.setPen(m_dotColor);
        const double radian = m_ranges.at((m_index + m_count - i) % m_count);
        const Position &position = m_dots.at(i);
        painter.drawEllipse(QPointF(position.x, position.y), radian, radian);
    }
    //m_index++;
}
