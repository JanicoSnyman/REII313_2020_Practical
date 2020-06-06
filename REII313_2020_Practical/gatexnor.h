#ifndef GATEXNOR_H
#define GATEXNOR_H
#include "gate.h"

class GateXNOR : public Gate {
public:
    GateXNOR();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void updateGate();
};

#endif // GATEXNOR_H
