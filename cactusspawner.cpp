#include "cactus.h"
#include "cactusspawner.h"
#include "timerlist.h"

CactusSpawner::CactusSpawner(QGraphicsScene * scene, Scoreboard * scoreboard)
{
    this->scoreboard = scoreboard;
    this->scene = scene;
    QTimer *timer = new QTimer();
    allTimers->addToList(timer);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnCactus()));

    timer->start(3000);
}

void CactusSpawner::spawnCactus() {
    Cactus * cactus = new Cactus(this->scoreboard->GetMoveSpeed());
    this->scene->addItem(cactus);
}
