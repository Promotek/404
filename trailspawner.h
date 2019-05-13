#ifndef TRAILSPAWNER_H
#define TRAILSPAWNER_H

#include "timerlist.h"

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class TrailSpawner: public QObject{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    TimerList *allTimers;
public:
    QTimer *timer;

    TrailSpawner(QGraphicsScene *scene);
public slots:
    void spawnTrail();
};
#endif // TRAILSPAWNER_H
