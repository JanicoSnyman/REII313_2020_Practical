#include "line.h"

Line::Line()
{
    this->sourcePoint = QPointF(100, 100);
    this->endPoint = QPointF(150, 200);
}

void Line::update() {

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->drawLine(this->sourcePoint, this->endPoint);
}

QRectF Line::boundingRect() const {
    return QRectF(this->sourcePoint, this->endPoint);
}
