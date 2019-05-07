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
public:
    int GetMoveSpeed();
    int PointsByTick;
    void Start();
    Scoreboard(int moveSpeed = 1);
    QGraphicsTextItem *GetTextItem();

public slots:
    void DoTick();

};

#endif // SCOREBOARD_H
