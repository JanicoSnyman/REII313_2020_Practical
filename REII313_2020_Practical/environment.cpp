#include "environment.h"

Environment::Environment() {
    this->addRect(0, 0, sceneWidth, taskbar);
    this->addRect(padding, padding, taskbar - 2*padding, taskbar - 2*padding);
    this->addRect(padding + taskbar, padding, taskbar - 2*padding, taskbar - 2*padding);
    this->addRect(padding + 2*taskbar, padding, taskbar - 2*padding, taskbar - 2*padding);
    this->addRect(padding + 3*taskbar, padding, taskbar - 2*padding, taskbar - 2*padding);
}
