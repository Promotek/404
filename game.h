#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "cactusspawner.h"
#include "dino.h"
#include "scoreboard.h"
#include "trailspawner.h"

class Game: public QGraphicsView{

public:
    Game(QWidget *parent=nullptr);

    QGraphicsScene * scene;
    Dino * player;
    QGraphicsRectItem * floor;
    Scoreboard * scoreboard;
    CactusSpawner * cactusSpawner;
    TrailSpawner *trailSpawner;
};

#endif // GAME_H
