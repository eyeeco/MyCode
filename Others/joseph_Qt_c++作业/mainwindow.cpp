#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myitem.h"
#include <QMouseEvent>
#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QList>
#include <QTime>
#include <QFile>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);

    while(QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_pushButton_clicked()
{
    if(start){

        terminate = 1;

    }else{
        terminate = 0;
        start = 1;
        ui->pushButton->setText("终止");
        MainProcess(ui->spinBox->value(),ui->spinBox_2->value(),ui->spinBox_3->value(),ui->spinBox_4->value(),0);
        start = 0;
        ui->pushButton->setText("开始");
    }

}
void MainWindow::MainProcess(qreal m,qreal n,qreal k,qreal speed,qreal save){

    view->close();
    scene->clear();
    str.clear();
    ui->textBrowser->clear();

    view = new QGraphicsView;
    scene = new QGraphicsScene;
    double r = 300.0;
    for(qreal i=0;i<m;i++){
        double theta = (double)i * 2 * 3.1415 / m ;
        MyItem *item = new MyItem(r*cos(theta),r*sin(theta),Qt::white,i);
        scene->addItem(item);
        str.append(item);
        item->num = i;
    }

    // 视图
    // 视图关联场景
    view->setScene(scene);
    view->resize(800,800);
    view->show();

    qreal temp = n;
    qreal count =k;

    if(save){
        while(str.size()!=0){
            count--;
            if(count>0){
                str[temp]->color = Qt::red ;
                str[temp]->update();
            }else{

                count = k;
                if(str[temp]->num == save){
                    break;
                }

                str[temp]->color = Qt::blue ;
                str[temp]->update();
                QString strings=QString::number(str[temp]->num);
                ui->textBrowser->append(strings);
                str.removeAt(temp);
                temp--;


            }

            if(temp>=str.size()-1){
                temp =0;
            }else{
                temp++;
            }
        }
    }

    while(str.size()!=0){

        sleep(speed);
        count--;
        if(count!=0){
            str[temp]->color = Qt::red ;
            str[temp]->update();
        }else{
            count = k;
            str[temp]->color = Qt::blue ;
            str[temp]->update();
            QString strings=QString::number(str[temp]->num);
            ui->textBrowser->append(strings);

            str.removeAt(temp);
            temp--;
        }

        if(temp>=str.size()-1){
            temp =0;
        }else{
            temp++;
        }

        while(wait){
            sleep(1000);
        }

        if(terminate){
            break;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    wait = 1;
}

void MainWindow::on_pushButton_3_clicked()
{
    wait = 0;
}

void MainWindow::on_action_triggered()
{
    QFile data("file.txt");
    if (data.open(QFile::WriteOnly | QIODevice::Truncate|QIODevice::Text)) {
        QTextStream out(&data);
        QString strings = ui->textBrowser->toPlainText();
        out << ui->spinBox->value() << endl;
        out << ui->spinBox_2->value() << endl;
        out << ui->spinBox_3->value() << endl;
        out << ui->spinBox_4->value() << endl;

        out << strings;
    }
    data.close();
}

void MainWindow::on_action_2_triggered()
{
    if(start==0){
    QFile file("file.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        QString str(line);
        vec.append(str.toInt());
    }
    file.close();

    terminate = 0;
    start = 1;
    ui->pushButton->setText("终止");
    ui->spinBox->setValue(vec[0]);
    ui->spinBox_2->setValue(vec[1]);
    ui->spinBox_3->setValue(vec[2]);
    ui->spinBox_4->setValue(vec[3]);
    MainProcess(vec[0],vec[1],vec[2],vec[3],vec.back());

    start = 0;
    ui->pushButton->setText("开始");
    }
}

void MainWindow::on_action_3_triggered()
{
    QPixmap p = view->grab();
    p.save(QCoreApplication::applicationDirPath()+"//save.png","png");
}
