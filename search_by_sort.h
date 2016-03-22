#ifndef SEARCH_BY_SORT_H
#define SEARCH_BY_SORT_H

#include <QDialog>

namespace Ui {
class search_by_sort;
}

class search_by_sort : public QDialog
{
    Q_OBJECT

public:
    explicit search_by_sort(int type,QWidget *parent = 0);
    ~search_by_sort();

private slots:
    void on_back_clicked();

    void on_comboBox_expense_currentIndexChanged(const QString &arg1);

    void on_comboBox_income_currentIndexChanged(const QString &arg1);

private:
    Ui::search_by_sort *ui;
};

#endif // SEARCH_BY_SORT_H
