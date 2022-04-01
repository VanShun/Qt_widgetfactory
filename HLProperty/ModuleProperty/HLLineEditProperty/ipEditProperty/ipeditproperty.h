#ifndef IPEDITPROPERTY_H
#define IPEDITPROPERTY_H

#include "hlwidgetproperty.h"

class IpEditProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    IpEditProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    virtual void stringPropertyChanged(QtProperty *property, const QString &val) override;
};

#endif // IPEDITPROPERTY_H
