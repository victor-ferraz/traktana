/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Tue Oct 26 22:33:13 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      38,   11,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      92,   11,   11,   11, 0x0a,
     121,   11,   11,   11, 0x0a,
     152,   11,   11,   11, 0x0a,
     180,   11,   11,   11, 0x0a,
     207,   11,   11,   11, 0x0a,
     242,   11,   11,   11, 0x0a,
     274,   11,   11,   11, 0x0a,
     303,   11,   11,   11, 0x0a,
     338,   11,   11,   11, 0x0a,
     378,   11,   11,   11, 0x0a,
     417,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionExit_triggered()\0"
    "on_actionStart_triggered()\0"
    "on_actionPause_triggered()\0"
    "on_actionRestart_triggered()\0"
    "on_actionOperation_triggered()\0"
    "on_actionStatus_triggered()\0"
    "on_actionDebug_triggered()\0"
    "on_actionOperationTool_triggered()\0"
    "on_actionDeviceTool_triggered()\0"
    "on_actionConnect_triggered()\0"
    "on_actionConnect_Debug_triggered()\0"
    "on_actionSerialDeviceConfig_triggered()\0"
    "on_actionSerialDebugConfig_triggered()\0"
    "on_actionAbout_triggered()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionExit_triggered(); break;
        case 1: on_actionStart_triggered(); break;
        case 2: on_actionPause_triggered(); break;
        case 3: on_actionRestart_triggered(); break;
        case 4: on_actionOperation_triggered(); break;
        case 5: on_actionStatus_triggered(); break;
        case 6: on_actionDebug_triggered(); break;
        case 7: on_actionOperationTool_triggered(); break;
        case 8: on_actionDeviceTool_triggered(); break;
        case 9: on_actionConnect_triggered(); break;
        case 10: on_actionConnect_Debug_triggered(); break;
        case 11: on_actionSerialDeviceConfig_triggered(); break;
        case 12: on_actionSerialDebugConfig_triggered(); break;
        case 13: on_actionAbout_triggered(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
