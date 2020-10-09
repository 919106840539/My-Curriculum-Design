#include "aftergamewindialog_4.h"
#include "ui_aftergamewindialog_4.h"

afterGameWinDialog_4::afterGameWinDialog_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameWinDialog_4)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameWinDialog_4::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameWinDialog_4::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameWinDialog_4::close);
}

afterGameWinDialog_4::~afterGameWinDialog_4()
{
    delete ui;
}
