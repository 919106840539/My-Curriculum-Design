#include "aftergamefaildialog_5.h"
#include "ui_aftergamefaildialog_5.h"

afterGameFailDialog_5::afterGameFailDialog_5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameFailDialog_5)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameFailDialog_5::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameFailDialog_5::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameFailDialog_5::close);
}

afterGameFailDialog_5::~afterGameFailDialog_5()
{
    delete ui;
}
