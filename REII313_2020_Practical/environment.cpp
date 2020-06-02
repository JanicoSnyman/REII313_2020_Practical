#include "environment.h"

//gasdfhbsdjvbijsrbgedw
/********  ********/
Environment::Environment() {
    /******** Initialize variables ********/
    this->nodes = new QList<Node *>;
    this->gates = new QList<Gate *>;
    this->lines = new QList<Line *>;
    lineConnecting = 0;

    /******** Setup update timer for environment ********/
    this->updateTimer = new QTimer(this);
    connect(this->updateTimer, SIGNAL(timeout()), this, SLOT(updateEnvironment()));
    this->updateTimer->start(50);

    /******** Setup push buttons ********/
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
}

void Environment::update() {
    /******** Update entire scene ********/
    this->QGraphicsScene::update();
    /******** Update lines ********/
    int i;
    for(i = 0; i < this->lines->length(); i++) {
        Line * item = this->lines->operator[](i);
        item->update();
    }
    for(i = 0; i < this->gates->length(); i++) {
        Gate * item = this->gates->operator[](i);
        item->updateGate();
    }
}

void Environment::updateEnvironment() {
    this->update();
}

void Environment::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event) {
    int i;
    /******** Handle double click for scene nodes ********/
    if(!this->nodes->isEmpty()){
        for(i = 0; i < this->nodes->length(); i++) {
            Node * item = this->nodes->operator[](i);
            if(item->isUnderMouse() && lineConnecting == 0) {
                item->level = item->level != 1;
            } else if(item->isUnderMouse() && lineConnecting == 1) {
                lineToConnect->sourceNode = item;
                lineConnecting = 2;
            } else if(item->isUnderMouse() && lineConnecting == 2) {
                lineToConnect->endNode = item;
                lineConnecting = 0;
            }
        }
    }

    if(!this->gates->isEmpty()) {
        for(i = 0; i < this->gates->length(); i++) {
            Gate * item = this->gates->operator[](i);
            int j;
            if(!item->inputs->isEmpty()) {
                for(j = 0; j < item->inputs->length(); j++) {
                    Node * inputNode = item->inputs->operator[](j);
                    if(inputNode->isUnderMouse() && lineConnecting == 1) {
                        lineToConnect->sourceNode = inputNode;
                        lineConnecting = 2;
                    } else if(inputNode->isUnderMouse() && lineConnecting == 2) {
                        lineToConnect->endNode = inputNode;
                        lineConnecting = 0;
                    }
                }
            }
            if(!item->outputs->isEmpty()) {
                for(j = 0; j < item->outputs->length(); j++) {
                    Node * outputNode = item->outputs->operator[](j);
                    if(outputNode->isUnderMouse() && lineConnecting == 1) {
                        lineToConnect->sourceNode = outputNode;
                        lineConnecting = 2;
                    } else if(outputNode->isUnderMouse() && lineConnecting == 2) {
                        lineToConnect->endNode = outputNode;
                        lineConnecting = 0;
                    }
                }
            }
        }
    }

    /******** Handle double click for lines ********/
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
}

void Environment::addOR() {
    qDebug() << "add Or";
}

void Environment::addNOT() {
    Gate * newGate = new GateNOT();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);
    qDebug() << this->gates->first()->inputs->first()->scenePos();
    qDebug() << this->gates->first()->scenePos();
    qDebug() << "add Not";
}

void Environment::addNode() {
    Node * newNode = new Node(200, 200);
    newNode->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newNode);
    this->nodes->push_back(newNode);

    qDebug() << "add Node";
}

void Environment::addLine() {
    Line * newLine = new Line();
    this->addItem(newLine);
    this->lines->push_back(newLine);
    qDebug() << "add Line";
}
