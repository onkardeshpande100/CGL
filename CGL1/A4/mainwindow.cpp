#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include<math.h>
#include <QMouseEvent>
#include <QPoint>

QImage image(1000,1000,QImage::Format_RGB888);
QColor color;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver=0;
   start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::dda(int x1,int y1,int x2,int y2)
{
    QRgb val;
    val=qRgb(0,255,0);
    int x,y,dx,dy,s1,s2,temp,e,interchange,i;
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(x2>x1)
        s1=1;
    else if(x2<x1)
        s1=-1;
    else
        s1=0;
    if(y2>y1)
        s2=1;
    else if(y2<y1)
        s2=-1;
    else
        s2=0;
    e=2*dy-dx;
    if(dy>dx)
    {
        temp=dx;
        dx=dy;
        dy=temp;
        interchange=1;
    }
    else
    {
        interchange=0;
    }
    for(i=0;i<=dx;i++)
    {
         image.setPixel(x,y,val);
        while(e>=0)
        {

            if(interchange==1)
            {
                x=x+s1;
            }
            else
                y=y+s2;
            e=e-2*dx;
        }
        if(interchange==1)
            y=y+s2;
        else
            x=x+s1;
        e=e+2*dy;
    }
     ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        //color = QColorDialog::getColor();
        QRgb col = qRgb(0,255,0);
        QRgb old = qRgb(0,0,0);
        seedfill(p,q,old,col);
        ui->label->setPixmap(QPixmap::fromImage(image));
     }
    else if(ev->button()==Qt::RightButton)
    {
        start = true;
        ver = 0;
    }
}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start==true)
    {
     int p=ev->pos().x();
     int q=ev->pos().y();
     a[ver]=p;
     b[ver]=q;
     if(ev->button()==Qt::RightButton)
     {
         dda(a[0],b[0],a[ver-1],b[ver-1]);
         start=false;
     }
     else {
         if(ver>0)
         {
             dda(a[ver],b[ver],a[ver-1],b[ver-1]);
         }
     }
     ver++;
    }
   }
void MainWindow::seedfill(int x,int y,QRgb old,QRgb color)
{
    QRgb curr=image.pixel(x,y);
    if(curr==old)
    {
        image.setPixel(x,y,color);
        seedfill(x,y+1,old,color);
        seedfill(x-1,y,old,color);
        seedfill(x,y-1,old,color);
        seedfill(x+1,y,old,color);
    }
}

void MainWindow::on_pushButton_clicked()
{
    start = true;
    ver = 0;
}
