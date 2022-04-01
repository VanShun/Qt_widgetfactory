/*********************************************************
** 描述：该模块实现了一个雷达状热点显示控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#ifndef RGRADIENTLABEL_H
#define RGRADIENTLABEL_H

#include <QWidget>
#include "global.h"

class RGradientLabel : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(RGradientLabel)
public:
    explicit RGradientLabel(QWidget *parent = nullptr);

    virtual ~RGradientLabel();

    void setStep(int step);

    void setInterval(int interval);

    void setBgColor(const QColor &bgColor);

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    void drawBg(QPainter *painter);

private:
    int m_step, m_interval, m_offset;
    bool m_add;
    QColor m_bgColor;
    QTimer *m_timer;

};

#endif // RGRADIENTLABEL_H
