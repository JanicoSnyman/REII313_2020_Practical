#include "node.h"

Node::Node() {

}

void Node::update() {

}

QRectF Node::boundingRect() const {
    return QRectF(200, 200, 50, 50);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->drawRect(200,200,50,50);
}


