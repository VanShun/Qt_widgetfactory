/*********************************************************
** 描述：该模块实现了一个点击出现波纹效果的控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/

#ifndef CIRCLECLICKLABEL_H
#define CIRCLECLICKLABEL_H

#include <QWidget>


class  CircleClickLabel : public QWidget
{
    Q_OBJECT
public:
    explicit CircleClickLabel(QWidget *parent = nullptr);
    ~CircleClickLabel();

    virtual QSize sizeHint() const override;

protected Q_SLOTS:
    virtual void updateRender();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    bool m_circleOn;
    QTimer *m_circleTimer;
    int m_crValue;
    QPoint m_pos;

};

#endif // CIRCLECLICKLABEL_H
