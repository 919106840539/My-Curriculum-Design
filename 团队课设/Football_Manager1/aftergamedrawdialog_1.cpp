#include "aftergamedrawdialog_1.h"
#include "ui_aftergamedrawdialog_1.h"

afterGameDrawDialog_1::afterGameDrawDialog_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameDrawDialog_1)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameDrawDialog_1::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameDrawDialog_1::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameDrawDialog_1::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&afterGameDrawDialog_1::close);
}

afterGameDrawDialog_1::~afterGameDrawDialog_1()
{
    delete ui;
}
