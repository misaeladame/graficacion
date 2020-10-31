
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
    int round_(float n)//9.5 + .5 = 10
                       //9.6 + .5 = 10 |.1
                       //9.4 + .9 = 9.9 | 9
    {
        return int(n+0.5);
    }
    graphics();
    void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas);

    void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color);


};

#endif // GRAPHICS_H
