#ifndef LINE_H
#define LINE_H

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


class Line : public QGraphicsItem {

public:
    Line();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    QRectF boundingRect() const;
    void update();

    QPointF sourcePoint;
    QPointF endPoint;
    Node * sourceNode;
    Node * endNode;

    bool selected;
};

#endif // LINE_H
