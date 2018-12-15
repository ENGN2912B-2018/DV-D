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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void on_enterButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
