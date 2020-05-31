#include "environment.h"

Environment::Environment() {
    this->nodes = new QList<Node *>;

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

    this->addRect(0, 0, sceneWidth, taskbar);
    //this->addRect(padding + 2*taskbar, padding, taskbar - 2*padding, taskbar - 2*padding);
    //this->addRect(padding + 3*taskbar, padding, taskbar - 2*padding, taskbar - 2*padding);
}

void Environment::addAND() {
    qDebug() << "add And";

    //this.newgate = new gateAnd();
    //this.setflag(QGraphicsItem::ItemIsMovable);
}

void Environment::addOR() {
    qDebug() << "add Or";
}

void Environment::addNOT() {
    qDebug() << "add Not";
}

void Environment::addNode() {
    Node * newNode = new Node();
    newNode->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newNode);
    this->nodes->push_back(newNode);

    qDebug() << "add Node";
}
