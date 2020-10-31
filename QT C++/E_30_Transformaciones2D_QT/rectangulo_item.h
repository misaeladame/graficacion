#ifndef RECTANGULO_ITEM_H
#define RECTANGULO_ITEM_H

#include <QObject>
#include <QGraphicsRectItem>

class rectangulo_Item : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit rectangulo_Item(QObject *parent = nullptr);
    rectangulo_Item(int ancho = 100, int alto = 100);
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

#endif // RECTANGULO_ITEM_H
