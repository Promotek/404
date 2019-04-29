#include "dino.h"
#include "trail.h"
#include <QGraphicsScene>
#include <QKeyEvent>

#include <QDebug>




void Dino::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        spawnTrail();

        //scene()->addItem(FoodPrint);
    }
}
void Dino::spawnTrail() {
    Trail * trail = new Trail();
    scene()->addItem(trail);
    trail->spawnLine();

}
