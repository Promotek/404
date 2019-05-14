#include "gameover.h"
#include "game.h"

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPushButton>
#include <QFontDatabase>
#include <QIcon>


extern Game *game;

GameOver::GameOver(): QObject(), QGraphicsPixmapItem() {
    this->setLabel();
    this->setButton();
}

void GameOver::setButton() {
    button = new QPushButton();
    button->setGeometry(500, 250, 200, 75);
    button->setFlat(true);
    button->setIcon(QIcon(":/Image/reloadButton.png"));
    button->setIconSize(QSize(200, 75));
    button->setStyleSheet("background-color: rgba(0, 0, 0, 0%);");
    connect(button, SIGNAL(clicked()), this, SLOT(createNewGame()));
}

void GameOver::setLabel() {
    label = new QLabel();
    label->setStyleSheet("background-color: rgba(0, 0, 0, 0%)");
    label->setGeometry(410, 175, 400, 75);
    label->setFont(QFont("Times", 28));
    label->setPixmap(QPixmap(":/Image/gameover.png"));
}

QPushButton* GameOver::getButton() {
    return button;
}

QLabel* GameOver::getLabel() {
    return label;
}

void GameOver::createNewGame() {
    game->isChangeColor = false;
    game->createUI();
}
