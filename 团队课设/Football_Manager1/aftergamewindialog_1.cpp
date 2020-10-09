#include "aftergamewindialog_1.h"
#include "ui_aftergamewindialog_1.h"

afterGameWinDialog_1::afterGameWinDialog_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameWinDialog_1)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameWinDialog_1::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameWinDialog_1::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameWinDialog_1::close);
}

afterGameWinDialog_1::~afterGameWinDialog_1()
{
    delete ui;
}
