#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::mousePressEvent(QMouseEvent* obj)
{
    //QPoint a=obj->pos();
    int x=event(obj)->x();
    int y=event(obj)->


}
