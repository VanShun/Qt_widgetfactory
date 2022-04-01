#include "grabitemwidgetproperty.h"
#include "hlgrabitemwidget.h"

GrabItemWidgetProperty::GrabItemWidgetProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new HLGrabItemWidget(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<HLGrabItemWidget*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    m_browser->addProperty(objectProp);
}
