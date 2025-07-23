#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QPushButton>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口的名称
    setWindowTitle("测试窗口");
    // 调整窗口大小
    resize(600, 480);
    // 创建一个菜单栏
    QMenuBar *mbr = new QMenuBar;
    setMenuBar(mbr);
    mbr->resize(600, 40);
    QMenu *fileMenu = mbr->addMenu("文件");
    QMenu *editMenu = mbr->addMenu("编辑");
    QMenu *viewMenu =mbr->addMenu("视图");

    QAction *newAc = new QAction("新建");
    QAction *openAc = new QAction("打开");
    QAction *saveAc = new QAction("保存");

    fileMenu->addAction(newAc);
    fileMenu->addAction(openAc);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAc);

    // 创建一个工具栏
    QToolBar *tbr = new QToolBar;
    addToolBar(Qt::TopToolBarArea, tbr);
    tbr->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

//    tbr->setFloatable(true);
//    tbr->setMovable(true);

    tbr->addAction(newAc);
    tbr->addAction(openAc);
    tbr->addSeparator();
    tbr->addAction(saveAc);

    // 创建一个浮动窗口
    QDockWidget *dw = new QDockWidget("浮动窗口");
    addDockWidget(Qt::LeftDockWidgetArea, dw);

    // 设置中心部件
    QPushButton *pbt = new QPushButton("中心按钮");
    setCentralWidget(pbt);

    // 创建一个状态栏
    QStatusBar *stb = new QStatusBar();
    setStatusBar(stb);

    QPushButton *pbt1 = new QPushButton("按钮1");
    QPushButton *pbt2 = new QPushButton("按钮2");
    QPushButton *pbt3 = new QPushButton("按钮3");
    stb->addWidget(pbt1);
    stb->addWidget(pbt2);
    stb->addPermanentWidget(pbt3);
}

MainWindow::~MainWindow()
{
}

