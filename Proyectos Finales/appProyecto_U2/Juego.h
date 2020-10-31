#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QWidget>
#include <QTimer>
#include "Health.h"
#include "Player.h"
#include "Score.h"
#include <QGraphicsView>

class Juego: public QGraphicsView{
public:
    Juego(QWidget *parent = 0);

    QGraphicsScene *escena;

    Player *player;
    Score *score;
    Health *health;

    QTimer *timer;
    QTimer *timer2;

    int timeEnem = 2000;
    int timeBuff = 10000;

    void Desconectar();
    void AumEnem();
    void DisEnem();
    void AumBuff();
    void DisBuff();
};

#endif // JUEGO_H

