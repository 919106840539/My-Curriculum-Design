#include "aftergamefaildialog_2.h"
#include "ui_aftergamefaildialog_2.h"

afterGameFailDialog_2::afterGameFailDialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameFailDialog_2)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameFailDialog_2::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameFailDialog_2::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameFailDialog_2::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&afterGameFailDialog_2::close);
}

afterGameFailDialog_2::~afterGameFailDialog_2()
{
    delete ui;
}
