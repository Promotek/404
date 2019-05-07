#ifndef GAME_H
#define GAME_H

#include "cactusspawner.h"
#include "dino.h"
#include "scoreboard.h"
#include "trailspawner.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

class Game: public QGraphicsView{

public:
    Game();

    QGraphicsScene * scene;
    Dino * player;
    QGraphicsRectItem * floor;
    Scoreboard * scoreboard;
    CactusSpawner * cactusSpawner;
    TrailSpawner *trailSpawner;
};

#endif // GAME_H
