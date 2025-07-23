#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("员工管理系统");
    resize(800, 600);

    // 将代码拆分出去,形成函数
    setWidgetLayout();
    connectSignals();
    addTestData();
}

// 布局函数
void Widget::setWidgetLayout(){
    // 创建对象
    listWidget = new QListWidget;

    btn1 = new QPushButton("添加");
    btn2 = new QPushButton("删除");

    searchEdit = new QLineEdit;
    searchEdit->setPlaceholderText("请输入需要搜索的员工");

    // 创建布局
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(btn1);
    hLayout->addWidget(btn2);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(listWidget);
    vLayout->addWidget(searchEdit);
    vLayout->addLayout(hLayout);
    setLayout(vLayout);
}

// 使用信号与槽链接交互功能
void Widget::connectSignals(){
    // 添加员工功能
    connect(btn1, &QPushButton::clicked, this, &Widget::addEmployee);
    // 删除员工功能
    connect(btn2, &QPushButton::clicked, this, &Widget::delEmployee);
    // 搜索功能
    connect(searchEdit, &QLineEdit::textChanged, this, &Widget::search);
}

// 添加测试数据
void Widget::addTestData(){
    listWidget->addItems(QStringList() << "张三" << "李四" << "王五" << "赵六");
}

// 槽函数--添加
void Widget::addEmployee(){
    bool flag;
    QString name = QInputDialog::getText(this, "添加员工", "请输入员工姓名", QLineEdit::Normal, "", &flag);
    if(flag && !name.isEmpty()){
        listWidget->addItem(name);
    }
}

// 槽函数--删除
void Widget::delEmployee(){
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "提示框", "是否删除选中项", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            delete listWidget->takeItem(listWidget->currentRow());
        }
}

// 槽函数--搜索
void Widget::search(const QString &text){
    // 遍历listWidget
    for(int i = 0; i < listWidget->count(); ++i){
        // 获取item部件
        QListWidgetItem *currentItem = listWidget->item(i);
        // 获取item的文本
        QString value = currentItem->text();

        // 进行判断(是否含有text的字串),设置隐藏
        if(!value.contains(text, Qt::CaseInsensitive)){
            currentItem->setHidden(true);
        }
        //currentItem->setHidden(!currentItem->text().contains(text, Qt::CaseInsensitive));
    }
}

Widget::~Widget()
{
}

