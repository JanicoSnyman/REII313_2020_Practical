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
        this->sourcePoint = QPointF(this->sourceNode->scenePos().x() + this->sourceNode->xoffset() + 5, this->sourceNode->scenePos().y() + this->sourceNode->yoffset() + 5);
    }
    if(endNode != nullptr) {
        this->endPoint = QPointF(this->endNode->scenePos().x() + this->endNode->xoffset() + 5, this->endNode->scenePos().y() + this->endNode->yoffset() + 5);
    }

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->drawLine(this->sourcePoint, this->endPoint);
}

QRectF Line::boundingRect() const {
    return QRectF(this->sourcePoint, this->endPoint);
}
