#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sizeEdit->setValidator(new QIntValidator(0, 100000, ui->sizeEdit));
    ui->rangeEdit->setValidator(new QIntValidator(0, 1000000, ui->rangeEdit));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();


    SIZE = ui->sizeEdit->text().toInt();
    range = ui->rangeEdit->text().toInt();

    int *numbers = new int[SIZE];

    time_t time (time_t* timer);
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        numbers[i] = (rand() % range);
    }

    showNumbers(numbers);

    std::thread thread(&MainWindow::shakerSort, this, numbers, 1, SIZE);
    thread.join();

    showNumbers(numbers);
}

void MainWindow::swap(int *Mas, int i)
{
    int temp;
    temp=Mas[i];
    Mas[i]=Mas[i-1];
    Mas[i-1]=temp;
}

void MainWindow::showNumbers(int *numbers)
{
    std::string string;
    for ( int i = 0; i < SIZE; i++ ) {
        string = string + std::to_string(numbers[i]) + " ";
    }

    ui->textBrowser->append(QString::fromStdString(string));
    ui->textBrowser->append("\n\n");
}

void MainWindow::shakerSort(int *Mas, int start, int n)
{
    mutex.lock();

    int left, right, i;
    left = start;
    right = n-1;

    while (left <= right) {
        for (i = right; i >= left; i--)
            if (Mas[i-1] > Mas[i]) {
                swap(Mas, i);
            }
            left++;
        for (i = left; i <= right; i++)
            if (Mas[i-1] > Mas[i]) {
                swap(Mas, i);
            }
                right--;
    }
    mutex.unlock();
}
