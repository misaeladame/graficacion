#ifndef RECTANGULO_1_H
#define RECTANGULO_1_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QKeyEvent>

#include <QObject>

class Rectangulo_1 : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Rectangulo_1(QObject *parent = nullptr);
    Rectangulo_1(int ancho=100, int alto=100);
    //FUNCION PARA MANEJAR EL TECLADO
    void keyPressEvent(QKeyEvent *event);

private:
    QTransform *Traslacion;
    QTransform *Escalacion;
    QTransform *Rotacion;
    QTransform *Transformacion1;
    QTransform *Transformacion3;
    QTransform *RotacionPuntoPivote;

    int Tx,Ty;
    double Sx, Sy;
    double xr, yr;
    double angulo;


    QTimer *timer;
    int ancho_,alto_;
signals:

};

#endif // RECTANGULO_1_H
