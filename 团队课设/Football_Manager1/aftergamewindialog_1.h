#ifndef AFTERGAMEWINDIALOG_1_H
#define AFTERGAMEWINDIALOG_1_H

#include <QDialog>

namespace Ui {
class afterGameWinDialog_1;
}

class afterGameWinDialog_1 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameWinDialog_1(QWidget *parent = 0);
    ~afterGameWinDialog_1();

private:
    Ui::afterGameWinDialog_1 *ui;
};

#endif // AFTERGAMEWINDIALOG_1_H
