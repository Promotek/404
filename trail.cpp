#include "dino.h"
#include "trail.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>

//#include <QDebug>

    Trail::Trail() :QGraphicsRectItem(){
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
//Function to Spawn trails on diffrent kind of levels. Here we have 3 levels
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
//Timer to Loop the Spawning of the 3 Trails
    void Trail::spawnLine() {
        QTimer * gap1 = new QTimer();
        connect(gap1,SIGNAL(timeout()),this,SLOT(slot_create()));
        gap1->start(750);
    }
//function to invoke the Function TailCreate in Order to properly get the timer working ...
    void Trail::slot_create() {
        TrailCreate(1);
        TrailCreate(2);
        TrailCreate(3);
    }


