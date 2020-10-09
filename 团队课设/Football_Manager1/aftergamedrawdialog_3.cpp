#include "aftergamedrawdialog_3.h"
#include "ui_aftergamedrawdialog_3.h"

afterGameDrawDialog_3::afterGameDrawDialog_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameDrawDialog_3)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameDrawDialog_3::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameDrawDialog_3::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameDrawDialog_3::close);
}

afterGameDrawDialog_3::~afterGameDrawDialog_3()
{
    delete ui;
}
