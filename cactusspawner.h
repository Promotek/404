#ifndef CACTUSSPAWNER_H
#define CACTUSSPAWNER_H

#include "scoreboard.h"

#include <QGraphicsScene>
#include <QTimer>

class CactusSpawner: public QObject
{
    Q_OBJECT
private:
    Scoreboard * scoreboard;
    QGraphicsScene * scene;
public:
    CactusSpawner(QGraphicsScene * scene, Scoreboard * scoreboard);
public slots:
    void spawnCactus();
};

#endif // CACTUSSPAWNER_H
