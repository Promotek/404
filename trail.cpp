#include "trail.h"
#include "game.h"

#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

extern Game *game;

Trail::Trail(): QObject(), QGraphicsRectItem(){
    moveTimer = new QTimer();
    allTimers->addToList(moveTimer);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(30);
}

void Trail::move() {
    setPos(x() - 12, y());
    if (pos().x() + rect().width() < -1300) {
        scene()->removeItem(this);
        delete this;
    }
}

void Trail::setTrail(int xPos, int yPos, int width, int heigth) {
    setRect(xPos, yPos, width, heigth);
    if (game->isChangeColor) {
        setPen(QPen(Qt::white));
    }
}
