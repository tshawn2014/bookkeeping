#include "backhint.h"
#include "ui_backhint.h"

backhint::backhint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::backhint)
{
    ui->setupUi(this);
}

backhint::backhint(int type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::backhint)
{
    ui->setupUi(this);
    ui->label->setText(QObject::tr("请输入金额！"));
}

backhint::~backhint()
{
    delete ui;
}

void backhint::on_pushButton_clicked()
{
    this->setModal(false);
    this->hide();
}
