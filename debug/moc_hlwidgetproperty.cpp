/****************************************************************************
** Meta object code from reading C++ file 'hlwidgetproperty.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HLProperty/hlwidgetproperty.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hlwidgetproperty.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HLWidgetProperty_t {
    QByteArrayData data[16];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HLWidgetProperty_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HLWidgetProperty_t qt_meta_stringdata_HLWidgetProperty = {
    {
QT_MOC_LITERAL(0, 0, 16), // "HLWidgetProperty"
QT_MOC_LITERAL(1, 17, 19), // "boolPropertyChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "QtProperty*"
QT_MOC_LITERAL(4, 50, 8), // "property"
QT_MOC_LITERAL(5, 59, 3), // "val"
QT_MOC_LITERAL(6, 63, 18), // "intPropertyChanged"
QT_MOC_LITERAL(7, 82, 21), // "doublePropertyChanged"
QT_MOC_LITERAL(8, 104, 21), // "stringPropertyChanged"
QT_MOC_LITERAL(9, 126, 20), // "colorPropertyChanged"
QT_MOC_LITERAL(10, 147, 19), // "fontPropertyChanged"
QT_MOC_LITERAL(11, 167, 19), // "enumPropertyChanged"
QT_MOC_LITERAL(12, 187, 19), // "sizePropertyChanged"
QT_MOC_LITERAL(13, 207, 19), // "rectPropertyChanged"
QT_MOC_LITERAL(14, 227, 25), // "sizepolicyPropertyChanged"
QT_MOC_LITERAL(15, 253, 15) // "geometryChanged"

    },
    "HLWidgetProperty\0boolPropertyChanged\0"
    "\0QtProperty*\0property\0val\0intPropertyChanged\0"
    "doublePropertyChanged\0stringPropertyChanged\0"
    "colorPropertyChanged\0fontPropertyChanged\0"
    "enumPropertyChanged\0sizePropertyChanged\0"
    "rectPropertyChanged\0sizepolicyPropertyChanged\0"
    "geometryChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HLWidgetProperty[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x09 /* Protected */,
       6,    2,   74,    2, 0x09 /* Protected */,
       7,    2,   79,    2, 0x09 /* Protected */,
       8,    2,   84,    2, 0x09 /* Protected */,
       9,    2,   89,    2, 0x09 /* Protected */,
      10,    2,   94,    2, 0x09 /* Protected */,
      11,    2,   99,    2, 0x09 /* Protected */,
      12,    2,  104,    2, 0x09 /* Protected */,
      13,    2,  109,    2, 0x09 /* Protected */,
      14,    2,  114,    2, 0x09 /* Protected */,
      15,    0,  119,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QColor,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QFont,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSize,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRect,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QSizePolicy,    4,    5,
    QMetaType::Void,

       0        // eod
};

void HLWidgetProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HLWidgetProperty *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boolPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->intPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->doublePropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->stringPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->colorPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 5: _t->fontPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QFont(*)>(_a[2]))); break;
        case 6: _t->enumPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->sizePropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QSize(*)>(_a[2]))); break;
        case 8: _t->rectPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2]))); break;
        case 9: _t->sizepolicyPropertyChanged((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QSizePolicy(*)>(_a[2]))); break;
        case 10: _t->geometryChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HLWidgetProperty::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_HLWidgetProperty.data,
    qt_meta_data_HLWidgetProperty,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HLWidgetProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HLWidgetProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HLWidgetProperty.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HLWidgetProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
