#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtWidgets>
#include <QList>
#include <myitem.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void MainProcess(qreal m,qreal n,qreal k,qreal speed,qreal save);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QList<MyItem*> str;
    QList<qreal> vec;
    qreal wait = 0;
    qreal m;
    qreal n;
    qreal k;
    qreal speed =1000;
    qreal start =0;
    qreal terminate = 0;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered();
};



#endif // MAINWINDOW_H
