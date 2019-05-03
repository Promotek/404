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
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(1000/60);
    }

    void TrailReworked::move(){
        // move to the left
        setPos(x()-4,y());
//        qDebug() <<"Trail Position b4 Delete : "<<pos().x()<<"\n";
        if (pos().x() <= -1500){
            qDebug() <<"Position out of bounds delete->";
            delete (this);
            qDebug() <<"Returning";
            qDebug() <<rand()% 10 +1 <<"Still in progress tho";
            return;

            //scene()->removeItem(this);
        }
    }

    void TrailReworked::TrailSpawn() {
        TrailReworked * Trail = new TrailReworked();
        scene()->addItem(Trail);
        if (this->pos().x() <= -1000) {
            qDebug() <<"First Object out of Bounds stopping Timer";
            TrailTimer->stop();
            qDebug() <<"Timer stopped -> restarting timer";
            //TrailTimer->start();
            TrailSlot();
            qDebug() <<"TrailSlot started";
        }
    }

    void TrailReworked::TrailSlot() {
        QTimer * timer2 = new QTimer();
        TrailTimer = timer2;
        connect (timer2,SIGNAL(timeout()),this,SLOT(TrailSpawn()));
        timer2->start(250);
    };



