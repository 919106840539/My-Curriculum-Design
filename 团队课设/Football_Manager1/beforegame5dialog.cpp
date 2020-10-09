#include "beforegame5dialog.h"
#include "ui_beforegame5dialog.h"

BeforeGame5Dialog::BeforeGame5Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BeforeGame5Dialog)
{
    ui->setupUi(this);

    connect(ui->toolButton,&QToolButton::clicked,this,&BeforeGame5Dialog::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&BeforeGame5Dialog::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&BeforeGame5Dialog::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&BeforeGame5Dialog::close);
}

BeforeGame5Dialog::~BeforeGame5Dialog()
{
    delete ui;
}
