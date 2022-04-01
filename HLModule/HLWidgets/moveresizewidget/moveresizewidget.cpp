/*********************************************************
** 描述：该模块实现了带边框阴影的、可移动及可缩放的控件，主要给其它类继承使用
** author: hrs
** date: 2021/1/12
**
*********************************************************/
#include "moveresizewidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
//#include <QDebug>
#include <qmath.h>

#define MAX_BORDERWIDTTH  5
#define IN_RANGE(x, y, v) ((((x) <= (v)) && ((v) <= (y))) ? true : false)

MoveResizeWidget::MoveResizeWidget(QWidget *parent)
    : QWidget(parent)
{
    m_struct.m_mouseLeftPress = false;
    m_struct.m_mouseNearBoader = false;
    m_direction = Direction_No;
    m_shadowColor = QColor(Qt::gray);

    setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMouseTracking(true);
}

MoveResizeWidget::~MoveResizeWidget()
{

}

QSize MoveResizeWidget::sizeHint() const
{
    return  QSize(200, 200);
}

void MoveResizeWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    drawBorder();
}

void MoveResizeWidget::mousePressEvent(QMouseEvent *event)
{
    //QWidget::mousePressEvent(event);

    m_struct.m_mouseNearBoader = false;
    setFocus();
    if (event->button() == Qt::LeftButton) {
        m_struct.m_windowPos = pos(); //记住鼠标按下时候窗体位置,相对于其父widget的
        m_struct.m_mouseLeftPress = true;
        m_shadowColor = QColor(150, 200, 255);
        if(m_direction != Direction_No)
        {
            mouseGrabber();
        }
        update();
        if (QRect(m_borderwidth * 2, m_borderwidth * 2,
                 width() - m_borderwidth * 4,
                 height() - m_borderwidth * 4).contains(event->pos())) {

            m_struct.m_mousePos = event->globalPos();//记下鼠标按下时鼠标的全局位置
        } else {
            m_struct.m_mouseNearBoader = true;
        }
    }
}

void MoveResizeWidget::mouseMoveEvent(QMouseEvent *event)
{
    //QWidget::mouseMoveEvent(event);
    sizeDirection();

    if (m_struct.m_mouseLeftPress) {
        if (m_struct.m_mouseNearBoader) {
            moveDirection();
        } else {
            move(m_struct.m_windowPos + (event->globalPos() - m_struct.m_mousePos));
        }
    }
}

void MoveResizeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    //QWidget::mouseReleaseEvent(event);
    m_struct.m_mouseNearBoader = false;
    m_struct.m_mouseLeftPress = false;
    m_shadowColor = QColor(Qt::gray);
    //clearFocus();

    setCursor(QCursor(Qt::ArrowCursor));
    if (m_direction != Direction_No) {
        m_direction = Direction_No;
        emit rectChanged();
    }
    update();
}

void MoveResizeWidget::sizeDirection()
{
    if (m_struct.m_mouseNearBoader) return; //拖动边框期间不再重复判定
    QPoint point = mapFromGlobal(QCursor::pos());
    if (point.x() > width() - m_borderwidth && point.x() < width() + m_borderwidth
            && point.y() < height() - m_borderwidth && point.y() > m_borderwidth) {
        setCursor(Qt::SizeHorCursor);
        m_direction = Direction_Right;
    } else if(point.x() < m_borderwidth && point.x() > -m_borderwidth
            &&point.y() < height() - m_borderwidth && point.y() > m_borderwidth) {
        setCursor(Qt::SizeHorCursor);
        m_direction = Direction_Left;
    } else if(point.y() > height() - m_borderwidth && point.y() < height() + m_borderwidth
              && point.x() > m_borderwidth && point.x() < width() - m_borderwidth) {
        setCursor(Qt::SizeVerCursor);
        m_direction = Direction_Bottom;
    } else if(point.y() < m_borderwidth && point.y() > -m_borderwidth
              && point.x() > m_borderwidth && point.x() < width() - m_borderwidth) {
        setCursor(Qt::SizeVerCursor);
        m_direction = Direction_Top;
    } else if(point.y() < m_borderwidth && point.x() > width() - m_borderwidth) {
        setCursor(Qt::SizeBDiagCursor);
        m_direction = Direction_RightTop;
    } else if(point.y() < m_borderwidth && point.x() < m_borderwidth) {
        setCursor(Qt::SizeFDiagCursor);
        m_direction = Direction_LeftTop;
    } else if(point.x() > m_borderwidth && point.y() > height() - m_borderwidth) {
        setCursor(Qt::SizeFDiagCursor);
        m_direction = Direction_RightBottom;
    } else if(point.x() < m_borderwidth && point.y() > height() - m_borderwidth) {
        setCursor(Qt::SizeBDiagCursor);
        m_direction = Direction_LeftBottom;
    } else {
        setCursor(Qt::ArrowCursor);
        m_direction = Direction_No;
    }
}

void MoveResizeWidget::moveDirection()
{
    switch(m_direction)
    {
        case Direction_Right:
        {
            const int wValue = QCursor::pos().x() - mapToGlobal(QPoint(0, 0)).x();
            if (IN_RANGE(minimumWidth(), maximumWidth(),wValue)) {
                setGeometry(x(), y(), wValue, height());
            }
            break;
        }
        case Direction_Left:
        {
            const int wValue = width() + mapToGlobal(QPoint(0, 0)).x() - QCursor::pos().x();
            int rightx = x() + width(); //右边界的x坐标不改变
            if (IN_RANGE(minimumWidth(), maximumWidth(),wValue)) {
                setGeometry(rightx - wValue, y(), wValue, height());
            }
            break;
        }
        case Direction_Bottom:
        {
            const int hValue = QCursor::pos().y() - mapToGlobal(QPoint(0, 0)).y();;
            if (IN_RANGE(minimumHeight(), maximumHeight(), hValue)) {
                setGeometry(x(), y(), width(), hValue);
            }
            break;
        }
        case Direction_Top:
        {
            const int hValue = mapToGlobal(QPoint(0, 0)).y() - QCursor::pos().y() + height();
            int bottomy = y() + height(); //下边界的y坐标不变
            if (IN_RANGE(minimumHeight(), maximumHeight(), hValue)) {
                setGeometry(x(), bottomy - hValue, width(), hValue);
            }
            break;
        }
        case Direction_RightTop:
        {
            const int hValue = mapToGlobal(QPoint(0, 0)).y() + height() - QCursor::pos().y();
            const int wValue = QCursor::pos().x() - mapToGlobal(QPoint(0, 0)).x();
            int bottomy = y() + height(); //下边界的y坐标不变

            if (IN_RANGE(minimumWidth(), maximumWidth(),wValue) && IN_RANGE(minimumHeight(), maximumHeight(), hValue)) {
                setGeometry(x(), bottomy - hValue, wValue, hValue);
            }

            break;
        }
        case Direction_LeftTop:
        {
            const int wValue = width() + mapToGlobal(QPoint(0, 0)).x() - QCursor::pos().x();
            const int hValue = height() + mapToGlobal(QPoint(0, 0)).y() - QCursor::pos().y();
            QPoint rightbottom = QPoint(x() + width(), y() + height());//右下角的点坐标不变
            if (IN_RANGE(minimumWidth(), maximumWidth(), wValue) && IN_RANGE(minimumHeight(), maximumHeight(), hValue)) {
                setGeometry(rightbottom.x() - wValue, rightbottom.y() - hValue, wValue, hValue);
            }
            break;
        }
        case Direction_RightBottom:
        {
            const int wValue = QCursor::pos().x() - mapToGlobal(QPoint(0, 0)).x();
            const int hValue = QCursor::pos().y() - mapToGlobal(QPoint(0, 0)).y();
            if (IN_RANGE(minimumWidth(), maximumWidth(), wValue) && IN_RANGE(minimumHeight(), maximumHeight(), hValue)) {
                setGeometry(x(), y(), wValue, hValue);
            }
            break;
        }
        case Direction_LeftBottom:
        {
            const int wValue = width() + mapToGlobal(QPoint(0, 0)).x() - QCursor::pos().x();
            const int hValue = QCursor::pos().y() - mapToGlobal(QPoint(0, 0)).y();
            QPoint righttop = QPoint(x() + width(), y());//右上角的点坐标不变
            if (IN_RANGE(minimumWidth(), maximumWidth(), wValue) && IN_RANGE(minimumHeight(), maximumHeight(), hValue)) {
                setGeometry(righttop.x() - wValue, righttop.y(), wValue, hValue);
            }
            break;
        }
        default: break;
    }
}

void MoveResizeWidget::drawBorder()
{
    QPainterPath path;
    int8_t side = qMin(this->width(), this->height()) / 10;
    m_borderwidth = side > MAX_BORDERWIDTTH ? MAX_BORDERWIDTTH : side;
    path.addRect(m_borderwidth, m_borderwidth,
                 this->width() - 2 * m_borderwidth,
                 this->height( ) - 2 * m_borderwidth);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillPath(path, QBrush(Qt::white));
    for (int i = 0; i < m_borderwidth; i++) {
        QPainterPath path;
        //path.setFillRule(Qt::WindingFill);
        path.addRect(m_borderwidth - i, m_borderwidth - i,
                     this->width() - (m_borderwidth - i) * 2,
                     this->height() - (m_borderwidth - i) * 2);
        m_shadowColor.setAlpha(150 - qSqrt(i) * 50);
        painter.setPen(m_shadowColor);
        painter.drawPath(path);
    }
}
