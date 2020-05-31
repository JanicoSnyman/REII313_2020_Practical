#ifndef GATEAND_H
#define GATEAND_H
#include "gate.h"

class GateAND
{
public:
    GateAND();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void update();
};

#endif // GATEAND_H
