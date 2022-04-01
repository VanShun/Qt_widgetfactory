#include "waterwaveprogressproperty.h"
#include "waterwaveprogress.h"

WaterWaveProgressProperty::WaterWaveProgressProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new WaterWaveProgress(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<WaterWaveProgress*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *minValueProp = m_intManager->addProperty("MinValue");
    m_intManager->setValue(minValueProp, 0);
    objectProp->addSubProperty(minValueProp);

    QtProperty *maxValueProp = m_intManager->addProperty("MaxValue");
    m_intManager->setValue(maxValueProp, 100);
    objectProp->addSubProperty(maxValueProp);

    QtProperty *valueProp = m_intManager->addProperty("Value");
    m_intManager->setValue(valueProp, 50);
    objectProp->addSubProperty(valueProp);

    QtProperty *waterDensityProp = m_intManager->addProperty("WaterDensity");
    m_intManager->setValue(waterDensityProp, 2);
    objectProp->addSubProperty(waterDensityProp);

    QtProperty *offsetProp = m_intManager->addProperty("Offset");
    m_intManager->setValue(offsetProp, 0);
    objectProp->addSubProperty(offsetProp);

    QtProperty *waterHeightProp = m_doubleManager->addProperty("WaterHeight");
    m_doubleManager->setValue(waterHeightProp, 0.03);
    objectProp->addSubProperty(waterHeightProp);

    QtProperty *borderWidthProp = m_doubleManager->addProperty("BorderWidth");
    m_doubleManager->setValue(borderWidthProp, 2);
    objectProp->addSubProperty(borderWidthProp);

    QtProperty *bgColorProp = m_colorManager->addProperty("BgColor");
    m_colorManager->setValue(bgColorProp, QColor(0, 100, 255));
    objectProp->addSubProperty(bgColorProp);

    m_browser->addProperty(objectProp);
}

void WaterWaveProgressProperty::intPropertyChanged(QtProperty *property, int val)
{
    WaterWaveProgress *widget = static_cast<WaterWaveProgress *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "MinValue") {
        widget->setMinValue(val);
    } else if (propertyName == "MaxValue") {
        widget->setMaxValue(val);
    } else if (propertyName == "Value") {
        widget->setValue(val);
    } else if (propertyName == "WaterDensity") {
        widget->setWaterDensity(val);
    } else if (propertyName == "Offset") {
        widget->setOffset(val);
    }
}

void WaterWaveProgressProperty::doublePropertyChanged(QtProperty *property, double val)
{
    WaterWaveProgress *widget = static_cast<WaterWaveProgress *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "WaterHeight") {
        widget->setWaterHeight(val);
    } else if (propertyName == "BorderWidth") {
        widget->setBorderWidth(val);
    }
}

void WaterWaveProgressProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    WaterWaveProgress *widget = static_cast<WaterWaveProgress *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "BgColor") {
        widget->setBgColor(val);
    }
}
