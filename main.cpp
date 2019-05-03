#include <QApplication>
#include "dino.h"
#include "cactus.h"
#include "scoreboard.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

/*

*/

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene

    //Dino * player = new Dino();
    //player->setRect(0,0,50,100); // change the rect from 0x0 (default) to 100x100 pixels

    Dino * player = new Dino(390);
    Scoreboard * scoreboard = new Scoreboard();

    //Floor "Rechteck" um Boden darszustellen. dieser braucht sich nicht uz bewegen.
    QGraphicsRectItem * floor = new QGraphicsRectItem();
    floor->setRect(0,0,1500,1);
    // add the item to the scene
    scene->addItem(player);
    scene->addItem(floor);
    scene->addItem(scoreboard->GetTextItem());
    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(1200,600);
    scene->setSceneRect(0,0,1200,600);


    player->setPos(view->width()-1100,view->height() - 200);
    floor->setPos(0,view->height() - 100);
    //Spawn Trails
   // player->TrailReworkedSpawn();
    //Spawn Cactus

    QTimer * trailTimer = new QTimer();
    QObject::connect(trailTimer, SIGNAL(timeout()), player, SLOT(spawnTrailRigth()));

    trailTimer->start(600);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawnCactus()));

    timer->start(3000);



    scoreboard->Start();
    return a.exec();
}
