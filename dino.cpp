#include "dino.h"
#include "trail.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>;
#include <QDebug>
#include "cactus.h"




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
        //spawnTrail();
        this->InitJump();
        //scene()->addItem(FoodPrint);
    }
}

void Dino::InitJump()
{
    if(!this->jumping){
        this->jumping = true;
        this->jumpprogress = 0;
        QTimer * timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(DoJump()));
        timer->start(30);
    }
}

void Dino::DoJump()
{
    if(this->jumpprogress >= 100){
        this->jumping = false;
        return;
    }

    this->jumpprogress++;

    if(jumpprogress <= 50)
    {
        setPos(x(),y()-4);
    }else{
        setPos(x(),y()+4);
    }
    std::cout << x() << "  " << y() << std::endl;
}
void Dino::spawnTrail() {
    Trail * trail = new Trail();
    scene()->addItem(trail);
    trail->spawnLine();

}

void Dino::spawnCactus() {
    Cactus * cactus = new Cactus;
    scene()->addItem(cactus);
    cactus->spawn();
}
