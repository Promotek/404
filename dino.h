#ifndef DINO_H
#define DINO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

class Dino:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    bool jumping = false;


    int jumpprogress;
    QTimer * timerPointer;
    double distance;
    int baselineY;


public:
    Dino(int baselineY);
    void keyPressEvent(QKeyEvent * event);
    void InitJump();

public slots:
    void spawnTrail();
    void DoJump();
    void spawnCactus();
};

#endif // Dino
