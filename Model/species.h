#ifndef SPECIES_H
#define SPECIES_H

#include <QGraphicsEllipseItem>

typedef enum
{
    INIT = 0x00,
    ALIVE,
    DEAD
} SpeciesStatus_t;

class Species : public QGraphicsEllipseItem
{
public:
    Species(QPoint coord) : QGraphicsEllipseItem(coord.x(), coord.y(), 10, 10), status(ALIVE)
    {}
    SpeciesStatus_t getStatus() { return status; }

private:
    SpeciesStatus_t status;
};

#endif // SPECIES_H
