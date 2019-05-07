#include "trail.h"
#include "game.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

Trail::Trail(int xPosition, int yPosition): QObject(), QGraphicsRectItem(){
    setRect(xPosition, yPosition, 10, 10);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Trail::move() {
    setPos(x() - 8, y());
    if (pos().x() + rect().width() < -1300) {
        scene()->removeItem(this);
        delete this;
    }
}
