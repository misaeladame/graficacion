#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>

class Level: public QGraphicsTextItem{
public:
    Level(QGraphicsItem *parent = 0);
    int getLevel();
    int lvlup();
private:
    int level;
};

#endif // LEVEL_H
