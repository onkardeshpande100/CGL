#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QRgb color;

public:
    int rectFlag,flag2;
    double rectX[2],rectY[2];
    explicit MainWindow(QWidget *parent = 0);
    int computecode(double x,double y);
    void dda(float x1, float y1, float x2, float y2);
    void mousePressEvent(QMouseEvent *q1);
    void cohensutherland(double x1,double y1,double x2,double y2);
    void createWindow();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
