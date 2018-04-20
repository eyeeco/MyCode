#include <myitem.h>
#include <QPainter>
#include <QCursor>
#include <QDialog>
MyItem::MyItem(double x, double y,QColor col,int i)
{
    setPos(x, y);
    color = col;
    num = i;
}
QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void MyItem::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);

    QRectF ff(0,0,50,50);
    QFont font("Arial",20,QFont::Bold,true);
    QString strings=QString::number(num);
    painter->setFont(font);
    painter->setBrush(color);
    painter->drawEllipse(0,0,50,50);
    painter->drawText(ff,Qt::AlignCenter,strings);
}

void MyItem::advance()
{


}
