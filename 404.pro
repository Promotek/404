#-------------------------------------------------
#
# Project created by QtCreator 2019-04-29T15:30:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 404
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    bird.cpp \
    cactus.cpp \
    cloud.cpp \
    cloudspawner.cpp \
    dino.cpp \
    game.cpp \
    gameover.cpp \
    obstacle.cpp \
    scoreboard.cpp \
    timerlist.cpp \
    trail.cpp \
    trailspawner.cpp

HEADERS  += \
    bird.h \
    cactus.h \
    cloud.h \
    cloudspawner.h \
    dino.h \
    game.h \
    gameover.h \
    gameoverscreen.h \
    obstacle.h \
    scoreboard.h \
    timerlist.h \
    trail.h \
    trailspawner.h

FORMS    +=

RESOURCES += \
    imgages/image.qrc

DISTFILES +=
