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

    timer->start(3000);

}

void Obstacle::setMoveSpeed(double moveSpeed) {
    this->moveSpeed = moveSpeed;
}

void Obstacle::setObstacle() {
    int random = rand() % 4;

    if (random == 0) {
        //bird
        bird = new Bird(moveSpeed);
        scene->addItem(bird);
    } else if(random == 1) {
        //cactusBig
        cactus = new Cactus(moveSpeed, ":/Image/cactusBig0000.png");
        scene->addItem(cactus);
    } else if(random == 2) {
        //cactusSmall
        cactus = new Cactus(moveSpeed, ":/Image/cactusSmall0000.png");
        scene->addItem(cactus);
    } else if (random == 3) {
        //cactusMany
        cactus = new Cactus(moveSpeed, ":/Image/cactusSmallMany0000.png");
        scene->addItem(cactus);
    }
}
