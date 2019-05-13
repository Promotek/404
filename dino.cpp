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

void Dino::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Up){
        this->initJump();
    } else if (event->key() == Qt::Key_Down) {
        this->initDuck();
    }
}

void Dino::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Down) {
        if (!jumping && ducking) {
            duckTimer->stop();
            ducking = false;
            this->initRun();
        }
    }
}

void Dino::initRun() {
    runTimer = new QTimer();
    allTimers->addToList(runTimer);
    connect(runTimer, SIGNAL(timeout()), this, SLOT(run()));
    runTimer->start(80);
}

void Dino::run() {
    if (game->isChangeColor) {
        runPath1 = ":/Image/dinorunNegative0000.png";
        runPath2 = ":/Image/dinorunNegative0001.png";
    } else {
        runPath1 = ":/Image/dinorun0000.png";
        runPath2 = ":/Image/dinorun0001.png";
    }
    if (runCounter % 2 == 0) {
        setImage(runPath1);
    } else {
        setImage(runPath2);
    }
    runCounter++;
    setPosition(x(), baselineY);
}

void Dino::setImage(QString path){
    setPixmap(QPixmap(path));
    setScale(4);
}

void Dino::setPosition(qreal x, qreal y) {
    setPos(x, y);
}

void Dino::initDuck() {
    if (!jumping) {
    runTimer->stop();

    ducking = true;
    duckTimer = new QTimer();
    allTimers->addToList(duckTimer);
    connect(duckTimer, SIGNAL(timeout()), this, SLOT(duck()));
    duckTimer->start(80);
    }
}

void Dino::duck() {
    if (game->isChangeColor) {
        duckPath1 = ":/Image/dinoduckNegative0000.png";
        duckPath2 = ":/Image/dinoduckNegative0001.png";
    } else {
        duckPath1 = ":/Image/dinoduck0000.png";
        duckPath2 = ":/Image/dinoduck0001.png";
    }
    if (duckCounter % 2 == 0) {
       setImage(duckPath1);
       setScale(2.4);
    } else {
        setImage(duckPath2);
        setScale(2.4);
    }
    duckCounter++;
    setPosition(x(), duckPosition);
}

void Dino::initJump() {
    if(!this->ducking && !this->jumping){
        this->jumping = true;
        this->jumpprogress = 0;
        this->distance = 0.1;

        timerPointer = new QTimer(this);
        allTimers->addToList(timerPointer);
        connect(timerPointer, SIGNAL(timeout()), this, SLOT(doJump()));

        timerPointer->start(1000/120);
    }
}

void Dino::doJump() {
    double jump;
    runTimer->stop();
    if (game->isChangeColor) {
        jumpPath = ":/Image/dinoJumpNegative0000.png";
    } else {
        jumpPath = ":/Image/dinoJump0000.png";
    }
    setImage(jumpPath);

    if  (this->jumpprogress >= 150){
        initRun();
        this->jumping = false;
        this->distance= 0.1;
        this->jumpprogress=1;
        timerPointer->stop();
        return;
    }
    jump = pow(this->distance,(-1));
    this->jumpprogress++;

    if(jumpprogress < 75)
    {
        this -> distance= this->distance + 0.01;
        setPosition(x(),y()-jump);
    }else if (jumpprogress > 75){
        this->distance=this->distance -0.01;
        if(y()+jump > baselineY){
            setPosition(x(), baselineY);
        }else{
            setPosition(x(),y()+jump);
        }
    }
}
