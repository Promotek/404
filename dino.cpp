#include "dino.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <math.h>

Dino::Dino(int baselineY) : QGraphicsPixmapItem() {
    this->baselineY = baselineY;
    initRun();
};

void Dino::initRun() {
    runTimer = new QTimer();
    allTimers->addToList(runTimer);
    connect(runTimer, SIGNAL(timeout()), this, SLOT(run()));
    runTimer->start(1000/100);
}

void Dino::run() {
    int random = rand() % 2 + 1;
    if (random == 1) {
        setImage(":/Image/dinorun0000.png");
    } else if (random == 2) {
        setImage(":/Image/dinorun0001.png");
    }
}

void Dino::setImage(QString path){
    setPixmap(QPixmap(path));
    setScale(4);
}

void Dino::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Up){
        this->initJump();
    }
}

void Dino::initJump() {
    if(!this->jumping){
        this->jumping = true;
        this->jumpprogress = 0;
        this->distance = 0.1;

        QTimer * timer = new QTimer(this);
        this->timerPointer = timer;
        allTimers->addToList(timer);
        allTimers->addToList(timerPointer);
        connect(timer, SIGNAL(timeout()), this, SLOT(doJump()));

        timer->start(1000/120);
    }
}

void Dino::doJump() {
    double jump;
    runTimer->stop();
    setImage(":/Image/dinoJump0000.png");

    if  (this->jumpprogress >= 100){
        initRun();
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
