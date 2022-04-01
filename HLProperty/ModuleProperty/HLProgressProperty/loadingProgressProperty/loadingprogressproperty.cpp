#include "loadingprogressproperty.h"
#include "loadingprogress.h"

LoadingProgressProperty::LoadingProgressProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new LoadingProgress(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<LoadingProgress*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *dotCountProp = m_intManager->addProperty("DotCount");
    m_intManager->setValue(dotCountProp, 20);
    m_intManager->setRange(dotCountProp, 1, 40);
    objectProp->addSubProperty(dotCountProp);

    QtProperty *dotColorProp = m_colorManager->addProperty("DotColor");
    m_colorManager->setValue(dotColorProp, QColor(49, 177, 190));
    objectProp->addSubProperty(dotColorProp);

    QtProperty *maxDiameterProp = m_doubleManager->addProperty("MaxDiameter");
    m_doubleManager->setValue(maxDiameterProp, 30);
    m_doubleManager->setMinimum(maxDiameterProp, 0);
    objectProp->addSubProperty(maxDiameterProp);

    QtProperty *minDiameterProp = m_doubleManager->addProperty("MinDiameter");
    m_doubleManager->setValue(minDiameterProp, 2);
    m_doubleManager->setMaximum(minDiameterProp, 0);
    objectProp->addSubProperty(minDiameterProp);

    m_browser->addProperty(objectProp);
}

void LoadingProgressProperty::intPropertyChanged(QtProperty *property, int val)
{
    LoadingProgress *widget = static_cast<LoadingProgress *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "DotCount") {
        widget->setDotCount(val);
    }
}

void LoadingProgressProperty::doublePropertyChanged(QtProperty *property, double val)
{
    LoadingProgress *widget = static_cast<LoadingProgress *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "MaxDiameter") {
        widget->setMaxDiameter(val);
    } else if (propertyName == "MinDiameter") {
        widget->setMinDiameter(val);
    }
}

void LoadingProgressProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    LoadingProgress *widget = static_cast<LoadingProgress *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "DotColor") {
        widget->setDotColor(val);
    }
}
