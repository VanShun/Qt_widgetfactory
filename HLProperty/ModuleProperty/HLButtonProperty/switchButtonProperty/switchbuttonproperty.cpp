#include "switchbuttonproperty.h"
#include "switchbutton.h"

SwitchButtonProperty::SwitchButtonProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new Switchbutton(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<Switchbutton*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *checkProp = m_boolManager->addProperty("Check");
    m_boolManager->setValue(checkProp, false);
    objectProp->addSubProperty(checkProp);

    m_browser->addProperty(objectProp);
}

void SwitchButtonProperty::boolPropertyChanged(QtProperty *property, bool val)
{
    Switchbutton *widget = static_cast<Switchbutton*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "Check") {
        widget->SetCheck(val);
    }
}
