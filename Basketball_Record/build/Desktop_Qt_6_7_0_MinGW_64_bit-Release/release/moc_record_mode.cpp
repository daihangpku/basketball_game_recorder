/****************************************************************************
** Meta object code from reading C++ file 'record_mode.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../record_mode.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'record_mode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSrecord_modeENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSrecord_modeENDCLASS = QtMocHelpers::stringData(
    "record_mode",
    "sentdata",
    "",
    "Team",
    "a",
    "b",
    "Game",
    "c",
    "on_backbutton_clicked",
    "on_go_to_members_clicked",
    "on_go_to_teams_clicked",
    "on_back_to_event_clicked",
    "on_back_to_teams_clicked",
    "on_go_to_record_clicked",
    "paintEvent",
    "QPaintEvent*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSrecord_modeENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   69,    2, 0x08,    5 /* Private */,
       9,    0,   70,    2, 0x08,    6 /* Private */,
      10,    0,   71,    2, 0x08,    7 /* Private */,
      11,    0,   72,    2, 0x08,    8 /* Private */,
      12,    0,   73,    2, 0x08,    9 /* Private */,
      13,    0,   74,    2, 0x08,   10 /* Private */,
      14,    1,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 6,    4,    5,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject record_mode::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSrecord_modeENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSrecord_modeENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSrecord_modeENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<record_mode, std::true_type>,
        // method 'sentdata'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Team, std::false_type>,
        QtPrivate::TypeAndForceComplete<Team, std::false_type>,
        QtPrivate::TypeAndForceComplete<Game, std::false_type>,
        // method 'on_backbutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_go_to_members_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_go_to_teams_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_back_to_event_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_back_to_teams_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_go_to_record_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'paintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>
    >,
    nullptr
} };

void record_mode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<record_mode *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sentdata((*reinterpret_cast< std::add_pointer_t<Team>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Team>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Game>>(_a[3]))); break;
        case 1: _t->on_backbutton_clicked(); break;
        case 2: _t->on_go_to_members_clicked(); break;
        case 3: _t->on_go_to_teams_clicked(); break;
        case 4: _t->on_back_to_event_clicked(); break;
        case 5: _t->on_back_to_teams_clicked(); break;
        case 6: _t->on_go_to_record_clicked(); break;
        case 7: _t->paintEvent((*reinterpret_cast< std::add_pointer_t<QPaintEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (record_mode::*)(Team , Team , Game );
            if (_t _q_method = &record_mode::sentdata; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *record_mode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *record_mode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSrecord_modeENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int record_mode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void record_mode::sentdata(Team _t1, Team _t2, Game _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
