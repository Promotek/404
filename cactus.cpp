#include "cactus.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>

Cactus::Cactus(): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/Image/cactusBig0000.png"));
    setScale(0.70);
    setPos(1300,420);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Cactus::move() {
    setPos(x() - 8, y());

    if (pos().x() + boundingRect().width() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
