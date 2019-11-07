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
    int x1, y1, r;
    QRgb value;
    //QImage image(631, 411, QImage::Format_RGB888);
    explicit MainWindow(QWidget *parent = 0);

    void bresenhamCircle(int x1, int y1, int r);
    void ddaCircle(int x1, int y1, int r);
    void ddaline(int x1, int y1, int x2, int y2);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
