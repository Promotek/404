#ifndef CLOUD_H
#define CLOUD_H

#include "timerlist.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Cloud: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

private:
    QTimer *timer;
    TimerList *allTimers;

public:
    Cloud(int y);

public slots:
    void move();
};

#endif // CLOUD_H
