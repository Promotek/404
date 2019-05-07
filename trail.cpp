#include "trail.h"
#include "game.h"

#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

Trail::Trail(int xPosition, int yPosition): QObject(), QGraphicsRectItem(){
    setRect(xPosition, yPosition, 10, 10);

    moveTimer = new QTimer();
    allTimers->addToList(moveTimer);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(50);
}

void Trail::move() {
    setPos(x() - 8, y());
    if (pos().x() + rect().width() < -1300) {
        scene()->removeItem(this);
        delete this;
    }
}
