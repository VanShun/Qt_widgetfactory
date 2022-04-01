#ifndef SCANLABELPROPERTY_H
#define SCANLABELPROPERTY_H

#include "hlwidgetproperty.h"

class ScanLabelProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit ScanLabelProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    virtual void intPropertyChanged(QtProperty *property, int val) override;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &val) override;
};

#endif // SCANLABELPROPERTY_H
