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

void graphics::circuloPitagoras(int xc, int yc, int radio, QPainter *canvas)
{
    double x = xc - radio, y1 = 0, y2 = 0;

    while(x <= xc+radio)
    {
        y1 = yc + sqrt(pow(radio, 2) - pow(x-xc,2));
        y2 = yc - sqrt(pow(radio, 2) - pow(x-xc,2));
        canvas->drawPoint(round_(x),round_(y1));
        canvas->drawPoint(round_(x),round_(y2));
        x++;
    }
}

void graphics::circuloPolares(int xc, int yc, int radio, QPainter *canvas)
{
    canvas->setPen(QColor(0, 0, 200));//qrand()%155+100));
    double dth, cdth, sdth, x, y, xt;
    dth = 1.0/radio;
    cdth = cos(dth);
    sdth = sin(dth);
    x = 0;
    y = radio;
    while ( y >= x)
    {
        canvas->drawPoint(round_(xc + x), round_(yc + y));//1er Cuadrante
        canvas->drawPoint(round_(xc - x), round_(yc + y));//2do Cuadrante
        canvas->drawPoint(round_(xc - x), round_(yc - y));//3er Cuadrante
        canvas->drawPoint(round_(xc + x), round_(yc - y));//4to Cuadrante
        xt = x;
        x = xt * cdth - y * sdth;
        y = y * cdth + xt * sdth;
    }
}

void graphics::circulo(int xc, int yc, int radio, QPainter *canvas)
{
    QPen pluma(QColor(0,0,200)); // = new QPen(QColor(0,0,200));
    // pluma.setWidth(8);
    // canvas->setPen(QColor(0, 0));//qrand()%155+100));
    double x, y;
    for(int grados = 0; grados < 360; grados+= 2)
    {       // COMVERTIR EL ANGULO DE GRADOS A RADIANES
        x = xc + radio * cos(grados / 180.0 * M_PI); // INCLUIR <math.h>
        y = yc + radio * sin(grados / 180.0 * M_PI);
        // canvas->drawPoint(x-1,y-1);
        canvas->drawPoint(round_(x),round_(y));
        // canvas->drawPoint(x+1, y+1);
    }
}
