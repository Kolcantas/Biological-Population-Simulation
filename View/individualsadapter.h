#ifndef INDIVIDUALSADAPTER_H
#define INDIVIDUALSADAPTER_H

#include "I_Individuals.h"
#include "I_GraphicsItems.h"


class IndividualsAdapter : public I_GraphicsItems
{
public:
    IndividualsAdapter(I_Individuals& inputInterface);
    ~IndividualsAdapter();

    QList<QGraphicsEllipseItem *> * getEllipses() override;

private:
    void obtainInputs();
    void clearInputs();
    I_Individuals& individualsInterface;
    QList<QGraphicsEllipseItem*> ellipses;
};

#endif // INDIVIDUALSADAPTER_H
