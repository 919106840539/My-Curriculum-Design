#include "choosegoalkeeperdialog.h"
#include "ui_choosegoalkeeperdialog.h"
#include <QTreeWidget>

ChooseGoalKeeperDialog::ChooseGoalKeeperDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseGoalKeeperDialog)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList()<<"门将信息");
    QTreeWidgetItem *NuoYiEr = new QTreeWidgetItem(QStringList()<<"诺伊尔");
    QTreeWidgetItem *KaiPa = new QTreeWidgetItem(QStringList()<<"凯帕");
    QTreeWidgetItem *TeErShiTeGen = new QTreeWidgetItem(QStringList()<<"特尔施特根");
    QTreeWidgetItem *BuErJi = new QTreeWidgetItem(QStringList()<<"布尔基");
    QTreeWidgetItem *BuFeng = new QTreeWidgetItem(QStringList()<<"布冯");
    QTreeWidgetItem *DuoNaLuMa = new QTreeWidgetItem(QStringList()<<"多纳鲁马");
    QTreeWidgetItem *LaiNuo = new QTreeWidgetItem(QStringList()<<"莱诺");
    QTreeWidgetItem *ALiSong = new QTreeWidgetItem(QStringList()<<"阿利松");
    QTreeWidgetItem *DeHeYa = new QTreeWidgetItem(QStringList()<<"德赫亚");

    ui->treeWidget->addTopLevelItem(NuoYiEr);
    ui->treeWidget->addTopLevelItem(KaiPa);
    ui->treeWidget->addTopLevelItem(TeErShiTeGen);
    ui->treeWidget->addTopLevelItem(BuErJi);
    ui->treeWidget->addTopLevelItem(BuFeng);
    ui->treeWidget->addTopLevelItem(DuoNaLuMa);
    ui->treeWidget->addTopLevelItem(LaiNuo);
    ui->treeWidget->addTopLevelItem(ALiSong);
    ui->treeWidget->addTopLevelItem(DeHeYa);

    QStringList age1;
    age1<<"年龄:34";
    QStringList rating1;
    rating1<<"能力值:89";
    QStringList position1;
    position1<<"位置:门将/右脚";
    QStringList weeksalary1;
    weeksalary1<<"周薪:28";
    QStringList transferfee1;
    transferfee1<<"转会费:1450";
    QTreeWidgetItem *a1 = new QTreeWidgetItem(age1);
    NuoYiEr->addChild(a1);
    QTreeWidgetItem *r1 = new QTreeWidgetItem(rating1);
    NuoYiEr->addChild(r1);
    QTreeWidgetItem *p1 = new QTreeWidgetItem(position1);
    NuoYiEr->addChild(p1);
    QTreeWidgetItem *w1 = new QTreeWidgetItem(weeksalary1);
    NuoYiEr->addChild(w1);
    QTreeWidgetItem *t1 = new QTreeWidgetItem(transferfee1);
    NuoYiEr->addChild(t1);

    QStringList age2;
    age2<<"年龄:25";
    QStringList rating2;
    rating2<<"能力值:83";
    QStringList position2;
    position2<<"位置:门将/右脚";
    QStringList weeksalary2;
    weeksalary2<<"周薪:15";
    QStringList transferfee2;
    transferfee2<<"转会费:2800";
    QTreeWidgetItem *a2 = new QTreeWidgetItem(age2);
    KaiPa->addChild(a2);
    QTreeWidgetItem *r2 = new QTreeWidgetItem(rating2);
    KaiPa->addChild(r2);
    QTreeWidgetItem *p2 = new QTreeWidgetItem(position2);
    KaiPa->addChild(p2);
    QTreeWidgetItem *w2 = new QTreeWidgetItem(weeksalary2);
    KaiPa->addChild(w2);
    QTreeWidgetItem *t2 = new QTreeWidgetItem(transferfee2);
    KaiPa->addChild(t2);

    QStringList age3;
    age3<<"年龄:28";
    QStringList rating3;
    rating3<<"能力值:90";
    QStringList position3;
    position3<<"位置:门将/右脚";
    QStringList weeksalary3;
    weeksalary3<<"周薪:16";
    QStringList transferfee3;
    transferfee3<<"转会费:7200";
    QTreeWidgetItem *a3 = new QTreeWidgetItem(age3);
    TeErShiTeGen->addChild(a3);
    QTreeWidgetItem *r3 = new QTreeWidgetItem(rating3);
    TeErShiTeGen->addChild(r3);
    QTreeWidgetItem *p3 = new QTreeWidgetItem(position3);
    TeErShiTeGen->addChild(p3);
    QTreeWidgetItem *w3 = new QTreeWidgetItem(weeksalary3);
    TeErShiTeGen->addChild(w3);
    QTreeWidgetItem *t3 = new QTreeWidgetItem(transferfee3);
    TeErShiTeGen->addChild(t3);

    QStringList age4;
    age4<<"年龄:29";
    QStringList rating4;
    rating4<<"能力值:85";
    QStringList position4;
    position4<<"位置:门将/右脚";
    QStringList weeksalary4;
    weeksalary4<<"周薪:5";
    QStringList transferfee4;
    transferfee4<<"转会费:1100";
    QTreeWidgetItem *a4 = new QTreeWidgetItem(age4);
    BuErJi->addChild(a4);
    QTreeWidgetItem *r4 = new QTreeWidgetItem(rating4);
    BuErJi->addChild(r4);
    QTreeWidgetItem *p4 = new QTreeWidgetItem(position4);
    BuErJi->addChild(p4);
    QTreeWidgetItem *w4 = new QTreeWidgetItem(weeksalary4);
    BuErJi->addChild(w4);
    QTreeWidgetItem *t4 = new QTreeWidgetItem(transferfee4);
    BuErJi->addChild(t4);

    QStringList age5;
    age5<<"年龄:42";
    QStringList rating5;
    rating5<<"能力值:83";
    QStringList position5;
    position5<<"位置:门将/右脚";
    QStringList weeksalary5;
    weeksalary5<<"周薪:6";
    QStringList transferfee5;
    transferfee5<<"转会费:4000";
    QTreeWidgetItem *a5 = new QTreeWidgetItem(age5);
    BuFeng->addChild(a5);
    QTreeWidgetItem *r5 = new QTreeWidgetItem(rating5);
    BuFeng->addChild(r5);
    QTreeWidgetItem *p5 = new QTreeWidgetItem(position5);
    BuFeng->addChild(p5);
    QTreeWidgetItem *w5 = new QTreeWidgetItem(weeksalary5);
    BuFeng->addChild(w5);
    QTreeWidgetItem *t5 = new QTreeWidgetItem(transferfee5);
    BuFeng->addChild(t5);

    QStringList age6;
    age6<<"年龄:21";
    QStringList rating6;
    rating6<<"能力值:85";
    QStringList position6;
    position6<<"位置:门将/右脚";
    QStringList weeksalary6;
    weeksalary6<<"周薪:21";
    QStringList transferfee6;
    transferfee6<<"转会费:6000";
    QTreeWidgetItem *a6 = new QTreeWidgetItem(age6);
    DuoNaLuMa->addChild(a6);
    QTreeWidgetItem *r6 = new QTreeWidgetItem(rating6);
    DuoNaLuMa->addChild(r6);
    QTreeWidgetItem *p6 = new QTreeWidgetItem(position6);
    DuoNaLuMa->addChild(p6);
    QTreeWidgetItem *w6 = new QTreeWidgetItem(weeksalary6);
    DuoNaLuMa->addChild(w6);
    QTreeWidgetItem *t6 = new QTreeWidgetItem(transferfee6);
    DuoNaLuMa->addChild(t6);

    QStringList age7;
    age7<<"年龄:28";
    QStringList rating7;
    rating7<<"能力值:85";
    QStringList position7;
    position7<<"位置:门将/右脚";
    QStringList weeksalary7;
    weeksalary7<<"周薪:10";
    QStringList transferfee7;
    transferfee7<<"转会费:3200";
    QTreeWidgetItem *a7 = new QTreeWidgetItem(age7);
    LaiNuo->addChild(a7);
    QTreeWidgetItem *r7 = new QTreeWidgetItem(rating7);
    LaiNuo->addChild(r7);
    QTreeWidgetItem *p7 = new QTreeWidgetItem(position7);
    LaiNuo->addChild(p7);
    QTreeWidgetItem *w7 = new QTreeWidgetItem(weeksalary7);
    LaiNuo->addChild(w7);
    QTreeWidgetItem *t7 = new QTreeWidgetItem(transferfee7);
    LaiNuo->addChild(t7);

    QStringList age8;
    age8<<"年龄:27";
    QStringList rating8;
    rating8<<"能力值:90";
    QStringList position8;
    position8<<"位置:门将/右脚";
    QStringList weeksalary8;
    weeksalary8<<"周薪:9";
    QStringList transferfee8;
    transferfee8<<"转会费:7200";
    QTreeWidgetItem *a8 = new QTreeWidgetItem(age8);
    ALiSong->addChild(a8);
    QTreeWidgetItem *r8 = new QTreeWidgetItem(rating8);
    ALiSong->addChild(r8);
    QTreeWidgetItem *p8 = new QTreeWidgetItem(position8);
    ALiSong->addChild(p8);
    QTreeWidgetItem *w8 = new QTreeWidgetItem(weeksalary8);
    ALiSong->addChild(w8);
    QTreeWidgetItem *t8 = new QTreeWidgetItem(transferfee8);
    ALiSong->addChild(t8);

    QStringList age9;
    age9<<"年龄:29";
    QStringList rating9;
    rating9<<"能力值:88";
    QStringList position9;
    position9<<"位置:门将/右脚";
    QStringList weeksalary9;
    weeksalary9<<"周薪:37";
    QStringList transferfee9;
    transferfee9<<"转会费:4000";
    QTreeWidgetItem *a9 = new QTreeWidgetItem(age9);
    DeHeYa->addChild(a9);
    QTreeWidgetItem *r9 = new QTreeWidgetItem(rating9);
    DeHeYa->addChild(r9);
    QTreeWidgetItem *p9 = new QTreeWidgetItem(position9);
    DeHeYa->addChild(p9);
    QTreeWidgetItem *w9 = new QTreeWidgetItem(weeksalary9);
    DeHeYa->addChild(w9);
    QTreeWidgetItem *t9 = new QTreeWidgetItem(transferfee9);
    DeHeYa->addChild(t9);

    chooseTwoCheckBox();

}

ChooseGoalKeeperDialog::~ChooseGoalKeeperDialog()
{
    delete ui;
}

void ChooseGoalKeeperDialog::chooseTwoCheckBox()
{
    ckBox1 = 0;
    ckBox2 = 0;
    ckBox3 = 0;
    ckBox4 = 0;
    ckBox5 = 0;
    ckBox6 = 0;
    ckBox7 = 0;
    ckBox8 = 0;
    ckBox9 = 0;
    ckBoxSum = 0;
    connect(ui->checkBox,&QCheckBox::stateChanged,[=](){
        if (ckBox1 == 0)
            ckBox1 = 1;
        else
            ckBox1 = 0;
    });
    connect(ui->checkBox_2,&QCheckBox::stateChanged,[=](){
        if (ckBox2 == 0)
            ckBox2 = 1;
        else
            ckBox2 = 0;
    });
    connect(ui->checkBox_3,&QCheckBox::stateChanged,[=](){
        if (ckBox3 == 0)
            ckBox3 = 1;
        else
            ckBox3 = 0;
    });
    connect(ui->checkBox_4,&QCheckBox::stateChanged,[=](){
        if (ckBox4 == 0)
            ckBox4 = 1;
        else
            ckBox4 = 0;
    });
    connect(ui->checkBox_5,&QCheckBox::stateChanged,[=](){
        if (ckBox5 == 0)
            ckBox5 = 1;
        else
            ckBox5 = 0;
    });
    connect(ui->checkBox_6,&QCheckBox::stateChanged,[=](){
        if (ckBox6 == 0)
            ckBox6 = 1;
        else
            ckBox6 = 0;
    });
    connect(ui->checkBox_7,&QCheckBox::stateChanged,[=](){
        if (ckBox7 == 0)
            ckBox7 = 1;
        else
            ckBox7 = 0;
    });
    connect(ui->checkBox_8,&QCheckBox::stateChanged,[=](){
        if (ckBox8 == 0)
            ckBox8 = 1;
        else
            ckBox8 = 0;
    });
    connect(ui->checkBox_9,&QCheckBox::stateChanged,[=](){
        if (ckBox9 == 0)
            ckBox9 = 1;
        else
            ckBox9 = 0;
    });
    ckBoxSum = (ckBox1+ckBox2+ckBox3+ckBox4+ckBox5+ckBox6+ckBox7+ckBox8+ckBox9);
    if (ckBoxSum == 2)
    {
        if (ckBox1 == 0)
        {
            ui->checkBox->setDisabled(true);
        }
        if (ckBox2 == 0)
        {
            ui->checkBox_2->setDisabled(true);
        }
        if (ckBox3 == 0)
        {
            ui->checkBox_3->setDisabled(true);
        }
        if (ckBox4 == 0)
        {
            ui->checkBox_4->setDisabled(true);
        }
        if (ckBox5 == 0)
        {
            ui->checkBox_5->setDisabled(true);
        }
        if (ckBox6 == 0)
        {
            ui->checkBox_6->setDisabled(true);
        }
        if (ckBox7 == 0)
        {
            ui->checkBox_7->setDisabled(true);
        }
        if (ckBox8 == 0)
        {
            ui->checkBox_8->setDisabled(true);
        }
        if (ckBox9 == 0)
        {
            ui->checkBox_9->setDisabled(true);
        }
    }


}
