#include "gameover.h"
#include "game.h"

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPushButton>
#include <QFontDatabase>

GameOver::GameOver(): QObject(), QGraphicsPixmapItem() {
    this->setLabel();
    this->setButton();
}

void GameOver::setButton() {
    button = new QPushButton;
    //TODO change Icon, use reload button instead and set position to mid of x
    button->setIcon(QIcon(":/Image/bird2.png"));
    button->setGeometry(550, 300, 100, 75);
    button->setFocus();
    connect(button, SIGNAL(clicked()), this, SLOT(createNewGame()));
}

void GameOver::setLabel() {
    label = new QLabel();
    //TODO set position to mid of x
    label->setFont(QFont("Times", 22));
    label->setGeometry(500, 200, 150, 75);
    label->setText("Game Over");
}

QPushButton* GameOver::getButton() {
    return button;
}

QLabel* GameOver::getLabel() {
    return label;
}

void GameOver::createNewGame() {
    Game *game = new Game();
    game->show();
}
