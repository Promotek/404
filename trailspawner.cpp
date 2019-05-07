#include "trailspawner.h"
#include "trail.h"
#include "game.h"
#include <QTimer>

TrailSpawner::TrailSpawner(QGraphicsScene *scene){
    this->scene = scene;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnTrail()));

    timer->start(600);
}

void TrailSpawner::spawnTrail(){
    Trail * trail = new Trail(1300, 530);
    scene->addItem(trail);
    Trail * trail2 = new Trail(1320, 525);
    scene->addItem(trail2);
    Trail * trail3 = new Trail(1335, 520);
    scene->addItem(trail3);
}
