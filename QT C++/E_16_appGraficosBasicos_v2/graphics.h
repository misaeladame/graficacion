#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QColor>


class graphics
{
public:
    // floor y cell
    int round_(double n)
    {
        return int(n+0.5);
    }
    graphics();

    void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color);

    void CirculoPitagoras(double xc, double yc, double r, QPainter *canvas);
};

#endif // GRAPHICS_H
