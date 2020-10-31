#include "graphics.h"

graphics::graphics()
{

}

void graphics::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color)
{
    int pasos;// steps, cantidad de pixeles a dibujar
    int dx = x2 - x1;
    int dy = y2 - y1;
    double x_inc, y_inc, x = x1, y = y1;


    if(abs(dx) > abs(dy))
        pasos = abs(dx);
    else
        pasos = abs(dy);

    // aplicar en ambos el cast
    x_inc = double(dx)/pasos;
    y_inc = double(dy)/double(pasos);

    // Primer punto de la línea
    canvas->setPen(color);// RECIBE EL COLOR
    canvas->drawPoint(round_(x), round_(y));

    for(int k = 0; k<= pasos; k++)
    {
        x = x + x_inc;
        y = y + y_inc;
        canvas->drawPoint(round_(x), round_(y));
    }
}
