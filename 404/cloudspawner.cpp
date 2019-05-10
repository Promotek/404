#include "cloudspawner.h"
#include "game.h"
#include "cloud.h"

#include <math.h>

extern Game *game;

CloudSpawner::CloudSpawner() {

    timer = new QTimer();
    allTimers->addToList(timer);
    connect(timer, SIGNAL(timeout()), this, SLOT(setCloud()));

    timer->start(6000);

}

void CloudSpawner::setCloud() {
    int randomY = rand() % 5;

    if (randomY == 0) {
        cloud = new Cloud(100);
        game->scene->addItem(cloud);
    } else if (randomY == 1) {
        cloud = new Cloud(150);
        game->scene->addItem(cloud);
    } else if (randomY == 2) {
        cloud = new Cloud(200);
        game->scene->addItem(cloud);
    } else if (randomY == 3) {
        cloud = new Cloud(250);
        game->scene->addItem(cloud);
    } else if (randomY == 4) {
        cloud = new Cloud(300);
        game->scene->addItem(cloud);
    }
}

