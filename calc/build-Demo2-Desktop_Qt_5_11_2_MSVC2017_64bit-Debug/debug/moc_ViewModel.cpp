/****************************************************************************
** Meta object code from reading C++ file 'ViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CalcDemo/ViewModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ViewModel_t {
    QByteArrayData data[10];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewModel_t qt_meta_stringdata_ViewModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ViewModel"
QT_MOC_LITERAL(1, 10, 11), // "updateLabel"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "labelText"
QT_MOC_LITERAL(4, 33, 16), // "onNumberSelected"
QT_MOC_LITERAL(5, 50, 10), // "numberChar"
QT_MOC_LITERAL(6, 61, 19), // "onOperationSelected"
QT_MOC_LITERAL(7, 81, 13), // "operationChar"
QT_MOC_LITERAL(8, 95, 12), // "onEqSelected"
QT_MOC_LITERAL(9, 108, 10) // "operations"

    },
    "ViewModel\0updateLabel\0\0labelText\0"
    "onNumberSelected\0numberChar\0"
    "onOperationSelected\0operationChar\0"
    "onEqSelected\0operations"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x02 /* Public */,
       6,    1,   45,    2, 0x02 /* Public */,
       8,    0,   48,    2, 0x02 /* Public */,
       9,    0,   49,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::QStringList,

       0        // eod
};

void ViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewModel *_t = static_cast<ViewModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onNumberSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onOperationSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onEqSelected(); break;
        case 4: { QStringList _r = _t->operations();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ViewModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ViewModel::updateLabel)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ViewModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ViewModel.data,
      qt_meta_data_ViewModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ViewModel::updateLabel(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
