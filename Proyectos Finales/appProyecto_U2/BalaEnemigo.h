#ifndef BALAENEMIGO_H
#define BALAENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class BalaEnemigo: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BalaEnemigo(QGraphicsItem *parent=0);
public slots:
    void move();
};

#endif // BALAENEMIGO_H
