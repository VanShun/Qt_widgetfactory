#include "clockmeterproperty.h"
#include "clockmeter.h"

ClockMeterProperty::ClockMeterProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new ClockMeter(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<ClockMeter*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *crownColorStartProp = m_colorManager->addProperty("CrownColorStart");
    objectProp->addSubProperty(crownColorStartProp);

    QtProperty *crownColorEndProp = m_colorManager->addProperty("CrownColorEnd");
    objectProp->addSubProperty(crownColorEndProp);

    QtProperty *foregroundProp = m_colorManager->addProperty("Foreground");
    objectProp->addSubProperty(foregroundProp);

    QtProperty *backgroundProp = m_colorManager->addProperty("Background");
    objectProp->addSubProperty(backgroundProp);

    QtProperty *pointerHourColorProp = m_colorManager->addProperty("PointerHourColor");
    objectProp->addSubProperty(pointerHourColorProp);

    QtProperty *pointerMinColorProp = m_colorManager->addProperty("PointerMinColor");
    objectProp->addSubProperty(pointerMinColorProp);

    QtProperty *pointerSecColorProp = m_colorManager->addProperty("pointerSecColor");
    objectProp->addSubProperty(pointerSecColorProp);

    QtProperty *sencondStyleProp = m_enumManager->addProperty("SecondStyle");
    objectProp->addSubProperty(sencondStyleProp);

    m_browser->addProperty(objectProp);
}

void ClockMeterProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    ClockMeter *widget = static_cast<ClockMeter *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "CrownColorStart") {
        widget->setCrownColorStart(val);
    } else if (propertyName == "CrownColorEnd") {
        widget->setCrownColorEnd(val);
    } else if (propertyName == "Foreground") {
        widget->setForeground(val);
    } else if (propertyName == "Background") {
        widget->setBackground(val);
    } else if (propertyName == "PointerHourColor") {
        widget->setPointerHourColor(val);
    } else if (propertyName == "PointerMinColor") {
        widget->setPointerMinColor(val);
    } else if (propertyName == "pointerSecColor") {
        widget->setPointerSecColor(val);
    }
}

void ClockMeterProperty::enumPropertyChanged(QtProperty *property, int val)
{
    ClockMeter *widget = static_cast<ClockMeter *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "SecondStyle") {
        widget->setSecondStyle(static_cast<ClockMeter::SecondStyle>(val));
    }
}
