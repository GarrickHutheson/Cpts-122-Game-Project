#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    bool left;
    bool right;
    bool up;
    bool down;
    bool shooting;
public slots:
    void spawn();
    void move();
    void shoot();

};

#endif // PLAYER_H
