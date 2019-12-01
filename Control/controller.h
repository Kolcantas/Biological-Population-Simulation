#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainwindow.h"
#include <QTimer>

#include "population.h"
#include "I_Individuals.h"


class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
    ~Controller();

    void start(int frameDelayInMs = 500);

public slots:
    void executeNextIteration();

private:
    void setup(int numberOfInitialIndividuals = 5);

    QTimer* refreshTimer;
    MainWindow* mainWindow = nullptr;
    Population* population = nullptr;
    unsigned long int iteration = 0;

};

#endif // CONTROLLER_H
