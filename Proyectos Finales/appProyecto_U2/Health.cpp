#include "Health.h"
#include "Juego.h"
#include <QFont>

extern Juego *game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("Cuphead Memphis",16));
}

void Health::Aumentar()
{
    health++;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::decrease(){
    if(health > 0){
        health--;
        setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
    }else{
        game->Desconectar();
    }
}

int Health::getHealth(){
    return health;
}
