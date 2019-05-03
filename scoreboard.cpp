#include "scoreboard.h"

#include <QTimer>
#include <iostream>

void Scoreboard::Start()
{
    this->timerPointer = new QTimer(this);

    connect(this->timerPointer, &QTimer::timeout, this, &Scoreboard::DoTick);
    timerPointer->start(1000/30);
}

Scoreboard::Scoreboard()
{
    this->textItem = new QGraphicsTextItem();
    this->textItem->setPos(10,10);
    this->points = 0;
    this->PointsByTick = 1;
    this->ticker = 0;
    this->textItem->setFont(QFont("Times", 28, QFont::Bold));
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
    this->points += this->PointsByTick;
    //std::cout << "Punkte "  << this->points << std::endl;

    this->textItem->setPlainText(QString().number(this->points));
    this->ticker++;
}
