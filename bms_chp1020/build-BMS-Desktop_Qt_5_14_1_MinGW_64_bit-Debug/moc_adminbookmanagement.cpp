/****************************************************************************
** Meta object code from reading C++ file 'adminbookmanagement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../BMS/view/adminbookmanagement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminbookmanagement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminBookManagement_t {
    QByteArrayData data[21];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminBookManagement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminBookManagement_t qt_meta_stringdata_AdminBookManagement = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AdminBookManagement"
QT_MOC_LITERAL(1, 20, 16), // "changePageSignal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "Index"
QT_MOC_LITERAL(4, 44, 21), // "on_btn_search_clicked"
QT_MOC_LITERAL(5, 66, 21), // "on_btn_author_clicked"
QT_MOC_LITERAL(6, 88, 23), // "on_btn_bookname_clicked"
QT_MOC_LITERAL(7, 112, 19), // "on_btn_ISBN_clicked"
QT_MOC_LITERAL(8, 132, 36), // "on_cbox_classify_currentIndex..."
QT_MOC_LITERAL(9, 169, 28), // "on_btn_addbook_batch_clicked"
QT_MOC_LITERAL(10, 198, 20), // "on_btn_first_clicked"
QT_MOC_LITERAL(11, 219, 17), // "on_btn_la_clicked"
QT_MOC_LITERAL(12, 237, 19), // "on_btn_last_clicked"
QT_MOC_LITERAL(13, 257, 19), // "on_btn_fore_clicked"
QT_MOC_LITERAL(14, 277, 28), // "on_line_search_returnPressed"
QT_MOC_LITERAL(15, 306, 22), // "on_btn_addbook_clicked"
QT_MOC_LITERAL(16, 329, 26), // "on_btn_addclassify_clicked"
QT_MOC_LITERAL(17, 356, 10), // "backToThis"
QT_MOC_LITERAL(18, 367, 16), // "updateBookRecord"
QT_MOC_LITERAL(19, 384, 4), // "Book"
QT_MOC_LITERAL(20, 389, 4) // "book"

    },
    "AdminBookManagement\0changePageSignal\0"
    "\0Index\0on_btn_search_clicked\0"
    "on_btn_author_clicked\0on_btn_bookname_clicked\0"
    "on_btn_ISBN_clicked\0"
    "on_cbox_classify_currentIndexChanged\0"
    "on_btn_addbook_batch_clicked\0"
    "on_btn_first_clicked\0on_btn_la_clicked\0"
    "on_btn_last_clicked\0on_btn_fore_clicked\0"
    "on_line_search_returnPressed\0"
    "on_btn_addbook_clicked\0"
    "on_btn_addclassify_clicked\0backToThis\0"
    "updateBookRecord\0Book\0book"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminBookManagement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   97,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    1,  101,    2, 0x08 /* Private */,
       9,    0,  104,    2, 0x08 /* Private */,
      10,    0,  105,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void AdminBookManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminBookManagement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changePageSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btn_search_clicked(); break;
        case 2: _t->on_btn_author_clicked(); break;
        case 3: _t->on_btn_bookname_clicked(); break;
        case 4: _t->on_btn_ISBN_clicked(); break;
        case 5: _t->on_cbox_classify_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btn_addbook_batch_clicked(); break;
        case 7: _t->on_btn_first_clicked(); break;
        case 8: _t->on_btn_la_clicked(); break;
        case 9: _t->on_btn_last_clicked(); break;
        case 10: _t->on_btn_fore_clicked(); break;
        case 11: _t->on_line_search_returnPressed(); break;
        case 12: _t->on_btn_addbook_clicked(); break;
        case 13: _t->on_btn_addclassify_clicked(); break;
        case 14: _t->backToThis(); break;
        case 15: _t->updateBookRecord((*reinterpret_cast< Book(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminBookManagement::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminBookManagement::changePageSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdminBookManagement::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminBookManagement.data,
    qt_meta_data_AdminBookManagement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdminBookManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminBookManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminBookManagement.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminBookManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void AdminBookManagement::changePageSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
