#include "scoreboard.h"

#include <QTimer>
#include <iostream>

int Scoreboard::GetMoveSpeed()
{
    return this->moveSpeed;
}

void Scoreboard::Start()
{
    this->timerPointer = new QTimer(this);

    connect(this->timerPointer, &QTimer::timeout, this, &Scoreboard::DoTick);
    timerPointer->start(1000/30);
}

Scoreboard::Scoreboard(int moveSpeed)
{
    this->textItem = new QGraphicsTextItem();
    this->textItem->setPos(10,10);
    this->points = 0;
    this->PointsByTick = 1;
    this->ticker = 0;
    this->textItem->setFont(QFont("Times", 28, QFont::Bold));
    this->moveSpeed = moveSpeed;
}

QGraphicsTextItem *Scoreboard::GetTextItem()
{
    return this->textItem;
}

void Scoreboard::DoTick()
{
    if(ticker == 100){

        this->PointsByTick += 1;
        if(this->PointsByTick % 10 == 0){
            this->PointsByTick += 1;
        }
        this->ticker = 0;
    }

    if(this->points%400 == 0){
        //Speedup Cactus movement
        this->moveSpeed += 1;
    }

    this->points += this->PointsByTick;

    this->textItem->setPlainText(QString().number(this->points));
    this->ticker++;
}
