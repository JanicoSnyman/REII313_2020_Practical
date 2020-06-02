#ifndef GATEOR_H
#define GATEOR_H
#include "gate.h"

class GateOR : public Gate {
public:
    GateOR();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void updateGate();
};

#endif // GATEOR_H
