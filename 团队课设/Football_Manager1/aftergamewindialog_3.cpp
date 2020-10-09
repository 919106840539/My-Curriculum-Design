#include "aftergamewindialog_3.h"
#include "ui_aftergamewindialog_3.h"

afterGameWinDialog_3::afterGameWinDialog_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameWinDialog_3)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameWinDialog_3::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameWinDialog_3::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameWinDialog_3::close);
}

afterGameWinDialog_3::~afterGameWinDialog_3()
{
    delete ui;
}
