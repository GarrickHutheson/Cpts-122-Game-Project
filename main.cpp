#include <QApplication>
#include "myrect.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    MyRect * player = new MyRect();
    player->setRect(0, 0, 80, 80);
    player->setBrush((Qt::yellow));

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView * view = new QGraphicsView();

    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setScene(scene);

    player->setPos((view->width()/2),(view->height() - player->rect().height() - 10 ));

    view->show();

    return a.exec();
}
