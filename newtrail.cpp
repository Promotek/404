#include "newtrail.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>

NewTrail::NewTrail(int xPosition, int yPosition): QObject(), QGraphicsRectItem(){
    setRect(xPosition, yPosition, 10, 10);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void NewTrail::move() {
    setPos(x() - 8, y());
    if (pos().x() + rect().width() < -1300) {
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Trail deleted";
    }
}
