#-------------------------------------------------
#
# Project created by QtCreator 2015-12-24T16:18:28
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bookkeeping
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    month.cpp \
    search_by_sort.cpp \
    month_total.cpp \
    total.cpp \
    input.cpp \
    backhint.cpp \
    ioe.cpp \
    expense.cpp \
    income.cpp \
    incomebysort.cpp \
    expensebysort.cpp \
    iobymonth.cpp

HEADERS  += mainwindow.h \
    month.h \
    search_by_sort.h \
    month_total.h \
    total.h \
    input.h \
    backhint.h \
    ioe.h \
    expense.h \
    income.h \
    incomebysort.h \
    expensebysort.h \
    iobymonth.h

FORMS    += mainwindow.ui \
    month.ui \
    search_by_sort.ui \
    month_total.ui \
    total.ui \
    input.ui \
    backhint.ui
