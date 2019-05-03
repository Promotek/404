#include "dino.h"
#include "trail_reworked.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <stdlib.h>


#include <QDebug>

    TrailReworked::TrailReworked() :QGraphicsRectItem(){
        if (rand()% 3 + 1 == 1){
        setRect(1200,530,rand()% 20 +1 ,3);
        }
        if (rand()% 3 + 1 == 2){
        setRect(1200,525,rand()% 20 +1 ,3);
        }
        if (rand()% 3 + 1 == 3){
        setRect(1200,520,rand()% 20 +1 ,3);
        }
        //scene()->addItem(this);
        QTimer * timer = new QTimer(this);
        Controller = timer;
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(1000/60);
        qDebug() << "returning from Constructor"<< rand()%10+1;
        return;
    }

    void TrailReworked::move(){
        // move to the left
        setPos(x()-4,y());
        //qDebug() <<"Trail Position b4 Delete : "<<pos().x()<<"\n";
        if (pos().x() <= -1000) {
            Controller->stop();
            scene()->removeItem(this);
            delete (this);
            //TrailReworked * newTrail = new TrailReworked();
            qDebug() <<"Deleted trail";
            //TrailTimer->start(200);
            return ;
            //qDebug() <<pos().x();
        }
        return;
    }

    void TrailReworked::TrailSpawn() {
        TrailReworked * Trail = new TrailReworked();
        //Controller = Trail;
        scene()->addItem(Trail);
        //qDebug()<<"Trailtimer stopped";
        //qDebug()<<"Trailtimer started";
    }

    void TrailReworked::TrailSlot() {
        QTimer * timer2 = new QTimer();
        TrailTimer = timer2;
        //timer2->setSingleShot(true);
        connect (timer2,SIGNAL(timeout()),this,SLOT(TrailSpawn()));
        timer2->start(250);
        qDebug()<<"Timer stopped";
    };



