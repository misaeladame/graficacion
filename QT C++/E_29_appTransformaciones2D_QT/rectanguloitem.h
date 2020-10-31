#ifndef RECTANGULOITEM_H
#define RECTANGULOITEM_H

#include <QObject>
#include <QGraphicsRectItem>

class rectanguloItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit rectanguloItem(QObject *parent = nullptr);

    rectanguloItem(int ancho=100, int alto=100);

    void keyPressEvent(QKeyEvent *event);

private:

    QTransform *Traslacion;
    QTransform *Escalacion;
    QTransform *Rotacion;

    int Tx, Ty;

    double Sx, Sy;
    double angulo;

    int ancho, alto;

signals:
};

#endif // RECTANGULOITEM_H
