#include "Rect.h"
#include "Bala.h"
#include "Enemigo.h"

#include <QKeyEvent>
#include <QGraphicsScene>

void Rect::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-10, y());
    }else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 <  800)
            setPos(x()+10, y());
    }else if(event->key() == Qt::Key_Space){
        //Crear bala
        Bala *bala = new Bala();
        bala->setPos(x(), y());
        scene()->addItem(bala);

    }
}

void Rect::spawn(){
   //Crear Enemigo
    Enemigo *enemigo = new Enemigo();
    scene()->addItem(enemigo);
}
