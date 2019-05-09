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
    QTimer *spawnTimer;

public:
    TrailSpawner(QGraphicsScene *scene);
public slots:
    void spawnTrail();
};
#endif // TRAILSPAWNER_H
