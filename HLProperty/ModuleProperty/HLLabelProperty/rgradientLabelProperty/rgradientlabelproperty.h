#ifndef RGRADIENTLABELPROPERTY_H
#define RGRADIENTLABELPROPERTY_H

#include "hlwidgetproperty.h"

class RGradientLabelProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit RGradientLabelProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    virtual void intPropertyChanged(QtProperty *property, int val) override;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &val) override;
};

#endif // RGRADIENTLABELPROPERTY_H
