#ifndef BIRDSPAWNER_H
#define BIRDSPAWNER_H


#include "scoreboard.h"
#include "timerlist.h"

#include <QGraphicsScene>
#include <QTimer>

class BirdSpawner: public QObject{
    Q_OBJECT
private:
    Scoreboard * scoreboard;
    QGraphicsScene * scene;
    TimerList *allTimers;

public:
    QTimer *timer;
    BirdSpawner(QGraphicsScene * scene, Scoreboard * scoreboard);

public slots:
    void spawnBird();

};

#endif // BIRDSPAWNER_H
