#ifndef POPULATION_H
#define POPULATION_H

#include "species.h"
#include "I_Individuals.h"

class Population : public I_Individuals
{
public:
    Population();
    virtual ~Population();

    void addIndividual();
    QList<Species*>* getIndividuals() override { return &listOfIndividuals; }

private:
    QPoint coordOfLastIndividual = {0, 0};
    QList<Species*> listOfIndividuals;
};

#endif // POPULATION_H
