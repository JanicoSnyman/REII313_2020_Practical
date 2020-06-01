#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include "config.h"


class Node : public QGraphicsItem {
public:
    Node(const int x, const int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void update();
    bool level;
private:
    int xpos;
    int ypos;
};

#endif // NODE_H
