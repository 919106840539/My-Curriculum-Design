#ifndef MIDTALKDIALOG_H
#define MIDTALKDIALOG_H

#include <QDialog>

namespace Ui {
class midTalkDialog;
}

class midTalkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit midTalkDialog(QWidget *parent = 0);
    int mygoal;
    int oppgoal;
    void set_mygoal(int a);
    void set_oppgoal(int a);
    ~midTalkDialog();

private:
    Ui::midTalkDialog *ui;
};

#endif // MIDTALKDIALOG_H
