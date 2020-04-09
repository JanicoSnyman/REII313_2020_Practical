#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QResizeEvent>
#include "environment.h"

class mainWindow : public QGraphicsView{
public:
    //mainWindow();
protected:
    void resizeEvent(QResizeEvent *);
private:
    Environment * window;
};

#endif // MAINWINDOW_H
