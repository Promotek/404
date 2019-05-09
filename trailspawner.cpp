#include "trailspawner.h"
#include "trail.h"
#include "game.h"

#include <QTimer>

extern Game *game;

TrailSpawner::TrailSpawner(QGraphicsScene *scene){
    this->scene = scene;

    timer = new QTimer();
    allTimers->addToList(timer);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnTrail()));

    timer->start(600);
}

void TrailSpawner::spawnTrail(){
    Trail * trail = new Trail(1200, 535);
    scene->addItem(trail);
    Trail * trail2 = new Trail(1230, 525);
    scene->addItem(trail2);
    Trail * trail3 = new Trail(1250, 500);
    scene->addItem(trail3);
}
