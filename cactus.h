#ifndef CACTUS_H
#define CACTUS_H

#include "timerlist.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Cactus: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    double moveSpeed;
    TimerList *allTimers;

public:
    QTimer * moveTimer;
    Cactus(double moveSpeed = 1, QString path = "", int yPos = 0);
    void setMoveSpeed(double moveSpeed);

public slots:
    void move();
};

#endif // CACTUS_H
