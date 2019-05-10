#include "scoreboard.h"
#include "game.h"

#include <QTimer>
#include <QLinearGradient>

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
    timerPointer->start(33);
}

QGraphicsTextItem *Scoreboard::getTextItem(){
    return this->textItem;
}

void Scoreboard::doTick(){
   /* if(ticker == 100){

        this->PointsByTick += 1;
        if(this->PointsByTick % 10 == 0){
            this->PointsByTick += 1;
        }
        this->ticker = 0;
    }*/

    if(this->points % 100 == 0){
        //Speedup Cactus movement
        this->moveSpeed += 1;
        if (this->moveSpeed >= 120) {
            this->moveSpeed = 120;
        }
        game->obstacle->setMoveSpeed(moveSpeed);
    }
    if (this->points >= 2000 && this->points % 2000 == 0) {
        game->isChangeColor = true;
        game->scene->setBackgroundBrush(Qt::black);
        game->floor->setPen(QPen(Qt::white));
        this->textItem->setDefaultTextColor(Qt::white);
    }
    if (this->points >= 3500 && this->points % 3500 == 0) {
        game->isChangeColor = false;
        game->scene->setBackgroundBrush(Qt::white);
        game->floor->setPen(QPen(Qt::black));
        this->textItem->setDefaultTextColor(Qt::black);
    }

    this->points += 1;

    this->textItem->setPlainText(QString().number(this->points));
    //this->ticker++;
}

int Scoreboard::getPoints() {
    return this->points;
}
