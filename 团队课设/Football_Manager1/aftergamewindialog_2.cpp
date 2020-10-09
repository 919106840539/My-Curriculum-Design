#include "aftergamewindialog_2.h"
#include "ui_aftergamewindialog_2.h"

afterGameWinDialog_2::afterGameWinDialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameWinDialog_2)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameWinDialog_2::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameWinDialog_2::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameWinDialog_2::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&afterGameWinDialog_2::close);
}

afterGameWinDialog_2::~afterGameWinDialog_2()
{
    delete ui;
}
