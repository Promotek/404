#ifndef DINO_H
#define DINO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QDialog>
#include <QKeyEvent>
#include <QTimer>

class Dino:public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    bool jumping = false;
    int jumpprogress;
    QTimer * timerPointer;
    float distance;

public:
    void keyPressEvent(QKeyEvent * event);
    void InitJump();

public slots:
    void spawnTrail();
    void DoJump();
    void spawnCactus();
};

#endif // Dino