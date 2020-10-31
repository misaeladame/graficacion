#include "Score.h"
#include "Health.h"
#include "Juego.h"
#include <QFont>

extern Juego *game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //Inicializar el puntuaje en 0
    score = 0;

    //Dibujar texto
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Cuphead Memphis",16));
}
void Score::Aumentar(int valor)
{
    if(game->health->getHealth() > 0){
        score+= valor;
        setPlainText("Score: " + QString::number(score));
        if (score >= valSup){
            valSup += 10;
            game->health->Aumentar();
            game->AumBuff();
            game->AumEnem();
        }
    }

}

int Score::getScore(){
    return score;
}

