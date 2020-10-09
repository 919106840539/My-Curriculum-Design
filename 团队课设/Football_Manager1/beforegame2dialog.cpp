#include "beforegame2dialog.h"
#include "ui_beforegame2dialog.h"

BeforeGame2Dialog::BeforeGame2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BeforeGame2Dialog)
{
    ui->setupUi(this);

    connect(ui->toolButton,&QToolButton::clicked,this,&BeforeGame2Dialog::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&BeforeGame2Dialog::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&BeforeGame2Dialog::close);
}

BeforeGame2Dialog::~BeforeGame2Dialog()
{
    delete ui;
}
