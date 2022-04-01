/*********************************************************
** 描述：该模块实现了一个圆弧状温度显示控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/
#ifndef TEMPARC_H
#define TEMPARC_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include "global.h"

class TempArc : public QWidget
{
    Q_OBJECT
    HL_DECLARE_MODULE(TempArc)
public:
    explicit TempArc(QWidget *parent = nullptr);

    virtual ~TempArc();
public:
    void updateAngle_C(const double value);

    void updateAngle_S(const double value);

    void setForeground(const QColor &color);

    void setBackground(const QColor &color);

    bool svalueVisible();

    void setSvalueVisible(bool visible);

    virtual QSize sizeHint() const override;

protected:
        virtual void paintEvent(QPaintEvent *event) override;

    virtual void mousePressEvent(QMouseEvent *event) override;

    virtual void mouseReleaseEvent(QMouseEvent *event) override;

    void drawCrown(QPainter *painter);       //绘制表冠

    void drawArc(QPainter *painter);         //绘制圆弧

    //void drawScale(QPainter *painter);       //绘制刻度

    void drawNumericValue(QPainter *painter);//draw number and unit

private:
    QColor m_crownColor;
    QColor m_foreground;
    QColor m_background;
    QString m_units;
    QString m_title;

    int m_maxValue, m_minValue;
    int m_scaleMajor;
    int m_scaleMinor;
    int m_startAngle,m_endAngle;
    int arcWidth;

    double m_cvalue;   //current value
    double m_svalue;   //set value
    bool m_showsvalue; //when poweroff, no svalue to show

    QPoint m_presspoint, m_releasepoint;
};

#endif // TEMPARC_H
