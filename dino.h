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
    int duckPosition;
    TimerList *allTimers;
    QTimer * jumpTimer;
    QTimer *runTimer;
    QTimer *duckTimer;

    void initJump();
    void initRun();
    void initDuck();

public:
    Dino(int baselineY);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void setImage(QString path);

public slots:
    void doJump();
    void run();
    void duck();
};

#endif // Dino
