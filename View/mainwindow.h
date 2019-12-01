#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "I_GraphicsItems.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateView();
    void showSize(QGraphicsScene& scene) const;
    void attachGraphicsItemInterface(I_GraphicsItems* interface);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsView* view;
    I_GraphicsItems* graphicsItemsInterface;
    QList<QGraphicsEllipseItem*>* ellipses;

    QGraphicsEllipseItem* ellipse;
};

#endif // MAINWINDOW_H
