#ifndef GAME_H
#define GAME_H

#include "dino.h"
#include "scoreboard.h"
#include "trailspawner.h"
#include "obstacle.h"

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
    TrailSpawner *trailSpawner;
    Obstacle *obstacle;
};

#endif // GAME_H
