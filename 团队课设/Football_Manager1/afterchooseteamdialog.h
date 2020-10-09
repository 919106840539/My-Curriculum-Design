#ifndef AFTERCHOOSETEAMDIALOG_H
#define AFTERCHOOSETEAMDIALOG_H

#include <QDialog>

namespace Ui {
class AfterChooseTeamDialog;
}

class AfterChooseTeamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AfterChooseTeamDialog(QWidget *parent = 0);
    void setUserName(QString name);
    void setTeamName(QString name);
    ~AfterChooseTeamDialog();
signals:
//    void setIndexTo2();


private:
    Ui::AfterChooseTeamDialog *ui;
};

#endif // AFTERCHOOSETEAMDIALOG_H
