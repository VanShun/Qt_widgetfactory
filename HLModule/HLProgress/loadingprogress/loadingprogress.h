/*********************************************************
** 描述：该模块实现了一个转圈圈形状的加载显示控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#ifndef LOADINGPROGRESS_H
#define LOADINGPROGRESS_H

#include <QTimer>
#include <QWidget>
#include "global.h"

struct Position
{
    double x;
    double y;
};

class LoadingProgress : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(LoadingProgress)
public:
    explicit LoadingProgress(QWidget *parent = nullptr);

    virtual ~LoadingProgress();

    void setDotCount(int count);

    void setDotColor(const QColor &color);

    void setMaxDiameter(double max);

    void setMinDiameter(double min);

    void updateDotPara();

    void startTimer();

    void stopTimer();

    virtual QSize sizeHint() const override;

protected slots:
    void updateRender();

protected:
    void paintDot(QPainter &painter);

    virtual void paintEvent(QPaintEvent *event) override;

    virtual void resizeEvent(QResizeEvent *event) override;

private:
    int m_index, m_count;
    QColor m_dotColor;
    double m_minDiameter, m_maxDiameter; //小圆圈中最大和最小的直径
    int m_interval;
    QTimer *m_timer;
    QList<double> m_ranges;  //小圆圈半径列表
    QList<Position> m_dots; //小圆圈圆心位置列表


};

#endif // LOADINGPROGRESS_H
