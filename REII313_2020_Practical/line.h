#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "node.h"
#include "config.h"


class Line : public QGraphicsItem {
    Q_OBJECT
public:
    Line();
    void update();
private:
    QList <Node *> nodes;
};

#endif // LINE_H
