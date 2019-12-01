#ifndef I_INDIVIDUALGRAPHICS_H
#define I_INDIVIDUALGRAPHICS_H

#include <list>
#include "species.h"

class I_Individuals {
public:
    virtual QList<Species*>* getIndividuals() = 0;
};

#endif // I_INDIVIDUALGRAPHICS_H
