#include "Bala.h"
#include "Buff.h"
#include "Enemigo.h"
#include "Player.h"
#include "Juego.h"
#include "Health.h"
#include <QKeyEvent>
#include <QGraphicsScene>

extern Juego *game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/Shoot.mp3"));

    setPixmap(QPixmap(":/images/Player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    QList<QGraphicsItem *> all = collidingItems();
    for (int i = 0, n = all.size(); i < n; i++){
        if(typeid(*(all[i])) == typeid(Enemigo)){

            game->score->Aumentar(valEnem);

            //Remover a ambos
            scene()->removeItem(all[i]);

            //Eliminar ambos
            delete  all[i];
        }
    }

    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-10, y());
    }else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 <  800)
            setPos(x()+10, y());
    }else if(event->key() == Qt::Key_Space){
        //Crear bala
        Bala *bala = new Bala();
        bala->setValEnem(valEnem);
        bala->setPos(x()+75, y()-10);
        scene()->addItem(bala);

        //Play Sonido
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }else if (bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }
    }
}

void Player::spawn(){
    Enemigo *enemigo = new Enemigo();
    valEnem = enemigo->getValEnem();
    if(Health().getHealth()  > 0){
        //Crear Enemigo
        scene()->addItem(enemigo);
    }else{
        scene()->removeItem(enemigo);
    }
}

void Player::BuffSpawn()
{
    Buff *buff = new Buff();
    if(Health().getHealth()  > 0){
        //Crear Enemigo
        scene()->addItem(buff);
    }else{
        scene()->removeItem(buff);
    }
}
