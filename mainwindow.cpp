#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "input.h"
#include "search_by_sort.h"
#include "month.h"
#include "month_total.h"
#include "total.h"

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

void MainWindow::on_inputIncome_clicked()
{
    //打开一个添加Ui：：input
    input * Input = new input(1,this);
    Input->setModal(true);
    Input->show();
}

void MainWindow::on_inputExpense_clicked()
{
    //打开一个添加Ui：：input
    input * Input = new input(2,this);
    Input->setModal(true);
    Input->show();
}

void MainWindow::on_sIncBySort_clicked()
{
    //打开一个Ui::
    search_by_sort * s_b_s = new search_by_sort(1,this);
    s_b_s->setModal(true);
    s_b_s->show();
}

void MainWindow::on_sExpBySort_clicked()
{
    //打开一个Ui::
    search_by_sort * s_b_s = new search_by_sort(2,this);
    s_b_s->setModal(true);
    s_b_s->show();
}

void MainWindow::on_sIODtlByMonth_clicked()
{

    month * mnth = new month(this);
    mnth->setModal(true);
    mnth->show();

}

void MainWindow::on_sIOAllByMonth_clicked()
{
    month_total * mtt = new month_total(this);
    mtt->setModal(true);
    mtt->show();
}

void MainWindow::on_searchIO_clicked()
{
    total * tt = new total(this);
    tt->setModal(true);
    tt->show();
}
