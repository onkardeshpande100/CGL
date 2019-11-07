/*
A Mandelbrot Set is a set of complex number z that does not diverge under the
transformation Xn+1=Xn^2+z with X0=0. Where, both X and z represents the complex
numbers. Write C++/Java program to
a) Plot the Mandelbrot set for the threshold |x|= 2.
b) Plot Julia set choosing z ≠ 0. Use 254 colors for plotting in both cases.

Roll No:2268
Batch:H2
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QImage image(400,400,QImage::Format_RGB555);


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MandelbrotSet()
{
    //int a=0,b=0,c=0;
    double wt=400;
    double ht=400;
    double MaxRe= 1.0;
    double MinRe= -2.0;
    double MinIm= -1.2;
    double MaxIm = MinIm+(MaxRe-MinRe)*ht/wt;
    double ref=(MaxRe-MinRe)/(wt-1);
    double imf=(MaxIm-MinIm)/(ht-1);
    unsigned n=30;


    for(unsigned y=0;y<ht;++y)
    {
        double c_im = MaxIm - y * imf;

        for(unsigned x=0;x<wt;++x)
        {
           double c_re = MinRe + x * ref;

           double z_re=c_re,z_im=c_im;

            bool isInside=true;
            for(unsigned i=0;i<n;++i)
            {
                double zre2= z_re * z_re , zim2= z_im * z_im;
                if(zre2 + zim2 > 4)
                {
                    isInside=false;
                    break;
                }
                z_im= 2 * z_re * z_im + c_im;
                z_re= zre2 - zim2 + c_re;

            }

            if(isInside)
            {

                image.setPixel(x,y,qRgb(0,255,0));
                cout<<"x= "<<x<<" y="<<y<<"\n";
            }


         }

    }

    ui->label->setPixmap(QPixmap::fromImage(image));




}

void MainWindow::Julia()
{
    double wt=400;
    double ht=400;
    unsigned n=256;
    double z_re,z_im;
    double c_re = -0.7;
    double c_im = 0.27015;
    int a=255,b=90,c=10;

    for(unsigned y=0;y<ht;++y)
    {

        for(unsigned x=0;x<wt;++x)
        {

            z_re = 1.5 * (x - wt / 2) / (0.5 * wt);
            z_im = (y - ht / 2) / (0.5 * ht);

            bool isInside=true;
            for(unsigned i=0;i<n;++i)
            {
                double zre2= z_re * z_re , zim2= z_im * z_im;

                z_im= 2 * z_re * z_im + c_im;
                z_re= zre2 - zim2 + c_re;


                if(zre2 + zim2 > 100)
                {
                    isInside=false;
                    break;
                }

            }

            if(isInside)
            {

                image.setPixel(x,y,qRgb(a,b,c));
                cout<<"x= "<<x<<" y="<<y<<"\n";

                a--;
                b++;
                c++;
            }


         }

    }

    ui->label->setPixmap(QPixmap::fromImage(image));

}





void MainWindow::on_pushButton_clicked()
{
    image.fill(Qt::black);
    Julia();
}

void MainWindow::on_pushButton_2_clicked()
{
    image.fill(Qt::black);
    MandelbrotSet();
}
