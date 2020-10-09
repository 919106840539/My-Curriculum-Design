#include "changeformationdialog.h"
#include "ui_changeformationdialog.h"

changeFormationDialog::changeFormationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeFormationDialog)
{
    ui->setupUi(this);
    connect(ui->toolButton,&QToolButton::clicked,this,&changeFormationDialog::close);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&changeFormationDialog::close);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&changeFormationDialog::close);
    connect(ui->toolButton_4,&QToolButton::clicked,this,&changeFormationDialog::close);
    connect(ui->toolButton_5,&QToolButton::clicked,this,&changeFormationDialog::close);
    connect(ui->toolButton_6,&QToolButton::clicked,this,&changeFormationDialog::close);
}

changeFormationDialog::~changeFormationDialog()
{
    delete ui;
}
