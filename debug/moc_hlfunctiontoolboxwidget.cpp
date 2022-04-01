/****************************************************************************
** Meta object code from reading C++ file 'hlfunctiontoolboxwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HLModule/HLTitle/HLfunctionToolBoxWidget/hlfunctiontoolboxwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hlfunctiontoolboxwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HLfunctionToolBoxTopItem_t {
    QByteArrayData data[4];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HLfunctionToolBoxTopItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HLfunctionToolBoxTopItem_t qt_meta_stringdata_HLfunctionToolBoxTopItem = {
    {
QT_MOC_LITERAL(0, 0, 24), // "HLfunctionToolBoxTopItem"
QT_MOC_LITERAL(1, 25, 12), // "mousePressAt"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5) // "index"

    },
    "HLfunctionToolBoxTopItem\0mousePressAt\0"
    "\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HLfunctionToolBoxTopItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void HLfunctionToolBoxTopItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HLfunctionToolBoxTopItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePressAt((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HLfunctionToolBoxTopItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HLfunctionToolBoxTopItem::mousePressAt)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HLfunctionToolBoxTopItem::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_HLfunctionToolBoxTopItem.data,
    qt_meta_data_HLfunctionToolBoxTopItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HLfunctionToolBoxTopItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HLfunctionToolBoxTopItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HLfunctionToolBoxTopItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HLfunctionToolBoxTopItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void HLfunctionToolBoxTopItem::mousePressAt(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_HLfunctionToolBoxItemGroup_t {
    QByteArrayData data[1];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HLfunctionToolBoxItemGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HLfunctionToolBoxItemGroup_t qt_meta_stringdata_HLfunctionToolBoxItemGroup = {
    {
QT_MOC_LITERAL(0, 0, 26) // "HLfunctionToolBoxItemGroup"

    },
    "HLfunctionToolBoxItemGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HLfunctionToolBoxItemGroup[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void HLfunctionToolBoxItemGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject HLfunctionToolBoxItemGroup::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_HLfunctionToolBoxItemGroup.data,
    qt_meta_data_HLfunctionToolBoxItemGroup,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HLfunctionToolBoxItemGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HLfunctionToolBoxItemGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HLfunctionToolBoxItemGroup.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HLfunctionToolBoxItemGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_HLfunctionToolBoxWidget_t {
    QByteArrayData data[4];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HLfunctionToolBoxWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HLfunctionToolBoxWidget_t qt_meta_stringdata_HLfunctionToolBoxWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "HLfunctionToolBoxWidget"
QT_MOC_LITERAL(1, 24, 14), // "onMousePressAt"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5) // "index"

    },
    "HLfunctionToolBoxWidget\0onMousePressAt\0"
    "\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HLfunctionToolBoxWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void HLfunctionToolBoxWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HLfunctionToolBoxWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMousePressAt((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HLfunctionToolBoxWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_HLfunctionToolBoxWidget.data,
    qt_meta_data_HLfunctionToolBoxWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HLfunctionToolBoxWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HLfunctionToolBoxWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HLfunctionToolBoxWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HLfunctionToolBoxWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
