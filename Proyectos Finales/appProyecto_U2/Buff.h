#ifndef BUFF_H
#define BUFF_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Buff: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Buff(QGraphicsItem *parent=0);
public slots:
    void move();
};

#endif // BUFF_H
