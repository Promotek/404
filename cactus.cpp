#include "dino.h"
#include "cactus.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

Cactus::Cactus() : QGraphicsPixmapItem(){
    setPixmap(QPixmap(":/Image/cactusBig0000.png"));
    setScale(0.70);
    setPos(1300,420);
    QTimer * CactusMove= new QTimer(this);
    connect(CactusMove,SIGNAL(timeout()),this,SLOT(move()));
    CactusMove->start(1000/60);
}
//Simple Move Function
void Cactus::move(){
    // move to the left
    if (pos().x() <= -1000) {
        //setPos(790,400);
        //SpawnTimer->stop();
        //delete (this);
        //SpawnTimer->start(1000);
        //Cactus * newCactus = new Cactus();
        //scene()->addItem(newCactus);
    }
    setPos(x()-3,y());
}
//Create a Series of Cacti that spawn 1 time per sec
void Cactus::spawn() {
    QTimer * SpawnCactus = new QTimer();
    connect(SpawnCactus,SIGNAL(timeout()),this,SLOT(CreateCactus()));
    SpawnCactus->start(1000);
}
//Create a new cactus which moves to the left
void Cactus::CreateCactus() {
    Cactus * cactus = new Cactus();
    scene()->addItem(cactus);
}
