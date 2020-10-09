#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QList>
#include <QTimer>
#include "chooseteamdialog.h"
#include "team.h"
#include "player.h"
#include "afterchooseteamdialog.h"
#include "choosecaptaindialog.h"
#include "choosevicecaptaindialog.h"
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
#include "redcarddialog.h"
#include "currentcommanddialog.h"
#include "changeformationdialog.h"
#include "midtalkdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void createTeam();
    void chooseCaptain();
    void chooseViceCaptain();
    void setChoosePlayerName(
            QString p1,QString p2,QString p3,QString p4,QString p5,
            QString p6,QString p7,QString p8,QString p9,QString p10,
            QString p11,QString p12,QString p13,QString p14,QString p15,
            QString p16,QString p17,QString p18,QString p19,QString p20,
            QString p21,QString p22,QString p23);
    void setTBPlayerName();
    void getHurt();
    void goal();
    void ownGoal();

    struct TEAM
    {
        QString name;
        player players[11];
    };

    TEAM oppteam[19];


    QString userName = QString("");
    QString teamName = QString("");
    QString oppTeamName = QString("");

    player goalKeeper1,goalKeeper2;
    player forward1,forward2,forward3,forward4,forward5,forward6,forward7;
    player midField1,midField2,midField3,midField4,midField5,midField6,midField7;
    player back1,back2,back3,back4,back5,back6,back7;
//    QString goalKeeper1 = QString("");
//    QString goalKeeper2 = QString("");

//    QString forward1 = QString("");
//    QString forward2 = QString("");
//    QString forward3 = QString("");
//    QString forward4 = QString("");
//    QString forward5 = QString("");
//    QString forward6 = QString("");
//    QString forward7 = QString("");

//    QString midField1 = QString("");
//    QString midField2 = QString("");
//    QString midField3 = QString("");
//    QString midField4 = QString("");
//    QString midField5 = QString("");
//    QString midField6 = QString("");
//    QString midField7 = QString("");

//    QString back1 = QString("");
//    QString back2 = QString("");
//    QString back3 = QString("");
//    QString back4 = QString("");
//    QString back5 = QString("");
//    QString back6 = QString("");
//    QString back7 = QString("");

    QString teamPlayers[23];//球队球员

    QString captian = QString("");
    QString viceCaptain = QString("");

    QString teamTrain = QString("");
    QString gkTrain1 = QString("");
    QString gkTrain2 = QString("");
    QString gkTrain3 = QString("");
    QString forTrain1 = QString("");
    QString forTrain2 = QString("");
    QString midTrain1 = QString("");
    QString midTrain2 = QString("");
    QString backTrain1 = QString("");
    QString backTrain2 = QString("");

    //上场球员
    QString p1 = QString("");
    QString p2 = QString("");
    QString p3 = QString("");
    QString p4 = QString("");
    QString p5 = QString("");
    QString p6 = QString("");
    QString p7 = QString("");
    QString p8 = QString("");
    QString p9 = QString("");
    QString p10 = QString("");
    QString p11 = QString("");
    QString p[11];//选择上场的球员

    QString formatConfirm = QString("");

    int myGoal;//我方进球数
    int oppGoal;//对方进球数

    int winCase;//表示比赛的结果，1赢，2输，3平

    int yellow[10]={0};//第一个元素代表门将，跳过，其余的记录除门将外其他球员的黄牌数目，下标依次为前锋，中场，后卫

    int red[10]={0};//第一个元素代表门将，跳过，其余的记录除门将外其他球员是否被红牌罚下，下标依次为前锋，中场，后卫

    int bar_val = 0;//进度条数值

    QTimer *timer0;//进度条随时间变化
    QTimer *timer1;//记录单场比赛的总时间，时间到后结束
    QTimer *timer2;//记录比赛过程中的时间，触发黄牌事件
    QTimer *timer3;//记录比赛过程中的时间，触发红牌事件
    QTimer *timer_myGoal_1;//30分钟处我方概率进球
    QTimer *timer_myGoal_2;//45分钟处我方概率进球
    QTimer *timer_myGoal_3;//60分钟处我方概率进球
    QTimer *timer_myGoal_4;//85分钟处我方概率进球
    QTimer *timer_oppGoal_1;//对方概率进球
    QTimer *timer_oppGoal_2;//对方概率进球
    QTimer *timer_oppGoal_3;//对方概率进球
    QTimer *timer_oppGoal_4;//对方概率进球
    QTimer *timer_ownGoal;//乌龙球
    QTimer *timer_talk;//更衣室谈话

    int remainingTime_1;
    int remainingTime_2;
    int remainingTime_3;
    int remainingTime_4;
    int remainingTime_5;
    int remainingTime_6;
    int remainingTime_7;
    int remainingTime_8;
    int remainingTime_9;
    int remainingTime_10;
    int remainingTime_11;
    int remainingTime_12;
    int remainingTime_13;


    //用QVector存储选好的球员,不能用
    QVector<QString> playerVector;
    QList<QString> playerList;

    team ftTeam[21];
    player players[100];

    ChooseTeamDialog *uiCTD;
    AfterChooseTeamDialog *uiACTD;
    ChooseCaptainDialog *uiCCD;
    ChooseViceCaptainDialog *uiCVCD;
    BeforeGame1Dialog *uiBGD_1;
    BeforeGame2Dialog *uiBGD_2;
    BeforeGame3Dialog *uiBGD_3;
    BeforeGame4Dialog *uiBGD_4;
    BeforeGame5Dialog *uiBGD_5;
    afterGameWinDialog_1 *uiAGWD_1;
    afterGameWinDialog_2 *uiAGWD_2;
    afterGameWinDialog_3 *uiAGWD_3;
    afterGameWinDialog_4 *uiAGWD_4;
    afterGameFailDialog_1 *uiAGFD_1;
    afterGameFailDialog_2 *uiAGFD_2;
    afterGameFailDialog_3 *uiAGFD_3;
    afterGameFailDialog_4 *uiAGFD_4;
    afterGameFailDialog_5 *uiAGFD_5;
    afterGameDrawDialog_1 *uiAGDD_1;
    afterGameDrawDialog_2 *uiAGDD_2;
    afterGameDrawDialog_3 *uiAGDD_3;
    redCardDialog *uiRCD;
    currentCommandDialog *uicurrentCommand;
    changeFormationDialog *uiCFD;
    midTalkDialog *uiMTD;

    int ckBoxSum = 0;
    bool check_1;
    bool check_2;

    int salarysum1 = 0;//门将总周薪
    int salarysum2 = 0;//前锋总周薪
    int salarysum3 = 0;//中场总周薪
    int salarysum4 = 0;//后卫总周薪
    int salarysum = 0; //全局变量salarysum,计算周薪总数，控制在周薪550万欧以下


    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    //void nextDialog();
    void bar();
    void randomYellow();
    void randomRed();
    void mygoal_30min();
    void mygoal_41min();
    void mygoal_60min();
    void mygoal_85min();
    void oppgoal_1();
    void oppgoal_2();
    void oppgoal_3();
    void oppgoal_4();
    void gameFinish();
    void talk();
};

#endif // MAINWINDOW_H
