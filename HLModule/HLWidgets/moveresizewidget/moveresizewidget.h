/*********************************************************
** 描述：该模块实现了带边框阴影的、可移动及可缩放的控件，主要给其它类继承使用
** author: hrs
** date: 2021/1/12
**
*********************************************************/
#ifndef MOVERESIZEWIDGET_H
#define MOVERESIZEWIDGET_H

#include <QWidget>
#include "global.h"

struct HL_MODULE_EXPORT MoveResizeStruct
{
    bool m_mouseLeftPress;
    bool m_mouseNearBoader;
    QPoint m_mousePos;
    QPoint m_windowPos;
};


class HL_MODULE_EXPORT MoveResizeWidget : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(MoveResizeWidget)
public:
    enum Direction
    {
        Direction_No = 0,
        Direction_Left = 1,
        Direction_Top = 2,
        Direction_Right = 4,
        Direction_Bottom = 8,
        Direction_LeftTop = Direction_Left + Direction_Top,
        Direction_LeftBottom = Direction_Left + Direction_Bottom,
        Direction_RightTop = Direction_Right + Direction_Top,
        Direction_RightBottom = Direction_Right + Direction_Bottom
    };

    explicit MoveResizeWidget(QWidget *parent = nullptr);
    virtual ~MoveResizeWidget();
    virtual QSize sizeHint() const override;

Q_SIGNALS:
    void rectChanged();

protected:
    //virtual bool eventFilter(QObject *object, QEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    void sizeDirection();
    void moveDirection();
    void drawBorder();

protected:
    MoveResizeStruct m_struct;
    Direction m_direction;
    int8_t m_borderwidth;
    QColor m_shadowColor;   //阴影颜色
private:

};

#endif // MOVERESIZEWIDGET_H
