#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>

Player::Player(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent) {
setPixmap(QPixmap(":/images/Andy.png"));
left = false;
right = false;
up = false;
down = false;
shooting = false;
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_A){
        left = true;
    }
    else if (event->key() == (Qt::Key_D)){
        right = true;
    }

    else if (event->key() == (Qt::Key_W)){
        up = true;
    }
    else if (event->key() == (Qt::Key_S)){
        down = true;
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        shooting = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_A){
        left = false;
    }
    else if (event->key() == (Qt::Key_D)){
        right = false;
    }

    else if (event->key() == (Qt::Key_W)){
        up = false;
    }
    else if (event->key() == (Qt::Key_S)){
        down = false;
    }

    if (event->key() == Qt::Key_Space){
        shooting = false;
    }
}



void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::move()
{
    //qDebug() << "In Player::move()";
    if (left == true){
        if (pos().x() > 0)
            setPos(x()-1.5,y());
    }
    if (right == true){
        if (pos().x() + 100 < scene()->width())
         setPos(x()+1.5,y());
    }

    if (up == true){
        if (pos().y() > 0)
         setPos(x(),y()-1.5);
    }
    if (down == true){
        if (pos().y() + this->pixmap().height() < scene()->height())
            setPos(x(),y()+1.5);
    }
}

void Player::shoot()
{
    if(shooting == true){
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + pixmap().width()/2 -6, y() + 120);
        scene()->addItem(bullet);
    }
}
