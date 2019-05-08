#include "cactus.h"
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

extern Game *game;

Cactus::Cactus(int moveSpeed): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/Image/cactusBig0000.png"));
    setScale(0.70);
    setPos(1300,420);
    this->moveSpeed = moveSpeed;

    moveTimer = new QTimer();

    // add Timer to list. Used to terminate all Timers if colliding
    allTimers->addToList(moveTimer);

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(50);
}

void Cactus::move() {
    // if cactus collides with dino
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
