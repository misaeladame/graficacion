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

void graphics::circuloPitagoras(int xc, int yc, int radio, QPainter *canvas, QColor color)
{
    double x = xc - radio, y1 = 0, y2 = 0;
    canvas->setPen(color);
    while(x <= xc+radio)
    {
        y1 = yc + sqrt(pow(radio, 2) - pow(x-xc,2));
        y2 = yc - sqrt(pow(radio, 2) - pow(x-xc,2));
        canvas->drawPoint(round_(x),round_(y1));
        canvas->drawPoint(round_(x),round_(y2));
        x++;
    }
}

void graphics::circuloPolares(int xc, int yc, int radio, QPainter *canvas, QColor color)
{
    canvas->setPen(QColor(color));//qrand()%155+100));
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

void graphics::circulo(int xc, int yc, int radio, QPainter *canvas, QColor color)
{
    canvas->setPen(QColor(color)); // = new QPen(QColor(0,0,200));
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

// AGREGAR LOS CAMBIOS
void graphics::espiral1(double radio, double factor, QPainter *canvas, QColor color)
{//DIBUJAMOS A PARTIR DEL CENTRO DE LA FORMA
    int xc = canvas->window().width()/2;
    int yc = canvas->window().height()/2-70;

    // const double dos_pi = M_PI * 2;
    const double dos_pi = 6.28318; //M_P1_2             
    canvas->setPen(color);
    int cont;
    double dth, cth, sth, x, y, xt, yt, x_tmp;
                 //FACTOR MODIFICAR
    dth = dos_pi/(factor * radio); // 1.7, 2.5, ETC
    // decrementar el FACTOR: 16-8, 4, 2, 1.8
    // FACTOR SE ASIGNARA DESDE LA INTERFAZ
    cth = cos(dth);
    sth = sin(dth);
    x = 0.0;
    y = radio;
    cont = 0;
    xt = xc + x;
    yt = yc + y;
    do {
        x_tmp = x;
        x = (x*cth - y* sth);
        y = (y*cth + x_tmp * sth);
        if(x>0) {
            x+=0.5;
        }
        else { x-=0.5; }
        if(y>0) { y+=0.5; }
        else { y-=0.5; }
        // USAR PUNTOS
        //canvas->drawPoint(xt+.5, round(yt+.5);
        //UTILIZANDO LA LINEADDA
        lineaDDA(round_(xt + .5), round_(yt + .5), round_(xc + x + .5), round_(yc + y + .5), canvas, color);
        xt = xc + x;
        yt = yc + y;
        cont++;
    }while(cont<300);
}//FIN ESPIRAL 1

void graphics::espiral2(double radio, double th, QPainter *canvas, QColor color)
{
    int xc = canvas->window().width()/2,
            yc = canvas->window().height()/2-80;
    canvas->setPen(color);
    double x, y, xt, yt;
    double const rad = radio;
    double const t = th;
    x = radio * cos(th);
    y = radio * sin(th);
    xt = xc + x;
    yt = yc + y;
    while (radio < 230)
    {
        th += t;    // VALORES INICIAL : .1;        // 1.7 ; //UTILZIAR VALORES PROPORCIONALES
        radio += rad;    // VALOR INICIAL : 0.9    //2.5; // USUARIO
        x = radio*cos(th);
        y = radio*sin(th);
        lineaDDA(round_(xt+.5), round_(yt+.5),
                 round_(xc+x+.5), round_(yc+y+.5), canvas, color);
        xt = xc + x;
        yt = yc + y;

    }
}//FIN ESPIRAL 2
