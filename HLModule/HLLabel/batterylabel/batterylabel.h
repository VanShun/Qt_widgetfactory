/*********************************************************
** 描述：该模块实现了一个电池电量显示控件
** author: hrs
** date: 2021/12/21
**
*********************************************************/

#ifndef BATTERYLABEL_H
#define BATTERYLABEL_H

#include <QWidget>
#include "global.h"

class  BatteryLabel : public QWidget
{
    Q_OBJECT    
    HL_DECLARE_MODULE(BatteryLabel)
public:
    explicit BatteryLabel(QWidget *parent = nullptr);

    virtual ~BatteryLabel();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);

    void setMaxValue(double maxValue);

    void setValue(double value);

    void setAlarmValue(double alarmValue);

    void setSuffValue(double suffValue);

    bool isCharging();

    void setChargingstat(bool chg);

    void setBorderColor(const QColor &borderColor);

    void setAlarmColor(const QColor &alarmColor);

    void setNormalColor(const QColor &normalColor);

    void setSuffColor(const QColor &suffColor);

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    void drawBorder(QPainter *painter);

    void drawBackground(QPainter *painter);

    void drawCharging(QPainter *painter);

private:    
    double m_minValue, m_maxValue, m_alarmValue, m_suffValue, m_currentValue;

    /* 边框、低电量、正常电量、充足电量颜色 */
    QColor m_borderColor, m_alarmColor, m_normalColor, m_suffColor;

    bool m_charging; //是否在充电
    QRectF m_batteryRect;

};

#endif // BATTERYLABEL_H
