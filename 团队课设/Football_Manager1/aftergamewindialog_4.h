#ifndef AFTERGAMEWINDIALOG_4_H
#define AFTERGAMEWINDIALOG_4_H

#include <QDialog>

namespace Ui {
class afterGameWinDialog_4;
}

class afterGameWinDialog_4 : public QDialog
{
    Q_OBJECT

public:
    explicit afterGameWinDialog_4(QWidget *parent = 0);
    ~afterGameWinDialog_4();

private:
    Ui::afterGameWinDialog_4 *ui;
};

#endif // AFTERGAMEWINDIALOG_4_H
