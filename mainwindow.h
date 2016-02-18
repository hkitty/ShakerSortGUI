#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cstdlib"
#include "ctime"
#include "mutex"
#include "thread"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


    int SIZE;
    int range;

    std::mutex mutex;

    void shakerSort(int *Mas, int start, int n);
    void swap(int *Mas, int i);
    void showNumbers(int *numbers);


};

#endif // MAINWINDOW_H
