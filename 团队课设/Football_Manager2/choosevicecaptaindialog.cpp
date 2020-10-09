#include "choosevicecaptaindialog.h"
#include "ui_choosevicecaptaindialog.h"

ChooseViceCaptainDialog::ChooseViceCaptainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseViceCaptainDialog)
{
    ui->setupUi(this);

    //将所有的RadioBtn归到按钮组中
    {
        playersBtnGroup = new QButtonGroup(this);
        playersBtnGroup->addButton(ui->radioButton,1);
        playersBtnGroup->addButton(ui->radioButton_2,2);
        playersBtnGroup->addButton(ui->radioButton_3,3);
        playersBtnGroup->addButton(ui->radioButton_4,4);
        playersBtnGroup->addButton(ui->radioButton_5,5);
        playersBtnGroup->addButton(ui->radioButton_6,6);
        playersBtnGroup->addButton(ui->radioButton_7,7);
        playersBtnGroup->addButton(ui->radioButton_8,8);
        playersBtnGroup->addButton(ui->radioButton_9,9);
        playersBtnGroup->addButton(ui->radioButton_10,10);
        playersBtnGroup->addButton(ui->radioButton_11,11);
        playersBtnGroup->addButton(ui->radioButton_12,12);
        playersBtnGroup->addButton(ui->radioButton_13,13);
        playersBtnGroup->addButton(ui->radioButton_14,14);
        playersBtnGroup->addButton(ui->radioButton_15,15);
        playersBtnGroup->addButton(ui->radioButton_16,16);
        playersBtnGroup->addButton(ui->radioButton_17,17);
        playersBtnGroup->addButton(ui->radioButton_18,18);
        playersBtnGroup->addButton(ui->radioButton_19,19);
        playersBtnGroup->addButton(ui->radioButton_20,20);
        playersBtnGroup->addButton(ui->radioButton_21,21);
        playersBtnGroup->addButton(ui->radioButton_22,22);
    }

    //将所有RadioBtn的click信号与槽函数连接
    {
        connect(ui->radioButton,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_2,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_3,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_4,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_5,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_6,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_7,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_8,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_9,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_10,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_11,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_12,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_13,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_14,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_15,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_16,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_17,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_18,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_19,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_20,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_21,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
        connect(ui->radioButton_22,&QRadioButton::clicked,this,&ChooseViceCaptainDialog::onRadioClick);
    }
}

ChooseViceCaptainDialog::~ChooseViceCaptainDialog()
{
    delete ui;
}

QString ChooseViceCaptainDialog::onRadioClick()
{
    switch(playersBtnGroup->checkedId())
    {
    case 1:
        return ui->radioButton->text();
    case 2:
        return ui->radioButton_2->text();
    case 3:
        return ui->radioButton_3->text();
    case 4:
        return ui->radioButton_4->text();
    case 5:
        return ui->radioButton_5->text();
    case 6:
        return ui->radioButton_6->text();
    case 7:
        return ui->radioButton_7->text();
    case 8:
        return ui->radioButton_8->text();
    case 9:
        return ui->radioButton_9->text();
    case 10:
        return ui->radioButton_10->text();
    case 11:
        return ui->radioButton_11->text();
    case 12:
        return ui->radioButton_12->text();
    case 13:
        return ui->radioButton_13->text();
    case 14:
        return ui->radioButton_14->text();
    case 15:
        return ui->radioButton_15->text();
    case 16:
        return ui->radioButton_16->text();
    case 17:
        return ui->radioButton_17->text();
    case 18:
        return ui->radioButton_18->text();
    case 19:
        return ui->radioButton_19->text();
    case 20:
        return ui->radioButton_20->text();
    case 21:
        return ui->radioButton_21->text();
    case 22:
        return ui->radioButton_22->text();
    }
    return QString("");
}

void ChooseViceCaptainDialog::setBox1(QString name)
{
    ui->radioButton->setText(name);
}
void ChooseViceCaptainDialog::setBox2(QString name)
{
    ui->radioButton_2->setText(name);
}
void ChooseViceCaptainDialog::setBox3(QString name)
{
    ui->radioButton_3->setText(name);
}
void ChooseViceCaptainDialog::setBox4(QString name)
{
    ui->radioButton_4->setText(name);
}
void ChooseViceCaptainDialog::setBox5(QString name)
{
    ui->radioButton_5->setText(name);
}
void ChooseViceCaptainDialog::setBox6(QString name)
{
    ui->radioButton_6->setText(name);
}
void ChooseViceCaptainDialog::setBox7(QString name)
{
    ui->radioButton_7->setText(name);
}
void ChooseViceCaptainDialog::setBox8(QString name)
{
    ui->radioButton_8->setText(name);
}
void ChooseViceCaptainDialog::setBox9(QString name)
{
    ui->radioButton_9->setText(name);
}
void ChooseViceCaptainDialog::setBox10(QString name)
{
    ui->radioButton_10->setText(name);
}
void ChooseViceCaptainDialog::setBox11(QString name)
{
    ui->radioButton_11->setText(name);
}
void ChooseViceCaptainDialog::setBox12(QString name)
{
    ui->radioButton_12->setText(name);
}
void ChooseViceCaptainDialog::setBox13(QString name)
{
    ui->radioButton_13->setText(name);
}
void ChooseViceCaptainDialog::setBox14(QString name)
{
    ui->radioButton_14->setText(name);
}
void ChooseViceCaptainDialog::setBox15(QString name)
{
    ui->radioButton_15->setText(name);
}
void ChooseViceCaptainDialog::setBox16(QString name)
{
    ui->radioButton_16->setText(name);
}
void ChooseViceCaptainDialog::setBox17(QString name)
{
    ui->radioButton_17->setText(name);
}
void ChooseViceCaptainDialog::setBox18(QString name)
{
    ui->radioButton_18->setText(name);
}
void ChooseViceCaptainDialog::setBox19(QString name)
{
    ui->radioButton_19->setText(name);
}
void ChooseViceCaptainDialog::setBox20(QString name)
{
    ui->radioButton_20->setText(name);
}
void ChooseViceCaptainDialog::setBox21(QString name)
{
    ui->radioButton_21->setText(name);
}
void ChooseViceCaptainDialog::setBox22(QString name)
{
    ui->radioButton_22->setText(name);
}
void ChooseViceCaptainDialog::setBox23(QString name)
{
    ui->radioButton_23->setText(name);
}

void ChooseViceCaptainDialog::reset()
{
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_5->setChecked(false);
    ui->radioButton_6->setChecked(false);
    ui->radioButton_7->setChecked(false);
    ui->radioButton_8->setChecked(false);
    ui->radioButton_9->setChecked(false);
    ui->radioButton_10->setChecked(false);
    ui->radioButton_11->setChecked(false);
    ui->radioButton_12->setChecked(false);
    ui->radioButton_13->setChecked(false);
    ui->radioButton_14->setChecked(false);
    ui->radioButton_15->setChecked(false);
    ui->radioButton_16->setChecked(false);
    ui->radioButton_17->setChecked(false);
    ui->radioButton_18->setChecked(false);
    ui->radioButton_19->setChecked(false);
    ui->radioButton_20->setChecked(false);
    ui->radioButton_21->setChecked(false);
    ui->radioButton_22->setChecked(false);
    ui->radioButton_23->setChecked(false);
}
