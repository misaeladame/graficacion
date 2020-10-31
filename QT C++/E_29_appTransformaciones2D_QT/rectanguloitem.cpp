#include "rectanguloitem.h"
#include <QKeyEvent>
#include <math.h>

rectanguloItem::rectanguloItem(QObject *parent) : QObject(parent)
{

}

rectanguloItem::rectanguloItem(int ancho, int alto)
{
    this->ancho = ancho;
    this->alto = alto;

    Tx = Ty = 0;
    Sx = Sy = 1.0;
    angulo = 0.0;

}

//keyPressEvent(QKeyEvent *event)
void rectanguloItem::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        setPos(this->x()-10, this->y());
    }
    if(event->key() == Qt::Key_D)
    {
        setPos(this->x()+10, this->y());
    }
    if(event->key() == Qt::Key_S)
    {
        setPos(this->x(), this->y()+10);
    }
    if(event->key() == Qt::Key_W)
    {
        setPos(this->x(), this->y()-10);
    }
}
