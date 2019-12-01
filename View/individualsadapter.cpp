#include "individualsadapter.h"

IndividualsAdapter::IndividualsAdapter(I_Individuals &inputInterface)
    : individualsInterface(inputInterface)
{
    obtainInputs();
}

IndividualsAdapter::~IndividualsAdapter()
{
    clearInputs();
}

QList<QGraphicsEllipseItem *> *IndividualsAdapter::getEllipses()
{
    /** @todo to be refactored, this is highly inefficient... observer pattern to subscribe to changes? */
    clearInputs();
    obtainInputs();
    return &ellipses;
}

void IndividualsAdapter::obtainInputs()
{
    QList<Species*>* species = individualsInterface.getIndividuals();

    for(QList<Species*>::iterator it = species->begin(); it != species->end(); it++)
    {
        ellipses.push_back(new QGraphicsEllipseItem((*it)->rect()));
    }
}

void IndividualsAdapter::clearInputs()
{
    for(QList<QGraphicsEllipseItem*>::iterator it = ellipses.begin(); it != ellipses.end(); it++)
    {
        delete (*it);
        ellipses.erase(it);
    }
}

