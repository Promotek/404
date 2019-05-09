#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "timerlist.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Obstacle: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
     int moveSpeed;
     TimerList *allTimers;
     QTimer *timer;
     QGraphicsScene *scene;

public:

    Obstacle(int moveSpeed = 1, QGraphicsScene *scene = nullptr);

public slots:
    void setObstacle();
};

#endif // OBSTACLE_H
