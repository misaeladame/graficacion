#ifndef PUNTO_H
#define PUNTO_H
// DEFINICION DE LA CLASE

#include <math.h>
class Punto
{ // POR DEFAULT SON PRIVADOS TODO LO DECLARADO HASTA QUE SE COLOQUE ALGUN MODIFICADOR COMO:
    // public o protected, DESPUES SE PUEDE VOLVER A USAR
    int x;
    int y;
public:
    // metodo inline
    Punto() {
                x = y = 1; //PROPAGACION DE VALORES
            }
    //METODO CON ARGUMENTOS POR DEFAULT
    Punto(int x = 1, int y = 1);
    Punto(Punto &p);//CONSTRUCTOR DE COPIA
        // PASAMOS LA REFERENCIA    &
    double calcularDist(Punto pf);// USO DEL OBJETO BLANCO
    int getX() {
                   return x;
               }
    // this ES EL PUNTERO AUTOREFERENCIADO
    // LOS PUNTEROS ( * ) EN C++ SE ACCDEDEN CON EL OPERADOR -> (FLECHA)
    void setX(int x){
                        this->x = x;
                    } // metodo inline
    int getY();
    void setY(int y);

};

#endif // PUNTO_H
