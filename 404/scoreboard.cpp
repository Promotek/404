#include "scoreboard.h"
#include "game.h"

#include <QTimer>

extern Game *game;

Scoreboard::Scoreboard(double moveSpeed){
    this->textItem = new QGraphicsTextItem();
    this->textItem->setPos(10,10);
    this->points = 0;
    this->PointsByTick = 1;
    this->ticker = 0;
    this->textItem->setFont(QFont("Times", 28, QFont::Bold));
    this->moveSpeed = moveSpeed;
}

double Scoreboard::getMoveSpeed() {
    return this->moveSpeed;
}

void Scoreboard::start(){
    this->timerPointer = new QTimer(this);
    allTimers->addToList(timerPointer);
    connect(this->timerPointer, &QTimer::timeout, this, &Scoreboard::doTick);
    timerPointer->start(1000/30);
}

QGraphicsTextItem *Scoreboard::getTextItem(){
    return this->textItem;
}

void Scoreboard::doTick(){
    if(ticker == 100){

        this->PointsByTick += 1;
        if(this->PointsByTick % 10 == 0){
            this->PointsByTick += 1;
        }
        this->ticker = 0;
    }

    if(this->points% 100 == 0){
        //Speedup Cactus movement
        this->moveSpeed += 1;
        if (this->moveSpeed >= 120) {
            this->moveSpeed = 120;
        }
        game->obstacle->setMoveSpeed(moveSpeed);
    }

    this->points += this->PointsByTick;

    this->textItem->setPlainText(QString().number(this->points));
    this->ticker++;
}
