#ifndef MOVERESIZEWIDGETPROPERTY_H
#define MOVERESIZEWIDGETPROPERTY_H

#include "hlwidgetproperty.h"

class MoveResizeWidgetProperty : public HLWidgetProperty
{
    Q_OBJECT
public:
    explicit MoveResizeWidgetProperty(QWidget *parent = nullptr);
};

#endif // MOVERESIZEWIDGETPROPERTY_H
