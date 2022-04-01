#ifndef TEMPARCPROPERTY_H
#define TEMPARCPROPERTY_H

#include "hlwidgetproperty.h"

class TempArcProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit TempArcProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    void colorPropertyChanged(QtProperty *property, const QColor &val) override;
    void boolPropertyChanged(QtProperty *property, bool val) override;
    void doublePropertyChanged(QtProperty *property, double val) override;
};

#endif // TEMPARCPROPERTY_H
