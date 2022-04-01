/****************************************************************************
** Meta object code from reading C++ file 'toolswidgetapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HLApp/HLCommon/toolswidgetapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolswidgetapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToolsWidgetApp_t {
    QByteArrayData data[9];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolsWidgetApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolsWidgetApp_t qt_meta_stringdata_ToolsWidgetApp = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ToolsWidgetApp"
QT_MOC_LITERAL(1, 15, 19), // "buttonModuleChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "index"
QT_MOC_LITERAL(4, 42, 18), // "labelModuleChanged"
QT_MOC_LITERAL(5, 61, 21), // "progressModuleChanged"
QT_MOC_LITERAL(6, 83, 21), // "lineEditModuleChanged"
QT_MOC_LITERAL(7, 105, 18), // "meterModuleChanged"
QT_MOC_LITERAL(8, 124, 19) // "widgetModuleChanged"

    },
    "ToolsWidgetApp\0buttonModuleChanged\0\0"
    "index\0labelModuleChanged\0progressModuleChanged\0"
    "lineEditModuleChanged\0meterModuleChanged\0"
    "widgetModuleChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolsWidgetApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ToolsWidgetApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToolsWidgetApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonModuleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->labelModuleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->progressModuleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->lineEditModuleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->meterModuleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->widgetModuleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ToolsWidgetApp::staticMetaObject = { {
    &MoveResizeWidget::staticMetaObject,
    qt_meta_stringdata_ToolsWidgetApp.data,
    qt_meta_data_ToolsWidgetApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ToolsWidgetApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolsWidgetApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolsWidgetApp.stringdata0))
        return static_cast<void*>(this);
    return MoveResizeWidget::qt_metacast(_clname);
}

int ToolsWidgetApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MoveResizeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
