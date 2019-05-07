#ifndef TRAIL_H
#define TRAIL_H

#include "timerlist.h"

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>

class Trail: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    QTimer *moveTimer;
    TimerList *allTimers;

    Trail(int xPosition, int yPosition);

public slots:
    void move();
};

#endif // TRAIL_H
