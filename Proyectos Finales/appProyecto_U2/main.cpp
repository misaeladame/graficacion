#include <QApplication>
#include "Juego.h"

Juego * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Juego();
    game->show();

    return a.exec();
}
