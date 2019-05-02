#include "dino.h"
#include "trail.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>
#include <QDebug>
#include "cactus.h"
#include <math.h>


Dino::Dino() : QGraphicsPixmapItem() {
setPixmap(QPixmap(":/Image/dino0000.png"));
setScale(4);
};


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

void Dino::InitJump() {

    if(!this->jumping){
        this->jumping = true;
        this->jumpprogress = 0;
        this->distance = 0.1;
        QTimer * timer = new QTimer(this);
        timerPointer = timer;
        connect(timer, SIGNAL(timeout()), this, SLOT(DoJump()));
        timer->start(1000/120);
    }

}

void Dino::DoJump()
{
    float jump;
    if  (this->jumpprogress > 100){
        this->jumping = false;
        this->distance= 0.1;
        this->jumpprogress=1;
        timerPointer->stop();
        //return;
    }
    jump = pow(this->distance,(-1));
    this->jumpprogress++;

    if(jumpprogress < 50)
    {
        this -> distance= this->distance + 0.01;
        setPos(x(),y()-jump);
    }else if (jumpprogress > 50){
        this->distance=this->distance -0.01;
        setPos(x(),y()+jump);
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
