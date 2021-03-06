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

Bird::Bird(double moveSpeed, QString path1, QString path2): QObject(), QGraphicsPixmapItem() {
    this->path1 = path1;
    this->path2 = path2;
    int randomY = rand() % 3;
    setPosition(1300, randomY);
    this->moveSpeed = moveSpeed;
    initFly();

    moveTimer = new QTimer();
    // add Timer to list. Used to terminate all Timers if colliding
    allTimers->addToList(moveTimer);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(35);
}

void Bird::setPosition(int x, int y) {
    if (y == 0) {
        setPos(x, 280);
    } else if (y == 1) {
        setPos(x, 330);
    } else if (y == 2) {
        setPos(x, 380);
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
    timer->start(160);
}

void Bird::fly() {
    if (counter % 2 == 0) {
        setImage(path1);
    } else {
        setImage(path2);
    }
    counter++;
}

void Bird::move() {
    // if bird collides with dino
    QList<QGraphicsItem *> items = collidingItems();
    for (int i = 0; i < items.size(); i++) {
        if (typeid (*(items[i])) == typeid (Dino)) {
            QString path = ":/Image/dinoDead0000.png";
            if(game->isChangeColor) {
                path = ":/Image/dinoDeadNegative0000.png";
            }
            game->player->setImage(path);
            QList<QTimer *> timers = allTimers->getList();
            GameOver *go = new GameOver();
            scene()->addWidget(go->getLabel());
            scene()->addWidget(go->getButton());
            for (QTimer *timer : timers) {
                timer->stop();
            }
            game->player->clearFocus();
        }
    }

    setPos(x() - moveSpeed, y());

    if (pos().x() + boundingRect().width() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
