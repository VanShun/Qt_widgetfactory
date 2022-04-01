#ifndef CLOCKMETERPROPERTY_H
#define CLOCKMETERPROPERTY_H

#include "hlwidgetproperty.h"

class ClockMeterProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit ClockMeterProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    virtual void colorPropertyChanged(QtProperty *property, const QColor &val) override;
    virtual void enumPropertyChanged(QtProperty *property, int val) override;
};

#endif // CLOCKMETERPROPERTY_H
