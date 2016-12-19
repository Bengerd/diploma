#include "roompicture.h"

roompicture::roompicture(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignLeft);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    this->setMinimumHeight(200);
    this->setMinimumWidth(200);

    scene = new QGraphicsScene();

    group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
    scene->addItem(group_1);            // Добавляем первую группу в сцену

    int width = this->width();      // определяем ширину виджета
    int height = this->height();    // определяем высоту виджета

    // Устанавливаем размер сцены по размеру виджета
    scene->setSceneRect(0,0,width,height);

    QPen penBlack(Qt::black); // Задаём чёрную кисть

    int roomLenght = width - 40;
    int roomWidth = height - 40;

    int centerOfWidget_X = width/2;
    int centerOfWidget_Y = height/2;

    group_1->addToGroup(scene->addLine(centerOfWidget_X - (roomLenght/2),
                                       centerOfWidget_Y - (roomWidth/2),
                                       centerOfWidget_X + (roomLenght/2),
                                       centerOfWidget_Y - (roomWidth/2),
                                       penBlack));

    group_1->addToGroup(scene->addLine(centerOfWidget_X + (roomLenght/2),
                                       centerOfWidget_Y - (roomWidth/2),
                                       centerOfWidget_X + (roomLenght/2),
                                       centerOfWidget_Y + (roomWidth/2),
                                       penBlack));

    group_1->addToGroup(scene->addLine(centerOfWidget_X + (roomLenght/2),
                                       centerOfWidget_Y + (roomWidth/2),
                                       centerOfWidget_X - (roomLenght/2),
                                       centerOfWidget_Y + (roomWidth/2),
                                       penBlack));

    group_1->addToGroup(scene->addLine(centerOfWidget_X - (roomLenght/2),
                                       centerOfWidget_Y + (roomWidth/2),
                                       centerOfWidget_X - (roomLenght/2),
                                       centerOfWidget_Y - (roomWidth/2),
                                       penBlack));

    this->setScene(scene);
}

roompicture::~roompicture()
{
    this->deleteItemsFromGroup(group_1);
}

roompicture::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}
