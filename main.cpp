#include <QApplication>
#include "myrect.h"
#include <QGraphicsScene>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    MyRect * rect = new MyRect();
    rect->setRect(0, 0, 150, 150);

    scene->addItem(rect);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    QGraphicsView * view = new QGraphicsView();
    view->setScene(scene);

    view->show();

    return a.exec();
}
