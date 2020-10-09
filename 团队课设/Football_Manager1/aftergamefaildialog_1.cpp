#include "aftergamefaildialog_1.h"
#include "ui_aftergamefaildialog_1.h"

afterGameFailDialog_1::afterGameFailDialog_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameFailDialog_1)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameFailDialog_1::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameFailDialog_1::close);
}

afterGameFailDialog_1::~afterGameFailDialog_1()
{
    delete ui;
}
