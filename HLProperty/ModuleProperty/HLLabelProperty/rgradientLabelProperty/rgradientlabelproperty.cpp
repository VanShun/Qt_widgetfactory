#include "rgradientlabelproperty.h"
#include "rgradientlabel.h"

RGradientLabelProperty::RGradientLabelProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new RGradientLabel(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<RGradientLabel*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *stepProp = m_intManager->addProperty("Step");
    m_intManager->setValue(stepProp, 10);
    objectProp->addSubProperty(stepProp);

    QtProperty *intervalProp = m_intManager->addProperty("Interval");
    m_intManager->setValue(intervalProp, 100);
    objectProp->addSubProperty(intervalProp);

    QtProperty *backgroundProp = m_colorManager->addProperty("Background");
    m_colorManager->setValue(backgroundProp, QColor(255, 179, 133));
    objectProp->addSubProperty(backgroundProp);

    m_browser->addProperty(objectProp);
}

void RGradientLabelProperty::intPropertyChanged(QtProperty *property, int val)
{
    RGradientLabel *widget = static_cast<RGradientLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "Step") {
        widget->setStep(val);
    } else if (propertyName == "Interval") {
        widget->setInterval(val);
    }
}

void RGradientLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    RGradientLabel *widget = static_cast<RGradientLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "Background") {
        widget->setBgColor(val);
    }
}
