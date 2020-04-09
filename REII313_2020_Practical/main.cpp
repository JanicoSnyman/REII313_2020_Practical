#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "environment.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Environment window;
    mainWindow view(&window);
    view.show();

    //view.mapToScene(view.viewport()->geometry()).boundingRect();

    return a.exec();
}
