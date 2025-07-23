/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../06_FileBrowser/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[13];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 21), // "showDirectoryContents"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 47, 4), // "item"
QT_MOC_LITERAL(5, 52, 8), // "openFile"
QT_MOC_LITERAL(6, 61, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(7, 79, 19), // "showTreeContextMenu"
QT_MOC_LITERAL(8, 99, 3), // "pos"
QT_MOC_LITERAL(9, 103, 20), // "showTableContextMenu"
QT_MOC_LITERAL(10, 124, 11), // "refreshTree"
QT_MOC_LITERAL(11, 136, 16), // "openSelectedFile"
QT_MOC_LITERAL(12, 153, 18) // "deleteSelectedFile"

    },
    "Widget\0showDirectoryContents\0\0"
    "QTreeWidgetItem*\0item\0openFile\0"
    "QTableWidgetItem*\0showTreeContextMenu\0"
    "pos\0showTableContextMenu\0refreshTree\0"
    "openSelectedFile\0deleteSelectedFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       9,    1,   60,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    0,   64,    2, 0x08 /* Private */,
      12,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    2,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showDirectoryContents((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->openFile((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->showTreeContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->showTableContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->refreshTree(); break;
        case 5: _t->openSelectedFile(); break;
        case 6: _t->deleteSelectedFile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
