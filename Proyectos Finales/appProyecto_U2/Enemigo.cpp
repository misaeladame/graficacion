#include "Enemigo.h"
#include "Juego.h"
#include "Bala.h"
#include "BalaEnemigo.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <stdlib.h>

extern Juego *game;

Enemigo::Enemigo(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Set Random posicion
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //Arreglo de Paths y Random del index
    QString characters[5] = {":/images/enemy1.png", ":/images/enemy2.png", ":/images/enemy3.png", ":/images/enemy4.png", ":/images/enemy5.png"};
    int RandIndex = rand() % 5;

    //Set de String Seleccionado por el randomIndex
    QString ChosenString = characters[RandIndex];

    //Dibujar el pixmap
    setPixmap(QPixmap(ChosenString));

    //Timers y conexion a move
    QTimer *timer = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    QTimer *timer3 = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //Start timer
    timer->start(50);

    //Transformaciones por diferente enemigo
    switch (RandIndex) {
        case 0:
             setScale(0.6); //esclacion 0.6
             valEnem = 1;
        break;
        case 1:
             setScale(0.5); //esclacion 0.5
             connect(timer2, SIGNAL(timeout()), this, SLOT(rotar()));  timer2->start(90);
             valEnem = 1;
        break;
        case 2:
            setRotation(180); //rotacion 180
            valEnem = 2;
        break;
        case 3:
             setScale(0.7); //escalacion 0.7;
             connect(timer2, SIGNAL(timeout()), this, SLOT(rotar()));  timer2->start(90); //Conexion a rotar junto su Start del timer
             valEnem = 4;
        break;
        case 4:
             setScale(0.4); //esclacion 0.4
             connect(timer3, SIGNAL(timeout()), this, SLOT(disparar())); timer3->start(1200);
             valEnem = 5;
        break;
    }

    setTransformOriginPoint(50,50);
}

int Enemigo::getValEnem()
{
    return valEnem;
}

void Enemigo::move(){
    //Mover Enemigo
    setPos(x(), y()+5);
    if(pos().y() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

void Enemigo::rotar()
{
    //Definiciones de variables
    static int angulo1 = 0;
    static int cont = 0;

    //Rotar
    if(cont <= 8){
        angulo1 += 45;
        if(cont == 8){
            angulo1 = 0;
            cont = 0;
        }
    }

    //Asignar angulo a rotacion
    setRotation(angulo1);
    cont++;
}

void Enemigo::disparar()
{
    BalaEnemigo *bala = new BalaEnemigo();
    bala->setPos(x()+50, y()+100);
    scene()->addItem(bala);
}
