#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("文件浏览器");
    resize(800, 600);

    set_Layout();
    set_connect();
    //add_data();
}

// 添加对象,设置布局
void Widget::set_Layout(){

}

Widget::~Widget()
{
}

