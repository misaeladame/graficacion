#include "mapeo.h"

void Mapeo::ventana(float WX1, float WY1, float WX2, float WY2)
{
    XWmin = WX1;
    YWmin = WY1;
    XWmax = WX2;
    YWmax = WY2;
}

void Mapeo::puerto(int PVX1, int PVY1, int PVX2, int PVY2)
{
    XPVmin = PVX1;
    YPVmin = PVY1;
    XPVmax = PVX2;
    YPVmax = PVY2;
}

                        // XT = XTRANSFORMADA Y YT = YTRANSFORMADA
void Mapeo::mapear(int X, int Y, int &XT, int &YT, int L, int M)
{
    float sX, sY;
    sX = ( XPVmax - XPVmin) / (XWmax - XWmin); // ESCALA EN X
    sY = ( YPVmax - YPVmin) / (YWmax - YWmin); // ESCALA EN Y
    // ESTAS VARIABLES REGRESAN SU VALOR POR REFERENCIA &
    XT = floor((sX*(X-XWmin)+XPVmin+L)+0.5);
      // USAR redondear o round
    YT = floor((sY*(YWmin-Y)-YPVmin+M)+0.5);
}
