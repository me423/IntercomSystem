/****************************************************************************
** Meta object code from reading C++ file 'Intercom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Intercom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Intercom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Intercom_t {
    QByteArrayData data[21];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Intercom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Intercom_t qt_meta_stringdata_Intercom = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Intercom"
QT_MOC_LITERAL(1, 9, 13), // "slotReadyRead"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "slotError"
QT_MOC_LITERAL(4, 34, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 63, 16), // "slotSendToServer"
QT_MOC_LITERAL(6, 80, 13), // "slotConnected"
QT_MOC_LITERAL(7, 94, 3), // "fst"
QT_MOC_LITERAL(8, 98, 3), // "snd"
QT_MOC_LITERAL(9, 102, 3), // "thd"
QT_MOC_LITERAL(10, 106, 3), // "fth"
QT_MOC_LITERAL(11, 110, 4), // "ffth"
QT_MOC_LITERAL(12, 115, 3), // "sth"
QT_MOC_LITERAL(13, 119, 4), // "snth"
QT_MOC_LITERAL(14, 124, 3), // "eth"
QT_MOC_LITERAL(15, 128, 3), // "nth"
QT_MOC_LITERAL(16, 132, 5), // "staar"
QT_MOC_LITERAL(17, 138, 5), // "zeero"
QT_MOC_LITERAL(18, 144, 5), // "reesh"
QT_MOC_LITERAL(19, 150, 9), // "slotClear"
QT_MOC_LITERAL(20, 160, 8) // "slotOpen"

    },
    "Intercom\0slotReadyRead\0\0slotError\0"
    "QAbstractSocket::SocketError\0"
    "slotSendToServer\0slotConnected\0fst\0"
    "snd\0thd\0fth\0ffth\0sth\0snth\0eth\0nth\0"
    "staar\0zeero\0reesh\0slotClear\0slotOpen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Intercom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    1,  105,    2, 0x08 /* Private */,
       5,    0,  108,    2, 0x08 /* Private */,
       6,    0,  109,    2, 0x08 /* Private */,
       7,    0,  110,    2, 0x08 /* Private */,
       8,    0,  111,    2, 0x08 /* Private */,
       9,    0,  112,    2, 0x08 /* Private */,
      10,    0,  113,    2, 0x08 /* Private */,
      11,    0,  114,    2, 0x08 /* Private */,
      12,    0,  115,    2, 0x08 /* Private */,
      13,    0,  116,    2, 0x08 /* Private */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    0,  119,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Intercom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Intercom *_t = static_cast<Intercom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotReadyRead(); break;
        case 1: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->slotSendToServer(); break;
        case 3: _t->slotConnected(); break;
        case 4: _t->fst(); break;
        case 5: _t->snd(); break;
        case 6: _t->thd(); break;
        case 7: _t->fth(); break;
        case 8: _t->ffth(); break;
        case 9: _t->sth(); break;
        case 10: _t->snth(); break;
        case 11: _t->eth(); break;
        case 12: _t->nth(); break;
        case 13: _t->staar(); break;
        case 14: _t->zeero(); break;
        case 15: _t->reesh(); break;
        case 16: _t->slotClear(); break;
        case 17: _t->slotOpen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject Intercom::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Intercom.data,
      qt_meta_data_Intercom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Intercom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Intercom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Intercom.stringdata0))
        return static_cast<void*>(const_cast< Intercom*>(this));
    return QWidget::qt_metacast(_clname);
}

int Intercom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
