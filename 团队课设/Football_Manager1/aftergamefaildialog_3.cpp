#include "aftergamefaildialog_3.h"
#include "ui_aftergamefaildialog_3.h"

afterGameFailDialog_3::afterGameFailDialog_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameFailDialog_3)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameFailDialog_3::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameFailDialog_3::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameFailDialog_3::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&afterGameFailDialog_3::close);
}

afterGameFailDialog_3::~afterGameFailDialog_3()
{
    delete ui;
}
