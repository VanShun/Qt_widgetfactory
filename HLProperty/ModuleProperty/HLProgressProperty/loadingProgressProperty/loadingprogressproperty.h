#ifndef LOADINGPROGRESSPROPERTY_H
#define LOADINGPROGRESSPROPERTY_H

#include "hlwidgetproperty.h"

class LoadingProgressProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    LoadingProgressProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    void intPropertyChanged(QtProperty *property, int val) override;
    void doublePropertyChanged(QtProperty *property, double val) override;
    void colorPropertyChanged(QtProperty *property, const QColor &val) override;
};

#endif // LOADINGPROGRESSPROPERTY_H
