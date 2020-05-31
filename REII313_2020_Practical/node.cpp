#include "node.h"

Node::Node(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void Node::update() {

}

QRectF Node::boundingRect() const {
    return QRectF(x, y, 10, 10);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->drawRect(x, y, 10, 10);
}


