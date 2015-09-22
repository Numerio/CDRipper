/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat May 26 13:21:59 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      20,   11,   11,   11, 0x08,
      27,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,
     222,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     256,   11,   11,   11, 0x08,
     266,   11,   11,   11, 0x08,
     284,   11,   11,   11, 0x08,
     302,   11,   11,   11, 0x08,
     319,   11,   11,   11, 0x08,
     335,   11,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0start()\0stop()\0cleanAll()\0"
    "rename()\0cdparanoia()\0upFile()\0"
    "upRippedFile()\0downFile()\0downRippedFile()\0"
    "addFile()\0addRippedFile()\0removeFile()\0"
    "removeRippedFile()\0newProject()\0"
    "saveProject()\0loadProject()\0settings()\0"
    "readFromStderr()\0readFromStdout()\0"
    "dfinish()\0dreadFromStderr()\0"
    "dreadFromStdout()\0paranoiaFinish()\0"
    "convertFinish()\0_calculateDuration()\0"
    "_calculate(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->stop(); break;
        case 2: _t->cleanAll(); break;
        case 3: _t->rename(); break;
        case 4: _t->cdparanoia(); break;
        case 5: _t->upFile(); break;
        case 6: _t->upRippedFile(); break;
        case 7: _t->downFile(); break;
        case 8: _t->downRippedFile(); break;
        case 9: _t->addFile(); break;
        case 10: _t->addRippedFile(); break;
        case 11: _t->removeFile(); break;
        case 12: _t->removeRippedFile(); break;
        case 13: _t->newProject(); break;
        case 14: _t->saveProject(); break;
        case 15: _t->loadProject(); break;
        case 16: _t->settings(); break;
        case 17: _t->readFromStderr(); break;
        case 18: _t->readFromStdout(); break;
        case 19: _t->dfinish(); break;
        case 20: _t->dreadFromStderr(); break;
        case 21: _t->dreadFromStdout(); break;
        case 22: _t->paranoiaFinish(); break;
        case 23: _t->convertFinish(); break;
        case 24: _t->_calculateDuration(); break;
        case 25: _t->_calculate((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
