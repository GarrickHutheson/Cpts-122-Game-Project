#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMouseEvent>


class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
public slots:
    void spawn();
    void move();
private:
    bool left;
    bool right;
    bool up;
    bool down;
    bool shooting;
};

#endif // PLAYER_H
