#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "timerlist.h"
#include "bird.h"
#include "cactus.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Obstacle: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
     double moveSpeed;
     TimerList *allTimers;
     QTimer *timer;
     QGraphicsScene *scene;

public:
     Bird *bird;
     Cactus *cactus;

     Obstacle(double moveSpeed = 1, QGraphicsScene *scene = nullptr);
     void setMoveSpeed(double moveSpeed);

public slots:
    void setObstacle();
};

#endif // OBSTACLE_H
