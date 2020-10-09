#include "redcarddialog.h"
#include "ui_redcarddialog.h"

redCardDialog::redCardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::redCardDialog)
{
    ui->setupUi(this);
}

redCardDialog::~redCardDialog()
{
    delete ui;
}

void redCardDialog::setname(QString name)
{
    ui->label_2->setText(name);
}
