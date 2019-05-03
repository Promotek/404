#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "dino.h"
#include "scoreboard.h"

class Game: public QGraphicsView{
public:
    Game(QWidget *parent=nullptr);

    QGraphicsScene * scene;
    Dino * player;
    QGraphicsRectItem * floor;
};

#endif // GAME_H
