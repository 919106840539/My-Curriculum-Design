#include "midtalkdialog.h"
#include "ui_midtalkdialog.h"

midTalkDialog::midTalkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::midTalkDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(6);
    connect(ui->commandLinkButton,&QCommandLinkButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    if (mygoal > 0)
    {
        connect(ui->toolButton,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(1);
        });
        connect(ui->toolButton_2,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(1);
        });
        connect(ui->toolButton_3,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(1);
        });
        connect(ui->toolButton_4,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(1);
        });
        connect(ui->toolButton_5,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(1);
        });
    }
    else
    {
        connect(ui->toolButton,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(2);
        });
        connect(ui->toolButton_2,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(2);
        });
        connect(ui->toolButton_3,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(2);
        });
        connect(ui->toolButton_4,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(2);
        });
        connect(ui->toolButton_5,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(2);
        });
    }
    connect(ui->toolButton_6,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->toolButton_7,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->toolButton_9,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->toolButton_10,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->toolButton_11,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    if (oppgoal > 0)
    {
        connect(ui->toolButton_12,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(4);
        });
        connect(ui->toolButton_13,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(4);
        });
        connect(ui->toolButton_14,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(4);
        });
        connect(ui->toolButton_15,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(4);
        });
    }
    else
    {
        connect(ui->toolButton_12,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(5);
        });
        connect(ui->toolButton_13,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(5);
        });
        connect(ui->toolButton_14,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(5);
        });
        connect(ui->toolButton_15,&QToolButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(5);
        });
    }
    connect(ui->toolButton_16,&QToolButton::clicked,this,&midTalkDialog::close);
    connect(ui->toolButton_17,&QToolButton::clicked,this,&midTalkDialog::close);
    connect(ui->toolButton_18,&QToolButton::clicked,this,&midTalkDialog::close);
    connect(ui->toolButton_19,&QToolButton::clicked,this,&midTalkDialog::close);
    connect(ui->toolButton_20,&QToolButton::clicked,this,&midTalkDialog::close);
    connect(ui->toolButton_21,&QToolButton::clicked,this,&midTalkDialog::close);
    connect(ui->toolButton_22,&QToolButton::clicked,this,&midTalkDialog::close);
}

midTalkDialog::~midTalkDialog()
{
    delete ui;
}

void midTalkDialog::set_mygoal(int a)
{
    mygoal = a;
}

void midTalkDialog::set_oppgoal(int a)
{
    oppgoal = a;
}
