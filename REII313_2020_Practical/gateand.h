#ifndef GATEAND_H
#define GATEAND_H
#include "gate.h"

class GateAND : public Gate {
public:
    GateAND();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void updateGate();
};

#endif // GATEAND_H
