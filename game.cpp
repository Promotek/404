#include "game.h"
#include <QApplication>
#include "cactus.h"
#include "dino.h"
#include "scoreboard.h"
#include "timerlist.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>

Game::Game(){
   createUI();
}

void Game::createUI() {
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);

    startGame();

    show();
}

void Game::startGame() {
    // create a Dino
    player = new Dino(400);
    this->scoreboard = new Scoreboard(15);

    //Floor "Rechteck" um Boden darszustellen. dieser braucht sich nicht zu bewegen.
    floor = new QGraphicsRectItem();
    floor->setRect(0,0,1500,1);

    // add items to the scene
    scene->addItem(player);
    scene->addItem(floor);
    scene->addItem(this->scoreboard->getTextItem());

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // set players and floor position
    player->setPos(width()-1100,height() - 200);
    floor->setPos(0,this->height() - 130);

    this->scoreboard->start();

    //Spawn Trails
    this->trailSpawner = new TrailSpawner(this->scene);

    //Spawn Obstacle
    this->obstacle = new Obstacle(this->scoreboard->getMoveSpeed(), scene);

    //Spawn Clouds
    this->cloudSpawner = new CloudSpawner();
}


