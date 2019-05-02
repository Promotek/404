#ifndef DINO_H
#define DINO_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QDialog>
#include <QKeyEvent>
#include <QTimer>

class Dino:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    bool jumping = false;
    int jumpprogress;
    QTimer * timerPointer;
    float distance;
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
