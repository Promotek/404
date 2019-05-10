#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>

class GameOver: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    QPushButton *button;
    QLabel *label;

    GameOver();
    void setButton();
    void setLabel();
    QPushButton* getButton();
    QLabel *getLabel();
public slots:
    void createNewGame();
};

#endif // GAMEOVER_H
