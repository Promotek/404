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
    int moveSpeed;
    TimerList *allTimers;
    int PointsByTick;
public:

    Scoreboard(int moveSpeed = 1);
    void start();
    QGraphicsTextItem *getTextItem();
    int getMoveSpeed();

public slots:
    void doTick();

};

#endif // SCOREBOARD_H
