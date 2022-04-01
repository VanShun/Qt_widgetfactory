#include "hlgrabitemwidget.h"
#include <QPainter>

#define PADDING          6

HLGrabItemWidget::HLGrabItemWidget(QWidget *parent) : QWidget(parent)
{
    m_direction = Direction_No;
    m_pressed = false;
    setMouseTracking(true);
}

void HLGrabItemWidget::onMouseChanged(int x, int y)
{
    if(x < 0 || y < 0)
    {
        return;
    }

    QPoint pt;  //矩形变化参考点
    switch(m_direction)
    {
        case Direction_No:
        case Direction_Right:
        case Direction_Bottom:
        case Direction_RightBottom:
            pt = m_origRect.topLeft();
            break;
        case Direction_RightTop:
            pt = m_origRect.bottomLeft();
            break;
        case Direction_Left:
        case Direction_LeftBottom:
            pt = m_origRect.topRight();
            break;
        case Direction_LeftTop:
        case Direction_Top:
            pt = m_origRect.bottomRight();
            break;
    }

    const int rx = (x >= pt.x()) ? pt.x() : x;
    const int ry = (y >= pt.y()) ? pt.y() : y;
    const int rw = abs(x - pt.x());
    const int rh = abs(y - pt.y());

    m_currentRect = QRect(rx, ry, rw, rh);
    setGeometry(m_currentRect);
}

QSize HLGrabItemWidget::sizeHint() const
{
    return QSize(180, 180);
}

void HLGrabItemWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_pressed = true;
        m_movePos = event->globalPos() - pos();
    }
}

void HLGrabItemWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_pressed = false;

        emit rectChanged();
    }
}

void HLGrabItemWidget::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint &gloPoint = mapToParent(event->pos());
    const QPoint &pt_topLeft = mapToParent(rect().topLeft());
    const QPoint &pt_bottomLeft = mapToParent(rect().bottomLeft());
    const QPoint &pt_bottomRight = mapToParent(rect().bottomRight());

    if(!m_pressed) {
        m_direction = getRegion(gloPoint);
        m_origRect = QRect(pt_topLeft, pt_bottomRight);
    } else {
        if(m_direction != Direction_No) {
            switch(m_direction) {
                case Direction_Left:
                    return onMouseChanged(gloPoint.x(), pt_bottomLeft.y() + 1);
                case Direction_Right:
                    return onMouseChanged(gloPoint.x(), pt_bottomRight.y() + 1);
                case Direction_Top:
                    return onMouseChanged(pt_topLeft.x(), gloPoint.y());
                case Direction_Bottom:
                    return onMouseChanged(pt_bottomRight.x() + 1, gloPoint.y());
                case Direction_LeftTop:
                case Direction_RightTop:
                case Direction_LeftBottom:
                case Direction_RightBottom:
                    return onMouseChanged(gloPoint.x(), gloPoint.y());

                default: break;
            }
        } else {
            move(event->globalPos() - m_movePos);
            m_movePos = event->globalPos() - pos();
        }
    }
    m_currentRect = geometry();
}

/******************************************************************
** 尺寸变化事件，重新获取边界绘制点
** [in]: event
*  [返回]：无
*******************************************************************/
void HLGrabItemWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    m_borderMarker.clear();
    m_borderMarker.push_back(QPoint(0, 0));
    m_borderMarker.push_back(QPoint(width(), 0));
    m_borderMarker.push_back(QPoint(0, height()));
    m_borderMarker.push_back(QPoint(width(), height()));

    m_borderMarker.push_back(QPoint((width() >> 1), 0));
    m_borderMarker.push_back(QPoint((width() >> 1), height()));
    m_borderMarker.push_back(QPoint(0, (height() >> 1)));
    m_borderMarker.push_back(QPoint(width(), (height() >> 1)));
}

/******************************************************************
** 绘图事件，绘制边框
** [in]: event
*  [返回]：无
*******************************************************************/
void HLGrabItemWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPen pen;

    pen.setWidth(10);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawPoints(m_borderMarker);
}

/******************************************************************
** 判断当前鼠标所属区域方位
** [in]: cursor 鼠标位置，注意这里是用的相对于其父widget的坐标位置
*  [返回]：鼠标区域
*******************************************************************/
HLGrabItemWidget::Direction HLGrabItemWidget::getRegion(const QPoint &cursor)
{
    Direction dir = Direction_No;
    setCursor(QCursor(Qt::SizeAllCursor));

    const QPoint &pt_topLeft = mapToParent(rect().topLeft());
    const QPoint &pt_bottomRight = mapToParent(rect().bottomRight());
    const int x = cursor.x();
    const int y = cursor.y();

    if (x <= pt_topLeft.x() + PADDING && x >= pt_topLeft.x()) {
        dir = Direction_Left;
        setCursor(QCursor(Qt::SizeHorCursor));
        if (y >= pt_topLeft.y() && y <= pt_topLeft.y() + PADDING) {
            dir = Direction_LeftTop;
            setCursor(QCursor(Qt::SizeFDiagCursor));
        } else if (y >= pt_bottomRight.y() - PADDING && y <= pt_bottomRight.y()) {
            dir = Direction_LeftBottom;
            setCursor(QCursor(Qt::SizeBDiagCursor));
        }
    } else if (x <= pt_bottomRight.x() && x >= pt_bottomRight.x() - PADDING) {
        dir = Direction_Right;
        setCursor(QCursor(Qt::SizeHorCursor));
        if (y >= pt_topLeft.y() && y <= pt_topLeft.y() + PADDING) {
            dir = Direction_RightTop;
            setCursor(QCursor(Qt::SizeBDiagCursor));
        } else if (y >= pt_bottomRight.y() - PADDING && y <= pt_bottomRight.y()) {
            dir = Direction_RightBottom;
            setCursor(QCursor(Qt::SizeFDiagCursor));
        }
    } else if (y <= pt_topLeft.y() + PADDING && y >= pt_topLeft.y()) {
        dir = Direction_Top;
        setCursor(QCursor(Qt::SizeVerCursor));
    } else if (y <= pt_bottomRight.y() && y >= pt_bottomRight.y() - PADDING) {
        dir = Direction_Bottom;
        setCursor(QCursor(Qt::SizeVerCursor));
    }
    return dir;
}
