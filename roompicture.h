#ifndef ROOMPICTURE_H
#define ROOMPICTURE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItemGroup>

class roompicture: public QGraphicsView
{
    Q_OBJECT
    public:
        explicit roompicture(QWidget *parent = 0);
        ~roompicture();

    private:
        QGraphicsScene *scene;
        QPixmap *pix;
        QGraphicsItemGroup  *group_1;

    private:
        deleteItemsFromGroup(QGraphicsItemGroup *group);
};

#endif // ROOMPICTURE_H
