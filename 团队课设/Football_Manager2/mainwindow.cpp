#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "team.h"
#include "player.h"
#include "chooseteamdialog.h"
#include "afterchooseteamdialog.h"
#include "beforegame1dialog.h"
#include "beforegame2dialog.h"
#include "beforegame3dialog.h"
#include "beforegame4dialog.h"
#include "beforegame5dialog.h"
#include "aftergamewindialog_1.h"
#include "aftergamewindialog_2.h"
#include "aftergamewindialog_3.h"
#include "aftergamewindialog_4.h"
#include "aftergamefaildialog_1.h"
#include "aftergamefaildialog_2.h"
#include "aftergamefaildialog_3.h"
#include "aftergamefaildialog_4.h"
#include "aftergamefaildialog_5.h"
#include "aftergamedrawdialog_1.h"
#include "aftergamedrawdialog_2.h"
#include "aftergamedrawdialog_3.h"
#include "time.h"
#include <QDialog>
#include <QMenuBar>
#include <QDebug>
#include <QString>
#include <QPushButton>
#include <QRadioButton>
#include <QStatusBar>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>
#include <QList>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //球队名称
    {
        ftTeam[0].name="拜仁慕尼黑";
        ftTeam[1].name="切尔西";
        ftTeam[2].name="尤文图斯";
        ftTeam[3].name="阿森纳";
        ftTeam[4].name="利物浦";
        ftTeam[5].name="曼联";
        ftTeam[6].name="曼城";
        ftTeam[7].name="西汉姆联";
        ftTeam[8].name="埃弗顿";
        ftTeam[9].name="皇家马德里";
        ftTeam[10].name="巴塞罗那";
        ftTeam[11].name="马德里竞技";
        ftTeam[12].name="瓦伦西亚";
        ftTeam[13].name="皇家贝蒂斯";
        ftTeam[14].name="亚特兰大";
        ftTeam[15].name="国际米兰";
        ftTeam[16].name="AC米兰";
        ftTeam[17].name="多特蒙德";
        ftTeam[18].name="弗赖堡";
        ftTeam[19].name="巴黎圣日耳曼";
        ftTeam[20].name="勒沃库森";
    }

    //球员信息
    {
        players[0].name = "莱万多夫斯基";
        players[0].age = 32;
        players[0].rating = 91;
        players[0].position = "前锋/右脚";
        players[0].weeksalary = 30;
        players[0].transferfee = 5600;
        players[0].hurt = false;

        players[1].name = "穆勒";
        players[1].age = 30;
        players[1].rating = 85;
        players[1].position = "前锋/右脚";
        players[1].weeksalary = 28;
        players[1].transferfee = 3000;
        players[1].hurt = false;

        players[2].name = "格雷茨卡";
        players[2].age = 25;
        players[2].rating = 84;
        players[2].position = "中场/右脚";
        players[2].weeksalary = 15;
        players[2].transferfee = 5000;
        players[2].hurt = false;

        players[3].name = "埃尔南德斯";
        players[3].age = 24;
        players[3].rating = 84;
        players[3].position = "后卫/左脚";
        players[3].weeksalary = 25;
        players[3].transferfee = 5600;
        players[3].hurt = false;

        players[4].name = "基米希";
        players[4].age = 25;
        players[4].rating = 87;
        players[4].position = "后卫/右脚";
        players[4].weeksalary = 15;
        players[4].transferfee = 7500;
        players[4].hurt = false;

        players[5].name = "诺伊尔";
        players[5].age = 34;
        players[5].rating = 89;
        players[5].position = "门将/右脚";
        players[5].weeksalary = 28;
        players[5].transferfee = 1450;
        players[5].hurt = false;

        players[6].name = "吉鲁";
        players[6].age = 33;
        players[6].rating = 80;
        players[6].position = "前锋/左脚";
        players[6].weeksalary = 11;
        players[6].transferfee = 700;
        players[6].hurt = false;

        players[7].name = "亚伯拉罕";
        players[7].age = 22;
        players[7].rating = 79;
        players[7].position = "前锋/右脚";
        players[7].weeksalary = 5;
        players[7].transferfee = 4000;
        players[7].hurt = false;

        players[8].name = "维尔纳";
        players[8].age = 24;
        players[8].rating = 86;
        players[8].position = "前锋/右脚";
        players[8].weeksalary = 6;
        players[8].transferfee = 6400;
        players[8].hurt = false;

        players[9].name = "若日尼奥";
        players[9].age = 28;
        players[9].rating = 84;
        players[9].position = "中场/左右脚";
        players[9].weeksalary = 11;
        players[9].transferfee = 5200;
        players[9].hurt = false;

        players[10].name = "科瓦契奇";
        players[10].age = 26;
        players[10].rating = 84;
        players[10].position = "中场/右脚";
        players[10].weeksalary = 11;
        players[10].transferfee = 4000;
        players[10].hurt = false;

        players[11].name = "齐耶赫";
        players[11].age = 27;
        players[11].rating = 86;
        players[11].position = "中场/左脚";
        players[11].weeksalary = 15;
        players[11].transferfee = 4000;
        players[11].hurt = false;

        players[12].name = "普利西奇";
        players[12].age = 21;
        players[12].rating = 80;
        players[12].position = "中场/右脚";
        players[12].weeksalary = 14;
        players[12].transferfee = 6000;
        players[12].hurt = false;


        players[13].name = "芒特";
        players[13].age = 21;
        players[13].rating = 79;
        players[13].position = "中场/右脚";
        players[13].weeksalary = 7;
        players[13].transferfee = 4050;
        players[13].hurt = false;


        players[14].name = "阿斯皮利奎塔";
        players[14].age = 31;
        players[14].rating = 84;
        players[14].position = "后卫/右脚";
        players[14].weeksalary = 9;
        players[14].transferfee = 2400;
        players[14].hurt = false;


        players[15].name = "奇尔韦尔";
        players[15].age = 23;
        players[15].rating = 81;
        players[15].position = "后卫/左脚";
        players[15].weeksalary = 7;
        players[15].transferfee = 4000;
        players[15].hurt = false;


        players[16].name = "凯帕";
        players[16].age = 25;
        players[16].rating = 83;
        players[16].position = "门将/右脚";
        players[16].weeksalary = 15;
        players[16].transferfee = 2800;
        players[16].hurt = false;


        players[17].name = "奥巴梅扬";
        players[17].age = 31;
        players[17].rating = 88;
        players[17].position = "前锋/右脚";
        players[17].weeksalary = 20;
        players[17].transferfee = 5600;
        players[17].hurt = false;


        players[18].name = "威廉";
        players[18].age = 32;
        players[18].rating = 82;
        players[18].position = "前锋/右脚";
        players[18].weeksalary = 12;
        players[18].transferfee = 2250;
        players[18].hurt = false;


        players[19].name = "姆巴佩";
        players[19].age = 21;
        players[19].rating = 89;
        players[19].position = "前锋/右脚";
        players[19].weeksalary = 36;
        players[19].transferfee = 18000;
        players[19].hurt = false;


        players[20].name = "内马尔";
        players[20].age = 28;
        players[20].rating = 92;
        players[20].position = "前锋/右脚";
        players[20].weeksalary = 70;
        players[20].transferfee = 12800;
        players[20].hurt = false;


        players[21].name = "德拉克斯勒";
        players[21].age = 26;
        players[21].rating = 82;
        players[21].position = "中场/右脚";
        players[21].weeksalary = 14;
        players[21].transferfee = 2400;
        players[21].hurt = false;


        players[22].name = "金彭贝";
        players[22].age = 25;
        players[22].rating = 82;
        players[22].position = "后卫/左脚";
        players[22].weeksalary = 14;
        players[22].transferfee = 2800;
        players[22].hurt = false;

        players[23].name = "哈梅斯罗德里格斯";
        players[23].age = 29;
        players[23].rating = 85;
        players[23].position = "中场/左脚";
        players[23].weeksalary = 32;
        players[23].transferfee = 3200;
        players[23].hurt = false;

        players[24].name = "马塞洛";
        players[24].age = 32;
        players[24].rating = 84;
        players[24].position = "后卫/左脚";
        players[24].weeksalary = 38;
        players[24].transferfee =1600;
        players[24].hurt = false;

        players[25].name = "拉莫斯";
        players[25].age = 34;
        players[25].rating = 84;
        players[25].position = "后卫/右脚";
        players[25].weeksalary = 38;
        players[25].transferfee = 1450;
        players[25].hurt = false;

        players[26].name = "瓦拉内";
        players[26].age = 27;
        players[26].rating = 86;
        players[26].position = "后卫/右脚";
        players[26].weeksalary = 20;
        players[26].transferfee = 6400;
        players[26].hurt = false;

        players[27].name = "卡瓦哈尔";
        players[27].age = 28;
        players[27].rating = 85;
        players[27].position = "后卫/右脚";
        players[27].weeksalary = 16;
        players[27].transferfee = 6400;
        players[27].hurt = false;

        players[28].name = "迪巴拉";
        players[28].age = 26;
        players[28].rating = 91;
        players[28].position = "前锋/左脚";
        players[28].weeksalary = 26;
        players[28].transferfee = 8000;
        players[28].hurt = false;

        players[29].name = "罗纳尔多";
        players[29].age = 35;
        players[29].rating = 93;
        players[29].position = "前锋/右脚";
        players[29].weeksalary = 110;
        players[29].transferfee = 6000;
        players[29].hurt = false;

        players[30].name = "拉姆塞";
        players[30].age = 29;
        players[30].rating = 83;
        players[30].position = "中场/右脚";
        players[30].weeksalary = 44;
        players[30].transferfee = 2200;
        players[30].hurt = false;

        players[31].name = "阿图尔";
        players[31].age = 24;
        players[31].rating = 85;
        players[31].position = "中场/右脚";
        players[31].weeksalary = 9;
        players[31].transferfee = 5600;
        players[31].hurt = false;

        players[32].name = "本坦库尔";
        players[32].age = 23;
        players[32].rating = 80;
        players[32].position = "中场/右脚";
        players[32].weeksalary = 9;
        players[32].transferfee = 5000;
        players[32].hurt = false;

        players[33].name = "德西利奥";
        players[33].age = 27;
        players[33].rating = 77;
        players[33].position = "后卫/右脚";
        players[33].weeksalary = 11;
        players[33].transferfee = 750;
        players[33].hurt = false;

        players[34].name = "德里赫特";
        players[34].age = 21;
        players[34].rating = 85;
        players[34].position = "后卫/右脚";
        players[34].weeksalary = 20;
        players[34].transferfee = 7000;
        players[34].hurt = false;

        players[35].name = "巴尔特拉";
        players[35].age = 29;
        players[35].rating = 83;
        players[35].position = "后卫/右脚";
        players[35].weeksalary = 7;
        players[35].transferfee = 1400;
        players[35].hurt = false;

        players[36].name = "哈弗茨";
        players[36].age = 21;
        players[36].rating = 84;
        players[36].position = "中场/左脚";
        players[36].weeksalary = 3;
        players[36].transferfee = 8100;
        players[36].hurt = false;

        players[37].name = "阿扎尔";
        players[37].age = 29;
        players[37].rating = 91;
        players[37].position = "前锋/左右脚";
        players[37].weeksalary = 60;
        players[37].transferfee = 8000;
        players[37].hurt = false;

        players[38].name = "贝尔";
        players[38].age = 31;
        players[38].rating = 85;
        players[38].position = "前锋/左脚";
        players[38].weeksalary = 53;
        players[38].transferfee = 2800;
        players[38].hurt = false;

        players[39].name = "阿森西奥";
        players[39].age = 24;
        players[39].rating = 82;
        players[39].position = "前锋/左脚";
        players[39].weeksalary = 16;
        players[39].transferfee = 4000;
        players[39].hurt = false;

        players[40].name = "罗德里戈";
        players[40].age = 19;
        players[40].rating = 83;
        players[40].position = "前锋/右脚";
        players[40].weeksalary = 16;
        players[40].transferfee = 4500;
        players[40].hurt = false;

        players[41].name = "克罗斯";
        players[41].age = 30;
        players[41].rating = 87;
        players[41].position = "中场/左右脚";
        players[41].weeksalary = 38;
        players[41].transferfee = 4800;
        players[41].hurt = false;

        players[42].name = "莫德里奇";
        players[42].age = 34;
        players[42].rating = 89;
        players[42].position = "中场/左右脚";
        players[42].weeksalary = 36;
        players[42].transferfee = 1200;
        players[42].hurt = false;

        players[43].name = "巴斯克斯";
        players[43].age = 29;
        players[43].rating = 80;
        players[43].position = "中场/右脚";
        players[43].weeksalary = 7;
        players[43].transferfee = 1600;
        players[43].hurt = false;

        players[44].name = "卡塞米罗";
        players[44].age = 28;
        players[44].rating = 88;
        players[44].position = "中场/右脚";
        players[44].weeksalary = 19;
        players[44].transferfee = 6400;
        players[44].hurt = false;

        players[45].name = "菲尔米诺";
        players[45].age = 28;
        players[45].rating = 88;
        players[45].position = "前锋/右脚";
        players[45].weeksalary = 18;
        players[45].transferfee = 7200;
        players[45].hurt = false;

        players[46].name = "萨拉赫";
        players[46].age = 28;
        players[46].rating = 90;
        players[46].position = "前锋/左脚";
        players[46].weeksalary = 20;
        players[46].transferfee = 12000;
        players[46].hurt = false;

        players[47].name = "马内";
        players[47].age = 28;
        players[47].rating = 90;
        players[47].position = "前锋/右脚";
        players[47].weeksalary = 15;
        players[47].transferfee = 12000;
        players[47].hurt = false;

        players[48].name = "张伯伦";
        players[48].age = 27;
        players[48].rating = 80;
        players[48].position = "中场/右脚";
        players[48].weeksalary = 12;
        players[48].transferfee = 2800;
        players[48].hurt = false;

        players[49].name = "亨德森";
        players[49].age = 30;
        players[49].rating = 85;
        players[49].position = "中场/右脚";
        players[49].weeksalary = 14;
        players[49].transferfee = 2800;
        players[49].hurt = false;

        players[50].name = "阿诺德";
        players[50].age = 21;
        players[50].rating = 85;
        players[50].position = "后卫/右脚";
        players[50].weeksalary = 4;
        players[50].transferfee = 11000;
        players[50].hurt = false;

        players[51].name = "范戴克";
        players[51].age = 29;
        players[51].rating = 91;
        players[51].position = "后卫/右脚";
        players[51].weeksalary = 18;
        players[51].transferfee = 8000;
        players[51].hurt = false;

        players[52].name = "罗伯逊";
        players[52].age = 26;
        players[52].rating = 86;
        players[52].position = "后卫/左脚";
        players[52].weeksalary = 5;
        players[52].transferfee = 6400;
        players[52].hurt = false;

        players[53].name = "马蒂普";
        players[53].age = 29;
        players[53].rating = 83;
        players[53].position = "后卫/右脚";
        players[53].weeksalary = 10;
        players[53].transferfee = 3200;
        players[53].hurt = false;

        players[54].name = "赖斯";
        players[54].age = 21;
        players[54].rating = 80;
        players[54].position = "中场/右脚";
        players[54].weeksalary = 6;
        players[54].transferfee = 4950;
        players[54].hurt = false;

        players[55].name = "斯特林";
        players[55].age = 25;
        players[55].rating = 88;
        players[55].position = "前锋/右脚";
        players[55].weeksalary = 15;
        players[55].transferfee =12800;
        players[55].hurt = false;

        players[56].name = "热苏斯";
        players[56].age = 23;
        players[56].rating = 82;
        players[56].position = "前锋/右脚";
        players[56].weeksalary = 9;
        players[56].transferfee = 5600;
        players[56].hurt = false;

        players[57].name = "马赫雷斯";
        players[57].age = 29;
        players[57].rating = 86;
        players[57].position = "前锋/左脚";
        players[57].weeksalary = 20;
        players[57].transferfee = 4800;
        players[57].hurt = false;

        players[58].name = "阿圭罗";
        players[58].age = 32;
        players[58].rating = 89;
        players[58].position = "前锋/左右脚";
        players[58].weeksalary = 23;
        players[58].transferfee = 5200;
        players[58].hurt = false;

        players[59].name = "伯纳多席尔瓦";
        players[59].age = 26;
        players[59].rating = 87;
        players[59].position = "中场/左脚";
        players[59].weeksalary = 15;
        players[59].transferfee = 8000;
        players[59].hurt = false;

        players[60].name = "德布劳内";
        players[60].age = 29;
        players[60].rating = 91;
        players[60].position = "中场/左右脚";
        players[60].weeksalary = 35;
        players[60].transferfee = 12000;
        players[60].hurt = false;

        players[61].name = "福登";
        players[61].age = 20;
        players[61].rating = 77;
        players[61].position = "中场/左脚";
        players[61].weeksalary = 2;
        players[61].transferfee = 4000;
        players[61].hurt = false;

        players[62].name = "门迪";
        players[62].age = 26;
        players[62].rating = 80;
        players[62].position = "后卫/左脚";
        players[62].weeksalary = 10;
        players[62].transferfee = 2800;
        players[62].hurt = false;

        players[63].name = "斯通斯";
        players[63].age = 26;
        players[63].rating = 81;
        players[63].position = "后卫/右脚";
        players[63].weeksalary = 10;
        players[63].transferfee = 3000;
        players[63].hurt = false;

        players[64].name = "格列兹曼";
        players[64].age = 29;
        players[64].rating = 89;
        players[64].position = "前锋/左脚";
        players[64].weeksalary = 68;
        players[64].transferfee = 9600;
        players[64].hurt = false;

        players[65].name = "梅西";
        players[65].age = 33;
        players[65].rating = 94;
        players[65].position = "前锋/左脚";
        players[65].weeksalary = 136;
        players[65].transferfee = 11200;
        players[65].hurt = false;

        players[66].name = "苏亚雷斯";
        players[66].age = 33;
        players[66].rating = 89;
        players[66].position = "前锋/右脚";
        players[66].weeksalary = 45;
        players[66].transferfee = 2800;
        players[66].hurt = false;

        players[67].name = "库蒂尼奥";
        players[67].age = 28;
        players[67].rating = 85;
        players[67].position = "中场/右脚";
        players[67].weeksalary = 47;
        players[67].transferfee = 5600;
        players[67].hurt = false;

        players[68].name = "德容";
        players[68].age = 23;
        players[68].rating = 86;
        players[68].position = "中场/右脚";
        players[68].weeksalary = 40;
        players[68].transferfee = 7200;
        players[68].hurt = false;

        players[69].name = "罗贝托";
        players[69].age = 28;
        players[69].rating = 82;
        players[69].position = "后卫/右脚";
        players[69].weeksalary = 19;
        players[69].transferfee = 4000;
        players[69].hurt = false;

        players[70].name = "皮克";
        players[70].age = 33;
        players[70].rating = 88;
        players[70].position = "后卫/右脚";
        players[70].weeksalary = 24;
        players[70].transferfee = 2000;
        players[70].hurt = false;

        players[71].name = "特尔施特根";
        players[71].age = 28;
        players[71].rating =90;
        players[71].position = "门将/右脚";
        players[71].weeksalary = 16;
        players[71].transferfee = 7200;
        players[71].hurt = false;

        players[72].name = "格纳布里";
        players[72].age = 25;
        players[72].rating = 85;
        players[72].position = "前锋/右脚";
        players[72].weeksalary = 9;
        players[72].transferfee = 7200;
        players[72].hurt = false;

        players[73].name = "萨内";
        players[73].age = 24;
        players[73].rating = 86;
        players[73].position = "前锋/左脚";
        players[73].weeksalary = 9;
        players[73].transferfee = 8000;
        players[73].hurt = false;

        players[74].name = "马丁内斯";
        players[74].age = 32;
        players[74].rating = 82;
        players[74].position = "中场/右脚";
        players[74].weeksalary = 11;
        players[74].transferfee = 1300;
        players[74].hurt = false;

        players[75].name = "托利索";
        players[75].age = 26;
        players[75].rating = 82;
        players[75].position = "中场/右脚";
        players[75].weeksalary = 13;
        players[75].transferfee = 2550;
        players[75].hurt = false;

        players[76].name = "阿拉巴";
        players[76].age = 28;
        players[76].rating = 83;
        players[76].position = "后卫/左脚";
        players[76].weeksalary = 19;
        players[76].transferfee = 6500;
        players[76].hurt = false;

        players[77].name = "帕瓦尔";
        players[77].age = 24;
        players[77].rating = 80;
        players[77].position = "后卫/右脚";
        players[77].weeksalary = 2;
        players[77].transferfee = 4000;
        players[77].hurt = false;

        players[78].name = "阿方索戴维斯";
        players[78].age = 19;
        players[78].rating = 77;
        players[78].position = "后卫/左脚";
        players[78].weeksalary = 5;
        players[78].transferfee = 6000;
        players[78].hurt = false;

        players[79].name = "哈兰德";
        players[79].age = 20;
        players[79].rating = 80;
        players[79].position = "前锋/左脚";
        players[79].weeksalary =8;
        players[79].transferfee = 7200;
        players[79].hurt = false;

        players[80].name = "布兰特";
        players[80].age = 24;
        players[80].rating = 84;
        players[80].position = "前锋/右脚";
        players[80].weeksalary = 8;
        players[80].transferfee = 4000;
        players[80].hurt = false;

        players[81].name = "罗伊斯";
        players[81].age = 31;
        players[81].rating = 87;
        players[81].position = "前锋/右脚";
        players[81].weeksalary = 21;
        players[81].transferfee = 2500;
        players[81].hurt = false;

        players[82].name = "桑乔";
        players[82].age = 20;
        players[82].rating = 86;
        players[82].position = "中场/右脚";
        players[82].weeksalary = 4;
        players[82].transferfee = 11700;
        players[82].hurt = false;

        players[83].name = "胡梅尔斯";
        players[83].age = 31;
        players[83].rating = 87;
        players[83].position = "后卫/右脚";
        players[83].weeksalary = 19;
        players[83].transferfee = 2400;
        players[83].hurt = false;

        players[84].name = "默尼耶";
        players[84].age = 28;
        players[84].rating = 81;
        players[84].position = "后卫/右脚";
        players[84].weeksalary = 6;
        players[84].transferfee = 2400;
        players[84].hurt = false;

        players[85].name = "布尔基";
        players[85].age = 29;
        players[85].rating = 85;
        players[85].position = "门将/右脚";
        players[85].weeksalary = 5;
        players[85].transferfee = 1100;
        players[85].hurt = false;

        players[86].name = "弗兰德";
        players[86].age = 28;
        players[86].rating = 82;
        players[86].position = "前锋/左脚";
        players[86].weeksalary = 10;
        players[86].transferfee = 2800;
        players[86].hurt = false;

        players[87].name = "伊卡尔迪";
        players[87].age = 27;
        players[87].rating = 86;
        players[87].position = "前锋/右脚";
        players[87].weeksalary = 24;
        players[87].transferfee = 6000;
        players[87].hurt = false;

        players[88].name = "维拉蒂";
        players[88].age = 27;
        players[88].rating = 87;
        players[88].position = "中场/右脚";
        players[88].weeksalary = 14;
        players[88].transferfee = 6000;
        players[88].hurt = false;

        players[89].name = "马尔基尼奥斯";
        players[89].age = 26;
        players[89].rating = 86;
        players[89].position = "后卫/右脚";
        players[89].weeksalary = 26;
        players[89].transferfee = 5200;
        players[89].hurt = false;

        players[90].name = "布冯";
        players[90].age = 42;
        players[90].rating = 83;
        players[90].position = "门将/右脚";
        players[90].weeksalary = 6;
        players[90].transferfee = 4000;
        players[90].hurt = false;

        players[91].name = "博努奇";
        players[91].age = 33;
        players[91].rating = 86;
        players[91].position = "后卫/右脚";
        players[91].weeksalary = 20;
        players[91].transferfee = 1800;
        players[91].hurt = false;

        players[92].name = "多纳鲁马";
        players[92].age = 21;
        players[92].rating = 85;
        players[92].position = "门将/右脚";
        players[92].weeksalary = 21;
        players[92].transferfee = 6000;
        players[92].hurt = false;

        players[93].name = "卢卡库";
        players[93].age = 27;
        players[93].rating = 86;
        players[93].position = "前锋/左脚";
        players[93].weeksalary = 18;
        players[93].transferfee = 8500;
        players[93].hurt = false;

        players[94].name = "桑切斯";
        players[94].age = 31;
        players[94].rating = 81;
        players[94].position = "前锋/右脚";
        players[94].weeksalary = 38;
        players[94].transferfee = 1600;
        players[94].hurt = false;

        players[95].name = "埃里克森";
        players[95].age = 28;
        players[95].rating = 87;
        players[95].position = "中场/左右脚";
        players[95].weeksalary = 32;
        players[95].transferfee = 6000;
        players[95].hurt = false;

        players[96].name = "戈丁";
        players[96].age = 34;
        players[96].rating = 87;
        players[96].position = "后卫/右脚";
        players[96].weeksalary = 12;
        players[96].transferfee = 5000;
        players[96].hurt = false;

        players[97].name = "莱诺";
        players[97].age = 28;
        players[97].rating = 85;
        players[97].position = "门将/右脚";
        players[97].weeksalary = 10;
        players[97].transferfee = 3200;
        players[97].hurt = false;

        players[98].name = "阿利松";
        players[98].age = 27;
        players[98].rating = 90;
        players[98].position = "门将/右脚";
        players[98].weeksalary = 9;
        players[98].transferfee = 7200;
        players[98].hurt = false;

        players[99].name = "德赫亚";
        players[99].age = 29;
        players[99].rating = 88;
        players[99].position = "门将/右脚";
        players[99].weeksalary = 37;
        players[99].transferfee = 4000;
        players[99].hurt = false;
    }

    //对方球队以及球员信息
    {
        oppteam[0].name = QString("切尔西");
        oppteam[0].players[0].name = QString("T.维尔纳");
        oppteam[0].players[0].age = 24;
        oppteam[0].players[0].position = QString("前锋/右脚");

        oppteam[0].players[1].name = QString("O.吉鲁");
        oppteam[0].players[1].age = 33;
        oppteam[0].players[1].position = QString("前锋/左脚");

        oppteam[0].players[2].name = QString ("N.坎特");
        oppteam[0].players[2].age = 29;
        oppteam[0].players[2].position = QString("中场/右脚");

        oppteam[0].players[3].name = QString( "哈弗茨");
        oppteam[0].players[3].age = 21;
        oppteam[0].players[3].position = QString("中场/右脚");

        oppteam[0].players[4].name = QString("克里斯蒂安.普利西奇");
        oppteam[0].players[4].age = 21;
        oppteam[0].players[4].position = QString("中场/右脚");

        oppteam[0].players[5].name = QString( "H.齐耶赫");
        oppteam[0].players[5].age = 27;
        oppteam[0].players[5].position = QString("中场/左脚");

        oppteam[0].players[6].name = QString("马科斯阿隆索");
        oppteam[0].players[6].age = 29;
        oppteam[0].players[6].position = QString( "后卫/左脚");

        oppteam[0].players[7].name = QString("塞萨尔阿斯皮利奎塔");
        oppteam[0].players[7].age = 31;
        oppteam[0].players[7].position = QString( "后卫/右脚");

        oppteam[0].players[8].name = QString("本奇尔韦尔");
        oppteam[0].players[8].age = 23;
        oppteam[0].players[8].position = QString( "后卫/左脚");

        oppteam[0].players[9].name = QString( "蒂亚戈.席尔瓦");
        oppteam[0].players[9].age = 35;
        oppteam[0].players[9].position = QString("后卫/右脚");

        oppteam[0].players[10].name = QString("凯帕阿里萨巴拉加");
        oppteam[0].players[10].age = 25;
        oppteam[0].players[10].position = QString( "门将/右脚");

        oppteam[1].name = QString("拜仁慕尼黑");
        oppteam[1].players[0].name = QString( "格纳布里");
        oppteam[1].players[0].age = 25;
        oppteam[1].players[0].position = QString( "前锋/右脚");

        oppteam[1].players[1].name = QString("莱万多夫斯基");
        oppteam[1].players[1].age = 32;
        oppteam[1].players[1].position = QString( "前锋/右脚");

        oppteam[1].players[2].name = QString("萨内");
        oppteam[1].players[2].age = 24;
        oppteam[1].players[2].position = QString("前锋/左脚");

        oppteam[1].players[3].name = QString( "托马斯.穆勒");
        oppteam[1].players[3].age = 31;
        oppteam[1].players[3].position = QString("前锋/右脚");

        oppteam[1].players[4].name = QString( "莱昂格雷茨卡");
        oppteam[1].players[4].age = 25;
        oppteam[1].players[4].position = QString("中场/右脚");

        oppteam[1].players[5].name = QString( "蒂亚戈A");
        oppteam[1].players[5].age = 29;
        oppteam[1].players[5].position = QString("中场/右脚");

        oppteam[1].players[6].name = QString("阿方索戴维斯");
        oppteam[1].players[6].age = 19;
        oppteam[1].players[6].position = QString("后卫/左脚");

        oppteam[1].players[7].name = QString( "阿拉巴");
        oppteam[1].players[7].age = 28;
        oppteam[1].players[7].position = QString("后卫/左脚");

        oppteam[1].players[8].name = QString("热罗姆博阿滕");
        oppteam[1].players[8].age = 32;
        oppteam[1].players[8].position = QString("后卫/右脚");

        oppteam[1].players[9].name = QString( "基米西");
        oppteam[1].players[9].age = 25;
        oppteam[1].players[9].position = QString("后卫/右脚");

        oppteam[1].players[10].name = QString("诺伊尔");
        oppteam[1].players[10].age = 34;
        oppteam[1].players[10].position = QString( "门将/右脚");

        oppteam[2].name = QString( "阿森纳");
        oppteam[2].players[0].name = QString("穆斯塔菲");
        oppteam[2].players[0].age = 28;
        oppteam[2].players[0].position = QString("后卫/右脚");

        oppteam[2].players[1].name = QString("大卫.路易斯");
        oppteam[2].players[1].age = 33;
        oppteam[2].players[1].position = QString("后卫/右脚");

        oppteam[2].players[2].name = QString("蒂尔尼");
        oppteam[2].players[2].age = 23;
        oppteam[2].players[2].position = QString("后卫/左脚");

        oppteam[2].players[3].name = QString("贝莱林");
        oppteam[2].players[3].age = 25;
        oppteam[2].players[3].position = QString("后卫/右脚");

        oppteam[2].players[4].name = QString("塞瓦略斯");
        oppteam[2].players[4].age = 24;
        oppteam[2].players[4].position = QString("中场/右脚");

        oppteam[2].players[5].name = QString("扎卡");
        oppteam[2].players[5].age = 27;
        oppteam[2].players[5].position = QString("中场/左脚");

        oppteam[2].players[6].name = QString("梅特兰奈尔斯");
        oppteam[2].players[6].age = 23;
        oppteam[2].players[6].position = QString("中场/右脚");

        oppteam[2].players[7].name = QString("尼古拉佩佩");
        oppteam[2].players[7].age = 25;
        oppteam[2].players[7].position = QString("前锋/左脚");

        oppteam[2].players[8].name = QString("拉卡泽特");
        oppteam[2].players[8].age = 29;
        oppteam[2].players[8].position = QString("前锋/右脚");

        oppteam[2].players[9].name = QString("奥巴梅杨");
        oppteam[2].players[9].age = 31;
        oppteam[2].players[9].position = QString("前锋/右脚");

        oppteam[2].players[10].name = QString( "达米安马丁内斯");
        oppteam[2].players[10].age = 28;
        oppteam[2].players[10].position = QString( "门将/右脚");

        oppteam[3].name  = QString("巴黎圣日耳曼");
        oppteam[3].players[0].name = QString("K.姆巴佩");
        oppteam[3].players[0].age = 21;
        oppteam[3].players[0].position = QString("前锋/右脚");

        oppteam[3].players[1].name = QString("Neymar");
        oppteam[3].players[1].age = 28;
        oppteam[3].players[1].position = QString ("前锋/右脚");

        oppteam[3].players[2].name = QString( "迪玛利亚");
        oppteam[3].players[2].age = 32;
        oppteam[3].players[2].position = QString( "中场/左脚");

        oppteam[3].players[3].name = QString("帕雷德斯");
        oppteam[3].players[3].age = 26;
        oppteam[3].players[3].position = QString("中场/右脚");

        oppteam[3].players[4].name = QString("马尔基尼奥斯");
        oppteam[3].players[4].age = 26;
        oppteam[3].players[4].position = QString("后卫/右脚");

        oppteam[3].players[5].name = QString("埃雷拉");
        oppteam[3].players[5].age = 31;
        oppteam[3].players[5].position = QString("中场/右脚");

        oppteam[3].players[6].name = QString("贝尔纳特");
        oppteam[3].players[6].age = 27;
        oppteam[3].players[6].position = QString("后卫/左脚");

        oppteam[3].players[7].name = QString("金彭贝");
        oppteam[3].players[7].age = 25;
        oppteam[3].players[7].position = QString("后卫/左脚");

        oppteam[3].players[8].name = QString("蒂洛科雷尔");
        oppteam[3].players[8].age = 23;
        oppteam[3].players[8].position = QString("后卫/右脚");

        oppteam[3].players[9].name = QString("里科");
        oppteam[3].players[9].age = 27;
        oppteam[3].players[9].position = QString("门将/右脚");

        oppteam[3].players[10].name = QString("库尔扎瓦");
        oppteam[3].players[10].age = 28;
        oppteam[3].players[10].position = QString("后卫/左脚");

        oppteam[4].name = QString("皇家马德里") ;
        oppteam[4].players[0].name = QString("阿森西奥");
        oppteam[4].players[0].age = 24;
        oppteam[4].players[0].position = QString("前锋/左脚");

        oppteam[4].players[1].name = QString("本泽马");
        oppteam[4].players[1].age = 32;
        oppteam[4].players[1].position = QString("前锋/左右脚");

        oppteam[4].players[2].name = QString("罗德里戈");
        oppteam[4].players[2].age = 19;
        oppteam[4].players[2].position = QString("前锋/右脚");

        oppteam[4].players[3].name = QString( "莫德里奇");
        oppteam[4].players[3].age = 35;
        oppteam[4].players[3].position = QString("中场/左右脚");

        oppteam[4].players[4].name = QString("卡塞米罗");
        oppteam[4].players[4].age = 28;
        oppteam[4].players[4].position = QString("中场/左右脚");

        oppteam[4].players[5].name = QString("费德里科巴尔韦德");
        oppteam[4].players[5].age = 22;
        oppteam[4].players[5].position = QString("中场/右脚");

        oppteam[4].players[6].name = QString("马塞洛");
        oppteam[4].players[6].age = 32;
        oppteam[4].players[6].position = QString("后卫/左脚");

        oppteam[4].players[7].name = QString("拉莫斯");
        oppteam[4].players[7].age = 34;
        oppteam[4].players[7].position = QString("后卫/右脚");

        oppteam[4].players[8].name = QString("米利唐");
        oppteam[4].players[8].age = 22;
        oppteam[4].players[8].position = QString("后卫/右脚");

        oppteam[4].players[9].name = QString("卡瓦哈尔");
        oppteam[4].players[9].age = 28;
        oppteam[4].players[9].position = QString("后卫/右脚");

        oppteam[4].players[10].name = QString("库尔图瓦");
        oppteam[4].players[10].age = 28;
        oppteam[4].players[10].position = QString("门将/左脚");

        oppteam[5].name = QString("尤文图斯") ;
        oppteam[5].players[0].name = QString("C罗");
        oppteam[5].players[0].age = 35;
        oppteam[5].players[0].position = QString("前锋/右脚");

        oppteam[5].players[1].name = QString("P.迪巴拉");
        oppteam[5].players[1].age = 26;
        oppteam[5].players[1].position = QString("前锋/左脚");

        oppteam[5].players[2].name = QString("F.贝尔纳代斯基");
        oppteam[5].players[2].age = 26;
        oppteam[5].players[2].position = QString("前锋/左脚");

        oppteam[5].players[3].name = QString("拉比奥");
        oppteam[5].players[3].age = 25;
        oppteam[5].players[3].position = QString("中场/左脚");

        oppteam[5].players[4].name = QString("A.拉姆塞");
        oppteam[5].players[4].age = 29;
        oppteam[5].players[4].position = QString("中场/右脚");

        oppteam[5].players[5].name = QString("本坦库尔");
        oppteam[5].players[5].age = 23;
        oppteam[5].players[5].position = QString("中场/右脚");

        oppteam[5].players[6].name = QString("达尼洛");
        oppteam[5].players[6].age = 29;
        oppteam[5].players[6].position = QString("后卫/右脚");

        oppteam[5].players[7].name = QString("博努奇");
        oppteam[5].players[7].age = 33;
        oppteam[5].players[7].position = QString("后卫/左脚");

        oppteam[5].players[8].name = QString("M.德利赫特");
        oppteam[5].players[8].age = 21;
        oppteam[5].players[8].position = QString("后卫/右脚");

        oppteam[5].players[9].name = QString("J.夸德拉多");
        oppteam[5].players[9].age = 32;
        oppteam[5].players[9].position = QString("中场/右脚");

        oppteam[5].players[10].name = QString("G.布冯");
        oppteam[5].players[10].age = 42;
        oppteam[5].players[10].position = QString("门将/右脚");

        oppteam[6].name = QString("弗赖堡") ;
        oppteam[6].players[0].name = QString("瓦尔德施密特");
        oppteam[6].players[0].age = 24;
        oppteam[6].players[0].position = QString("前锋/左脚");

        oppteam[6].players[1].name = QString("霍勒");
        oppteam[6].players[1].age = 26;
        oppteam[6].players[1].position = QString("前锋/右脚");

        oppteam[6].players[2].name = QString("绍洛伊");
        oppteam[6].players[2].age = 23;
        oppteam[6].players[2].position = QString("前锋/右脚");

        oppteam[6].players[3].name = QString("霍夫勒");
        oppteam[6].players[3].age = 30;
        oppteam[6].players[3].position = QString("中场/右脚");

        oppteam[6].players[4].name = QString("阿布拉希");
        oppteam[6].players[4].age = 30;
        oppteam[6].players[4].position = QString("中场/右脚");

        oppteam[6].players[5].name = QString("格里福");
        oppteam[6].players[5].age = 27;
        oppteam[6].players[5].position = QString("中场/右脚");

        oppteam[6].players[6].name = QString("京特尔");
        oppteam[6].players[6].age = 27;
        oppteam[6].players[6].position = QString("后卫/左脚");

        oppteam[6].players[7].name = QString("曼纽尔古尔德");
        oppteam[6].players[7].age = 29;
        oppteam[6].players[7].position = QString("后卫/右脚");

        oppteam[6].players[8].name = QString("科赫");
        oppteam[6].players[8].age = 24;
        oppteam[6].players[8].position = QString("后卫/右脚");

        oppteam[6].players[9].name = QString("施密德");
        oppteam[6].players[9].age = 30;
        oppteam[6].players[9].position = QString("中场/右脚");

        oppteam[6].players[10].name = QString("施沃洛夫");
        oppteam[6].players[10].age = 28;
        oppteam[6].players[10].position = QString("门将/右脚");

        oppteam[7].name = QString("西汉姆联");
        oppteam[7].players[0].name = QString("安东尼奥");
        oppteam[7].players[0].age = 30;
        oppteam[7].players[0].position = QString("中场/右脚");

        oppteam[7].players[1].name = QString("诺布尔");
        oppteam[7].players[1].age = 33;
        oppteam[7].players[1].position = QString("中场/右脚");

        oppteam[7].players[2].name = QString("鲍恩");
        oppteam[7].players[2].age = 23;
        oppteam[7].players[2].position = QString("前锋/左脚");

        oppteam[7].players[3].name = QString("德克兰.赖斯");
        oppteam[7].players[3].age = 21;
        oppteam[7].players[3].position = QString("中场/右脚");

        oppteam[7].players[4].name = QString("绍切克");
        oppteam[7].players[4].age = 25;
        oppteam[7].players[4].position = QString("中场/右脚");

        oppteam[7].players[5].name = QString("本.约翰逊");
        oppteam[7].players[5].age = 20;
        oppteam[7].players[5].position = QString("中场/右脚");

        oppteam[7].players[6].name = QString("奥邦纳");
        oppteam[7].players[6].age = 32;
        oppteam[7].players[6].position = QString("后卫/左脚");

        oppteam[7].players[7].name = QString("伊萨.迪奥普");
        oppteam[7].players[7].age = 23;
        oppteam[7].players[7].position = QString("后卫/右脚");

        oppteam[7].players[8].name = QString("弗雷德里克斯");
        oppteam[7].players[8].age = 27;
        oppteam[7].players[8].position = QString("后卫/右脚");

        oppteam[7].players[9].name = QString("法比安斯基");
        oppteam[7].players[9].age = 35;
        oppteam[7].players[9].position = QString("门将/右脚");

        oppteam[7].players[10].name = QString("阿莱");
        oppteam[7].players[10].age = 26;
        oppteam[7].players[10].position = QString("前锋/右脚");

        oppteam[8].name = QString("纽卡斯尔联") ;
        oppteam[8].players[0].name = QString("盖尔");
        oppteam[8].players[0].age = 29;
        oppteam[8].players[0].position = QString("前锋/右脚");

        oppteam[8].players[1].name = QString("圣马克西曼");
        oppteam[8].players[1].age = 23;
        oppteam[8].players[1].position = QString("中场/右脚");

        oppteam[8].players[2].name = QString("里奇");
        oppteam[8].players[2].age = 31;
        oppteam[8].players[2].position = QString("中场/左脚");

        oppteam[8].players[3].name = QString("阿尔米隆");
        oppteam[8].players[3].age = 26;
        oppteam[8].players[3].position = QString("中场/左脚");

        oppteam[8].players[4].name = QString("本塔莱布");
        oppteam[8].players[4].age = 25;
        oppteam[8].players[4].position = QString("中场/左脚");

        oppteam[8].players[5].name = QString("谢尔维");
        oppteam[8].players[5].age = 28;
        oppteam[8].players[5].position = QString("中场/右脚");

        oppteam[8].players[6].name = QString("拉扎罗");
        oppteam[8].players[6].age = 24;
        oppteam[8].players[6].position = QString("中场/右脚");

        oppteam[8].players[7].name = QString("丹尼.罗斯");
        oppteam[8].players[7].age = 30;
        oppteam[8].players[7].position = QString("后卫/左脚");

        oppteam[8].players[8].name = QString("费尔南德斯");
        oppteam[8].players[8].age = 31;
        oppteam[8].players[8].position = QString("后卫/右脚");

        oppteam[8].players[9].name = QString("曼基略");
        oppteam[8].players[9].age = 26;
        oppteam[8].players[9].position = QString("后卫/右脚");

        oppteam[8].players[10].name = QString("杜布拉夫卡");
        oppteam[8].players[10].age = 31;
        oppteam[8].players[10].position = QString("门将/右脚");

        oppteam[9].name = QString("曼联") ;
        oppteam[9].players[0].name = QString("拉什福德");
        oppteam[9].players[0].age = 22;
        oppteam[9].players[0].position = QString("前锋/右脚");

        oppteam[9].players[1].name = QString("丹尼尔.詹姆斯");
        oppteam[9].players[1].age = 22;
        oppteam[9].players[1].position = QString("中场/右脚");

        oppteam[9].players[2].name = QString("布鲁诺.费尔南德斯");
        oppteam[9].players[2].age = 26;
        oppteam[9].players[2].position = QString("中场/右脚");

        oppteam[9].players[3].name = QString("布兰登.威廉姆斯");
        oppteam[9].players[3].age = 20;
        oppteam[9].players[3].position = QString("后卫/右脚");

        oppteam[9].players[4].name = QString("马蒂奇");
        oppteam[9].players[4].age = 32;
        oppteam[9].players[4].position = QString("中场/左脚");

        oppteam[9].players[5].name = QString("弗雷德");
        oppteam[9].players[5].age = 27;
        oppteam[9].players[5].position = QString("中场/左脚");

        oppteam[9].players[6].name = QString("万.比萨卡");
        oppteam[9].players[6].age = 22;
        oppteam[9].players[6].position = QString("后卫/右脚");

        oppteam[9].players[7].name = QString("林德洛夫");
        oppteam[9].players[7].age = 26;
        oppteam[9].players[7].position = QString("后卫/右脚");

        oppteam[9].players[8].name = QString("H.马奎尔");
        oppteam[9].players[8].age = 27;
        oppteam[9].players[8].position = QString("后卫/右脚");

        oppteam[9].players[9].name = QString("E.拜利");
        oppteam[9].players[9].age = 26;
        oppteam[9].players[9].position = QString("后卫/右脚");

        oppteam[9].players[10].name = QString("大卫德赫亚");
        oppteam[9].players[10].age = 29;
        oppteam[9].players[10].position = QString("门将/右脚");

        oppteam[10].name = QString("托特纳姆热刺") ;
        oppteam[10].players[0].name = QString("哈里.凯恩");
        oppteam[10].players[0].age = 27;
        oppteam[10].players[0].position = QString("前锋/右脚");

        oppteam[10].players[1].name = QString("孙兴慜");
        oppteam[10].players[1].age = 28;
        oppteam[10].players[1].position = QString("前锋/左右脚");

        oppteam[10].players[2].name = QString("卢卡斯.莫拉");
        oppteam[10].players[2].age = 28;
        oppteam[10].players[2].position = QString("前锋/右脚");

        oppteam[10].players[3].name = QString("温克斯");
        oppteam[10].players[3].age = 24;
        oppteam[10].players[3].position = QString("中场/右脚");

        oppteam[10].players[4].name = QString("洛塞尔索");
        oppteam[10].players[4].age = 24;
        oppteam[10].players[4].position = QString("中场/左脚");

        oppteam[10].players[5].name = QString("穆萨.西索科");
        oppteam[10].players[5].age = 31;
        oppteam[10].players[5].position = QString("中场/右脚");

        oppteam[10].players[6].name = QString("本.戴维斯");
        oppteam[10].players[6].age = 27;
        oppteam[10].players[6].position = QString("后卫/左脚");

        oppteam[10].players[7].name = QString("阿尔德韦雷尔德");
        oppteam[10].players[7].age = 31;
        oppteam[10].players[7].position = QString("后卫 / 右脚");

        oppteam[10].players[8].name = QString("达文森.桑切斯");
        oppteam[10].players[8].age = 24;
        oppteam[10].players[8].position = QString("后卫 / 右脚");

        oppteam[10].players[9].name = QString("奥里耶");
        oppteam[10].players[9].age = 27;
        oppteam[10].players[9].position = QString("后卫 / 右脚");

        oppteam[10].players[10].name = QString("洛里");
        oppteam[10].players[10].age = 33;
        oppteam[10].players[10].position = QString("门将/左脚");

        oppteam[11].name = QString("谢菲尔德联" );
        oppteam[11].players[0].name = QString("麦戈德里克");
        oppteam[11].players[0].age = 32;
        oppteam[11].players[0].position = QString("前锋/右脚");

        oppteam[11].players[1].name = QString("麦克布涅");
        oppteam[11].players[1].age = 24;
        oppteam[11].players[1].position = QString("前锋/右脚");

        oppteam[11].players[2].name = QString("史蒂文斯");
        oppteam[11].players[2].age = 32;
        oppteam[11].players[2].position = QString("后卫/左脚");

        oppteam[11].players[3].name = QString("奥斯本");
        oppteam[11].players[3].age = 26;
        oppteam[11].players[3].position = QString("中场/左脚");

        oppteam[11].players[4].name = QString("诺伍德");
        oppteam[11].players[4].age = 29;
        oppteam[11].players[4].position = QString("中场/右脚");

        oppteam[11].players[5].name = QString("博格");
        oppteam[11].players[5].age = 22;
        oppteam[11].players[5].position = QString("中场/右脚");

        oppteam[11].players[6].name = QString("鲍多克");
        oppteam[11].players[6].age = 27;
        oppteam[11].players[6].position = QString("后卫/右脚");

        oppteam[11].players[7].name = QString("杰克.奥康奈尔");
        oppteam[11].players[7].age = 26;
        oppteam[11].players[7].position = QString("后卫/左脚");

        oppteam[11].players[8].name = QString("伊根");
        oppteam[11].players[8].age = 27;
        oppteam[11].players[8].position = QString("后卫/右脚");

        oppteam[11].players[9].name = QString("巴沙姆");
        oppteam[11].players[9].age = 32;
        oppteam[11].players[9].position = QString("后卫/右脚");

        oppteam[11].players[10].name = QString("西蒙穆尔");
        oppteam[11].players[10].age = 30;
        oppteam[11].players[10].position = QString("门将/右脚");

        oppteam[12].name = QString("莱斯特城");
        oppteam[12].players[0].name = QString("J.瓦尔迪");
        oppteam[12].players[0].age = 33;
        oppteam[12].players[0].position = QString("前锋/右脚");

        oppteam[12].players[1].name = QString("伊希纳乔");
        oppteam[12].players[1].age = 23;
        oppteam[12].players[1].position = QString("前锋/左脚");

        oppteam[12].players[2].name = QString("阿约塞.佩雷斯");
        oppteam[12].players[2].age = 27;
        oppteam[12].players[2].position = QString("前锋/右脚");

        oppteam[12].players[3].name = QString("蒂勒曼斯");
        oppteam[12].players[3].age = 23;
        oppteam[12].players[3].position = QString("中场/左右脚");

        oppteam[12].players[4].name = QString("恩迪迪");
        oppteam[12].players[4].age = 23;
        oppteam[12].players[4].position = QString("中场/右脚");

        oppteam[12].players[5].name = QString("乔杜里");
        oppteam[12].players[5].age = 22;
        oppteam[12].players[5].position = QString("中场/左脚");

        oppteam[12].players[6].name = QString("阿尔布赖顿");
        oppteam[12].players[6].age = 30;
        oppteam[12].players[6].position = QString("中场/右脚");

        oppteam[12].players[7].name = QString("埃文斯");
        oppteam[12].players[7].age = 32;
        oppteam[12].players[7].position = QString("后卫/左右脚");

        oppteam[12].players[8].name = QString("摩根");
        oppteam[12].players[8].age = 36;
        oppteam[12].players[8].position = QString("后卫/右脚");

        oppteam[12].players[9].name = QString("贾斯廷");
        oppteam[12].players[9].age = 21;
        oppteam[12].players[9].position = QString("后卫/右脚");

        oppteam[12].players[10].name = QString("卡斯帕.舒梅切尔");
        oppteam[12].players[10].age = 33;
        oppteam[12].players[10].position = QString("门将/右脚");

        oppteam[13].name = QString("水晶宫" );
        oppteam[13].players[0].name = QString("乔丹.阿尤");
        oppteam[13].players[0].age = 29;
        oppteam[13].players[0].position = QString("前锋/右脚");

        oppteam[13].players[1].name = QString("本特克");
        oppteam[13].players[1].age = 29;
        oppteam[13].players[1].position = QString("前锋/右脚");

        oppteam[13].players[2].name = QString("扎哈");
        oppteam[13].players[2].age = 27;
        oppteam[13].players[2].position = QString("前锋/右脚");

        oppteam[13].players[3].name = QString("麦克阿瑟");
        oppteam[13].players[3].age = 32;
        oppteam[13].players[3].position = QString("中场/右脚");

        oppteam[13].players[4].name = QString("米利沃杰维奇");
        oppteam[13].players[4].age = 29;
        oppteam[13].players[4].position = QString("中场/右脚");

        oppteam[13].players[5].name = QString("麦克斯.迈尔");
        oppteam[13].players[5].age = 24;
        oppteam[13].players[5].position = QString("中场/左右脚");

        oppteam[13].players[6].name = QString("沃德");
        oppteam[13].players[6].age = 30;
        oppteam[13].players[6].position = QString("后卫/右脚");

        oppteam[13].players[7].name = QString("丹恩");
        oppteam[13].players[7].age = 33;
        oppteam[13].players[7].position = QString("后卫/右脚");

        oppteam[13].players[8].name = QString("加里.卡希尔");
        oppteam[13].players[8].age = 34;
        oppteam[13].players[8].position = QString("后卫/右脚");

        oppteam[13].players[9].name = QString("范安霍尔特");
        oppteam[13].players[9].age = 30;
        oppteam[13].players[9].position = QString("后卫/左脚");

        oppteam[13].players[10].name = QString("瓜伊塔");
        oppteam[13].players[10].age = 33;
        oppteam[13].players[10].position = QString("门将/右脚");

        oppteam[14].name = QString("马德里竞技");
        oppteam[14].players[0].name = QString("莫拉塔");
        oppteam[14].players[0].age = 27;
        oppteam[14].players[0].position = QString("前锋/右脚");

        oppteam[14].players[1].name = QString("马科斯.略伦特");
        oppteam[14].players[1].age = 25;
        oppteam[14].players[1].position = QString("中场/右脚");

        oppteam[14].players[2].name = QString("科克");
        oppteam[14].players[2].age = 28;
        oppteam[14].players[2].position = QString("中场/右脚");

        oppteam[14].players[3].name = QString("萨乌尔");
        oppteam[14].players[3].age = 25;
        oppteam[14].players[3].position = QString("中场/左脚");

        oppteam[14].players[4].name = QString("托马斯.帕尔特伊");
        oppteam[14].players[4].age = 27;
        oppteam[14].players[4].position = QString("中场/右脚");

        oppteam[14].players[5].name = QString("科雷亚");
        oppteam[14].players[5].age = 25;
        oppteam[14].players[5].position = QString("前锋/右脚");

        oppteam[14].players[6].name = QString("雷南.洛迪");
        oppteam[14].players[6].age = 22;
        oppteam[14].players[6].position = QString("后卫/左脚");

        oppteam[14].players[7].name = QString("马里奥.埃尔莫索");
        oppteam[14].players[7].age = 25;
        oppteam[14].players[7].position = QString("后卫/左脚");

        oppteam[14].players[8].name = QString("特里皮尔");
        oppteam[14].players[8].age = 29;
        oppteam[14].players[8].position = QString("后卫/右脚");

        oppteam[14].players[9].name = QString("萨维奇");
        oppteam[14].players[9].age = 29;
        oppteam[14].players[9].position = QString("后卫/右脚");

        oppteam[14].players[9].name = QString("奥布拉克");
        oppteam[14].players[9].age = 27;
        oppteam[14].players[9].position = QString("门将/右脚");

        oppteam[15].name = QString("国际米兰" );
        oppteam[15].players[0].name = QString("劳塔罗.马丁内斯");
        oppteam[15].players[0].age = 23;
        oppteam[15].players[0].position = QString("前锋/右脚");

        oppteam[15].players[1].name = QString("阿什利.扬");
        oppteam[15].players[1].age = 35;
        oppteam[15].players[1].position = QString("后卫/右脚");

        oppteam[15].players[2].name = QString("加利亚尔迪尼");
        oppteam[15].players[2].age = 26;
        oppteam[15].players[2].position = QString("中场/右脚");

        oppteam[15].players[3].name = QString("布罗佐维奇");
        oppteam[15].players[3].age = 27;
        oppteam[15].players[3].position = QString("中场/左右脚");

        oppteam[15].players[4].name = QString("巴雷拉");
        oppteam[15].players[4].age = 23;
        oppteam[15].players[4].position = QString("中场/右脚");

        oppteam[15].players[5].name = QString("丹布罗西奥");
        oppteam[15].players[5].age = 32;
        oppteam[15].players[5].position = QString("后卫/右脚");

        oppteam[15].players[6].name = QString("巴斯托尼");
        oppteam[15].players[6].age = 21;
        oppteam[15].players[6].position = QString("后卫/左脚");

        oppteam[15].players[7].name = QString("德弗赖");
        oppteam[15].players[7].age = 28;
        oppteam[15].players[7].position = QString("后卫/右脚");

        oppteam[15].players[8].name = QString("戈丁");
        oppteam[15].players[8].age = 34;
        oppteam[15].players[8].position = QString("后卫/右脚");

        oppteam[15].players[9].name = QString("汉达诺维奇");
        oppteam[15].players[9].age = 36;
        oppteam[15].players[9].position = QString("门将/右脚");

        oppteam[15].players[10].name = QString("R.卢卡库");
        oppteam[15].players[10].age = 27;
        oppteam[15].players[10].position = QString("前锋/左脚");

        oppteam[16].name = QString("AC米兰") ;
        oppteam[16].players[0].name = QString("伊布");
        oppteam[16].players[0].age = 38;
        oppteam[16].players[0].position = QString("前锋/右脚");

        oppteam[16].players[1].name = QString("雷比奇");
        oppteam[16].players[1].age = 26;
        oppteam[16].players[1].position = QString("前锋/右脚");

        oppteam[16].players[2].name = QString("帕奎塔");
        oppteam[16].players[2].age = 23;
        oppteam[16].players[2].position = QString("中场/左脚");

        oppteam[16].players[3].name = QString("恰尔汉奥卢");
        oppteam[16].players[3].age = 26;
        oppteam[16].players[3].position = QString("中场/右脚");

        oppteam[16].players[4].name = QString("本纳赛尔");
        oppteam[16].players[4].age = 22;
        oppteam[16].players[4].position = QString("中场/左脚");

        oppteam[16].players[5].name = QString("凯西");
        oppteam[16].players[5].age = 23;
        oppteam[16].players[5].position = QString("中场/左右脚");

        oppteam[16].players[6].name = QString("特奥.埃尔南德斯");
        oppteam[16].players[6].age = 22;
        oppteam[16].players[6].position = QString("后卫/左脚");

        oppteam[16].players[7].name = QString("罗马尼奥利");
        oppteam[16].players[7].age = 25;
        oppteam[16].players[7].position = QString("后卫/左脚");

        oppteam[16].players[8].name = QString("克亚尔");
        oppteam[16].players[8].age = 31;
        oppteam[16].players[8].position = QString("后卫/右脚");

        oppteam[16].players[9].name = QString("安德烈亚.孔蒂");
        oppteam[16].players[9].age = 26;
        oppteam[16].players[9].position = QString("后卫/右脚");

        oppteam[16].players[10].name = QString("多纳鲁马");
        oppteam[16].players[10].age = 21;
        oppteam[16].players[10].position = QString("门将/右脚");

        oppteam[17].name = QString("多特蒙德");
        oppteam[17].players[0].name = QString("布兰特");
        oppteam[17].players[0].age = 24;
        oppteam[17].players[0].position = QString("前锋/右脚");

        oppteam[17].players[1].name = QString("马尔科罗伊斯");
        oppteam[17].players[1].age = 31;
        oppteam[17].players[1].position = QString("前锋/右脚");

        oppteam[17].players[2].name = QString("G.雷纳");
        oppteam[17].players[2].age = 17;
        oppteam[17].players[2].position = QString("中场/右脚");

        oppteam[17].players[3].name = QString("尼克舒尔茨");
        oppteam[17].players[3].age = 27;
        oppteam[17].players[3].position = QString("中场/左脚");

        oppteam[17].players[4].name = QString("维特塞尔");
        oppteam[17].players[4].age = 31;
        oppteam[17].players[4].position = QString("中场/右脚");

        oppteam[17].players[5].name = QString("乔丹桑乔");
        oppteam[17].players[5].age = 20;
        oppteam[17].players[5].position = QString("中场/右脚");

        oppteam[17].players[6].name = QString("马特乌.默雷伊");
        oppteam[17].players[6].age = 20;
        oppteam[17].players[6].position = QString("后卫/右脚");

        oppteam[17].players[7].name = QString("帕斯拉克");
        oppteam[17].players[7].age = 22;
        oppteam[17].players[7].position = QString("后卫/右脚");

        oppteam[17].players[8].name = QString("阿坎吉");
        oppteam[17].players[8].age = 25;
        oppteam[17].players[8].position = QString("后卫/右脚");

        oppteam[17].players[9].name = QString("默尼耶");
        oppteam[17].players[9].age = 29;
        oppteam[17].players[9].position = QString("后卫/右脚");

        oppteam[17].players[10].name = QString("布尔基");
        oppteam[17].players[10].age = 29;
        oppteam[17].players[10].position = QString("门将/右脚");

        oppteam[18].name = QString("法兰克福") ;
        oppteam[18].players[0].name = QString("亚伯拉罕");
        oppteam[18].players[0].age = 34;
        oppteam[18].players[0].position = QString("后卫/右脚");

        oppteam[18].players[1].name = QString("欣特雷格");
        oppteam[18].players[1].age = 28;
        oppteam[18].players[1].position = QString("后卫/左脚");

        oppteam[18].players[2].name = QString("恩迪卡");
        oppteam[18].players[2].age = 21;
        oppteam[18].players[2].position = QString("后卫/左脚");

        oppteam[18].players[3].name = QString("丹尼.达科斯塔");
        oppteam[18].players[3].age = 27;
        oppteam[18].players[3].position = QString("后卫/右脚");

        oppteam[18].players[4].name = QString("罗德");
        oppteam[18].players[4].age = 29;
        oppteam[18].players[4].position = QString("中场/右脚");

        oppteam[18].players[5].name = QString("伊尔桑克");
        oppteam[18].players[5].age = 31;
        oppteam[18].players[5].position = QString("中场/右脚");

        oppteam[18].players[6].name = QString("科斯蒂奇");
        oppteam[18].players[6].age = 27;
        oppteam[18].players[6].position = QString("中场/左脚");

        oppteam[18].players[7].name = QString("镰田大地");
        oppteam[18].players[7].age = 24;
        oppteam[18].players[7].position = QString("中场/右脚");

        oppteam[18].players[8].name = QString("阿赫");
        oppteam[18].players[8].age = 22;
        oppteam[18].players[8].position = QString("前锋/右脚");

        oppteam[18].players[9].name = QString("A.席尔瓦");
        oppteam[18].players[9].age = 24;
        oppteam[18].players[9].position = QString("前锋/右脚");

        oppteam[18].players[10].name = QString("凯文特拉普");
        oppteam[18].players[10].age = 30;
        oppteam[18].players[10].position = QString("门将/右脚");
    }

    this->setFixedSize(960,540);
    this->setWindowTitle("Football Manager 2021");

    //设置启动时默认页面
    ui->stackedWidget->setCurrentIndex(20);

    //“开始游戏”按钮
    connect(ui->startBtn,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //“退出游戏”按钮
    connect(ui->exitBtn,&QPushButton::clicked,this,&MainWindow::close);

    //“创建球队”按钮
    connect(ui->createTeamBtn,&QPushButton::clicked,[=](){
        createTeam();
        ui->stackedWidget->setCurrentIndex(2);
    });

    //“选择球员”按钮
    connect(ui->choosePlayerBtn,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
        salarysum = 0;
    });

//门将信息以及选择

    //用左侧TreeWidget显示门将信息
    {
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
    }
    //“选择门将”按钮
    connect(ui->ChooseGoalKeeperBtn,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        check_1 = true;
        check_2 = true;
        if(ui->checkBox_19->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("诺伊尔"))
                    {
                        goalKeeper1.name = players[i].name;
                        goalKeeper1.age = players[i].age;
                        goalKeeper1.rating = players[i].rating;
                        goalKeeper1.position = players[i].position;
                        goalKeeper1.weeksalary = players[i].weeksalary;
                        goalKeeper1.is_p = players[i].is_p;
                        goalKeeper1.transferfee = players[i].transferfee;
                        goalKeeper1.hurt = players[i].hurt;
                    }
                }
            }
            else if (goalKeeper2.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("诺伊尔"))
                    {
                        goalKeeper2.name = players[i].name;
                        goalKeeper2.age = players[i].age;
                        goalKeeper2.rating = players[i].rating;
                        goalKeeper2.position = players[i].position;
                        goalKeeper2.weeksalary = players[i].weeksalary;
                        goalKeeper2.is_p = players[i].is_p;
                        goalKeeper2.transferfee = players[i].transferfee;
                        goalKeeper2.hurt = players[i].hurt;
                    }
                }
            }
        }
        if (ui->checkBox_20->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("凯帕"))
                    {
                        goalKeeper1.name = players[i].name;
                        goalKeeper1.age = players[i].age;
                        goalKeeper1.rating = players[i].rating;
                        goalKeeper1.position = players[i].position;
                        goalKeeper1.weeksalary = players[i].weeksalary;
                        goalKeeper1.is_p = players[i].is_p;
                        goalKeeper1.transferfee = players[i].transferfee;
                        goalKeeper1.hurt = players[i].hurt;
                    }
                }
            }
            else if (goalKeeper2.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("凯帕"))
                    {
                        goalKeeper2.name = players[i].name;
                        goalKeeper2.age = players[i].age;
                        goalKeeper2.rating = players[i].rating;
                        goalKeeper2.position = players[i].position;
                        goalKeeper2.weeksalary = players[i].weeksalary;
                        goalKeeper2.is_p = players[i].is_p;
                        goalKeeper2.transferfee = players[i].transferfee;
                        goalKeeper2.hurt = players[i].hurt;
                    }
                }
            }
        }
        if (ui->checkBox_21->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("特尔施特根"))
                    {
                        goalKeeper1.name = players[i].name;
                        goalKeeper1.age = players[i].age;
                        goalKeeper1.rating = players[i].rating;
                        goalKeeper1.position = players[i].position;
                        goalKeeper1.weeksalary = players[i].weeksalary;
                        goalKeeper1.is_p = players[i].is_p;
                        goalKeeper1.transferfee = players[i].transferfee;
                        goalKeeper1.hurt = players[i].hurt;
                    }
                }
            }
            else if (goalKeeper2.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("特尔施特根"))
                    {
                        goalKeeper2.name = players[i].name;
                        goalKeeper2.age = players[i].age;
                        goalKeeper2.rating = players[i].rating;
                        goalKeeper2.position = players[i].position;
                        goalKeeper2.weeksalary = players[i].weeksalary;
                        goalKeeper2.is_p = players[i].is_p;
                        goalKeeper2.transferfee = players[i].transferfee;
                        goalKeeper2.hurt = players[i].hurt;
                    }
                }
            }
        }
        if(ui->checkBox_22->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("布尔基"))
                    {
                        goalKeeper1.name = players[i].name;
                        goalKeeper1.age = players[i].age;
                        goalKeeper1.rating = players[i].rating;
                        goalKeeper1.position = players[i].position;
                        goalKeeper1.weeksalary = players[i].weeksalary;
                        goalKeeper1.is_p = players[i].is_p;
                        goalKeeper1.transferfee = players[i].transferfee;
                        goalKeeper1.hurt = players[i].hurt;
                    }
                }
            }
            else if (goalKeeper2.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("布尔基"))
                    {
                        goalKeeper2.name = players[i].name;
                        goalKeeper2.age = players[i].age;
                        goalKeeper2.rating = players[i].rating;
                        goalKeeper2.position = players[i].position;
                        goalKeeper2.weeksalary = players[i].weeksalary;
                        goalKeeper2.is_p = players[i].is_p;
                        goalKeeper2.transferfee = players[i].transferfee;
                        goalKeeper2.hurt = players[i].hurt;
                    }
                }
            }
        }
        if(ui->checkBox_23->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("布冯"))
                    {
                        goalKeeper1.name = players[i].name;
                        goalKeeper1.age = players[i].age;
                        goalKeeper1.rating = players[i].rating;
                        goalKeeper1.position = players[i].position;
                        goalKeeper1.weeksalary = players[i].weeksalary;
                        goalKeeper1.is_p = players[i].is_p;
                        goalKeeper1.transferfee = players[i].transferfee;
                        goalKeeper1.hurt = players[i].hurt;
                    }
                }
            }
            else if (goalKeeper2.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("布冯"))
                    {
                        goalKeeper2.name = players[i].name;
                        goalKeeper2.age = players[i].age;
                        goalKeeper2.rating = players[i].rating;
                        goalKeeper2.position = players[i].position;
                        goalKeeper2.weeksalary = players[i].weeksalary;
                        goalKeeper2.is_p = players[i].is_p;
                        goalKeeper2.transferfee = players[i].transferfee;
                        goalKeeper2.hurt = players[i].hurt;
                    }
                }
            }
        }
        if(ui->checkBox_24->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("多纳鲁马"))
                    {
                        goalKeeper1.name = players[i].name;
                        goalKeeper1.age = players[i].age;
                        goalKeeper1.rating = players[i].rating;
                        goalKeeper1.position = players[i].position;
                        goalKeeper1.weeksalary = players[i].weeksalary;
                        goalKeeper1.is_p = players[i].is_p;
                        goalKeeper1.transferfee = players[i].transferfee;
                        goalKeeper1.hurt = players[i].hurt;
                    }
                }
            }
            else if (goalKeeper2.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("多纳鲁马"))
                    {
                        goalKeeper2.name = players[i].name;
                        goalKeeper2.age = players[i].age;
                        goalKeeper2.rating = players[i].rating;
                        goalKeeper2.position = players[i].position;
                        goalKeeper2.weeksalary = players[i].weeksalary;
                        goalKeeper2.is_p = players[i].is_p;
                        goalKeeper2.transferfee = players[i].transferfee;
                        goalKeeper2.hurt = players[i].hurt;
                    }
                }
            }
        }
        if(ui->checkBox_25->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("莱诺"))
                    {
                        goalKeeper1.name = players[i].name;
                        goalKeeper1.age = players[i].age;
                        goalKeeper1.rating = players[i].rating;
                        goalKeeper1.position = players[i].position;
                        goalKeeper1.weeksalary = players[i].weeksalary;
                        goalKeeper1.is_p = players[i].is_p;
                        goalKeeper1.transferfee = players[i].transferfee;
                        goalKeeper1.hurt = players[i].hurt;
                    }
                }
            }
            else if (goalKeeper2.name == QString(""))
            {
                for (int i=0;i<100;i++)
                {
                    if (players[i].name == QString("莱诺"))
                    {
                        goalKeeper2.name = players[i].name;
                        goalKeeper2.age = players[i].age;
                        goalKeeper2.rating = players[i].rating;
                        goalKeeper2.position = players[i].position;
                        goalKeeper2.weeksalary = players[i].weeksalary;
                        goalKeeper2.is_p = players[i].is_p;
                        goalKeeper2.transferfee = players[i].transferfee;
                        goalKeeper2.hurt = players[i].hurt;
                    }
                }
            }
        }
        if(ui->checkBox_26->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1 == QString(""))
                goalKeeper1 = QString("阿利松");
            else if (goalKeeper2 == QString(""))
                goalKeeper2 = QString("阿利松");
        }
        if(ui->checkBox_27->isChecked())
        {
            ckBoxSum++;
            if (goalKeeper1 == QString(""))
                goalKeeper1 = QString("德赫亚");
            else if (goalKeeper2 == QString(""))
                goalKeeper2 = QString("德赫亚");
        }
        qDebug()<<"goalKeeper1:"<<goalKeeper1;
        qDebug()<<"goalKeeper2:"<<goalKeeper2;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        salarysum1 = 0;
        for (int i=0;i<100;i++)
        {
            if (goalKeeper1 == players[i].name)
                salarysum1 += players[i].weeksalary;
            else if (goalKeeper2 == players[i].name)
                salarysum1 += players[i].weeksalary;
            else
                continue;
        }
        qDebug()<<"salarysum1:"<<salarysum1;

        //如果选择的门将数目超过2个，弹窗警告
        if (ckBoxSum > 2)
        {
            check_1 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择两名门将\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_19->setCheckState(Qt::Unchecked);
                ui->checkBox_19->setChecked(false);
                ui->checkBox_20->setCheckState(Qt::Unchecked);
                ui->checkBox_20->setChecked(false);
                ui->checkBox_21->setCheckState(Qt::Unchecked);
                ui->checkBox_21->setChecked(false);
                ui->checkBox_22->setCheckState(Qt::Unchecked);
                ui->checkBox_22->setChecked(false);
                ui->checkBox_23->setCheckState(Qt::Unchecked);
                ui->checkBox_23->setChecked(false);
                ui->checkBox_24->setCheckState(Qt::Unchecked);
                ui->checkBox_24->setChecked(false);
                ui->checkBox_25->setCheckState(Qt::Unchecked);
                ui->checkBox_25->setChecked(false);
                ui->checkBox_26->setCheckState(Qt::Unchecked);
                ui->checkBox_26->setChecked(false);
                ui->checkBox_27->setCheckState(Qt::Unchecked);
                ui->checkBox_27->setChecked(false);
                salarysum1 = 0;
                goalKeeper1.name = QString("");
                goalKeeper2.name = QString("");
                qDebug()<<"salarysum1:"<<salarysum1;
            }
        }

        //如果选择的门将数目不足2个，弹窗警告
        if (ckBoxSum < 2)
        {
            check_2 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的门将数目不足两个\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_19->setCheckState(Qt::Unchecked);
                ui->checkBox_19->setChecked(false);
                ui->checkBox_20->setCheckState(Qt::Unchecked);
                ui->checkBox_20->setChecked(false);
                ui->checkBox_21->setCheckState(Qt::Unchecked);
                ui->checkBox_21->setChecked(false);
                ui->checkBox_22->setCheckState(Qt::Unchecked);
                ui->checkBox_22->setChecked(false);
                ui->checkBox_23->setCheckState(Qt::Unchecked);
                ui->checkBox_23->setChecked(false);
                ui->checkBox_24->setCheckState(Qt::Unchecked);
                ui->checkBox_24->setChecked(false);
                ui->checkBox_25->setCheckState(Qt::Unchecked);
                ui->checkBox_25->setChecked(false);
                ui->checkBox_26->setCheckState(Qt::Unchecked);
                ui->checkBox_26->setChecked(false);
                ui->checkBox_27->setCheckState(Qt::Unchecked);
                ui->checkBox_27->setChecked(false);
                salarysum1 = 0;
                goalKeeper1.name = QString("");
                goalKeeper2.name = QString("");
                qDebug()<<salarysum1;
            }
        }

        //如果所选门将的周薪总和大于等于55，弹窗询问
        if (salarysum1 >= 55)
        {
            int a = QMessageBox::question(this,QString("注意"),QString("过高的门将薪资将会限制同队中其他球员的选择\n是否重新选择"),QMessageBox::Cancel|QMessageBox::Ok);
            //ok后重置并且重新选择
            if(a == QMessageBox::Ok)
            {
                ui->checkBox_19->setCheckState(Qt::Unchecked);
                ui->checkBox_19->setChecked(false);
                ui->checkBox_20->setCheckState(Qt::Unchecked);
                ui->checkBox_20->setChecked(false);
                ui->checkBox_21->setCheckState(Qt::Unchecked);
                ui->checkBox_21->setChecked(false);
                ui->checkBox_22->setCheckState(Qt::Unchecked);
                ui->checkBox_22->setChecked(false);
                ui->checkBox_23->setCheckState(Qt::Unchecked);
                ui->checkBox_23->setChecked(false);
                ui->checkBox_24->setCheckState(Qt::Unchecked);
                ui->checkBox_24->setChecked(false);
                ui->checkBox_25->setCheckState(Qt::Unchecked);
                ui->checkBox_25->setChecked(false);
                ui->checkBox_26->setCheckState(Qt::Unchecked);
                ui->checkBox_26->setChecked(false);
                ui->checkBox_27->setCheckState(Qt::Unchecked);
                ui->checkBox_27->setChecked(false);
                salarysum1 = 0;
                goalKeeper1.name = QString("");
                goalKeeper2.name = QString("");
                qDebug()<<salarysum1;
            }
            //cancel后进入下一页面
            else if (check_1&&check_2)
            {
                ui->stackedWidget->setCurrentIndex(4);
                salarysum+=salarysum1;
            }
        }
        else if (check_1&&check_2)
        {
            ui->stackedWidget->setCurrentIndex(4);
            salarysum+=salarysum1;
        }
    });

//前锋信息以及选择

    //用左侧TreeWidget显示前锋信息 
    {
        ui->treeWidget_2->setHeaderLabels(QStringList()<<"前锋信息");
        QTreeWidgetItem *LaiWanDuoFuSiJi = new QTreeWidgetItem(QStringList()<<"莱万多夫斯基");
        QTreeWidgetItem *MuLe = new QTreeWidgetItem(QStringList()<<"穆勒");
        QTreeWidgetItem *JiLu = new QTreeWidgetItem(QStringList()<<"吉鲁");
        QTreeWidgetItem *YaBoLaHan = new QTreeWidgetItem(QStringList()<<"亚伯拉罕");
        QTreeWidgetItem *WeiErNa = new QTreeWidgetItem(QStringList()<<"维尔纳");
        QTreeWidgetItem *AoBaMeiYang = new QTreeWidgetItem(QStringList()<<"奥巴梅扬");
        QTreeWidgetItem *WeiLian = new QTreeWidgetItem(QStringList()<<"威廉");
        QTreeWidgetItem *MuBaPei = new QTreeWidgetItem(QStringList()<<"姆巴佩");
        QTreeWidgetItem *NeiMaEr = new QTreeWidgetItem(QStringList()<<"内马尔");
        QTreeWidgetItem *DiBaLa = new QTreeWidgetItem(QStringList()<<"迪巴拉");
        QTreeWidgetItem *LuoNaErDuo = new QTreeWidgetItem(QStringList()<<"罗纳尔多");
        QTreeWidgetItem *AZhaEr = new QTreeWidgetItem(QStringList()<<"阿扎尔");
        QTreeWidgetItem *BeiEr = new QTreeWidgetItem(QStringList()<<"贝尔");
        QTreeWidgetItem *ASenXiAo = new QTreeWidgetItem(QStringList()<<"阿森西奥");
        QTreeWidgetItem *LuoDeLiGe = new QTreeWidgetItem(QStringList()<<"罗德里戈");
        QTreeWidgetItem *FeiErMiNuo = new QTreeWidgetItem(QStringList()<<"菲尔米诺");
        QTreeWidgetItem *SaLaHe = new QTreeWidgetItem(QStringList()<<"萨拉赫");
        QTreeWidgetItem *MaNei = new QTreeWidgetItem(QStringList()<<"马内");
        QTreeWidgetItem *SiTeLin = new QTreeWidgetItem(QStringList()<<"斯特林");
        QTreeWidgetItem *ReSuSi = new QTreeWidgetItem(QStringList()<<"热苏斯");
        QTreeWidgetItem *MaHeLeiSi = new QTreeWidgetItem(QStringList()<<"马赫雷斯");
        QTreeWidgetItem *AGuiLuo = new QTreeWidgetItem(QStringList()<<"阿圭罗");
        QTreeWidgetItem *GeLieZiMan = new QTreeWidgetItem(QStringList()<<"格列兹曼");
        QTreeWidgetItem *MeiXi = new QTreeWidgetItem(QStringList()<<"梅西");
        QTreeWidgetItem *SuYaLeiSi = new QTreeWidgetItem(QStringList()<<"苏亚雷斯");
        QTreeWidgetItem *GeNaBuLi = new QTreeWidgetItem(QStringList()<<"格纳布里");
        QTreeWidgetItem *SaNei = new QTreeWidgetItem(QStringList()<<"萨内");
        QTreeWidgetItem *HaLanDe = new QTreeWidgetItem(QStringList()<<"哈兰德");
        QTreeWidgetItem *BuLanTe = new QTreeWidgetItem(QStringList()<<"布兰特");
        QTreeWidgetItem *LuoYiSi = new QTreeWidgetItem(QStringList()<<"罗伊斯");
        QTreeWidgetItem *FuLanDe = new QTreeWidgetItem(QStringList()<<"弗兰德");
        QTreeWidgetItem *YiKaErDi = new QTreeWidgetItem(QStringList()<<"伊卡尔迪");
        QTreeWidgetItem *LuKaKu = new QTreeWidgetItem(QStringList()<<"卢卡库");
        QTreeWidgetItem *SangQieSi = new QTreeWidgetItem(QStringList()<<"桑切斯");

        ui->treeWidget_2->addTopLevelItem(LaiWanDuoFuSiJi);
        ui->treeWidget_2->addTopLevelItem(MuLe);
        ui->treeWidget_2->addTopLevelItem(JiLu);
        ui->treeWidget_2->addTopLevelItem(YaBoLaHan);
        ui->treeWidget_2->addTopLevelItem(WeiErNa);
        ui->treeWidget_2->addTopLevelItem(AoBaMeiYang);
        ui->treeWidget_2->addTopLevelItem(WeiLian);
        ui->treeWidget_2->addTopLevelItem(MuBaPei);
        ui->treeWidget_2->addTopLevelItem(NeiMaEr);
        ui->treeWidget_2->addTopLevelItem(DiBaLa);
        ui->treeWidget_2->addTopLevelItem(LuoNaErDuo);
        ui->treeWidget_2->addTopLevelItem(AZhaEr);
        ui->treeWidget_2->addTopLevelItem(BeiEr);
        ui->treeWidget_2->addTopLevelItem(ASenXiAo);
        ui->treeWidget_2->addTopLevelItem(LuoDeLiGe);
        ui->treeWidget_2->addTopLevelItem(FeiErMiNuo);
        ui->treeWidget_2->addTopLevelItem(SaLaHe);
        ui->treeWidget_2->addTopLevelItem(MaNei);
        ui->treeWidget_2->addTopLevelItem(SiTeLin);
        ui->treeWidget_2->addTopLevelItem(ReSuSi);
        ui->treeWidget_2->addTopLevelItem(MaHeLeiSi);
        ui->treeWidget_2->addTopLevelItem(AGuiLuo);
        ui->treeWidget_2->addTopLevelItem(GeLieZiMan);
        ui->treeWidget_2->addTopLevelItem(MeiXi);
        ui->treeWidget_2->addTopLevelItem(SuYaLeiSi);
        ui->treeWidget_2->addTopLevelItem(GeNaBuLi);
        ui->treeWidget_2->addTopLevelItem(SaNei);
        ui->treeWidget_2->addTopLevelItem(HaLanDe);
        ui->treeWidget_2->addTopLevelItem(BuLanTe);
        ui->treeWidget_2->addTopLevelItem(LuoYiSi);
        ui->treeWidget_2->addTopLevelItem(FuLanDe);
        ui->treeWidget_2->addTopLevelItem(YiKaErDi);
        ui->treeWidget_2->addTopLevelItem(LuKaKu);
        ui->treeWidget_2->addTopLevelItem(SangQieSi);


        QStringList age10;
        age10<<"年龄:32";
        QStringList rating10;
        rating10<<"能力值:91";
        QStringList position10;
        position10<<"位置:前锋/右脚";
        QStringList weeksalary10;
        weeksalary10<<"周薪:30";
        QStringList transferfee10;
        transferfee10<<"转会费:5600";
        QTreeWidgetItem *a10 = new QTreeWidgetItem(age10);
        LaiWanDuoFuSiJi->addChild(a10);
        QTreeWidgetItem *r10 = new QTreeWidgetItem(rating10);
        LaiWanDuoFuSiJi->addChild(r10);
        QTreeWidgetItem *p10 = new QTreeWidgetItem(position10);
        LaiWanDuoFuSiJi->addChild(p10);
        QTreeWidgetItem *w10 = new QTreeWidgetItem(weeksalary10);
        LaiWanDuoFuSiJi->addChild(w10);
        QTreeWidgetItem *t10 = new QTreeWidgetItem(transferfee10);
        LaiWanDuoFuSiJi->addChild(t10);

        QStringList age11;
        age11<<"年龄:30";
        QStringList rating11;
        rating11<<"能力值:85";
        QStringList position11;
        position11<<"位置:前锋/右脚";
        QStringList weeksalary11;
        weeksalary11<<"周薪:28";
        QStringList transferfee11;
        transferfee11<<"转会费:3000";
        QTreeWidgetItem *a11 = new QTreeWidgetItem(age11);
        MuLe->addChild(a11);
        QTreeWidgetItem *r11 = new QTreeWidgetItem(rating11);
        MuLe->addChild(r11);
        QTreeWidgetItem *p11 = new QTreeWidgetItem(position11);
        MuLe->addChild(p11);
        QTreeWidgetItem *w11 = new QTreeWidgetItem(weeksalary11);
        MuLe->addChild(w11);
        QTreeWidgetItem *t11 = new QTreeWidgetItem(transferfee11);
        MuLe->addChild(t11);

        QStringList age12;
        age12<<"年龄:33";
        QStringList rating12;
        rating12<<"能力值:80";
        QStringList position12;
        position12<<"位置:前锋/左脚";
        QStringList weeksalary12;
        weeksalary12<<"周薪:11";
        QStringList transferfee12;
        transferfee12<<"转会费:700";
        QTreeWidgetItem *a12 = new QTreeWidgetItem(age12);
        JiLu->addChild(a12);
        QTreeWidgetItem *r12 = new QTreeWidgetItem(rating12);
        JiLu->addChild(r12);
        QTreeWidgetItem *p12 = new QTreeWidgetItem(position12);
        JiLu->addChild(p12);
        QTreeWidgetItem *w12 = new QTreeWidgetItem(weeksalary12);
        JiLu->addChild(w12);
        QTreeWidgetItem *t12 = new QTreeWidgetItem(transferfee12);
        JiLu->addChild(t12);

        QStringList age13;
        age13<<"年龄:22";
        QStringList rating13;
        rating13<<"能力值:79";
        QStringList position13;
        position13<<"位置:前锋/右脚";
        QStringList weeksalary13;
        weeksalary13<<"周薪:5";
        QStringList transferfee13;
        transferfee13<<"转会费:4000";
        QTreeWidgetItem *a13 = new QTreeWidgetItem(age13);
        YaBoLaHan->addChild(a13);
        QTreeWidgetItem *r13 = new QTreeWidgetItem(rating13);
        YaBoLaHan->addChild(r13);
        QTreeWidgetItem *p13 = new QTreeWidgetItem(position13);
        YaBoLaHan->addChild(p13);
        QTreeWidgetItem *w13 = new QTreeWidgetItem(weeksalary13);
        YaBoLaHan->addChild(w13);
        QTreeWidgetItem *t13 = new QTreeWidgetItem(transferfee13);
        YaBoLaHan->addChild(t13);

        QStringList age14;
        age14<<"年龄:24";
        QStringList rating14;
        rating14<<"能力值:86";
        QStringList position14;
        position14<<"位置:前锋/右脚";
        QStringList weeksalary14;
        weeksalary14<<"周薪:6";
        QStringList transferfee14;
        transferfee14<<"转会费:6400";
        QTreeWidgetItem *a14 = new QTreeWidgetItem(age14);
        WeiErNa->addChild(a14);
        QTreeWidgetItem *r14 = new QTreeWidgetItem(rating14);
        WeiErNa->addChild(r14);
        QTreeWidgetItem *p14 = new QTreeWidgetItem(position14);
        WeiErNa->addChild(p14);
        QTreeWidgetItem *w14 = new QTreeWidgetItem(weeksalary14);
        WeiErNa->addChild(w14);
        QTreeWidgetItem *t14 = new QTreeWidgetItem(transferfee14);
        WeiErNa->addChild(t14);

        QStringList age15;
        age15<<"年龄:31";
        QStringList rating15;
        rating15<<"能力值:88";
        QStringList position15;
        position15<<"位置:前锋/右脚";
        QStringList weeksalary15;
        weeksalary15<<"周薪:20";
        QStringList transferfee15;
        transferfee15<<"转会费:5600";
        QTreeWidgetItem *a15 = new QTreeWidgetItem(age15);
        AoBaMeiYang->addChild(a15);
        QTreeWidgetItem *r15 = new QTreeWidgetItem(rating15);
        AoBaMeiYang->addChild(r15);
        QTreeWidgetItem *p15 = new QTreeWidgetItem(position15);
        AoBaMeiYang->addChild(p15);
        QTreeWidgetItem *w15 = new QTreeWidgetItem(weeksalary15);
        AoBaMeiYang->addChild(w15);
        QTreeWidgetItem *t15 = new QTreeWidgetItem(transferfee15);
        AoBaMeiYang->addChild(t15);

        QStringList age16;
        age16<<"年龄:32";
        QStringList rating16;
        rating16<<"能力值:82";
        QStringList position16;
        position16<<"位置:前锋/右脚";
        QStringList weeksalary16;
        weeksalary16<<"周薪:12";
        QStringList transferfee16;
        transferfee16<<"转会费:2250";
        QTreeWidgetItem *a16 = new QTreeWidgetItem(age16);
        WeiLian->addChild(a16);
        QTreeWidgetItem *r16 = new QTreeWidgetItem(rating16);
        WeiLian->addChild(r16);
        QTreeWidgetItem *p16 = new QTreeWidgetItem(position16);
        WeiLian->addChild(p16);
        QTreeWidgetItem *w16 = new QTreeWidgetItem(weeksalary16);
        WeiLian->addChild(w16);
        QTreeWidgetItem *t16 = new QTreeWidgetItem(transferfee16);
        WeiLian->addChild(t16);

        QStringList age17;
        age17<<"年龄:21";
        QStringList rating17;
        rating17<<"能力值:89";
        QStringList position17;
        position17<<"位置:前锋/右脚";
        QStringList weeksalary17;
        weeksalary17<<"周薪:36";
        QStringList transferfee17;
        transferfee17<<"转会费:18000";
        QTreeWidgetItem *a17 = new QTreeWidgetItem(age17);
        MuBaPei->addChild(a17);
        QTreeWidgetItem *r17 = new QTreeWidgetItem(rating17);
        MuBaPei->addChild(r17);
        QTreeWidgetItem *p17 = new QTreeWidgetItem(position17);
        MuBaPei->addChild(p17);
        QTreeWidgetItem *w17 = new QTreeWidgetItem(weeksalary17);
        MuBaPei->addChild(w17);
        QTreeWidgetItem *t17 = new QTreeWidgetItem(transferfee17);
        MuBaPei->addChild(t17);

        QStringList age18;
        age18<<"年龄:28";
        QStringList rating18;
        rating18<<"能力值:92";
        QStringList position18;
        position18<<"位置:前锋/右脚";
        QStringList weeksalary18;
        weeksalary18<<"周薪:70";
        QStringList transferfee18;
        transferfee18<<"转会费:12800";
        QTreeWidgetItem *a18 = new QTreeWidgetItem(age18);
        NeiMaEr->addChild(a18);
        QTreeWidgetItem *r18 = new QTreeWidgetItem(rating18);
        NeiMaEr->addChild(r18);
        QTreeWidgetItem *p18 = new QTreeWidgetItem(position18);
        NeiMaEr->addChild(p18);
        QTreeWidgetItem *w18 = new QTreeWidgetItem(weeksalary18);
        NeiMaEr->addChild(w18);
        QTreeWidgetItem *t18 = new QTreeWidgetItem(transferfee18);
        NeiMaEr->addChild(t18);

        QStringList age19;
        age19<<"年龄:26";
        QStringList rating19;
        rating19<<"能力值:91";
        QStringList position19;
        position19<<"位置:前锋/左脚";
        QStringList weeksalary19;
        weeksalary19<<"周薪:26";
        QStringList transferfee19;
        transferfee19<<"转会费:8000";
        QTreeWidgetItem *a19 = new QTreeWidgetItem(age19);
        DiBaLa->addChild(a19);
        QTreeWidgetItem *r19 = new QTreeWidgetItem(rating19);
        DiBaLa->addChild(r19);
        QTreeWidgetItem *p19 = new QTreeWidgetItem(position19);
        DiBaLa->addChild(p19);
        QTreeWidgetItem *w19 = new QTreeWidgetItem(weeksalary19);
        DiBaLa->addChild(w19);
        QTreeWidgetItem *t19 = new QTreeWidgetItem(transferfee19);
        DiBaLa->addChild(t19);

        QStringList age20;
        age20<<"年龄:35";
        QStringList rating20;
        rating20<<"能力值:93";
        QStringList position20;
        position20<<"位置:前锋/右脚";
        QStringList weeksalary20;
        weeksalary20<<"周薪:110";
        QStringList transferfee20;
        transferfee20<<"转会费:6000";
        QTreeWidgetItem *a20 = new QTreeWidgetItem(age20);
        LuoNaErDuo->addChild(a20);
        QTreeWidgetItem *r20 = new QTreeWidgetItem(rating20);
        LuoNaErDuo->addChild(r20);
        QTreeWidgetItem *p20 = new QTreeWidgetItem(position20);
        LuoNaErDuo->addChild(p20);
        QTreeWidgetItem *w20 = new QTreeWidgetItem(weeksalary20);
        LuoNaErDuo->addChild(w20);
        QTreeWidgetItem *t20 = new QTreeWidgetItem(transferfee20);
        LuoNaErDuo->addChild(t20);

        QStringList age21;
        age21 << "年龄:29";
        QStringList rating21;
        rating21 << "能力值:91";
        QStringList position21;
        position21 << "位置:前锋/左右脚";
        QStringList weeksalary21;
        weeksalary21 << "周薪:60";
        QStringList transferfee21;
        transferfee21 << "转会费:8000";
        QTreeWidgetItem* a21 = new QTreeWidgetItem(age21);
        AZhaEr->addChild(a21);
        QTreeWidgetItem* r21 = new QTreeWidgetItem(rating21);
        AZhaEr->addChild(r21);
        QTreeWidgetItem* p21 = new QTreeWidgetItem(position21);
        AZhaEr->addChild(p21);
        QTreeWidgetItem* w21 = new QTreeWidgetItem(weeksalary21);
        AZhaEr->addChild(w21);
        QTreeWidgetItem* t21 = new QTreeWidgetItem(transferfee21);
        AZhaEr->addChild(t21);

        QStringList age22;
        age22 << "年龄:31";
        QStringList rating22;
        rating22 << "能力值:85";
        QStringList position22;
        position22 << "位置:前锋/左脚";
        QStringList weeksalary22;
        weeksalary22 << "周薪:53";
        QStringList transferfee22;
        transferfee22 << "转会费:2800";
        QTreeWidgetItem* a22 = new QTreeWidgetItem(age22);
        BeiEr->addChild(a22);
        QTreeWidgetItem* r22 = new QTreeWidgetItem(rating22);
        BeiEr->addChild(r22);
        QTreeWidgetItem* p22 = new QTreeWidgetItem(position22);
        BeiEr->addChild(p22);
        QTreeWidgetItem* w22 = new QTreeWidgetItem(weeksalary22);
        BeiEr->addChild(w22);
        QTreeWidgetItem* t22 = new QTreeWidgetItem(transferfee22);
        BeiEr->addChild(t22);

        QStringList age23;
        age23 << "年龄:24";
        QStringList rating23;
        rating23 << "能力值:82";
        QStringList position23;
        position23 << "位置:前锋/左脚";
        QStringList weeksalary23;
        weeksalary23 << "周薪:16";
        QStringList transferfee23;
        transferfee23 << "转会费:4000";
        QTreeWidgetItem* a23 = new QTreeWidgetItem(age23);
        ASenXiAo->addChild(a23);
        QTreeWidgetItem* r23 = new QTreeWidgetItem(rating23);
        ASenXiAo->addChild(r23);
        QTreeWidgetItem* p23 = new QTreeWidgetItem(position23);
        ASenXiAo->addChild(p23);
        QTreeWidgetItem* w23 = new QTreeWidgetItem(weeksalary23);
        ASenXiAo->addChild(w23);
        QTreeWidgetItem* t23 = new QTreeWidgetItem(transferfee23);
        ASenXiAo->addChild(t23);

        QStringList age24;
        age24 << "年龄:19";
        QStringList rating24;
        rating24 << "能力值:83";
        QStringList position24;
        position24 << "位置:前锋/右脚";
        QStringList weeksalary24;
        weeksalary24 << "周薪:16";
        QStringList transferfee24;
        transferfee24 << "转会费:4500";
        QTreeWidgetItem* a24 = new QTreeWidgetItem(age24);
        LuoDeLiGe->addChild(a24);
        QTreeWidgetItem* r24 = new QTreeWidgetItem(rating24);
        LuoDeLiGe->addChild(r24);
        QTreeWidgetItem* p24 = new QTreeWidgetItem(position24);
        LuoDeLiGe->addChild(p24);
        QTreeWidgetItem* w24 = new QTreeWidgetItem(weeksalary24);
        LuoDeLiGe->addChild(w24);
        QTreeWidgetItem* t24 = new QTreeWidgetItem(transferfee24);
        LuoDeLiGe->addChild(t24);

        QStringList age25;
        age25 << "年龄:28";
        QStringList rating25;
        rating25 << "能力值:88";
        QStringList position25;
        position25 << "位置:前锋/右脚";
        QStringList weeksalary25;
        weeksalary25 << "周薪:18";
        QStringList transferfee25;
        transferfee25 << "转会费:7200";
        QTreeWidgetItem* a25 = new QTreeWidgetItem(age25);
        FeiErMiNuo->addChild(a25);
        QTreeWidgetItem* r25 = new QTreeWidgetItem(rating25);
        FeiErMiNuo->addChild(r25);
        QTreeWidgetItem* p25 = new QTreeWidgetItem(position25);
        FeiErMiNuo->addChild(p25);
        QTreeWidgetItem* w25 = new QTreeWidgetItem(weeksalary25);
        FeiErMiNuo->addChild(w25);
        QTreeWidgetItem* t25 = new QTreeWidgetItem(transferfee25);
        FeiErMiNuo->addChild(t25);

        QStringList age26;
        age26 << "年龄:28";
        QStringList rating26;
        rating26 << "能力值:90";
        QStringList position26;
        position26 << "位置:前锋/左脚";
        QStringList weeksalary26;
        weeksalary26 << "周薪:20";
        QStringList transferfee26;
        transferfee26 << "转会费:12000";
        QTreeWidgetItem* a26 = new QTreeWidgetItem(age26);
        SaLaHe->addChild(a26);
        QTreeWidgetItem* r26 = new QTreeWidgetItem(rating26);
        SaLaHe->addChild(r26);
        QTreeWidgetItem* p26 = new QTreeWidgetItem(position26);
        SaLaHe->addChild(p26);
        QTreeWidgetItem* w26 = new QTreeWidgetItem(weeksalary26);
        SaLaHe->addChild(w26);
        QTreeWidgetItem* t26 = new QTreeWidgetItem(transferfee26);
        SaLaHe->addChild(t26);

        QStringList age27;
        age27 << "年龄:28";
        QStringList rating27;
        rating27 << "能力值:90";
        QStringList position27;
        position27 << "位置:前锋/右脚";
        QStringList weeksalary27;
        weeksalary27 << "周薪:15";
        QStringList transferfee27;
        transferfee27 << "转会费:12000";
        QTreeWidgetItem* a27 = new QTreeWidgetItem(age27);
        MaNei->addChild(a27);
        QTreeWidgetItem* r27 = new QTreeWidgetItem(rating27);
        MaNei->addChild(r27);
        QTreeWidgetItem* p27 = new QTreeWidgetItem(position27);
        MaNei->addChild(p27);
        QTreeWidgetItem* w27 = new QTreeWidgetItem(weeksalary27);
        MaNei->addChild(w27);
        QTreeWidgetItem* t27 = new QTreeWidgetItem(transferfee27);
        MaNei->addChild(t27);

        QStringList age28;
        age28 << "年龄:25";
        QStringList rating28;
        rating28 << "能力值:88";
        QStringList position28;
        position28 << "位置:前锋/右脚";
        QStringList weeksalary28;
        weeksalary28 << "周薪:15";
        QStringList transferfee28;
        transferfee28 << "转会费:12800";
        QTreeWidgetItem* a28 = new QTreeWidgetItem(age28);
        SiTeLin->addChild(a28);
        QTreeWidgetItem* r28 = new QTreeWidgetItem(rating28);
        SiTeLin->addChild(r28);
        QTreeWidgetItem* p28 = new QTreeWidgetItem(position28);
        SiTeLin->addChild(p28);
        QTreeWidgetItem* w28 = new QTreeWidgetItem(weeksalary28);
        SiTeLin->addChild(w28);
        QTreeWidgetItem* t28 = new QTreeWidgetItem(transferfee28);
        SiTeLin->addChild(t28);

        QStringList age29;
        age29 << "年龄:23";
        QStringList rating29;
        rating29 << "能力值:82";
        QStringList position29;
        position29 << "位置:前锋/右脚";
        QStringList weeksalary29;
        weeksalary29 << "周薪:9";
        QStringList transferfee29;
        transferfee29 << "转会费:5600";
        QTreeWidgetItem* a29 = new QTreeWidgetItem(age29);
        ReSuSi->addChild(a29);
        QTreeWidgetItem* r29 = new QTreeWidgetItem(rating29);
        ReSuSi->addChild(r29);
        QTreeWidgetItem* p29 = new QTreeWidgetItem(position29);
        ReSuSi->addChild(p29);
        QTreeWidgetItem* w29 = new QTreeWidgetItem(weeksalary29);
        ReSuSi->addChild(w29);
        QTreeWidgetItem* t29 = new QTreeWidgetItem(transferfee29);
        ReSuSi->addChild(t29);

        QStringList age30;
        age30 << "年龄:29";
        QStringList rating30;
        rating30 << "能力值:86";
        QStringList position30;
        position30 << "位置:前锋/左脚";
        QStringList weeksalary30;
        weeksalary30 << "周薪:20";
        QStringList transferfee30;
        transferfee30 << "转会费:4800";
        QTreeWidgetItem* a30 = new QTreeWidgetItem(age30);
        MaHeLeiSi->addChild(a30);
        QTreeWidgetItem* r30 = new QTreeWidgetItem(rating30);
        MaHeLeiSi->addChild(r30);
        QTreeWidgetItem* p30 = new QTreeWidgetItem(position30);
        MaHeLeiSi->addChild(p30);
        QTreeWidgetItem* w30 = new QTreeWidgetItem(weeksalary30);
        MaHeLeiSi->addChild(w30);
        QTreeWidgetItem* t30 = new QTreeWidgetItem(transferfee30);
        MaHeLeiSi->addChild(t30);

        QStringList age31;
        age31 << "年龄:32";
        QStringList rating31;
        rating31 << "能力值:89";
        QStringList position31;
        position31 << "位置:前锋/左右脚";
        QStringList weeksalary31;
        weeksalary31 << "周薪:23";
        QStringList transferfee31;
        transferfee31 << "转会费:5200";
        QTreeWidgetItem* a31 = new QTreeWidgetItem(age31);
        AGuiLuo->addChild(a31);
        QTreeWidgetItem* r31 = new QTreeWidgetItem(rating31);
        AGuiLuo->addChild(r31);
        QTreeWidgetItem* p31 = new QTreeWidgetItem(position31);
        AGuiLuo->addChild(p31);
        QTreeWidgetItem* w31 = new QTreeWidgetItem(weeksalary31);
        AGuiLuo->addChild(w31);
        QTreeWidgetItem* t31 = new QTreeWidgetItem(transferfee31);
        AGuiLuo->addChild(t31);

        QStringList age32;
        age32 << "年龄:29";
        QStringList rating32;
        rating32 << "能力值:89";
        QStringList position32;
        position32 << "位置:前锋/左脚";
        QStringList weeksalary32;
        weeksalary32 << "周薪:68";
        QStringList transferfee32;
        transferfee32 << "转会费:9600";
        QTreeWidgetItem* a32 = new QTreeWidgetItem(age32);
        GeLieZiMan->addChild(a32);
        QTreeWidgetItem* r32 = new QTreeWidgetItem(rating32);
        GeLieZiMan->addChild(r32);
        QTreeWidgetItem* p32 = new QTreeWidgetItem(position32);
        GeLieZiMan->addChild(p32);
        QTreeWidgetItem* w32 = new QTreeWidgetItem(weeksalary32);
        GeLieZiMan->addChild(w32);
        QTreeWidgetItem* t32 = new QTreeWidgetItem(transferfee32);
        GeLieZiMan->addChild(t32);

        QStringList age33;
        age33 << "年龄:33";
        QStringList rating33;
        rating33 << "能力值:94";
        QStringList position33;
        position33 << "位置:前锋/左脚";
        QStringList weeksalary33;
        weeksalary33 << "周薪:136";
        QStringList transferfee33;
        transferfee33 << "转会费:11200";
        QTreeWidgetItem* a33 = new QTreeWidgetItem(age33);
        MeiXi->addChild(a33);
        QTreeWidgetItem* r33 = new QTreeWidgetItem(rating33);
        MeiXi->addChild(r33);
        QTreeWidgetItem* p33 = new QTreeWidgetItem(position33);
        MeiXi->addChild(p33);
        QTreeWidgetItem* w33 = new QTreeWidgetItem(weeksalary33);
        MeiXi->addChild(w33);
        QTreeWidgetItem* t33 = new QTreeWidgetItem(transferfee33);
        MeiXi->addChild(t33);

        QStringList age34;
        age34 << "年龄:33";
        QStringList rating34;
        rating34 << "能力值:89";
        QStringList position34;
        position34 << "位置:前锋/右脚";
        QStringList weeksalary34;
        weeksalary34 << "周薪:45";
        QStringList transferfee34;
        transferfee34 << "转会费:2800";
        QTreeWidgetItem* a34 = new QTreeWidgetItem(age34);
        SuYaLeiSi->addChild(a34);
        QTreeWidgetItem* r34 = new QTreeWidgetItem(rating34);
        SuYaLeiSi->addChild(r34);
        QTreeWidgetItem* p34 = new QTreeWidgetItem(position34);
        SuYaLeiSi->addChild(p34);
        QTreeWidgetItem* w34 = new QTreeWidgetItem(weeksalary34);
        SuYaLeiSi->addChild(w34);
        QTreeWidgetItem* t34 = new QTreeWidgetItem(transferfee34);
        SuYaLeiSi->addChild(t34);

        QStringList age35;
        age35 << "年龄:25";
        QStringList rating35;
        rating35 << "能力值:85";
        QStringList position35;
        position35 << "位置:前锋/右脚";
        QStringList weeksalary35;
        weeksalary35 << "周薪:9";
        QStringList transferfee35;
        transferfee35 << "转会费:7200";
        QTreeWidgetItem* a35 = new QTreeWidgetItem(age35);
        GeNaBuLi->addChild(a35);
        QTreeWidgetItem* r35 = new QTreeWidgetItem(rating35);
        GeNaBuLi->addChild(r35);
        QTreeWidgetItem* p35 = new QTreeWidgetItem(position35);
        GeNaBuLi->addChild(p35);
        QTreeWidgetItem* w35 = new QTreeWidgetItem(weeksalary35);
        GeNaBuLi->addChild(w35);
        QTreeWidgetItem* t35 = new QTreeWidgetItem(transferfee35);
        GeNaBuLi->addChild(t35);

        QStringList age36;
        age36 << "年龄:25";
        QStringList rating36;
        rating36 << "能力值:86";
        QStringList position36;
        position36 << "前锋/左脚";
        QStringList weeksalary36;
        weeksalary36 << "周薪:9";
        QStringList transferfee36;
        transferfee36 << "转会费:8000";
        QTreeWidgetItem* a36 = new QTreeWidgetItem(age36);
        SaNei->addChild(a36);
        QTreeWidgetItem* r36 = new QTreeWidgetItem(rating36);
        SaNei->addChild(r36);
        QTreeWidgetItem* p36 = new QTreeWidgetItem(position36);
        SaNei->addChild(p36);
        QTreeWidgetItem* w36 = new QTreeWidgetItem(weeksalary36);
        SaNei->addChild(w36);
        QTreeWidgetItem* t36 = new QTreeWidgetItem(transferfee36);
        SaNei->addChild(t36);

        QStringList age37;
        age37 << "年龄:20";
        QStringList rating37;
        rating37 << "能力值:80";
        QStringList position37;
        position37 << "前锋/左脚";
        QStringList weeksalary37;
        weeksalary37 << "周薪:8";
        QStringList transferfee37;
        transferfee37 << "转会费:7200";
        QTreeWidgetItem* a37 = new QTreeWidgetItem(age37);
        HaLanDe->addChild(a37);
        QTreeWidgetItem* r37 = new QTreeWidgetItem(rating37);
        HaLanDe->addChild(r37);
        QTreeWidgetItem* p37 = new QTreeWidgetItem(position37);
        HaLanDe->addChild(p37);
        QTreeWidgetItem* w37 = new QTreeWidgetItem(weeksalary37);
        HaLanDe->addChild(w37);
        QTreeWidgetItem* t37 = new QTreeWidgetItem(transferfee37);
        HaLanDe->addChild(t37);

        QStringList age38;
        age38 << "年龄:24";
        QStringList rating38;
        rating38 << "能力值:84";
        QStringList position38;
        position38 << "前锋/右脚";
        QStringList weeksalary38;
        weeksalary38 << "周薪:8";
        QStringList transferfee38;
        transferfee38 << "转会费:4000";
        QTreeWidgetItem* a38 = new QTreeWidgetItem(age38);
        BuLanTe->addChild(a38);
        QTreeWidgetItem* r38 = new QTreeWidgetItem(rating38);
        BuLanTe->addChild(r38);
        QTreeWidgetItem* p38 = new QTreeWidgetItem(position38);
        BuLanTe->addChild(p38);
        QTreeWidgetItem* w38 = new QTreeWidgetItem(weeksalary38);
        BuLanTe->addChild(w38);
        QTreeWidgetItem* t38 = new QTreeWidgetItem(transferfee38);
        BuLanTe->addChild(t38);

        QStringList age39;
        age39 << "年龄:31";
        QStringList rating39;
        rating39 << "能力值:84";
        QStringList position39;
        position39 << "前锋/右脚";
        QStringList weeksalary39;
        weeksalary39 << "周薪:21";
        QStringList transferfee39;
        transferfee39 << "转会费:2500";
        QTreeWidgetItem* a39 = new QTreeWidgetItem(age39);
        LuoYiSi->addChild(a39);
        QTreeWidgetItem* r39 = new QTreeWidgetItem(rating39);
        LuoYiSi->addChild(r39);
        QTreeWidgetItem* p39 = new QTreeWidgetItem(position39);
        LuoYiSi->addChild(p39);
        QTreeWidgetItem* w39 = new QTreeWidgetItem(weeksalary39);
        LuoYiSi->addChild(w39);
        QTreeWidgetItem* t39 = new QTreeWidgetItem(transferfee39);
        LuoYiSi->addChild(t39);

        QStringList age40;
        age40 << "年龄:28";
        QStringList rating40;
        rating40 << "能力值:82";
        QStringList position40;
        position40 << "前锋/左脚";
        QStringList weeksalary40;
        weeksalary40 << "周薪:10";
        QStringList transferfee40;
        transferfee40 << "转会费:2800";
        QTreeWidgetItem* a40 = new QTreeWidgetItem(age40);
        FuLanDe->addChild(a40);
        QTreeWidgetItem* r40 = new QTreeWidgetItem(rating40);
        FuLanDe->addChild(r40);
        QTreeWidgetItem* p40 = new QTreeWidgetItem(position40);
        FuLanDe->addChild(p40);
        QTreeWidgetItem* w40 = new QTreeWidgetItem(weeksalary40);
        FuLanDe->addChild(w40);
        QTreeWidgetItem* t40 = new QTreeWidgetItem(transferfee40);
        FuLanDe->addChild(t40);

        QStringList age41;
        age41 << "年龄:27";
        QStringList rating41;
        rating41 << "能力值:86";
        QStringList position41;
        position41 << "前锋/右脚";
        QStringList weeksalary41;
        weeksalary41 << "周薪:24";
        QStringList transferfee41;
        transferfee41 << "转会费:6000";
        QTreeWidgetItem* a41 = new QTreeWidgetItem(age41);
        YiKaErDi->addChild(a41);
        QTreeWidgetItem* r41 = new QTreeWidgetItem(rating41);
        YiKaErDi->addChild(r41);
        QTreeWidgetItem* p41 = new QTreeWidgetItem(position41);
        YiKaErDi->addChild(p41);
        QTreeWidgetItem* w41 = new QTreeWidgetItem(weeksalary41);
        YiKaErDi->addChild(w41);
        QTreeWidgetItem* t41 = new QTreeWidgetItem(transferfee41);
        YiKaErDi->addChild(t41);

        QStringList age42;
        age42 << "年龄:27";
        QStringList rating42;
        rating42 << "能力值:86";
        QStringList position42;
        position42 << "前锋/左脚";
        QStringList weeksalary42;
        weeksalary42 << "周薪:18";
        QStringList transferfee42;
        transferfee42 << "转会费:8500";
        QTreeWidgetItem* a42 = new QTreeWidgetItem(age42);
        LuKaKu->addChild(a42);
        QTreeWidgetItem* r42 = new QTreeWidgetItem(rating42);
        LuKaKu->addChild(r42);
        QTreeWidgetItem* p42 = new QTreeWidgetItem(position42);
        LuKaKu->addChild(p42);
        QTreeWidgetItem* w42 = new QTreeWidgetItem(weeksalary42);
        LuKaKu->addChild(w42);
        QTreeWidgetItem* t42 = new QTreeWidgetItem(transferfee42);
        LuKaKu->addChild(t42);

        QStringList age43;
        age43 << "年龄:31";
        QStringList rating43;
        rating43 << "能力值:81";
        QStringList position43;
        position43 << "前锋/右脚";
        QStringList weeksalary43;
        weeksalary43 << "周薪:38";
        QStringList transferfee43;
        transferfee43 << "转会费:1600";
        QTreeWidgetItem* a43 = new QTreeWidgetItem(age43);
        SangQieSi->addChild(a43);
        QTreeWidgetItem* r43 = new QTreeWidgetItem(rating43);
        SangQieSi->addChild(r43);
        QTreeWidgetItem* p43 = new QTreeWidgetItem(position43);
        SangQieSi->addChild(p43);
        QTreeWidgetItem* w43 = new QTreeWidgetItem(weeksalary43);
        SangQieSi->addChild(w43);
        QTreeWidgetItem* t43 = new QTreeWidgetItem(transferfee43);
        SangQieSi->addChild(t43);
    }
    //“选择前锋”按钮
    connect(ui->ChooseForwardBtn,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        check_1 = true;
        check_2 = true;
        if(ui->checkBox->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("莱万多夫斯基");
            else if (forward2 == QString())
                forward2 = QString("莱万多夫斯基");
            else if (forward3 == QString())
                forward3 = QString("莱万多夫斯基");
            else if (forward4 == QString())
                forward4 = QString("莱万多夫斯基");
            else if (forward5 == QString())
                forward5 = QString("莱万多夫斯基");
            else if (forward6 == QString())
                forward6 = QString("莱万多夫斯基");
            else if (forward7 == QString())
                forward7 = QString("莱万多夫斯基");
        }
        if (ui->checkBox_2->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("穆勒");
            else if (forward2 == QString())
                forward2 = QString("穆勒");
            else if (forward3 == QString())
                forward3 = QString("穆勒");
            else if (forward4 == QString())
                forward4 = QString("穆勒");
            else if (forward5 == QString())
                forward5 = QString("穆勒");
            else if (forward6 == QString())
                forward6 = QString("穆勒");
            else if (forward7 == QString())
                forward7 = QString("穆勒");
        }
        if (ui->checkBox_3->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("吉鲁");
            else if (forward2 == QString())
                forward2 = QString("吉鲁");
            else if (forward3 == QString())
                forward3 = QString("吉鲁");
            else if (forward4 == QString())
                forward4 = QString("吉鲁");
            else if (forward5 == QString())
                forward5 = QString("吉鲁");
            else if (forward6 == QString())
                forward6 = QString("吉鲁");
            else if (forward7 == QString())
                forward7 = QString("吉鲁");
        }
        if(ui->checkBox_4->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("亚伯拉罕");
            else if (forward2 == QString())
                forward2 = QString("亚伯拉罕");
            else if (forward3 == QString())
                forward3 = QString("亚伯拉罕");
            else if (forward4 == QString())
                forward4 = QString("亚伯拉罕");
            else if (forward5 == QString())
                forward5 = QString("亚伯拉罕");
            else if (forward6 == QString())
                forward6 = QString("亚伯拉罕");
            else if (forward7 == QString())
                forward7 = QString("亚伯拉罕");
        }
        if(ui->checkBox_5->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("维尔纳");
            else if (forward2 == QString())
                forward2 = QString("维尔纳");
            else if (forward3 == QString())
                forward3 = QString("维尔纳");
            else if (forward4 == QString())
                forward4 = QString("维尔纳");
            else if (forward5 == QString())
                forward5 = QString("维尔纳");
            else if (forward6 == QString())
                forward6 = QString("维尔纳");
            else if (forward7 == QString())
                forward7 = QString("维尔纳");
        }
        if(ui->checkBox_6->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("奥巴梅杨");
            else if (forward2 == QString())
                forward2 = QString("奥巴梅杨");
            else if (forward3 == QString())
                forward3 = QString("奥巴梅杨");
            else if (forward4 == QString())
                forward4 = QString("奥巴梅杨");
            else if (forward5 == QString())
                forward5 = QString("奥巴梅杨");
            else if (forward6 == QString())
                forward6 = QString("奥巴梅杨");
            else if (forward7 == QString())
                forward7 = QString("奥巴梅杨");
        }
        if(ui->checkBox_7->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("威廉");
            else if (forward2 == QString())
                forward2 = QString("威廉");
            else if (forward3 == QString())
                forward3 = QString("威廉");
            else if (forward4 == QString())
                forward4 = QString("威廉");
            else if (forward5 == QString())
                forward5 = QString("威廉");
            else if (forward6 == QString())
                forward6 = QString("威廉");
            else if (forward7 == QString())
                forward7 = QString("威廉");
        }
        if(ui->checkBox_8->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("姆巴佩");
            else if (forward2 == QString())
                forward2 = QString("姆巴佩");
            else if (forward3 == QString())
                forward3 = QString("姆巴佩");
            else if (forward4 == QString())
                forward4 = QString("姆巴佩");
            else if (forward5 == QString())
                forward5 = QString("姆巴佩");
            else if (forward6 == QString())
                forward6 = QString("姆巴佩");
            else if (forward7 == QString())
                forward7 = QString("姆巴佩");
        }
        if(ui->checkBox_9->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("内马尔");
            else if (forward2 == QString())
                forward2 = QString("内马尔");
            else if (forward3 == QString())
                forward3 = QString("内马尔");
            else if (forward4 == QString())
                forward4 = QString("内马尔");
            else if (forward5 == QString())
                forward5 = QString("内马尔");
            else if (forward6 == QString())
                forward6 = QString("内马尔");
            else if (forward7 == QString())
                forward7 = QString("内马尔");
        }
        if(ui->checkBox_10->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("迪巴拉");
            else if (forward2 == QString())
                forward2 = QString("迪巴拉");
            else if (forward3 == QString())
                forward3 = QString("迪巴拉");
            else if (forward4 == QString())
                forward4 = QString("迪巴拉");
            else if (forward5 == QString())
                forward5 = QString("迪巴拉");
            else if (forward6 == QString())
                forward6 = QString("迪巴拉");
            else if (forward7 == QString())
                forward7 = QString("迪巴拉");
        }
        if(ui->checkBox_11->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("罗纳尔多");
            else if (forward2 == QString())
                forward2 = QString("罗纳尔多");
            else if (forward3 == QString())
                forward3 = QString("罗纳尔多");
            else if (forward4 == QString())
                forward4 = QString("罗纳尔多");
            else if (forward5 == QString())
                forward5 = QString("罗纳尔多");
            else if (forward6 == QString())
                forward6 = QString("罗纳尔多");
            else if (forward7 == QString())
                forward7 = QString("罗纳尔多");
        }
        if(ui->checkBox_12->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("阿扎尔");
            else if (forward2 == QString())
                forward2 = QString("阿扎尔");
            else if (forward3 == QString())
                forward3 = QString("阿扎尔");
            else if (forward4 == QString())
                forward4 = QString("阿扎尔");
            else if (forward5 == QString())
                forward5 = QString("阿扎尔");
            else if (forward6 == QString())
                forward6 = QString("阿扎尔");
            else if (forward7 == QString())
                forward7 = QString("阿扎尔");
        }
        if(ui->checkBox_13->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("贝尔");
            else if (forward2 == QString())
                forward2 = QString("贝尔");
            else if (forward3 == QString())
                forward3 = QString("贝尔");
            else if (forward4 == QString())
                forward4 = QString("贝尔");
            else if (forward5 == QString())
                forward5 = QString("贝尔");
            else if (forward6 == QString())
                forward6 = QString("贝尔");
            else if (forward7 == QString())
                forward7 = QString("贝尔");
        }
        if(ui->checkBox_14->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("阿森西奥");
            else if (forward2 == QString())
                forward2 = QString("阿森西奥");
            else if (forward3 == QString())
                forward3 = QString("阿森西奥");
            else if (forward4 == QString())
                forward4 = QString("阿森西奥");
            else if (forward5 == QString())
                forward5 = QString("阿森西奥");
            else if (forward6 == QString())
                forward6 = QString("阿森西奥");
            else if (forward7 == QString())
                forward7 = QString("阿森西奥");
        }
        if(ui->checkBox_15->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("罗德里戈");
            else if (forward2 == QString())
                forward2 = QString("罗德里戈");
            else if (forward3 == QString())
                forward3 = QString("罗德里戈");
            else if (forward4 == QString())
                forward4 = QString("罗德里戈");
            else if (forward5 == QString())
                forward5 = QString("罗德里戈");
            else if (forward6 == QString())
                forward6 = QString("罗德里戈");
            else if (forward7 == QString())
                forward7 = QString("罗德里戈");
        }
        if(ui->checkBox_16->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("菲尔米诺");
            else if (forward2 == QString())
                forward2 = QString("菲尔米诺");
            else if (forward3 == QString())
                forward3 = QString("菲尔米诺");
            else if (forward4 == QString())
                forward4 = QString("菲尔米诺");
            else if (forward5 == QString())
                forward5 = QString("菲尔米诺");
            else if (forward6 == QString())
                forward6 = QString("菲尔米诺");
            else if (forward7 == QString())
                forward7 = QString("菲尔米诺");
        }
        if(ui->checkBox_17->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("萨拉赫");
            else if (forward2 == QString())
                forward2 = QString("萨拉赫");
            else if (forward3 == QString())
                forward3 = QString("萨拉赫");
            else if (forward4 == QString())
                forward4 = QString("萨拉赫");
            else if (forward5 == QString())
                forward5 = QString("萨拉赫");
            else if (forward6 == QString())
                forward6 = QString("萨拉赫");
            else if (forward7 == QString())
                forward7 = QString("萨拉赫");
        }
        if(ui->checkBox_18->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("马内");
            else if (forward2 == QString())
                forward2 = QString("马内");
            else if (forward3 == QString())
                forward3 = QString("马内");
            else if (forward4 == QString())
                forward4 = QString("马内");
            else if (forward5 == QString())
                forward5 = QString("马内");
            else if (forward6 == QString())
                forward6 = QString("马内");
            else if (forward7 == QString())
                forward7 = QString("马内");
        }
        if(ui->checkBox_28->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("斯特林");
            else if (forward2 == QString())
                forward2 = QString("斯特林");
            else if (forward3 == QString())
                forward3 = QString("斯特林");
            else if (forward4 == QString())
                forward4 = QString("斯特林");
            else if (forward5 == QString())
                forward5 = QString("斯特林");
            else if (forward6 == QString())
                forward6 = QString("斯特林");
            else if (forward7 == QString())
                forward7 = QString("斯特林");
        }
        if(ui->checkBox_29->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("热苏斯");
            else if (forward2 == QString())
                forward2 = QString("热苏斯");
            else if (forward3 == QString())
                forward3 = QString("热苏斯");
            else if (forward4 == QString())
                forward4 = QString("热苏斯");
            else if (forward5 == QString())
                forward5 = QString("热苏斯");
            else if (forward6 == QString())
                forward6 = QString("热苏斯");
            else if (forward7 == QString())
                forward7 = QString("热苏斯");
        }
        if(ui->checkBox_30->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("马赫雷斯");
            else if (forward2 == QString())
                forward2 = QString("马赫雷斯");
            else if (forward3 == QString())
                forward3 = QString("马赫雷斯");
            else if (forward4 == QString())
                forward4 = QString("马赫雷斯");
            else if (forward5 == QString())
                forward5 = QString("马赫雷斯");
            else if (forward6 == QString())
                forward6 = QString("马赫雷斯");
            else if (forward7 == QString())
                forward7 = QString("马赫雷斯");
        }
        if(ui->checkBox_31->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("阿圭罗");
            else if (forward2 == QString())
                forward2 = QString("阿圭罗");
            else if (forward3 == QString())
                forward3 = QString("阿圭罗");
            else if (forward4 == QString())
                forward4 = QString("阿圭罗");
            else if (forward5 == QString())
                forward5 = QString("阿圭罗");
            else if (forward6 == QString())
                forward6 = QString("阿圭罗");
            else if (forward7 == QString())
                forward7 = QString("阿圭罗");
        }
        if(ui->checkBox_32->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("格列兹曼");
            else if (forward2 == QString())
                forward2 = QString("格列兹曼");
            else if (forward3 == QString())
                forward3 = QString("格列兹曼");
            else if (forward4 == QString())
                forward4 = QString("格列兹曼");
            else if (forward5 == QString())
                forward5 = QString("格列兹曼");
            else if (forward6 == QString())
                forward6 = QString("格列兹曼");
            else if (forward7 == QString())
                forward7 = QString("格列兹曼");
        }
        if(ui->checkBox_33->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("梅西");
            else if (forward2 == QString())
                forward2 = QString("梅西");
            else if (forward3 == QString())
                forward3 = QString("梅西");
            else if (forward4 == QString())
                forward4 = QString("梅西");
            else if (forward5 == QString())
                forward5 = QString("梅西");
            else if (forward6 == QString())
                forward6 = QString("梅西");
            else if (forward7 == QString())
                forward7 = QString("梅西");
        }
        if(ui->checkBox_34->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("苏亚雷斯");
            else if (forward2 == QString())
                forward2 = QString("苏亚雷斯");
            else if (forward3 == QString())
                forward3 = QString("苏亚雷斯");
            else if (forward4 == QString())
                forward4 = QString("苏亚雷斯");
            else if (forward5 == QString())
                forward5 = QString("苏亚雷斯");
            else if (forward6 == QString())
                forward6 = QString("苏亚雷斯");
            else if (forward7 == QString())
                forward7 = QString("苏亚雷斯");
        }
        if(ui->checkBox_35->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("格纳布里");
            else if (forward2 == QString())
                forward2 = QString("格纳布里");
            else if (forward3 == QString())
                forward3 = QString("格纳布里");
            else if (forward4 == QString())
                forward4 = QString("格纳布里");
            else if (forward5 == QString())
                forward5 = QString("格纳布里");
            else if (forward6 == QString())
                forward6 = QString("格纳布里");
            else if (forward7 == QString())
                forward7 = QString("格纳布里");
        }
        if(ui->checkBox_36->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("塞内");
            else if (forward2 == QString())
                forward2 = QString("塞内");
            else if (forward3 == QString())
                forward3 = QString("塞内");
            else if (forward4 == QString())
                forward4 = QString("塞内");
            else if (forward5 == QString())
                forward5 = QString("塞内");
            else if (forward6 == QString())
                forward6 = QString("塞内");
            else if (forward7 == QString())
                forward7 = QString("塞内");
        }
        if(ui->checkBox_37->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("哈兰德");
            else if (forward2 == QString())
                forward2 = QString("哈兰德");
            else if (forward3 == QString())
                forward3 = QString("哈兰德");
            else if (forward4 == QString())
                forward4 = QString("哈兰德");
            else if (forward5 == QString())
                forward5 = QString("哈兰德");
            else if (forward6 == QString())
                forward6 = QString("哈兰德");
            else if (forward7 == QString())
                forward7 = QString("哈兰德");
        }
        if(ui->checkBox_38->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("布兰特");
            else if (forward2 == QString())
                forward2 = QString("布兰特");
            else if (forward3 == QString())
                forward3 = QString("布兰特");
            else if (forward4 == QString())
                forward4 = QString("布兰特");
            else if (forward5 == QString())
                forward5 = QString("布兰特");
            else if (forward6 == QString())
                forward6 = QString("布兰特");
            else if (forward7 == QString())
                forward7 = QString("布兰特");
        }
        if(ui->checkBox_39->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("罗伊斯");
            else if (forward2 == QString())
                forward2 = QString("罗伊斯");
            else if (forward3 == QString())
                forward3 = QString("罗伊斯");
            else if (forward4 == QString())
                forward4 = QString("罗伊斯");
            else if (forward5 == QString())
                forward5 = QString("罗伊斯");
            else if (forward6 == QString())
                forward6 = QString("罗伊斯");
            else if (forward7 == QString())
                forward7 = QString("罗伊斯");
        }
        if(ui->checkBox_40->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("弗兰德");
            else if (forward2 == QString())
                forward2 = QString("弗兰德");
            else if (forward3 == QString())
                forward3 = QString("弗兰德");
            else if (forward4 == QString())
                forward4 = QString("弗兰德");
            else if (forward5 == QString())
                forward5 = QString("弗兰德");
            else if (forward6 == QString())
                forward6 = QString("弗兰德");
            else if (forward7 == QString())
                forward7 = QString("弗兰德");
        }
        if(ui->checkBox_41->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("伊尔卡迪");
            else if (forward2 == QString())
                forward2 = QString("伊尔卡迪");
            else if (forward3 == QString())
                forward3 = QString("伊尔卡迪");
            else if (forward4 == QString())
                forward4 = QString("伊尔卡迪");
            else if (forward5 == QString())
                forward5 = QString("伊尔卡迪");
            else if (forward6 == QString())
                forward6 = QString("伊尔卡迪");
            else if (forward7 == QString())
                forward7 = QString("伊尔卡迪");
        }
        if(ui->checkBox_42->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("卢卡库");
            else if (forward2 == QString())
                forward2 = QString("卢卡库");
            else if (forward3 == QString())
                forward3 = QString("卢卡库");
            else if (forward4 == QString())
                forward4 = QString("卢卡库");
            else if (forward5 == QString())
                forward5 = QString("卢卡库");
            else if (forward6 == QString())
                forward6 = QString("卢卡库");
            else if (forward7 == QString())
                forward7 = QString("卢卡库");
        }
        if(ui->checkBox_43->isChecked())
        {
            ckBoxSum++;
            if (forward1 == QString())
                forward1 = QString("桑切斯");
            else if (forward2 == QString())
                forward2 = QString("桑切斯");
            else if (forward3 == QString())
                forward3 = QString("桑切斯");
            else if (forward4 == QString())
                forward4 = QString("桑切斯");
            else if (forward5 == QString())
                forward5 = QString("桑切斯");
            else if (forward6 == QString())
                forward6 = QString("桑切斯");
            else if (forward7 == QString())
                forward7 = QString("桑切斯");
        }
        qDebug()<<"forward1:"<<forward1;
        qDebug()<<"forward2:"<<forward2;
        qDebug()<<"forward3:"<<forward3;
        qDebug()<<"forward4:"<<forward4;
        qDebug()<<"forward5:"<<forward5;
        qDebug()<<"forward6:"<<forward6;
        qDebug()<<"forward7:"<<forward7;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        salarysum2 = 0;
        for (int i=0;i<100;i++)
        {
            if (forward1 == players[i].name)
                salarysum2 += players[i].weeksalary;
            else if (forward2 == players[i].name)
                salarysum2 += players[i].weeksalary;
            else if (forward3 == players[i].name)
                salarysum2 += players[i].weeksalary;
            else if (forward4 == players[i].name)
                salarysum2 += players[i].weeksalary;
            else if (forward5 == players[i].name)
                salarysum2 += players[i].weeksalary;
            else if (forward6 == players[i].name)
                salarysum2 += players[i].weeksalary;
            else if (forward7 == players[i].name)
                salarysum2 += players[i].weeksalary;
            else
                continue;
        }
        qDebug()<<"salarysum2:"<<salarysum2;

        //如果选择的前锋数目超过7个，弹窗警告
        if (ckBoxSum > 7)
        {
            check_1 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择七名前锋\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox->setCheckState(Qt::Unchecked);
                ui->checkBox->setChecked(false);
                ui->checkBox_2->setCheckState(Qt::Unchecked);
                ui->checkBox_2->setChecked(false);
                ui->checkBox_3->setCheckState(Qt::Unchecked);
                ui->checkBox_3->setChecked(false);
                ui->checkBox_4->setCheckState(Qt::Unchecked);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_5->setCheckState(Qt::Unchecked);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_6->setCheckState(Qt::Unchecked);
                ui->checkBox_6->setChecked(false);
                ui->checkBox_7->setCheckState(Qt::Unchecked);
                ui->checkBox_7->setChecked(false);
                ui->checkBox_8->setCheckState(Qt::Unchecked);
                ui->checkBox_8->setChecked(false);
                ui->checkBox_9->setCheckState(Qt::Unchecked);
                ui->checkBox_9->setChecked(false);
                ui->checkBox_10->setCheckState(Qt::Unchecked);
                ui->checkBox_10->setChecked(false);
                ui->checkBox_11->setCheckState(Qt::Unchecked);
                ui->checkBox_11->setChecked(false);
                ui->checkBox_12->setCheckState(Qt::Unchecked);
                ui->checkBox_12->setChecked(false);
                ui->checkBox_13->setCheckState(Qt::Unchecked);
                ui->checkBox_13->setChecked(false);
                ui->checkBox_14->setCheckState(Qt::Unchecked);
                ui->checkBox_14->setChecked(false);
                ui->checkBox_15->setCheckState(Qt::Unchecked);
                ui->checkBox_15->setChecked(false);
                ui->checkBox_16->setCheckState(Qt::Unchecked);
                ui->checkBox_16->setChecked(false);
                ui->checkBox_17->setCheckState(Qt::Unchecked);
                ui->checkBox_17->setChecked(false);
                ui->checkBox_18->setCheckState(Qt::Unchecked);
                ui->checkBox_18->setChecked(false);
                ui->checkBox_28->setCheckState(Qt::Unchecked);
                ui->checkBox_28->setChecked(false);
                ui->checkBox_29->setCheckState(Qt::Unchecked);
                ui->checkBox_29->setChecked(false);
                ui->checkBox_30->setCheckState(Qt::Unchecked);
                ui->checkBox_30->setChecked(false);
                ui->checkBox_31->setCheckState(Qt::Unchecked);
                ui->checkBox_31->setChecked(false);
                ui->checkBox_32->setCheckState(Qt::Unchecked);
                ui->checkBox_32->setChecked(false);
                ui->checkBox_33->setCheckState(Qt::Unchecked);
                ui->checkBox_33->setChecked(false);
                ui->checkBox_34->setCheckState(Qt::Unchecked);
                ui->checkBox_34->setChecked(false);
                ui->checkBox_35->setCheckState(Qt::Unchecked);
                ui->checkBox_35->setChecked(false);
                ui->checkBox_36->setCheckState(Qt::Unchecked);
                ui->checkBox_36->setChecked(false);
                ui->checkBox_37->setCheckState(Qt::Unchecked);
                ui->checkBox_37->setChecked(false);
                ui->checkBox_38->setCheckState(Qt::Unchecked);
                ui->checkBox_38->setChecked(false);
                ui->checkBox_39->setCheckState(Qt::Unchecked);
                ui->checkBox_39->setChecked(false);
                ui->checkBox_40->setCheckState(Qt::Unchecked);
                ui->checkBox_40->setChecked(false);
                ui->checkBox_41->setCheckState(Qt::Unchecked);
                ui->checkBox_41->setChecked(false);
                ui->checkBox_42->setCheckState(Qt::Unchecked);
                ui->checkBox_42->setChecked(false);
                ui->checkBox_43->setCheckState(Qt::Unchecked);
                ui->checkBox_43->setChecked(false);
                salarysum2 = 0;
                forward1 = QString();
                forward2 = QString();
                forward3 = QString();
                forward4 = QString();
                forward5 = QString();
                forward6 = QString();
                forward7 = QString();
                qDebug()<<"salarysum2:"<<salarysum2;
                qDebug()<<"forward1:"<<forward1;
                qDebug()<<"forward2:"<<forward2;
                qDebug()<<"forward3:"<<forward3;
                qDebug()<<"forward4:"<<forward4;
                qDebug()<<"forward5:"<<forward5;
                qDebug()<<"forward6:"<<forward6;
                qDebug()<<"forward7:"<<forward7;
            }
        }

        //如果选择的前锋数目不足7个，弹窗警告
        if (ckBoxSum < 7)
        {
            check_2 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的前锋数目不足七个\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox->setCheckState(Qt::Unchecked);
                ui->checkBox->setChecked(false);
                ui->checkBox_2->setCheckState(Qt::Unchecked);
                ui->checkBox_2->setChecked(false);
                ui->checkBox_3->setCheckState(Qt::Unchecked);
                ui->checkBox_3->setChecked(false);
                ui->checkBox_4->setCheckState(Qt::Unchecked);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_5->setCheckState(Qt::Unchecked);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_6->setCheckState(Qt::Unchecked);
                ui->checkBox_6->setChecked(false);
                ui->checkBox_7->setCheckState(Qt::Unchecked);
                ui->checkBox_7->setChecked(false);
                ui->checkBox_8->setCheckState(Qt::Unchecked);
                ui->checkBox_8->setChecked(false);
                ui->checkBox_9->setCheckState(Qt::Unchecked);
                ui->checkBox_9->setChecked(false);
                ui->checkBox_10->setCheckState(Qt::Unchecked);
                ui->checkBox_10->setChecked(false);
                ui->checkBox_11->setCheckState(Qt::Unchecked);
                ui->checkBox_11->setChecked(false);
                ui->checkBox_12->setCheckState(Qt::Unchecked);
                ui->checkBox_12->setChecked(false);
                ui->checkBox_13->setCheckState(Qt::Unchecked);
                ui->checkBox_13->setChecked(false);
                ui->checkBox_14->setCheckState(Qt::Unchecked);
                ui->checkBox_14->setChecked(false);
                ui->checkBox_15->setCheckState(Qt::Unchecked);
                ui->checkBox_15->setChecked(false);
                ui->checkBox_16->setCheckState(Qt::Unchecked);
                ui->checkBox_16->setChecked(false);
                ui->checkBox_17->setCheckState(Qt::Unchecked);
                ui->checkBox_17->setChecked(false);
                ui->checkBox_18->setCheckState(Qt::Unchecked);
                ui->checkBox_18->setChecked(false);
                ui->checkBox_28->setCheckState(Qt::Unchecked);
                ui->checkBox_28->setChecked(false);
                ui->checkBox_29->setCheckState(Qt::Unchecked);
                ui->checkBox_29->setChecked(false);
                ui->checkBox_30->setCheckState(Qt::Unchecked);
                ui->checkBox_30->setChecked(false);
                ui->checkBox_31->setCheckState(Qt::Unchecked);
                ui->checkBox_31->setChecked(false);
                ui->checkBox_32->setCheckState(Qt::Unchecked);
                ui->checkBox_32->setChecked(false);
                ui->checkBox_33->setCheckState(Qt::Unchecked);
                ui->checkBox_33->setChecked(false);
                ui->checkBox_34->setCheckState(Qt::Unchecked);
                ui->checkBox_34->setChecked(false);
                ui->checkBox_35->setCheckState(Qt::Unchecked);
                ui->checkBox_35->setChecked(false);
                ui->checkBox_36->setCheckState(Qt::Unchecked);
                ui->checkBox_36->setChecked(false);
                ui->checkBox_37->setCheckState(Qt::Unchecked);
                ui->checkBox_37->setChecked(false);
                ui->checkBox_38->setCheckState(Qt::Unchecked);
                ui->checkBox_38->setChecked(false);
                ui->checkBox_39->setCheckState(Qt::Unchecked);
                ui->checkBox_39->setChecked(false);
                ui->checkBox_40->setCheckState(Qt::Unchecked);
                ui->checkBox_40->setChecked(false);
                ui->checkBox_41->setCheckState(Qt::Unchecked);
                ui->checkBox_41->setChecked(false);
                ui->checkBox_42->setCheckState(Qt::Unchecked);
                ui->checkBox_42->setChecked(false);
                ui->checkBox_43->setCheckState(Qt::Unchecked);
                ui->checkBox_43->setChecked(false);
                salarysum2 = 0;
                forward1 = QString();
                forward2 = QString();
                forward3 = QString();
                forward4 = QString();
                forward5 = QString();
                forward6 = QString();
                forward7 = QString();
                qDebug()<<"salarysum2:"<<salarysum2;
                qDebug()<<"forward1:"<<forward1;
                qDebug()<<"forward2:"<<forward2;
                qDebug()<<"forward3:"<<forward3;
                qDebug()<<"forward4:"<<forward4;
                qDebug()<<"forward5:"<<forward5;
                qDebug()<<"forward6:"<<forward6;
                qDebug()<<"forward7:"<<forward7;
            }
        }

        //如果所选前锋的周薪总和大于等于160，弹窗询问
        if (salarysum2 >= 160)
        {
            int a = QMessageBox::question(this,QString("注意"),QString("过高的前锋薪资将会限制同队中其他球员的选择\n是否重新选择"),QMessageBox::Cancel|QMessageBox::Ok);
            //ok后重置并且重新选择
            if(a == QMessageBox::Ok)
            {
                ui->checkBox->setCheckState(Qt::Unchecked);
                ui->checkBox->setChecked(false);
                ui->checkBox_2->setCheckState(Qt::Unchecked);
                ui->checkBox_2->setChecked(false);
                ui->checkBox_3->setCheckState(Qt::Unchecked);
                ui->checkBox_3->setChecked(false);
                ui->checkBox_4->setCheckState(Qt::Unchecked);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_5->setCheckState(Qt::Unchecked);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_6->setCheckState(Qt::Unchecked);
                ui->checkBox_6->setChecked(false);
                ui->checkBox_7->setCheckState(Qt::Unchecked);
                ui->checkBox_7->setChecked(false);
                ui->checkBox_8->setCheckState(Qt::Unchecked);
                ui->checkBox_8->setChecked(false);
                ui->checkBox_9->setCheckState(Qt::Unchecked);
                ui->checkBox_9->setChecked(false);
                ui->checkBox_10->setCheckState(Qt::Unchecked);
                ui->checkBox_10->setChecked(false);
                ui->checkBox_11->setCheckState(Qt::Unchecked);
                ui->checkBox_11->setChecked(false);
                ui->checkBox_12->setCheckState(Qt::Unchecked);
                ui->checkBox_12->setChecked(false);
                ui->checkBox_13->setCheckState(Qt::Unchecked);
                ui->checkBox_13->setChecked(false);
                ui->checkBox_14->setCheckState(Qt::Unchecked);
                ui->checkBox_14->setChecked(false);
                ui->checkBox_15->setCheckState(Qt::Unchecked);
                ui->checkBox_15->setChecked(false);
                ui->checkBox_16->setCheckState(Qt::Unchecked);
                ui->checkBox_16->setChecked(false);
                ui->checkBox_17->setCheckState(Qt::Unchecked);
                ui->checkBox_17->setChecked(false);
                ui->checkBox_18->setCheckState(Qt::Unchecked);
                ui->checkBox_18->setChecked(false);
                ui->checkBox_28->setCheckState(Qt::Unchecked);
                ui->checkBox_28->setChecked(false);
                ui->checkBox_29->setCheckState(Qt::Unchecked);
                ui->checkBox_29->setChecked(false);
                ui->checkBox_30->setCheckState(Qt::Unchecked);
                ui->checkBox_30->setChecked(false);
                ui->checkBox_31->setCheckState(Qt::Unchecked);
                ui->checkBox_31->setChecked(false);
                ui->checkBox_32->setCheckState(Qt::Unchecked);
                ui->checkBox_32->setChecked(false);
                ui->checkBox_33->setCheckState(Qt::Unchecked);
                ui->checkBox_33->setChecked(false);
                ui->checkBox_34->setCheckState(Qt::Unchecked);
                ui->checkBox_34->setChecked(false);
                ui->checkBox_35->setCheckState(Qt::Unchecked);
                ui->checkBox_35->setChecked(false);
                ui->checkBox_36->setCheckState(Qt::Unchecked);
                ui->checkBox_36->setChecked(false);
                ui->checkBox_37->setCheckState(Qt::Unchecked);
                ui->checkBox_37->setChecked(false);
                ui->checkBox_38->setCheckState(Qt::Unchecked);
                ui->checkBox_38->setChecked(false);
                ui->checkBox_39->setCheckState(Qt::Unchecked);
                ui->checkBox_39->setChecked(false);
                ui->checkBox_40->setCheckState(Qt::Unchecked);
                ui->checkBox_40->setChecked(false);
                ui->checkBox_41->setCheckState(Qt::Unchecked);
                ui->checkBox_41->setChecked(false);
                ui->checkBox_42->setCheckState(Qt::Unchecked);
                ui->checkBox_42->setChecked(false);
                ui->checkBox_43->setCheckState(Qt::Unchecked);
                ui->checkBox_43->setChecked(false);
                salarysum2 = 0;
                forward1 = QString();
                forward2 = QString();
                forward3 = QString();
                forward4 = QString();
                forward5 = QString();
                forward6 = QString();
                forward7 = QString();
                qDebug()<<"salarysum2:"<<salarysum2;
                qDebug()<<"forward1:"<<forward1;
                qDebug()<<"forward2:"<<forward2;
                qDebug()<<"forward3:"<<forward3;
                qDebug()<<"forward4:"<<forward4;
                qDebug()<<"forward5:"<<forward5;
                qDebug()<<"forward6:"<<forward6;
                qDebug()<<"forward7:"<<forward7;
            }
            //cancel后进入下一页面
            else if (check_1&&check_2)
            {
                ui->stackedWidget->setCurrentIndex(5);
                salarysum+=salarysum2;
            }
        }
        else if (check_1&&check_2)
        {
            ui->stackedWidget->setCurrentIndex(5);
            salarysum+=salarysum2;
        }
    });

//中场信息以及选择

    //用左侧TreeWidget显示中场信息
    {
        ui->treeWidget_3->setHeaderLabels(QStringList()<<"中场信息");
        QTreeWidgetItem *GeLeiCiKa = new QTreeWidgetItem(QStringList()<<"格雷茨卡");
        QTreeWidgetItem *RuoRiNiAo = new QTreeWidgetItem(QStringList()<<"若日尼奥");
        QTreeWidgetItem *KeWaQiQi = new QTreeWidgetItem(QStringList()<<"科瓦契奇");
        QTreeWidgetItem *QiYeHe = new QTreeWidgetItem(QStringList()<<"齐耶赫");
        QTreeWidgetItem *PuLiXiQi = new QTreeWidgetItem(QStringList()<<"普利西奇");
        QTreeWidgetItem *MangTe = new QTreeWidgetItem(QStringList()<<"芒特");
        QTreeWidgetItem *DeLaKeSiLe = new QTreeWidgetItem(QStringList()<<"德拉克斯勒");
        QTreeWidgetItem *HaMeiSiLuoDeLiGeSi = new QTreeWidgetItem(QStringList()<<"哈梅斯罗德里格斯");
        QTreeWidgetItem *LaMuSai = new QTreeWidgetItem(QStringList()<<"拉姆塞");
        QTreeWidgetItem *ATuEr = new QTreeWidgetItem(QStringList()<<"阿图尔");
        QTreeWidgetItem *BenTanKuEr = new QTreeWidgetItem(QStringList()<<"本坦库尔");
        QTreeWidgetItem *HaFuCi = new QTreeWidgetItem(QStringList()<<"哈弗茨");
        QTreeWidgetItem *KeLuoSi = new QTreeWidgetItem(QStringList()<<"克罗斯");
        QTreeWidgetItem *MoDeLiQi = new QTreeWidgetItem(QStringList()<<"莫德里奇");
        QTreeWidgetItem *BaSiKeSi = new QTreeWidgetItem(QStringList()<<"巴斯克斯");
        QTreeWidgetItem *KaSaiMiLuo = new QTreeWidgetItem(QStringList()<<"卡塞米罗");
        QTreeWidgetItem *ZhangBoLun = new QTreeWidgetItem(QStringList()<<"张伯伦");
        QTreeWidgetItem *HengDeSen = new QTreeWidgetItem(QStringList()<<"亨德森");
        QTreeWidgetItem *LaiSi = new QTreeWidgetItem(QStringList()<<"赖斯");
        QTreeWidgetItem *BoNaDuoXiErWa = new QTreeWidgetItem(QStringList()<<"伯纳多席尔瓦");
        QTreeWidgetItem *DeBuLaoNei = new QTreeWidgetItem(QStringList()<<"德布劳内");
        QTreeWidgetItem *FuDeng = new QTreeWidgetItem(QStringList()<<"福登");
        QTreeWidgetItem *KuDiNiAo = new QTreeWidgetItem(QStringList()<<"库蒂尼奥");
        QTreeWidgetItem *DeRong = new QTreeWidgetItem(QStringList()<<"德容");
        QTreeWidgetItem *MaDingNeiSi = new QTreeWidgetItem(QStringList()<<"马丁内斯");
        QTreeWidgetItem *TuoLiSuo = new QTreeWidgetItem(QStringList()<<"托利索");
        QTreeWidgetItem *SangQiao = new QTreeWidgetItem(QStringList()<<"桑乔");
        QTreeWidgetItem *WeiLaDi = new QTreeWidgetItem(QStringList()<<"维拉蒂");
        QTreeWidgetItem *AiLiKeSen = new QTreeWidgetItem(QStringList()<<"埃里克森");

        ui->treeWidget_3->addTopLevelItem(GeLeiCiKa);
        ui->treeWidget_3->addTopLevelItem(RuoRiNiAo);
        ui->treeWidget_3->addTopLevelItem(KeWaQiQi);
        ui->treeWidget_3->addTopLevelItem(QiYeHe);
        ui->treeWidget_3->addTopLevelItem(PuLiXiQi);
        ui->treeWidget_3->addTopLevelItem(MangTe);
        ui->treeWidget_3->addTopLevelItem(DeLaKeSiLe);
        ui->treeWidget_3->addTopLevelItem(HaMeiSiLuoDeLiGeSi);
        ui->treeWidget_3->addTopLevelItem(LaMuSai);
        ui->treeWidget_3->addTopLevelItem(ATuEr);
        ui->treeWidget_3->addTopLevelItem(BenTanKuEr);
        ui->treeWidget_3->addTopLevelItem(HaFuCi);
        ui->treeWidget_3->addTopLevelItem(KeLuoSi);
        ui->treeWidget_3->addTopLevelItem(MoDeLiQi);
        ui->treeWidget_3->addTopLevelItem(BaSiKeSi);
        ui->treeWidget_3->addTopLevelItem(KaSaiMiLuo);
        ui->treeWidget_3->addTopLevelItem(ZhangBoLun);
        ui->treeWidget_3->addTopLevelItem(HengDeSen);
        ui->treeWidget_3->addTopLevelItem(LaiSi);
        ui->treeWidget_3->addTopLevelItem(BoNaDuoXiErWa);
        ui->treeWidget_3->addTopLevelItem(DeBuLaoNei);
        ui->treeWidget_3->addTopLevelItem(FuDeng);
        ui->treeWidget_3->addTopLevelItem(KuDiNiAo);
        ui->treeWidget_3->addTopLevelItem(DeRong);
        ui->treeWidget_3->addTopLevelItem(MaDingNeiSi);
        ui->treeWidget_3->addTopLevelItem(TuoLiSuo);
        ui->treeWidget_3->addTopLevelItem(SangQiao);
        ui->treeWidget_3->addTopLevelItem(WeiLaDi);
        ui->treeWidget_3->addTopLevelItem(AiLiKeSen);

        QStringList age44;
        age44 << "年龄:25";
        QStringList rating44;
        rating44 << "能力值:84";
        QStringList position44;
        position44 << "中场/右脚";
        QStringList weeksalary44;
        weeksalary44 << "周薪:15";
        QStringList transferfee44;
        transferfee44 << "转会费:5000";
        QTreeWidgetItem* a44 = new QTreeWidgetItem(age44);
        GeLeiCiKa->addChild(a44);
        QTreeWidgetItem* r44 = new QTreeWidgetItem(rating44);
        GeLeiCiKa->addChild(r44);
        QTreeWidgetItem* p44 = new QTreeWidgetItem(position44);
        GeLeiCiKa->addChild(p44);
        QTreeWidgetItem* w44 = new QTreeWidgetItem(weeksalary44);
        GeLeiCiKa->addChild(w44);
        QTreeWidgetItem* t44 = new QTreeWidgetItem(transferfee44);
        GeLeiCiKa->addChild(t44);

        QStringList age45;
        age45 << "年龄:28";
        QStringList rating45;
        rating45 << "能力值:84";
        QStringList position45;
        position45 << "中场/左右脚";
        QStringList weeksalary45;
        weeksalary45 << "周薪:11";
        QStringList transferfee45;
        transferfee45 << "转会费:5200";
        QTreeWidgetItem* a45 = new QTreeWidgetItem(age45);
        RuoRiNiAo->addChild(a45);
        QTreeWidgetItem* r45 = new QTreeWidgetItem(rating45);
        RuoRiNiAo->addChild(r45);
        QTreeWidgetItem* p45 = new QTreeWidgetItem(position45);
        RuoRiNiAo->addChild(p45);
        QTreeWidgetItem* w45 = new QTreeWidgetItem(weeksalary45);
        RuoRiNiAo->addChild(w45);
        QTreeWidgetItem* t45 = new QTreeWidgetItem(transferfee45);
        RuoRiNiAo->addChild(t45);

        QStringList age46;
        age46 << "年龄:26";
        QStringList rating46;
        rating46 << "能力值:84";
        QStringList position46;
        position46 << "中场/右脚";
        QStringList weeksalary46;
        weeksalary46 << "周薪:11";
        QStringList transferfee46;
        transferfee46 << "转会费:4000";
        QTreeWidgetItem* a46 = new QTreeWidgetItem(age46);
        KeWaQiQi->addChild(a46);
        QTreeWidgetItem* r46 = new QTreeWidgetItem(rating46);
        KeWaQiQi->addChild(r46);
        QTreeWidgetItem* p46 = new QTreeWidgetItem(position46);
        KeWaQiQi->addChild(p46);
        QTreeWidgetItem* w46 = new QTreeWidgetItem(weeksalary46);
        KeWaQiQi->addChild(w46);
        QTreeWidgetItem* t46 = new QTreeWidgetItem(transferfee46);
        KeWaQiQi->addChild(t46);

        QStringList age47;
        age47 << "年龄:27";
        QStringList rating47;
        rating47 << "能力值:86";
        QStringList position47;
        position47 << "中场/左脚";
        QStringList weeksalary47;
        weeksalary47 << "周薪:15";
        QStringList transferfee47;
        transferfee47 << "转会费:4000";
        QTreeWidgetItem* a47 = new QTreeWidgetItem(age47);
        QiYeHe->addChild(a47);
        QTreeWidgetItem* r47 = new QTreeWidgetItem(rating47);
        QiYeHe->addChild(r47);
        QTreeWidgetItem* p47 = new QTreeWidgetItem(position47);
        QiYeHe->addChild(p47);
        QTreeWidgetItem* w47 = new QTreeWidgetItem(weeksalary47);
        QiYeHe->addChild(w47);
        QTreeWidgetItem* t47 = new QTreeWidgetItem(transferfee47);
        QiYeHe->addChild(t47);

        QStringList age48;
        age48 << "年龄:21";
        QStringList rating48;
        rating48 << "能力值:80";
        QStringList position48;
        position48 << "中场/右脚";
        QStringList weeksalary48;
        weeksalary48 << "周薪:14";
        QStringList transferfee48;
        transferfee48 << "转会费:6000";
        QTreeWidgetItem* a48 = new QTreeWidgetItem(age48);
        PuLiXiQi->addChild(a48);
        QTreeWidgetItem* r48 = new QTreeWidgetItem(rating48);
        PuLiXiQi->addChild(r48);
        QTreeWidgetItem* p48 = new QTreeWidgetItem(position48);
        PuLiXiQi->addChild(p48);
        QTreeWidgetItem* w48 = new QTreeWidgetItem(weeksalary48);
        PuLiXiQi->addChild(w48);
        QTreeWidgetItem* t48 = new QTreeWidgetItem(transferfee48);
        PuLiXiQi->addChild(t48);

        QStringList age49;
        age49 << "年龄:21";
        QStringList rating49;
        rating49 << "能力值:79";
        QStringList position49;
        position49 << "中场/右脚";
        QStringList weeksalary49;
        weeksalary49 << "周薪:7";
        QStringList transferfee49;
        transferfee49 << "转会费:4050";
        QTreeWidgetItem* a49 = new QTreeWidgetItem(age49);
        MangTe->addChild(a49);
        QTreeWidgetItem* r49 = new QTreeWidgetItem(rating49);
        MangTe->addChild(r49);
        QTreeWidgetItem* p49 = new QTreeWidgetItem(position49);
        MangTe->addChild(p49);
        QTreeWidgetItem* w49 = new QTreeWidgetItem(weeksalary49);
        MangTe->addChild(w49);
        QTreeWidgetItem* t49 = new QTreeWidgetItem(transferfee49);
        MangTe->addChild(t49);

        QStringList age50;
        age50 << "年龄:26";
        QStringList rating50;
        rating50 << "能力值:82";
        QStringList position50;
        position50 << "中场/右脚";
        QStringList weeksalary50;
        weeksalary50 << "周薪:14";
        QStringList transferfee50;
        transferfee50 << "转会费:2400";
        QTreeWidgetItem* a50 = new QTreeWidgetItem(age50);
        DeLaKeSiLe->addChild(a50);
        QTreeWidgetItem* r50 = new QTreeWidgetItem(rating50);
        DeLaKeSiLe->addChild(r50);
        QTreeWidgetItem* p50 = new QTreeWidgetItem(position50);
        DeLaKeSiLe->addChild(p50);
        QTreeWidgetItem* w50 = new QTreeWidgetItem(weeksalary50);
        DeLaKeSiLe->addChild(w50);
        QTreeWidgetItem* t50 = new QTreeWidgetItem(transferfee50);
        DeLaKeSiLe->addChild(t50);

        QStringList age51;
        age51 << "年龄:29";
        QStringList rating51;
        rating51 << "能力值:85";
        QStringList position51;
        position51 << "中场/左脚";
        QStringList weeksalary51;
        weeksalary51 << "周薪:32";
        QStringList transferfee51;
        transferfee51 << "转会费:3200";
        QTreeWidgetItem* a51 = new QTreeWidgetItem(age51);
        HaMeiSiLuoDeLiGeSi ->addChild(a51);
        QTreeWidgetItem* r51 = new QTreeWidgetItem(rating51);
        HaMeiSiLuoDeLiGeSi->addChild(r51);
        QTreeWidgetItem* p51 = new QTreeWidgetItem(position51);
        HaMeiSiLuoDeLiGeSi->addChild(p51);
        QTreeWidgetItem* w51 = new QTreeWidgetItem(weeksalary51);
        HaMeiSiLuoDeLiGeSi->addChild(w51);
        QTreeWidgetItem* t51 = new QTreeWidgetItem(transferfee51);
        HaMeiSiLuoDeLiGeSi->addChild(t51);

        QStringList age52;
        age52 << "年龄:29";
        QStringList rating52;
        rating52 << "能力值:83";
        QStringList position52;
        position52 << "中场/右脚";
        QStringList weeksalary52;
        weeksalary52 << "周薪:44";
        QStringList transferfee52;
        transferfee52 << "转会费:2200";
        QTreeWidgetItem* a52 = new QTreeWidgetItem(age52);
        LaMuSai->addChild(a52);
        QTreeWidgetItem* r52 = new QTreeWidgetItem(rating52);
        LaMuSai->addChild(r52);
        QTreeWidgetItem* p52 = new QTreeWidgetItem(position52);
        LaMuSai->addChild(p52);
        QTreeWidgetItem* w52 = new QTreeWidgetItem(weeksalary52);
        LaMuSai->addChild(w52);
        QTreeWidgetItem* t52 = new QTreeWidgetItem(transferfee52);
        LaMuSai->addChild(t52);

        QStringList age53;
        age53 << "年龄:24";
        QStringList rating53;
        rating53 << "能力值:85";
        QStringList position53;
        position53 << "中场/右脚";
        QStringList weeksalary53;
        weeksalary53 << "周薪:9";
        QStringList transferfee53;
        transferfee53 << "转会费:5600";
        QTreeWidgetItem* a53= new QTreeWidgetItem(age53);
        ATuEr->addChild(a53);
        QTreeWidgetItem* r53 = new QTreeWidgetItem(rating53);
        ATuEr->addChild(r53);
        QTreeWidgetItem* p53 = new QTreeWidgetItem(position53);
        ATuEr->addChild(p53);
        QTreeWidgetItem* w53 = new QTreeWidgetItem(weeksalary53);
        ATuEr->addChild(w53);
        QTreeWidgetItem* t53 = new QTreeWidgetItem(transferfee53);
        ATuEr->addChild(t53);

        QStringList age54;
        age54 << "年龄:23";
        QStringList rating54;
        rating54 << "能力值:80";
        QStringList position54;
        position54 << "中场/右脚";
        QStringList weeksalary54;
        weeksalary54 << "周薪:9";
        QStringList transferfee54;
        transferfee54 << "转会费:5000";
        QTreeWidgetItem* a54 = new QTreeWidgetItem(age54);
        BenTanKuEr->addChild(a54);
        QTreeWidgetItem* r54 = new QTreeWidgetItem(rating54);
        BenTanKuEr->addChild(r54);
        QTreeWidgetItem* p54 = new QTreeWidgetItem(position54);
        BenTanKuEr->addChild(p54);
        QTreeWidgetItem* w54 = new QTreeWidgetItem(weeksalary54);
        BenTanKuEr->addChild(w54);
        QTreeWidgetItem* t54 = new QTreeWidgetItem(transferfee54);
        BenTanKuEr->addChild(t54);

        QStringList age55;
        age55 << "年龄:21";
        QStringList rating55;
        rating55 << "能力值:84";
        QStringList position55;
        position55 << "中场/左脚";
        QStringList weeksalary55;
        weeksalary55 << "周薪:3";
        QStringList transferfee55;
        transferfee55 << "转会费:8100";
        QTreeWidgetItem* a55 = new QTreeWidgetItem(age55);
        HaFuCi->addChild(a55);
        QTreeWidgetItem* r55 = new QTreeWidgetItem(rating55);
        HaFuCi->addChild(r55);
        QTreeWidgetItem* p55 = new QTreeWidgetItem(position55);
        HaFuCi->addChild(p55);
        QTreeWidgetItem* w55 = new QTreeWidgetItem(weeksalary55);
        HaFuCi->addChild(w55);
        QTreeWidgetItem* t55 = new QTreeWidgetItem(transferfee55);
        HaFuCi->addChild(t55);

        QStringList age56;
        age56 << "年龄:28";
        QStringList rating56;
        rating56 << "能力值:87";
        QStringList position56;
        position56 << "中场/左右脚";
        QStringList weeksalary56;
        weeksalary56 << "周薪:32";
        QStringList transferfee56;
        transferfee56 << "转会费:6000";
        QTreeWidgetItem* a56 = new QTreeWidgetItem(age56);
        AiLiKeSen->addChild(a56);
        QTreeWidgetItem* r56 = new QTreeWidgetItem(rating56);
        AiLiKeSen->addChild(r56);
        QTreeWidgetItem* p56 = new QTreeWidgetItem(position56);
        AiLiKeSen->addChild(p56);
        QTreeWidgetItem* w56 = new QTreeWidgetItem(weeksalary56);
        AiLiKeSen->addChild(w56);
        QTreeWidgetItem* t56 = new QTreeWidgetItem(transferfee56);
        AiLiKeSen->addChild(t56);

        QStringList age57;
        age57 << "年龄:30";
        QStringList rating57;
        rating57 << "能力值:87";
        QStringList position57;
        position57 << "中场/左右脚";
        QStringList weeksalary57;
        weeksalary57 << "周薪:38";
        QStringList transferfee57;
        transferfee57 << "转会费:4800";
        QTreeWidgetItem* a57 = new QTreeWidgetItem(age57);
        KeLuoSi->addChild(a57);
        QTreeWidgetItem* r57 = new QTreeWidgetItem(rating57);
        KeLuoSi->addChild(r57);
        QTreeWidgetItem* p57 = new QTreeWidgetItem(position57);
        KeLuoSi->addChild(p57);
        QTreeWidgetItem* w57 = new QTreeWidgetItem(weeksalary57);
        KeLuoSi->addChild(w57);
        QTreeWidgetItem* t57 = new QTreeWidgetItem(transferfee57);
        KeLuoSi->addChild(t57);

        QStringList age58;
        age58 << "年龄:34";
        QStringList rating58;
        rating58 << "能力值:89";
        QStringList position58;
        position58 << "中场/左右脚";
        QStringList weeksalary58;
        weeksalary58 << "周薪:36";
        QStringList transferfee58;
        transferfee58 << "转会费:1200";
        QTreeWidgetItem* a58 = new QTreeWidgetItem(age58);
        MoDeLiQi->addChild(a58);
        QTreeWidgetItem* r58 = new QTreeWidgetItem(rating58);
        MoDeLiQi->addChild(r58);
        QTreeWidgetItem* p58 = new QTreeWidgetItem(position58);
        MoDeLiQi->addChild(p58);
        QTreeWidgetItem* w58 = new QTreeWidgetItem(weeksalary58);
        MoDeLiQi->addChild(w58);
        QTreeWidgetItem* t58 = new QTreeWidgetItem(transferfee58);
        MoDeLiQi->addChild(t58);

        QStringList age59;
        age59 << "年龄:29";
        QStringList rating59;
        rating59 << "能力值:80";
        QStringList position59;
        position59 << "中场/右脚";
        QStringList weeksalary59;
        weeksalary59 << "周薪:7";
        QStringList transferfee59;
        transferfee59 << "转会费:1600";
        QTreeWidgetItem* a59 = new QTreeWidgetItem(age59);
        BaSiKeSi->addChild(a59);
        QTreeWidgetItem* r59 = new QTreeWidgetItem(rating59);
        BaSiKeSi->addChild(r59);
        QTreeWidgetItem* p59 = new QTreeWidgetItem(position59);
        BaSiKeSi->addChild(p59);
        QTreeWidgetItem* w59 = new QTreeWidgetItem(weeksalary59);
        BaSiKeSi->addChild(w59);
        QTreeWidgetItem* t59 = new QTreeWidgetItem(transferfee59);
        BaSiKeSi->addChild(t59);

        QStringList age60;
        age60<< "年龄:28";
        QStringList rating60;
        rating60 << "能力值:88";
        QStringList position60;
        position60 << "中场/右脚";
        QStringList weeksalary60;
        weeksalary60 << "周薪:19";
        QStringList transferfee60;
        transferfee60 << "转会费:6400";
        QTreeWidgetItem* a60 = new QTreeWidgetItem(age60);
        KaSaiMiLuo->addChild(a60);
        QTreeWidgetItem* r60 = new QTreeWidgetItem(rating60);
        KaSaiMiLuo->addChild(r60);
        QTreeWidgetItem* p60 = new QTreeWidgetItem(position60);
        KaSaiMiLuo->addChild(p60);
        QTreeWidgetItem* w60 = new QTreeWidgetItem(weeksalary60);
        KaSaiMiLuo->addChild(w60);
        QTreeWidgetItem* t60 = new QTreeWidgetItem(transferfee60);
        KaSaiMiLuo->addChild(t60);

        QStringList age61;
        age61 << "年龄:27";
        QStringList rating61;
        rating61 << "能力值:80";
        QStringList position61;
        position61 << "中场/右脚";
        QStringList weeksalary61;
        weeksalary61 << "周薪:12";
        QStringList transferfee61;
        transferfee61 << "转会费:2800";
        QTreeWidgetItem* a61 = new QTreeWidgetItem(age61);
        ZhangBoLun->addChild(a61);
        QTreeWidgetItem* r61 = new QTreeWidgetItem(rating61);
        ZhangBoLun->addChild(r61);
        QTreeWidgetItem* p61 = new QTreeWidgetItem(position61);
        ZhangBoLun->addChild(p61);
        QTreeWidgetItem* w61 = new QTreeWidgetItem(weeksalary61);
        ZhangBoLun->addChild(w61);
        QTreeWidgetItem* t61 = new QTreeWidgetItem(transferfee61);
        ZhangBoLun->addChild(t61);

        QStringList age62;
        age62 << "年龄:30";
        QStringList rating62;
        rating62 << "能力值:85";
        QStringList position62;
        position62 << "中场/右脚";
        QStringList weeksalary62;
        weeksalary62 << "周薪:14";
        QStringList transferfee62;
        transferfee62 << "转会费:2800";
        QTreeWidgetItem* a62 = new QTreeWidgetItem(age62);
        HengDeSen->addChild(a62);
        QTreeWidgetItem* r62 = new QTreeWidgetItem(rating62);
        HengDeSen->addChild(r62);
        QTreeWidgetItem* p62 = new QTreeWidgetItem(position62);
        HengDeSen->addChild(p62);
        QTreeWidgetItem* w62 = new QTreeWidgetItem(weeksalary62);
        HengDeSen->addChild(w62);
        QTreeWidgetItem* t62 = new QTreeWidgetItem(transferfee62);
        HengDeSen->addChild(t62);

        QStringList age63;
        age63 << "年龄:21";
        QStringList rating63;
        rating63 << "能力值:80";
        QStringList position63;
        position63 << "中场/右脚";
        QStringList weeksalary63;
        weeksalary63 << "周薪:6";
        QStringList transferfee63;
        transferfee63 << "转会费:4950";
        QTreeWidgetItem* a63 = new QTreeWidgetItem(age63);
        LaiSi->addChild(a63);
        QTreeWidgetItem* r63 = new QTreeWidgetItem(rating63);
        LaiSi->addChild(r63);
        QTreeWidgetItem* p63 = new QTreeWidgetItem(position63);
        LaiSi->addChild(p63);
        QTreeWidgetItem* w63 = new QTreeWidgetItem(weeksalary63);
        LaiSi->addChild(w63);
        QTreeWidgetItem* t63 = new QTreeWidgetItem(transferfee63);
        LaiSi->addChild(t63);

        QStringList age64;
        age64 << "年龄:26";
        QStringList rating64;
        rating64 << "能力值:87";
        QStringList position64;
        position64 << "中场/左脚";
        QStringList weeksalary64;
        weeksalary64 << "周薪:15";
        QStringList transferfee64;
        transferfee64 << "转会费:8000";
        QTreeWidgetItem* a64 = new QTreeWidgetItem(age64);
        BoNaDuoXiErWa->addChild(a64);
        QTreeWidgetItem* r64 = new QTreeWidgetItem(rating64);
        BoNaDuoXiErWa->addChild(r64);
        QTreeWidgetItem* p64 = new QTreeWidgetItem(position64);
        BoNaDuoXiErWa->addChild(p64);
        QTreeWidgetItem* w64 = new QTreeWidgetItem(weeksalary64);
        BoNaDuoXiErWa->addChild(w64);
        QTreeWidgetItem* t64 = new QTreeWidgetItem(transferfee64);
        BoNaDuoXiErWa->addChild(t64);

        QStringList age65;
        age65 << "年龄:29";
        QStringList rating65;
        rating65 << "能力值:91";
        QStringList position65;
        position65 << "中场/左右脚";
        QStringList weeksalary65;
        weeksalary65 << "周薪:35";
        QStringList transferfee65;
        transferfee65 << "转会费:12000";
        QTreeWidgetItem* a65 = new QTreeWidgetItem(age65);
        DeBuLaoNei->addChild(a65);
        QTreeWidgetItem* r65 = new QTreeWidgetItem(rating65);
        DeBuLaoNei->addChild(r65);
        QTreeWidgetItem* p65 = new QTreeWidgetItem(position65);
        DeBuLaoNei->addChild(p65);
        QTreeWidgetItem* w65 = new QTreeWidgetItem(weeksalary65);
        DeBuLaoNei->addChild(w65);
        QTreeWidgetItem* t65 = new QTreeWidgetItem(transferfee65);
        DeBuLaoNei->addChild(t65);

        QStringList age66;
        age66 << "年龄:20";
        QStringList rating66;
        rating66 << "能力值:77";
        QStringList position66;
        position66 << "中场/左脚";
        QStringList weeksalary66;
        weeksalary66 << "周薪:2";
        QStringList transferfee66;
        transferfee66 << "转会费:4000";
        QTreeWidgetItem* a66 = new QTreeWidgetItem(age66);
        FuDeng->addChild(a66);
        QTreeWidgetItem* r66 = new QTreeWidgetItem(rating66);
        FuDeng->addChild(r66);
        QTreeWidgetItem* p66 = new QTreeWidgetItem(position66);
        FuDeng->addChild(p66);
        QTreeWidgetItem* w66 = new QTreeWidgetItem(weeksalary66);
        FuDeng->addChild(w66);
        QTreeWidgetItem* t66 = new QTreeWidgetItem(transferfee66);
        FuDeng->addChild(t66);

        QStringList age67;
        age67 << "年龄:28";
        QStringList rating67;
        rating67 << "能力值:85";
        QStringList position67;
        position67 << "中场/右脚";
        QStringList weeksalary67;
        weeksalary67 << "周薪:47";
        QStringList transferfee67;
        transferfee67 << "转会费:5600";
        QTreeWidgetItem* a67 = new QTreeWidgetItem(age67);
        KuDiNiAo->addChild(a67);
        QTreeWidgetItem* r67 = new QTreeWidgetItem(rating67);
        KuDiNiAo->addChild(r67);
        QTreeWidgetItem* p67 = new QTreeWidgetItem(position67);
        KuDiNiAo->addChild(p67);
        QTreeWidgetItem* w67 = new QTreeWidgetItem(weeksalary67);
        KuDiNiAo->addChild(w67);
        QTreeWidgetItem* t67 = new QTreeWidgetItem(transferfee67);
        KuDiNiAo->addChild(t67);

        QStringList age68;
        age68 << "年龄:23";
        QStringList rating68;
        rating68 << "能力值:86";
        QStringList position68;
        position68 << "中场/右脚";
        QStringList weeksalary68;
        weeksalary68 << "周薪:40";
        QStringList transferfee68;
        transferfee68 << "转会费:7200";
        QTreeWidgetItem* a68 = new QTreeWidgetItem(age68);
        DeRong->addChild(a68);
        QTreeWidgetItem* r68 = new QTreeWidgetItem(rating68);
        DeRong->addChild(r68);
        QTreeWidgetItem* p68 = new QTreeWidgetItem(position68);
        DeRong->addChild(p68);
        QTreeWidgetItem* w68 = new QTreeWidgetItem(weeksalary68);
        DeRong->addChild(w68);
        QTreeWidgetItem* t68 = new QTreeWidgetItem(transferfee68);
        DeRong->addChild(t68);

        QStringList age69;
        age69 << "年龄:32";
        QStringList rating69;
        rating69 << "能力值:82";
        QStringList position69;
        position69 << "中场/右脚";
        QStringList weeksalary69;
        weeksalary69 << "周薪:11";
        QStringList transferfee69;
        transferfee69 << "转会费:1300";
        QTreeWidgetItem* a69 = new QTreeWidgetItem(age69);
        MaDingNeiSi->addChild(a69);
        QTreeWidgetItem* r69 = new QTreeWidgetItem(rating69);
        MaDingNeiSi->addChild(r69);
        QTreeWidgetItem* p69 = new QTreeWidgetItem(position69);
        MaDingNeiSi->addChild(p69);
        QTreeWidgetItem* w69 = new QTreeWidgetItem(weeksalary69);
        MaDingNeiSi->addChild(w69);
        QTreeWidgetItem* t69 = new QTreeWidgetItem(transferfee69);
        MaDingNeiSi->addChild(t69);

        QStringList age70;
        age70 << "年龄:26";
        QStringList rating70;
        rating70 << "能力值:82";
        QStringList position70;
        position70 << "中场/右脚";
        QStringList weeksalary70;
        weeksalary70 << "周薪:13";
        QStringList transferfee70;
        transferfee70 << "转会费:2550";
        QTreeWidgetItem* a70 = new QTreeWidgetItem(age70);
        TuoLiSuo->addChild(a70);
        QTreeWidgetItem* r70 = new QTreeWidgetItem(rating70);
        TuoLiSuo->addChild(r70);
        QTreeWidgetItem* p70 = new QTreeWidgetItem(position70);
        TuoLiSuo->addChild(p70);
        QTreeWidgetItem* w70 = new QTreeWidgetItem(weeksalary70);
        TuoLiSuo->addChild(w70);
        QTreeWidgetItem* t70 = new QTreeWidgetItem(transferfee70);
        TuoLiSuo->addChild(t70);

        QStringList age71;
        age71 << "年龄:20";
        QStringList rating71;
        rating71 << "能力值:86";
        QStringList position71;
        position71 << "中场/右脚";
        QStringList weeksalary71;
        weeksalary71 << "周薪:4";
        QStringList transferfee71;
        transferfee71 << "转会费:1170";
        QTreeWidgetItem* a71 = new QTreeWidgetItem(age71);
        SangQiao->addChild(a71);
        QTreeWidgetItem* r71 = new QTreeWidgetItem(rating71);
        SangQiao->addChild(r71);
        QTreeWidgetItem* p71 = new QTreeWidgetItem(position71);
        SangQiao->addChild(p71);
        QTreeWidgetItem* w71 = new QTreeWidgetItem(weeksalary71);
        SangQiao->addChild(w71);
        QTreeWidgetItem* t71 = new QTreeWidgetItem(transferfee71);
        SangQiao->addChild(t71);

        QStringList age72;
        age72 << "年龄:27";
        QStringList rating72;
        rating72 << "能力值:87";
        QStringList position72;
        position72 << "中场/右脚";
        QStringList weeksalary72;
        weeksalary72 << "周薪:14";
        QStringList transferfee72;
        transferfee72 << "转会费:6000";
        QTreeWidgetItem* a72 = new QTreeWidgetItem(age72);
        WeiLaDi->addChild(a72);
        QTreeWidgetItem* r72 = new QTreeWidgetItem(rating72);
        WeiLaDi->addChild(r72);
        QTreeWidgetItem* p72 = new QTreeWidgetItem(position72);
        WeiLaDi->addChild(p72);
        QTreeWidgetItem* w72 = new QTreeWidgetItem(weeksalary72);
        WeiLaDi->addChild(w72);
        QTreeWidgetItem* t72 = new QTreeWidgetItem(transferfee72);
        WeiLaDi->addChild(t72);
    }
    //“选择中场”按钮
    connect(ui->ChooseMidFieldBtn,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        check_1 = true;
        check_2 = true;
        if (ui->checkBox_44->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("格雷茨卡");
            else if (midField2==QString())
                midField2=QString("格雷茨卡");
            else if(midField3==QString())
                midField3=QString("格雷茨卡");
            else if(midField4==QString())
                midField4=QString("格雷茨卡");
            else if(midField5==QString())
                midField5=QString("格雷茨卡");
            else if(midField6==QString())
                midField6=QString("格雷茨卡");
            else if(midField7==QString())
                midField7=QString("格雷茨卡");
        }
        if (ui->checkBox_45->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("若日尼奥");
            else if (midField2==QString())
                midField2=QString("若日尼奥");
            else if(midField3==QString())
                midField3=QString("若日尼奥");
            else if(midField4==QString())
                midField4=QString("若日尼奥");
            else if(midField5==QString())
                midField5=QString("若日尼奥");
            else if(midField6==QString())
                midField6=QString("若日尼奥");
            else if(midField7==QString())
                midField7=QString("若日尼奥");
        }
        if (ui->checkBox_46->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("科瓦契奇");
            else if (midField2==QString())
                midField2=QString("科瓦契奇");
            else if(midField3==QString())
                midField3=QString("科瓦契奇");
            else if(midField4==QString())
                midField4=QString("科瓦契奇");
            else if(midField5==QString())
                midField5=QString("科瓦契奇");
            else if(midField6==QString())
                midField6=QString("科瓦契奇");
            else if(midField7==QString())
                midField7=QString("科瓦契奇");
        }
        if (ui->checkBox_47->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("齐耶赫");
            else if (midField2==QString())
                midField2=QString("齐耶赫");
            else if(midField3==QString())
                midField3=QString("齐耶赫");
            else if(midField4==QString())
                midField4=QString("齐耶赫");
            else if(midField5==QString())
                midField5=QString("齐耶赫");
            else if(midField6==QString())
                midField6=QString("齐耶赫");
            else if(midField7==QString())
                midField7=QString("齐耶赫");
        }
        if (ui->checkBox_48->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("普利西奇");
            else if (midField2==QString())
                midField2=QString("普利西奇");
            else if(midField3==QString())
                midField3=QString("普利西奇");
            else if(midField4==QString())
                midField4=QString("普利西奇");
            else if(midField5==QString())
                midField5=QString("普利西奇");
            else if(midField6==QString())
                midField6=QString("普利西奇");
            else if(midField7==QString())
                midField7=QString("普利西奇");
        }
        if (ui->checkBox_49->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("芒特");
            else if (midField2==QString())
                midField2=QString("芒特");
            else if(midField3==QString())
                midField3=QString("芒特");
            else if(midField4==QString())
                midField4=QString("芒特");
            else if(midField5==QString())
                midField5=QString("芒特");
            else if(midField6==QString())
                midField6=QString("芒特");
            else if(midField7==QString())
                midField7=QString("芒特");
        }
        if (ui->checkBox_50->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("德拉克斯勒");
            else if (midField2==QString())
                midField2=QString("德拉克斯勒");
            else if(midField3==QString())
                midField3=QString("德拉克斯勒");
            else if(midField4==QString())
                midField4=QString("德拉克斯勒");
            else if(midField5==QString())
                midField5=QString("德拉克斯勒");
            else if(midField6==QString())
                midField6=QString("德拉克斯勒");
            else if(midField7==QString())
                midField7=QString("德拉克斯勒");
        }
        if (ui->checkBox_51->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("哈梅斯罗德里格斯");
            else if (midField2==QString())
                midField2=QString("哈梅斯罗德里格斯");
            else if(midField3==QString())
                midField3=QString("哈梅斯罗德里格斯");
            else if(midField4==QString())
                midField4=QString("哈梅斯罗德里格斯");
            else if(midField5==QString())
                midField5=QString("哈梅斯罗德里格斯");
            else if(midField6==QString())
                midField6=QString("哈梅斯罗德里格斯");
            else if(midField7==QString())
                midField7=QString("哈梅斯罗德里格斯");
        }
        if (ui->checkBox_52->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("拉姆塞");
            else if (midField2==QString())
                midField2=QString("拉姆塞");
            else if(midField3==QString())
                midField3=QString("拉姆塞");
            else if(midField4==QString())
                midField4=QString("拉姆塞");
            else if(midField5==QString())
                midField5=QString("拉姆塞");
            else if(midField6==QString())
                midField6=QString("拉姆塞");
            else if(midField7==QString())
                midField7=QString("拉姆塞");
        }
        if (ui->checkBox_53->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("阿图尔");
            else if (midField2==QString())
                midField2=QString("阿图尔");
            else if(midField3==QString())
                midField3=QString("阿图尔");
            else if(midField4==QString())
                midField4=QString("阿图尔");
            else if(midField5==QString())
                midField5=QString("阿图尔");
            else if(midField6==QString())
                midField6=QString("阿图尔");
            else if(midField7==QString())
                midField7=QString("阿图尔");
        }
        if (ui->checkBox_54->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("本坦库尔");
            else if (midField2==QString())
                midField2=QString("本坦库尔");
            else if(midField3==QString())
                midField3=QString("本坦库尔");
            else if(midField4==QString())
                midField4=QString("本坦库尔");
            else if(midField5==QString())
                midField5=QString("本坦库尔");
            else if(midField6==QString())
                midField6=QString("本坦库尔");
            else if(midField7==QString())
                midField7=QString("本坦库尔");
        }
        if (ui->checkBox_55->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("哈弗茨");
            else if (midField2==QString())
                midField2=QString("哈弗茨");
            else if(midField3==QString())
                midField3=QString("哈弗茨");
            else if(midField4==QString())
                midField4=QString("哈弗茨");
            else if(midField5==QString())
                midField5=QString("哈弗茨");
            else if(midField6==QString())
                midField6=QString("哈弗茨");
            else if(midField7==QString())
                midField7=QString("哈弗茨");
        }
        if (ui->checkBox_56->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("克罗斯");
            else if (midField2==QString())
                midField2=QString("克罗斯");
            else if(midField3==QString())
                midField3=QString("克罗斯");
            else if(midField4==QString())
                midField4=QString("克罗斯");
            else if(midField5==QString())
                midField5=QString("克罗斯");
            else if(midField6==QString())
                midField6=QString("克罗斯");
            else if(midField7==QString())
                midField7=QString("克罗斯");
        }
        if (ui->checkBox_57->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("莫德里奇");
            else if (midField2==QString())
                midField2=QString("莫德里奇");
            else if(midField3==QString())
                midField3=QString("莫德里奇");
            else if(midField4==QString())
                midField4=QString("莫德里奇");
            else if(midField5==QString())
                midField5=QString("莫德里奇");
            else if(midField6==QString())
                midField6=QString("莫德里奇");
            else if(midField7==QString())
                midField7=QString("莫德里奇");
        }
        if (ui->checkBox_58->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("巴斯克斯");
            else if (midField2==QString())
                midField2=QString("巴斯克斯");
            else if(midField3==QString())
                midField3=QString("巴斯克斯");
            else if(midField4==QString())
                midField4=QString("巴斯克斯");
            else if(midField5==QString())
                midField5=QString("巴斯克斯");
            else if(midField6==QString())
                midField6=QString("巴斯克斯");
            else if(midField7==QString())
                midField7=QString("巴斯克斯");
        }
        if (ui->checkBox_59->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("卡塞米罗");
            else if (midField2==QString())
                midField2=QString("卡塞米罗");
            else if(midField3==QString())
                midField3=QString("卡塞米罗");
            else if(midField4==QString())
                midField4=QString("卡塞米罗");
            else if(midField5==QString())
                midField5=QString("卡塞米罗");
            else if(midField6==QString())
                midField6=QString("卡塞米罗");
            else if(midField7==QString())
                midField7=QString("卡塞米罗");
        }
        if (ui->checkBox_60->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("张伯伦");
            else if (midField2==QString())
                midField2=QString("张伯伦");
            else if(midField3==QString())
                midField3=QString("张伯伦");
            else if(midField4==QString())
                midField4=QString("张伯伦");
            else if(midField5==QString())
                midField5=QString("张伯伦");
            else if(midField6==QString())
                midField6=QString("张伯伦");
            else if(midField7==QString())
                midField7=QString("张伯伦");
        }
        if (ui->checkBox_61->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("亨德森");
            else if (midField2==QString())
                midField2=QString("亨德森");
            else if(midField3==QString())
                midField3=QString("亨德森");
            else if(midField4==QString())
                midField4=QString("亨德森");
            else if(midField5==QString())
                midField5=QString("亨德森");
            else if(midField6==QString())
                midField6=QString("亨德森");
            else if(midField7==QString())
                midField7=QString("亨德森");
        }
        if (ui->checkBox_62->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("赖斯");
            else if (midField2==QString())
                midField2=QString("赖斯");
            else if(midField3==QString())
                midField3=QString("赖斯");
            else if(midField4==QString())
                midField4=QString("赖斯");
            else if(midField5==QString())
                midField5=QString("赖斯");
            else if(midField6==QString())
                midField6=QString("赖斯");
            else if(midField7==QString())
                midField7=QString("赖斯");
        }
        if (ui->checkBox_63->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("伯纳多席尔瓦");
            else if (midField2==QString())
                midField2=QString("伯纳多席尔瓦");
            else if(midField3==QString())
                midField3=QString("伯纳多席尔瓦");
            else if(midField4==QString())
                midField4=QString("伯纳多席尔瓦");
            else if(midField5==QString())
                midField5=QString("伯纳多席尔瓦");
            else if(midField6==QString())
                midField6=QString("伯纳多席尔瓦");
            else if(midField7==QString())
                midField7=QString("伯纳多席尔瓦");
        }
        if (ui->checkBox_64->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("德布劳内");
            else if (midField2==QString())
                midField2=QString("德布劳内");
            else if(midField3==QString())
                midField3=QString("德布劳内");
            else if(midField4==QString())
                midField4=QString("德布劳内");
            else if(midField5==QString())
                midField5=QString("德布劳内");
            else if(midField6==QString())
                midField6=QString("德布劳内");
            else if(midField7==QString())
                midField7=QString("德布劳内");
        }
        if (ui->checkBox_65->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("福登");
            else if (midField2==QString())
                midField2=QString("福登");
            else if(midField3==QString())
                midField3=QString("福登");
            else if(midField4==QString())
                midField4=QString("福登");
            else if(midField5==QString())
                midField5=QString("福登");
            else if(midField6==QString())
                midField6=QString("福登");
            else if(midField7==QString())
                midField7=QString("福登");
        }
        if (ui->checkBox_66->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("库蒂尼奥");
            else if (midField2==QString())
                midField2=QString("库蒂尼奥");
            else if(midField3==QString())
                midField3=QString("库蒂尼奥");
            else if(midField4==QString())
                midField4=QString("库蒂尼奥");
            else if(midField5==QString())
                midField5=QString("库蒂尼奥");
            else if(midField6==QString())
                midField6=QString("库蒂尼奥");
            else if(midField7==QString())
                midField7=QString("库蒂尼奥");
        }
        if (ui->checkBox_67->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("德容");
            else if (midField2==QString())
                midField2=QString("德容");
            else if(midField3==QString())
                midField3=QString("德容");
            else if(midField4==QString())
                midField4=QString("德容");
            else if(midField5==QString())
                midField5=QString("德容");
            else if(midField6==QString())
                midField6=QString("德容");
            else if(midField7==QString())
                midField7=QString("德容");
        }
        if (ui->checkBox_68->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("马丁内斯");
            else if (midField2==QString())
                midField2=QString("马丁内斯");
            else if(midField3==QString())
                midField3=QString("马丁内斯");
            else if(midField4==QString())
                midField4=QString("马丁内斯");
            else if(midField5==QString())
                midField5=QString("马丁内斯");
            else if(midField6==QString())
                midField6=QString("马丁内斯");
            else if(midField7==QString())
                midField7=QString("马丁内斯");
        }
        if (ui->checkBox_69->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("托利索");
            else if (midField2==QString())
                midField2=QString("托利索");
            else if(midField3==QString())
                midField3=QString("托利索");
            else if(midField4==QString())
                midField4=QString("托利索");
            else if(midField5==QString())
                midField5=QString("托利索");
            else if(midField6==QString())
                midField6=QString("托利索");
            else if(midField7==QString())
                midField7=QString("托利索");
        }
        if (ui->checkBox_70->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("桑乔");
            else if (midField2==QString())
                midField2=QString("桑乔");
            else if(midField3==QString())
                midField3=QString("桑乔");
            else if(midField4==QString())
                midField4=QString("桑乔");
            else if(midField5==QString())
                midField5=QString("桑乔");
            else if(midField6==QString())
                midField6=QString("桑乔");
            else if(midField7==QString())
                midField7=QString("桑乔");
        }
        if (ui->checkBox_71->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("维拉蒂");
            else if (midField2==QString())
                midField2=QString("维拉蒂");
            else if(midField3==QString())
                midField3=QString("维拉蒂");
            else if(midField4==QString())
                midField4=QString("维拉蒂");
            else if(midField5==QString())
                midField5=QString("维拉蒂");
            else if(midField6==QString())
                midField6=QString("维拉蒂");
            else if(midField7==QString())
                midField7=QString("维拉蒂");
        }
        if (ui->checkBox_72->isChecked())
        {
            ckBoxSum++;
            if (midField1==QString())
                midField1=QString("埃里克森");
            else if (midField2==QString())
                midField2=QString("埃里克森");
            else if(midField3==QString())
                midField3=QString("埃里克森");
            else if(midField4==QString())
                midField4=QString("埃里克森");
            else if(midField5==QString())
                midField5=QString("埃里克森");
            else if(midField6==QString())
                midField6=QString("埃里克森");
            else if(midField7==QString())
                midField7=QString("埃里克森");
        }
        qDebug()<<"midField1:"<<midField1;
        qDebug()<<"midField2:"<<midField2;
        qDebug()<<"midField3:"<<midField3;
        qDebug()<<"midField4:"<<midField4;
        qDebug()<<"midField5:"<<midField5;
        qDebug()<<"midField6:"<<midField6;
        qDebug()<<"midField7:"<<midField7;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        salarysum3 = 0;
        for (int i=0;i<100;i++)
        {
            if (midField1 == players[i].name)
                salarysum3 += players[i].weeksalary;
            else if (midField2 == players[i].name)
                salarysum3 += players[i].weeksalary;
            else if (midField3 == players[i].name)
                salarysum3 += players[i].weeksalary;
            else if (midField4 == players[i].name)
                salarysum3 += players[i].weeksalary;
            else if (midField5 == players[i].name)
                salarysum3 += players[i].weeksalary;
            else if (midField6 == players[i].name)
                salarysum3 += players[i].weeksalary;
            else if (midField7 == players[i].name)
                salarysum3 += players[i].weeksalary;
            else
                continue;
        }
        qDebug()<<"salarysum3:"<<salarysum3;

        //如果选择的中场数目超过7个，弹窗警告
        if (ckBoxSum > 7)
        {
            check_1 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择七名中场\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_44->setCheckState(Qt::Unchecked);
                ui->checkBox_44->setChecked(false);
                ui->checkBox_45->setCheckState(Qt::Unchecked);
                ui->checkBox_45->setChecked(false);
                ui->checkBox_46->setCheckState(Qt::Unchecked);
                ui->checkBox_46->setChecked(false);
                ui->checkBox_47->setCheckState(Qt::Unchecked);
                ui->checkBox_47->setChecked(false);
                ui->checkBox_48->setCheckState(Qt::Unchecked);
                ui->checkBox_48->setChecked(false);
                ui->checkBox_49->setCheckState(Qt::Unchecked);
                ui->checkBox_49->setChecked(false);
                ui->checkBox_50->setCheckState(Qt::Unchecked);
                ui->checkBox_50->setChecked(false);
                ui->checkBox_51->setCheckState(Qt::Unchecked);
                ui->checkBox_51->setChecked(false);
                ui->checkBox_52->setCheckState(Qt::Unchecked);
                ui->checkBox_52->setChecked(false);
                ui->checkBox_53->setCheckState(Qt::Unchecked);
                ui->checkBox_53->setChecked(false);
                ui->checkBox_54->setCheckState(Qt::Unchecked);
                ui->checkBox_54->setChecked(false);
                ui->checkBox_55->setCheckState(Qt::Unchecked);
                ui->checkBox_55->setChecked(false);
                ui->checkBox_56->setCheckState(Qt::Unchecked);
                ui->checkBox_56->setChecked(false);
                ui->checkBox_57->setCheckState(Qt::Unchecked);
                ui->checkBox_57->setChecked(false);
                ui->checkBox_58->setCheckState(Qt::Unchecked);
                ui->checkBox_58->setChecked(false);
                ui->checkBox_59->setCheckState(Qt::Unchecked);
                ui->checkBox_59->setChecked(false);
                ui->checkBox_60->setCheckState(Qt::Unchecked);
                ui->checkBox_60->setChecked(false);
                ui->checkBox_61->setCheckState(Qt::Unchecked);
                ui->checkBox_61->setChecked(false);
                ui->checkBox_62->setCheckState(Qt::Unchecked);
                ui->checkBox_62->setChecked(false);
                ui->checkBox_63->setCheckState(Qt::Unchecked);
                ui->checkBox_63->setChecked(false);
                ui->checkBox_64->setCheckState(Qt::Unchecked);
                ui->checkBox_64->setChecked(false);
                ui->checkBox_65->setCheckState(Qt::Unchecked);
                ui->checkBox_65->setChecked(false);
                ui->checkBox_66->setCheckState(Qt::Unchecked);
                ui->checkBox_66->setChecked(false);
                ui->checkBox_67->setCheckState(Qt::Unchecked);
                ui->checkBox_67->setChecked(false);
                ui->checkBox_68->setCheckState(Qt::Unchecked);
                ui->checkBox_68->setChecked(false);
                ui->checkBox_69->setCheckState(Qt::Unchecked);
                ui->checkBox_69->setChecked(false);
                ui->checkBox_70->setCheckState(Qt::Unchecked);
                ui->checkBox_70->setChecked(false);
                ui->checkBox_71->setCheckState(Qt::Unchecked);
                ui->checkBox_71->setChecked(false);
                ui->checkBox_72->setCheckState(Qt::Unchecked);
                ui->checkBox_72->setChecked(false);
                salarysum3 = 0;
                midField1 = QString();
                midField2 = QString();
                midField3 = QString();
                midField4 = QString();
                midField5 = QString();
                midField6 = QString();
                midField7 = QString();
                qDebug()<<"midField1:"<<midField1;
                qDebug()<<"midField2:"<<midField2;
                qDebug()<<"midField3:"<<midField3;
                qDebug()<<"midField4:"<<midField4;
                qDebug()<<"midField5:"<<midField5;
                qDebug()<<"midField6:"<<midField6;
                qDebug()<<"midField7:"<<midField7;
                qDebug()<<"salarysum3:"<<salarysum3;
            }
        }

        //如果选择的中场数目不足7个，弹窗警告
        if (ckBoxSum < 7)
        {
            check_2 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的中场数目不足七个\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_44->setCheckState(Qt::Unchecked);
                ui->checkBox_44->setChecked(false);
                ui->checkBox_45->setCheckState(Qt::Unchecked);
                ui->checkBox_45->setChecked(false);
                ui->checkBox_46->setCheckState(Qt::Unchecked);
                ui->checkBox_46->setChecked(false);
                ui->checkBox_47->setCheckState(Qt::Unchecked);
                ui->checkBox_47->setChecked(false);
                ui->checkBox_48->setCheckState(Qt::Unchecked);
                ui->checkBox_48->setChecked(false);
                ui->checkBox_49->setCheckState(Qt::Unchecked);
                ui->checkBox_49->setChecked(false);
                ui->checkBox_50->setCheckState(Qt::Unchecked);
                ui->checkBox_50->setChecked(false);
                ui->checkBox_51->setCheckState(Qt::Unchecked);
                ui->checkBox_51->setChecked(false);
                ui->checkBox_52->setCheckState(Qt::Unchecked);
                ui->checkBox_52->setChecked(false);
                ui->checkBox_53->setCheckState(Qt::Unchecked);
                ui->checkBox_53->setChecked(false);
                ui->checkBox_54->setCheckState(Qt::Unchecked);
                ui->checkBox_54->setChecked(false);
                ui->checkBox_55->setCheckState(Qt::Unchecked);
                ui->checkBox_55->setChecked(false);
                ui->checkBox_56->setCheckState(Qt::Unchecked);
                ui->checkBox_56->setChecked(false);
                ui->checkBox_57->setCheckState(Qt::Unchecked);
                ui->checkBox_57->setChecked(false);
                ui->checkBox_58->setCheckState(Qt::Unchecked);
                ui->checkBox_58->setChecked(false);
                ui->checkBox_59->setCheckState(Qt::Unchecked);
                ui->checkBox_59->setChecked(false);
                ui->checkBox_60->setCheckState(Qt::Unchecked);
                ui->checkBox_60->setChecked(false);
                ui->checkBox_61->setCheckState(Qt::Unchecked);
                ui->checkBox_61->setChecked(false);
                ui->checkBox_62->setCheckState(Qt::Unchecked);
                ui->checkBox_62->setChecked(false);
                ui->checkBox_63->setCheckState(Qt::Unchecked);
                ui->checkBox_63->setChecked(false);
                ui->checkBox_64->setCheckState(Qt::Unchecked);
                ui->checkBox_64->setChecked(false);
                ui->checkBox_65->setCheckState(Qt::Unchecked);
                ui->checkBox_65->setChecked(false);
                ui->checkBox_66->setCheckState(Qt::Unchecked);
                ui->checkBox_66->setChecked(false);
                ui->checkBox_67->setCheckState(Qt::Unchecked);
                ui->checkBox_67->setChecked(false);
                ui->checkBox_68->setCheckState(Qt::Unchecked);
                ui->checkBox_68->setChecked(false);
                ui->checkBox_69->setCheckState(Qt::Unchecked);
                ui->checkBox_69->setChecked(false);
                ui->checkBox_70->setCheckState(Qt::Unchecked);
                ui->checkBox_70->setChecked(false);
                ui->checkBox_71->setCheckState(Qt::Unchecked);
                ui->checkBox_71->setChecked(false);
                ui->checkBox_72->setCheckState(Qt::Unchecked);
                ui->checkBox_72->setChecked(false);
                salarysum3 = 0;
                midField1 = QString();
                midField2 = QString();
                midField3 = QString();
                midField4 = QString();
                midField5 = QString();
                midField6 = QString();
                midField7 = QString();
                qDebug()<<"midField1:"<<midField1;
                qDebug()<<"midField2:"<<midField2;
                qDebug()<<"midField3:"<<midField3;
                qDebug()<<"midField4:"<<midField4;
                qDebug()<<"midField5:"<<midField5;
                qDebug()<<"midField6:"<<midField6;
                qDebug()<<"midField7:"<<midField7;
                qDebug()<<"salarysum3:"<<salarysum3;
            }
        }

        //如果所选中场的周薪总和大于等于380，弹窗询问
        if (salarysum3 >= 380)
        {
            int a = QMessageBox::question(this,QString("注意"),QString("过高的中场薪资将会限制同队中其他球员的选择\n是否重新选择"),QMessageBox::Cancel|QMessageBox::Ok);
            //ok后重置并且重新选择
            if(a == QMessageBox::Ok)
            {
                ui->checkBox_44->setCheckState(Qt::Unchecked);
                ui->checkBox_44->setChecked(false);
                ui->checkBox_45->setCheckState(Qt::Unchecked);
                ui->checkBox_45->setChecked(false);
                ui->checkBox_46->setCheckState(Qt::Unchecked);
                ui->checkBox_46->setChecked(false);
                ui->checkBox_47->setCheckState(Qt::Unchecked);
                ui->checkBox_47->setChecked(false);
                ui->checkBox_48->setCheckState(Qt::Unchecked);
                ui->checkBox_48->setChecked(false);
                ui->checkBox_49->setCheckState(Qt::Unchecked);
                ui->checkBox_49->setChecked(false);
                ui->checkBox_50->setCheckState(Qt::Unchecked);
                ui->checkBox_50->setChecked(false);
                ui->checkBox_51->setCheckState(Qt::Unchecked);
                ui->checkBox_51->setChecked(false);
                ui->checkBox_52->setCheckState(Qt::Unchecked);
                ui->checkBox_52->setChecked(false);
                ui->checkBox_53->setCheckState(Qt::Unchecked);
                ui->checkBox_53->setChecked(false);
                ui->checkBox_54->setCheckState(Qt::Unchecked);
                ui->checkBox_54->setChecked(false);
                ui->checkBox_55->setCheckState(Qt::Unchecked);
                ui->checkBox_55->setChecked(false);
                ui->checkBox_56->setCheckState(Qt::Unchecked);
                ui->checkBox_56->setChecked(false);
                ui->checkBox_57->setCheckState(Qt::Unchecked);
                ui->checkBox_57->setChecked(false);
                ui->checkBox_58->setCheckState(Qt::Unchecked);
                ui->checkBox_58->setChecked(false);
                ui->checkBox_59->setCheckState(Qt::Unchecked);
                ui->checkBox_59->setChecked(false);
                ui->checkBox_60->setCheckState(Qt::Unchecked);
                ui->checkBox_60->setChecked(false);
                ui->checkBox_61->setCheckState(Qt::Unchecked);
                ui->checkBox_61->setChecked(false);
                ui->checkBox_62->setCheckState(Qt::Unchecked);
                ui->checkBox_62->setChecked(false);
                ui->checkBox_63->setCheckState(Qt::Unchecked);
                ui->checkBox_63->setChecked(false);
                ui->checkBox_64->setCheckState(Qt::Unchecked);
                ui->checkBox_64->setChecked(false);
                ui->checkBox_65->setCheckState(Qt::Unchecked);
                ui->checkBox_65->setChecked(false);
                ui->checkBox_66->setCheckState(Qt::Unchecked);
                ui->checkBox_66->setChecked(false);
                ui->checkBox_67->setCheckState(Qt::Unchecked);
                ui->checkBox_67->setChecked(false);
                ui->checkBox_68->setCheckState(Qt::Unchecked);
                ui->checkBox_68->setChecked(false);
                ui->checkBox_69->setCheckState(Qt::Unchecked);
                ui->checkBox_69->setChecked(false);
                ui->checkBox_70->setCheckState(Qt::Unchecked);
                ui->checkBox_70->setChecked(false);
                ui->checkBox_71->setCheckState(Qt::Unchecked);
                ui->checkBox_71->setChecked(false);
                ui->checkBox_72->setCheckState(Qt::Unchecked);
                ui->checkBox_72->setChecked(false);
                salarysum3 = 0;
                midField1 = QString();
                midField2 = QString();
                midField3 = QString();
                midField4 = QString();
                midField5 = QString();
                midField6 = QString();
                midField7 = QString();
                qDebug()<<"midField1:"<<midField1;
                qDebug()<<"midField2:"<<midField2;
                qDebug()<<"midField3:"<<midField3;
                qDebug()<<"midField4:"<<midField4;
                qDebug()<<"midField5:"<<midField5;
                qDebug()<<"midField6:"<<midField6;
                qDebug()<<"midField7:"<<midField7;
                qDebug()<<"salarysum3:"<<salarysum3;
            }
            //cancel后进入下一页面
            else if (check_1&&check_2)
            {
                ui->stackedWidget->setCurrentIndex(6);
                salarysum+=salarysum3;
            }
        }
        else if (check_1&&check_2)
        {
            ui->stackedWidget->setCurrentIndex(6);
            salarysum+=salarysum3;
        }
    });

//后卫信息以及选择

    //用左侧TreeWidget显示后卫信息
    {
        ui->treeWidget_4->setHeaderLabels(QStringList()<<"后卫信息");

        QTreeWidgetItem *AiErNanDeSi = new QTreeWidgetItem(QStringList()<<"埃尔南德斯");
        QTreeWidgetItem *JiMiXi = new QTreeWidgetItem(QStringList()<<"基米希");
        QTreeWidgetItem *ASiPiLiKuiTa = new QTreeWidgetItem(QStringList()<<"阿斯皮利奎塔");
        QTreeWidgetItem *QiErWeiEr = new QTreeWidgetItem(QStringList()<<"奇尔韦尔");
        QTreeWidgetItem *JinPengBei = new QTreeWidgetItem(QStringList()<<"金彭贝");
        QTreeWidgetItem *MaSaiLuo = new QTreeWidgetItem(QStringList()<<"马塞洛");
        QTreeWidgetItem *LaMoSi = new QTreeWidgetItem(QStringList()<<"拉莫斯");
        QTreeWidgetItem *WaLaNei = new QTreeWidgetItem(QStringList()<<"瓦拉内");
        QTreeWidgetItem *KaWaHaEr = new QTreeWidgetItem(QStringList()<<"卡瓦哈尔");
        QTreeWidgetItem *DeXiLiAo = new QTreeWidgetItem(QStringList()<<"德西利奥");
        QTreeWidgetItem *DeLiHeTe = new QTreeWidgetItem(QStringList()<<"德里赫特");
        QTreeWidgetItem *BaErTeLa = new QTreeWidgetItem(QStringList()<<"巴尔特拉");
        QTreeWidgetItem *ANuoDe = new QTreeWidgetItem(QStringList()<<"阿诺德");
        QTreeWidgetItem *FanDaiKe = new QTreeWidgetItem(QStringList()<<"范戴克");
        QTreeWidgetItem *LuoBoXun = new QTreeWidgetItem(QStringList()<<"罗伯逊");
        QTreeWidgetItem *MaDiPu = new QTreeWidgetItem(QStringList()<<"马蒂普");
        QTreeWidgetItem *MenDi = new QTreeWidgetItem(QStringList()<<"门迪");
        QTreeWidgetItem *SiTongSi = new QTreeWidgetItem(QStringList()<<"斯通斯");
        QTreeWidgetItem *LuoBeiTuo = new QTreeWidgetItem(QStringList()<<"罗贝托");
        QTreeWidgetItem *PiKe = new QTreeWidgetItem(QStringList()<<"皮克");
        QTreeWidgetItem *ALaBa = new QTreeWidgetItem(QStringList()<<"阿拉巴");
        QTreeWidgetItem *PaWaEr = new QTreeWidgetItem(QStringList()<<"帕瓦尔");
        QTreeWidgetItem *AFangSuoDaiWeiSi = new QTreeWidgetItem(QStringList()<<"阿方索戴维斯");
        QTreeWidgetItem *HuMeiErSi = new QTreeWidgetItem(QStringList()<<"胡梅尔斯");
        QTreeWidgetItem *MoNiYe = new QTreeWidgetItem(QStringList()<<"默尼耶");
        QTreeWidgetItem *MaErJiNiAoSi = new QTreeWidgetItem(QStringList()<<"马尔基尼奥斯");
        QTreeWidgetItem *BoNuQi = new QTreeWidgetItem(QStringList()<<"博努奇");
        QTreeWidgetItem *GeDing = new QTreeWidgetItem(QStringList()<<"戈丁");

        ui->treeWidget_4->addTopLevelItem(AiErNanDeSi);
        ui->treeWidget_4->addTopLevelItem(JiMiXi);
        ui->treeWidget_4->addTopLevelItem(ASiPiLiKuiTa);
        ui->treeWidget_4->addTopLevelItem(QiErWeiEr);
        ui->treeWidget_4->addTopLevelItem(JinPengBei);
        ui->treeWidget_4->addTopLevelItem(MaSaiLuo);
        ui->treeWidget_4->addTopLevelItem(LaMoSi);
        ui->treeWidget_4->addTopLevelItem(WaLaNei);
        ui->treeWidget_4->addTopLevelItem(KaWaHaEr);
        ui->treeWidget_4->addTopLevelItem(DeXiLiAo);
        ui->treeWidget_4->addTopLevelItem(DeLiHeTe);
        ui->treeWidget_4->addTopLevelItem(BaErTeLa);
        ui->treeWidget_4->addTopLevelItem(ANuoDe);
        ui->treeWidget_4->addTopLevelItem(FanDaiKe);
        ui->treeWidget_4->addTopLevelItem(LuoBoXun);
        ui->treeWidget_4->addTopLevelItem(MaDiPu);
        ui->treeWidget_4->addTopLevelItem(MenDi);
        ui->treeWidget_4->addTopLevelItem(SiTongSi);
        ui->treeWidget_4->addTopLevelItem(LuoBeiTuo);
        ui->treeWidget_4->addTopLevelItem(PiKe);
        ui->treeWidget_4->addTopLevelItem(ALaBa);
        ui->treeWidget_4->addTopLevelItem(PaWaEr);
        ui->treeWidget_4->addTopLevelItem(AFangSuoDaiWeiSi);
        ui->treeWidget_4->addTopLevelItem(HuMeiErSi);
        ui->treeWidget_4->addTopLevelItem(MoNiYe);
        ui->treeWidget_4->addTopLevelItem(MaErJiNiAoSi);
        ui->treeWidget_4->addTopLevelItem(BoNuQi);
        ui->treeWidget_4->addTopLevelItem(GeDing);

        QStringList age73;
        age73 << "年龄:34";
        QStringList rating73;
        rating73 << "能力值:87";
        QStringList position73;
        position73 << "后卫/右脚";
        QStringList weeksalary73;
        weeksalary73 << "周薪:12";
        QStringList transferfee73;
        transferfee73 << "转会费:5000";
        QTreeWidgetItem* a73 = new QTreeWidgetItem(age73);
        GeDing->addChild(a73);
        QTreeWidgetItem* r73 = new QTreeWidgetItem(rating73);
        GeDing->addChild(r73);
        QTreeWidgetItem* p73 = new QTreeWidgetItem(position73);
        GeDing->addChild(p73);
        QTreeWidgetItem* w73 = new QTreeWidgetItem(weeksalary73);
        GeDing->addChild(w73);
        QTreeWidgetItem* t73 = new QTreeWidgetItem(transferfee73);
        GeDing->addChild(t73);

        QStringList age74;
        age74 << "年龄:24";
        QStringList rating74;
        rating74 << "能力值:84";
        QStringList position74;
        position74 << "后卫/左脚";
        QStringList weeksalary74;
        weeksalary74 << "周薪:25";
        QStringList transferfee74;
        transferfee74 << "转会费:5600";
        QTreeWidgetItem* a74 = new QTreeWidgetItem(age74);
        AiErNanDeSi->addChild(a74);
        QTreeWidgetItem* r74 = new QTreeWidgetItem(rating74);
        AiErNanDeSi->addChild(r74);
        QTreeWidgetItem* p74 = new QTreeWidgetItem(position74);
        AiErNanDeSi->addChild(p74);
        QTreeWidgetItem* w74 = new QTreeWidgetItem(weeksalary74);
        AiErNanDeSi->addChild(w74);
        QTreeWidgetItem* t74 = new QTreeWidgetItem(transferfee74);
        AiErNanDeSi->addChild(t74);

        QStringList age75;
        age75 << "年龄:25";
        QStringList rating75;
        rating75 << "能力值:87";
        QStringList position75;
        position75 << "后卫/左脚";
        QStringList weeksalary75;
        weeksalary75 << "周薪:15";
        QStringList transferfee75;
        transferfee75 << "转会费:7500";
        QTreeWidgetItem* a75 = new QTreeWidgetItem(age75);
        JiMiXi->addChild(a75);
        QTreeWidgetItem* r75 = new QTreeWidgetItem(rating75);
        JiMiXi->addChild(r75);
        QTreeWidgetItem* p75 = new QTreeWidgetItem(position75);
        JiMiXi->addChild(p75);
        QTreeWidgetItem* w75 = new QTreeWidgetItem(weeksalary75);
        JiMiXi->addChild(w75);
        QTreeWidgetItem* t75 = new QTreeWidgetItem(transferfee75);
        JiMiXi->addChild(t75);

        QStringList age76;
        age76 << "年龄:31";
        QStringList rating76;
        rating76 << "能力值:84";
        QStringList position76;
        position76 << "后卫/右脚";
        QStringList weeksalary76;
        weeksalary76 << "周薪:9";
        QStringList transferfee76;
        transferfee76 << "转会费:2400";
        QTreeWidgetItem* a76 = new QTreeWidgetItem(age76);
        ASiPiLiKuiTa->addChild(a76);
        QTreeWidgetItem* r76 = new QTreeWidgetItem(rating76);
        ASiPiLiKuiTa->addChild(r76);
        QTreeWidgetItem* p76 = new QTreeWidgetItem(position76);
        ASiPiLiKuiTa->addChild(p76);
        QTreeWidgetItem* w76 = new QTreeWidgetItem(weeksalary76);
        ASiPiLiKuiTa->addChild(w76);
        QTreeWidgetItem* t76 = new QTreeWidgetItem(transferfee76);
        ASiPiLiKuiTa->addChild(t76);

        QStringList age77;
        age77 << "年龄:23";
        QStringList rating77;
        rating77 << "能力值:81";
        QStringList position77;
        position77 << "后卫/左脚";
        QStringList weeksalary77;
        weeksalary77 << "周薪:7";
        QStringList transferfee77;
        transferfee77 << "转会费:4000";
        QTreeWidgetItem* a77 = new QTreeWidgetItem(age77);
        QiErWeiEr->addChild(a77);
        QTreeWidgetItem* r77 = new QTreeWidgetItem(rating77);
        QiErWeiEr->addChild(r77);
        QTreeWidgetItem* p77 = new QTreeWidgetItem(position77);
        QiErWeiEr->addChild(p77);
        QTreeWidgetItem* w77 = new QTreeWidgetItem(weeksalary77);
        QiErWeiEr->addChild(w77);
        QTreeWidgetItem* t77 = new QTreeWidgetItem(transferfee77);
        QiErWeiEr->addChild(t77);

        QStringList age78;
        age78 << "年龄:25";
        QStringList rating78;
        rating78 << "能力值:82";
        QStringList position78;
        position78 << "后卫/左脚";
        QStringList weeksalary78;
        weeksalary78 << "周薪:14";
        QStringList transferfee78;
        transferfee78 << "转会费:2800";
        QTreeWidgetItem* a78 = new QTreeWidgetItem(age78);
        JinPengBei->addChild(a78);
        QTreeWidgetItem* r78 = new QTreeWidgetItem(rating78);
        JinPengBei->addChild(r78);
        QTreeWidgetItem* p78 = new QTreeWidgetItem(position78);
        JinPengBei->addChild(p78);
        QTreeWidgetItem* w78 = new QTreeWidgetItem(weeksalary78);
        JinPengBei->addChild(w78);
        QTreeWidgetItem* t78 = new QTreeWidgetItem(transferfee78);
        JinPengBei->addChild(t78);

        QStringList age79;
        age79 << "年龄:32";
        QStringList rating79;
        rating79 << "能力值:84";
        QStringList position79;
        position79 << "后卫/左脚";
        QStringList weeksalary79;
        weeksalary79 << "周薪:38";
        QStringList transferfee79;
        transferfee79 << "转会费:1600";
        QTreeWidgetItem* a79 = new QTreeWidgetItem(age79);
        MaSaiLuo->addChild(a79);
        QTreeWidgetItem* r79 = new QTreeWidgetItem(rating79);
        MaSaiLuo->addChild(r79);
        QTreeWidgetItem* p79 = new QTreeWidgetItem(position79);
        MaSaiLuo->addChild(p79);
        QTreeWidgetItem* w79 = new QTreeWidgetItem(weeksalary79);
        MaSaiLuo->addChild(w79);
        QTreeWidgetItem* t79 = new QTreeWidgetItem(transferfee79);
        MaSaiLuo->addChild(t79);


        QStringList age80;
        age80 << "年龄:34";
        QStringList rating80;
        rating80 << "能力值:84";
        QStringList position80;
        position80 << "后卫/右脚";
        QStringList weeksalary80;
        weeksalary80 << "周薪:38";
        QStringList transferfee80;
        transferfee80 << "转会费:1450";
        QTreeWidgetItem* a80 = new QTreeWidgetItem(age80);
        LaMoSi ->addChild(a80);
        QTreeWidgetItem* r80 = new QTreeWidgetItem(rating80);
        LaMoSi->addChild(r80);
        QTreeWidgetItem* p80 = new QTreeWidgetItem(position80);
        LaMoSi->addChild(p80);
        QTreeWidgetItem* w80 = new QTreeWidgetItem(weeksalary80);
        LaMoSi->addChild(w80);
        QTreeWidgetItem* t80 = new QTreeWidgetItem(transferfee80);
        LaMoSi->addChild(t80);

        QStringList age81;
        age81 << "年龄:27";
        QStringList rating81;
        rating81 << "能力值:86";
        QStringList position81;
        position81 << "后卫/右脚";
        QStringList weeksalary81;
        weeksalary81 << "周薪:20";
        QStringList transferfee81;
        transferfee81 << "转会费:6400";
        QTreeWidgetItem* a81 = new QTreeWidgetItem(age81);
        WaLaNei->addChild(a81);
        QTreeWidgetItem* r81 = new QTreeWidgetItem(rating81);
        WaLaNei->addChild(r81);
        QTreeWidgetItem* p81 = new QTreeWidgetItem(position81);
        WaLaNei->addChild(p81);
        QTreeWidgetItem* w81 = new QTreeWidgetItem(weeksalary81);
        WaLaNei->addChild(w81);
        QTreeWidgetItem* t81 = new QTreeWidgetItem(transferfee81);
        WaLaNei->addChild(t81);

        QStringList age82;
        age82 << "年龄:28";
        QStringList rating82;
        rating82 << "能力值:85";
        QStringList position82;
        position82 << "后卫/右脚";
        QStringList weeksalary82;
        weeksalary82 << "周薪:16";
        QStringList transferfee82;
        transferfee82 << "转会费:6400";
        QTreeWidgetItem* a82 = new QTreeWidgetItem(age82);
        KaWaHaEr->addChild(a82);
        QTreeWidgetItem* r82 = new QTreeWidgetItem(rating82);
        KaWaHaEr->addChild(r82);
        QTreeWidgetItem* p82 = new QTreeWidgetItem(position82);
        KaWaHaEr->addChild(p82);
        QTreeWidgetItem* w82 = new QTreeWidgetItem(weeksalary82);
        KaWaHaEr->addChild(w82);
        QTreeWidgetItem* t82 = new QTreeWidgetItem(transferfee82);
        KaWaHaEr->addChild(t82);

        QStringList age83;
        age83 << "年龄:27";
        QStringList rating83;
        rating83 << "能力值:77";
        QStringList position83;
        position83 << "后卫/右脚";
        QStringList weeksalary83;
        weeksalary83 << "周薪:11";
        QStringList transferfee83;
        transferfee83 << "转会费:750";
        QTreeWidgetItem* a83 = new QTreeWidgetItem(age83);
        DeXiLiAo->addChild(a83);
        QTreeWidgetItem* r83 = new QTreeWidgetItem(rating83);
        DeXiLiAo->addChild(r83);
        QTreeWidgetItem* p83 = new QTreeWidgetItem(position83);
        DeXiLiAo->addChild(p83);
        QTreeWidgetItem* w83 = new QTreeWidgetItem(weeksalary83);
        DeXiLiAo->addChild(w83);
        QTreeWidgetItem* t83 = new QTreeWidgetItem(transferfee83);
        DeXiLiAo->addChild(t83);

        QStringList age84;
        age84 << "年龄:21";
        QStringList rating84;
        rating84 << "能力值:85";
        QStringList position84;
        position84 << "后卫/右脚";
        QStringList weeksalary84;
        weeksalary84 << "周薪:20";
        QStringList transferfee84;
        transferfee84 << "转会费:7000";
        QTreeWidgetItem* a84 = new QTreeWidgetItem(age84);
        DeLiHeTe->addChild(a84);
        QTreeWidgetItem* r84 = new QTreeWidgetItem(rating84);
        DeLiHeTe->addChild(r84);
        QTreeWidgetItem* p84 = new QTreeWidgetItem(position84);
        DeLiHeTe->addChild(p84);
        QTreeWidgetItem* w84 = new QTreeWidgetItem(weeksalary84);
        DeLiHeTe->addChild(w84);
        QTreeWidgetItem* t84 = new QTreeWidgetItem(transferfee84);
        DeLiHeTe->addChild(t84);

        QStringList age85;
        age85 << "年龄:29";
        QStringList rating85;
        rating85 << "能力值:83";
        QStringList position85;
        position85 << "后卫/右脚";
        QStringList weeksalary85;
        weeksalary85 << "周薪:7";
        QStringList transferfee85;
        transferfee85 << "转会费:1400";
        QTreeWidgetItem* a85 = new QTreeWidgetItem(age85);
        BaErTeLa->addChild(a85);
        QTreeWidgetItem* r85 = new QTreeWidgetItem(rating85);
        BaErTeLa->addChild(r85);
        QTreeWidgetItem* p85 = new QTreeWidgetItem(position85);
        BaErTeLa->addChild(p85);
        QTreeWidgetItem* w85 = new QTreeWidgetItem(weeksalary85);
        BaErTeLa->addChild(w85);
        QTreeWidgetItem* t85 = new QTreeWidgetItem(transferfee85);
        BaErTeLa->addChild(t85);

        QStringList age86;
        age86 << "年龄:21";
        QStringList rating86;
        rating86 << "能力值:85";
        QStringList position86;
        position86 << "后卫/右脚";
        QStringList weeksalary86;
        weeksalary86 << "周薪:4";
        QStringList transferfee86;
        transferfee86 << "转会费:11000";
        QTreeWidgetItem* a86 = new QTreeWidgetItem(age86);
        ANuoDe->addChild(a86);
        QTreeWidgetItem* r86 = new QTreeWidgetItem(rating86);
        ANuoDe->addChild(r86);
        QTreeWidgetItem* p86 = new QTreeWidgetItem(position86);
        ANuoDe->addChild(p86);
        QTreeWidgetItem* w86 = new QTreeWidgetItem(weeksalary86);
        ANuoDe->addChild(w86);
        QTreeWidgetItem* t86 = new QTreeWidgetItem(transferfee86);
        ANuoDe->addChild(t86);

        QStringList age87;
        age87 << "年龄:29";
        QStringList rating87;
        rating87 << "能力值:91";
        QStringList position87;
        position87 << "后卫/右脚";
        QStringList weeksalary87;
        weeksalary87 << "周薪:18";
        QStringList transferfee87;
        transferfee87 << "转会费:8000";
        QTreeWidgetItem* a87 = new QTreeWidgetItem(age87);
        FanDaiKe->addChild(a87);
        QTreeWidgetItem* r87 = new QTreeWidgetItem(rating87);
        FanDaiKe->addChild(r87);
        QTreeWidgetItem* p87 = new QTreeWidgetItem(position87);
        FanDaiKe->addChild(p87);
        QTreeWidgetItem* w87 = new QTreeWidgetItem(weeksalary87);
        FanDaiKe->addChild(w87);
        QTreeWidgetItem* t87 = new QTreeWidgetItem(transferfee87);
        FanDaiKe->addChild(t87);

        QStringList age88;
        age88 << "年龄:26";
        QStringList rating88;
        rating88 << "能力值:86";
        QStringList position88;
        position88 << "后卫/左脚";
        QStringList weeksalary88;
        weeksalary88 << "周薪:5";
        QStringList transferfee88;
        transferfee88 << "转会费:6400";
        QTreeWidgetItem* a88 = new QTreeWidgetItem(age88);
        LuoBoXun->addChild(a88);
        QTreeWidgetItem* r88 = new QTreeWidgetItem(rating88);
        LuoBoXun->addChild(r88);
        QTreeWidgetItem* p88 = new QTreeWidgetItem(position88);
        LuoBoXun->addChild(p88);
        QTreeWidgetItem* w88 = new QTreeWidgetItem(weeksalary88);
        LuoBoXun->addChild(w88);
        QTreeWidgetItem* t88 = new QTreeWidgetItem(transferfee88);
        LuoBoXun->addChild(t88);

        QStringList age89;
        age89 << "年龄:29";
        QStringList rating89;
        rating89 << "能力值:83";
        QStringList position89;
        position89 << "后卫/右脚";
        QStringList weeksalary89;
        weeksalary89 << "周薪:10";
        QStringList transferfee89;
        transferfee89 << "转会费:3200";
        QTreeWidgetItem* a89 = new QTreeWidgetItem(age89);
        MaDiPu->addChild(a89);
        QTreeWidgetItem* r89 = new QTreeWidgetItem(rating89);
        MaDiPu->addChild(r89);
        QTreeWidgetItem* p89 = new QTreeWidgetItem(position89);
        MaDiPu->addChild(p89);
        QTreeWidgetItem* w89 = new QTreeWidgetItem(weeksalary89);
        MaDiPu->addChild(w89);
        QTreeWidgetItem* t89 = new QTreeWidgetItem(transferfee89);
        MaDiPu->addChild(t89);

        QStringList age90;
        age90 << "年龄:26";
        QStringList rating90;
        rating90 << "能力值:80";
        QStringList position90;
        position90 << "后卫/右脚";
        QStringList weeksalary90;
        weeksalary90 << "周薪:10";
        QStringList transferfee90;
        transferfee90 << "转会费:2800";
        QTreeWidgetItem* a90 = new QTreeWidgetItem(age90);
        MenDi->addChild(a90);
        QTreeWidgetItem* r90 = new QTreeWidgetItem(rating90);
        MenDi->addChild(r90);
        QTreeWidgetItem* p90 = new QTreeWidgetItem(position90);
        MenDi->addChild(p90);
        QTreeWidgetItem* w90 = new QTreeWidgetItem(weeksalary90);
        MenDi->addChild(w90);
        QTreeWidgetItem* t90 = new QTreeWidgetItem(transferfee90);
        MenDi->addChild(t90);

        QStringList age91;
        age91 << "年龄:26";
        QStringList rating91;
        rating91 << "能力值:81";
        QStringList position91;
        position91 << "后卫/右脚";
        QStringList weeksalary91;
        weeksalary91 << "周薪:10";
        QStringList transferfee91;
        transferfee91 << "转会费:3000";
        QTreeWidgetItem* a91 = new QTreeWidgetItem(age91);
        SiTongSi->addChild(a91);
        QTreeWidgetItem* r91 = new QTreeWidgetItem(rating91);
        SiTongSi->addChild(r91);
        QTreeWidgetItem* p91 = new QTreeWidgetItem(position91);
        SiTongSi->addChild(p91);
        QTreeWidgetItem* w91 = new QTreeWidgetItem(weeksalary91);
        SiTongSi->addChild(w91);
        QTreeWidgetItem* t91 = new QTreeWidgetItem(transferfee91);
        SiTongSi->addChild(t91);

        QStringList age92;
        age92 << "年龄:28";
        QStringList rating92;
        rating92 << "能力值:82";
        QStringList position92;
        position92 << "后卫/右脚";
        QStringList weeksalary92;
        weeksalary92 << "周薪:19";
        QStringList transferfee92;
        transferfee92 << "转会费:4000";
        QTreeWidgetItem* a92 = new QTreeWidgetItem(age92);
        LuoBeiTuo->addChild(a92);
        QTreeWidgetItem* r92 = new QTreeWidgetItem(rating92);
        LuoBeiTuo->addChild(r92);
        QTreeWidgetItem* p92 = new QTreeWidgetItem(position92);
        LuoBeiTuo->addChild(p92);
        QTreeWidgetItem* w92 = new QTreeWidgetItem(weeksalary92);
        LuoBeiTuo->addChild(w92);
        QTreeWidgetItem* t92 = new QTreeWidgetItem(transferfee92);
        LuoBeiTuo->addChild(t92);

        QStringList age93;
        age93 << "年龄:33";
        QStringList rating93;
        rating93 << "能力值:88";
        QStringList position93;
        position93 << "后卫/右脚";
        QStringList weeksalary93;
        weeksalary93 << "周薪:24";
        QStringList transferfee93;
        transferfee93 << "转会费:2000";
        QTreeWidgetItem* a93 = new QTreeWidgetItem(age93);
        PiKe->addChild(a93);
        QTreeWidgetItem* r93 = new QTreeWidgetItem(rating93);
        PiKe->addChild(r93);
        QTreeWidgetItem* p93 = new QTreeWidgetItem(position93);
        PiKe->addChild(p93);
        QTreeWidgetItem* w93 = new QTreeWidgetItem(weeksalary93);
        PiKe->addChild(w93);
        QTreeWidgetItem* t93 = new QTreeWidgetItem(transferfee93);
        PiKe->addChild(t93);

        QStringList age94;
        age94 << "年龄:28";
        QStringList rating94;
        rating94 << "能力值:83";
        QStringList position94;
        position94 << "后卫/左脚";
        QStringList weeksalary94;
        weeksalary94 << "周薪:19";
        QStringList transferfee94;
        transferfee94 << "转会费:6500";
        QTreeWidgetItem* a94 = new QTreeWidgetItem(age94);
        ALaBa->addChild(a94);
        QTreeWidgetItem* r94 = new QTreeWidgetItem(rating94);
        ALaBa->addChild(r94);
        QTreeWidgetItem* p94 = new QTreeWidgetItem(position94);
        ALaBa->addChild(p94);
        QTreeWidgetItem* w94 = new QTreeWidgetItem(weeksalary94);
        ALaBa->addChild(w94);
        QTreeWidgetItem* t94 = new QTreeWidgetItem(transferfee94);
        ALaBa->addChild(t94);

        QStringList age95;
        age95 << "年龄:24";
        QStringList rating95;
        rating95 << "能力值:80";
        QStringList position95;
        position95 << "后卫/右脚";
        QStringList weeksalary95;
        weeksalary95 << "周薪:2";
        QStringList transferfee95;
        transferfee95 << "转会费:4000";
        QTreeWidgetItem* a95 = new QTreeWidgetItem(age95);
        PaWaEr->addChild(a95);
        QTreeWidgetItem* r95 = new QTreeWidgetItem(rating95);
        PaWaEr->addChild(r95);
        QTreeWidgetItem* p95 = new QTreeWidgetItem(position95);
        PaWaEr->addChild(p95);
        QTreeWidgetItem* w95 = new QTreeWidgetItem(weeksalary95);
        PaWaEr->addChild(w95);
        QTreeWidgetItem* t95 = new QTreeWidgetItem(transferfee95);
        PaWaEr->addChild(t95);

        QStringList age96;
        age96 << "年龄:19";
        QStringList rating96;
        rating96 << "能力值:77";
        QStringList position96;
        position96 << "后卫/右脚";
        QStringList weeksalary96;
        weeksalary96 << "周薪:5";
        QStringList transferfee96;
        transferfee96 << "转会费:6000";
        QTreeWidgetItem* a96 = new QTreeWidgetItem(age96);
        AFangSuoDaiWeiSi->addChild(a96);
        QTreeWidgetItem* r96 = new QTreeWidgetItem(rating96);
        AFangSuoDaiWeiSi->addChild(r96);
        QTreeWidgetItem* p96 = new QTreeWidgetItem(position96);
        AFangSuoDaiWeiSi->addChild(p96);
        QTreeWidgetItem* w96 = new QTreeWidgetItem(weeksalary96);
        AFangSuoDaiWeiSi->addChild(w96);
        QTreeWidgetItem* t96 = new QTreeWidgetItem(transferfee96);
        AFangSuoDaiWeiSi->addChild(t96);

        QStringList age97;
        age97 << "年龄:31";
        QStringList rating97;
        rating97 << "能力值:87";
        QStringList position97;
        position97 << "后卫/右脚";
        QStringList weeksalary97;
        weeksalary97 << "周薪:19";
        QStringList transferfee97;
        transferfee97 << "转会费:2400";
        QTreeWidgetItem* a97 = new QTreeWidgetItem(age97);
        HuMeiErSi->addChild(a97);
        QTreeWidgetItem* r97 = new QTreeWidgetItem(rating97);
        HuMeiErSi->addChild(r97);
        QTreeWidgetItem* p97 = new QTreeWidgetItem(position97);
        HuMeiErSi->addChild(p97);
        QTreeWidgetItem* w97 = new QTreeWidgetItem(weeksalary97);
        HuMeiErSi->addChild(w97);
        QTreeWidgetItem* t97 = new QTreeWidgetItem(transferfee97);
        HuMeiErSi->addChild(t97);

        QStringList age98;
        age98 << "年龄:28";
        QStringList rating98;
        rating98 << "能力值:81";
        QStringList position98;
        position98 << "后卫/右脚";
        QStringList weeksalary98;
        weeksalary98 << "周薪:6";
        QStringList transferfee98;
        transferfee98 << "转会费:2400";
        QTreeWidgetItem* a98 = new QTreeWidgetItem(age98);
        MoNiYe->addChild(a98);
        QTreeWidgetItem* r98 = new QTreeWidgetItem(rating98);
        MoNiYe->addChild(r98);
        QTreeWidgetItem* p98 = new QTreeWidgetItem(position98);
        MoNiYe->addChild(p98);
        QTreeWidgetItem* w98 = new QTreeWidgetItem(weeksalary98);
        MoNiYe->addChild(w98);
        QTreeWidgetItem* t98 = new QTreeWidgetItem(transferfee98);
        MoNiYe->addChild(t98);

        QStringList age99;
        age99 << "年龄:26";
        QStringList rating99;
        rating99 << "能力值:86";
        QStringList position99;
        position99 << "后卫/右脚";
        QStringList weeksalary99;
        weeksalary99 << "周薪:26";
        QStringList transferfee99;
        transferfee99 << "转会费:5200";
        QTreeWidgetItem* a99 = new QTreeWidgetItem(age99);
        MaErJiNiAoSi->addChild(a99);
        QTreeWidgetItem* r99 = new QTreeWidgetItem(rating99);
        MaErJiNiAoSi->addChild(r99);
        QTreeWidgetItem* p99 = new QTreeWidgetItem(position99);
        MaErJiNiAoSi->addChild(p99);
        QTreeWidgetItem* w99 = new QTreeWidgetItem(weeksalary99);
        MaErJiNiAoSi->addChild(w99);
        QTreeWidgetItem* t99 = new QTreeWidgetItem(transferfee99);
        MaErJiNiAoSi->addChild(t99);

        QStringList age100;
        age100 << "年龄:33";
        QStringList rating100;
        rating100 << "能力值:86";
        QStringList position100;
        position100 << "后卫/右脚";
        QStringList weeksalary100;
        weeksalary100 << "周薪:20";
        QStringList transferfee100;
        transferfee100 << "转会费:1800";
        QTreeWidgetItem* a100 = new QTreeWidgetItem(age100);
        BoNuQi->addChild(a100);
        QTreeWidgetItem* r100 = new QTreeWidgetItem(rating100);
        BoNuQi->addChild(r100);
        QTreeWidgetItem* p100 = new QTreeWidgetItem(position100);
        BoNuQi->addChild(p100);
        QTreeWidgetItem* w100 = new QTreeWidgetItem(weeksalary100);
        BoNuQi->addChild(w100);
        QTreeWidgetItem* t100 = new QTreeWidgetItem(transferfee100);
        BoNuQi->addChild(t100);
    }
    //“选择后卫”按钮
    connect(ui->ChooseBackBtn,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        check_1 = true;
        check_2 = true;
        if (ui->checkBox_73->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("埃尔南德斯");
            else if (back2==QString())
                back2=QString("埃尔南德斯");
            else if(back3==QString())
                back3=QString("埃尔南德斯");
            else if(back4==QString())
                back4=QString("埃尔南德斯");
            else if(back5==QString())
                back5=QString("埃尔南德斯");
            else if(back6==QString())
                back6=QString("埃尔南德斯");
            else if(back7==QString())
                back7=QString("埃尔南德斯");
        }
        if (ui->checkBox_74->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("基米希");
            else if (back2==QString())
                back2=QString("基米希");
            else if(back3==QString())
                back3=QString("基米希");
            else if(back4==QString())
                back4=QString("基米希");
            else if(back5==QString())
                back5=QString("基米希");
            else if(back6==QString())
                back6=QString("基米希");
            else if(back7==QString())
                back7=QString("基米希");
        }
        if (ui->checkBox_75->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("阿斯皮利奎塔");
            else if (back2==QString())
                back2=QString("阿斯皮利奎塔");
            else if(back3==QString())
                back3=QString("阿斯皮利奎塔");
            else if(back4==QString())
                back4=QString("阿斯皮利奎塔");
            else if(back5==QString())
                back5=QString("阿斯皮利奎塔");
            else if(back6==QString())
                back6=QString("阿斯皮利奎塔");
            else if(back7==QString())
                back7=QString("阿斯皮利奎塔");
        }
        if (ui->checkBox_76->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("奇尔韦尔");
            else if (back2==QString())
                back2=QString("奇尔韦尔");
            else if(back3==QString())
                back3=QString("奇尔韦尔");
            else if(back4==QString())
                back4=QString("奇尔韦尔");
            else if(back5==QString())
                back5=QString("奇尔韦尔");
            else if(back6==QString())
                back6=QString("奇尔韦尔");
            else if(back7==QString())
                back7=QString("奇尔韦尔");
        }
        if (ui->checkBox_77->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("金彭贝");
            else if (back2==QString())
                back2=QString("金彭贝");
            else if(back3==QString())
                back3=QString("金彭贝");
            else if(back4==QString())
                back4=QString("金彭贝");
            else if(back5==QString())
                back5=QString("金彭贝");
            else if(back6==QString())
                back6=QString("金彭贝");
            else if(back7==QString())
                back7=QString("金彭贝");
        }
        if (ui->checkBox_78->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("马塞洛");
            else if (back2==QString())
                back2=QString("马塞洛");
            else if(back3==QString())
                back3=QString("马塞洛");
            else if(back4==QString())
                back4=QString("马塞洛");
            else if(back5==QString())
                back5=QString("马塞洛");
            else if(back6==QString())
                back6=QString("马塞洛");
            else if(back7==QString())
                back7=QString("马塞洛");
        }
        if (ui->checkBox_79->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("拉莫斯");
            else if (back2==QString())
                back2=QString("拉莫斯");
            else if(back3==QString())
                back3=QString("拉莫斯");
            else if(back4==QString())
                back4=QString("拉莫斯");
            else if(back5==QString())
                back5=QString("拉莫斯");
            else if(back6==QString())
                back6=QString("拉莫斯");
            else if(back7==QString())
                back7=QString("拉莫斯");
        }
        if (ui->checkBox_80->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("瓦拉内");
            else if (back2==QString())
                back2=QString("瓦拉内");
            else if(back3==QString())
                back3=QString("瓦拉内");
            else if(back4==QString())
                back4=QString("瓦拉内");
            else if(back5==QString())
                back5=QString("瓦拉内");
            else if(back6==QString())
                back6=QString("瓦拉内");
            else if(back7==QString())
                back7=QString("瓦拉内");
        }
        if (ui->checkBox_81->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("卡瓦哈尔");
            else if (back2==QString())
                back2=QString("卡瓦哈尔");
            else if(back3==QString())
                back3=QString("卡瓦哈尔");
            else if(back4==QString())
                back4=QString("卡瓦哈尔");
            else if(back5==QString())
                back5=QString("卡瓦哈尔");
            else if(back6==QString())
                back6=QString("卡瓦哈尔");
            else if(back7==QString())
                back7=QString("卡瓦哈尔");
        }
        if (ui->checkBox_82->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("德西利奥");
            else if (back2==QString())
                back2=QString("德西利奥");
            else if(back3==QString())
                back3=QString("德西利奥");
            else if(back4==QString())
                back4=QString("德西利奥");
            else if(back5==QString())
                back5=QString("德西利奥");
            else if(back6==QString())
                back6=QString("德西利奥");
            else if(back7==QString())
                back7=QString("德西利奥");
        }
        if (ui->checkBox_83->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("德里赫特");
            else if (back2==QString())
                back2=QString("德里赫特");
            else if(back3==QString())
                back3=QString("德里赫特");
            else if(back4==QString())
                back4=QString("德里赫特");
            else if(back5==QString())
                back5=QString("德里赫特");
            else if(back6==QString())
                back6=QString("德里赫特");
            else if(back7==QString())
                back7=QString("德里赫特");
        }
        if (ui->checkBox_84->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("巴尔特拉");
            else if (back2==QString())
                back2=QString("巴尔特拉");
            else if(back3==QString())
                back3=QString("巴尔特拉");
            else if(back4==QString())
                back4=QString("巴尔特拉");
            else if(back5==QString())
                back5=QString("巴尔特拉");
            else if(back6==QString())
                back6=QString("巴尔特拉");
            else if(back7==QString())
                back7=QString("巴尔特拉");
        }
        if (ui->checkBox_85->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("阿诺德");
            else if (back2==QString())
                back2=QString("阿诺德");
            else if(back3==QString())
                back3=QString("阿诺德");
            else if(back4==QString())
                back4=QString("阿诺德");
            else if(back5==QString())
                back5=QString("阿诺德");
            else if(back6==QString())
                back6=QString("阿诺德");
            else if(back7==QString())
                back7=QString("阿诺德");
        }
        if (ui->checkBox_86->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("范戴克");
            else if (back2==QString())
                back2=QString("范戴克");
            else if(back3==QString())
                back3=QString("范戴克");
            else if(back4==QString())
                back4=QString("范戴克");
            else if(back5==QString())
                back5=QString("范戴克");
            else if(back6==QString())
                back6=QString("范戴克");
            else if(back7==QString())
                back7=QString("范戴克");
        }
        if (ui->checkBox_87->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("罗伯逊");
            else if (back2==QString())
                back2=QString("罗伯逊");
            else if(back3==QString())
                back3=QString("罗伯逊");
            else if(back4==QString())
                back4=QString("罗伯逊");
            else if(back5==QString())
                back5=QString("罗伯逊");
            else if(back6==QString())
                back6=QString("罗伯逊");
            else if(back7==QString())
                back7=QString("罗伯逊");
        }
        if (ui->checkBox_88->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("马蒂普");
            else if (back2==QString())
                back2=QString("马蒂普");
            else if(back3==QString())
                back3=QString("马蒂普");
            else if(back4==QString())
                back4=QString("马蒂普");
            else if(back5==QString())
                back5=QString("马蒂普");
            else if(back6==QString())
                back6=QString("马蒂普");
            else if(back7==QString())
                back7=QString("马蒂普");
        }
        if (ui->checkBox_89->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("门迪");
            else if (back2==QString())
                back2=QString("门迪");
            else if(back3==QString())
                back3=QString("门迪");
            else if(back4==QString())
                back4=QString("门迪");
            else if(back5==QString())
                back5=QString("门迪");
            else if(back6==QString())
                back6=QString("门迪");
            else if(back7==QString())
                back7=QString("门迪");
        }
        if (ui->checkBox_90->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("斯通斯");
            else if (back2==QString())
                back2=QString("斯通斯");
            else if(back3==QString())
                back3=QString("斯通斯");
            else if(back4==QString())
                back4=QString("斯通斯");
            else if(back5==QString())
                back5=QString("斯通斯");
            else if(back6==QString())
                back6=QString("斯通斯");
            else if(back7==QString())
                back7=QString("斯通斯");
        }
        if (ui->checkBox_91->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("罗贝托");
            else if (back2==QString())
                back2=QString("罗贝托");
            else if(back3==QString())
                back3=QString("罗贝托");
            else if(back4==QString())
                back4=QString("罗贝托");
            else if(back5==QString())
                back5=QString("罗贝托");
            else if(back6==QString())
                back6=QString("罗贝托");
            else if(back7==QString())
                back7=QString("罗贝托");
        }
        if (ui->checkBox_92->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("皮克");
            else if (back2==QString())
                back2=QString("皮克");
            else if(back3==QString())
                back3=QString("皮克");
            else if(back4==QString())
                back4=QString("皮克");
            else if(back5==QString())
                back5=QString("皮克");
            else if(back6==QString())
                back6=QString("皮克");
            else if(back7==QString())
                back7=QString("皮克");
        }
        if (ui->checkBox_93->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("阿拉巴");
            else if (back2==QString())
                back2=QString("阿拉巴");
            else if(back3==QString())
                back3=QString("阿拉巴");
            else if(back4==QString())
                back4=QString("阿拉巴");
            else if(back5==QString())
                back5=QString("阿拉巴");
            else if(back6==QString())
                back6=QString("阿拉巴");
            else if(back7==QString())
                back7=QString("阿拉巴");
        }
        if (ui->checkBox_94->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("帕瓦尔");
            else if (back2==QString())
                back2=QString("帕瓦尔");
            else if(back3==QString())
                back3=QString("帕瓦尔");
            else if(back4==QString())
                back4=QString("帕瓦尔");
            else if(back5==QString())
                back5=QString("帕瓦尔");
            else if(back6==QString())
                back6=QString("帕瓦尔");
            else if(back7==QString())
                back7=QString("帕瓦尔");
        }
        if (ui->checkBox_95->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("阿方索戴维斯");
            else if (back2==QString())
                back2=QString("阿方索戴维斯");
            else if(back3==QString())
                back3=QString("阿方索戴维斯");
            else if(back4==QString())
                back4=QString("阿方索戴维斯");
            else if(back5==QString())
                back5=QString("阿方索戴维斯");
            else if(back6==QString())
                back6=QString("阿方索戴维斯");
            else if(back7==QString())
                back7=QString("阿方索戴维斯");
        }
        if (ui->checkBox_96->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("胡梅尔斯");
            else if (back2==QString())
                back2=QString("胡梅尔斯");
            else if(back3==QString())
                back3=QString("胡梅尔斯");
            else if(back4==QString())
                back4=QString("胡梅尔斯");
            else if(back5==QString())
                back5=QString("胡梅尔斯");
            else if(back6==QString())
                back6=QString("胡梅尔斯");
            else if(back7==QString())
                back7=QString("胡梅尔斯");
        }
        if (ui->checkBox_97->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("默尼耶");
            else if (back2==QString())
                back2=QString("默尼耶");
            else if(back3==QString())
                back3=QString("默尼耶");
            else if(back4==QString())
                back4=QString("默尼耶");
            else if(back5==QString())
                back5=QString("默尼耶");
            else if(back6==QString())
                back6=QString("默尼耶");
            else if(back7==QString())
                back7=QString("默尼耶");
        }
        if (ui->checkBox_98->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("马尔基尼奥斯");
            else if (back2==QString())
                back2=QString("马尔基尼奥斯");
            else if(back3==QString())
                back3=QString("马尔基尼奥斯");
            else if(back4==QString())
                back4=QString("马尔基尼奥斯");
            else if(back5==QString())
                back5=QString("马尔基尼奥斯");
            else if(back6==QString())
                back6=QString("马尔基尼奥斯");
            else if(back7==QString())
                back7=QString("马尔基尼奥斯");
        }
        if (ui->checkBox_99->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("博努奇");
            else if (back2==QString())
                back2=QString("博努奇");
            else if(back3==QString())
                back3=QString("博努奇");
            else if(back4==QString())
                back4=QString("博努奇");
            else if(back5==QString())
                back5=QString("博努奇");
            else if(back6==QString())
                back6=QString("博努奇");
            else if(back7==QString())
                back7=QString("博努奇");
        }
        if (ui->checkBox_100->isChecked())
        {
            ckBoxSum++;
            if (back1==QString())
                back1=QString("戈丁");
            else if (back2==QString())
                back2=QString("戈丁");
            else if(back3==QString())
                back3=QString("戈丁");
            else if(back4==QString())
                back4=QString("戈丁");
            else if(back5==QString())
                back5=QString("戈丁");
            else if(back6==QString())
                back6=QString("戈丁");
            else if(back7==QString())
                back7=QString("戈丁");
        }
        qDebug()<<"back1:"<<back1;
        qDebug()<<"back2:"<<back2;
        qDebug()<<"back3:"<<back3;
        qDebug()<<"back4:"<<back4;
        qDebug()<<"back5:"<<back5;
        qDebug()<<"back6:"<<back6;
        qDebug()<<"back7:"<<back7;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        salarysum4 = 0;
        for (int i=0;i<100;i++)
        {
            if (back1 == players[i].name)
                salarysum4 += players[i].weeksalary;
            else if (back2 == players[i].name)
                salarysum4 += players[i].weeksalary;
            else if (back3 == players[i].name)
                salarysum4 += players[i].weeksalary;
            else if (back4 == players[i].name)
                salarysum4 += players[i].weeksalary;
            else if (back5 == players[i].name)
                salarysum4 += players[i].weeksalary;
            else if (back6 == players[i].name)
                salarysum4 += players[i].weeksalary;
            else if (back7 == players[i].name)
                salarysum4 += players[i].weeksalary;
            else
                continue;
        }
        qDebug()<<"salarysum4:"<<salarysum4;

        //如果选择的后卫数目超过7个，弹窗警告
        if (ckBoxSum > 7)
        {
            check_1 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择七名后卫\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_73->setCheckState(Qt::Unchecked);
                ui->checkBox_73->setChecked(false);
                ui->checkBox_74->setCheckState(Qt::Unchecked);
                ui->checkBox_74->setChecked(false);
                ui->checkBox_75->setCheckState(Qt::Unchecked);
                ui->checkBox_75->setChecked(false);
                ui->checkBox_76->setCheckState(Qt::Unchecked);
                ui->checkBox_76->setChecked(false);
                ui->checkBox_77->setCheckState(Qt::Unchecked);
                ui->checkBox_77->setChecked(false);
                ui->checkBox_78->setCheckState(Qt::Unchecked);
                ui->checkBox_78->setChecked(false);
                ui->checkBox_79->setCheckState(Qt::Unchecked);
                ui->checkBox_79->setChecked(false);
                ui->checkBox_80->setCheckState(Qt::Unchecked);
                ui->checkBox_80->setChecked(false);
                ui->checkBox_81->setCheckState(Qt::Unchecked);
                ui->checkBox_81->setChecked(false);
                ui->checkBox_82->setCheckState(Qt::Unchecked);
                ui->checkBox_82->setChecked(false);
                ui->checkBox_83->setCheckState(Qt::Unchecked);
                ui->checkBox_83->setChecked(false);
                ui->checkBox_84->setCheckState(Qt::Unchecked);
                ui->checkBox_84->setChecked(false);
                ui->checkBox_85->setCheckState(Qt::Unchecked);
                ui->checkBox_85->setChecked(false);
                ui->checkBox_86->setCheckState(Qt::Unchecked);
                ui->checkBox_86->setChecked(false);
                ui->checkBox_87->setCheckState(Qt::Unchecked);
                ui->checkBox_87->setChecked(false);
                ui->checkBox_88->setCheckState(Qt::Unchecked);
                ui->checkBox_88->setChecked(false);
                ui->checkBox_89->setCheckState(Qt::Unchecked);
                ui->checkBox_89->setChecked(false);
                ui->checkBox_90->setCheckState(Qt::Unchecked);
                ui->checkBox_90->setChecked(false);
                ui->checkBox_91->setCheckState(Qt::Unchecked);
                ui->checkBox_91->setChecked(false);
                ui->checkBox_92->setCheckState(Qt::Unchecked);
                ui->checkBox_92->setChecked(false);
                ui->checkBox_93->setCheckState(Qt::Unchecked);
                ui->checkBox_93->setChecked(false);
                ui->checkBox_94->setCheckState(Qt::Unchecked);
                ui->checkBox_94->setChecked(false);
                ui->checkBox_95->setCheckState(Qt::Unchecked);
                ui->checkBox_95->setChecked(false);
                ui->checkBox_96->setCheckState(Qt::Unchecked);
                ui->checkBox_96->setChecked(false);
                ui->checkBox_97->setCheckState(Qt::Unchecked);
                ui->checkBox_97->setChecked(false);
                ui->checkBox_98->setCheckState(Qt::Unchecked);
                ui->checkBox_98->setChecked(false);
                ui->checkBox_99->setCheckState(Qt::Unchecked);
                ui->checkBox_99->setChecked(false);
                ui->checkBox_100->setCheckState(Qt::Unchecked);
                ui->checkBox_100->setChecked(false);
                salarysum4 = 0;
                back1 = QString();
                back2 = QString();
                back3 = QString();
                back4 = QString();
                back5 = QString();
                back6 = QString();
                back7 = QString();
                qDebug()<<"back1:"<<back1;
                qDebug()<<"back2:"<<back2;
                qDebug()<<"back3:"<<back3;
                qDebug()<<"back4:"<<back4;
                qDebug()<<"back5:"<<back5;
                qDebug()<<"back6:"<<back6;
                qDebug()<<"back7:"<<back7;
                qDebug()<<"salarysum4:"<<salarysum4;
            }
        }

        //如果选择的中场数目不足7个，弹窗警告
        if (ckBoxSum < 7)
        {
            check_2 = false;
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的后卫数目不足七个\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_73->setCheckState(Qt::Unchecked);
                ui->checkBox_73->setChecked(false);
                ui->checkBox_74->setCheckState(Qt::Unchecked);
                ui->checkBox_74->setChecked(false);
                ui->checkBox_75->setCheckState(Qt::Unchecked);
                ui->checkBox_75->setChecked(false);
                ui->checkBox_76->setCheckState(Qt::Unchecked);
                ui->checkBox_76->setChecked(false);
                ui->checkBox_77->setCheckState(Qt::Unchecked);
                ui->checkBox_77->setChecked(false);
                ui->checkBox_78->setCheckState(Qt::Unchecked);
                ui->checkBox_78->setChecked(false);
                ui->checkBox_79->setCheckState(Qt::Unchecked);
                ui->checkBox_79->setChecked(false);
                ui->checkBox_80->setCheckState(Qt::Unchecked);
                ui->checkBox_80->setChecked(false);
                ui->checkBox_81->setCheckState(Qt::Unchecked);
                ui->checkBox_81->setChecked(false);
                ui->checkBox_82->setCheckState(Qt::Unchecked);
                ui->checkBox_82->setChecked(false);
                ui->checkBox_83->setCheckState(Qt::Unchecked);
                ui->checkBox_83->setChecked(false);
                ui->checkBox_84->setCheckState(Qt::Unchecked);
                ui->checkBox_84->setChecked(false);
                ui->checkBox_85->setCheckState(Qt::Unchecked);
                ui->checkBox_85->setChecked(false);
                ui->checkBox_86->setCheckState(Qt::Unchecked);
                ui->checkBox_86->setChecked(false);
                ui->checkBox_87->setCheckState(Qt::Unchecked);
                ui->checkBox_87->setChecked(false);
                ui->checkBox_88->setCheckState(Qt::Unchecked);
                ui->checkBox_88->setChecked(false);
                ui->checkBox_89->setCheckState(Qt::Unchecked);
                ui->checkBox_89->setChecked(false);
                ui->checkBox_90->setCheckState(Qt::Unchecked);
                ui->checkBox_90->setChecked(false);
                ui->checkBox_91->setCheckState(Qt::Unchecked);
                ui->checkBox_91->setChecked(false);
                ui->checkBox_92->setCheckState(Qt::Unchecked);
                ui->checkBox_92->setChecked(false);
                ui->checkBox_93->setCheckState(Qt::Unchecked);
                ui->checkBox_93->setChecked(false);
                ui->checkBox_94->setCheckState(Qt::Unchecked);
                ui->checkBox_94->setChecked(false);
                ui->checkBox_95->setCheckState(Qt::Unchecked);
                ui->checkBox_95->setChecked(false);
                ui->checkBox_96->setCheckState(Qt::Unchecked);
                ui->checkBox_96->setChecked(false);
                ui->checkBox_97->setCheckState(Qt::Unchecked);
                ui->checkBox_97->setChecked(false);
                ui->checkBox_98->setCheckState(Qt::Unchecked);
                ui->checkBox_98->setChecked(false);
                ui->checkBox_99->setCheckState(Qt::Unchecked);
                ui->checkBox_99->setChecked(false);
                ui->checkBox_100->setCheckState(Qt::Unchecked);
                ui->checkBox_100->setChecked(false);
                salarysum4 = 0;
                back1 = QString();
                back2 = QString();
                back3 = QString();
                back4 = QString();
                back5 = QString();
                back6 = QString();
                back7 = QString();
                qDebug()<<"back1:"<<back1;
                qDebug()<<"back2:"<<back2;
                qDebug()<<"back3:"<<back3;
                qDebug()<<"back4:"<<back4;
                qDebug()<<"back5:"<<back5;
                qDebug()<<"back6:"<<back6;
                qDebug()<<"back7:"<<back7;
                qDebug()<<"salarysum4:"<<salarysum4;
            }
        }

        salarysum+=salarysum4;
        qDebug()<<"salarysum:"<<salarysum;
        //如果全部所选球员的周薪总和大于等于550，弹窗警告
        if (salarysum >= 550 && check_1 && check_2)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("球员总薪资超出预算，请改变您的后卫选择"),QMessageBox::Ok);
            //ok后重置并且重新选择
            if(a == QMessageBox::Ok)
            {
                ui->checkBox_73->setCheckState(Qt::Unchecked);
                ui->checkBox_73->setChecked(false);
                ui->checkBox_74->setCheckState(Qt::Unchecked);
                ui->checkBox_74->setChecked(false);
                ui->checkBox_75->setCheckState(Qt::Unchecked);
                ui->checkBox_75->setChecked(false);
                ui->checkBox_76->setCheckState(Qt::Unchecked);
                ui->checkBox_76->setChecked(false);
                ui->checkBox_77->setCheckState(Qt::Unchecked);
                ui->checkBox_77->setChecked(false);
                ui->checkBox_78->setCheckState(Qt::Unchecked);
                ui->checkBox_78->setChecked(false);
                ui->checkBox_79->setCheckState(Qt::Unchecked);
                ui->checkBox_79->setChecked(false);
                ui->checkBox_80->setCheckState(Qt::Unchecked);
                ui->checkBox_80->setChecked(false);
                ui->checkBox_81->setCheckState(Qt::Unchecked);
                ui->checkBox_81->setChecked(false);
                ui->checkBox_82->setCheckState(Qt::Unchecked);
                ui->checkBox_82->setChecked(false);
                ui->checkBox_83->setCheckState(Qt::Unchecked);
                ui->checkBox_83->setChecked(false);
                ui->checkBox_84->setCheckState(Qt::Unchecked);
                ui->checkBox_84->setChecked(false);
                ui->checkBox_85->setCheckState(Qt::Unchecked);
                ui->checkBox_85->setChecked(false);
                ui->checkBox_86->setCheckState(Qt::Unchecked);
                ui->checkBox_86->setChecked(false);
                ui->checkBox_87->setCheckState(Qt::Unchecked);
                ui->checkBox_87->setChecked(false);
                ui->checkBox_88->setCheckState(Qt::Unchecked);
                ui->checkBox_88->setChecked(false);
                ui->checkBox_89->setCheckState(Qt::Unchecked);
                ui->checkBox_89->setChecked(false);
                ui->checkBox_90->setCheckState(Qt::Unchecked);
                ui->checkBox_90->setChecked(false);
                ui->checkBox_91->setCheckState(Qt::Unchecked);
                ui->checkBox_91->setChecked(false);
                ui->checkBox_92->setCheckState(Qt::Unchecked);
                ui->checkBox_92->setChecked(false);
                ui->checkBox_93->setCheckState(Qt::Unchecked);
                ui->checkBox_93->setChecked(false);
                ui->checkBox_94->setCheckState(Qt::Unchecked);
                ui->checkBox_94->setChecked(false);
                ui->checkBox_95->setCheckState(Qt::Unchecked);
                ui->checkBox_95->setChecked(false);
                ui->checkBox_96->setCheckState(Qt::Unchecked);
                ui->checkBox_96->setChecked(false);
                ui->checkBox_97->setCheckState(Qt::Unchecked);
                ui->checkBox_97->setChecked(false);
                ui->checkBox_98->setCheckState(Qt::Unchecked);
                ui->checkBox_98->setChecked(false);
                ui->checkBox_99->setCheckState(Qt::Unchecked);
                ui->checkBox_99->setChecked(false);
                ui->checkBox_100->setCheckState(Qt::Unchecked);
                ui->checkBox_100->setChecked(false);
                salarysum4 = 0;
                back1 = QString();
                back2 = QString();
                back3 = QString();
                back4 = QString();
                back5 = QString();
                back6 = QString();
                back7 = QString();
                qDebug()<<"back1:"<<back1;
                qDebug()<<"back2:"<<back2;
                qDebug()<<"back3:"<<back3;
                qDebug()<<"back4:"<<back4;
                qDebug()<<"back5:"<<back5;
                qDebug()<<"back6:"<<back6;
                qDebug()<<"back7:"<<back7;
                qDebug()<<"salarysum4:"<<salarysum4;
            }
        }
        else if (check_1&&check_2)
        {
            ui->stackedWidget->setCurrentIndex(24);
        }
    });

    connect(ui->commandLinkButton_11,&QCommandLinkButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(7);
    });

    //存储球员信息的QVector  不能用
    {
        QVector<QString>playerVector(23);

        playerVector[0] = goalKeeper1;
        playerVector[1] = goalKeeper2;
        playerVector[2] = forward1;
        playerVector[3] = forward2;
        playerVector[4] = forward3;
        playerVector[5] = forward4;
        playerVector[6] = forward5;
        playerVector[7] = forward6;
        playerVector[8] = forward7;
        playerVector[9] = midField1;
        playerVector[10] = midField2;
        playerVector[11] = midField3;
        playerVector[12] = midField4;
        playerVector[13] = midField5;
        playerVector[14] = midField6;
        playerVector[15] = midField7;
        playerVector[16] = back1;
        playerVector[17] = back2;
        playerVector[18] = back3;
        playerVector[19] = back4;
        playerVector[20] = back5;
        playerVector[21] = back6;
        playerVector[22] = back7;
    }
    //playerList<<goalKeeper1<<goalKeeper2<<forward1<<forward2<<forward3<<forward4<<forward5<<forward6<<forward7<<midField1<<midField2<<midField3<<midField4<<midField5<<midField6<<midField7<<back1<<back2<<back3<<back4<<back5<<back6<<back7;
    //球队队员的数组
    {
        teamPlayers[0] = goalKeeper1;
        teamPlayers[1] = goalKeeper2;
        teamPlayers[2] = forward1;
        teamPlayers[3] = forward2;
        teamPlayers[4] = forward3;
        teamPlayers[5] = forward4;
        teamPlayers[6] = forward5;
        teamPlayers[7] = forward6;
        teamPlayers[8] = forward7;
        teamPlayers[9] = midField1;
        teamPlayers[10] = midField2;
        teamPlayers[11] = midField3;
        teamPlayers[12] = midField4;
        teamPlayers[13] = midField5;
        teamPlayers[14] = midField6;
        teamPlayers[15] = midField7;
        teamPlayers[16] = back1;
        teamPlayers[17] = back2;
        teamPlayers[18] = back3;
        teamPlayers[19] = back4;
        teamPlayers[20] = back5;
        teamPlayers[21] = back6;
        teamPlayers[22] = back7;
    }

    //选择正队长
    connect(ui->ChooseCaptainBtn,&QPushButton::clicked,[=](){
        chooseCaptain();
    });

    //选择副队长
    connect(ui->ChooseViceCapBtn,&QPushButton::clicked,[=](){
        if (captian == QString(""))
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("请先选择正队长\n"),QMessageBox::Ok);
        }
        else
        {
            chooseViceCaptain();
            ui->stackedWidget->setCurrentIndex(8);
        }
    });

//操作界面
    ui->groupBox_7->setStyleSheet("color:white;");
    ui->TrainToolBtn->setStyleSheet("color:white;");
    ui->CompeteToolBtn->setStyleSheet("color:white;");

    //"训练"按钮
    connect(ui->TrainToolBtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(9);
    });

    //"比赛"按钮
    connect(ui->CompeteToolBtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(15);
    });

//队伍训练
    //"阵容训练"页面内容
    {
        //给treeWidget_5添加按需出现的水平滚动条
        ui->treeWidget_5->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->treeWidget_5->header()->setStretchLastSection(false);

        ui->treeWidget_5->setHeaderLabels(QStringList()<<"训练阵容");
        QTreeWidgetItem *FTTT = new QTreeWidgetItem(QStringList()<<"4-2-2-2");
        QTreeWidgetItem *TFT = new QTreeWidgetItem(QStringList()<<"3-5-2");
        QTreeWidgetItem *FTTO= new QTreeWidgetItem(QStringList()<<"4-2-3-1");
        QTreeWidgetItem *FTT = new QTreeWidgetItem(QStringList()<<"4-3-3");
        QTreeWidgetItem *TFOT = new QTreeWidgetItem(QStringList()<<"3-4-1-2");
        QTreeWidgetItem *FOTOT = new QTreeWidgetItem(QStringList()<<"4-1-2-1-2");

        ui->treeWidget_5->addTopLevelItem(FTTT);
        ui->treeWidget_5->addTopLevelItem(TFT);
        ui->treeWidget_5->addTopLevelItem(FTTO);
        ui->treeWidget_5->addTopLevelItem(FTT);
        ui->treeWidget_5->addTopLevelItem(TFOT);
        ui->treeWidget_5->addTopLevelItem(FOTOT);

        QStringList YouDian1;
        YouDian1<<"优点：防守稳固，攻击性中场球员带来的进攻范围大，选择多。";
        QStringList QueDian1;
        QueDian1<<"缺点：中场给对手留下空间较大，前后场衔接容易被对手分割。";
        QTreeWidgetItem *yd1 = new QTreeWidgetItem(YouDian1);
        FTTT->addChild(yd1);
        QTreeWidgetItem *qd1 = new QTreeWidgetItem(QueDian1);
        FTTT->addChild(qd1);

        QStringList YouDian2;
        YouDian2<<"优点：高素质的球员形成扎实的防守，牢牢把控住中场。";
        QStringList QueDian2;
        QueDian2<<"缺点：需要高效率的翼卫球员，中卫素质要求高，容错率低。";
        QTreeWidgetItem *yd2 = new QTreeWidgetItem(YouDian2);
        TFT->addChild(yd2);
        QTreeWidgetItem *qd2 = new QTreeWidgetItem(QueDian2);
        TFT->addChild(qd2);

        QStringList YouDian3;
        YouDian3<<"优点：灵活均衡的攻防，强大的中场。";
        QStringList QueDian3;
        QueDian3<<"缺点：一个前锋可能很难找到空间，机会不多，后腰两侧薄弱。";
        QTreeWidgetItem *yd3 = new QTreeWidgetItem(YouDian3);
        FTTO->addChild(yd3);
        QTreeWidgetItem *qd3= new QTreeWidgetItem(QueDian3);
        FTTO->addChild(qd3);

        QStringList YouDian4;
        YouDian4<<"优点：出色的进攻宽度，强大的中场核心。";
        QStringList QueDian4;
        QueDian4<<"缺点：球员素质要求高，高度依赖边锋的能力。";
        QTreeWidgetItem *yd4 = new QTreeWidgetItem(YouDian4);
        FTT->addChild(yd4);
        QTreeWidgetItem *qd4 = new QTreeWidgetItem(QueDian4);
        FTT->addChild(qd4);

        QStringList YouDian5;
        YouDian5<<"优点：超强的反击力，两名锋线肆虐对手防线。";
        QStringList QueDian5;
        QueDian5<<"缺点：三后卫压力大，需要一个高速的中后卫和积极的边锋。";
        QTreeWidgetItem *yd5 = new QTreeWidgetItem(YouDian5);
        TFOT->addChild(yd5);
        QTreeWidgetItem *qd5 = new QTreeWidgetItem(QueDian5);
        TFOT->addChild(qd5);

        QStringList YouDian6;
        YouDian6<<"优点：支配球出色，优秀的中场深度。";
        QStringList QueDian6;
        QueDian6<<"缺点：宽度不足，两翼容易暴露，反击一般。";
        QTreeWidgetItem *yd6 = new QTreeWidgetItem(YouDian6);
        FOTOT->addChild(yd6);
        QTreeWidgetItem *qd6= new QTreeWidgetItem(QueDian6);
        FOTOT->addChild(qd6);
    }

    //"阵容训练"按钮
    connect(ui->teamTrain,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(10);
    });

    //"阵容训练"页面内"开始训练"按钮
    connect(ui->teamTrainComplete,&QPushButton::clicked,[=](){
        if (ui->radioButton->isChecked())
        {
            teamTrain = QString("4-2-2-2");
        }
        if (ui->radioButton_2->isChecked())
        {
            teamTrain = QString("3-5-2");
        }
        if (ui->radioButton_3->isChecked())
        {
            teamTrain = QString("4-2-3-1");
        }
        if (ui->radioButton_4->isChecked())
        {
            teamTrain = QString("4-3-3");
        }
        if (ui->radioButton_5->isChecked())
        {
            teamTrain = QString("3-4-1-2");
        }
        if (ui->radioButton_6->isChecked())
        {
            teamTrain = QString("4-1-2-1-2");
        }
        qDebug()<<"teamTrain:"<<teamTrain;
        if (teamTrain == QString(""))
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("教练，您还没有选择训练阵容\n请选择"),QMessageBox::Ok);
        }
        else
        {
            int a = QMessageBox::information(this,QString("训练结果"),QString("教练，您的队伍已经完成阵容训练"),QMessageBox::Ok);
            ui->stackedWidget->setCurrentIndex(9);
        }
    });

    //"门将训练"页面内容
    {
        //给treeWidget_6添加按需出现的水平滚动条
        ui->treeWidget_6->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->treeWidget_6->header()->setStretchLastSection(false);

        ui->treeWidget_6->setHeaderLabels(QStringList()<<"门将个人训练选择");
        QTreeWidgetItem *zuoyouyidong = new QTreeWidgetItem(QStringList()<<"左右移动接球");
        QTreeWidgetItem *shangxiajieqiu = new QTreeWidgetItem(QStringList()<<"上下接球训练");
        QTreeWidgetItem *hengchuanmenjiang = new QTreeWidgetItem(QStringList()<<"横穿门将训练");
        QTreeWidgetItem *qianmenzhufantan = new QTreeWidgetItem(QStringList()<<"前门柱反弹训练");
        QTreeWidgetItem *liangcijieqiu = new QTreeWidgetItem(QStringList()<<"两次接球训练");
        QTreeWidgetItem *fengduqianmenzhu = new QTreeWidgetItem(QStringList()<<"封堵前门柱射门训练");
        QTreeWidgetItem *faqiu = new QTreeWidgetItem(QStringList()<<"发球训练");
        ui->treeWidget_6->addTopLevelItem(zuoyouyidong);
        ui->treeWidget_6->addTopLevelItem(shangxiajieqiu);
        ui->treeWidget_6->addTopLevelItem(hengchuanmenjiang);
        ui->treeWidget_6->addTopLevelItem(qianmenzhufantan);
        ui->treeWidget_6->addTopLevelItem(liangcijieqiu);
        ui->treeWidget_6->addTopLevelItem(fengduqianmenzhu);
        ui->treeWidget_6->addTopLevelItem(faqiu);
    }

    //"门将训练"按钮
    connect(ui->goalKeeperTrain,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(11);
    });

    //"门将训练"页面内"开始训练"按钮
    connect(ui->goalKeeperTrainComplete,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        if(ui->checkBox_101->isChecked())
        {
            ckBoxSum++;
            if (gkTrain1 == QString(""))
                gkTrain1 = QString("左右移动接球");
            else if (gkTrain2 == QString(""))
                gkTrain2 = QString("左右移动接球");
            else if (gkTrain3 == QString(""))
                gkTrain3 = QString("左右移动接球");
        }
        if(ui->checkBox_102->isChecked())
        {
            ckBoxSum++;
            if (gkTrain1 == QString(""))
                gkTrain1 = QString("上下接球训练");
            else if (gkTrain2 == QString(""))
                gkTrain2 = QString("上下接球训练");
            else if (gkTrain3 == QString(""))
                gkTrain3 = QString("上下接球训练");
        }
        if(ui->checkBox_103->isChecked())
        {
            ckBoxSum++;
            if (gkTrain1 == QString(""))
                gkTrain1 = QString("横穿门将训练");
            else if (gkTrain2 == QString(""))
                gkTrain2 = QString("横穿门将训练");
            else if (gkTrain3 == QString(""))
                gkTrain3 = QString("横穿门将训练");
        }
        if(ui->checkBox_104->isChecked())
        {
            ckBoxSum++;
            if (gkTrain1 == QString(""))
                gkTrain1 = QString("前门柱反弹训练");
            else if (gkTrain2 == QString(""))
                gkTrain2 = QString("前门柱反弹训练");
            else if (gkTrain3 == QString(""))
                gkTrain3 = QString("前门柱反弹训练");
        }
        if(ui->checkBox_105->isChecked())
        {
            ckBoxSum++;
            if (gkTrain1 == QString(""))
                gkTrain1 = QString("两次接球训练");
            else if (gkTrain2 == QString(""))
                gkTrain2 = QString("两次接球训练");
            else if (gkTrain3 == QString(""))
                gkTrain3 = QString("两次接球训练");
        }
        if(ui->checkBox_106->isChecked())
        {
            ckBoxSum++;
            if (gkTrain1 == QString(""))
                gkTrain1 = QString("封堵前门柱射门训练");
            else if (gkTrain2 == QString(""))
                gkTrain2 = QString("封堵前门柱射门训练");
            else if (gkTrain3 == QString(""))
                gkTrain3 = QString("封堵前门柱射门训练");
        }
        if(ui->checkBox_107->isChecked())
        {
            ckBoxSum++;
            if (gkTrain1 == QString(""))
                gkTrain1 = QString("发球训练");
            else if (gkTrain2 == QString(""))
                gkTrain2 = QString("发球训练");
            else if (gkTrain3 == QString(""))
                gkTrain3 = QString("发球训练");
        }
        qDebug()<<"gkTrain1:"<<gkTrain1;
        qDebug()<<"gkTrain2:"<<gkTrain2;
        qDebug()<<"gkTrain3:"<<gkTrain3;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        if (ckBoxSum > 3)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择3种训练方式\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_101->setCheckState(Qt::Unchecked);
                ui->checkBox_101->setChecked(false);
                ui->checkBox_102->setCheckState(Qt::Unchecked);
                ui->checkBox_102->setChecked(false);
                ui->checkBox_103->setCheckState(Qt::Unchecked);
                ui->checkBox_103->setChecked(false);
                ui->checkBox_104->setCheckState(Qt::Unchecked);
                ui->checkBox_104->setChecked(false);
                ui->checkBox_105->setCheckState(Qt::Unchecked);
                ui->checkBox_105->setChecked(false);
                ui->checkBox_106->setCheckState(Qt::Unchecked);
                ui->checkBox_106->setChecked(false);
                ui->checkBox_107->setCheckState(Qt::Unchecked);
                ui->checkBox_107->setChecked(false);
                gkTrain1=QString("");
                gkTrain2=QString("");
                gkTrain3=QString("");
                ckBoxSum = 0;
                qDebug()<<"gkTrain1:"<<gkTrain1;
                qDebug()<<"gkTrain2:"<<gkTrain2;
                qDebug()<<"gkTrain3:"<<gkTrain3;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else if (ckBoxSum < 3)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的训练方式不足3种\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_101->setCheckState(Qt::Unchecked);
                ui->checkBox_101->setChecked(false);
                ui->checkBox_102->setCheckState(Qt::Unchecked);
                ui->checkBox_102->setChecked(false);
                ui->checkBox_103->setCheckState(Qt::Unchecked);
                ui->checkBox_103->setChecked(false);
                ui->checkBox_104->setCheckState(Qt::Unchecked);
                ui->checkBox_104->setChecked(false);
                ui->checkBox_105->setCheckState(Qt::Unchecked);
                ui->checkBox_105->setChecked(false);
                ui->checkBox_106->setCheckState(Qt::Unchecked);
                ui->checkBox_106->setChecked(false);
                ui->checkBox_107->setCheckState(Qt::Unchecked);
                ui->checkBox_107->setChecked(false);
                gkTrain1=QString("");
                gkTrain2=QString("");
                gkTrain3=QString("");
                ckBoxSum = 0;
                qDebug()<<"gkTrain1:"<<gkTrain1;
                qDebug()<<"gkTrain2:"<<gkTrain2;
                qDebug()<<"gkTrain3:"<<gkTrain3;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else
        {
            int a = QMessageBox::information(this,QString("训练结果"),QString("教练，您的门将已经按照您的要求完成了训练"),QMessageBox::Ok);
            ui->checkBox_101->setCheckState(Qt::Unchecked);
            ui->checkBox_101->setChecked(false);
            ui->checkBox_102->setCheckState(Qt::Unchecked);
            ui->checkBox_102->setChecked(false);
            ui->checkBox_103->setCheckState(Qt::Unchecked);
            ui->checkBox_103->setChecked(false);
            ui->checkBox_104->setCheckState(Qt::Unchecked);
            ui->checkBox_104->setChecked(false);
            ui->checkBox_105->setCheckState(Qt::Unchecked);
            ui->checkBox_105->setChecked(false);
            ui->checkBox_106->setCheckState(Qt::Unchecked);
            ui->checkBox_106->setChecked(false);
            ui->checkBox_107->setCheckState(Qt::Unchecked);
            ui->checkBox_107->setChecked(false);
            ui->stackedWidget->setCurrentIndex(9);
        }
    });

    //"前锋训练"页面内容
    {
        //给treeWidget_7添加按需出现的水平滚动条
        ui->treeWidget_7->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->treeWidget_7->header()->setStretchLastSection(false);

        ui->treeWidget_7->setHeaderLabels(QStringList()<<"前锋个人训练选择");
        QTreeWidgetItem *banzhuanshen = new QTreeWidgetItem(QStringList()<<"半转身训练");
        QTreeWidgetItem *qiantui = new QTreeWidgetItem(QStringList()<<"前推训练");
        QTreeWidgetItem *zhuanshenshemen = new QTreeWidgetItem(QStringList()<<"转身射门训练");
        QTreeWidgetItem *erguoyi = new QTreeWidgetItem(QStringList()<<"二过一配合射门");
        QTreeWidgetItem *bufa = new QTreeWidgetItem(QStringList()<<"步法练习");
        ui->treeWidget_7->addTopLevelItem(banzhuanshen);
        ui->treeWidget_7->addTopLevelItem(qiantui);
        ui->treeWidget_7->addTopLevelItem(zhuanshenshemen);
        ui->treeWidget_7->addTopLevelItem(erguoyi);
        ui->treeWidget_7->addTopLevelItem(bufa);
    }

    //"前锋训练"按钮
    connect(ui->forwardTrain,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(12);
    });

    //"前锋训练"页面内"开始训练"按钮
    connect(ui->forwardTrainComplete,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        if(ui->checkBox_108->isChecked())
        {
            ckBoxSum++;
            if (forTrain1 == QString(""))
                forTrain1 = QString("半转身训练");
            else if (forTrain2 == QString(""))
                forTrain2 = QString("半转身训练");
        }
        if(ui->checkBox_109->isChecked())
        {
            ckBoxSum++;
            if (forTrain1 == QString(""))
                forTrain1 = QString("前推训练");
            else if (forTrain2 == QString(""))
                forTrain2 = QString("前推训练");
        }
        if(ui->checkBox_110->isChecked())
        {
            ckBoxSum++;
            if (forTrain1 == QString(""))
                forTrain1 = QString("转身射门训练");
            else if (forTrain2 == QString(""))
                forTrain2 = QString("转身射门训练");
        }
        if(ui->checkBox_111->isChecked())
        {
            ckBoxSum++;
            if (forTrain1 == QString(""))
                forTrain1 = QString("二过一配合射门");
            else if (forTrain2 == QString(""))
                forTrain2 = QString("二过一配合射门");
        }
        if(ui->checkBox_112->isChecked())
        {
            ckBoxSum++;
            if (forTrain1 == QString(""))
                forTrain1 = QString("步法练习");
            else if (forTrain2 == QString(""))
                forTrain2 = QString("步法练习");
        }
        qDebug()<<"forTrain1:"<<forTrain1;
        qDebug()<<"forTrain2:"<<forTrain2;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        if (ckBoxSum > 2)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择2种训练方式\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_108->setCheckState(Qt::Unchecked);
                ui->checkBox_108->setChecked(false);
                ui->checkBox_109->setCheckState(Qt::Unchecked);
                ui->checkBox_109->setChecked(false);
                ui->checkBox_110->setCheckState(Qt::Unchecked);
                ui->checkBox_110->setChecked(false);
                ui->checkBox_111->setCheckState(Qt::Unchecked);
                ui->checkBox_111->setChecked(false);
                ui->checkBox_112->setCheckState(Qt::Unchecked);
                ui->checkBox_112->setChecked(false);
                forTrain1=QString("");
                forTrain2=QString("");
                ckBoxSum = 0;
                qDebug()<<"forTrain1:"<<forTrain1;
                qDebug()<<"forTrain2:"<<forTrain2;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else if (ckBoxSum < 2)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的训练方式不足2种\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_108->setCheckState(Qt::Unchecked);
                ui->checkBox_108->setChecked(false);
                ui->checkBox_109->setCheckState(Qt::Unchecked);
                ui->checkBox_109->setChecked(false);
                ui->checkBox_110->setCheckState(Qt::Unchecked);
                ui->checkBox_110->setChecked(false);
                ui->checkBox_111->setCheckState(Qt::Unchecked);
                ui->checkBox_111->setChecked(false);
                ui->checkBox_112->setCheckState(Qt::Unchecked);
                ui->checkBox_112->setChecked(false);
                forTrain1=QString("");
                forTrain2=QString("");
                ckBoxSum = 0;
                qDebug()<<"forTrain1:"<<forTrain1;
                qDebug()<<"forTrain2:"<<forTrain2;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else
        {
            int a = QMessageBox::information(this,QString("训练结果"),QString("教练，您的前锋已经按照您的要求完成了训练"),QMessageBox::Ok);
            ui->checkBox_108->setCheckState(Qt::Unchecked);
            ui->checkBox_108->setChecked(false);
            ui->checkBox_109->setCheckState(Qt::Unchecked);
            ui->checkBox_109->setChecked(false);
            ui->checkBox_110->setCheckState(Qt::Unchecked);
            ui->checkBox_110->setChecked(false);
            ui->checkBox_111->setCheckState(Qt::Unchecked);
            ui->checkBox_111->setChecked(false);
            ui->checkBox_112->setCheckState(Qt::Unchecked);
            ui->checkBox_112->setChecked(false);
            ui->stackedWidget->setCurrentIndex(9);
        }
    });

    //"中场训练"页面内容
    {
        //给treeWidget_8添加按需出现的水平滚动条
        ui->treeWidget_8->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->treeWidget_8->header()->setStretchLastSection(false);

        ui->treeWidget_8->setHeaderLabels(QStringList()<<"中场个人训练选择");
        QTreeWidgetItem *dongtai = new QTreeWidgetItem(QStringList()<<"动态传接球训练");
        QTreeWidgetItem *fangshoutouqiu = new QTreeWidgetItem(QStringList()<<"防守型头球训练");
        QTreeWidgetItem *qiezhanqietui = new QTreeWidgetItem(QStringList()<<"1V1且战且退训练");
        QTreeWidgetItem *shiye = new QTreeWidgetItem(QStringList()<<"视野训练");
        QTreeWidgetItem *bufaxunlian = new QTreeWidgetItem(QStringList()<<"步法训练");
        ui->treeWidget_8->addTopLevelItem(dongtai);
        ui->treeWidget_8->addTopLevelItem(fangshoutouqiu);
        ui->treeWidget_8->addTopLevelItem(qiezhanqietui);
        ui->treeWidget_8->addTopLevelItem(shiye);
        ui->treeWidget_8->addTopLevelItem(bufaxunlian);
    }

    //"中场训练"按钮
    connect(ui->midFieldTrain,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(13);
    });

    //"中场训练"页面内"开始训练"按钮
    connect(ui->midTrainComplete,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        if(ui->checkBox_113->isChecked())
        {
            ckBoxSum++;
            if (midTrain1 == QString(""))
                midTrain1 = QString("动态传接球训练");
            else if (midTrain2 == QString(""))
                midTrain2 = QString("动态传接球训练");
        }
        if(ui->checkBox_114->isChecked())
        {
            ckBoxSum++;
            if (midTrain1 == QString(""))
                midTrain1 = QString("防守型头球训练");
            else if (midTrain2 == QString(""))
                midTrain2 = QString("防守型头球训练");
        }
        if(ui->checkBox_115->isChecked())
        {
            ckBoxSum++;
            if (midTrain1 == QString(""))
                midTrain1 = QString("1V1且战且退训练");
            else if (midTrain2 == QString(""))
                midTrain2 = QString("1V1且战且退训练");
        }
        if(ui->checkBox_116->isChecked())
        {
            ckBoxSum++;
            if (midTrain1 == QString(""))
                midTrain1 = QString("视野训练");
            else if (midTrain2 == QString(""))
                midTrain2 = QString("视野训练");
        }
        if(ui->checkBox_117->isChecked())
        {
            ckBoxSum++;
            if (midTrain1 == QString(""))
                midTrain1 = QString("步法训练");
            else if (midTrain2 == QString(""))
                midTrain2 = QString("步法训练");
        }
        qDebug()<<"midTrain1:"<<midTrain1;
        qDebug()<<"midTrain2:"<<midTrain2;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        if (ckBoxSum > 2)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择2种训练方式\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_113->setCheckState(Qt::Unchecked);
                ui->checkBox_113->setChecked(false);
                ui->checkBox_114->setCheckState(Qt::Unchecked);
                ui->checkBox_114->setChecked(false);
                ui->checkBox_115->setCheckState(Qt::Unchecked);
                ui->checkBox_115->setChecked(false);
                ui->checkBox_116->setCheckState(Qt::Unchecked);
                ui->checkBox_116->setChecked(false);
                ui->checkBox_117->setCheckState(Qt::Unchecked);
                ui->checkBox_117->setChecked(false);
                midTrain1=QString("");
                midTrain2=QString("");
                ckBoxSum = 0;
                qDebug()<<"midTrain1:"<<midTrain1;
                qDebug()<<"midTrain2:"<<midTrain2;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else if (ckBoxSum < 2)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的训练方式不足2种\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_113->setCheckState(Qt::Unchecked);
                ui->checkBox_113->setChecked(false);
                ui->checkBox_114->setCheckState(Qt::Unchecked);
                ui->checkBox_114->setChecked(false);
                ui->checkBox_115->setCheckState(Qt::Unchecked);
                ui->checkBox_115->setChecked(false);
                ui->checkBox_116->setCheckState(Qt::Unchecked);
                ui->checkBox_116->setChecked(false);
                ui->checkBox_117->setCheckState(Qt::Unchecked);
                ui->checkBox_117->setChecked(false);
                midTrain1=QString("");
                midTrain2=QString("");
                ckBoxSum = 0;
                qDebug()<<"midTrain1:"<<midTrain1;
                qDebug()<<"midTrain2:"<<midTrain2;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else
        {
            int a = QMessageBox::information(this,QString("训练结果"),QString("教练，您的中场已经按照您的要求完成了训练"),QMessageBox::Ok);
            ui->checkBox_113->setCheckState(Qt::Unchecked);
            ui->checkBox_113->setChecked(false);
            ui->checkBox_114->setCheckState(Qt::Unchecked);
            ui->checkBox_114->setChecked(false);
            ui->checkBox_115->setCheckState(Qt::Unchecked);
            ui->checkBox_115->setChecked(false);
            ui->checkBox_116->setCheckState(Qt::Unchecked);
            ui->checkBox_116->setChecked(false);
            ui->checkBox_117->setCheckState(Qt::Unchecked);
            ui->checkBox_117->setChecked(false);
            ui->stackedWidget->setCurrentIndex(9);
        }
    });

    //"后卫训练"页面内容
    {
        ui->treeWidget_9->setHeaderLabels(QStringList()<<"后卫个人训练选择");
        QTreeWidgetItem *bufaxun = new QTreeWidgetItem(QStringList()<<"步法训练");
        QTreeWidgetItem *liliang = new QTreeWidgetItem(QStringList()<<"力量训练");
        QTreeWidgetItem *zuzhijingong = new QTreeWidgetItem(QStringList()<<"后场组织进攻训练");
        QTreeWidgetItem *houfang = new QTreeWidgetItem(QStringList()<<"后防协作训练");
        QTreeWidgetItem *changchuan= new QTreeWidgetItem(QStringList()<<"长传训练");
        QTreeWidgetItem *lanjie= new QTreeWidgetItem(QStringList()<<"拦截能力训练");
        ui->treeWidget_9->addTopLevelItem(bufaxun);
        ui->treeWidget_9->addTopLevelItem(liliang);
        ui->treeWidget_9->addTopLevelItem(zuzhijingong);
        ui->treeWidget_9->addTopLevelItem(houfang);
        ui->treeWidget_9->addTopLevelItem(changchuan);
        ui->treeWidget_9->addTopLevelItem(lanjie);
    }

    //"后卫训练"按钮
    connect(ui->backTrain,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(14);
    });

    //"后卫训练"页面内"开始训练"按钮
    connect(ui->backTrainComplete,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        if(ui->checkBox_118->isChecked())
        {
            ckBoxSum++;
            if (backTrain1 == QString(""))
                backTrain1 = QString("步法训练");
            else if (backTrain2 == QString(""))
                backTrain2 = QString("步法训练");
        }
        if(ui->checkBox_119->isChecked())
        {
            ckBoxSum++;
            if (backTrain1 == QString(""))
                backTrain1 = QString("力量训练");
            else if (backTrain2 == QString(""))
                backTrain2 = QString("力量训练");
        }
        if(ui->checkBox_120->isChecked())
        {
            ckBoxSum++;
            if (backTrain1 == QString(""))
                backTrain1 = QString("后场组织进攻训练");
            else if (backTrain2 == QString(""))
                backTrain2 = QString("后场组织进攻训练");
        }
        if(ui->checkBox_121->isChecked())
        {
            ckBoxSum++;
            if (backTrain1 == QString(""))
                backTrain1 = QString("后防协作训练");
            else if (backTrain2 == QString(""))
                backTrain2 = QString("后防协作训练");
        }
        if(ui->checkBox_122->isChecked())
        {
            ckBoxSum++;
            if (backTrain1 == QString(""))
                backTrain1 = QString("长传训练");
            else if (backTrain2 == QString(""))
                backTrain2 = QString("长传训练");
        }
        if(ui->checkBox_123->isChecked())
        {
            ckBoxSum++;
            if (backTrain1 == QString(""))
                backTrain1 = QString("拦截能力训练");
            else if (backTrain2 == QString(""))
                backTrain2 = QString("拦截能力训练");
        }

        qDebug()<<"backTrain1:"<<backTrain1;
        qDebug()<<"backTrain2:"<<backTrain2;
        qDebug()<<"ckBoxSum:"<<ckBoxSum;
        if (ckBoxSum > 2)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您只能选择2种训练方式\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_118->setCheckState(Qt::Unchecked);
                ui->checkBox_118->setChecked(false);
                ui->checkBox_119->setCheckState(Qt::Unchecked);
                ui->checkBox_119->setChecked(false);
                ui->checkBox_120->setCheckState(Qt::Unchecked);
                ui->checkBox_120->setChecked(false);
                ui->checkBox_121->setCheckState(Qt::Unchecked);
                ui->checkBox_121->setChecked(false);
                ui->checkBox_122->setCheckState(Qt::Unchecked);
                ui->checkBox_122->setChecked(false);
                ui->checkBox_123->setCheckState(Qt::Unchecked);
                ui->checkBox_123->setChecked(false);
                backTrain1=QString("");
                backTrain2=QString("");
                ckBoxSum = 0;
                qDebug()<<"backTrain1:"<<backTrain1;
                qDebug()<<"backTrain2:"<<backTrain2;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else if (ckBoxSum < 2)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("您选择的训练方式不足2种\n请重新选择"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_118->setCheckState(Qt::Unchecked);
                ui->checkBox_118->setChecked(false);
                ui->checkBox_119->setCheckState(Qt::Unchecked);
                ui->checkBox_119->setChecked(false);
                ui->checkBox_120->setCheckState(Qt::Unchecked);
                ui->checkBox_120->setChecked(false);
                ui->checkBox_121->setCheckState(Qt::Unchecked);
                ui->checkBox_121->setChecked(false);
                ui->checkBox_122->setCheckState(Qt::Unchecked);
                ui->checkBox_122->setChecked(false);
                ui->checkBox_123->setCheckState(Qt::Unchecked);
                ui->checkBox_123->setChecked(false);
                backTrain1=QString("");
                backTrain2=QString("");
                ckBoxSum = 0;
                qDebug()<<"backTrain1:"<<backTrain1;
                qDebug()<<"backTrain2:"<<backTrain2;
                qDebug()<<"ckBoxSum:"<<ckBoxSum;
            }
        }
        else
        {
            int a = QMessageBox::information(this,QString("训练结果"),QString("教练，您的后卫已经按照您的要求完成了训练"),QMessageBox::Ok);
            ui->checkBox_118->setCheckState(Qt::Unchecked);
            ui->checkBox_118->setChecked(false);
            ui->checkBox_119->setCheckState(Qt::Unchecked);
            ui->checkBox_119->setChecked(false);
            ui->checkBox_120->setCheckState(Qt::Unchecked);
            ui->checkBox_120->setChecked(false);
            ui->checkBox_121->setCheckState(Qt::Unchecked);
            ui->checkBox_121->setChecked(false);
            ui->checkBox_122->setCheckState(Qt::Unchecked);
            ui->checkBox_122->setChecked(false);
            ui->checkBox_123->setCheckState(Qt::Unchecked);
            ui->checkBox_123->setChecked(false);
            ui->stackedWidget->setCurrentIndex(9);
        }
    });

    //"返回"按钮
    connect(ui->returnBtn,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(8);
    });

//赛前新闻发布会
    connect(ui->beforeGameBtn,&QPushButton::clicked,[=](){
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%5+1;
        qDebug()<<"cas:"<<cas;
        switch (cas) {
        case 1:
        {
            uiBGD_1 = new BeforeGame1Dialog(this);
            uiBGD_1->setWindowTitle("请选择您的对话");
            uiBGD_1->show();
            uiBGD_1->exec();
        }
            break;
        case 2:
        {
            uiBGD_2 = new BeforeGame2Dialog(this);
            uiBGD_2->setWindowTitle("请选择您的对话");
            uiBGD_2->show();
            uiBGD_2->exec();
        }
            break;
        case 3:
        {
            uiBGD_3 = new BeforeGame3Dialog(this);
            uiBGD_3->setWindowTitle("请选择您的对话");
            uiBGD_3->show();
            uiBGD_3->exec();
        }
            break;
        case 4:
        {
            uiBGD_4 = new BeforeGame4Dialog(this);
            uiBGD_4->setWindowTitle("请选择您的对话");
            uiBGD_4->show();
            uiBGD_4->exec();
        }
            break;
        case 5:
        {
            uiBGD_5 = new BeforeGame5Dialog(this);
            uiBGD_5->setWindowTitle("请选择您的对话");
            uiBGD_5->show();
            uiBGD_5->exec();
        }
            break;
        default:
            break;
        }
        ui->stackedWidget->setCurrentIndex(16);
    });

//赛前准备
    //"下一步"按钮
    connect(ui->commandLinkButton,&QCommandLinkButton::clicked,[=](){
        //checkbox显示全体球员的信息
        this->setChoosePlayerName(goalKeeper1.name,goalKeeper2.name,forward1.name,forward2.name,forward3.name,
                                  forward4.name,forward5.name,forward6.name,forward7.name,midField1.name,midField2.name,
                                  midField3.name,midField4.name,midField5.name,midField6.name,midField7.name,back1.name,
                                  back2.name,back3.name,back4.name,back5.name,back6.name,back7.name);
        ui->stackedWidget->setCurrentIndex(17);
    });

    //底部导航区按钮
    {
        connect(ui->commandLinkButton_2,&QCommandLinkButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(17);
        });

        connect(ui->commandLinkButton_4,&QCommandLinkButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(19);
        });

        connect(ui->commandLinkButton_5,&QCommandLinkButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(17);
        });
        connect(ui->commandLinkButton_6,&QCommandLinkButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(18);
        });
        connect(ui->commandLinkButton_7,&QCommandLinkButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(19);
        });

        connect(ui->commandLinkButton_8,&QCommandLinkButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(17);
        });

        connect(ui->commandLinkButton_10,&QCommandLinkButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(19);
        });
    }

    //"选择上场球员"界面
    //"选好球员"按钮
    connect(ui->selectPlayersBtn,&QPushButton::clicked,[=](){
        ckBoxSum = 0;
        if(ui->checkBox_124->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = goalKeeper1;
            else if (p2 == QString(""))
                p2 = goalKeeper1;
            else if (p3 == QString(""))
                p3 = goalKeeper1;
            else if (p4 == QString(""))
                p4 = goalKeeper1;
            else if (p5 == QString(""))
                p5 = goalKeeper1;
            else if (p6 == QString(""))
                p6 = goalKeeper1;
            else if (p7 == QString(""))
                p7 = goalKeeper1;
            else if (p8 == QString(""))
                p8 = goalKeeper1;
            else if (p9 == QString(""))
                p9 = goalKeeper1;
            else if (p10 == QString(""))
                p10 = goalKeeper1;
            else if (p11 == QString(""))
                p11 = goalKeeper1;
        }
        if(ui->checkBox_125->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = goalKeeper2;
            else if (p2 == QString(""))
                p2 = goalKeeper2;
            else if (p3 == QString(""))
                p3 = goalKeeper2;
            else if (p4 == QString(""))
                p4 = goalKeeper2;
            else if (p5 == QString(""))
                p5 = goalKeeper2;
            else if (p6 == QString(""))
                p6 = goalKeeper2;
            else if (p7 == QString(""))
                p7 = goalKeeper2;
            else if (p8 == QString(""))
                p8 = goalKeeper2;
            else if (p9 == QString(""))
                p9 = goalKeeper2;
            else if (p10 == QString(""))
                p10 = goalKeeper2;
            else if (p11 == QString(""))
                p11 = goalKeeper2;
        }
        if(ui->checkBox_126->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = forward1;
            else if (p2 == QString(""))
                p2 = forward1;
            else if (p3 == QString(""))
                p3 = forward1;
            else if (p4 == QString(""))
                p4 = forward1;
            else if (p5 == QString(""))
                p5 = forward1;
            else if (p6 == QString(""))
                p6 = forward1;
            else if (p7 == QString(""))
                p7 = forward1;
            else if (p8 == QString(""))
                p8 = forward1;
            else if (p9 == QString(""))
                p9 = forward1;
            else if (p10 == QString(""))
                p10 = forward1;
            else if (p11 == QString(""))
                p11 = forward1;
        }
        if(ui->checkBox_127->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = forward2;
            else if (p2 == QString(""))
                p2 = forward2;
            else if (p3 == QString(""))
                p3 = forward2;
            else if (p4 == QString(""))
                p4 = forward2;
            else if (p5 == QString(""))
                p5 = forward2;
            else if (p6 == QString(""))
                p6 = forward2;
            else if (p7 == QString(""))
                p7 = forward2;
            else if (p8 == QString(""))
                p8 = forward2;
            else if (p9 == QString(""))
                p9 = forward2;
            else if (p10 == QString(""))
                p10 = forward2;
            else if (p11 == QString(""))
                p11 = forward2;
        }
        if(ui->checkBox_128->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = forward3;
            else if (p2 == QString(""))
                p2 = forward3;
            else if (p3 == QString(""))
                p3 = forward3;
            else if (p4 == QString(""))
                p4 = forward3;
            else if (p5 == QString(""))
                p5 = forward3;
            else if (p6 == QString(""))
                p6 = forward3;
            else if (p7 == QString(""))
                p7 = forward3;
            else if (p8 == QString(""))
                p8 = forward3;
            else if (p9 == QString(""))
                p9 = forward3;
            else if (p10 == QString(""))
                p10 = forward3;
            else if (p11 == QString(""))
                p11 = forward3;
        }
        if(ui->checkBox_129->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = forward4;
            else if (p2 == QString(""))
                p2 = forward4;
            else if (p3 == QString(""))
                p3 = forward4;
            else if (p4 == QString(""))
                p4 = forward4;
            else if (p5 == QString(""))
                p5 = forward4;
            else if (p6 == QString(""))
                p6 = forward4;
            else if (p7 == QString(""))
                p7 = forward4;
            else if (p8 == QString(""))
                p8 = forward4;
            else if (p9 == QString(""))
                p9 = forward4;
            else if (p10 == QString(""))
                p10 = forward4;
            else if (p11 == QString(""))
                p11 = forward4;
        }
        if(ui->checkBox_130->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = forward5;
            else if (p2 == QString(""))
                p2 = forward5;
            else if (p3 == QString(""))
                p3 = forward5;
            else if (p4 == QString(""))
                p4 = forward5;
            else if (p5 == QString(""))
                p5 = forward5;
            else if (p6 == QString(""))
                p6 = forward5;
            else if (p7 == QString(""))
                p7 = forward5;
            else if (p8 == QString(""))
                p8 = forward5;
            else if (p9 == QString(""))
                p9 = forward5;
            else if (p10 == QString(""))
                p10 = forward5;
            else if (p11 == QString(""))
                p11 = forward5;
        }
        if(ui->checkBox_131->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = forward6;
            else if (p2 == QString(""))
                p2 = forward6;
            else if (p3 == QString(""))
                p3 = forward6;
            else if (p4 == QString(""))
                p4 = forward6;
            else if (p5 == QString(""))
                p5 = forward6;
            else if (p6 == QString(""))
                p6 = forward6;
            else if (p7 == QString(""))
                p7 = forward6;
            else if (p8 == QString(""))
                p8 = forward6;
            else if (p9 == QString(""))
                p9 = forward6;
            else if (p10 == QString(""))
                p10 = forward6;
            else if (p11 == QString(""))
                p11 = forward6;
        }
        if(ui->checkBox_132->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = forward7;
            else if (p2 == QString(""))
                p2 = forward7;
            else if (p3 == QString(""))
                p3 = forward7;
            else if (p4 == QString(""))
                p4 = forward7;
            else if (p5 == QString(""))
                p5 = forward7;
            else if (p6 == QString(""))
                p6 = forward7;
            else if (p7 == QString(""))
                p7 = forward7;
            else if (p8 == QString(""))
                p8 = forward7;
            else if (p9 == QString(""))
                p9 = forward7;
            else if (p10 == QString(""))
                p10 = forward7;
            else if (p11 == QString(""))
                p11 = forward7;
        }
        if(ui->checkBox_133->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = midField1;
            else if (p2 == QString(""))
                p2 = midField1;
            else if (p3 == QString(""))
                p3 = midField1;
            else if (p4 == QString(""))
                p4 = midField1;
            else if (p5 == QString(""))
                p5 = midField1;
            else if (p6 == QString(""))
                p6 = midField1;
            else if (p7 == QString(""))
                p7 = midField1;
            else if (p8 == QString(""))
                p8 = midField1;
            else if (p9 == QString(""))
                p9 = midField1;
            else if (p10 == QString(""))
                p10 = midField1;
            else if (p11 == QString(""))
                p11 = midField1;
        }
        if(ui->checkBox_134->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = midField2;
            else if (p2 == QString(""))
                p2 = midField2;
            else if (p3 == QString(""))
                p3 = midField2;
            else if (p4 == QString(""))
                p4 = midField2;
            else if (p5 == QString(""))
                p5 = midField2;
            else if (p6 == QString(""))
                p6 = midField2;
            else if (p7 == QString(""))
                p7 = midField2;
            else if (p8 == QString(""))
                p8 = midField2;
            else if (p9 == QString(""))
                p9 = midField2;
            else if (p10 == QString(""))
                p10 = midField2;
            else if (p11 == QString(""))
                p11 = midField2;
        }
        if(ui->checkBox_135->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = midField3;
            else if (p2 == QString(""))
                p2 = midField3;
            else if (p3 == QString(""))
                p3 = midField3;
            else if (p4 == QString(""))
                p4 = midField3;
            else if (p5 == QString(""))
                p5 = midField3;
            else if (p6 == QString(""))
                p6 = midField3;
            else if (p7 == QString(""))
                p7 = midField3;
            else if (p8 == QString(""))
                p8 = midField3;
            else if (p9 == QString(""))
                p9 = midField3;
            else if (p10 == QString(""))
                p10 = midField3;
            else if (p11 == QString(""))
                p11 = midField3;
        }
        if(ui->checkBox_136->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = midField4;
            else if (p2 == QString(""))
                p2 = midField4;
            else if (p3 == QString(""))
                p3 = midField4;
            else if (p4 == QString(""))
                p4 = midField4;
            else if (p5 == QString(""))
                p5 = midField4;
            else if (p6 == QString(""))
                p6 = midField4;
            else if (p7 == QString(""))
                p7 = midField4;
            else if (p8 == QString(""))
                p8 = midField4;
            else if (p9 == QString(""))
                p9 = midField4;
            else if (p10 == QString(""))
                p10 = midField4;
            else if (p11 == QString(""))
                p11 = midField4;
        }
        if(ui->checkBox_137->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = midField5;
            else if (p2 == QString(""))
                p2 = midField5;
            else if (p3 == QString(""))
                p3 = midField5;
            else if (p4 == QString(""))
                p4 = midField5;
            else if (p5 == QString(""))
                p5 = midField5;
            else if (p6 == QString(""))
                p6 = midField5;
            else if (p7 == QString(""))
                p7 = midField5;
            else if (p8 == QString(""))
                p8 = midField5;
            else if (p9 == QString(""))
                p9 = midField5;
            else if (p10 == QString(""))
                p10 = midField5;
            else if (p11 == QString(""))
                p11 = midField5;
        }
        if(ui->checkBox_138->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = midField6;
            else if (p2 == QString(""))
                p2 = midField6;
            else if (p3 == QString(""))
                p3 = midField6;
            else if (p4 == QString(""))
                p4 = midField6;
            else if (p5 == QString(""))
                p5 = midField6;
            else if (p6 == QString(""))
                p6 = midField6;
            else if (p7 == QString(""))
                p7 = midField6;
            else if (p8 == QString(""))
                p8 = midField6;
            else if (p9 == QString(""))
                p9 = midField6;
            else if (p10 == QString(""))
                p10 = midField6;
            else if (p11 == QString(""))
                p11 = midField6;
        }
        if(ui->checkBox_139->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = midField7;
            else if (p2 == QString(""))
                p2 = midField7;
            else if (p3 == QString(""))
                p3 = midField7;
            else if (p4 == QString(""))
                p4 = midField7;
            else if (p5 == QString(""))
                p5 = midField7;
            else if (p6 == QString(""))
                p6 = midField7;
            else if (p7 == QString(""))
                p7 = midField7;
            else if (p8 == QString(""))
                p8 = midField7;
            else if (p9 == QString(""))
                p9 = midField7;
            else if (p10 == QString(""))
                p10 = midField7;
            else if (p11 == QString(""))
                p11 = midField7;
        }
        if(ui->checkBox_140->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = back1;
            else if (p2 == QString(""))
                p2 = back1;
            else if (p3 == QString(""))
                p3 = back1;
            else if (p4 == QString(""))
                p4 = back1;
            else if (p5 == QString(""))
                p5 = back1;
            else if (p6 == QString(""))
                p6 = back1;
            else if (p7 == QString(""))
                p7 = back1;
            else if (p8 == QString(""))
                p8 = back1;
            else if (p9 == QString(""))
                p9 = back1;
            else if (p10 == QString(""))
                p10 = back1;
            else if (p11 == QString(""))
                p11 = back1;
        }
        if(ui->checkBox_141->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = back2;
            else if (p2 == QString(""))
                p2 = back2;
            else if (p3 == QString(""))
                p3 = back2;
            else if (p4 == QString(""))
                p4 = back2;
            else if (p5 == QString(""))
                p5 = back2;
            else if (p6 == QString(""))
                p6 = back2;
            else if (p7 == QString(""))
                p7 = back2;
            else if (p8 == QString(""))
                p8 = back2;
            else if (p9 == QString(""))
                p9 = back2;
            else if (p10 == QString(""))
                p10 = back2;
            else if (p11 == QString(""))
                p11 = back2;
        }
        if(ui->checkBox_142->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = back3;
            else if (p2 == QString(""))
                p2 = back3;
            else if (p3 == QString(""))
                p3 = back3;
            else if (p4 == QString(""))
                p4 = back3;
            else if (p5 == QString(""))
                p5 = back3;
            else if (p6 == QString(""))
                p6 = back3;
            else if (p7 == QString(""))
                p7 = back3;
            else if (p8 == QString(""))
                p8 = back3;
            else if (p9 == QString(""))
                p9 = back3;
            else if (p10 == QString(""))
                p10 = back3;
            else if (p11 == QString(""))
                p11 = back3;
        }
        if(ui->checkBox_143->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = back4;
            else if (p2 == QString(""))
                p2 = back4;
            else if (p3 == QString(""))
                p3 = back4;
            else if (p4 == QString(""))
                p4 = back4;
            else if (p5 == QString(""))
                p5 = back4;
            else if (p6 == QString(""))
                p6 = back4;
            else if (p7 == QString(""))
                p7 = back4;
            else if (p8 == QString(""))
                p8 = back4;
            else if (p9 == QString(""))
                p9 = back4;
            else if (p10 == QString(""))
                p10 = back4;
            else if (p11 == QString(""))
                p11 = back4;
        }
        if(ui->checkBox_144->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = back5;
            else if (p2 == QString(""))
                p2 = back5;
            else if (p3 == QString(""))
                p3 = back5;
            else if (p4 == QString(""))
                p4 = back5;
            else if (p5 == QString(""))
                p5 = back5;
            else if (p6 == QString(""))
                p6 = back5;
            else if (p7 == QString(""))
                p7 = back5;
            else if (p8 == QString(""))
                p8 = back5;
            else if (p9 == QString(""))
                p9 = back5;
            else if (p10 == QString(""))
                p10 = back5;
            else if (p11 == QString(""))
                p11 = back5;
        }
        if(ui->checkBox_145->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = back6;
            else if (p2 == QString(""))
                p2 = back6;
            else if (p3 == QString(""))
                p3 = back6;
            else if (p4 == QString(""))
                p4 = back6;
            else if (p5 == QString(""))
                p5 = back6;
            else if (p6 == QString(""))
                p6 = back6;
            else if (p7 == QString(""))
                p7 = back6;
            else if (p8 == QString(""))
                p8 = back6;
            else if (p9 == QString(""))
                p9 = back6;
            else if (p10 == QString(""))
                p10 = back6;
            else if (p11 == QString(""))
                p11 = back6;
        }
        if(ui->checkBox_146->isChecked())
        {
            ckBoxSum++;
            if (p1 == QString(""))
                p1 = back7;
            else if (p2 == QString(""))
                p2 = back7;
            else if (p3 == QString(""))
                p3 = back7;
            else if (p4 == QString(""))
                p4 = back7;
            else if (p5 == QString(""))
                p5 = back7;
            else if (p6 == QString(""))
                p6 = back7;
            else if (p7 == QString(""))
                p7 = back7;
            else if (p8 == QString(""))
                p8 = back7;
            else if (p9 == QString(""))
                p9 = back7;
            else if (p10 == QString(""))
                p10 = back7;
            else if (p11 == QString(""))
                p11 = back7;
        }

        if (ckBoxSum != 11)
        {
            int a = QMessageBox::warning(this,QString("注意"),QString("教练，请您选择11个上场球员"),QMessageBox::Ok);
            if (a == QMessageBox::Ok)
            {
                ui->checkBox_124->setChecked(false);
                ui->checkBox_124->setCheckState(Qt::Unchecked);
                ui->checkBox_125->setChecked(false);
                ui->checkBox_125->setCheckState(Qt::Unchecked);
                ui->checkBox_126->setChecked(false);
                ui->checkBox_126->setCheckState(Qt::Unchecked);
                ui->checkBox_127->setChecked(false);
                ui->checkBox_127->setCheckState(Qt::Unchecked);
                ui->checkBox_128->setChecked(false);
                ui->checkBox_128->setCheckState(Qt::Unchecked);
                ui->checkBox_129->setChecked(false);
                ui->checkBox_129->setCheckState(Qt::Unchecked);
                ui->checkBox_130->setChecked(false);
                ui->checkBox_130->setCheckState(Qt::Unchecked);
                ui->checkBox_131->setChecked(false);
                ui->checkBox_131->setCheckState(Qt::Unchecked);
                ui->checkBox_132->setChecked(false);
                ui->checkBox_132->setCheckState(Qt::Unchecked);
                ui->checkBox_133->setChecked(false);
                ui->checkBox_133->setCheckState(Qt::Unchecked);
                ui->checkBox_134->setChecked(false);
                ui->checkBox_134->setCheckState(Qt::Unchecked);
                ui->checkBox_135->setChecked(false);
                ui->checkBox_135->setCheckState(Qt::Unchecked);
                ui->checkBox_136->setChecked(false);
                ui->checkBox_136->setCheckState(Qt::Unchecked);
                ui->checkBox_137->setChecked(false);
                ui->checkBox_137->setCheckState(Qt::Unchecked);
                ui->checkBox_138->setChecked(false);
                ui->checkBox_138->setCheckState(Qt::Unchecked);
                ui->checkBox_139->setChecked(false);
                ui->checkBox_139->setCheckState(Qt::Unchecked);
                ui->checkBox_140->setChecked(false);
                ui->checkBox_140->setCheckState(Qt::Unchecked);
                ui->checkBox_141->setChecked(false);
                ui->checkBox_141->setCheckState(Qt::Unchecked);
                ui->checkBox_142->setChecked(false);
                ui->checkBox_142->setCheckState(Qt::Unchecked);
                ui->checkBox_143->setChecked(false);
                ui->checkBox_143->setCheckState(Qt::Unchecked);
                ui->checkBox_144->setChecked(false);
                ui->checkBox_144->setCheckState(Qt::Unchecked);
                ui->checkBox_145->setChecked(false);
                ui->checkBox_145->setCheckState(Qt::Unchecked);
                ui->checkBox_146->setChecked(false);
                ui->checkBox_146->setCheckState(Qt::Unchecked);
            }
        }
        else
        {
            p[0] = p1;
            p[1] = p2;
            p[2] = p3;
            p[3] = p4;
            p[4] = p5;
            p[5] = p6;
            p[6] = p7;
            p[7] = p8;
            p[8] = p9;
            p[9] = p10;
            p[10] = p11;
            for (int i=0;i<11;i++)
            {
                qDebug()<<"p"<<i<<":"<<p[i];
            }
            ui->stackedWidget->setCurrentIndex(18);
        }
    });

    //"选择阵型"界面
    {
        connect(ui->formationConfirmBtn,&QPushButton::clicked,[=](){
            if (ui->radioButton_7->isChecked())
            {
                formatConfirm = QString("4-2-2-2");
            }
            else if (ui->radioButton_8->isChecked())
            {
                formatConfirm = QString("3-5-2");
            }
            else if (ui->radioButton_9->isChecked())
            {
                formatConfirm = QString("4-2-3-1");
            }
            else if (ui->radioButton_10->isChecked())
            {
                formatConfirm = QString("4-3-3");
            }
            else if (ui->radioButton_11->isChecked())
            {
                formatConfirm = QString("3-4-1-2");
            }
            else if (ui->radioButton_12->isChecked())
            {
                formatConfirm = QString("4-1-2-1-2");
            }
            if (teamTrain != formatConfirm)
            {
                int a = QMessageBox::warning(this,QString("注意"),QString("你所选的阵型目前球队并没有得到足够的训练\n是否继续？"),QMessageBox::Cancel|QMessageBox::Ok);
                if (a == QMessageBox::Cancel)
                {
                    ui->radioButton_7->setChecked(false);
                    ui->radioButton_8->setChecked(false);
                    ui->radioButton_9->setChecked(false);
                    ui->radioButton_10->setChecked(false);
                    ui->radioButton_11->setChecked(false);
                    ui->radioButton_12->setChecked(false);
                }
                else
                {
                    ui->stackedWidget->setCurrentIndex(20);
                }
            }
            else
            {
                ui->stackedWidget->setCurrentIndex(20);
            }
        });
    }

//比赛开始
    timer0 = new QTimer(this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    timer_myGoal_1 = new QTimer(this);
    timer_myGoal_2 = new QTimer(this);
    timer_myGoal_3 = new QTimer(this);
    timer_myGoal_4 = new QTimer(this);
    timer_oppGoal_1 = new QTimer(this);
    timer_oppGoal_2 = new QTimer(this);
    timer_oppGoal_3 = new QTimer(this);
    timer_oppGoal_4 = new QTimer(this);
    timer_ownGoal = new QTimer(this);
    timer_talk = new QTimer(this);
    uiMTD = new midTalkDialog(this);
    uicurrentCommand = new currentCommandDialog(this);
    uicurrentCommand->setWindowTitle(QString("实时喊话"));
    uiCFD = new changeFormationDialog(this);
    uiCFD->setWindowTitle(QString("改变阵型"));

    connect(timer0,&QTimer::timeout,this,&MainWindow::bar);
    connect(timer1,&QTimer::timeout,this,&MainWindow::gameFinish);
    connect(timer2,&QTimer::timeout,this,&MainWindow::randomYellow);
    connect(timer3,&QTimer::timeout,this,&MainWindow::randomRed);
    connect(timer_myGoal_1,&QTimer::timeout,this,&MainWindow::mygoal_30min);
    connect(timer_myGoal_2,&QTimer::timeout,this,&MainWindow::mygoal_41min);
    connect(timer_myGoal_3,&QTimer::timeout,this,&MainWindow::mygoal_60min);
    connect(timer_myGoal_4,&QTimer::timeout,this,&MainWindow::mygoal_85min);
    connect(timer_oppGoal_1,&QTimer::timeout,this,&MainWindow::oppgoal_1);
    connect(timer_oppGoal_2,&QTimer::timeout,this,&MainWindow::oppgoal_2);
    connect(timer_oppGoal_3,&QTimer::timeout,this,&MainWindow::oppgoal_3);
    connect(timer_oppGoal_4,&QTimer::timeout,this,&MainWindow::oppgoal_4);
    connect(timer_ownGoal,&QTimer::timeout,this,&MainWindow::ownGoal);
    connect(timer_talk,&QTimer::timeout,this,&MainWindow::talk);

    timer0->setInterval(1000);//每秒改动进度条的数值
    timer1->setInterval(61000);//下半场61秒触发一次比赛结束(下半场比赛结束)
    timer2->setInterval(30000);//每30秒触发一次随机黄牌
    timer3->setInterval(50000);//每50秒触发一次随机红牌
    timer_myGoal_1->setInterval(40000);//40秒触发30min处进球
    timer_myGoal_2->setInterval(55000);//55秒触发41min处进球
    timer_myGoal_3->setInterval(20000);//下半场20秒触发60min处进球(下半场)
    timer_myGoal_4->setInterval(53000);//下半场53秒触发85min处进球(下半场)
    timer_oppGoal_1->setInterval(38000);//对手进球的第1次随机判定
    timer_oppGoal_2->setInterval(5000);//对手进球的第2次随机判定(下半场)
    timer_oppGoal_3->setInterval(18000);//对手进球的第3次随机判定(下半场)
    timer_oppGoal_4->setInterval(55000);//对手进球的第4次随机判定(下半场)
    timer_ownGoal->setInterval(45000);//每45秒判定一次随机的乌龙球
    timer_talk->setInterval(60000);//上半场结束，中场时间，触发更衣室谈话

    //随机选取对手
    int cas = 0;
    srand((unsigned)time(NULL));
    cas = rand()%19;
    while(true)
    {
        if (oppteam[cas].name != teamName)
        {
            oppTeamName = oppteam[cas].name;
            break;
        }
        else
        {
            cas = rand()%19;
            continue;
        }
    }


    //"开赛"按钮
    connect(ui->gameBeginBtn,&QPushButton::clicked,[=](){
        bar_val = 0;
        ui->progressBar->setValue(0);
        ui->progressBar->setMaximum(120);
        ui->label_24->setText(teamName);
        ui->label_25->setText(oppTeamName);
        myGoal = 0;
        oppGoal = 0;
        ui->lcdNumber->display(myGoal);
        ui->lcdNumber_2->display(oppGoal);
        ui->stackedWidget->setCurrentIndex(21);
        timer0->start();
        timer2->start();
        timer3->start();
        timer_myGoal_1->start();
        timer_myGoal_2->start();
        timer_oppGoal_1->start();
        timer_ownGoal->start();
        timer_talk->start();
    });

    //"实时喊话"按钮
    connect(ui->currentCommandBtn,&QPushButton::clicked,[=](){
        uicurrentCommand->show();
        uicurrentCommand->exec();
    });

    //"换人"界面
    {
        if (goalKeeper1 != p1)
            ui->radioButton_24->setText(goalKeeper1);
    }

    //"换人"按钮
    connect(ui->submissionBtn,&QPushButton::clicked,[=](){

    });

    //"改变阵型"按钮
    connect(ui->changeFormationBtn,&QPushButton::clicked,[=](){
        uiCFD->show();
        uiCFD->exec();
    });


//赛后新闻发布会
    connect(ui->afterGameBtn,&QPushButton::clicked,[=](){
        if (winCase == 1)//赢得比赛后的新闻发布会
        {
            int cas = 0;
            srand((unsigned)time(NULL));
            cas = rand()%4+1;
            qDebug()<<"cas:"<<cas;
            switch (cas) {
            case 1:
            {
                uiAGWD_1 = new afterGameWinDialog_1(this);
                uiAGWD_1->setWindowTitle("请选择您的对话");
                uiAGWD_1->show();
                uiAGWD_1->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 2:
            {
                uiAGWD_2 = new afterGameWinDialog_2(this);
                uiAGWD_2->setWindowTitle("请选择您的对话");
                uiAGWD_2->show();
                uiAGWD_2->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 3:
            {
                uiAGWD_3 = new afterGameWinDialog_3(this);
                uiAGWD_3->setWindowTitle("请选择您的对话");
                uiAGWD_3->show();
                uiAGWD_3->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 4:
            {
                uiAGWD_4 = new afterGameWinDialog_4(this);
                uiAGWD_4->setWindowTitle("请选择您的对话");
                uiAGWD_4->show();
                uiAGWD_4->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            default:
                break;
            }
        }
        else if (winCase == 2)//输掉比赛后的新闻发布会
        {
            int cas = 0;
            srand((unsigned)time(NULL));
            cas = rand()%5+1;
            qDebug()<<"cas:"<<cas;
            switch (cas) {
            case 1:
            {
                uiAGFD_1 = new afterGameFailDialog_1(this);
                uiAGFD_1->setWindowTitle("请选择您的对话");
                uiAGFD_1->show();
                uiAGFD_1->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 2:
            {
                uiAGFD_2 = new afterGameFailDialog_2(this);
                uiAGFD_2->setWindowTitle("请选择您的对话");
                uiAGFD_2->show();
                uiAGFD_2->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 3:
            {
                uiAGFD_3 = new afterGameFailDialog_3(this);
                uiAGFD_3->setWindowTitle("请选择您的对话");
                uiAGFD_3->show();
                uiAGFD_3->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 4:
            {
                uiAGFD_4 = new afterGameFailDialog_4(this);
                uiAGFD_4->setWindowTitle("请选择您的对话");
                uiAGFD_4->show();
                uiAGFD_4->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 5:
            {
                uiAGFD_5 = new afterGameFailDialog_5(this);
                uiAGFD_5->setWindowTitle("请选择您的对话");
                uiAGFD_5->show();
                uiAGFD_5->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            default:
                break;
            }
        }
        else                //平局后的新闻发布会
        {
            int cas = 0;
            srand((unsigned)time(NULL));
            cas = rand()%3+1;
            qDebug()<<"cas:"<<cas;
            switch (cas) {
            case 1:
            {
                uiAGDD_1 = new afterGameDrawDialog_1(this);
                uiAGDD_1->setWindowTitle("请选择您的对话");
                uiAGDD_1->show();
                uiAGDD_1->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 2:
            {
                uiAGDD_2 = new afterGameDrawDialog_2(this);
                uiAGDD_2->setWindowTitle("请选择您的对话");
                uiAGDD_2->show();
                uiAGDD_2->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            case 3:
            {
                uiAGDD_3 = new afterGameDrawDialog_3(this);
                uiAGDD_3->setWindowTitle("请选择您的对话");
                uiAGDD_3->show();
                uiAGDD_3->exec();
                ui->stackedWidget->setCurrentIndex(8);
            }
                break;
            default:
                break;
            }
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTeam()
{
    bool ok;
    userName = QInputDialog::getText(this,QString("你好 教练"),QString("请输入你的名字"),QLineEdit::Normal,QString(),&ok);

    if (ok && !userName.isEmpty())
    {
        qDebug() << userName;
        uiCTD = new ChooseTeamDialog(this);
        uiCTD->setWindowTitle(QString("请选择球队"));
        uiCTD->show();
        uiCTD->exec();
        teamName = uiCTD->getTeamName();
        qDebug() << teamName;

        uiACTD = new AfterChooseTeamDialog(this);
        uiACTD->setUserName(userName);
        uiACTD->setTeamName(teamName);
        uiACTD->show();
        uiACTD->exec();
    }
}

void MainWindow::chooseCaptain()
{
    uiCCD = new ChooseCaptainDialog(this);
    uiCCD->setBox1(goalKeeper1.name);
    uiCCD->setBox2(goalKeeper2.name);
    uiCCD->setBox3(forward1.name);
    uiCCD->setBox4(forward2.name);
    uiCCD->setBox5(forward3.name);
    uiCCD->setBox6(forward4.name);
    uiCCD->setBox7(forward5.name);
    uiCCD->setBox8(forward6.name);
    uiCCD->setBox9(forward7.name);
    uiCCD->setBox10(midField1.name);
    uiCCD->setBox11(midField2.name);
    uiCCD->setBox12(midField3.name);
    uiCCD->setBox13(midField4.name);
    uiCCD->setBox14(midField5.name);
    uiCCD->setBox15(midField6.name);
    uiCCD->setBox16(midField7.name);
    uiCCD->setBox17(back1.name);
    uiCCD->setBox18(back2.name);
    uiCCD->setBox19(back3.name);
    uiCCD->setBox20(back4.name);
    uiCCD->setBox21(back5.name);
    uiCCD->setBox22(back6.name);
    uiCCD->setBox23(back7.name);
    uiCCD->show();
    uiCCD->exec();
    captian = uiCCD->onRadioClick();
    qDebug()<<"captain:"<<captian;
}

void MainWindow::chooseViceCaptain()
{
    uiCVCD = new ChooseViceCaptainDialog(this);
    uiCVCD->setBox1(goalKeeper1.name);
    uiCVCD->setBox2(goalKeeper2.name);
    uiCVCD->setBox3(forward1.name);
    uiCVCD->setBox4(forward2.name);
    uiCVCD->setBox5(forward3.name);
    uiCVCD->setBox6(forward4.name);
    uiCVCD->setBox7(forward5.name);
    uiCVCD->setBox8(forward6.name);
    uiCVCD->setBox9(forward7.name);
    uiCVCD->setBox10(midField1.name);
    uiCVCD->setBox11(midField2.name);
    uiCVCD->setBox12(midField3.name);
    uiCVCD->setBox13(midField4.name);
    uiCVCD->setBox14(midField5.name);
    uiCVCD->setBox15(midField6.name);
    uiCVCD->setBox16(midField7.name);
    uiCVCD->setBox17(back1.name);
    uiCVCD->setBox18(back2.name);
    uiCVCD->setBox19(back3.name);
    uiCVCD->setBox20(back4.name);
    uiCVCD->setBox21(back5.name);
    uiCVCD->setBox22(back6.name);
    uiCVCD->setBox23(back7.name);
    uiCVCD->show();
    uiCVCD->exec();
    viceCaptain = uiCVCD->onRadioClick();
    while (viceCaptain == captian)
    {
        int a = QMessageBox::warning(this,QString("注意"),QString("您所选的正副队长均为同一人\n请重新选择"),QMessageBox::Ok);
        uiCVCD->reset();
        uiCVCD->show();
        uiCVCD->exec();
        viceCaptain = uiCVCD->onRadioClick();
    }
    qDebug()<<"vice captain:"<<viceCaptain;
}

void MainWindow::setChoosePlayerName(QString p1, QString p2, QString p3, QString p4, QString p5, QString p6, QString p7, QString p8, QString p9, QString p10, QString p11, QString p12, QString p13, QString p14, QString p15, QString p16, QString p17, QString p18, QString p19, QString p20, QString p21, QString p22, QString p23)
{
    ui->checkBox_124->setText(p1);
    ui->checkBox_125->setText(p2);
    ui->checkBox_126->setText(p3);
    ui->checkBox_127->setText(p4);
    ui->checkBox_128->setText(p5);
    ui->checkBox_129->setText(p6);
    ui->checkBox_130->setText(p7);
    ui->checkBox_131->setText(p8);
    ui->checkBox_132->setText(p9);
    ui->checkBox_133->setText(p10);
    ui->checkBox_134->setText(p11);
    ui->checkBox_135->setText(p12);
    ui->checkBox_136->setText(p13);
    ui->checkBox_137->setText(p14);
    ui->checkBox_138->setText(p15);
    ui->checkBox_139->setText(p16);
    ui->checkBox_140->setText(p17);
    ui->checkBox_141->setText(p18);
    ui->checkBox_142->setText(p19);
    ui->checkBox_143->setText(p20);
    ui->checkBox_144->setText(p21);
    ui->checkBox_145->setText(p22);
    ui->checkBox_146->setText(p23);
}

void MainWindow::randomYellow()
{
    int cas1 = 0;
    srand((unsigned)time(NULL));
    cas1 = rand()%100+1;
    if (cas1 >= 1 && cas1 <= 10)
    {
        int cas2 = rand()%10;
        if (cas2 == 0)
            return;
        else if (red[cas2] == 0)
            yellow[cas2]++;
        else
            return;
        if (yellow[cas2] == 1)
        {

            int a = QMessageBox::question(this,QString("黄牌警告"),QString("您的一名球员得到了一张黄牌\n是否对他进行提醒，以免造成麻烦？"),QMessageBox::Ok|QMessageBox::Cancel);
            if (a == QMessageBox::Ok)
            {
                int b = QMessageBox::information(this,QString("结果通知"),QString("您成功提醒了他\n他表示会在后续比赛中注意"),QMessageBox::Ok);
            }

        }
        if (yellow[cas2] >= 2)
        {
            switch (cas2)
            {
            case 1:
            {
                if (red[1])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p2);
                uiRCD->show();
                uiRCD->exec();
                red[1] = 1;
            }
                break;
            case 2:
            {
                if (red[2])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p3);
                uiRCD->show();
                uiRCD->exec();
                red[2] = 1;
            }
                break;
            case 3:
            {
                if (red[3])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p4);
                uiRCD->show();
                uiRCD->exec();
                red[3] = 1;
            }
                break;
            case 4:
            {
                if (red[4])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p5);
                uiRCD->show();
                uiRCD->exec();
                red[4] = 1;
            }
                break;
            case 5:
            {
                if (red[5])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p6);
                uiRCD->show();
                uiRCD->exec();
                red[5] = 1;
            }
                break;
            case 6:
            {
                if (red[6])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p7);
                uiRCD->show();
                uiRCD->exec();
                red[6] = 1;
            }
                break;
            case 7:
            {
                if (red[7])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p8);
                uiRCD->show();
                uiRCD->exec();
                red[7] = 1;
            }
                break;
            case 8:
            {
                if (red[8])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p9);
                uiRCD->show();
                uiRCD->exec();
                red[8] = 1;
            }
                break;
            case 9:
            {
                if (red[9])
                    break;
                uiRCD = new redCardDialog(this);
                uiRCD->setWindowTitle(QString("红牌罚下通告"));
                uiRCD->setname(p10);
                uiRCD->show();
                uiRCD->exec();
                red[9] = 1;
            }
                break;
            default:
                break;
            }
        }
    }
}

void MainWindow::randomRed()
{
    int cas1 = 0;
    srand((unsigned)time(NULL));
    cas1 = rand()%100+1;
    qDebug()<<"randomRed:"<<cas1;
    if (cas1 >= 1 && cas1 <= 8)
    {
        int cas2 = rand()%10;
        switch (cas2)
        {
        case 1:
        {
            if (red[1])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p2);
            uiRCD->show();
            uiRCD->exec();
            red[1] = 1;
        }
            break;
        case 2:
        {
            if (red[2])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p3);
            uiRCD->show();
            uiRCD->exec();
            red[2] = 1;
        }
            break;
        case 3:
        {
            if (red[3])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p4);
            uiRCD->show();
            uiRCD->exec();
            red[3] = 1;
        }
            break;
        case 4:
        {
            if (red[4])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p5);
            uiRCD->show();
            uiRCD->exec();
            red[4] = 1;
        }
            break;
        case 5:
        {
            if (red[5])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p6);
            uiRCD->show();
            uiRCD->exec();
            red[5] = 1;
        }
            break;
        case 6:
        {
            if (red[6])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p7);
            uiRCD->show();
            uiRCD->exec();
            red[6] = 1;
        }
            break;
        case 7:
        {
            if (red[7])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p8);
            uiRCD->show();
            uiRCD->exec();
            red[7] = 1;
        }
            break;
        case 8:
        {
            if (red[8])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p9);
            uiRCD->show();
            uiRCD->exec();
            red[8] = 1;
        }
            break;
        case 9:
        {
            if (red[9])
                break;
            uiRCD = new redCardDialog(this);
            uiRCD->setWindowTitle(QString("红牌罚下通告"));
            uiRCD->setname(p10);
            uiRCD->show();
            uiRCD->exec();
            red[9] = 1;
        }
            break;
        default:
            break;
        }

    }
}

void MainWindow::ownGoal()
{
    int cas = 0;
    srand((unsigned)time(NULL));
    cas = rand()%100+1;
    if (cas >= 41 && cas <= 45)
    {
        oppGoal++;
        ui->lcdNumber_2->display(oppGoal);
        int a = QMessageBox::information(this,QString("进球通告"),QString("教练，真是不走运\n您的队伍进了一个乌龙球"),QMessageBox::Ok);
    }
}

void MainWindow::bar()
{
    bar_val = ui->progressBar->value();
    bar_val++;
    qDebug()<<"bar_val:"<<bar_val;
    if (bar_val > 120)
    {
        timer0->stop();
        ui->progressBar->setValue(120);
    }
    else
        ui->progressBar->setValue(bar_val);
}

void MainWindow::mygoal_30min()
{
//    bool t = false;
//    for (int i=1;i<=9;i++)
//    {
//        if (p[i] == QString("莱万多夫斯基")||p[i] == QString("穆勒")||p[i] == QString("维尔纳")||p[i] == QString("奥巴梅扬")||p[i] == QString("姆巴佩")||p[i] == QString("内马尔")||p[i] == QString("迪巴拉")||p[i] == QString("罗纳尔多")||p[i] == QString("阿扎尔")||p[i] == QString("贝尔")||p[i] == QString("菲尔米诺")||p[i] == QString("萨拉赫")||p[i] == QString("马内")||p[i] == QString("斯特林")||p[i] == QString("马赫雷斯")||p[i] == QString("阿圭罗")||p[i] == QString("格列兹曼")||p[i] == QString("梅西")||p[i] == QString("苏亚雷斯")||p[i] == QString("格纳布里")||p[i] == QString("萨内")||p[i] == QString("罗伊斯")||p[i] == QString("伊卡尔迪")||p[i] == QString("卢卡库")||p[i] == QString("齐耶赫")||p[i] == QString("哈梅斯罗德里格斯")||p[i] == QString("阿图尔")||p[i] == QString("克罗斯")||p[i] == QString("莫德里奇")||p[i] == QString("卡塞米罗")||p[i] == QString("亨德森")||p[i] == QString("伯纳多席尔瓦")||p[i] == QString("德布劳内")||p[i] == QString("库蒂尼奥")||p[i] == QString("德容")||p[i] == QString("桑乔")||p[i] == QString("维拉蒂")||p[i] == QString("埃里克森")||p[i] == QString("基米希")||p[i] == QString("瓦拉内")||p[i] == QString("卡瓦哈尔")||p[i] == QString("德里赫特")||p[i] == QString("阿诺德")||p[i] == QString("范戴克")||p[i] == QString("罗伯逊")||p[i] == QString("皮克")||p[i] == QString("胡梅尔斯")||p[i] == QString("马尔基尼奥斯")||p[i] == QString("博努奇")||p[i] == QString("戈丁"))
//        {
//            t = true;
//            break;
//        }
//        else
//            continue;
//    }
    if (goalKeeper1.rating >= 85 ||)
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_30min  cas:"<<cas;
        if (cas >= 1 && cas <= 60)
        {
            myGoal++;
            timer_myGoal_1->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
    else
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_30min  cas:"<<cas;
        if (cas >= 1 && cas <= 40)
        {
            myGoal++;
            timer_myGoal_1->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
}

void MainWindow::mygoal_41min()
{
    bool t = false;
    for (int i=1;i<=9;i++)
    {
        if (p[i] == QString("莱万多夫斯基")||p[i] == QString("穆勒")||p[i] == QString("维尔纳")||p[i] == QString("奥巴梅扬")||p[i] == QString("姆巴佩")||p[i] == QString("内马尔")||p[i] == QString("迪巴拉")||p[i] == QString("罗纳尔多")||p[i] == QString("阿扎尔")||p[i] == QString("贝尔")||p[i] == QString("菲尔米诺")||p[i] == QString("萨拉赫")||p[i] == QString("马内")||p[i] == QString("斯特林")||p[i] == QString("马赫雷斯")||p[i] == QString("阿圭罗")||p[i] == QString("格列兹曼")||p[i] == QString("梅西")||p[i] == QString("苏亚雷斯")||p[i] == QString("格纳布里")||p[i] == QString("萨内")||p[i] == QString("罗伊斯")||p[i] == QString("伊卡尔迪")||p[i] == QString("卢卡库")||p[i] == QString("齐耶赫")||p[i] == QString("哈梅斯罗德里格斯")||p[i] == QString("阿图尔")||p[i] == QString("克罗斯")||p[i] == QString("莫德里奇")||p[i] == QString("卡塞米罗")||p[i] == QString("亨德森")||p[i] == QString("伯纳多席尔瓦")||p[i] == QString("德布劳内")||p[i] == QString("库蒂尼奥")||p[i] == QString("德容")||p[i] == QString("桑乔")||p[i] == QString("维拉蒂")||p[i] == QString("埃里克森")||p[i] == QString("基米希")||p[i] == QString("瓦拉内")||p[i] == QString("卡瓦哈尔")||p[i] == QString("德里赫特")||p[i] == QString("阿诺德")||p[i] == QString("范戴克")||p[i] == QString("罗伯逊")||p[i] == QString("皮克")||p[i] == QString("胡梅尔斯")||p[i] == QString("马尔基尼奥斯")||p[i] == QString("博努奇")||p[i] == QString("戈丁"))
        {
            t = true;
            break;
        }
        else
            continue;
    }
    if (t)
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_41min  cas:"<<cas;
        if (cas >= 1 &&cas <= 70)
        {
            myGoal++;
            timer_myGoal_2->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
    else
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_41min  cas:"<<cas;
        if (cas >= 1 && cas <= 50)
        {
            myGoal++;
            timer_myGoal_2->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
}

void MainWindow::mygoal_60min()
{
    bool t = false;
    for (int i=1;i<=9;i++)
    {
        if (p[i] == QString("莱万多夫斯基")||p[i] == QString("穆勒")||p[i] == QString("维尔纳")||p[i] == QString("奥巴梅扬")||p[i] == QString("姆巴佩")||p[i] == QString("内马尔")||p[i] == QString("迪巴拉")||p[i] == QString("罗纳尔多")||p[i] == QString("阿扎尔")||p[i] == QString("贝尔")||p[i] == QString("菲尔米诺")||p[i] == QString("萨拉赫")||p[i] == QString("马内")||p[i] == QString("斯特林")||p[i] == QString("马赫雷斯")||p[i] == QString("阿圭罗")||p[i] == QString("格列兹曼")||p[i] == QString("梅西")||p[i] == QString("苏亚雷斯")||p[i] == QString("格纳布里")||p[i] == QString("萨内")||p[i] == QString("罗伊斯")||p[i] == QString("伊卡尔迪")||p[i] == QString("卢卡库")||p[i] == QString("齐耶赫")||p[i] == QString("哈梅斯罗德里格斯")||p[i] == QString("阿图尔")||p[i] == QString("克罗斯")||p[i] == QString("莫德里奇")||p[i] == QString("卡塞米罗")||p[i] == QString("亨德森")||p[i] == QString("伯纳多席尔瓦")||p[i] == QString("德布劳内")||p[i] == QString("库蒂尼奥")||p[i] == QString("德容")||p[i] == QString("桑乔")||p[i] == QString("维拉蒂")||p[i] == QString("埃里克森")||p[i] == QString("基米希")||p[i] == QString("瓦拉内")||p[i] == QString("卡瓦哈尔")||p[i] == QString("德里赫特")||p[i] == QString("阿诺德")||p[i] == QString("范戴克")||p[i] == QString("罗伯逊")||p[i] == QString("皮克")||p[i] == QString("胡梅尔斯")||p[i] == QString("马尔基尼奥斯")||p[i] == QString("博努奇")||p[i] == QString("戈丁"))
        {
            t = true;
            break;
        }
        else
            continue;
    }
    if (t)
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_60min  cas:"<<cas;
        if (cas >= 1 &&cas <= 30)
        {
            myGoal++;
            timer_myGoal_3->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
    else
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_60min  cas:"<<cas;
        if (cas >= 1 && cas <= 10)
        {
            myGoal++;
            timer_myGoal_3->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
}

void MainWindow::mygoal_85min()
{
    bool t = false;
    for (int i=1;i<=9;i++)
    {
        if (p[i] == QString("莱万多夫斯基")||p[i] == QString("穆勒")||p[i] == QString("维尔纳")||p[i] == QString("奥巴梅扬")||p[i] == QString("姆巴佩")||p[i] == QString("内马尔")||p[i] == QString("迪巴拉")||p[i] == QString("罗纳尔多")||p[i] == QString("阿扎尔")||p[i] == QString("贝尔")||p[i] == QString("菲尔米诺")||p[i] == QString("萨拉赫")||p[i] == QString("马内")||p[i] == QString("斯特林")||p[i] == QString("马赫雷斯")||p[i] == QString("阿圭罗")||p[i] == QString("格列兹曼")||p[i] == QString("梅西")||p[i] == QString("苏亚雷斯")||p[i] == QString("格纳布里")||p[i] == QString("萨内")||p[i] == QString("罗伊斯")||p[i] == QString("伊卡尔迪")||p[i] == QString("卢卡库")||p[i] == QString("齐耶赫")||p[i] == QString("哈梅斯罗德里格斯")||p[i] == QString("阿图尔")||p[i] == QString("克罗斯")||p[i] == QString("莫德里奇")||p[i] == QString("卡塞米罗")||p[i] == QString("亨德森")||p[i] == QString("伯纳多席尔瓦")||p[i] == QString("德布劳内")||p[i] == QString("库蒂尼奥")||p[i] == QString("德容")||p[i] == QString("桑乔")||p[i] == QString("维拉蒂")||p[i] == QString("埃里克森")||p[i] == QString("基米希")||p[i] == QString("瓦拉内")||p[i] == QString("卡瓦哈尔")||p[i] == QString("德里赫特")||p[i] == QString("阿诺德")||p[i] == QString("范戴克")||p[i] == QString("罗伯逊")||p[i] == QString("皮克")||p[i] == QString("胡梅尔斯")||p[i] == QString("马尔基尼奥斯")||p[i] == QString("博努奇")||p[i] == QString("戈丁"))
        {
            t = true;
            break;
        }
        else
            continue;
    }
    if (t)
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_85min  cas:"<<cas;
        if (cas >= 1 &&cas <= 40)
        {
            myGoal++;
            timer_myGoal_4->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
    else
    {
        int cas = 0;
        srand((unsigned)time(NULL));
        cas = rand()%100+1;
        qDebug()<<"mygoal_85min  cas:"<<cas;
        if (cas >= 1 && cas <= 30)
        {
            myGoal++;
            timer_myGoal_4->stop();
            ui->lcdNumber->display(myGoal);
            int a = QMessageBox::information(this,QString("球进啦！"),QString("恭喜，教练，您的球队进球得分了"),QMessageBox::Ok);

        }
    }
}

void MainWindow::oppgoal_1()
{
    int cas = 0;
    srand((unsigned)time(NULL));
    cas = rand()%100+1;
    qDebug()<<"oppgoal_1  cas ="<<cas;
    if (cas >= 1 && cas <= 45)
    {
        oppGoal++;
        timer_oppGoal_1->stop();
        ui->lcdNumber_2->display(oppGoal);
        int a = QMessageBox::information(this,QString("球进了"),QString("很不幸，教练，对方进球了\n我们需要加把劲了"),QMessageBox::Ok);

    }
}

void MainWindow::oppgoal_2()
{
    int cas = 0;
    srand((unsigned)time(NULL));
    cas = rand()%100+1;
    qDebug()<<"oppgoal_2  cas ="<<cas;
    if (cas >= 11 && cas <= 60)
    {
        oppGoal++;
        timer_oppGoal_2->stop();
        ui->lcdNumber_2->display(oppGoal);
        int a = QMessageBox::information(this,QString("球进了"),QString("很不幸，教练，对方进球了\n我们需要加把劲了"),QMessageBox::Ok);

    }
}

void MainWindow::oppgoal_3()
{
    int cas = 0;
    srand((unsigned)time(NULL));
    cas = rand()%100+1;
    qDebug()<<"oppgoal_3  cas ="<<cas;
    if (cas >= 1 && cas <= 45)
    {
        oppGoal++;
        timer_oppGoal_3->stop();
        ui->lcdNumber_2->display(oppGoal);
        int a = QMessageBox::information(this,QString("球进了"),QString("很不幸，教练，对方进球了\n我们需要加把劲了"),QMessageBox::Ok);

    }
}

void MainWindow::oppgoal_4()
{
    int cas = 0;
    srand((unsigned)time(NULL));
    cas = rand()%100+1;
    qDebug()<<"oppgoal_4 cas ="<<cas;
    if (cas >= 1 && cas <= 30)
    {
        oppGoal++;
        timer_oppGoal_4->stop();
        ui->lcdNumber_2->display(oppGoal);
        int a = QMessageBox::information(this,QString("球进了"),QString("很不幸，教练，对方进球了\n我们需要加把劲了"),QMessageBox::Ok);

    }
}

void MainWindow::talk()
{
    timer0->stop();
    timer2->stop();
    timer3->stop();
    timer_myGoal_1->stop();
    timer_myGoal_2->stop();
    timer_oppGoal_1->stop();
    timer_ownGoal->stop();
    timer_talk->stop();
    uiMTD->setWindowTitle(QString("中场 更衣室谈话"));
    uiMTD->set_mygoal(myGoal);
    uiMTD->set_oppgoal(oppGoal);
    uiMTD->show();
    uiMTD->exec();
    timer0->start();
    timer1->start();
    timer2->start();
    timer3->start();
    timer_myGoal_3->start();
    timer_myGoal_4->start();
    timer_oppGoal_2->start();
    timer_oppGoal_3->start();
    timer_oppGoal_4->start();
    timer_ownGoal->start();
}

void MainWindow::gameFinish()
{
    timer0->stop();
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer_myGoal_1->stop();
    timer_myGoal_2->stop();
    timer_myGoal_3->stop();
    timer_myGoal_4->stop();
    timer_oppGoal_1->stop();
    timer_oppGoal_2->stop();
    timer_oppGoal_3->stop();
    timer_oppGoal_4->stop();
    timer_ownGoal->stop();
    timer_talk->stop();
    if (myGoal > oppGoal)
    {
        winCase = 1;
        int a = QMessageBox::information(this,QString("比赛结束"),QString("恭喜您，教练，我们的队伍夺得了本场比赛的胜利"),QMessageBox::Ok);
        ui->stackedWidget->setCurrentIndex(22);
    }
    else if (myGoal == oppGoal)
    {
        winCase = 3;
        int a = QMessageBox::information(this,QString("比赛结束"),QString("教练，我们的球队和对方不相上下，打了一个平手"),QMessageBox::Ok);
        ui->stackedWidget->setCurrentIndex(22);
    }
    else
    {
        winCase = 2;
        int a = QMessageBox::information(this,QString("比赛结束"),QString("很不幸，教练，我们的队伍输掉了本场比赛"),QMessageBox::Ok);
        ui->stackedWidget->setCurrentIndex(22);
    }
    myGoal = 0;
    oppGoal = 0;
}
