#include "rectangulo_1.h"
#include <math.h>

Rectangulo_1::Rectangulo_1(QObject *parent) : QObject(parent)
{

}
Rectangulo_1::Rectangulo_1(int ancho, int alto)
{
    ancho_ = ancho;
    alto_ = alto;

    Tx=Ty=0;
    Sx=Sy=1.0;
    xr = yr = 0;
    //
    angulo = 0.0;

    Traslacion = new QTransform();
    Escalacion = new QTransform();
   //
    Rotacion = new QTransform();
    RotacionPuntoPivote = new QTransform();



}


//TRASLACION UTILIZANDO EL METODO setPos
/*
void Rectangulo_1::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) //flecha izq                               //Key_A)
    {     //Este Rectangulo
        setPos(this->x()-10,y());
    }
    if(event->key() == Qt::Key_Right)//flecha der
    {
       setPos(x()+10,y());

    }
    if(event->key() == Qt::Key_Up)     //flecha arriba
    {
       setPos(x(),y()-10);
    }
    if(event->key() == Qt::Key_Down)     //flecha abajo
    {
       setPos(x(),y()+10);
    }
}
*/

/////



//UTILIZANDO TRANSFORMACIONES
//********
void Rectangulo_1::keyPressEvent(QKeyEvent *event)
{
    //TRASLACION
    if(event->key() == Qt::Key_Left)
    {
        Tx-=10;
       // this->rect().setLeft(x());
    }
    if(event->key() == Qt::Key_Right)
    {
      Tx+=10;
    }
    if(event->key() == Qt::Key_Up)
    {
       Ty-=10;
    }
    if(event->key() == Qt::Key_Down)
    {
        Ty+=10;
    }
    Traslacion->setMatrix(1,0,0,
                          0,1,0,
                          Tx,Ty,1);

     //this->setTransform(*Traslacion);

    // ESCALACION
    if(event->key()==Qt::Key_Z) {
        Sx+=.1;
    }

    if(event->key()==Qt::Key_X) {
        Sx-=.1;
        if(Sx<0) {
            Sx = 0;
        }
    }

    if(event->key()==Qt::Key_C) {
        Sy += .1;
    }

    if(event->key()==Qt::Key_V) {
        Sy-=.1;
        if(Sy<0) {
            Sy = 0;
        }
    }


    Traslacion->setMatrix(Sx,0,0,
                          0,Sy,0,
                          0,0,1);

    //this->setTransform((*Traslacion)*(*Escalacion));

    // ROTACION

    if(event->key() == Qt::Key_R) {
        angulo += 5.0;
    }

    if(event->key() == Qt::Key_E) {
        angulo -= 5.0;
    }

    double radianes = angulo * M_PI / 180.0;
    double seno = sin(radianes);
    double coseno = cos(radianes);

    Rotacion->setMatrix(coseno, seno, 0,
                        -seno, coseno, 0,
                           0,      0,   1);

    //this->setTransform(*Rotacion);

    //PROBAR UTILIZANDO LAS TRES TRANSFORMACIONES
    // ROTACION DEL PUNTO PIVOTE
    // 1ero. TRASLADAR AL ORIGEN EL PUNTO PIVOTE
    // 2do. APLICAR LA MATRIZ DE ROTACION
    // 3ro. Trasladar a su posición original



// MANERA 1
    /*
    if(event->key() == Qt::Key_O) {
        xr += 1;
    }

    if(event->key() == Qt::Key_P) {
        yr -= 1;
    }
    */

    // Manera 2

    /*
    double op1 = xr * ( 1 - coseno ) + yr * seno;
    double op2 = yr * ( 1 - coseno ) - xr * seno;

    RotacionPuntoPivote->setMatrix(coseno, seno, 0,
                                   -seno, coseno, 0,
                                   op1, op2, 1);
    */

    //this->setTransform(*RotacionPuntoPivote);

    /*
    Transformacion1->setMatrix(1, 0, 0,
                        0, 1, 0,
                        -xr, -yr, 1);

    Transformacion3->setMatrix(1, 0, 0,
                        0, 1, 0,
                        xr, yr, 1);


    this->setTransform((*Transformacion1)*(*Rotacion)*(*Transformacion3));
  */

// MANERA DEL INGE

    // objetos estaticos
    QTransform traslacionNeg(1, 0, 0,
                             0, 1, 0,
    -((this->rect().width()/2) + 100), -((this->rect().width()/2) + 100));


    QTransform traslacionPos(1, 0, 0,
                             0, 1, 0,
    ((this->rect().width()/2) + 100), ((this->rect().width()/2) + 100));

    this->setTransform(traslacionNeg * (*Rotacion) * traslacionPos);
}
