#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

//CREAR PROYECTO EMPTY, OTHER PROJECT


#include "rectangulo_1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

     Rectangulo_1 *rect = new Rectangulo_1(400,400);
    rect->setRect(0,0,50,50);
    //ASIGNAR EL ENFOQUE AL OBJETO RECT
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    rect->setFocus();
    //Agregar el Rect_item a la escena
    scene->addItem(rect);
    //Agregar una vista
    QGraphicsView *view = new QGraphicsView(scene);
    view->resize(400,400);

    //EVITAR QUE LA VENTANA SE ESTE REDIMENSIONADO
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  //  view->setFixedSize(400,400);
  //  scene->setSceneRect(0,0,400,400);

    view->show();
    return a.exec();
}
