#ifndef GRAFICOS_H
#define GRAFICOS_H
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QColor>

class graficos
{
public:
    // floor y cell
    int round_(double n)
    {
        return int(n+0.5);
    }
    graficos();

    void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color);


    // Dragon
    void dragon(QPainter *canvas, QColor color);
    void generarDragon(int Paso, int signo, int EjeX[4098], int EjeY[4098], QPainter *canvas, QColor color);

    // Dragon arabesco
    void dragonArabesco(QPainter *canvas, QColor color);
    void generarDragonArabesco(int Paso, int signo, int EjeX[4098], int EjeY[4098], QPainter *canvas, QColor color);

    // Curva de Henon
    void curvaHenon(QPainter *canvas, QColor color);
    void generarCurvaHenon(int maxX, int maxY, double EscalaX, double EscalaY, double DespX, double DespY, QPainter *canvas, QColor color);

    // Malthus 1
    void malthus1(QPainter *canvas, QColor color);
    void generarMalthus1(int maxX, int maxY, int MaxGen, QPainter *canvas);

    // Malthus 2
    void malthus2(QPainter *canvas, QColor color);
    void generarMalthus2(int maxX, int maxY, QPainter *canvas);

    // Mandelbrot
    void mandelbrot(QPainter *canvas, QColor color);
};

#endif // GRAFICOS_H
