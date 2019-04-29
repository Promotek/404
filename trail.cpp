#include "dino.h"
#include "trail.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include <QDebug>

    Trail::Trail() {
        setRect(765,550,10,10);
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(1000/60);
    }

    void Trail::move(){
        // move to the left
        setPos(x()-2,y());
        /*if (pos().x() + rect().width() < 0){
            scene()->removeItem(this);
            delete this;
        }*/
    }

    void Trail::TrailCreate(int level) {
        if (level == 1) {
            Trail * trail = new Trail();
            scene()->addItem(trail);
            setRect(765,550,10,10);
            QTimer * timer = new QTimer(this);
            connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(1000/60);
        } else if (level == 2) {
            Trail * trail = new Trail();
            scene()->addItem(trail);
            setRect(765,530,10,10);
            QTimer * timer = new QTimer(this);
            connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(1000/60);
        } else if (level == 3) {
            Trail * trail = new Trail();
            scene()->addItem(trail);
            setRect(765,540,10,10);
            QTimer * timer = new QTimer(this);
            connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(1000/60);
        }
    }

    void Trail::spawnLine() {
        QTimer * gap1 = new QTimer();
        connect(gap1,SIGNAL(timeout()),this,SLOT(slot_create()));
        gap1->start(2000);
       /* QTimer * gap2 = new QTimer();
        connect(gap2,SIGNAL(timeout()),this,SLOT(slot_create(2)));
        gap2->start(2000);
        QTimer * gap3 = new QTimer();
        connect(gap3,SIGNAL(timeout()),this,SLOT(slot_create(3)));
        gap3->start(2000);*/
    }

    void Trail::slot_create() {
        TrailCreate(1);
        TrailCreate(2);
        TrailCreate(3);
    }


