#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "environment.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Environment scene;
    scene.setSceneRect(0, 0, sceneWidth, sceneHeight);
    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
