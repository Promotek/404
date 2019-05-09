#ifndef BIRD_H
#define BIRD_H

#include "timerlist.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bird: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int moveSpeed;
    TimerList *allTimers;
    QTimer * moveTimer;

    void setImage(QString path);
    void initFly();
    void setPosition(int x, int y);

public:
    Bird(int moveSpeed);

public slots:
    void move();
    void fly();
};

#endif // BIRD_H
