#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>

#include <QDebug>
Bullet::Bullet()
{
        //drew the rect
        setRect(0,0, 3, 18);
        //connect
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(20);
}

void Bullet::move()
{
    //handle bullet enemy
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for (int i = 0, n = colliding_items.size(); i <n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }




    setPos(x(), y()-15);
    if(pos().y() + rect().height() < 0){
       scene()->removeItem(this);
       delete this;
       //qDebug() << "BULLET GONE!";
    }
}
