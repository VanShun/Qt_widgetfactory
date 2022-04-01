#ifndef SWITCHBUTTONPROPERTY_H
#define SWITCHBUTTONPROPERTY_H

#include "hlwidgetproperty.h"

class SwitchButtonProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit SwitchButtonProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool val) override;
};

#endif // SWITCHBUTTONPROPERTY_H
