#include "aftergamefaildialog_4.h"
#include "ui_aftergamefaildialog_4.h"

afterGameFailDialog_4::afterGameFailDialog_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterGameFailDialog_4)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&afterGameFailDialog_4::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&afterGameFailDialog_4::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&afterGameFailDialog_4::close);
}

afterGameFailDialog_4::~afterGameFailDialog_4()
{
    delete ui;
}
