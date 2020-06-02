#ifndef GATENOT_H
#define GATENOT_H
#include "gate.h"


class GateNOT : public Gate {
public:
    GateNOT();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void updateGate();
};

#endif // GATENOT_H
