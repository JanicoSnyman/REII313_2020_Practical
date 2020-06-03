#include "line.h"

Line::Line()
{
    this->sourcePoint = QPointF(100, 100);
    this->endPoint = QPointF(150, 200);
    this->sourceNode = nullptr;
    this->endNode = nullptr;

    selected = false;
}

void Line::update() {
    if(sourceNode != nullptr) {
        this->sourcePoint = QPointF(this->sourceNode->scenePos().x() + this->sourceNode->xoffset() + 5, this->sourceNode->scenePos().y() + this->sourceNode->yoffset() + 5);
    }
    if(endNode != nullptr) {
        this->endPoint = QPointF(this->endNode->scenePos().x() + this->endNode->xoffset() + 5, this->endNode->scenePos().y() + this->endNode->yoffset() + 5);
    }

    if(sourceNode != nullptr && endNode != nullptr) {
        if(sourceNode->gateIn && !endNode->gateIn) {
            sourceNode->level = endNode->level;
        } else if(!sourceNode->gateIn && endNode->gateIn) {
            endNode->level = sourceNode->level;
        } else if(sourceNode->gateOut && !endNode->gateOut) {
            endNode->level = sourceNode->level;
        } else if(!sourceNode->gateOut && endNode->gateOut) {
            sourceNode->level = endNode->level;
        } else {
            endNode->level = sourceNode->level;
        }
    }
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    QPen pen;
    if(selected) {
        pen.setWidth(2);
        pen.setColor(Qt::blue);
    }
    painter->setPen(pen);
    painter->drawLine(this->sourcePoint, this->endPoint);
}

QRectF Line::boundingRect() const {
    return QRectF(this->sourcePoint, this->endPoint);
}
