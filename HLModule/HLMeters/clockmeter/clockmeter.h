/*********************************************************
** 描述：该模块实现了一个时钟显示控件
** author: hrs
** date: 2022/1/21
**
*********************************************************/

#ifndef CLOCKMETER_H
#define CLOCKMETER_H

#include <QWidget>
#include "global.h"

class ClockMeter : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(ClockMeter)
public:
	enum SecondStyle {
        SecondStyleNormal = 0,
        SecondStyleSpring = 1,          //秒针抖动模式
        SecondStyleContinue = 2,        //秒针连续模式
        SecondStyleHide = 3             //不显示指针模式
	};

    explicit ClockMeter(QWidget *parent = nullptr);
    ~ClockMeter();

    void setCrownColorStart(const QColor &crownColorStart);
    void setCrownColorEnd(const QColor &crownColorEnd);

    void setForeground(const QColor &foreground);
    void setBackground(const QColor &background);

    void setPointerHourColor(const QColor &pointerHourColor);
    void setPointerMinColor(const QColor &pointerMinColor);
    void setPointerSecColor(const QColor &pointerSecColor);

    void setSecondStyle(SecondStyle secondStyle);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateTime();
    void updateSpring();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawCrown(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawHour(QPainter *painter);
    void drawMin(QPainter *painter);
    void drawSec(QPainter *painter);
    void drawDot(QPainter *painter);

private:
    QColor m_crownColorStart;
    QColor m_crownColorEnd;

    QColor m_foreground;
    QColor m_background;

    QColor m_pointerHourColor;
    QColor m_pointerMinColor;
    QColor m_pointerSecColor;

    SecondStyle m_secondStyle;

    QTimer *m_timer;
    int m_hour, m_min, m_sec, m_msec;

    QTimer *m_timerSpring;
    double m_angleSpring;

};

#endif // CLOCKMETER_H
