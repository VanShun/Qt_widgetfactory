#include "temparcproperty.h"
#include "temparc.h"
//#include <QDebug>

TempArcProperty::TempArcProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new TempArc(this);
    //if (m_item) qDebug() << "new temparc" << endl;
    //m_item->show();

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<TempArc*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *settedValueProp = m_doubleManager->addProperty("SettedValue");
    m_doubleManager->setValue(settedValueProp, 23);
    objectProp->addSubProperty(settedValueProp);

    QtProperty *currentValueProp = m_doubleManager->addProperty("CurrentValue");
    m_doubleManager->setValue(currentValueProp, 30);
    objectProp->addSubProperty(currentValueProp);

    QtProperty *foregroundProp = m_colorManager->addProperty("Foreground");
    m_colorManager->setValue(foregroundProp, QColor(0x64, 0x95, 0xed));
    objectProp->addSubProperty(foregroundProp);

    QtProperty *backgroundProp = m_colorManager->addProperty("Background");
    m_colorManager->setValue(backgroundProp, QColor(0xdc, 0xdc, 0xdc));
    objectProp->addSubProperty(backgroundProp);

    QtProperty *svalueVisibleProp = m_boolManager->addProperty("SvalueVisible");
    m_boolManager->setValue(svalueVisibleProp, false);
    objectProp->addSubProperty(svalueVisibleProp);

    m_browser->addProperty(objectProp);
}

void TempArcProperty::doublePropertyChanged(QtProperty *property, double val)
{
    TempArc *widget = static_cast<TempArc *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "SettedValue") {
        widget->updateAngle_S(val);
    } else if (propertyName == "CurrentValue") {
        widget->updateAngle_C(val);
    }
}

void TempArcProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    TempArc *widget = static_cast<TempArc *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "Foreground") {
        widget->setForeground(val);
    } else if (propertyName == "Background") {
        widget->setBackground(val);
    }
}

void TempArcProperty::boolPropertyChanged(QtProperty *property, bool val)
{
    TempArc *widget = static_cast<TempArc *>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "SvalueVisible") {
        widget->setSvalueVisible(val);
    }
}
