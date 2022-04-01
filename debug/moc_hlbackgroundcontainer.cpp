/****************************************************************************
** Meta object code from reading C++ file 'hlbackgroundcontainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HLApp/HLCommon/hlbackgroundcontainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hlbackgroundcontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HLBackgroundContainerItem_t {
    QByteArrayData data[1];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HLBackgroundContainerItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HLBackgroundContainerItem_t qt_meta_stringdata_HLBackgroundContainerItem = {
    {
QT_MOC_LITERAL(0, 0, 25) // "HLBackgroundContainerItem"

    },
    "HLBackgroundContainerItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HLBackgroundContainerItem[] = {

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

void HLBackgroundContainerItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject HLBackgroundContainerItem::staticMetaObject = { {
    &HLGrabItemWidget::staticMetaObject,
    qt_meta_stringdata_HLBackgroundContainerItem.data,
    qt_meta_data_HLBackgroundContainerItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HLBackgroundContainerItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HLBackgroundContainerItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HLBackgroundContainerItem.stringdata0))
        return static_cast<void*>(this);
    return HLGrabItemWidget::qt_metacast(_clname);
}

int HLBackgroundContainerItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = HLGrabItemWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_HLBackgroundContainer_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HLBackgroundContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HLBackgroundContainer_t qt_meta_stringdata_HLBackgroundContainer = {
    {
QT_MOC_LITERAL(0, 0, 21) // "HLBackgroundContainer"

    },
    "HLBackgroundContainer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HLBackgroundContainer[] = {

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

void HLBackgroundContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject HLBackgroundContainer::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_HLBackgroundContainer.data,
    qt_meta_data_HLBackgroundContainer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HLBackgroundContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HLBackgroundContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HLBackgroundContainer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HLBackgroundContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
