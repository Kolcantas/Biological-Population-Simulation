#include "controller.h"
#include <iostream>

Controller::Controller()
{
    mainWindow = new MainWindow;
    population = new Population;
    individualsAdapter = new IndividualsAdapter(*population);
    mainWindow->attachGraphicsItemInterface(individualsAdapter);

    setup();
}

Controller::~Controller()
{
    delete mainWindow;
    delete population;
    delete individualsAdapter;
}

void Controller::setup(int numberOfInitialIndividuals)
{
    for(int i = 0; i < numberOfInitialIndividuals; i++)
    {
        population->addIndividual();
    }


    refreshTimer = new QTimer(mainWindow);
    QObject::connect(refreshTimer, SIGNAL(timeout()), this, SLOT(executeNextIteration()));
}

void Controller::start(int frameDelayInMs)
{
    mainWindow->show();
    refreshTimer->start(frameDelayInMs);
}

void Controller::executeNextIteration()
{
    std::cout << "Iteration: " << iteration++ << "." << std::endl;
    mainWindow->updateView();
}

