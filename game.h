#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include <QSplashScreen>

class Game: public QGraphicsView{
public:
    Game();

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    //Spawner * spawner;

};

#endif // GAME_H
