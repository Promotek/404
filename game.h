#ifndef GAME_H
#define GAME_H

#include "cactusspawner.h"
#include "dino.h"
#include "scoreboard.h"
#include "trailspawner.h"
#include "birdspawner.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

class Game: public QGraphicsView{

public:
    Game();
    void startGame();
    void createUI();

    QGraphicsScene * scene;
    Dino * player;
    QGraphicsRectItem * floor;
    Scoreboard * scoreboard;
    CactusSpawner * cactusSpawner;
    TrailSpawner *trailSpawner;
    BirdSpawner *birdSpawner;
};

#endif // GAME_H
