#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "node.h"
#include "config.h"


class Line : public QGraphicsItem {

public:
    Line();
    void update();
private:
    Node * sourceNode;
    Node * endNode;
};

#endif // LINE_H
