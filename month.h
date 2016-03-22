#ifndef MONTH_H
#define MONTH_H

#include <QDialog>

namespace Ui {
class month;
}

class month : public QDialog
{
    Q_OBJECT

public:
    explicit month(QWidget *parent = 0);
    ~month();

private slots:
    void on_back_clicked();

    void on_comboBox_month_currentIndexChanged(int index);

private:
    Ui::month *ui;
};

#endif // MONTH_H
