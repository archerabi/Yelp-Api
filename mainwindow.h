#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class YelpApi;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    YelpApi* api;

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
