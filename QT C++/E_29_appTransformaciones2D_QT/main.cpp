//#include <QCoreApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "rectanguloitem.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication app(argc, argv);

    // PRIMERO CREAMOS LA ESCENA
    QGraphicsScene *scene = new QGraphicsScene();

    rectanguloItem *rectangulo = new rectanguloItem(100, 100);
    // Modificamos los valores del Rectangulo
    rectangulo->setRect(0, 0, 50, 50);
    rectangulo->setFlag(QGraphicsItem::ItemIsFocusable);

    rectangulo->setFocus();
    scene->addItem(rectangulo);

    //Definimos la vista
    QGraphicsView *vista = new QGraphicsView(scene);

    //Definimos las dimensiones de la vista o ventana
    vista->resize(500, 500);

    //PARA EVITAR QUE SE REDIMENSIONES
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vista->show();

    return app.exec();
}
