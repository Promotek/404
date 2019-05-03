#include "game.h"
#include <QApplication>
#include "dino.h"
#include "scoreboard.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>

Game::Game(QWidget *parent){
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);

    // create a Dino
    player = new Dino(390);
    Scoreboard * scoreboard = new Scoreboard();

    //Floor "Rechteck" um Boden darszustellen. dieser braucht sich nicht uz bewegen.
    floor = new QGraphicsRectItem();
    floor->setRect(0,0,1500,1);

    // add items to the scene
    scene->addItem(player);
    scene->addItem(floor);
    scene->addItem(scoreboard->GetTextItem());

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // set players and floor position
    player->setPos(width()-1100,height() - 200);
    floor->setPos(0,this->height() - 100);

    //Spawn Trails
    QTimer * trailTimer = new QTimer();
    QObject::connect(trailTimer, SIGNAL(timeout()), player, SLOT(spawnTrail()));

    trailTimer->start(600);

    //Spawn Cactus
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawnCactus()));

    timer->start(3000);

    scoreboard->Start();

    show();
}
