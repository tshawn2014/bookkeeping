#ifndef INPUT_H
#define INPUT_H

#include <QDialog>

namespace Ui {
class input;
}

class input : public QDialog
{
    Q_OBJECT

public:
    explicit input(int type, QWidget *parent = 0);//1为支出，2为收入
    ~input();

private slots:
    void on_Cancel_clicked();
    void change_(int);
    void on_Confirm_clicked();

private:
    Ui::input *ui;
    int type;
};

#endif // INPUT_H
