#include "scanlabelproperty.h"
#include "scanlabel.h"

ScanLabelProperty::ScanLabelProperty(QWidget *parent)
{
    m_item = new ScanLabel(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<ScanLabel*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *imageRadiusProp = m_intManager->addProperty("ImageRadius");
    m_intManager->setValue(imageRadiusProp, 10);
    objectProp->addSubProperty(imageRadiusProp);

    QtProperty *imageBorderWidthProp = m_intManager->addProperty("ImageBorderWidth");
    m_intManager->setValue(imageBorderWidthProp, 5);
    objectProp->addSubProperty(imageBorderWidthProp);

    QtProperty *scanRadiusProp = m_intManager->addProperty("ScanRadius");
    m_intManager->setValue(scanRadiusProp, 50);
    objectProp->addSubProperty(scanRadiusProp);

    QtProperty *scanColorProp = m_colorManager->addProperty("ScanColor");
    m_colorManager->setValue(scanColorProp, QColor(255, 100, 10));
    objectProp->addSubProperty(scanColorProp);

    m_browser->addProperty(objectProp);
}

void ScanLabelProperty::intPropertyChanged(QtProperty *property, int val)
{
    ScanLabel *widget = static_cast<ScanLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "ImageRadius") {
        widget->setImageRadius(val);
    } else if (propertyName == "ImageBorderWidth") {
        widget->setImageBorderWidth(val);
    } else if (propertyName == "ScanRadius") {
        widget->setScanRadius(val);
    }
}

void ScanLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    ScanLabel *widget = static_cast<ScanLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "ScanColor") {
        widget->setScanColor(val);
    }
}
