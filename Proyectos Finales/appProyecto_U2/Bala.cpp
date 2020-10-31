#include "Bala.h"
#include "Juego.h"
#include "Enemigo.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>

extern Juego *game;

Bala::Bala(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Dibujar el rect
    setPixmap(QPixmap(":/images/Shoot.png"));

    //conectar
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bala::setValEnem(int valor)
{
    valEnem = valor;
}

void Bala::move(){
    //Si bala impacta a un enemigo
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemigo)){

            //Aumentar Score
            game->score->Aumentar(valEnem);

            //Remover a ambos
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Eliminar ambos
            delete  colliding_items[i];
            delete this;
            return;
        }
    }

    //Mover Bala
    setPos(x(), y()-10);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}


