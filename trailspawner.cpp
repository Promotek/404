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

    timer->start(250);
}

void TrailSpawner::spawnTrail(){
    Trail * trail = new Trail();
    trail->setTrail(1230 + rand()% 20 +1, 450, rand()% 8 + 1, 2);
    scene->addItem(trail);
    Trail * trail2 = new Trail();
    trail2->setTrail(1250 + rand()% 20 +1, 455, rand()% 8 + 1, 2);
    scene->addItem(trail2);
    Trail * trail3 = new Trail();
    trail3->setTrail(1200 + rand()% 20 +1, 445, rand()% 15 + 1, 2);
    scene->addItem(trail3);
   /* Trail * trail4 = new Trail();
    trail4->setTrail(1215, 460, 8, 1);
    scene->addItem(trail4);
    Trail * trail5 = new Trail();
    trail5->setTrail(1280, 480, 9, 1);
    scene->addItem(trail5);*/
}
