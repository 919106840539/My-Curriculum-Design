#include "beforegame1dialog.h"
#include "ui_beforegame1dialog.h"

BeforeGame1Dialog::BeforeGame1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BeforeGame1Dialog)
{
    ui->setupUi(this);

    connect(ui->toolButton,&QToolButton::clicked,this,&BeforeGame1Dialog::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&BeforeGame1Dialog::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&BeforeGame1Dialog::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&BeforeGame1Dialog::close);
    connect(ui->toolButton_5,&QToolButton::clicked,this,&BeforeGame1Dialog::close);

}

BeforeGame1Dialog::~BeforeGame1Dialog()
{
    delete ui;
}
