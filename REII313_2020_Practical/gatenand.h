#ifndef GATENAND_H
#define GATENAND_H
#include "gate.h"

class GateNAND : public Gate {
public:
    GateNAND();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void updateGate();
};

#endif // GATENAND_H
