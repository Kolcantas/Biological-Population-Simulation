#ifndef I_GRAPHICSITEMS_H
#define I_GRAPHICSITEMS_H

#include <QGraphicsEllipseItem>
#include <list>

class I_GraphicsItems
{
public:
    virtual QList<QGraphicsEllipseItem*>* getEllipses() = 0;
};

#endif // I_GRAPHICSITEMS_H
