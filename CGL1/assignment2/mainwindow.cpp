#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
QImage image(601, 431, QImage::Format_RGB888);
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
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    r = ui->textEdit_3->toPlainText().toInt();

   // QImage image(631, 411, QImage::Format_RGB888);
    value = qRgb(0,255,0);

    bresenhamCircle(x1, y1, r);//draw outer circle
    ddaCircle(x1, y1, (r/2));//draw inner circle

    float a;

    a = r * 0.8660;

    int x2, y, x3;

    y = y1 + (r/2);

    x2 = x1 - a;
    x3 = x1 + a;

    int temp = y1-r;

    ddaline(x1, temp, x2, y);
    ddaline(x1, temp, x3, y);
    ddaline(x2, y, x3, y);

    ui->label_5->setPixmap(QPixmap :: fromImage(image));
}

void MainWindow :: ddaline(int x1, int y1, int x2, int y2){
    int dx, dy, cnt;
    float x, y;
    float incx, incy;

    dx = (x2 - x1);
    dy = (y2 - y1);

    if(abs(dx)>=abs(dy)){
        cnt = dx;
    }
    else{
        cnt = dy;
    }

    incx = dx/(float)cnt;
    incy = dy/(float)cnt;

    x = x1;
    y = y1;

    image.setPixel(x, y, value);
    for(int i=1; i<cnt; i++){
        x += incx;
        y += incy;

        image.setPixel(x, y, value);
    }

}

void MainWindow::ddaCircle(int x, int y, int r){
    float e=1;
    int st_x, st_y;
    st_x = r;
    st_y = 0;
    float x1, y1, x2, y2;

    for(int i=r; i>1; i/=2){
        e++;
    }

    e = pow(2, e);
    e = 1/e;

    st_x = r;
    st_y = 0;

    x1 = st_x;
    y1 = st_y;

    do{
        x2 = x1 + (e*y1);
        y2 = y1 - (e*x2);
        image.setPixel(x+x2, y+y2, value);
        x1 = x2;
        y1 = y2;
    }while((y1-st_y)<e || (st_x-x1)>e);


}

void MainWindow::bresenhamCircle(int x1, int y1, int r){
    int x, y, g, d, limit;
    limit = 0;
    x = 0;
    y = r;
    g = 2 * (1-r);

    while(1){
        image.setPixel(x1+x, y1+y, value);
        image.setPixel(x1+x, y1-y, value);
        image.setPixel(x1-x, y1-y, value);
        image.setPixel(x1-x, y1+y, value);
        image.setPixel(y1+y, x1+x, value);
        image.setPixel(y1-y, x1+x, value);
        image.setPixel(y1-y, x1-x, value);
        image.setPixel(y1+y, x1-x, value);

        if(y<=limit){
            break;
        }
        if(g<0){
            d = (2*g) + (2*y) -1;
            if(d<=0){
                x = x+1;
                g = g + (2*x) + 1;
            }
            else{
                x = x+1;
                y = y-1;
                g = g+(2*x)-(2*y)+2;
            }
        }
        else if(g>0){
            d = (2*g) - (2*x) - 1;
            if(d<=0){
                x = x+1;
                y = y-1;
                g = g+(2*x)-(2*y)+2;
            }
            else{
                y = y-1;
                g = g-(2*y)+1;
            }
        }
        else{
            x = x+1;
            y = y-1;
            g = g+(2*x)-(2*y)+2;
        }
    }


}
