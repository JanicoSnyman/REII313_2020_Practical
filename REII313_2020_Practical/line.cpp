#include "line.h"

Line::Line()
{
    this->sourcePoint = QPointF(100, 100);
    this->endPoint = QPointF(150, 200);
    this->sourceNode = nullptr;
    this->endNode = nullptr;
}

void Line::update() {
    if(sourceNode != nullptr) {
        this->sourcePoint = QPointF(this->sourceNode->scenePos().x() + this->sourceNode->xoffset(), this->sourceNode->scenePos().y() + this->sourceNode->yoffset());
    }
    if(endNode != nullptr) {
        this->endPoint = QPointF(this->endNode->scenePos().x() + this->endNode->xoffset(), this->endNode->scenePos().y() + this->endNode->yoffset());
    }
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->drawLine(this->sourcePoint, this->endPoint);
}

QRectF Line::boundingRect() const {
    return QRectF(this->sourcePoint, this->endPoint);
}
