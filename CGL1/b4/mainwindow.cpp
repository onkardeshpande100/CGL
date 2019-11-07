#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"

QImage image(600,600, QImage::Format_RGB888);
QRgb value;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x[0] = 350;
    y[0] = 250;
    x[1] = 400;
    y[1] = 150;
    x[2] = 450;
    y[2] = 250;
}

void MainWindow :: matmul(float a[3][3], float b[3][3]){
    float temp[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            temp[i][j] = 0;
            for(int k=0; k<3; k++){
                temp[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            a[i][j] = temp[i][j];
        }
    }
}

void MainWindow :: draw(){
    image.fill(qRgb(0,0,0));
    value = qRgb(255, 0, 0);
    bresenham(300, 0, 300, 599);
    bresenham(0, 300, 599, 300);
    bresenham(0, 599, 599, 0);

    value = qRgb(100,100,0);
    bresenham(350, 250, 400, 150);
    bresenham(350, 250, 450, 250);
    bresenham(450, 250, 400, 150);

    value = qRgb(0, 255, 0);
    bresenham(x[0], y[0], x[1], y[1]);
    bresenham(x[0], y[0], x[2], y[2]);
    bresenham(x[2], y[2], x[1], y[1]);

    ui->label->setPixmap(QPixmap::fromImage(image));
}

int MainWindow :: sign(float a){
    if(a<0){
        return -1;
    }
    return 1;
}

void MainWindow :: bresenham(float x1, float y1, float x2, float y2){

    int dx,dy,s1,s2,temp,flag_interchange,e,x,y;
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    s1=sign(x2-x1);
    s2=sign(y2-y1);

    if(dy>dx){
        temp=dx;
        dx=dy;
        dy=temp;
        flag_interchange=1;
    }
    else
        flag_interchange=0;

    e=2*dy-dx;

    for(int i=0;i<=dx;i++){
        image.setPixel(x,y,value);
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_x_axis_clicked()
{
    float mat[3][3], ref[3][3], trans[3][3];
    for(int i=0; i<3; i++){
        mat[i][0] = x[i];
        mat[i][1] = y[i];
        mat[i][2] = 1;
        for(int j=0; j<3; j++){
            ref[i][j] = 0;
            trans[i][j] = 0;
            if(i == j){
                trans[i][j] = 1;
            }
        }
    }
    trans[2][0] = -300;
    trans[2][1] = -300;

    matmul(mat, trans);

    ref[0][0] = 1;
    ref[1][1] = -1;

    matmul(mat, ref);

    trans[2][0] = 300;
    trans[2][1] = 300;

    matmul(mat, trans);

    for(int i=0; i<3; i++){
        x[i] = mat[i][0] + 300;
        y[i] = mat[i][1] + 300;
    }

    draw();
}

void MainWindow::on_draw_clicked()
{
    draw();
}

void MainWindow::on_y_axis_clicked()
{
    float mat[3][3], ref[3][3], trans[3][3];
    for(int i=0; i<3; i++){
        mat[i][0] = x[i];
        mat[i][1] = y[i];
        mat[i][2] = 1;
        for(int j=0; j<3; j++){
            ref[i][j] = 0;
            trans[i][j] = 0;
            if(i == j){
                trans[i][j] = 1;
            }
        }
    }
    trans[2][0] = -300;
    trans[2][1] = -300;

    matmul(mat, trans);

    ref[0][0] = -1;
    ref[1][1] = 1;

    matmul(mat, ref);

    trans[2][0] = 300;
    trans[2][1] = 300;

    matmul(mat, trans);

    for(int i=0; i<3; i++){
        x[i] = mat[i][0] + 300;
        y[i] = mat[i][1] + 300;
    }
    draw();
}

void MainWindow::on_xy_axis_clicked()
{
    float mat[3][3], ref[3][3], trans[3][3];
    for(int i=0; i<3; i++){
        mat[i][0] = x[i];
        mat[i][1] = y[i];
        mat[i][2] = 1;
        for(int j=0; j<3; j++){
            ref[i][j] = 0;
            trans[i][j] = 0;
            if(i == j){
                trans[i][j] = 1;
            }
        }
    }
    trans[2][0] = -300;
    trans[2][1] = -300;

    matmul(mat, trans);

    ref[0][1] = -1;
    ref[1][0] = -1;

    matmul(mat, ref);

    trans[2][0] = 300;
    trans[2][1] = 300;

    matmul(mat, trans);

    for(int i=0; i<3; i++){
        x[i] = mat[i][0] + 300;
        y[i] = mat[i][1] + 300;
    }
    draw();
}

void MainWindow::on_rotateButton_clicked()
{
    int x_r = ui->x_rot->toPlainText().toInt();
    int y_r = ui->y_rot->toPlainText().toInt();

    x_r += 300;
    y_r = 300 - y_r;

    float mat[3][3], ref[3][3], trans[3][3];
    for(int i=0; i<3; i++){
        mat[i][0] = x[i];
        mat[i][1] = y[i];
        mat[i][2] = 1;
        for(int j=0; j<3; j++){
            ref[i][j] = 0;
            trans[i][j] = 0;
            if(i == j){
                trans[i][j] = 1;
            }
        }
    }
    trans[2][0] = x_r*(-1);
    trans[2][1] = y_r*(-1);

    matmul(mat, trans);

    float a = 3.14/2;

    ref[0][1] = -1*sin(a);
    ref[0][0] = cos(a);
    ref[1][1] = cos(a);
    ref[1][0] = sin(a);

    matmul(mat, ref);

    trans[2][0] = x_r;
    trans[2][1] = y_r;

    matmul(mat, trans); //here

    for(int i=0; i<3; i++){
        x[i] = mat[i][0] + x_r;
        y[i] = mat[i][1] + y_r;
    }
    draw();
}
