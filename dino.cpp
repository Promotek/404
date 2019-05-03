#include "dino.h"
#include "trail.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>
#include <QDebug>
#include "trail_reworked.h"
#include <math.h>
#include "cactus.h"


Dino::Dino(int baselineY) : QGraphicsPixmapItem() {
setPixmap(QPixmap(":/Image/dino0000.png"));
setScale(4);
this->baselineY = baselineY;
};

void Dino::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-7,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }

    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Up){
        //spawnTrail();
        this->InitJump();
        //scene()->addItem(FoodPrint);
    }
}

void Dino::InitJump() {
    std::cout << jumpprogress << " " << x() << "  " << y() << std::endl;
    if(!this->jumping){
        this->jumping = true;
        this->jumpprogress = 0;
        this->distance = 0.1;
        QTimer * timer = new QTimer(this);
        this->timerPointer = timer;

        connect(timer, SIGNAL(timeout()), this, SLOT(DoJump()));
        timer->start(1000/120);
    }

}

void Dino::DoJump()
{
    double jump;

    if  (this->jumpprogress >= 100){
        this->jumping = false;
        this->distance= 0.1;
        this->jumpprogress=1;
        timerPointer->stop();
        std::cout << "END:" << jumpprogress << " " << x() << "  " << y() << std::endl;
        return;
    }
    jump = pow(this->distance,(-1));
    this->jumpprogress++;

    if(jumpprogress < 50)
    {
        this -> distance= this->distance + 0.01;
        setPos(x(),y()-jump);
    }else if (jumpprogress > 50){
        this->distance=this->distance -0.01;
        if(y()+jump > baselineY){
            setPos(x(), baselineY);
        }else{
            setPos(x(),y()+jump);
        }
    }
    std::cout << jumpprogress << " " << x() << "  " << y() << std::endl;
}
void Dino::spawnTrail() {
    Trail * trail = new Trail();
    scene()->addItem(trail);
    trail->spawnLine();

}
void Dino::TrailReworkedSpawn() {
    TrailReworked * trail2 = new TrailReworked();
    scene()->addItem(trail2);
    trail2->TrailSlot();

}

void Dino::spawnCactus() {
    Cactus * cactus = new Cactus();
    scene()->addItem(cactus);
}
