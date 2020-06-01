#include "node.h"

Node::Node(const int x, const int y) {
    this->xpos = x;
    this->ypos = y;
    this->level = 0;
}

void Node::update() {

}

QRectF Node::boundingRect() const {
    return QRectF(xpos, ypos, 10, 10);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    if(this->level) {
        painter->setPen(Qt::green);
    } else {
        painter->setPen(Qt::red);
    }
    painter->drawRect(xpos, ypos, 10, 10);
}


