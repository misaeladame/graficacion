#include "BalaEnemigo.h"
#include "Bala.h"
#include "Juego.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>

extern Juego *game;

BalaEnemigo::BalaEnemigo(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Dibujar el rect
    setPixmap(QPixmap(":/images/enemy4.png"));
    setScale(0.7);

    //conectar
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void BalaEnemigo::move(){
    //Si bala impacta a un enemigo
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Bala)){

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Eliminar ambos
            delete  colliding_items[i];
            delete this;
            return;
        }
    }

    //Mover Bala
    setPos(x(), y()+10);
    if(pos().y() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

