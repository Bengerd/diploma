#include "graphicveiw.h"

graphicveiw::graphicveiw(QWidget *parent)
    : QGraphicsView(parent)
{

    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignLeft);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    /* Также зададим минимальные размеры виджета
     * */
    this->setMinimumHeight(m_width*50);
    this->setMinimumWidth(m_length*50);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет

    group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов

    scene->addItem(group_1);            // Добавляем первую группу в сцену

    timer = new QTimer();               // Инициализируем Таймер
    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);                   // Стартуем таймер на 50 миллисекунд

}

graphicveiw::~graphicveiw()
{

}

void graphicveiw::repaintScreen()
{
    /* Удаляем все элементы со сцены,
     * если они есть перед новой отрисовкой
     * */
    this->deleteItemsFromGroup(group_1);

    this->setMinimumHeight(m_width*50 + 100);
    this->setMinimumWidth(m_length*50 + 100);

    int width = this->width();      // определяем ширину виджета
    int height = this->height();    // определяем высоту виджета

    // Устанавливаем размер сцены по размеру виджета
    scene->setSceneRect(0,0,width,height);

    QPen penBlack(Qt::black); // Задаём чёрную кисть


    // Отрисовка комнаты сверху
    int roomLenght = m_length*50;
    int roomWidth = m_width*50;

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
}

void graphicveiw::slotAlarmTimer()
{
    repaintScreen();
}

/* Этим методом перехватываем событие изменения размера виджет
 * */
void graphicveiw::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
}



/* Метод для удаления всех элементов из группы
 * */
void graphicveiw::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    /* Перебираем все элементы сцены, и если они принадлежат группе,
     * переданной в метод, то удаляем их
     * */
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}

// Акссесор для установки значения длины
void graphicveiw::setLength(QString l)
{
    bool ok = true;
    m_length = l.toInt(&ok,10);
}

// Акссесор для установки значения ширины
void graphicveiw::setWidth(QString w)
{
    bool ok = true;
    m_width = w.toInt(&ok,10);
}
