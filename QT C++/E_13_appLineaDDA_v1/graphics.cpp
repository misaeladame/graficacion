#include "graphics.h"

graphics::graphics()
{

}

// VAYAN LEYENDO LO RELACIONADO A git y github
void graphics::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas)
{
    int pasos;// steps, cantidad de pixeles a dibujar
        int dx = x2 - x1;
        int dy = y2 - y1;
        float x_inc, y_inc, x = x1, y = y1;

        if(abs(dx) > abs(dy))
            pasos = abs(dx);
        else
            pasos = abs(dy);

        // aplicar en ambos el cast

        x_inc = float(dx)/pasos;
        y_inc = float(dy)/(float)pasos;
        // Primer punto de la línea

        canvas->setPen(QColor(0,0,200));//grand()%155+100));
        //dibujamos el

        // canvas->drawPoint(floor(x+.5), floor(y+0.5));
        //floor(9.1) = 9,   floor(9.9) = 9
        //ceil(9.1) = 10,  ceil(9.9) = 10
            //implementar qround(5,5) =
        canvas->drawPoint(round(x), round(y));

        for(int k = 0; k<= pasos; k++)
        {
            x = x + x_inc;
            y = y + y_inc;
            canvas->drawPoint(round(x), qRound(y));
        }
}

void graphics::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color)
{
    int pasos;// steps, cantidad de pixeles a dibujar
        int dx = x2 - x1;
        int dy = y2 - y1;
        float x_inc, y_inc, x = x1, y = y1;

        if(abs(dx) > abs(dy))
            pasos = abs(dx);
        else
            pasos = abs(dy);

        // aplicar en ambos el cast

        x_inc = float(dx)/pasos;
        y_inc = float(dy)/(float)pasos;
        // Primer punto de la línea

        canvas->setPen(color);//grand()%155+100));
        //dibujamos el

        // canvas->drawPoint(floor(x+.5), floor(y+0.5));
        //floor(9.1) = 9,   floor(9.9) = 9
        //ceil(9.1) = 10,  ceil(9.9) = 10
            //implementar qround(5,5) =
        canvas->drawPoint(round(x), round(y));

        for(int k = 0; k<= pasos; k++)
        {
            x = x + x_inc;
            y = y + y_inc;
            canvas->drawPoint(round(x), qRound(y));
        }
}
