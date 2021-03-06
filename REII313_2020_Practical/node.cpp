#include "node.h"

Node::Node(const int x, const int y) {
    this->xpos = x;
    this->ypos = y;
    this->level = 0;
    this->gateOut = false;
    this->gateIn = false;
    clocked = false;
}

void Node::update() {

}

QRectF Node::boundingRect() const {
    return QRectF(xpos, ypos, 10, 10);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    QPen pen;
    pen.setWidth(2);
    if(this->level) {
        pen.setColor(Qt::darkGreen);
        painter->setPen(pen);
    } else {
        pen.setColor(Qt::red);
        painter->setPen(pen);
    }
    painter->drawRect(xpos, ypos, 10, 10);
}

int Node::xoffset() {
    return this->xpos;
}

int Node::yoffset() {
    return this->ypos;
}
