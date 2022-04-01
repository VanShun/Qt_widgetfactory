#ifndef WATERWAVEPROGRESSPROPERTY_H
#define WATERWAVEPROGRESSPROPERTY_H

#include "hlwidgetproperty.h"

class WaterWaveProgressProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    WaterWaveProgressProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    void intPropertyChanged(QtProperty *property, int val) override;
    void doublePropertyChanged(QtProperty *property, double val) override;
    void colorPropertyChanged(QtProperty *property, const QColor &val) override;
};

#endif // WATERWAVEPROGRESSPROPERTY_H
