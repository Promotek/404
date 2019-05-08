#include "game.h"
#include <QApplication>
#include "cactus.h"
#include "dino.h"
#include "scoreboard.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>

#include "timerlist.h"

Game::Game(){
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);

    // create a Dino
    player = new Dino(390);
    this->scoreboard = new Scoreboard(7);

    //Floor "Rechteck" um Boden darszustellen. dieser braucht sich nicht zu bewegen.
    floor = new QGraphicsRectItem();
    floor->setRect(0,0,1500,1);

    // add items to the scene
    scene->addItem(player);
    scene->addItem(floor);
    scene->addItem(this->scoreboard->GetTextItem());

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // set players and floor position
    player->setPos(width()-1100,height() - 200);
    floor->setPos(0,this->height() - 100);

    //Spawn Trails
    this->trailSpawner = new TrailSpawner(this->scene);

    //Spawn Cactus
    this->cactusSpawner = new CactusSpawner(this->scene, this->scoreboard);

    this->scoreboard->Start();

    show();
}


