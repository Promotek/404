#include "cloud.h"
#include "game.h"

#include <QTimer>

extern Game *game;

Cloud::Cloud(int y) {
    setPixmap(QPixmap(":/Image/cloud0000.png"));
    setScale(2.5);
    setPos(1210, y);

    timer = new QTimer();
    allTimers->addToList(timer);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(40);
}

void Cloud::move() {
    if (pos().x() + (boundingRect().width()*2.5) < 0) {
        game->scene->removeItem(this);
        delete this;
    }
    setPos(x() - 4, y());
}
