#ifndef BALA_H
#define BALA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bala: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bala(QGraphicsItem *parent=0);
    void setValEnem(int);
public slots:
    void move();
private:
    int valEnem;
};

#endif // BALA_H


