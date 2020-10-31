//#include <QCoreApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "rectangulo_item.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication app(argc, argv);

    //PRIMERO CREAMOS LA ESCENA
    QGraphicsScene *scene = new QGraphicsScene();
    rectangulo_Item *rectangulo = new rectangulo_Item(100, 100);

    //MODIFICAMOS LOS VALORES DEL RECTÁNGULO
    rectangulo -> setRect(0, 0, 50, 50);
    rectangulo -> setFlag(QGraphicsItem::ItemIsFocusable);
    rectangulo->setFlag(QGraphicsItem::ItemIsMovable); //mover con el mouse

    rectangulo -> setFocus();
    scene -> addItem(rectangulo);

    //DEFINIMOS LA VISTA
    QGraphicsView *vista = new QGraphicsView(scene);
    //DEFINIMOS LAS DIMENSIONES DE LA VISTA O VENTANA
    vista -> resize(500, 500);

    //PARA EVITAR QUE SE REDIMENSIONE
    vista -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->show();

    return app.exec();
}
