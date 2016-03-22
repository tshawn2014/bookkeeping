#ifndef BACKHINT_H
#define BACKHINT_H

#include <QDialog>

namespace Ui {
class backhint;
}

class backhint : public QDialog
{
    Q_OBJECT

public:
    explicit backhint(QWidget *parent = 0);
    explicit backhint(int type,QWidget *parent = 0);
    ~backhint();

private slots:
    void on_pushButton_clicked();

private:
    Ui::backhint *ui;
};

#endif // BACKHINT_H
