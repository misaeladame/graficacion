#include "Level.h"
#include "Health.h"
#include "Juego.h"
#include <QFont>

extern Juego *game;

Level::Level(QGraphicsItem *parent): QGraphicsTextItem(parent){

    level = 0;

    //Dibujar texto
    setPlainText("Level: " + QString::number(level + 1));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Cuphead Memphis",16));
}


int Level::getLevel(){
    return level;
}

int Level::lvlup(){
    level++;
    setPlainText("Level: " + QString::number(level + 1));
}


