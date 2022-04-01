#include "hlwidgetproperty.h"
#include "hlbackgroundcontainer.h"
#include <QHBoxLayout>
//#include <QDebug>

HLWidgetProperty::HLWidgetProperty(QWidget *parent) : QWidget(parent)
  ,m_item(nullptr)
  ,m_containerItem(nullptr)
{
    /* 各种类型的propertymanager */
    m_boolManager = new QtBoolPropertyManager(this);
    m_intManager = new QtIntPropertyManager(this);
    m_doubleManager = new QtDoublePropertyManager(this);
    m_stringManager = new QtStringPropertyManager(this);
    m_colorManager = new QtColorPropertyManager(this);
    m_fontManager = new QtFontPropertyManager(this);
    m_enumManager = new QtEnumPropertyManager(this);
    m_sizeManager = new QtSizePropertyManager(this);
    m_rectManager = new QtRectPropertyManager(this);
    m_sizepolicyManager = new QtSizePolicyPropertyManager(this);
    m_groupManager = new QtGroupPropertyManager(this);

    //各种类型的property factory
    m_checkBoxFactory = new QtCheckBoxFactory(this);
    m_spinBoxFactory = new QtSpinBoxFactory(this);
    m_doubleSpinBoxFactory = new QtDoubleSpinBoxFactory(this);
    m_lineEditFactory = new QtLineEditFactory(this);
    m_comboBoxFactory = new QtEnumEditorFactory(this);
    m_fontEditorFactory = new QtFontEditorFactory(this);
    m_colorEditFactory = new QtColorEditorFactory(this);

    //定义property browser
    m_browser = new QtTreePropertyBrowser(this);
    m_browser->setFactoryForManager(m_boolManager, m_checkBoxFactory);
    m_browser->setFactoryForManager(m_intManager, m_spinBoxFactory);
    m_browser->setFactoryForManager(m_doubleManager, m_doubleSpinBoxFactory);
    m_browser->setFactoryForManager(m_stringManager, m_lineEditFactory);
    m_browser->setFactoryForManager(m_colorManager, m_colorEditFactory);
    m_browser->setFactoryForManager(m_fontManager, m_fontEditorFactory);
    m_browser->setFactoryForManager(m_enumManager, m_comboBoxFactory);
    m_browser->setFactoryForManager(m_sizeManager->subIntPropertyManager(), m_spinBoxFactory);
    m_browser->setFactoryForManager(m_rectManager->subIntPropertyManager(), m_spinBoxFactory);
    m_browser->setFactoryForManager(m_sizepolicyManager->subIntPropertyManager(), m_spinBoxFactory);
    m_browser->setFactoryForManager(m_sizepolicyManager->subEnumPropertyManager(), m_comboBoxFactory);

    //各类型propermanager的信号与槽连接
    connect(m_boolManager, SIGNAL(valueChanged(QtProperty*, bool)), this, SLOT(boolPropertyChanged(QtProperty*, bool)));
    connect(m_intManager, SIGNAL(valueChanged(QtProperty*, int)), this, SLOT(intPropertyChanged(QtProperty*, int)));
    connect(m_doubleManager, SIGNAL(valueChanged(QtProperty*, double)), this, SLOT(doublePropertyChanged(QtProperty*, double)));
    connect(m_stringManager, SIGNAL(valueChanged(QtProperty*, const QString&)), this, SLOT(stringPropertyChanged(QtProperty*, const QString&)));
    connect(m_colorManager, SIGNAL(valueChanged(QtProperty*, const QColor&)), this, SLOT(colorPropertyChanged(QtProperty*, const QColor&)));
    connect(m_fontManager, SIGNAL(valueChanged(QtProperty*, const QFont&)), this, SLOT(fontPropertyChanged(QtProperty*, const QFont&)));
    connect(m_enumManager, SIGNAL(valueChanged(QtProperty*, int)), this, SLOT(enumPropertyChanged(QtProperty*, int)));
    connect(m_sizeManager, SIGNAL(valueChanged(QtProperty*, const QSize&)), this, SLOT(sizePropertyChanged(QtProperty*, const QSize&)));
    connect(m_rectManager, SIGNAL(valueChanged(QtProperty*, const QRect&)), this, SLOT(rectPropertyChanged(QtProperty*, const QRect&)));
    connect(m_sizepolicyManager, SIGNAL(valueChanged(QtProperty*, const QSizePolicy&)), this, SLOT(sizepolicyPropertyChanged(QtProperty*, const QSizePolicy&)));

    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->setContentsMargins(0, 0, 0, 0);
    hlayout->addWidget(m_browser);
    setLayout(hlayout);
}

HLWidgetProperty::~HLWidgetProperty()
{

}

void HLWidgetProperty::init()
{
    m_containerItem = static_cast<QWidget*>(m_item->parent());
    connect(static_cast<HLBackgroundContainerItem*>(m_containerItem), SIGNAL(rectChanged()), SLOT(geometryChanged()));
    geometryChanged();
}

QWidget *HLWidgetProperty::getWidget() const
{
    return m_item;
}

void HLWidgetProperty::boolPropertyChanged(QtProperty *property, bool val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::intPropertyChanged(QtProperty *property, int val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::doublePropertyChanged(QtProperty *property, double val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::stringPropertyChanged(QtProperty *property, const QString &val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::fontPropertyChanged(QtProperty *property, const QFont &val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::enumPropertyChanged(QtProperty *property, int val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::rectPropertyChanged(QtProperty *property, const QRect &val)
{
    if (nullptr == m_containerItem) return;
    //qDebug() << "rectPropertyChanged:" << val << endl;
    if (property->propertyName() == "Geometry") {
        if (m_item->width() <= val.width() && m_item->height() <= val.height()) {
            m_containerItem->setGeometry(val);  //背景适应控件大小
        } else {
            //控件尺寸调整得过大，重新调整为不超过背景大小
            m_rectManager->setValue(property, m_containerItem->geometry());
        }
    }
}

void HLWidgetProperty::sizepolicyPropertyChanged(QtProperty *property, const QSizePolicy &val)
{
    Q_UNUSED(property)
    Q_UNUSED(val)
}

void HLWidgetProperty::geometryChanged()
{
    if (nullptr == m_containerItem) {
        return;
    }
    //qDebug() << "geometryChanged" << endl;
    for (QtProperty *property : m_rectManager->properties()) {
        if (property->propertyName() == "Geometry") {
            m_rectManager->setValue(property, m_containerItem->geometry());
        }
    }
}
