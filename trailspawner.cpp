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

    timer->start(1000);
}

void TrailSpawner::spawnTrail(){
    Trail * trail = new Trail();
    trail->setTrail(1200, 485, 3, 1);
    scene->addItem(trail);
    Trail * trail2 = new Trail();
    trail2->setTrail(1330, 475, 4, 1);
    scene->addItem(trail2);
    Trail * trail3 = new Trail();
    trail3->setTrail(1250, 450, 5, 1);
    scene->addItem(trail3);
    Trail * trail4 = new Trail();
    trail4->setTrail(1300, 460, 6, 1);
    scene->addItem(trail4);
    Trail * trail5 = new Trail();
    trail5->setTrail(1215, 480, 7, 1);
    scene->addItem(trail5);
}
