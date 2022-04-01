#ifndef HLWIDGETPROPERTY_H
#define HLWIDGETPROPERTY_H

#include <QWidget>
#include "qtpropertymanager.h"
#include "qteditorfactory.h"
#include "qttreepropertybrowser.h"

class HLWidgetProperty : public QWidget
{
    Q_OBJECT
public:
    explicit HLWidgetProperty(QWidget *parent = nullptr);
    virtual ~HLWidgetProperty();

    void init();
    QWidget *getWidget() const;

protected Q_SLOTS:
    //以下信号为property变化处理槽函数，该基类不做具体实现，由具体子类继承实现
    virtual void boolPropertyChanged(QtProperty *property, bool val);
    virtual void intPropertyChanged(QtProperty *property, int val);
    virtual void doublePropertyChanged(QtProperty *property, double val);
    virtual void stringPropertyChanged(QtProperty *property, const QString &val);
    virtual void colorPropertyChanged(QtProperty *property, const QColor &val);
    virtual void fontPropertyChanged(QtProperty *property, const QFont &val);
    virtual void enumPropertyChanged(QtProperty *property, int val);
    virtual void sizePropertyChanged(QtProperty *property, const QSize &val);
    virtual void rectPropertyChanged(QtProperty *property, const QRect &val);
    virtual void sizepolicyPropertyChanged(QtProperty *property, const QSizePolicy &val);

public Q_SLOTS:
    void geometryChanged();

protected:
    QWidget *m_item, *m_containerItem;

    /* 各种类型的propertymanager */
    QtBoolPropertyManager *m_boolManager;
    QtIntPropertyManager *m_intManager;
    QtDoublePropertyManager *m_doubleManager;
    QtStringPropertyManager *m_stringManager;
    QtColorPropertyManager *m_colorManager;
    QtFontPropertyManager *m_fontManager;
    QtEnumPropertyManager *m_enumManager;
    QtSizePropertyManager *m_sizeManager;
    QtRectPropertyManager *m_rectManager;
    QtSizePolicyPropertyManager *m_sizepolicyManager;
    QtGroupPropertyManager *m_groupManager;

    //各种类型的property factory
    QtCheckBoxFactory *m_checkBoxFactory;
    QtSpinBoxFactory *m_spinBoxFactory;
    QtDoubleSpinBoxFactory *m_doubleSpinBoxFactory;
    QtLineEditFactory *m_lineEditFactory;
    QtEnumEditorFactory *m_comboBoxFactory;
    QtFontEditorFactory *m_fontEditorFactory;
    QtColorEditorFactory *m_colorEditFactory;

    //定义property browser
    QtAbstractPropertyBrowser *m_browser;
};

#endif // HLWIDGETPROPERTY_H
