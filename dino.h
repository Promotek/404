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
    bool ducking = false;
    int jumpprogress;
    double distance;
    int duckPosition;
    int runCounter;
    int duckCounter;
    QString runPath1;
    QString runPath2;
    QString jumpPath;
    QString duckPath1;
    QString duckPath2;
    TimerList *allTimers;
    QTimer *runTimer;
    QTimer *duckTimer;

public:
    int baselineY;

    Dino(int baselineY);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void initJump();
    void setImage(QString path);
    void initRun();
    void initDuck();
    void setPosition(qreal x, qreal y);

    QTimer * timerPointer;

public slots:
    void doJump();
    void run();
    void duck();
};

#endif // Dino
