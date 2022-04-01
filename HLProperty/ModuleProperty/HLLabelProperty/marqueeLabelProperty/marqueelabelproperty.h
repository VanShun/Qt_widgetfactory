#ifndef MARQUEELABELPROPERTY_H
#define MARQUEELABELPROPERTY_H

#include "hlwidgetproperty.h"

class MarqueeLabelProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit MarqueeLabelProperty(QWidget *parent = nullptr);

protected Q_SLOTS:
    virtual void intPropertyChanged(QtProperty *property, int val) override;
    virtual void boolPropertyChanged(QtProperty *property, bool val) override;
    virtual void stringPropertyChanged(QtProperty *property, const QString &val) override;
    virtual void enumPropertyChanged(QtProperty *property, int val) override;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &val) override;
};

#endif // MARQUEELABELPROPERTY_H
