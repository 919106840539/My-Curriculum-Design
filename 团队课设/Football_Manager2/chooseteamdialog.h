#ifndef CHOOSETEAMDIALOG_H
#define CHOOSETEAMDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseTeamDialog;
}

class ChooseTeamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseTeamDialog(QWidget *parent = 0);
    QString getTeamName();
    ~ChooseTeamDialog();

private:
    Ui::ChooseTeamDialog *ui;
};

#endif // CHOOSETEAMDIALOG_H
