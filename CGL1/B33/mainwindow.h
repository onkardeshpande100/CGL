#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int rectFlag=0;
    int rectCount=0;
    double rectArrX[2]={0};
    double rectArrY[2]={0};
    void mousePressEvent(QMouseEvent *P);
    void Bresenham(float x1, float y1, float x2, float y2);
    int Sign(float a);
    int setZero();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
