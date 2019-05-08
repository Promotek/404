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
    QTimer *runTimer;

public:
    Dino(int baselineY);
    void keyPressEvent(QKeyEvent * event);
    void initJump();
    void setImage(QString path);
    void initRun();

    QTimer * timerPointer;

public slots:
    void doJump();
    void run();
};

#endif // Dino
