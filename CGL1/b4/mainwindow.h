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
    float x[3], y[3];
    void draw();
    void matmul(float a[3][3], float b[3][3]);
    void bresenham(float, float, float, float);
    int sign(float a);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_x_axis_clicked();

    void on_draw_clicked();

    void on_y_axis_clicked();

    void on_xy_axis_clicked();

    void on_rotateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
