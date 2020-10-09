#ifndef AFTERGAMEWINDIALOG_2_H
#define AFTERGAMEWINDIALOG_2_H

#include <QDialog>

namespace Ui {
class afterGameWinDialog_2;
}

class afterGameWinDialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameWinDialog_2(QWidget *parent = 0);
    ~afterGameWinDialog_2();

private:
    Ui::afterGameWinDialog_2 *ui;
};

#endif // AFTERGAMEWINDIALOG_2_H
