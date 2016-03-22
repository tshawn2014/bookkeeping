#ifndef MONTH_TOTAL_H
#define MONTH_TOTAL_H

#include <QDialog>

namespace Ui {
class month_total;
}

class month_total : public QDialog
{
    Q_OBJECT

public:
    explicit month_total(QWidget *parent = 0);
    ~month_total();

private slots:
    void on_back_clicked();
    //void search_2(int);

    void on_comboBox_month_currentIndexChanged(int index);

private:
    Ui::month_total *ui;
};

#endif // MONTH_TOTAL_H
