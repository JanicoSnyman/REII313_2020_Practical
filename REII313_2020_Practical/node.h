#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QTimer>
#include <QDebug>
#include "config.h"


class Node : public QGraphicsItem {
public:
    Node();
    void update();
private:
    int x;
    int y;
    bool level;
};

#endif // NODE_H
