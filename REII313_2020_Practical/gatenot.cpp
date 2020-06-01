#include "gatenot.h"

GateNOT::GateNOT()
{
    this->inputs = new QList<Node *>;
    this->outputs = new QList<Node *>;

    Node * input = new Node(90, 145);
    input->setParentItem(this);
    input->level = 0;
    this->inputs->push_back(input);

    Node * output = new Node(210, 145);
    output->setParentItem(this);
    output->level = 1;
    this->outputs->push_back(output);
}

void GateNOT::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget) {
    painter->drawLine(100, 100, 100, 200);
    painter->drawLine(100, 100, 200, 150);
    painter->drawLine(100, 200, 200, 150);
    painter->drawEllipse(200, 145, 10, 10);
}

QRectF GateNOT::boundingRect() const {
    return QRectF(90, 100, 130, 100);
}

void GateNOT::update() {

}
