#include "aftergamedrawdialog_2.h"
#include "ui_aftergamedrawdialog_2.h"

afterGameDrawDialog_2::afterGameDrawDialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameDrawDialog_2)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameDrawDialog_2::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameDrawDialog_2::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameDrawDialog_2::close);
}

afterGameDrawDialog_2::~afterGameDrawDialog_2()
{
    delete ui;
}
