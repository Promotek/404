#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>

class GameOver: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

private:
    QPushButton *button;
    QLabel *label;
    void setButton();
    void setLabel();

public:
    GameOver();
    QPushButton* getButton();
    QLabel *getLabel();

public slots:
    void createNewGame();
};

#endif // GAMEOVER_H
