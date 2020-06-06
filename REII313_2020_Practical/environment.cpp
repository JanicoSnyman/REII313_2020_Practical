#include "environment.h"

/********  ********/
Environment::Environment() {
    /******** Initialize variables ********/
    this->nodes = new QList<Node *>;
    this->gates = new QList<Gate *>;
    this->lines = new QList<Line *>;
    connectingEnable = false;
    lineConnecting = 0;
    deletionEnable = false;
    nodeClockEnable = false;

    mainView = QRectF(0, 0, sceneWidth, sceneHeight);
    helpView = QRectF(0, sceneHeight, sceneWidth, sceneHeight);

    /******** Setup update timers for environment ********/
    this->updateTimer = new QTimer(this);
    connect(this->updateTimer, SIGNAL(timeout()), this, SLOT(updateEnvironment()));
    this->updateTimer->start(50);

    this->nodeClock = new QTimer(this);
    connect(this->nodeClock, SIGNAL(timeout()), this, SLOT(clockTimeout()));
    this->nodeClock->start(nodeClockspeed);

    /******** Setup push buttons ********/
    this->buttonAND = new QPushButton();
    this->buttonAND->setGeometry(padding + 4*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonAND->setText("AND");
    this->addWidget(this->buttonAND);
    connect(this->buttonAND, SIGNAL(clicked()), this, SLOT(addAND()));

    this->buttonNAND = new QPushButton();
    this->buttonNAND->setGeometry(padding + 6*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonNAND->setText("NAND");
    this->addWidget(this->buttonNAND);
    connect(this->buttonNAND, SIGNAL(clicked()), this, SLOT(addNAND()));

    this->buttonOR = new QPushButton();
    this->buttonOR->setGeometry(padding + 8*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonOR->setText("OR");
    this->addWidget(this->buttonOR);
    connect(this->buttonOR, SIGNAL(clicked()), this, SLOT(addOR()));

    this->buttonNOT = new QPushButton();
    this->buttonNOT->setGeometry(padding + 10*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonNOT->setText("NOT");
    this->addWidget(this->buttonNOT);
    connect(this->buttonNOT, SIGNAL(clicked()), this, SLOT(addNOT()));

    this->buttonNode = new QPushButton();
    this->buttonNode->setGeometry(padding, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonNode->setText("Node");
    this->addWidget(this->buttonNode);
    connect(this->buttonNode, SIGNAL(clicked()), this, SLOT(addNode()));

    this->buttonLine = new QPushButton();
    this->buttonLine->setGeometry(padding + 2*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonLine->setText("Line");
    this->addWidget(this->buttonLine);
    connect(this->buttonLine, SIGNAL(clicked()), this, SLOT(addLine()));

    this->buttonHelp = new QPushButton();
    this->buttonHelp->setGeometry(sceneWidth - 2*taskbar + padding, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonHelp->setText("Help");
    this->addWidget(this->buttonHelp);
    connect(this->buttonHelp, SIGNAL(clicked()), this, SLOT(viewHelp()));

    this->buttonMainview = new QPushButton();
    this->buttonMainview->setGeometry(padding, sceneHeight + padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonMainview->setText("Return");
    this->addWidget(this->buttonMainview);
    connect(this->buttonMainview, SIGNAL(clicked()), this, SLOT(viewMain()));
    ///////////////////
    this->buttonNOR = new QPushButton();
    this->buttonNOR->setGeometry(padding + 12*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonNOR->setText("NOR");
    this->addWidget(this->buttonNOR);
    connect(this->buttonNOR, SIGNAL(clicked()), this, SLOT(addNOR()));

    this->buttonXOR = new QPushButton();
    this->buttonXOR->setGeometry(padding + 14*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonXOR->setText("XOR");
    this->addWidget(this->buttonXOR);
    connect(this->buttonXOR, SIGNAL(clicked()), this, SLOT(addXOR()));

    this->buttonXNOR = new QPushButton();
    this->buttonXNOR->setGeometry(padding + 16*taskbar, padding, 2*taskbar - 2*padding, taskbar - 2*padding);
    this->buttonXNOR->setText("XNOR");
    this->addWidget(this->buttonXNOR);
    connect(this->buttonXNOR, SIGNAL(clicked()), this, SLOT(addXNOR()));

    this->addRect(0, 0, sceneWidth, taskbar);

    /******** Add text promts for line connection steps ********/
    this->selectSource = new QGraphicsTextItem("Line selected, double click first node to connect.");
    this->selectSource->setX(sceneWidth - 250);
    this->selectSource->setY(taskbar + 10);
    this->addItem(this->selectSource);
    this->selectSource->hide();

    this->selectEnd = new QGraphicsTextItem("Source selected, double click second node to connect.");
    this->selectEnd->setX(sceneWidth - 270);
    this->selectEnd->setY(taskbar + 10);
    this->addItem(this->selectEnd);
    this->selectEnd->hide();

    this->connectingEnableText = new QGraphicsTextItem("Line connecting enabled, double click line to select");
    this->connectingEnableText->setX(sceneWidth - 300);
    this->connectingEnableText->setY(taskbar + 10);
    this->addItem(this->connectingEnableText);
    this->connectingEnableText->hide();

    /******** Add text to indicate state of node clock mode ********/
    this->nodeClockText = new QGraphicsTextItem("Node clock toggle enabled, double click node to toggle it");
    this->nodeClockText->setX(sceneWidth - 300);
    this->nodeClockText->setY(taskbar + 10);
    this->addItem(this->nodeClockText);
    this->nodeClockText->hide();

    /******** Add text to indicate state of deletion mode ********/
    this->deletionEnableText = new QGraphicsTextItem("Deletion enabled, double click object to delete it");
    this->deletionEnableText->setX(sceneWidth - 270);
    this->deletionEnableText->setY(taskbar + 10);
    this->addItem(this->deletionEnableText);
    this->deletionEnableText->hide();

    /******** Add help text to help view ********/
    this->helpText1 = new QGraphicsTextItem("Double click on an individual node to toggle its level");
    this->helpText1->setX(padding);
    this->helpText1->setY(sceneHeight + taskbar);
    this->helpText1->setScale(1.5);
    this->addItem(this->helpText1);

    this->helpText2 = new QGraphicsTextItem("Press the \"C\" button to enable the connecting of lines to nodes");
    this->helpText2->setX(padding);
    this->helpText2->setY(sceneHeight + 2*taskbar);
    this->helpText2->setScale(1.5);
    this->addItem(this->helpText2);

    this->helpText3 = new QGraphicsTextItem("Press the \"Delete\" button to enable the deletion of objects");
    this->helpText3->setX(padding);
    this->helpText3->setY(sceneHeight + 3*taskbar);
    this->helpText3->setScale(1.5);
    this->addItem(this->helpText3);

    this->helpText4 = new QGraphicsTextItem("Press the \"X\" button to enable the toggling of node clocks on nodes");
    this->helpText4->setX(padding);
    this->helpText4->setY(sceneHeight + 4*taskbar);
    this->helpText4->setScale(1.5);
    this->addItem(this->helpText4);
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

void Environment::clockTimeout() {
    if(!this->nodes->isEmpty()){
        int i;
        for(i = 0; i < this->nodes->length(); i++) {
            Node * item = this->nodes->operator[](i);
            if(item->clocked) {
                item->level = item->level != 1;
            }
        }
    }
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
                this->selectSource->hide();
                this->selectEnd->show();
            } else if(item->isUnderMouse() && lineConnecting == 2) {
                lineToConnect->endNode = item;
                lineToConnect->selected = false;
                lineToConnect = nullptr;
                lineConnecting = 0;
                this->selectEnd->hide();
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
                        this->selectSource->hide();
                        this->selectEnd->show();
                    } else if(inputNode->isUnderMouse() && lineConnecting == 2) {
                        lineToConnect->endNode = inputNode;
                        lineToConnect->selected = false;
                        lineConnecting = 0;
                        this->selectEnd->hide();
                    }
                }
            }
            if(!item->outputs->isEmpty()) {
                for(j = 0; j < item->outputs->length(); j++) {
                    Node * outputNode = item->outputs->operator[](j);
                    if(outputNode->isUnderMouse() && lineConnecting == 1) {
                        lineToConnect->sourceNode = outputNode;
                        lineConnecting = 2;
                        this->selectSource->hide();
                        this->selectEnd->show();
                    } else if(outputNode->isUnderMouse() && lineConnecting == 2) {
                        lineToConnect->endNode = outputNode;
                        lineToConnect->selected = false;
                        lineConnecting = 0;
                        this->selectEnd->hide();
                    }
                }
            }
        }
    }

    /******** Handle double click for lines ********/
    if(!this->lines->isEmpty()) {
        for(i = 0; i < this->lines->length(); i++) {
            Line * item = this->lines->operator[](i);
            if(item->isUnderMouse() && lineConnecting  == 0 && connectingEnable) {
                lineToConnect = item;
                lineToConnect->selected = true;
                lineConnecting = 1;
                this->selectSource->show();
                this->connectingEnableText->hide();
                connectingEnable = false;
            }
        }
    }


    /******** Handle node clock events ********/
    if(nodeClockEnable) {
        if(!this->nodes->isEmpty()){
            for(i = 0; i < this->nodes->length(); i++) {
                Node * item = this->nodes->operator[](i);
                if(item->isUnderMouse()) {
                    item->clocked = item->clocked != 1;
                }
            }
        }
    }




    /******** Handle deletion events ********/
    if(deletionEnable) {
        /******** Deletion of lines ********/
        if(!this->lines->isEmpty()) {
            for(i = 0; i < this->lines->length(); i++) {
                Line * item = this->lines->operator[](i);
                if(item->isUnderMouse()) {
                    item->sourceNode = nullptr;
                    item->endNode = nullptr;
                    //this->removeItem(item);
                    this->lines->removeAt(i);
                    item->hide();
                }
            }
        }

        /******** Deletion of nodes ********/
        if(!this->nodes->isEmpty()){
            for(i = 0; i < this->nodes->length(); i++) {
                Node * item = this->nodes->operator[](i);
                if(item->isUnderMouse()) {
                    /******** Clear all connections to this node from lines in scene ********/
                    if(!this->lines->isEmpty()) {
                        int j;
                        for(j = 0; j < this->lines->length(); j++) {
                            Line * line = this->lines->operator[](j);
                            if(line->sourceNode == item) {
                                line->sourceNode = nullptr;
                            }
                            if(line->endNode == item) {
                                line->endNode = nullptr;
                            }
                        }
                    }
                    this->removeItem(item);
                    this->nodes->removeAt(i);
                    delete item;
                }
            }
        }

        /******** Deletion of gates ********/
        if(!this->gates->isEmpty()) {
            for(i = 0; i < this->gates->length(); i++) {
                Gate * item = this->gates->operator[](i);
                if(item->isUnderMouse()) {
                    int j;
                    /******** Clear connections to input nodes ********/
                    if(!item->inputs->isEmpty()) {
                        for(j = 0; j < item->inputs->length(); j++) {
                            Node * inputNode = item->inputs->operator[](j);
                            int k;
                            for(k = 0; k < this->lines->length(); k++) {
                                Line * line = this->lines->operator[](k);
                                if(line->sourceNode == inputNode) {
                                    line->sourceNode = nullptr;
                                }
                                if(line->endNode == inputNode) {
                                    line->endNode = nullptr;
                                }
                            }
                        }
                    }
                    /******** Clear connections to output nodes ********/
                    if(!item->outputs->isEmpty()) {
                        for(j = 0; j < item->outputs->length(); j++) {
                            Node * outputNode = item->outputs->operator[](j);
                            int k;
                            for(k = 0; k < this->lines->length(); k++) {
                                Line * line = this->lines->operator[](k);
                                if(line->sourceNode == outputNode) {
                                    line->sourceNode = nullptr;
                                }
                                if(line->endNode == outputNode) {
                                    line->endNode = nullptr;
                                }
                            }
                        }
                    }
                    this->removeItem(item);
                    this->gates->removeAt(i);
                    delete item;
                }
            }
        }
    }


    this->update();
    qDebug() << "Double Clicked!!";
}

void Environment::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_C && !deletionEnable && !nodeClockEnable) {
        connectingEnable = connectingEnable != 1;
        if(connectingEnable) {
            this->connectingEnableText->show();
        } else {
            this->connectingEnableText->hide();
        }
    }
    if(event->key() == Qt::Key_Delete && lineConnecting == 0 && !connectingEnable && !nodeClockEnable) {
        deletionEnable = deletionEnable != 1;
        if(deletionEnable) {
            deletionEnableText->show();
        } else {
            deletionEnableText->hide();
        }
    }
    if(event->key() == Qt::Key_X && lineConnecting == 0 && !connectingEnable && !deletionEnable) {
        qDebug() << "Node toggle";
        this->nodeClockEnable = this->nodeClockEnable != 1;
        if(nodeClockEnable) {
            nodeClockText->show();
        } else {
            nodeClockText->hide();
        }
    }
}

void Environment::addAND() {
    Gate * newGate = new GateAND();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);

    qDebug() << "add And";
}

void Environment::addNAND() {
    Gate * newGate = new GateNAND();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);

    qDebug() << "add NAND";
}

void Environment::addOR() {
    Gate * newGate = new GateOR();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);
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

void Environment::addNOR() {
    Gate * newGate = new GateNOR();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);
    qDebug() << "add Nor";
}

void Environment::addXOR() {
    Gate * newGate = new GateXOR();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);
    qDebug() << "add Xor";
}

void Environment::addXNOR() {
    Gate * newGate = new GateXNOR();
    newGate->setFlag(QGraphicsItem::ItemIsMovable, true);
    this->addItem(newGate);
    this->gates->push_back(newGate);
    qDebug() << "add Xnor";
}

void Environment::viewHelp() {
    this->setSceneRect(helpView);
}

void Environment::viewMain() {
    this->setSceneRect(mainView);
}
