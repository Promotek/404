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

    timer->start(400);
}

void TrailSpawner::spawnTrail(){
    Trail * trail = new Trail();
    trail->setTrail(1200, 485, 5, 1);
    scene->addItem(trail);
    Trail * trail2 = new Trail();
    trail2->setTrail(1320, 440, 6, 1);
    scene->addItem(trail2);
    Trail * trail3 = new Trail();
    trail3->setTrail(1250, 450, 7, 1);
    scene->addItem(trail3);
    Trail * trail4 = new Trail();
    trail4->setTrail(1215, 460, 8, 1);
    scene->addItem(trail4);
    Trail * trail5 = new Trail();
    trail5->setTrail(1280, 480, 9, 1);
    scene->addItem(trail5);
}
