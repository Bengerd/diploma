#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_UpdateButton_clicked()
{
    ui->graphicsView->setWidth(ui->WidthEdit->text());
    ui->graphicsView->setLength(ui->LengthEdit->text());
}
