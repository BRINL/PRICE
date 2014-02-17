/****************************************************************************
** Meta object code from reading C++ file 'Mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PRICER/Mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 8),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 8),
QT_MOC_LITERAL(4, 30, 8),
QT_MOC_LITERAL(5, 39, 6),
QT_MOC_LITERAL(6, 46, 8),
QT_MOC_LITERAL(7, 55, 5),
QT_MOC_LITERAL(8, 61, 3),
QT_MOC_LITERAL(9, 65, 8),
QT_MOC_LITERAL(10, 74, 3),
QT_MOC_LITERAL(11, 78, 7),
QT_MOC_LITERAL(12, 86, 8),
QT_MOC_LITERAL(13, 95, 5),
QT_MOC_LITERAL(14, 101, 15),
QT_MOC_LITERAL(15, 117, 3),
QT_MOC_LITERAL(16, 121, 7),
QT_MOC_LITERAL(17, 129, 7),
QT_MOC_LITERAL(18, 137, 7),
QT_MOC_LITERAL(19, 145, 6),
QT_MOC_LITERAL(20, 152, 6),
QT_MOC_LITERAL(21, 159, 4),
QT_MOC_LITERAL(22, 164, 6)
    },
    "MainWindow\0AddSimuL\0\0AddSimuB\0edStrike\0"
    "edSpot\0edExpiry\0edVol\0edr\0edlambda\0"
    "edm\0edvega2\0edMCStop\0edPOC\0edNumberOfPaths\0"
    "edt\0update2\0update3\0update4\0CleanB\0"
    "CleanL\0VarP\0Volimp\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x0a,
       3,    0,  120,    2, 0x0a,
       4,    0,  121,    2, 0x0a,
       5,    0,  122,    2, 0x0a,
       6,    0,  123,    2, 0x0a,
       7,    0,  124,    2, 0x0a,
       8,    0,  125,    2, 0x0a,
       9,    0,  126,    2, 0x0a,
      10,    0,  127,    2, 0x0a,
      11,    0,  128,    2, 0x0a,
      12,    0,  129,    2, 0x0a,
      13,    0,  130,    2, 0x0a,
      14,    0,  131,    2, 0x0a,
      15,    0,  132,    2, 0x0a,
      16,    0,  133,    2, 0x0a,
      17,    0,  134,    2, 0x0a,
      18,    0,  135,    2, 0x0a,
      19,    0,  136,    2, 0x0a,
      20,    0,  137,    2, 0x0a,
      21,    0,  138,    2, 0x0a,
      22,    0,  139,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::ULong,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->AddSimuL(); break;
        case 1: _t->AddSimuB(); break;
        case 2: { double _r = _t->edStrike();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 3: { double _r = _t->edSpot();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 4: { double _r = _t->edExpiry();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: { double _r = _t->edVol();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->edr();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { double _r = _t->edlambda();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 8: { double _r = _t->edm();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 9: { double _r = _t->edvega2();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->edMCStop();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->edPOC();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { ulong _r = _t->edNumberOfPaths();
            if (_a[0]) *reinterpret_cast< ulong*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->edt();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: _t->update2(); break;
        case 15: _t->update3(); break;
        case 16: _t->update4(); break;
        case 17: _t->CleanB(); break;
        case 18: _t->CleanL(); break;
        case 19: _t->VarP(); break;
        case 20: _t->Volimp(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
