#include "beforegame4dialog.h"
#include "ui_beforegame4dialog.h"

BeforeGame4Dialog::BeforeGame4Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BeforeGame4Dialog)
{
    ui->setupUi(this);

    connect(ui->toolButton,&QToolButton::clicked,this,&BeforeGame4Dialog::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&BeforeGame4Dialog::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&BeforeGame4Dialog::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&BeforeGame4Dialog::close);
    connect(ui->toolButton_5,&QToolButton::clicked,this,&BeforeGame4Dialog::close);
}

BeforeGame4Dialog::~BeforeGame4Dialog()
{
    delete ui;
}
