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

extern Game *game;

Cactus::Cactus(double moveSpeed, QString path, int yPos, int xPos): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(path));
    setScale(0.9);
    setPos(1200 + xPos, yPos);
    this->moveSpeed = moveSpeed;

    moveTimer = new QTimer();
    // add Timer to list. Used to terminate all Timers if colliding
    allTimers->addToList(moveTimer);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(35);
}

void Cactus::setMoveSpeed(double moveSpeed) {
    this->moveSpeed = moveSpeed;
}

void Cactus::move() {
    // if cactus collides with dino
    QList<QGraphicsItem *> items = collidingItems();
    for (int i = 0; i < items.size(); i++) {
        if (typeid (*(items[i])) == typeid (Dino)) {
            Dino *dino = game->player;
            QString path = ":/Image/dinoDead0000.png";
            if(game->isChangeColor) {
                path = ":/Image/dinoDeadNegative0000.png";
            }
            dino->setImage(path);
            dino->setPosition(dino->x(), dino->baselineY);
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
