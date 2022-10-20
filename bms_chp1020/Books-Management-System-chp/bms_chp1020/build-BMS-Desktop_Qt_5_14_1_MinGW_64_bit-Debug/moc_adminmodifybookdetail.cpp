/****************************************************************************
** Meta object code from reading C++ file 'adminmodifybookdetail.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../BMS/view/adminmodifybookdetail.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminmodifybookdetail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminModifyBookDetail_t {
    QByteArrayData data[7];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminModifyBookDetail_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminModifyBookDetail_t qt_meta_stringdata_AdminModifyBookDetail = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AdminModifyBookDetail"
QT_MOC_LITERAL(1, 22, 10), // "backSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "bookUpdateSignal"
QT_MOC_LITERAL(4, 51, 4), // "Book"
QT_MOC_LITERAL(5, 56, 4), // "book"
QT_MOC_LITERAL(6, 61, 19) // "on_btn_back_clicked"

    },
    "AdminModifyBookDetail\0backSignal\0\0"
    "bookUpdateSignal\0Book\0book\0"
    "on_btn_back_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminModifyBookDetail[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void AdminModifyBookDetail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminModifyBookDetail *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backSignal(); break;
        case 1: _t->bookUpdateSignal((*reinterpret_cast< Book(*)>(_a[1]))); break;
        case 2: _t->on_btn_back_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminModifyBookDetail::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminModifyBookDetail::backSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminModifyBookDetail::*)(Book );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminModifyBookDetail::bookUpdateSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdminModifyBookDetail::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminModifyBookDetail.data,
    qt_meta_data_AdminModifyBookDetail,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdminModifyBookDetail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminModifyBookDetail::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminModifyBookDetail.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminModifyBookDetail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AdminModifyBookDetail::backSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminModifyBookDetail::bookUpdateSignal(Book _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
