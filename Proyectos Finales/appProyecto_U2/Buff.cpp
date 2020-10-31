#include "Buff.h"
#include "Juego.h"
#include "Health.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <stdlib.h>

extern Juego *game;

Buff::Buff(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Set Random posicion
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //Dibujar el rect
    setPixmap(QPixmap(":/images/Coin.png"));

    //conectar
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}


void Buff::move(){
    //Si buffo impacta a jugador
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            //Aumentar Score
            game->score->Aumentar(5);

            //Remover a ambos
            scene()->removeItem(this);

            //Eliminar ambos
            delete this;
            return;
        }
    }

    //Mover Buffo
    setPos(x(), y()+5);
    if(pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
