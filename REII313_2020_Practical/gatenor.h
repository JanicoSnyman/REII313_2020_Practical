#ifndef GATENOR_H
#define GATENOR_H
#include "gate.h"

class GateNOR : public Gate {
public:
    GateNOR();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void updateGate();
};

#endif // GATENOR_H
