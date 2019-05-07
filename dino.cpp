#include "dino.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <math.h>

Dino::Dino(int baselineY) : QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/Image/dino0000.png"));
    setScale(4);
    this->baselineY = baselineY;
};

void Dino::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Up){
        this->InitJump();
    }
}

void Dino::InitJump() {
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
}
