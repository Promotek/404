#ifndef DINO_H
#define DINO_H

#include "timerlist.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

class Dino:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    bool jumping = false;
    int jumpprogress;
    double distance;
    int baselineY;
    TimerList *allTimers;

public:
    Dino(int baselineY, QString location);
    void keyPressEvent(QKeyEvent * event);
    void InitJump();

    QTimer * timerPointer;

public slots:
    void DoJump();

};

#endif // Dino
