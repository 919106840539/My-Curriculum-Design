#include "chooseteamdialog.h"
#include "ui_chooseteamdialog.h"

ChooseTeamDialog::ChooseTeamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseTeamDialog)
{
    ui->setupUi(this);
//    setMinimumSize(600,500);
//    resize(600,500);
}

ChooseTeamDialog::~ChooseTeamDialog()
{
    delete ui;
}


QString ChooseTeamDialog::getTeamName()
{
    if (ui->radioButton->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("拜仁慕尼黑");
    }
    if (ui->radioButton_2->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("切尔西");
    }
    if (ui->radioButton_3->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("尤文图斯");
    }
    if (ui->radioButton_4->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("阿森纳");
    }
    if (ui->radioButton_5->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("利物浦");
    }
    if (ui->radioButton_6->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("曼联");
    }
    if (ui->radioButton_7->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("曼城");
    }
    if (ui->radioButton_8->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("西汉姆联");
    }
    if (ui->radioButton_9->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("埃弗顿");
    }if (ui->radioButton_10->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("皇家马德里");
    }
    if (ui->radioButton_11->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("巴塞罗那");
    }
    if (ui->radioButton_12->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("马德里竞技");
    }
    if (ui->radioButton_13->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("瓦伦西亚");
    }
    if (ui->radioButton_14->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("皇家贝蒂斯");
    }
    if (ui->radioButton_15->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("亚特兰大");
    }
    if (ui->radioButton_16->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("国际米兰");
    }
    if (ui->radioButton_17->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("AC米兰");
    }
    if (ui->radioButton_18->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("多特蒙德");
    }
    if (ui->radioButton_19->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("弗莱堡");
    }
    if (ui->radioButton_20->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("巴黎圣日耳曼");
    }
    if (ui->radioButton_21->isChecked()&&ui->buttonBox->Ok)
    {
        return QString("勒沃库森");
    }
    return QString();
}
