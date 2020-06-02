#include "environment.h"

Environment::Environment() {
    this->nodes = new QList<Node *>;
    this->gates = new QList<Gate *>;
    this->lines = new QList<Line *>;
    lineConnecting = 0;

    this->buttonAND = new QPushButton();
    this->buttonAND->setGeometry(padding, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonAND->setText("AND");
    this->addWidget(this->buttonAND);
    connect(this->buttonAND, SIGNAL(clicked()), this, SLOT(addAND()));

    this->buttonOR = new QPushButton();
    this->buttonOR->setGeometry(padding + 2*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonOR->setText("OR");
    this->addWidget(this->buttonOR);
    connect(this->buttonOR, SIGNAL(clicked()), this, SLOT(addOR()));

    this->buttonNOT = new QPushButton();
    this->buttonNOT->setGeometry(padding + 4*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonNOT->setText("NOT");
    this->addWidget(this->buttonNOT);
    connect(this->buttonNOT, SIGNAL(clicked()), this, SLOT(addNOT()));

    this->buttonNode = new QPushButton();
    this->buttonNode->setGeometry(padding + 6*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonNode->setText("Node");
    this->addWidget(this->buttonNode);
    connect(this->buttonNode, SIGNAL(clicked()), this, SLOT(addNode()));

    this->buttonLine = new QPushButton();
    this->buttonLine->setGeometry(padding + 8*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonLine->setText("Line");
    this->addWidget(this->buttonLine);
    connect(this->buttonLine, SIGNAL(clicked()), this, SLOT(addLine()));

    this->addRect(0, 0, sceneWidth, taskbar);
    //this->addRect(padding + 2*taskbar, padding, taskbar - 2*padding, taskbar - 2*padding);
    //this->addRect(padding + 3*taskbar, padding, taskbar - 2*padding, taskbar - 2*padding);
}

void Environment::update() {
    this->QGraphicsScene::update();
    int i;
    for(i = 0; i < this->lines->length(); i++) {
        Line * item = this->lines->operator[](i);
        item->update();
    }
}

void Environment::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event) {
    int i;
    if(!this->nodes->isEmpty()){
        for(i = 0; i < this->nodes->length(); i++) {
            Node * item = this->nodes->operator[](i);
            if(item->isUnderMouse() && lineConnecting == 0) {
                item->level = item->level != 1;
            } else if(item->isUnderMouse() && lineConnecting == 1) {
                lineToConnect->sourceNode = item;
                lineToConnect->sourcePoint = QPointF(item->scenePos().x() + 200, item->scenePos().y() + 200);
                lineConnecting = 2;
            } else if(item->isUnderMouse() && lineConnecting == 2) {
                lineToConnect->endNode = item;
                lineToConnect->endPoint = QPointF(item->scenePos().x() + 200, item->scenePos().y() + 200);
                lineConnecting = 0;
            }
        }
    }
    if(!this->lines->isEmpty()) {
        for(i = 0; i < this->lines->length(); i++) {
            Line * item = this->lines->operator[](i);
            if(item->isUnderMouse() && lineConnecting  == 0) {
                lineToConnect = item;
                lineConnecting = 1;
            }
        }
    }

    this->update();
    qDebug() << "Double Clicked!!";
}

void Environment::addAND() {
    Gate * newGate = new GateAND();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);

    qDebug() << "add And";
    this->update();
    //this.newgate = new gateAnd();
    //this.setflag(QGraphicsItem::ItemIsMovable);
}

void Environment::addOR() {
    qDebug() << "add Or";
    this->update();
}

void Environment::addNOT() {
    Gate * newGate = new GateNOT();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);
    qDebug() << this->gates->first()->inputs->first()->scenePos();
    qDebug() << this->gates->first()->scenePos();
    qDebug() << "add Not";
    this->update();
}

void Environment::addNode() {
    Node * newNode = new Node(200, 200);
    newNode->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newNode);
    this->nodes->push_back(newNode);

    qDebug() << "add Node";
    this->update();
}

void Environment::addLine() {
    Line * newLine = new Line();
    this->addItem(newLine);
    this->lines->push_back(newLine);
    qDebug() << "add Line";
    this->update();
}
