#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage image(451, 371, QImage::Format_RGB888);
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


void MainWindow::dda(int x1,int y1,int x2,int y2,int type)
{
    value=qRgb(0,255,0);

    int dx, dy, cnt;
    float x, y;
    float incx, incy;

    bool flag;

    dx = (x2 - x1);
    dy = (y2 - y1);

    if(abs(dx)>=abs(dy)){
        cnt = dx;
        flag = true;
    }
    else{
        cnt = dy;
        flag = false;
    }

    incx = dx/(float)cnt;
    incy = dy/(float)cnt;

    x = x1;
    y = y1;

    for(int i=1; i<cnt; i++){
        switch (type) {
        case 1:                 //dotted
            if(i%2!=0)
                image.setPixel(x,y,value);
            break;

        case 2:                 //dash
            if(i%4 != 0 && (i-1)%4 != 0){
                image.setPixel(x, y, value);
            }
            break;

        case 3:                 //thick
            if(flag){
                image.setPixel(x, y, value);
                image.setPixel(x, y+1, value);
                image.setPixel(x, y-1, value);
            }
            else{
                image.setPixel(x, y, value);
                image.setPixel(x+1, y, value);
                image.setPixel(x-1, y, value);
            }
            break;

        case 4:                 //dash sot
            if(i%9 != 4 && i%9 != 5 && i%9 != 7 && i%9 != 8){
                image.setPixel(x, y, value);
            }
            break;

         case 5:                //solid
             image.setPixel(x, y, value);
             break;
        }
        x=x+incx;
        y=y+incy;
        }

    }


void MainWindow::on_pushButton_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();


    dda(x1,y1,x2,y2,1);

    ui->label_5->setPixmap(QPixmap :: fromImage(image));

}



void MainWindow::on_pushButton_2_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();


    dda(x1,y1,x2,y2,4);

    ui->label_5->setPixmap(QPixmap :: fromImage(image));
}




void MainWindow::on_pushButton_3_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();


    dda(x1,y1,x2,y2,2);

    ui->label_5->setPixmap(QPixmap :: fromImage(image));
}

void MainWindow::on_pushButton_4_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();


    dda(x1,y1,x2,y2,3);

    ui->label_5->setPixmap(QPixmap :: fromImage(image));
}


void MainWindow::on_pushButton_5_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();


    dda(x1,y1,x2,y2,5);

    ui->label_5->setPixmap(QPixmap :: fromImage(image));
}
