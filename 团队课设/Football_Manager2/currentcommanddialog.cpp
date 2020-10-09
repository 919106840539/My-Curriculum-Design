#include "currentcommanddialog.h"
#include "ui_currentcommanddialog.h"

currentCommandDialog::currentCommandDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currentCommandDialog)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&currentCommandDialog::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&currentCommandDialog::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&currentCommandDialog::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&currentCommandDialog::close);
    connect(ui->toolButton_5,&QToolButton::clicked,this,&currentCommandDialog::close);
}

currentCommandDialog::~currentCommandDialog()
{
    delete ui;
}
