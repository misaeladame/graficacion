#include "Juego.h"
#include "Enemigo.h"
#include "Buff.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include <QBrush>
#include <QIcon>
#include <QMediaPlaylist>
#include <QMediaPlayer>

Juego::Juego(QWidget *parent){

    setWindowIcon(QIcon(":/images/icon.jpg"));

    escena = new QGraphicsScene();
    escena->setSceneRect(0,0,800,600);

    setBackgroundBrush(QBrush(QImage(":/images/background.bmp")));

    //Añadir vista
    setScene(escena);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(800,600);

    Player *player = new Player();
    player->setPos(400,500);
    //Hacer focusable el rect
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Añadir objecto a la escena
    escena->addItem(player);

    //Crear Score
    score = new Score();
    escena->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    escena->addItem(health);

    //Spawn Enemigos
    timer = new QTimer();
    //QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(timeEnem);

    //Spawn Enemigos
    timer2 = new QTimer();
    //QObject::connect(timer2, SIGNAL(timeout()), player, SLOT(Buffspawn()));
    timer2->connect(timer2, SIGNAL(timeout()), player, SLOT(BuffSpawn()));
    timer2->start(timeBuff);

    // Musica de Fondo
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl ("qrc:/sounds/Cuphead OST - Botanic Panic [Music].mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *musica = new QMediaPlayer();
    musica->setPlaylist(playlist);
    musica->setVolume(20);
    musica->play();

    show();
}

void Juego::Desconectar()
{
    timer->stop();
    timer2->stop();
    escena->addText("GAME OVER", QFont("Cuphead Memphis", 48))->setPos(250,250);
}

void Juego::AumEnem()
{
    timeEnem-=50;
    timer->start(timeEnem);
}

void Juego::DisEnem()
{
    timeEnem+=50;
    timer->start(timeEnem);
}

void Juego::AumBuff()
{
    timeBuff-=10;
    timer->start(timeBuff);
}

void Juego::DisBuff()
{
    timeBuff+=10;
    timer->start(timeBuff);
}
