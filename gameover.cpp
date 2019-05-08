#include "gameover.h"
#include "game.h"

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPushButton>
#include <QFontDatabase>


extern Game *game;

GameOver::GameOver(): QObject(), QGraphicsPixmapItem() {
    this->setLabel();
    this->setButton();
}

void GameOver::setButton() {
    button = new QPushButton;
    //TODO change Icon, use reload button instead
    button->setIcon(QIcon(":/Image/bird2.png"));
    button->setGeometry(500, 250, 200, 75);
    button->setFocus();
    connect(button, SIGNAL(clicked()), this, SLOT(createNewGame()));
}

void GameOver::setLabel() {
    label = new QLabel();
    label->setStyleSheet("background-color: rgb(255, 255, 255);");
    label->setGeometry(510, 175, 200, 75);
    label->setFont(QFont("Times", 28));
    label->setText("Game Over");
}

QPushButton* GameOver::getButton() {
    return button;
}

QLabel* GameOver::getLabel() {
    return label;
}

void GameOver::createNewGame() {
    game->createUI();
}
