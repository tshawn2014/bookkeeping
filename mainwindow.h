#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "input.h"

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
    void on_inputIncome_clicked();

    void on_inputExpense_clicked();

    void on_sIncBySort_clicked();

    void on_sExpBySort_clicked();

    void on_sIODtlByMonth_clicked();

    void on_sIOAllByMonth_clicked();

    void on_searchIO_clicked();

private:
    Ui::MainWindow *ui;
    //input * Input;

};

#endif // MAINWINDOW_H
