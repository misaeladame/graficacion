#include "rectangulo_item.h"
#include <QKeyEvent>
#include <math.h>

rectangulo_Item::rectangulo_Item(QObject *parent) : QObject(parent)
{

}

rectangulo_Item::rectangulo_Item(int ancho, int alto)
{
    this -> ancho = ancho;
    this -> alto = alto;

    Tx = Ty = 0;
    Sx = Sy = 1.0;
    angulo = 0.0;
}

/*void rectangulo_Item::keyPressEvent(QKeyEvent *event)
{
    if(event -> key() == Qt::Key_Left)
    {
        setPos(this -> x() - 10, this -> y());
    }

    if(event -> key() == Qt::Key_Right)
    {
        setPos(this -> x() + 10, this -> y());
    }

    if(event -> key() == Qt::Key_Up)
    {
        setPos(this -> x(), this -> y() - 10);
    }

    if(event -> key() == Qt::Key_Down)
    {
        setPos(this -> x(), this -> y() + 10);
    }
}*/
//Utilizar las matrices de tranformacion 2D que provee el compilador de qt
void rectangulo_Item::keyPressEvent(QKeyEvent *event){

    //Traslacion
    if(event->key()==Qt::Key_Left){
        Tx-=10;
    }
    if(event->key()==Qt::Key_Right){
        Tx+=10;
    }
    if(event->key()==Qt::Key_Up){
        Ty-=10;
    }
    if(event->key()==Qt::Key_Down){
        Ty+=10;
    }
    Traslacion->setMatrix(1,0,0,
                          0,1,0,
                          Tx,Ty,1);
    this->setTransform(*Traslacion);

}
