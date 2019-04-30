#include "dino.h"
#include "trail.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

//#include <QDebug>

    Trail::Trail() {
        setRect(765,550,10,10);
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(1000/60);
    }

    void Trail::move(){
        // move to the left
        setPos(x()-2,y());
//        qDebug() <<"Trail Position b4 Delete : "<<pos().x()<<"\n";
        if (pos().x() <= -1500){
            //scene()->removeItem(this);


        }
    }

    void Trail::TrailCreate(int level) {
        if (level == 1) {
            Trail * trail1 = new Trail();
            setRect(660,550,10,10);
            scene()->addItem(trail1);
        }
        if (level == 2) {
            Trail * trail2 = new Trail();
            trail2->setRect(800,530,10,10);
            scene()->addItem(trail2);
        } else if (level == 3) {
            Trail * trail3 = new Trail();
            scene()->addItem(trail3);
            trail3->setRect(730,540,10,10);
        }
    }

    void Trail::spawnLine() {
        QTimer * gap1 = new QTimer();
        connect(gap1,SIGNAL(timeout()),this,SLOT(slot_create()));
        gap1->start(750);
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


