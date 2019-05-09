#include "bird.h"
#include "timerlist.h"
#include "dino.h"
#include "game.h"
#include "gameover.h"

#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>
#include <math.h>

#include <QDebug>

extern Game *game;

Bird::Bird(int moveSpeed): QObject(), QGraphicsPixmapItem() {
    int randomY = rand() % 3;
    setPosition(1300, randomY);
    this->moveSpeed = moveSpeed;
    initFly();

    moveTimer = new QTimer();
    // add Timer to list. Used to terminate all Timers if colliding
    allTimers->addToList(moveTimer);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(50);
}

void Bird::setPosition(int x, int y) {
    if (y == 0) {
        setPos(x, 330);
    } else if (y == 1) {
        setPos(x, 380);
    } else if (y == 2) {
        setPos(x, 430);
    }
}

void Bird::setImage(QString path) {
    setPixmap(QPixmap(path));
    setScale(0.70);
}

void Bird::initFly() {
    QTimer *timer = new QTimer();
    allTimers->addToList(timer);
    connect(timer, SIGNAL(timeout()), this, SLOT(fly()));
    timer->start(1000/10);
}

void Bird::fly() {
    int random = rand() % 2 + 1;
    if (random == 1) {
        setImage(":/Image/bird.png");
    } else if (random == 2) {
        setImage(":/Image/bird2.png");
    }
}

void Bird::move() {
    // if bird collides with dino
    QList<QGraphicsItem *> items = collidingItems();
    for (int i = 0; i < items.size(); i++) {
        if (typeid (*(items[i])) == typeid (Dino)) {
            game->player->setImage(":/Image/dinoDead0000.png");
            QList<QTimer *> timers = allTimers->getList();
            GameOver *go = new GameOver();
            scene()->addWidget(go->getLabel());
            scene()->addWidget(go->getButton());
            for (QTimer *timer : timers) {
                timer->stop();
            }
        }
    }

    setPos(x() - moveSpeed, y());

    if (pos().x() + boundingRect().width() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
