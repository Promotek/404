#include "cactus.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include "dino.h"
#include "game.h"

extern Game * game;

Cactus::Cactus(): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/Image/cactusBig0000.png"));
    setScale(0.70);
    setPos(1300,420);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Cactus::move() {
    // if cactus collides with dino
    QList<QGraphicsItem *> items = collidingItems();
    for (int i = 0; i < items.size(); i++) {
        if (typeid (*(items[i])) == typeid (Dino)) {
            game->player->timerPointer->stop();
        }
    }

    setPos(x() - 8, y());

    if (pos().x() + boundingRect().width() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
