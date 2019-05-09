#ifndef CACTUS_H
#define CACTUS_H

#include "timerlist.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Cactus: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    int moveSpeed;
    TimerList *allTimers;

public:
    QTimer * moveTimer;
    Cactus(int moveSpeed = 1, QString path = "");
public slots:
    void move();
};

#endif // CACTUS_H
