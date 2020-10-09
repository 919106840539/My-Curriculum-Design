#include "afterchooseteamdialog.h"
#include "ui_afterchooseteamdialog.h"
#include "mainwindow.h"

AfterChooseTeamDialog::AfterChooseTeamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfterChooseTeamDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("恭喜您成为教练");
}

AfterChooseTeamDialog::~AfterChooseTeamDialog()
{
    delete ui;
}

void AfterChooseTeamDialog::setUserName(QString name)
{
    ui->label->setText(name);
}

void AfterChooseTeamDialog::setTeamName(QString name)
{
    ui->label_3->setText(name);
}
