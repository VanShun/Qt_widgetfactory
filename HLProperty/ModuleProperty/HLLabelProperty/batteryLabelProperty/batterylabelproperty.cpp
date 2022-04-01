#include "batterylabelproperty.h"
#include "batterylabel.h"

BatteryLabelProperty::BatteryLabelProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new BatteryLabel(this);
    //m_item->setVisible(false);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<BatteryLabel*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *maxValueProp = m_doubleManager->addProperty("MaxValue");
    objectProp->addSubProperty(maxValueProp);
    m_doubleManager->setRange(maxValueProp, 0, 100);
    m_doubleManager->setValue(maxValueProp, 100);

    QtProperty *minValueProp = m_doubleManager->addProperty("MinValue");
    objectProp->addSubProperty(minValueProp);
    m_doubleManager->setRange(minValueProp, 0, 100);
    m_doubleManager->setValue(minValueProp, 0);

    QtProperty *valueProp = m_doubleManager->addProperty("Value");
    objectProp->addSubProperty(valueProp);
    m_doubleManager->setValue(valueProp, 50);

    QtProperty *alarmValueProp = m_doubleManager->addProperty("AlarmValue");
    objectProp->addSubProperty(alarmValueProp);
    m_doubleManager->setRange(alarmValueProp, 0, 30);
    m_doubleManager->setValue(alarmValueProp, 20);

    QtProperty *suffValueProp = m_doubleManager->addProperty("SuffValue");
    objectProp->addSubProperty(suffValueProp);
    m_doubleManager->setRange(suffValueProp, 80, 90);
    m_doubleManager->setValue(suffValueProp, 80);

    QtProperty *chargingProp = m_boolManager->addProperty("Charging");
    objectProp->addSubProperty(chargingProp);
    m_boolManager->setValue(chargingProp ,false);

    QtProperty *borderColorProp = m_colorManager->addProperty("BorderColor");
    objectProp->addSubProperty(borderColorProp);
    m_colorManager->setValue(borderColorProp, QColor(100, 100, 100));

    QtProperty *alarmColorProp = m_colorManager->addProperty("AlarmColor");
    objectProp->addSubProperty(alarmColorProp);
    m_colorManager->setValue(alarmColorProp, QColor(250, 118, 113));

    QtProperty *normalColorProp = m_colorManager->addProperty("NormalColor");
    objectProp->addSubProperty(normalColorProp);
    m_colorManager->setValue(normalColorProp, QColor(255, 215, 0));

    QtProperty *suffColorProp = m_colorManager->addProperty("SuffColor");
    objectProp->addSubProperty(suffColorProp);
    m_colorManager->setValue(suffColorProp, QColor(50, 205, 51));

    m_browser->addProperty(objectProp);
}

void BatteryLabelProperty::doublePropertyChanged(QtProperty *property, double val)
{
    BatteryLabel *widget = static_cast<BatteryLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "MaxValue") {
        widget->setMaxValue(val);
    } else if (propertyName == "MinValue") {
        widget->setMinValue(val);
    } else if (propertyName == "Value") {
        widget->setValue(val);
    } else if (propertyName == "AlarmValue") {
        widget->setAlarmValue(val);
    } else if (propertyName == "SuffValue") {
        widget->setSuffValue(val);
    }
}

void BatteryLabelProperty::boolPropertyChanged(QtProperty *property, bool val)
{
    BatteryLabel *widget = static_cast<BatteryLabel*>(m_item);
    if (property->propertyName() == "Charging") {
        widget->setChargingstat(val);
    }
}

void BatteryLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    BatteryLabel *widget = static_cast<BatteryLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "BorderColor") {
        widget->setBorderColor(val);
    } else if (propertyName == "AlarmColor") {
        widget->setAlarmColor(val);
    } else if (propertyName == "NormalColor") {
        widget->setNormalColor(val);
    } else if (propertyName == "SuffColor") {
        widget->setSuffColor(val);
    }
}
