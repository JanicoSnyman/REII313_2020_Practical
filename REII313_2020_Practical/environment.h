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
#include "gatenand.h"
#include "gatenot.h"
#include "gateor.h"
#include "line.h"

class Environment : public QGraphicsScene {
Q_OBJECT
public:
    Environment();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    void keyPressEvent(QKeyEvent * event);
    void update();
public slots:
    void addAND();
    void addNAND();
    void addOR();
    void addNOT();
    void addNode();
    void addLine();
    void viewHelp();
    void viewMain();
    void updateEnvironment();
private:
    QPushButton * buttonAND;
    QPushButton * buttonNAND;
    QPushButton * buttonOR;
    QPushButton * buttonNOT;
    QPushButton * buttonNode;
    QPushButton * buttonLine;
    QPushButton * buttonHelp;
    QPushButton * buttonMainview;

    QList <Node *> * nodes;
    QList <Gate *> * gates;
    QList <Line *> * lines;

    bool connectingEnable;
    QGraphicsTextItem * connectingEnableText;
    unsigned int lineConnecting;
    Line * lineToConnect;
    QGraphicsTextItem * selectSource;
    QGraphicsTextItem * selectEnd;

    QTimer * updateTimer;

    QRectF mainView;
    QRectF helpView;

    QGraphicsTextItem * helpText1;
    QGraphicsTextItem * helpText2;
    QGraphicsTextItem * helpText3;
};


#endif // ENVIRONMENT_H
