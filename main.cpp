#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <QStringList>
#include <QDebug>
#include <QSqlDatabase>
#include <QObject>

int main(int argc, char *argv[])
{
    QProcess process;
    process.start("e:/MySQL/bin/mysql.exe");
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
    qDebug() << driver;
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
