#include "obstacle.h"
#include "dino.h"
#include "gameover.h"
#include "game.h"
#include "bird.h"
#include "cactus.h"

#include <math.h>

extern Game *game;

Obstacle::Obstacle(double moveSpeed, QGraphicsScene *scene){
    this->moveSpeed = moveSpeed;
    this->scene = scene;

    timer = new QTimer();
    allTimers->addToList(timer);
    connect(timer, SIGNAL(timeout()), this, SLOT(setObstacle()));

    timer->start(2500);

}

void Obstacle::setMoveSpeed(double moveSpeed) {
    this->moveSpeed = moveSpeed;
}

void Obstacle::setObstacle() {
    int random = rand() % 4;
    int xPos = rand() % 150 + 50;

    if (random == 0) {
        createBird();
    } else if(random == 1) {
       createCactusBig(xPos);
    } else if(random == 2) {
        createCactusSmall(xPos);
    } else if (random == 3) {
       createCactusMany(xPos);
    }
}

void Obstacle::createBird() {
    QString path1 = ":/Image/bird.png";
    QString path2 = ":/Image/bird2.png";
    if (game->isChangeColor) {
        path1 = ":/Image/birdNegative.png";
        path2 = ":/Image/bird2Negative.png";
    }
    bird = new Bird(moveSpeed, path1, path2);
    scene->addItem(bird);
}

void Obstacle::createCactusBig(int xPos) {
    QString path = ":/Image/cactusBig0000.png";
    if (game->isChangeColor) {
        path = ":/Image/cactusBigNegative0000.png";
    }
    cactus = new Cactus(moveSpeed, path, 350, xPos);
    scene->addItem(cactus);
}

void Obstacle::createCactusSmall(int xPos) {
    QString path = ":/Image/cactusSmall0000.png";
    if (game->isChangeColor) {
        path = ":/Image/cactusSmallNegative0000.png";
    }
    cactus = new Cactus(moveSpeed, path, 385, xPos);
    scene->addItem(cactus);
}

void Obstacle::createCactusMany(int xPos) {
    QString path = ":/Image/cactusSmallMany0000.png";
    if (game->isChangeColor) {
        path = ":/Image/cactusSmallManyNegative0000.png";
    }
    cactus = new Cactus(moveSpeed, path, 385, xPos);
    scene->addItem(cactus);
}
