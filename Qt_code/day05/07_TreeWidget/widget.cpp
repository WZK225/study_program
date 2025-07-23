#include "widget.h"
#include <QTreeWidget>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    // 设置水平头
    QTreeWidget *treeWidget = new QTreeWidget;
    treeWidget->setHeaderLabels(QStringList() << "将帅名" << "将帅介绍");

    // 设置树形部件项目
    QTreeWidgetItem *weaponryItem = new QTreeWidgetItem(QStringList() << "兵器");
    QTreeWidgetItem *fightItem = new QTreeWidgetItem(QStringList() << "战斗力");
    QTreeWidgetItem *warRecordItem = new QTreeWidgetItem(QStringList() << "战绩");

    // 加载顶层结点
    treeWidget->addTopLevelItem(weaponryItem);
    treeWidget->addTopLevelItem(fightItem);
    treeWidget->addTopLevelItem(warRecordItem);

    // 追加子节点
    QStringList herol1;
    herol1 << "关羽" << "关二爷，过五关斩六";
    QTreeWidgetItem *l1 = new QTreeWidgetItem(herol1);
    weaponryItem->addChild(l1);

    QStringList herol2;
    herol2 << "张飞" << "涿郡屠夫，长坂坡一声吼吓退曹操七十万大军";
    QTreeWidgetItem *l2 = new QTreeWidgetItem(herol2);
    weaponryItem->addChild(l2);

    QStringList herol3;
    herol3 << "赵云" << "常山赵子龙，七进七出救阿斗";
    QTreeWidgetItem *l3 = new QTreeWidgetItem(herol3);
    weaponryItem->addChild(l3);

    QStringList fight1;
    fight1 << "刀斧手" << "战斗力99";
    QTreeWidgetItem *f1 = new QTreeWidgetItem(fight1);
    fightItem->addChild(f1);

    QStringList fight2;
    fight2 << "嘴王" << "战斗力90";
    QTreeWidgetItem *f2 = new QTreeWidgetItem(fight2);
    fightItem->addChild(f2);

    QStringList fight3;
    fight3 << "侍卫" << "战斗力100";
    QTreeWidgetItem *f3 = new QTreeWidgetItem(fight3);
    fightItem->addChild(f3);

    QStringList record1;
    record1 << "站位" << "砍杀华雄";
    QTreeWidgetItem *r1 = new QTreeWidgetItem(record1);
    warRecordItem->addChild(r1);

    QStringList record2;
    record2 << "嘴位" << "死磕吕布";
    QTreeWidgetItem *r2 = new QTreeWidgetItem(record2);
    warRecordItem->addChild(r2);

    QStringList record3;
    record3 << "冲位" << "入曹营如探囊取物";
    QTreeWidgetItem *r3 = new QTreeWidgetItem(record3);
    warRecordItem->addChild(r3);

    treeWidget->expandAll();

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(treeWidget);
    setLayout(hLayout);
}

Widget::~Widget()
{
}

