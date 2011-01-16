#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "api/yelpapi.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    api = new YelpApi(this);
    api->setApikey("04AghwOHSqdpFFWCou-dvw");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    api->searchByPosition(ui->lineEdit->text().toDouble(),
//                          ui->lineEdit_2->text().toDouble());
    api->searchByPosition(30.27482,-81.462336,25);
}
