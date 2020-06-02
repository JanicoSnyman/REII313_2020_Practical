#ifndef GATE_H
#define GATE_H

#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "node.h"
#include "config.h"


class Gate : public QGraphicsItem {

public:
    Gate();
    virtual void updateGate() = 0;
    QList<Node *> * inputs;
    QList<Node *> * outputs;
};

#endif // GATE_H
