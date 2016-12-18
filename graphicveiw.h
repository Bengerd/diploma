#ifndef GRAPHICVEIW_H
#define GRAPHICVEIW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QString>

class graphicveiw : public QGraphicsView
{
    Q_OBJECT
    public:
        explicit graphicveiw(QWidget *parent = 0);
        ~graphicveiw();

    // Аксессоры
    void setLength(QString l);          // Акссесор для установки значения длины
    void setWidth(QString w);           // Акссесор для установки значения ширины

    void repaintScreen();               // Функция перерисовки виджета


    signals:

    public slots:
        void slotAlarmTimer();  /* слот для обработчика переполнения таймера
                                 * в нём будет производиться перерисовка
                                 * виджета
                                 * */

    private:
        int m_length = 6;               // Объявляем длину комнаты
        int m_width = 6;                // Объявляем ширину комнаты
        QGraphicsScene      *scene;     // Объявляем сцену для отрисовки
        QGraphicsItemGroup  *group_1;   // Объявляем первую группу элементов
        QTimer              *timer;     // Объявляем таймер для задержки отрисовки

    private:
        /* Перегружаем событие изменения размера окна,
         * чтобы перехватывать его
         * */
        void resizeEvent(QResizeEvent *event);
        /* Метод для удаления всех элементов
         * из группы элементов
         * */
        void deleteItemsFromGroup(QGraphicsItemGroup *group_1);

    };

#endif // GRAPHICVEIW_H
