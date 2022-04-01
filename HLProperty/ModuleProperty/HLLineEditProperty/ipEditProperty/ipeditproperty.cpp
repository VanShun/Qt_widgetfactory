#include "ipeditproperty.h"
#include "ipedit.h"

IpEditProperty::IpEditProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new IpEdit(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<IpEdit*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *textProp = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textProp, "255.255.255.255");
    objectProp->addSubProperty(textProp);

    m_browser->addProperty(objectProp);
}

void IpEditProperty::stringPropertyChanged(QtProperty *property, const QString &val)
{
    IpEdit * widget = static_cast<IpEdit *>(m_item);

    if (property->propertyName() == "Text") {
        widget->setText(val);
    }
}
