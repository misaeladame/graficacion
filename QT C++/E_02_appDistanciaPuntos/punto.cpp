#include "punto.h"
// IMPLEMENTACION DE LA CLASE
Punto::Punto(int x, int y)
{
    this->x = x;
    this->y = y;
}
Punto::Punto(Punto &p)
{
    x = p.x;
    y = p.y;
}
double Punto::calcularDist(Punto pf)
{
    //RECIBE DE FORMA IMPLICITA EL PRIMER PUNTO (pi)
    // SE UTILIZA EL OBJETO BLANCO

    double dist;        //x2 - x1
    dist = sqrt(pow(pf.x - this->x, 2)+ pow(pf.y - this->y, 2.0));
    return dist;

    // return sqrt(pow(pf.x - x, 2.0)+ pow(pf.y - this->y, 2.0));

}
int Punto::getY()
{
    return y;
}
void Punto::setY(int y)
{
    this->y = y;
}
