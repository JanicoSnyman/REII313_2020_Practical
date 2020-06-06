#include "gatexor.h"

GateXOR::GateXOR()
{
    this->inputs = new QList<Node *>;
    this->outputs = new QList<Node *>;

    Node * input1 = new Node(100, 120);
    input1->setParentItem(this);
    input1->level = 0;
    input1->gateIn = true;
    this->inputs->push_back(input1);

    Node * input2 = new Node(100, 170);
    input2->setParentItem(this);
    input2->level = 0;
    input2->gateIn = true;
    this->inputs->push_back(input2);

    Node * output = new Node(200, 145);
    output->setParentItem(this);
    output->level = 0;
    output->gateOut = true;
    this->outputs->push_back(output);
}

void GateXOR::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget) {
    painter->drawArc(75, 100, 50, 100, 90*16, -180*16);
    painter->drawArc(0, 100, 200, 100, 90*16, -90*16);
    painter->drawArc(0, 100, 200, 100, 270*16, 90*16);
    painter->drawArc(70, 100, 45, 100, 90*16, -180*16);
}


QRectF GateXOR::boundingRect() const {
    return QRectF(90, 100, 120, 100);
}

void GateXOR::updateGate() {
    this->outputs->first()->level = (this->inputs->at(0)->level && !(this->inputs->at(1)->level)) || (!(this->inputs->at(0)->level) && this->inputs->at(1)->level);
}
