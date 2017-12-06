#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QImage>
#include <QPalette>
#include <QBrush>
#include <QThread>


Game::Game(){

    //create welcome screen
    QPixmap pixmap(":/images/Splash_screen.png");
    QSplashScreen welcome(pixmap);
    welcome.show();
    QThread::sleep(4);

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1366,768); // make the scene 1366X768 instead of infinity by infinity (default)

    //set scene background
    setBackgroundBrush(QBrush(QImage(":/images/Wsu_Background.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1366,768);

    // create the player
    player = new Player();
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    QTimer * moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()),player,SLOT(move()));
    moveTimer->start(5);

    QTimer * shootTimer = new QTimer();
    QObject::connect(shootTimer, SIGNAL(timeout()),player,SLOT(shoot()));
    shootTimer->start(300);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}
