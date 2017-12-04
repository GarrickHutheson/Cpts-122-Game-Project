#include "myrect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"

#include <qdebug.h>
void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setBrush(Qt::black);
        bullet->setPos(x()+this->rect().width()/2, y()-25);
        scene()->addItem(bullet);
    }
}
