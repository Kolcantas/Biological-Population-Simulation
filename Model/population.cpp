#include "population.h"


Population::Population()
{

}

Population::~Population()
{
    for(QList<Species*>::iterator it = listOfIndividuals.begin(); it != listOfIndividuals.end(); it++)
    {
        delete (*it);
        listOfIndividuals.erase(it);
    }
}

void Population::addIndividual()
{
    listOfIndividuals.push_back(new Species(coordOfLastIndividual));
    coordOfLastIndividual.setX(coordOfLastIndividual.x() + 50);
}
