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
    int  x[5],y[5],i,j;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();\


private:
    Ui::MainWindow *ui;

    void MainWindow::mousePressEvent(QMouseEvent *obj)
};

#endif // MAINWINDOW_H
