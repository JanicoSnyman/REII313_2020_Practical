#include "gateand.h"

GateAND::GateAND()
{
    this->inputs = new QList<Node *>;
    this->outputs = new QList<Node *>;

    Node * input1 = new Node(90, 120);
    input1->setParentItem(this);
    input1->level = 0;
    this->inputs->push_back(input1);

    Node * input2 = new Node(90, 170);
    input2->setParentItem(this);
    input2->level = 0;
    this->inputs->push_back(input2);

    Node * output = new Node(200, 145);
    output->setParentItem(this);
    output->level = 0;
    this->outputs->push_back(output);
}

void GateAND::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget) {
    painter->drawLine(100, 100, 100, 200);
    painter->drawLine(100, 100, 150, 100);
    painter->drawLine(100, 200, 150, 200);
    painter->drawArc(100, 100, 100, 100, 90*16, -180*16);
}


QRectF GateAND::boundingRect() const {
    return QRectF(90, 100, 120, 100);
}

void GateAND::update() {

}
