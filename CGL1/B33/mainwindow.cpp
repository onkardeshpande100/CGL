#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRgb color=

}


MainWindow::~MainWindow()
{
    delete ui;
}
QImage image(801,431,QImage::Format_RGB888);
vid MainWindow::setZero()
{
    rectFlag=0;
    rectCount=0;
    rectArrX[0]=0;
    rectArrY[0]=0;
    rectArrX[1]=0;
    rectArrY[1]=0;

}

void MainWindow ::  mousePressEvent(QMouseEvent *P)
{
    if(rectFlag==0)
    {
        if(rectCount==0)
        {
            rectArrX[0]=P->pos().x();
            rectArrY[0]=P->pos().y();
            rectCount++;
        }
        else
        {
            rectArrX[1]=P->pos().x();
            rectArrX[1]=P->pos().y();
            rectFlag++;
            Bresenham(rectArrX[0],rectArrY[0],rectArrX[1],rectArrY[0]);
            Bresenham(rectArrX[1],rectArrY[0],rectArrX[1],rectArrY[1]);
            Bresenham(rectArrX[0],rectArrY[1],rectArrX[1],rectArrY[1]);
            Bresenham(rectArrX[0],rectArrY[0],rectArrX[0],rectArrY[1]);
        }
    }
}
int MainWindow::Sign(float a)
{
    if(a<0){
        return -1;
    }
    return 1;
}


void MainWindow :: Bresenham(float x1, float y1, float x2, float y2){

    int dx,dy,s1,s2,temp,flag_interchange,e,x,y;
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    s1=Sign(x2-x1);
    s2=Sign(y2-y1);

    if(dy>dx){
        temp=dx;
        dx=dy;
        dy=temp;
        flag_interchange=1;
    }
    else
        flag_interchange=0;

    e=2*dy-dx;

    for(int i=0;i<dx;i++){
        image.setPixel(x,y,qRgb(0,255,0));
        while(e>=0){
            if(flag_interchange==1)
                x=x+s1;
            else
                y=y+s2;
            e=e-2*dx;
        }
        if(flag_interchange==1)
            y=y+s2;
        else
            x=x+s1;
        e=e+2*dy;
    }
}
