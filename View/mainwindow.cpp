#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,500,500);
    showSize(*scene);

    view = new QGraphicsView(scene);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(false);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setGeometry(0,0,500,500);
    scrollArea->setWidget(view);

//    QList<QObject*> childrenList = this->children();
//    std::cout << "Children of " << qPrintable(this->objectName()) << " are:" << std::endl;
//    for(QList<QObject*>::iterator it = childrenList.begin(); it < childrenList.end(); it++)
//    {
//        std::cout << qPrintable((*it)->objectName()) << std::endl;
//    }

    QBrush redBrush(Qt::red);
    QPen pen(Qt::yellow);
    ellipse = scene->addEllipse(100, 100, 30, 30, pen, redBrush);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateView()
{
    ellipses = graphicsItemsInterface->getEllipses();
    for(QList<QGraphicsEllipseItem*>::iterator it = ellipses->begin(); it != ellipses->end(); it++)
    {
        scene->addEllipse((*it)->rect());
    }

    ellipse->moveBy(50,50);
}

void MainWindow::showSize(QGraphicsScene& scene) const
{
    std::cout << "WIDTH: " << scene.width() << "\t";
    std::cout << "HEIGHT " << scene.height() << "\t" << std::endl;
}

void MainWindow::attachGraphicsItemInterface(I_GraphicsItems *interface)
{
    graphicsItemsInterface = interface;
}

