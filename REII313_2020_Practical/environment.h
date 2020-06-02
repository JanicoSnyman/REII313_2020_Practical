#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QGraphicsScene>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QTimer>
#include <QDebug>
#include <QPushButton>
#include "config.h"
#include "node.h"
#include "gateand.h"
#include "gatenot.h"
#include "line.h"

class Environment : public QGraphicsScene {
Q_OBJECT
public:
    Environment();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    void update();
public slots:
    void addAND();
    void addOR();
    void addNOT();
    void addNode();
    void addLine();
private:
    QPushButton * buttonAND;
    QPushButton * buttonOR;
    QPushButton * buttonNOT;
    QPushButton * buttonNode;
    QPushButton * buttonLine;

    QList <Node *> * nodes;
    QList <Gate *> * gates;
    QList <Line *> * lines;

    unsigned int lineConnecting;
    Line * lineToConnect;
};


#endif // ENVIRONMENT_H
