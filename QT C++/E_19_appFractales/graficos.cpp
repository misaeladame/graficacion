#include "graficos.h"
#include <QColor>

graficos::graficos()
{

}

void graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color)
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

void graficos::dragon(QPainter *canvas, QColor color)
{
    int i;
    int Paso = 4096;
    int signo = -1;
    int EjeX[4098], EjeY[4098];
    EjeX[1] = canvas->window().width()/4;
    EjeX[4097] = 3 * canvas->window().width()/4;
    EjeY[1] = EjeY[4097] = canvas->window().height()/1.7;

    canvas->setPen(color);
    QFont fuente = canvas->font();
    fuente.setPointSize(fuente.pointSize() * 2);
    //Canvas.setFont(fuente);
    canvas->setFont(QFont("ROCKWELL", 22));
    canvas->drawText(5, 25, "CURVA FRACTAL DEL DRAGON");
    //LINEA HORIZONTAL
    //APLICAR LA LINEA DDA
    canvas->setPen(QColor(255, 255, 255));
    canvas->drawLine(EjeX[1],EjeY[1], EjeX[4097], EjeY[4097]);
    for( i = 1; i <= 11; i++)
    {
        generarDragon(Paso, signo, EjeX, EjeY, canvas, color); //generarDragon(Canvas);
        Paso /= 2; // Paso = Paso / 2;
    }
}

void graficos::generarDragon(int Paso, int signo, int EjeX[4098], int EjeY[4098], QPainter *canvas, QColor color)
{
    int j, dx, dy;
    j = Paso / 2;
    canvas->setPen(color);//qrand()%
                             // signo *= -1;
    for(int i = 1; i <= 4096; i += Paso)
    {
        dx = EjeX[Paso+i] - EjeX[i];
        dy = EjeY[Paso+i] - EjeY[i];

        signo *= -1;
        EjeX[i + j] = EjeX[i] + ( dx + ( dy * signo)) / 2;
        EjeY[i + j] = EjeY[i] + ( dy - ( dx * signo)) / 2;
        //USAR LA LINEA DDA
   //     lineaDDA(EjeX[i], EjeY[i], EjeX[i+j], EjeY[i+j], canvas, color);
   //     lineaDDA(EjeX[i+j], EjeY[i+j], EjeX[i+Paso], EjeY[i+Paso], canvas, color);

        canvas->drawLine(EjeX[i], EjeY[i], EjeX[i+j], EjeY[i+j] );
        canvas->drawLine(EjeX[i+j], EjeY[i+j], EjeX[i+Paso], EjeY[i+Paso]);

    }
}

void graficos::dragonArabesco(QPainter *canvas, QColor color)
{
    int i;
    int Paso = 4096;
    int signo = 1;
    int EjeX[4098], EjeY[4098];
    EjeX[1] = canvas->window().width()/4;
    EjeX[4097] = 3 * canvas->window().width()/4;
    EjeY[1] = EjeY[4097] = canvas->window().height()/1.35;

    canvas->setPen(color);
    QFont fuente = canvas->font();
    fuente.setPointSize(fuente.pointSize() * 2);
    //Canvas.setFont(fuente);
    canvas->setFont(QFont("ROCKWELL", 22));
    canvas->drawText(5, 25, "CURVA FRACTAL DEL ARABESCO");
    //LINEA HORIZONTAL
    //APLICAR LA LINEA DDA
    canvas->setPen(QColor(255, 255, 255));
    canvas->drawLine(EjeX[1],EjeY[1], EjeX[4097], EjeY[4097]);
    for( i = 1; i <= 11; i++)
    {
        generarDragonArabesco(Paso, signo, EjeX, EjeY, canvas, color); //generarDragon(Canvas);
        Paso /= 2; // Paso = Paso / 2;
    }
}

void graficos::generarDragonArabesco(int Paso, int signo, int EjeX[], int EjeY[], QPainter *canvas, QColor color)
{
    int j, dx, dy;
    j = Paso / 2;
    canvas->setPen(color);//qrand()%
                             // signo *= -1;
    for(int i = 1; i <= 4096; i += Paso)
    {
        dx = EjeX[Paso+i] - EjeX[i];
        dy = EjeY[Paso+i] - EjeY[i];

        signo *= 1;
        EjeX[i + j] = EjeX[i] + ( dx + ( dy * signo)) / 2;
        EjeY[i + j] = EjeY[i] + ( dy - ( dx * signo)) / 2;
        //USAR LA LINEA DDA
   //     lineaDDA(EjeX[i], EjeY[i], EjeX[i+j], EjeY[i+j], canvas, color);
   //     lineaDDA(EjeX[i+j], EjeY[i+j], EjeX[i+Paso], EjeY[i+Paso], canvas, color);

        canvas->drawLine(EjeX[i], EjeY[i], EjeX[i+j], EjeY[i+j] );
        canvas->drawLine(EjeX[i+j], EjeY[i+j], EjeX[i+Paso], EjeY[i+Paso]);

    }
}

void graficos::curvaHenon(QPainter *canvas, QColor color)
{
    int maxX = canvas->window().width();
    int maxY = canvas->window().height();
    double EscalaX = 1;
    double EscalaY = 1;
    double DespX = 0;
    double DespY = 0;
    canvas->setPen(color);
    QFont fuente = canvas->font();
    fuente.setPointSize(fuente.pointSize() * 2);
    //Canvas.setFont(fuente);
    canvas->setFont(QFont("ROCKWELL", 22));
    canvas->drawText(5, 25, "CURVA FRACTAL DEL HERON");
    generarCurvaHenon(maxX, maxY, EscalaX, EscalaY, DespX, DespY, canvas, color);


}

void graficos::generarCurvaHenon(int maxX, int maxY, double EscalaX, double EscalaY, double DespX, double DespY, QPainter *canvas, QColor color)
{
    int i, PosX, PosY;
    double Xant, Xnuevo, Yant, Ynuevo;

    //=====================================//
    //       Confinador de Henon           //
    //    x = y + 1 - ( 1.4 * x * x )      //
    //    y = 0.3 * x                      //
    //=====================================//

    Xant = Xnuevo = Yant = Ynuevo = 0;
    canvas->setPen(color);
    for( int c = 1; c <= 15; c++) {
        for ( i = 1;i <= 0x02FF; i++) {
            Xnuevo = Yant + 1 - ( 1.4 * Xant * Xant );
            Ynuevo = 0.3 * Xant;

            PosX = ( Xnuevo * maxX / 3 * EscalaX) +
                    maxX / 2 + DespX;
            PosY = ( Ynuevo * maxY * EscalaY ) +
                    maxY / 2 + DespY;
            if ( ( PosX >= 0 ) && ( PosX <= maxX ) &&
                 ( PosY >= 0 ) && ( PosY <= maxY ) )
                canvas->drawPoint(PosX, PosY);
            Yant = Ynuevo;
            Xant = Xnuevo;
        }
    }
}

void graficos::malthus1(QPainter *canvas, QColor color)
{
    int maxX = canvas->window().width();
    int maxY = canvas->window().height();
    int MaxGen = 0x00FF;

    generarMalthus1(maxX, maxY, MaxGen, canvas);
}

void graficos::generarMalthus1(int maxX, int maxY, int MaxGen, QPainter *canvas)
{
    int i, j, k, l, Contador, Color, X, Y;
    double PobAnt, PobNueva, Razon;
    PobNueva = 0.0;
    Razon = 2.3;
    Color = 0x000000;

    for(j = 1; j <= 151; j++) {
        Color++;
        if ( Color >= 0xFFFFFF) Color = 0x0000FF;
        Contador = 0;
        Razon += 0.01;
        PobAnt = 0.01;
        for ( i = 1; i <= MaxGen; i++ ) {
            PobNueva = Razon * ( PobAnt * ( 1 - PobAnt ));
            X = PobAnt * maxX;
            Y = maxY - ( PobNueva * maxY );
            canvas->setPen(Color);
            canvas->drawPoint(X, Y);
            if ( PobAnt == PobNueva ) Contador++;
            else Contador = 0;
            if ( Contador > 10 ) i = MaxGen;

            PobAnt = PobNueva;
        }
    }

}

void graficos::malthus2(QPainter *canvas, QColor color)
{
    int maxX = canvas->window().width();
    int maxY = canvas->window().height();

    generarMalthus2(maxX, maxY, canvas);
}

void graficos::generarMalthus2(int maxX, int maxY, QPainter *canvas)
{
    int i, j, k, l, Color = 0, Contador;
    double PobAnt, PobNueva, X, Y, Razon;

    PobAnt = PobNueva = 0.0;
    Razon = 2.3;
    Y = 0;
    for ( j = 1; j <= 15; j++) {
        Color++;
        if ( Color > 0xFFFFFF ) Color = 0x0000FF;
        for ( k=1; k<=10; k++) {
            Contador = 0;
            Razon = Razon + 0.01;
            PobAnt = 0.01;
            for ( i = 1; i <= 1000; i++ ) {
                PobNueva = Razon * ( PobAnt * ( 1 - PobAnt));
                X = PobNueva - PobAnt;
                canvas->setPen(Color);
                canvas->drawPoint( ( X * maxX / 2 ) + maxX / 2,
                                   ( maxY / 2 ) - ( Y * maxY / 2 ) );
                if ( PobAnt == PobNueva ) Contador++;
                else                      Contador = 0;
                if( Contador > 100 ) i = 100000;
                PobAnt = PobNueva;
                Y = X;
            }
        }
    }
}

void graficos::mandelbrot(QPainter *canvas, QColor color)
{
    int maxX, maxY, Limite, i, j, Pasos, Terminar;
    double PasoX, PasoY, PosX, PosY, OrigX, OrigY,
            DimX, DimY, IterX, IterY, TempX;

    maxX = canvas->window().width();
    maxY = canvas->window().height();
    Limite = 100;

    OrigX = -2.0;
    OrigY = -1.25;
    DimX = 0.5;
    DimY = 1.25;

    PasoX = ( DimX - OrigX ) / maxX;
    PasoY = ( DimY - OrigY ) / maxY;
    for ( i = 0; i < maxX; i++ )
    {
        for( j = 0; j<= maxY; j++)
        {
            PosX = OrigX + i * PasoX;
            PosY = OrigY + j * PasoY;
            IterX = 0.0;

            IterY = 0.0;
            Terminar = Pasos = 0;

            while ( !Terminar ) {
                TempX = ( IterX * IterX ) - ( IterY * IterY ) + PosX;

                IterY = 2 * ( IterX * IterY ) + PosY;
                IterX = TempX;
                Pasos++;
                if ( hypot( fabs(IterX), fabs(IterY ) ) >= 2.0 )
                    Terminar++;
                if ( Pasos >= Limite ) Terminar++;

            }
            if ( Pasos < Limite ) {
                canvas->setPen(Pasos);
                canvas->drawPoint ( i, j );
            }
        }
    }
}



