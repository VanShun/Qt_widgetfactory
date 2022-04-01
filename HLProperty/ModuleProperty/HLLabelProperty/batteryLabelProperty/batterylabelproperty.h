#ifndef BATTERYLABELPROPERTY_H
#define BATTERYLABELPROPERTY_H

#include "hlwidgetproperty.h"

class BatteryLabelProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit BatteryLabelProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    virtual void doublePropertyChanged(QtProperty *property, double val) override;
    virtual void boolPropertyChanged(QtProperty *property, bool val) override;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &val) override;
};

#endif // BATTERYLABELPROPERTY_H
