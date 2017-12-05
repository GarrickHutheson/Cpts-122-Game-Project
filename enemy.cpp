#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <typeinfo>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 1266;
    setPos(random_number,0);

    // drew the enemy
    setPixmap(QPixmap(":/images/javaCup.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){


    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            // increase the score
            game->health->decrease();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existant enemy)
            return;
        }
    }
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > scene()->height() - pixmap().height()){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
