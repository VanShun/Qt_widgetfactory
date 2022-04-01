#include "marqueelabelproperty.h"
#include "marqueelabel.h"

MarqueeLabelProperty::MarqueeLabelProperty(QWidget *parent)
    :HLWidgetProperty(parent)
{
    m_item = new MarqueeLabel(this);

    QtProperty *objectProp = m_groupManager->addProperty("QObject");
    QtProperty *classNameProp = m_stringManager->addProperty("ClassName");
    objectProp->addSubProperty(classNameProp);
    m_stringManager->setValue(classNameProp, static_cast<MarqueeLabel*>(m_item)->getClassName());

    QtProperty *geometryProp = m_rectManager->addProperty("Geometry");
    objectProp->addSubProperty(geometryProp);

    QtProperty *textProp = m_stringManager->addProperty("Text");
    m_stringManager->setValue(textProp, "hello hualian");
    objectProp->addSubProperty(textProp);

    QtProperty *intervalProp = m_intManager->addProperty("Interval");
    m_intManager->setValue(intervalProp, 20);
    objectProp->addSubProperty(intervalProp);

    QtProperty *steplProp = m_intManager->addProperty("Step");
    m_intManager->setValue(steplProp, 2);
    objectProp->addSubProperty(steplProp);

    QtProperty *fontsizeProp = m_intManager->addProperty("Fontsize");
    m_intManager->setValue(fontsizeProp, 30);
    objectProp->addSubProperty(fontsizeProp);

    QtProperty *hoverStopProp = m_boolManager->addProperty("HoverStop");
    m_boolManager->setValue(hoverStopProp, false);
    objectProp->addSubProperty(hoverStopProp);

    QtProperty *foregroundProp = m_colorManager->addProperty("Foreground");
    m_colorManager->setValue(foregroundProp, QColor(100, 184, 255));
    objectProp->addSubProperty(foregroundProp);

    QtProperty *backgroundProp = m_colorManager->addProperty("Background");
    m_colorManager->setValue(backgroundProp, QColor(222, 222, 222));
    objectProp->addSubProperty(backgroundProp);

    QtProperty *moveStyleProp = m_enumManager->addProperty("MoveStyle");
    m_enumManager->setValue(moveStyleProp, static_cast<MarqueeLabel::MoveStyle>(0));
    objectProp->addSubProperty(moveStyleProp);

    m_browser->addProperty(objectProp);
}

void MarqueeLabelProperty::intPropertyChanged(QtProperty *property, int val)
{
    MarqueeLabel *widget = static_cast<MarqueeLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "Interval") {
        widget->setInterval(val);
    } else if (propertyName == "Step") {
        widget->setStep(val);
    } else if (propertyName == "Fontsize") {
        widget->setFontsize(val);
    }
}

void MarqueeLabelProperty::boolPropertyChanged(QtProperty *property, bool val)
{
    MarqueeLabel *widget = static_cast<MarqueeLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "HoverStop") {
        widget->enMouseHoverStop(val);
    }
}

void MarqueeLabelProperty::stringPropertyChanged(QtProperty *property, const QString &val)
{
    MarqueeLabel *widget = static_cast<MarqueeLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "Text") {
        widget->setText(val);
    }
}

void MarqueeLabelProperty::enumPropertyChanged(QtProperty *property, int val)
{
    MarqueeLabel *widget = static_cast<MarqueeLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "MoveStyle") {
        widget->setMoveStyle(static_cast<MarqueeLabel::MoveStyle>(val));
    }
}

void MarqueeLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    MarqueeLabel *widget = static_cast<MarqueeLabel*>(m_item);
    QString propertyName = property->propertyName();

    if (propertyName == "Foreground") {
        widget->setForeground(val);
    } else if (propertyName == "Background") {
        widget->setBackground(val);
    }
}
