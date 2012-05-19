/****************************************************************************
** Meta object code from reading C++ file 'Dialog.h'
**
** Created: Mon 7. May 01:00:51 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      31,    7,    7,    7, 0x08,
      49,    7,    7,    7, 0x08,
      67,    7,    7,    7, 0x08,
      82,    7,    7,    7, 0x08,
      98,    7,    7,    7, 0x08,
     119,    7,    7,    7, 0x08,
     134,    7,    7,    7, 0x08,
     157,    7,    7,    7, 0x08,
     174,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialog[] = {
    "Dialog\0\0setExistingDirectory()\0"
    "setOpenFileName()\0questionMessage()\0"
    "errorMessage()\0DetectFileDpi()\0"
    "DetectWriteFileDpi()\0WriteFileDpi()\0"
    "DetectWriteFolderDpi()\0WriteFolderDpi()\0"
    "handleFinished()\0"
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog *_t = static_cast<Dialog *>(_o);
        switch (_id) {
        case 0: _t->setExistingDirectory(); break;
        case 1: _t->setOpenFileName(); break;
        case 2: _t->questionMessage(); break;
        case 3: _t->errorMessage(); break;
        case 4: _t->DetectFileDpi(); break;
        case 5: _t->DetectWriteFileDpi(); break;
        case 6: _t->WriteFileDpi(); break;
        case 7: _t->DetectWriteFolderDpi(); break;
        case 8: _t->WriteFolderDpi(); break;
        case 9: _t->handleFinished(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Dialog,
      qt_meta_data_Dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
