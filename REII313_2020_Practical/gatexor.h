#ifndef GATEXOR_H
#define GATEXOR_H
#include "gate.h"

class GateXOR : public Gate {
public:
    GateXOR();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void updateGate();
};

#endif // GATEXOR_H
