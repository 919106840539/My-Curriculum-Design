#ifndef CHOOSEGOALKEEPERDIALOG_H
#define CHOOSEGOALKEEPERDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseGoalKeeperDialog;
}

class ChooseGoalKeeperDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseGoalKeeperDialog(QWidget *parent = 0);

    int ckBox1;
    int ckBox2;
    int ckBox3;
    int ckBox4;
    int ckBox5;
    int ckBox6;
    int ckBox7;
    int ckBox8;
    int ckBox9;
    int ckBoxSum;
    void chooseTwoCheckBox();

    int salarysum;
    ~ChooseGoalKeeperDialog();

private:
    Ui::ChooseGoalKeeperDialog *ui;
};

#endif // CHOOSEGOALKEEPERDIALOG_H
