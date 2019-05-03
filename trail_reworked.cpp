#include "dino.h"
#include "trail_reworked.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>

//#include <QDebug>

    TrailReworked::TrailReworked() :QGraphicsRectItem(){
        setRect(765,550,10,10);
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(1000/60);
    }

    void TrailReworked::move(){
        // move to the left
        setPos(x()-2,y());
//        qDebug() <<"Trail Position b4 Delete : "<<pos().x()<<"\n";
        if (pos().x() <= -1500){
            //scene()->removeItem(this);
        }
    }




