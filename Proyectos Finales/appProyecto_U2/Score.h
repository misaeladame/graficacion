#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent = 0);
    void Aumentar(int);
    int getScore();
private:
    int score;
    int valSup = 10;
};

#endif // SCORE_H

