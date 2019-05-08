#include "obstacle.h"
#include "dino.h"
#include "gameover.h"
#include "game.h"
#include "bird.h"
#include "cactus.h"

#include <math.h>

Obstacle::Obstacle(int moveSpeed, QGraphicsScene *scene){
    this->moveSpeed = moveSpeed;
    this->scene = scene;

    timer = new QTimer();
    allTimers->addToList(timer);
    connect(timer, SIGNAL(timeout()), this, SLOT(setObstacle()));

    timer->start(3000);

}

void Obstacle::setObstacle() {
    int random = rand() % 4;

    if (random == 0) {
        //bird
        Bird *bird = new Bird(moveSpeed);
        scene->addItem(bird);
    } else if(random == 1) {
        //cactusBig
        Cactus *cactus = new Cactus(moveSpeed, ":/Image/cactusBig0000.png");
        scene->addItem(cactus);
    } else if(random == 2) {
        //cactusSmall
        Cactus *cactus = new Cactus(moveSpeed, ":/Image/cactusSmall0000.png");
        scene->addItem(cactus);
    } else if (random == 3) {
        //cactusMany
        Cactus *cactus = new Cactus(moveSpeed, ":/Image/cactusSmallMany0000.png");
        scene->addItem(cactus);
    }
}
