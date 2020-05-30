#ifndef GATE_H
#define GATE_H

#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "node.h"
#include "config.h"


class Gate : public QGraphicsItem {

public:
    Gate();
    virtual void update() = 0;
private:
    QList<Node *> inputs;
    QList<Node *> outputs;
};

#endif // GATE_H
