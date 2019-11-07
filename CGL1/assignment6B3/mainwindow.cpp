#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     color=qRgb(170,160,180);
     rectFlag=0;
     flag2=0;
//
     createWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}
QImage image(731,471,QImage::Format_RGB888);
void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float xinc,yinc,x,y,dx,dy;
    int l,s1,s2,i;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>dy)
        l=dx;
    else
        l=dy;
    xinc=(x2-x1)/l;
    yinc=(y2-y1)/l;
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
    x=x1+0.5*s1;
    y=y1+0.5*s2;
    for(i=0;i<l;i++)
    {
        image.setPixel(x,y,color);
        x=x+xinc;
        y=y+yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}
int inside=0;
int left=1;
int right=2;
int bottom=4;
int top=8;

//int rectX[1]=500;
//int rectX[0]=50;
//int rectY[1]=400;
//int rectY[0]=50;
void MainWindow::createWindow()
{
    dda(rectX[0],rectY[0],rectX[1],rectY[0]);
    dda(rectX[1],rectY[0],rectX[1],rectY[1]);
    dda(rectX[1],rectY[1],rectX[0],rectY[1]);
    dda(rectX[0],rectY[1],rectX[0],rectY[0]);
}
int MainWindow:: computecode(double x,double y)
{
    int code=inside;
    if(x<rectX[0])
    {
        code=code|left;
    }
    else if(x>rectX[1])
    {
        code=code|right;
    }
    if(y<rectY[0])
    {
        code=code|top;
    }
    else if(y>rectY[1])
    {
        code =code|bottom;
    }
    return code;
}
void MainWindow::cohensutherland(double x1,double y1,double x2,double y2)
{
        int code1=computecode(x1,y1);
        int code2=computecode(x2,y2);

        bool accept=false;
        while(1)
        {
            if(code1==0&&code2==0)
            {
                accept=true;
                break;
            }
            else if(code1&code2)
            {
                break;
            }
            else
            {
                int code3;
                double x,y;
                if(code1!=0)
                {
                    code3=code1;
                }
                else
                {
                    code3=code2;
                }
                if(code3&top)
                {
                    x=x1+(x2-x1)*(rectY[0]-y1)/(y2-y1);
                    y=rectY[0];
                }
                else if(code3&bottom)
                {
                    x=x1+(x2-x1)*(rectY[1]-y1)/(y2-y1);
                    y=rectY[1];
                }
                else if(code3&left)
                {
                    x=rectX[0];
                    y=y1+(y2-y1)*(rectX[0]-x1)/(x2-x1);
                }
                else if(code3&right)
                {
                    x=rectX[1];
                    y=y1+(y2-y1)*(rectX[1]-x1)/(x2-x1);
                }
                if(code3==code1)
                {
                    x1=x;
                    y1=y;
                    code1=computecode(x1,y1);
                }
                else
                {
                    x2=x;
                    y2=y;
                    code2=computecode(x2,y2);
                }
            }
        }
        if(accept)
        {
            dda(x1,y1,x2,y2);
        }
}
double arrx[2]={0};
double arry[2]={0};
int count=0;
void MainWindow::mousePressEvent(QMouseEvent *q1)
{
    if(rectFlag==0)
    {
        if(flag2==0)
        {
            rectX[0]=q1->pos().x();
            rectY[0]=q1->pos().y();
            flag2++;
        }
        else
        {
            rectX[1]=q1->pos().x();
            rectY[1]=q1->pos().y();
            rectFlag++;
            dda(rectX[0],rectY[0],rectX[1],rectY[0]);
            dda(rectX[1],rectY[0],rectX[1],rectY[1]);
            dda(rectX[1],rectY[1],rectX[0],rectY[1]);
            dda(rectX[0],rectY[1],rectX[0],rectY[0]);
        }
    }

   else if(count<2)
   {
       arrx[count]=q1->pos().x();
       arry[count]=q1->pos().y();
       count++;
       if(count==2)
       {
           count=0;
           cohensutherland(arrx[0],arry[0],arrx[1],arry[1]);
       }
   }
}
