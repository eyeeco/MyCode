#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QTimer>
class MyItem : public QGraphicsItem
{
public:
    MyItem(double x,double y,QColor color,int i);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void advance();
    QTimer timer;
    QColor color;
    int num;

};

#endif // MYITEM_H
