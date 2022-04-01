/*********************************************************
** 描述：该模块实现了可移动及可缩放的控件，主要给其它类继承使用,与moveresizewidget
** 很相似，实现上的主要不同点是该widget中对坐标变换都是统一转换为相对于其父widget的
** 坐标(maptoParent)来进行
** author: hrs
** date: 2021/1/12
**
*********************************************************/

#ifndef HLGRABITEMWIDGET_H
#define HLGRABITEMWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "global.h"

class HLGrabItemWidget : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(HLGrabItemWidget)
public:
    enum Direction {                 //鼠标在边框移动方向
        Direction_No = 0,
        Direction_Left = 1,
        Direction_Top = 2,
        Direction_Right = 4,
        Direction_Bottom = 8,
        Direction_LeftTop = Direction_Left + Direction_Top,
        Direction_LeftBottom = Direction_Left + Direction_Bottom,
        Direction_RightTop = Direction_Right + Direction_Top,
        Direction_RightBottom = Direction_Right + Direction_LeftBottom
    };

    explicit HLGrabItemWidget(QWidget *parent = nullptr);
    virtual QSize sizeHint() const override;

signals:
    void rectChanged();
protected slots:
    virtual void onMouseChanged(int x, int y);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    Direction getRegion(const QPoint &cursor);
protected:
    bool m_pressed;
    QPolygon m_borderMarker;
    QPoint m_movePos;
    QRect m_origRect, m_currentRect;
    Direction m_direction;
};

#endif // HLGRABITEMWIDGET_H
