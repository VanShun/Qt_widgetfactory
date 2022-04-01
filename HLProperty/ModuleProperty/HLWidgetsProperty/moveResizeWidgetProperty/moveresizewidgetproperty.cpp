#include "moveresizewidgetproperty.h"
#include "moveresizewidget.h"

MoveResizeWidgetProperty::MoveResizeWidgetProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new MoveResizeWidget(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<MoveResizeWidget*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    m_browser->addProperty(objectProp);
}
