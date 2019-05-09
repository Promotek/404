#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "timerlist.h"

#include <QGraphicsRectItem>
#include <QLabel>

class Scoreboard :public QObject
{
    Q_OBJECT
private:
    int points;
    QTimer * timerPointer;
    QGraphicsTextItem * textItem;
    int ticker;
    double moveSpeed;
    TimerList *allTimers;
    int PointsByTick;
public:

    Scoreboard(double moveSpeed = 1);
    void start();
    QGraphicsTextItem *getTextItem();
    double getMoveSpeed();

public slots:
    void doTick();

};

#endif // SCOREBOARD_H
