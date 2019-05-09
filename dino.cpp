#include "dino.h"
#include "game.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <math.h>

extern Game *game;

Dino::Dino(int baselineY) : QGraphicsPixmapItem() {
    this->baselineY = baselineY;
    this->duckPosition = baselineY + 40;
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
    setPos(x(), baselineY);
}

void Dino::setImage(QString path){
    setPixmap(QPixmap(path));
    setScale(4);
}

void Dino::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Up){
        this->initJump();
    } else if (event->key() == Qt::Key_Down) {
        this->initDuck();
    }
}

void Dino::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Down) {
        duckTimer->stop();
        this->initRun();
    }
}

void Dino::initDuck() {
    runTimer->stop();

    duckTimer = new QTimer();
    allTimers->addToList(duckTimer);
    connect(duckTimer, SIGNAL(timeout()), this, SLOT(duck()));
    duckTimer->start(1000/100);
}

void Dino::duck() {
    runTimer->stop();
    int random = rand() % 2 + 1;
    if (random == 1) {
       setImage(":/Image/dinoduck0000.png");
       setScale(2.4);
    } else if (random == 2) {
        setImage(":/Image/dinoduck0001.png");
        setScale(2.4);
    }
    setPos(x(), duckPosition);
}

void Dino::initJump() {
    if(!this->jumping){
        this->jumping = true;
        this->jumpprogress = 0;
        this->distance = 0.1;

        jumpTimer = new QTimer(this);
        allTimers->addToList(jumpTimer);
        connect(jumpTimer, SIGNAL(timeout()), this, SLOT(doJump()));

        jumpTimer->start(1000/120);
    }
}

void Dino::doJump() {
    double jump;
    runTimer->stop();
    if (duckTimer != nullptr) {
        duckTimer->stop();
    }
    setImage(":/Image/dinoJump0000.png");

    if  (this->jumpprogress >= 150){
        initRun();
        this->jumping = false;
        this->distance= 0.1;
        this->jumpprogress=1;
        jumpTimer->stop();
        return;
    }
    jump = pow(this->distance,(-1));
    this->jumpprogress++;

    if(jumpprogress < 75)
    {
        this -> distance= this->distance + 0.01;
        setPos(x(),y()-jump);
    }else if (jumpprogress > 75){
        this->distance=this->distance -0.01;
        if(y()+jump > baselineY){
            setPos(x(), baselineY);
        }else{
            setPos(x(),y()+jump);
        }
    }
}
