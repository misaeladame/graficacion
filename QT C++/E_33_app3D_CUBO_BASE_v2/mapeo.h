#ifndef MAPEO_H
#define MAPEO_H
#include <math.h>

class Mapeo
{
//LOS ATRIBUTOS SE DECLARARON COMO PRIVADOS
    //Mundo Real, SE PUEDEN UTILIZAR LA UNIDADES DE MEDIDA
                  //QUE SE DESEEN
    float XWmin,YWmin, XWmax, YWmax;//VENTANA
    int XPVmin, YPVmin, XPVmax, YPVmax; //Puerto de Visión

public:
    //REPRESENTAN LOS EXTREMOS DEL AREA DE DONDE PROVIENE
    //LO QUE SE VA A DIBUJAR (MUNDO REAL)
    void ventana(float WX1, float WY1, float WX2, float WY2);

    //REPRESENTAN LAS COORDENADAS DEL ÁREA DONDE SE VA
    //A DIBUJAR EN LA PANTALLA DEL DISPOSITIVO
    void puerto(int PVX1, int PVY1, int PVX2, int PVY2);
                                        //L y M representan el origen
    void mapear(int X, int Y, int &XT, int &YT, int L, int M);
                             //& = referencia o dir. de memoria de la variable


};

#endif // MAPEO_H
