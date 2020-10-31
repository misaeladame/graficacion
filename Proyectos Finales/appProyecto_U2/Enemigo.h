#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemigo: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemigo(QGraphicsItem *parent = 0);
    int getValEnem();
    void setvalEnem(int);
public slots:
    void move();
    void rotar();
    void disparar();
private:
    int valEnem;
};

#endif // ENEMIGO_H
