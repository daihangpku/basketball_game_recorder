/****************************************************************************
** Meta object code from reading C++ file 'replay.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../replay.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'replay.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSreplayENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSreplayENDCLASS = QtMocHelpers::stringData(
    "replay",
    "on_pushButton_clicked",
    "",
    "timeout1_slot",
    "generate_game_report",
    "Game&",
    "game",
    "Team&",
    "team1",
    "team2",
    "on_see_clicked",
    "on_out2_clicked",
    "on_all_show_clicked",
    "on_continue_2_clicked",
    "on_stop_clicked",
    "process_event",
    "Event*",
    "event",
    "on_begin_clicked",
    "on_replayy_clicked",
    "paintEvent",
    "QPaintEvent*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSreplayENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    3,   88,    2, 0x08,    3 /* Private */,
      10,    0,   95,    2, 0x08,    7 /* Private */,
      11,    0,   96,    2, 0x08,    8 /* Private */,
      12,    0,   97,    2, 0x08,    9 /* Private */,
      13,    0,   98,    2, 0x08,   10 /* Private */,
      14,    0,   99,    2, 0x08,   11 /* Private */,
      15,    3,  100,    2, 0x08,   12 /* Private */,
      18,    0,  107,    2, 0x08,   16 /* Private */,
      19,    0,  108,    2, 0x08,   17 /* Private */,
      20,    1,  109,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 16,    8,    9,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject replay::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSreplayENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSreplayENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSreplayENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<replay, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timeout1_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generate_game_report'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Game &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Team &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Team &, std::false_type>,
        // method 'on_see_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_out2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_all_show_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_continue_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'process_event'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Team &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Team &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Event *, std::false_type>,
        // method 'on_begin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_replayy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'paintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>
    >,
    nullptr
} };

void replay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<replay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->timeout1_slot(); break;
        case 2: _t->generate_game_report((*reinterpret_cast< std::add_pointer_t<Game&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Team&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Team&>>(_a[3]))); break;
        case 3: _t->on_see_clicked(); break;
        case 4: _t->on_out2_clicked(); break;
        case 5: _t->on_all_show_clicked(); break;
        case 6: _t->on_continue_2_clicked(); break;
        case 7: _t->on_stop_clicked(); break;
        case 8: _t->process_event((*reinterpret_cast< std::add_pointer_t<Team&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Team&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Event*>>(_a[3]))); break;
        case 9: _t->on_begin_clicked(); break;
        case 10: _t->on_replayy_clicked(); break;
        case 11: _t->paintEvent((*reinterpret_cast< std::add_pointer_t<QPaintEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *replay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *replay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSreplayENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int replay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
