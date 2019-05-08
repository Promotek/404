#include "bird.h"
#include "birdspawner.h"
#include "timerlist.h"

#include <math.h>

#include <QDebug>

BirdSpawner::BirdSpawner(QGraphicsScene * scene, Scoreboard * scoreboard)
{
    this->scoreboard = scoreboard;
    this->scene = scene;

    QTimer *timer = new QTimer();
    allTimers->addToList(timer);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnBird()));

    timer->start(5000);
}

void BirdSpawner::spawnBird() {
    Bird * bird = new Bird(this->scoreboard->GetMoveSpeed());
    this->scene->addItem(bird);
}
