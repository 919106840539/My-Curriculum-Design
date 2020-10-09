#include "beforegame3dialog.h"
#include "ui_beforegame3dialog.h"

BeforeGame3Dialog::BeforeGame3Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BeforeGame3Dialog)
{
    ui->setupUi(this);

    connect(ui->toolButton,&QToolButton::clicked,this,&BeforeGame3Dialog::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&BeforeGame3Dialog::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&BeforeGame3Dialog::close);
}

BeforeGame3Dialog::~BeforeGame3Dialog()
{
    delete ui;
}
